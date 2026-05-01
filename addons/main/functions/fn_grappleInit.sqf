if (missionNamespace getVariable ["Para42_grappleInitDone", false]) exitWith {};
missionNamespace setVariable ["Para42_grappleInitDone", true];

Para42_grappleMagazine = "42nd_40mm_Grapple";
Para42_grappleMaxDistance = 200;
Para42_grappleClimbSpeed = 12;
Para42_grappleRopeColor = [0.35, 0.22, 0.10, 1];
Para42_grappleAnchorLifetime = 300;
Para42_grappleAnchorUseRadius = 8;
Para42_grappleAnchorDrawRange = 200;
Para42_grappleAnchorHelper = "Sign_Arrow_F";

// ============================================================
// Server-side anchor management
// ============================================================

Para42_fnc_grappleCreateAnchor = {
    params [
        ["_startASL", [], [[]]],
        ["_endASL", [], [[]]],
        ["_creator", objNull, [objNull]]
    ];
    if (!isServer) exitWith {};
    if ((count _startASL) != 3 || {(count _endASL) != 3}) exitWith {};

    private _helper = createVehicle [Para42_grappleAnchorHelper, ASLToAGL _endASL, [], 0, "CAN_COLLIDE"];
    if (isNull _helper) exitWith {};

    _helper setPosASL _endASL;
    _helper hideObjectGlobal true;
    _helper allowDamage false;
    _helper enableSimulationGlobal false;

    _helper setVariable ["Para42_grappleStartASL", _startASL, true];
    _helper setVariable ["Para42_grappleEndASL", _endASL, true];
    _helper setVariable ["Para42_grappleExpiry", diag_tickTime + Para42_grappleAnchorLifetime, true];
    _helper setVariable ["Para42_grappleCreator", _creator, true];

    private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
    _anchors pushBack _helper;
    missionNamespace setVariable ["Para42_grappleAnchors", _anchors, true];
};

if (isServer) then {
    missionNamespace setVariable ["Para42_grappleAnchors", [], true];

    [] spawn {
        while {true} do {
            uiSleep 15;
            private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
            if (_anchors isEqualTo []) then { continue };

            private _now = diag_tickTime;
            private _kept = [];
            {
                if (isNull _x) then { continue };
                private _expiry = _x getVariable ["Para42_grappleExpiry", 0];
                if (_expiry <= _now) then {
                    deleteVehicle _x;
                } else {
                    _kept pushBack _x;
                };
            } forEach _anchors;

            if ((count _kept) != (count _anchors)) then {
                missionNamespace setVariable ["Para42_grappleAnchors", _kept, true];
            };
        };
    };
};

// ============================================================
// Client-side (hasInterface only)
// ============================================================

if (!hasInterface) exitWith {};

Para42_fnc_grappleCanFire = {
    params [["_unit", player, [objNull]]];
    if (isNull _unit || {!alive _unit}) exitWith {false};
    if (!isNull objectParent _unit) exitWith {false};
    if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {false};
    (Para42_grappleMagazine in (magazines _unit))
};

Para42_fnc_grappleFindNearestAnchor = {
    params [["_unit", player, [objNull]], ["_maxDist", Para42_grappleAnchorUseRadius]];
    if (isNull _unit) exitWith {objNull};

    private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
    private _best = objNull;
    private _bestDist = _maxDist + 0.01;

    {
        if (isNull _x) then { continue };
        private _startASL = _x getVariable ["Para42_grappleStartASL", []];
        private _endASL = _x getVariable ["Para42_grappleEndASL", []];
        if ((count _startASL) != 3 || {(count _endASL) != 3}) then { continue };

        private _d = (_unit distance (ASLToAGL _startASL)) min (_unit distance (ASLToAGL _endASL));
        if (_d < _bestDist) then {
            _best = _x;
            _bestDist = _d;
        };
    } forEach _anchors;

    _best
};

Para42_fnc_grappleClimb = {
    params [["_unit", objNull, [objNull]], ["_targetPosASL", [], [[]]]];
    if (isNull _unit || {!alive _unit} || {(count _targetPosASL) != 3}) exitWith {};
    if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {};

    _unit setVariable ["Para42_grappleBusy", true, true];

    [_unit, _targetPosASL] spawn {
        params ["_unit", "_targetPosASL"];

        _unit allowDamage false;
        _unit setCaptive true;

        private _startASL = getPosASL _unit;
        private _totalDist = _startASL vectorDistance _targetPosASL;
        private _duration = (_totalDist / Para42_grappleClimbSpeed) max 0.4;
        private _startTime = diag_tickTime;

        while {alive _unit && {(diag_tickTime - _startTime) < _duration}} do {
            private _t = ((diag_tickTime - _startTime) / _duration) min 1;
            private _smooth = _t * _t * (3 - 2 * _t);
            private _pos = _startASL vectorAdd ((_targetPosASL vectorDiff _startASL) vectorMultiply _smooth);
            _unit setPosASL _pos;
            _unit setVelocity [0, 0, 0];
            uiSleep 0.02;
        };

        if (alive _unit) then {
            private _landing = _targetPosASL vectorAdd [0, 0, 0.2];
            _unit setPosASL _landing;
            _unit setVelocity [0, 0, 0];
        };

        _unit setCaptive false;
        _unit allowDamage true;
        _unit setVariable ["Para42_grappleBusy", false, true];
    };
};

