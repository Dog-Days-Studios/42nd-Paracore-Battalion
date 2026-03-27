params ["_unit", "_anchor"];

if (!local _unit) exitWith {};
if (isNull _anchor) exitWith {};
if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {};

private _data = _anchor getVariable ["Para42_grappleData", []];
if ((count _data) < 6) exitWith {};

private _anchorPosASL = _data select 0;
private _ledgePosASL = _data select 4;
private _climbTopPosASL = _data select 5;
private _surfaceNormal = _data select 3;
private _endPosASL = [];

if ((_ledgePosASL isEqualType []) && {(count _ledgePosASL) == 3}) then {
    _endPosASL = _ledgePosASL;
} else {
    if ((_climbTopPosASL isEqualType []) && {(count _climbTopPosASL) == 3}) then {
        _endPosASL = _climbTopPosASL;
    } else {
        if ((_anchorPosASL isEqualType []) && {(count _anchorPosASL) == 3}) then {
            _endPosASL = _anchorPosASL;
        };
    };
};

if (_endPosASL isEqualTo []) exitWith {};

private _horizontalNormal = [_surfaceNormal select 0, _surfaceNormal select 1, 0];
if ((vectorMagnitude _horizontalNormal) < 0.01) then {
    _horizontalNormal = [0, 1, 0];
};
_horizontalNormal = vectorNormalized _horizontalNormal;

private _snapToStandingSurface = {
    params ["_targetPosASL", "_horizontalNormal", "_unit"];

    private _resolvedPosASL = [];
    private _landingOffsets = [0, -0.15, -0.3, -0.45, -0.7, -0.95, 0.12, 0.28];

    {
        if (_resolvedPosASL isNotEqualTo []) exitWith {};

        private _probeBaseASL = _targetPosASL vectorAdd (_horizontalNormal vectorMultiply _x);
        private _probeStartASL = _probeBaseASL vectorAdd [0, 0, 0.45];
        private _probeEndASL = _probeBaseASL vectorAdd [0, 0, -1.4];
        private _hits = lineIntersectsSurfaces [_probeStartASL, _probeEndASL, _unit, objNull, true, 4, "GEOM", "NONE"];

        if (_hits isEqualTo []) then {
            _hits = lineIntersectsSurfaces [_probeStartASL, _probeEndASL, _unit, objNull, true, 4, "FIRE", "NONE"];
        };

        {
            private _hitPosASL = _x select 0;
            private _hitNormal = _x select 1;

            if ((_hitNormal select 2) > 0.55) then {
                private _candidatePosASL = _hitPosASL vectorAdd [0, 0, 0.08];
                private _clearanceStartASL = _candidatePosASL vectorAdd [0, 0, 0.15];
                private _clearanceEndASL = _candidatePosASL vectorAdd [0, 0, 1.7];
                private _clearanceHits = lineIntersectsSurfaces [_clearanceStartASL, _clearanceEndASL, _unit, objNull, true, 1, "GEOM", "NONE"];

                if (_clearanceHits isEqualTo []) exitWith {
                    _resolvedPosASL = _candidatePosASL;
                };
            };
        } forEach _hits;
    } forEach _landingOffsets;

    if (_resolvedPosASL isEqualTo []) then {
        _resolvedPosASL = _targetPosASL;
    };

    _resolvedPosASL
};

_endPosASL = [_endPosASL, _horizontalNormal, _unit] call _snapToStandingSurface;

_unit setVariable ["Para42_grappleBusy", true];
_unit setVariable ["Para42_grappleRappelling", false];
_unit setVariable ["Para42_activeVerticalAnchor", objNull];
_unit allowDamage false;

private _startPosASL = getPosASL _unit;
private _travelVector = _endPosASL vectorDiff _startPosASL;
private _travelDistance = vectorMagnitude _travelVector;

if (_travelDistance < 0.15) exitWith {
    _unit setVariable ["Para42_grappleBusy", false];
    if (alive _unit) then {
        _unit allowDamage true;
    };
};

private _duration = _travelDistance / 2.4;
if (_duration < 0.6) then {
    _duration = 0.6;
};
if (_duration > 2) then {
    _duration = 2;
};

_unit playMoveNow "AmovPercMstpSrasWrflDnon";

private _startTime = time;

while {alive _unit && {(time - _startTime) < _duration}} do {
    if (!isNull objectParent _unit) exitWith {};

    private _alpha = (time - _startTime) / _duration;
    private _currentPosASL = _startPosASL vectorAdd (_travelVector vectorMultiply _alpha);

    _unit setVelocity [0, 0, 0];
    _unit setPosASL _currentPosASL;

    uiSleep 0.01;
};

if (alive _unit && {isNull objectParent _unit}) then {
    _unit setVelocity [0, 0, 0];
    _unit setPosASL _endPosASL;
};

_unit setVariable ["Para42_grappleBusy", false];

uiSleep 0.5;

if (alive _unit) then {
    _unit allowDamage true;
};
