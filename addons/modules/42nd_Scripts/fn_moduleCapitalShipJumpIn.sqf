params [
    ["_logic", objNull, [objNull]],
    ["_units", [], [[]]],
    ["_activated", true, [true]]
];

if (!_activated || {isNull _logic} || {!local _logic}) exitWith {false};

private _shipClass = _logic getVariable ["ShipClass", "ls_staticShip_venator_zeus"];
private _spawnHeight = parseNumber format ["%1", _logic getVariable ["SpawnHeight", 2000]];
private _heading = parseNumber format ["%1", _logic getVariable ["Heading", -1]];
private _cruiseSpeed = parseNumber format ["%1", _logic getVariable ["CruiseSpeed", 40]];
private _moveForever = (parseNumber format ["%1", _logic getVariable ["MoveForever", 0]]) > 0.5;

[_logic, _shipClass, _spawnHeight, _heading, _cruiseSpeed, _moveForever] call Para42_fnc_spawnCapitalShipJumpInServer;

true
