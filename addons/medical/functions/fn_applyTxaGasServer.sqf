if (!isServer) exitWith {
    _this remoteExecCall ["Para42_fnc_applyTxaGasServer", 2];
};

params [
    "_positionASL",
    ["_radius", 10],
    ["_cloudDuration", 12],
    ["_tickInterval", 0.5],
    ["_exposureTime", 4]
];

private _center = ASLToAGL _positionASL;
private _cloudDurationSafe = _cloudDuration max 0.5;
private _tickIntervalSafe = _tickInterval max 0.1;
private _exposureTimeSafe = _exposureTime max _tickIntervalSafe;
private _deadline = CBA_missionTime + _cloudDurationSafe;
private _exposureByUnit = createHashMap;
private _dosedUnits = createHashMap;

[{
    params ["_args", "_idPFH"];
    _args params ["_center", "_radius", "_deadline", "_tickInterval", "_exposureTime", "_exposureByUnit", "_dosedUnits"];

    if (CBA_missionTime >= _deadline) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _seenUnits = createHashMap;

    {
        if (!alive _x) then {
            continue;
        };

        private _unitKey = netId _x;
        _seenUnits set [_unitKey, true];

        if (_dosedUnits getOrDefault [_unitKey, false]) then {
            continue;
        };

        private _exposure = (_exposureByUnit getOrDefault [_unitKey, 0]) + _tickInterval;

        if (_exposure >= _exposureTime) then {
            [_x, "Body", "TXA"] remoteExecCall ["kat_pharma_fnc_medicationLocal", _x];
            _dosedUnits set [_unitKey, true];
            _exposureByUnit deleteAt _unitKey;
            continue;
        };

        _exposureByUnit set [_unitKey, _exposure];
    } forEach (_center nearEntities ["CAManBase", _radius]);

    {
        if !(_seenUnits getOrDefault [_x, false]) then {
            _exposureByUnit deleteAt _x;
        };
    } forEach (keys _exposureByUnit);
}, _tickIntervalSafe, [_center, _radius, _deadline, _tickIntervalSafe, _exposureTimeSafe, _exposureByUnit, _dosedUnits]] call CBA_fnc_addPerFrameHandler;
