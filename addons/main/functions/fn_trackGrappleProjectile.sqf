params ["_unit", "_projectile", "_ammoClass"];

private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;
private _maxLength = getNumber (_ammoConfig >> "Para42_grappleMaxLength");
private _lifetime = getNumber (_ammoConfig >> "Para42_grappleLifetime");
private _traceDistance = getNumber (_ammoConfig >> "Para42_grappleTraceDistance");
private _traverseMinDistance = getNumber (_ammoConfig >> "Para42_grappleTraverseMinDistance");
private _traverseMaxDistance = getNumber (_ammoConfig >> "Para42_grappleTraverseMaxDistance");
private _timeToLive = getNumber (_ammoConfig >> "timeToLive");
private _grappleMode = toLower getText (_ammoConfig >> "Para42_grappleMode");

if !(_grappleMode in ["vertical", "traverse", "universal"]) then {
    _grappleMode = "universal";
};

if (_maxLength <= 0) then {
    _maxLength = 30;
};

if (_lifetime <= 0) then {
    _lifetime = 600;
};

if (_traceDistance <= 0) then {
    _traceDistance = 60;
};

if (_traverseMinDistance < 0) then {
    _traverseMinDistance = 0;
};

if (_traverseMaxDistance <= 0) then {
    _traverseMaxDistance = _traceDistance;
};

if (_timeToLive <= 0) then {
    _timeToLive = 8;
};

private _sampleInterval = 0.01;
private _timeoutAt = diag_tickTime + _timeToLive + 0.25;
private _launchPosASL = (getPosASL _unit) vectorAdd [0, 0, 1.15];
private _lastPosASL = getPosASL _projectile;
private _startPosASL = +_lastPosASL;
private _lastVelocity = velocity _projectile;
private _impactData = [];

private _findImpactOnSegment = {
    params ["_segmentStartASL", "_segmentEndASL", "_unit", "_projectile"];

    private _hits = lineIntersectsSurfaces [_segmentStartASL, _segmentEndASL, _unit, _projectile, true, 10, "GEOM", "NONE"];
    if (_hits isEqualTo []) then {
        _hits = lineIntersectsSurfaces [_segmentStartASL, _segmentEndASL, _unit, _projectile, true, 10, "FIRE", "NONE"];
    };

    if (_hits isEqualTo []) exitWith {[]};

    _hits select 0
};

while {diag_tickTime < _timeoutAt} do {
    private _currentPosASL = +_lastPosASL;
    private _currentVelocity = +_lastVelocity;

    if (isNull _projectile) then {
        if ((vectorMagnitude _lastVelocity) > 1) then {
            _currentPosASL = _lastPosASL vectorAdd (_lastVelocity vectorMultiply _sampleInterval);
        };
    } else {
        _currentPosASL = getPosASL _projectile;
        _currentVelocity = velocity _projectile;
    };

    if ((_startPosASL distance _currentPosASL) > _traceDistance) exitWith {};

    private _segmentStartASL = _lastPosASL;
    private _segmentEndASL = _currentPosASL;

    if ((_segmentStartASL distance _segmentEndASL) < 0.05 && {(vectorMagnitude _currentVelocity) > 1}) then {
        _segmentEndASL = _currentPosASL vectorAdd (_currentVelocity vectorMultiply _sampleInterval);
    };

    private _hit = [_segmentStartASL, _segmentEndASL, _unit, _projectile] call _findImpactOnSegment;
    if (_hit isNotEqualTo []) exitWith {
        _impactData = [_hit select 0, _hit select 1, _hit select 2];
    };

    if (isNull _projectile) exitWith {};

    _lastPosASL = _currentPosASL;
    _lastVelocity = _currentVelocity;

    uiSleep _sampleInterval;
};

if (_impactData isEqualTo []) exitWith {};

if (!isNull _projectile) then {
    deleteVehicle _projectile;
};

[
    _unit,
    _impactData select 0,
    _impactData select 1,
    _maxLength,
    _lifetime,
    _launchPosASL,
    _traverseMinDistance,
    _traverseMaxDistance,
    _grappleMode,
    _impactData param [2, objNull, [objNull]]
] remoteExecCall ["Para42_fnc_deployGrappleServer", 2];
