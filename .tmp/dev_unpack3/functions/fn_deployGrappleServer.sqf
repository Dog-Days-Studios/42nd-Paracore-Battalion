params [
    "_unit",
    "_impactPosASL",
    "_surfaceNormal",
    "_maxLength",
    "_lifetime",
    ["_launchPosASL", [], [[]]],
    ["_traverseMinDistance", 0, [0]],
    ["_traverseMaxDistance", 0, [0]],
    ["_grappleMode", "universal", [""]],
    ["_impactObject", objNull, [objNull]]
];

if (!isServer) exitWith {
    _this remoteExecCall ["Para42_fnc_deployGrappleServer", 2];
};

if (isNull _unit) exitWith {};
if (_maxLength <= 0) then {
    _maxLength = 250;
};
if (_lifetime <= 0) then {
    _lifetime = 600;
};

private _topPosASL = +_impactPosASL;
private _surfaceVector = vectorNormalized _surfaceNormal;
private _shotDirection = if ((_launchPosASL isEqualType []) && {(count _launchPosASL) == 3}) then {
    _topPosASL vectorDiff _launchPosASL
} else {
    [0, 1, 0]
};

private _wallNormal = [_surfaceVector select 0, _surfaceVector select 1, 0];
if ((vectorMagnitude _wallNormal) < 0.01) then {
    _wallNormal = [-(_shotDirection select 0), -(_shotDirection select 1), 0];
};
if ((vectorMagnitude _wallNormal) < 0.01) then {
    _wallNormal = [0, 1, 0];
};
_wallNormal = vectorNormalized _wallNormal;

private _findSurfaceHits = {
    params ["_startPosASL", "_endPosASL", "_unit", ["_count", 8, [0]]];

    private _hits = lineIntersectsSurfaces [_startPosASL, _endPosASL, _unit, objNull, true, _count, "GEOM", "NONE"];
    if (_hits isEqualTo []) then {
        _hits = lineIntersectsSurfaces [_startPosASL, _endPosASL, _unit, objNull, true, _count, "FIRE", "NONE"];
    };

    _hits
};

private _findBottomPos = {
    params ["_topPosASL", "_wallNormal", "_maxLength", "_unit", "_findSurfaceHits"];

    private _candidateOffsets = [0, 0.15, 0.3, 0.45, 0.6];

    {
        private _dropStartASL = (_topPosASL vectorAdd (_wallNormal vectorMultiply _x)) vectorAdd [0, 0, -0.05];
        private _dropEndASL = _dropStartASL vectorAdd [0, 0, -_maxLength];
        private _groundHits = [_dropStartASL, _dropEndASL, _unit, 2] call _findSurfaceHits;

        if (_groundHits isNotEqualTo []) exitWith {
            (_groundHits select 0 select 0) vectorAdd [0, 0, 0.15]
        };
    } forEach _candidateOffsets;

    []
};

private _findLaunchSideStartPos = {
    params ["_launchPosASL", "_topPosASL", "_wallNormal", "_unit", "_findSurfaceHits"];

    if (!(_launchPosASL isEqualType []) || {(count _launchPosASL) != 3}) exitWith {[]};

    private _flatDirection = _topPosASL vectorDiff _launchPosASL;
    _flatDirection set [2, 0];

    if ((vectorMagnitude _flatDirection) < 0.01) then {
        _flatDirection = _wallNormal vectorMultiply -1;
    } else {
        _flatDirection = vectorNormalized _flatDirection;
    };

    private _probeOffsets = [0, 0.75, 1.5, 2.25, 3, 4];

    {
        private _probeBaseASL = _launchPosASL vectorAdd (_flatDirection vectorMultiply _x);
        private _probeStartASL = _probeBaseASL vectorAdd [0, 0, 0.6];
        private _probeEndASL = _probeBaseASL vectorAdd [0, 0, -8];
        private _hits = [_probeStartASL, _probeEndASL, _unit, 4] call _findSurfaceHits;

        if (_hits isNotEqualTo []) exitWith {
            (_hits select 0 select 0) vectorAdd [0, 0, 0.15]
        };
    } forEach _probeOffsets;

    private _terrainHeightASL = getTerrainHeightASL [_launchPosASL select 0, _launchPosASL select 1];
    [_launchPosASL select 0, _launchPosASL select 1, _terrainHeightASL + 0.15]
};

private _resolveStandingPos = {
    params ["_surfacePosASL", "_wallNormal", "_unit", "_findSurfaceHits"];

    private _resolvedPosASL = [];
    private _landingOffsets = [-1.4, -1.1, -0.85, -0.6, -0.45, -0.3, -0.18, -0.08, 0, 0.12, 0.28];

    {
        if (_resolvedPosASL isNotEqualTo []) exitWith {};

        private _candidateProbeASL = _surfacePosASL vectorAdd (_wallNormal vectorMultiply _x);
        private _supportStartASL = _candidateProbeASL vectorAdd [0, 0, 0.45];
        private _supportEndASL = _candidateProbeASL vectorAdd [0, 0, -1.2];
        private _supportHits = [_supportStartASL, _supportEndASL, _unit, 4] call _findSurfaceHits;

        {
            private _supportPosASL = _x select 0;
            private _supportNormal = _x select 1;

            if ((_supportNormal select 2) > 0.55) then {
                private _candidatePosASL = _supportPosASL vectorAdd [0, 0, 0.08];
                private _clearanceStartASL = _candidatePosASL vectorAdd [0, 0, 0.15];
                private _clearanceEndASL = _candidatePosASL vectorAdd [0, 0, 1.7];
                private _clearanceHits = [_clearanceStartASL, _clearanceEndASL, _unit, 1] call _findSurfaceHits;

                if (_clearanceHits isEqualTo []) exitWith {
                    _resolvedPosASL = _candidatePosASL;
                };
            };
        } forEach _supportHits;
    } forEach _landingOffsets;

    _resolvedPosASL
};

