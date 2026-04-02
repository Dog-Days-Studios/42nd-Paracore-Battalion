params ["_unit"];

if (isNull _unit) exitWith {false};
if (_unit == player) exitWith {false};
if (!alive player) exitWith {false};
if (!alive _unit) exitWith {false};
if !(_unit isKindOf "Man") exitWith {false};

private _cacheUntil = _unit getVariable ["CTHUD_markerLOSCacheUntil", -1];
if (_cacheUntil >= diag_tickTime) exitWith {
    _unit getVariable ["CTHUD_markerHasDirectLOS", false]
};

private _ignoreObserver = vehicle player;
private _ignoreTarget = _unit;
private _hasDirectLineOfSight = (lineIntersectsSurfaces [
    eyePos player,
    eyePos _unit,
    _ignoreObserver,
    _ignoreTarget,
    true,
    1,
    "VIEW",
    "FIRE"
] isEqualTo []);

_unit setVariable ["CTHUD_markerHasDirectLOS", _hasDirectLineOfSight];
_unit setVariable ["CTHUD_markerLOSCacheUntil", diag_tickTime + 0.1];

_hasDirectLineOfSight
