if (!isServer) exitWith {
    _this remoteExecCall ["Para42_fnc_applyTxaGasServer", 2];
};

params ["_positionASL", ["_radius", 10]];

private _center = ASLToAGL _positionASL;

{
    if (!alive _x) then {
        continue;
    };

    [_x, "Body", "TXA"] remoteExecCall ["kat_pharma_fnc_medicationLocal", _x];
} forEach (_center nearEntities ["CAManBase", _radius]);
