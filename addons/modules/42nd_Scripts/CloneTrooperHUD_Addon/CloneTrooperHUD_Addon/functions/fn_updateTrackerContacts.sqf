if (!hasInterface) exitWith {[]};
if (isNull player) exitWith {[]};

private _now = diag_tickTime;
private _refresh = (missionNamespace getVariable ["CTHUD_trackerRefresh", 0.25]) max 0.05;
private _fadeTime = (missionNamespace getVariable ["CTHUD_trackerFadeTime", 1.5]) max 0;
private _nextUpdate = missionNamespace getVariable ["CTHUD_trackerNextUpdate", -1];
private _cachedContacts = missionNamespace getVariable ["CTHUD_trackerContacts", []];

if (_now < _nextUpdate) exitWith {
    private _filteredContacts = _cachedContacts select {
        ((_x select 6) isEqualTo "active") || {(_now - (_x select 5)) <= _fadeTime}
    };

    missionNamespace setVariable ["CTHUD_trackerContacts", _filteredContacts];
    _filteredContacts
};

if (!alive player) exitWith {
    missionNamespace setVariable ["CTHUD_trackerContacts", []];
    missionNamespace setVariable ["CTHUD_trackerNextUpdate", _now + _refresh];
    []
};

private _sensorObject = vehicle player;
if (isNull _sensorObject) then {
    _sensorObject = player;
};

private _isRadarMode = (_sensorObject isNotEqualTo player) && {call CTHUD_fnc_isPilotHudHelmet};
private _sensorPos = getPosVisual _sensorObject;
private _heading = getDirVisual _sensorObject;
private _range = if (_isRadarMode) then {
    ((missionNamespace getVariable ["CTHUD_trackerPilotRange", 450]) max 100) min 1500
} else {
    ((missionNamespace getVariable ["CTHUD_trackerRange", 60]) max 15) min 150
};
private _trackedKeys = createHashMap;
private _contacts = [];
private _entityTypes = [["CAManBase"], ["Air", "LandVehicle", "Ship"]] select _isRadarMode;

{
    if (!alive _x) then {
        continue;
    };

    if (_trackedKeys getOrDefault [netId _x, false]) then {
        continue;
    };

    if (_x isEqualTo player) then {
        continue;
    };

    if (_isRadarMode && {_x isKindOf "CAManBase"}) then {
        continue;
    };

    if ((vehicle _x) isEqualTo _sensorObject) then {
        continue;
    };

    private _iff = [_x] call CTHUD_fnc_getIFF;
    if (_iff isEqualTo "none") then {
        continue;
    };

    private _contactPos = getPosVisual _x;
    private _dx = (_contactPos select 0) - (_sensorPos select 0);
    private _dy = (_contactPos select 1) - (_sensorPos select 1);
    private _distance = sqrt ((_dx * _dx) + (_dy * _dy));

    if (_distance > _range) then {
        continue;
    };

    private _hasLos = if (_x isKindOf "Man") then {
        [_x] call CTHUD_fnc_hasDirectLineOfSight
    } else {
        _isRadarMode
    };
    private _contactType = ["contact", _iff] select _hasLos;
    private _contactCategory = ["man", "vehicle"] select !(_x isKindOf "Man");
    private _localRight = (_dx * cos _heading) - (_dy * sin _heading);
    private _localForward = (_dx * sin _heading) + (_dy * cos _heading);
    private _unitKey = netId _x;

    _trackedKeys set [_unitKey, true];
    _contacts pushBack [_unitKey, _contactType, _localRight, _localForward, _distance, _now, "active", _contactCategory];
} forEach (nearestObjects [_sensorPos, _entityTypes, _range, true]);

if (_fadeTime > 0) then {
    {
        private _unitKey = _x select 0;

        // Skip contacts that were re-acquired in the current scan
        if (_trackedKeys getOrDefault [_unitKey, false]) then {
            continue;
        };

        // Drop contacts that have faded beyond the fade window
        if ((_now - (_x select 5)) > _fadeTime) then {
            continue;
        };

        // Mark as lost but preserve last-seen timestamp from when it was active
        private _prevState = _x select 6;
        private _lostTimestamp = if (_prevState isEqualTo "active") then {_now} else {_x select 5};

        _contacts pushBack [
            _unitKey,
            _x select 1,
            _x select 2,
            _x select 3,
            _x select 4,
            _lostTimestamp,
            "lost",
            _x param [7, "man"]
        ];
    } forEach _cachedContacts;
};

missionNamespace setVariable ["CTHUD_trackerContacts", _contacts];
missionNamespace setVariable ["CTHUD_trackerNextUpdate", _now + _refresh];

_contacts
