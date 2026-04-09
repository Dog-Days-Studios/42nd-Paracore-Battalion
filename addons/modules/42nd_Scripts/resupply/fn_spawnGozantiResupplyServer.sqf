params [
    ["_logic", objNull, [objNull]],
    ["_notifyUnit", objNull, [objNull]],
    ["_cargoClass", "42nd_Ammo_Resupply_Crate", [""]],
    ["_approachHeading", -1, [0]]
];

if (!isServer) exitWith {
    [_logic, _notifyUnit, _cargoClass, _approachHeading] remoteExecCall ["Para42_fnc_spawnGozantiResupplyServer", 2];
    objNull
};

if (isNull _logic || {_cargoClass isEqualTo ""}) exitWith {objNull};
if (_logic getVariable ["42nd_gozantiResupplyQueued", false]) exitWith {objNull};

_logic setVariable ["42nd_gozantiResupplyQueued", true, true];

private _cargoCfg = configFile >> "CfgVehicles" >> _cargoClass;
if !(isClass _cargoCfg) exitWith {
    if (!isNull _logic) then {
        deleteVehicle _logic;
    };
    objNull
};

private _dropPosATL = getPosATL _logic;
_dropPosATL set [2, 0];

private _resolvedHeading = if (_approachHeading < 0) then {
    getDir _logic
} else {
    _approachHeading
};

private _cargoLabel = getText (_cargoCfg >> "displayName");
if (_cargoLabel isEqualTo "") then {
    _cargoLabel = _cargoClass;
};

[_notifyUnit, _cargoClass, _cargoLabel, _dropPosATL, _resolvedHeading, false] call Para42_fnc_requestGozantiAiResupply;

deleteVehicle _logic;
objNull