Para42_fnc_grappleFire = {
    params [["_target", objNull, [objNull]], ["_caller", objNull, [objNull]]];
    if (isNull _caller || {!local _caller}) exitWith {};
    if !([_caller] call Para42_fnc_grappleCanFire) exitWith {};

    private _cameraStart = AGLToASL (positionCameraToWorld [0, 0, 0]);
    private _cameraFwd = (positionCameraToWorld [0, 0, 1]) vectorDiff (positionCameraToWorld [0, 0, 0]);
    _cameraFwd = vectorNormalized _cameraFwd;
    private _cameraEnd = _cameraStart vectorAdd (_cameraFwd vectorMultiply Para42_grappleMaxDistance);

    private _hits = lineIntersectsSurfaces [_cameraStart, _cameraEnd, _caller, objNull, true, 1, "GEOM", "NONE"];
    if (_hits isEqualTo []) exitWith {
        hint "No anchor surface in range.";
    };

    (_hits select 0) params ["_hitPosASL"];

    if ((_caller distance (ASLToAGL _hitPosASL)) > Para42_grappleMaxDistance) exitWith {
        hint "Anchor out of range.";
    };

    _caller removeMagazine Para42_grappleMagazine;

    private _startASL = getPosASL _caller;
    [_startASL, _hitPosASL, _caller] remoteExec ["Para42_fnc_grappleCreateAnchor", 2];

    [_caller, _hitPosASL] call Para42_fnc_grappleClimb;
};

Para42_fnc_grappleUseAnchor = {
    params [["_target", objNull, [objNull]], ["_caller", objNull, [objNull]]];
    if (isNull _caller || {!local _caller}) exitWith {};
    if (_caller getVariable ["Para42_grappleBusy", false]) exitWith {};
    if (!isNull objectParent _caller) exitWith {};

    private _anchor = [_caller] call Para42_fnc_grappleFindNearestAnchor;
    if (isNull _anchor) exitWith {};

    private _startASL = _anchor getVariable ["Para42_grappleStartASL", []];
    private _endASL = _anchor getVariable ["Para42_grappleEndASL", []];
    if ((count _startASL) != 3 || {(count _endASL) != 3}) exitWith {};

    private _dStart = _caller distance (ASLToAGL _startASL);
    private _dEnd = _caller distance (ASLToAGL _endASL);
    private _targetASL = [_startASL, _endASL] select (_dStart < _dEnd);

    [_caller, _targetASL] call Para42_fnc_grappleClimb;
};

// Shared Draw3D: render every live anchor's rope
addMissionEventHandler ["Draw3D", {
    private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
    if (_anchors isEqualTo []) exitWith {};
    if (isNull player) exitWith {};

    {
        if (isNull _x) then { continue };
        private _startASL = _x getVariable ["Para42_grappleStartASL", []];
        private _endASL = _x getVariable ["Para42_grappleEndASL", []];
        if ((count _startASL) != 3 || {(count _endASL) != 3}) then { continue };

        private _startAGL = ASLToAGL _startASL;
        private _endAGL = ASLToAGL _endASL;

        if ((player distance _startAGL) > Para42_grappleAnchorDrawRange &&
            {(player distance _endAGL) > Para42_grappleAnchorDrawRange}) then { continue };

        drawLine3D [_startAGL, _endAGL, Para42_grappleRopeColor];
    } forEach _anchors;
}];

// Watcher: rebind scroll actions when the local player changes (e.g., respawn)
[] spawn {
    private _lastPlayer = objNull;

    while {true} do {
        if (!isNull player && {_lastPlayer isNotEqualTo player}) then {
            private _oldOwner = missionNamespace getVariable ["Para42_grappleActionOwner", objNull];
            private _oldFire = missionNamespace getVariable ["Para42_grappleActionId", -1];
            private _oldUse = missionNamespace getVariable ["Para42_grappleUseActionId", -1];

            if (!isNull _oldOwner) then {
                if (_oldFire >= 0) then { _oldOwner removeAction _oldFire };
                if (_oldUse >= 0) then { _oldOwner removeAction _oldUse };
            };

            private _fireId = player addAction [
                "<t color='#d8a060'>Fire Grapple</t>",
                { _this call Para42_fnc_grappleFire },
                nil,
                6,
                true,
                true,
                "",
                "[_this] call Para42_fnc_grappleCanFire"
            ];

            private _useId = player addAction [
                "<t color='#d8a060'>Use Grapple Rope</t>",
                { _this call Para42_fnc_grappleUseAnchor },
                nil,
                5,
                true,
                true,
                "",
                "!(_this getVariable ['Para42_grappleBusy', false]) && isNull objectParent _this && !isNull ([_this] call Para42_fnc_grappleFindNearestAnchor)"
            ];

            missionNamespace setVariable ["Para42_grappleActionOwner", player];
            missionNamespace setVariable ["Para42_grappleActionId", _fireId];
            missionNamespace setVariable ["Para42_grappleUseActionId", _useId];
            _lastPlayer = player;
        };

        uiSleep 1;
    };
};