private _findBestTopPos = {
    params ["_topPosASL", "_wallNormal", "_unit", "_findSurfaceHits", "_resolveStandingPos"];

    private _bestTopPosASL = [];
    private _bestScore = 1e9;
    private _surfaceOffsets = [-2.25, -1.85, -1.45, -1.1, -0.8, -0.5, -0.22, 0, 0.18, 0.45, 0.75];
    private _startHeights = [2.5, 2.0, 1.5, 1.0, 0.55, 0];

    {
        private _surfaceOffset = _x;

        {
            private _probeBaseASL = _topPosASL vectorAdd (_wallNormal vectorMultiply _surfaceOffset);
            private _probeStartASL = _probeBaseASL vectorAdd [0, 0, _x];
            private _probeEndASL = _probeBaseASL vectorAdd [0, 0, -7];
            private _hits = [_probeStartASL, _probeEndASL, _unit, 8] call _findSurfaceHits;

            {
                private _hitPosASL = _x select 0;
                private _hitNormal = _x select 1;

                if ((_hitNormal select 2) > 0.55) then {
                    private _candidatePosASL = [_hitPosASL, _wallNormal, _unit, _findSurfaceHits] call _resolveStandingPos;

                    if ((_candidatePosASL isEqualType []) && {(count _candidatePosASL) == 3}) then {
                        private _score = abs ((_candidatePosASL select 2) - (_topPosASL select 2)) + (abs _surfaceOffset * 0.45) + ([0, 0.25] select (_surfaceOffset > 0.05));

                        if (_score < _bestScore) then {
                            _bestScore = _score;
                            _bestTopPosASL = _candidatePosASL;
                        };
                    };
                };
            } forEach _hits;
        } forEach _startHeights;
    } forEach _surfaceOffsets;

    _bestTopPosASL
};

private _bottomPosASL = [_topPosASL, _wallNormal, _maxLength, _unit, _findSurfaceHits] call _findBottomPos;
if (_bottomPosASL isEqualTo []) then {
    private _terrainHeightASL = getTerrainHeightASL [_topPosASL select 0, _topPosASL select 1];
    private _fallbackGroundPosASL = [_topPosASL select 0, _topPosASL select 1, _terrainHeightASL + 0.15];

    if ((_topPosASL distance _fallbackGroundPosASL) <= _maxLength) then {
        _bottomPosASL = _fallbackGroundPosASL;
    } else {
        _bottomPosASL = _topPosASL vectorAdd [0, 0, -_maxLength];
    };
};

private _lineStartPosASL = [_launchPosASL, _topPosASL, _wallNormal, _unit, _findSurfaceHits] call _findLaunchSideStartPos;
if (_lineStartPosASL isEqualTo []) then {
    _lineStartPosASL = +_bottomPosASL;
};

private _climbTopPosASL = [_topPosASL, _wallNormal, _unit, _findSurfaceHits, _resolveStandingPos] call _findBestTopPos;
private _ledgePosASL = +_climbTopPosASL;

if (_climbTopPosASL isEqualTo []) then {
    _climbTopPosASL = [_topPosASL vectorAdd (_wallNormal vectorMultiply -0.35), _wallNormal, _unit, _findSurfaceHits] call _resolveStandingPos;
};

if (_climbTopPosASL isEqualTo []) then {
    _climbTopPosASL = [_topPosASL, _wallNormal, _unit, _findSurfaceHits] call _resolveStandingPos;
};

if (_climbTopPosASL isEqualTo []) then {
    _climbTopPosASL = _topPosASL vectorAdd [0, 0, 0.1];
    _ledgePosASL = [];
};

private _anchor = createVehicle ["Land_Can_V2_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
_anchor allowDamage false;
_anchor enableSimulationGlobal false;
_anchor hideObjectGlobal true;
_anchor setPosASL _topPosASL;

if !(isNull _impactObject) then {
    private _modelSpacePosition = _impactObject worldToModelVisual (ASLToAGL _topPosASL);
    _anchor attachTo [_impactObject, _modelSpacePosition];
};

private _startHelper = createVehicle ["Land_Can_V2_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
_startHelper allowDamage false;
_startHelper enableSimulationGlobal false;
_startHelper hideObjectGlobal true;
_startHelper setPosASL _lineStartPosASL;

private _persistentRope = objNull;
private _ropeVisual = objNull;

_anchor setVariable ["Para42_grappleRopeVisual", _ropeVisual, true];

_anchor setVariable ["Para42_grappleMode", "universal", true];
_anchor setVariable [
    "Para42_grappleData",
    [_topPosASL, _topPosASL, _bottomPosASL, _wallNormal, _ledgePosASL, _climbTopPosASL, _lineStartPosASL, _topPosASL],
    true
];
_anchor setVariable ["Para42_grappleOwner", _unit];
_anchor setVariable ["Para42_grappleStartHelper", _startHelper];
_anchor setVariable ["Para42_grapplePersistentRope", _persistentRope];

private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
_anchors = _anchors select {!isNull _x};
_anchors pushBackUnique _anchor;
missionNamespace setVariable ["Para42_grappleAnchors", _anchors, true];

if (!isNull _unit) then {
    [_unit, _anchor] remoteExecCall ["Para42_fnc_autoEngageGrappleClient", _unit];
};

[_anchor, _lifetime] spawn {
    params ["_anchor", "_lifetime"];
    sleep _lifetime;
    if (!isNull _anchor) then {
        [_anchor] call Para42_fnc_removeGrappleServer;
    };
};
