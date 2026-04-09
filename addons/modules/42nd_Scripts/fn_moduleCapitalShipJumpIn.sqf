private _input = if (_this isEqualType []) then {_this} else {[_this]};
private _logic = _input param [0, objNull];
private _units = _input param [1, []];
private _activated = _input param [2, true];

if !(_logic isEqualType objNull) exitWith {false};
if !(_units isEqualType []) then {
    _units = [];
};
if !(_activated isEqualType true) then {
    _activated = true;
};

if (!_activated || {isNull _logic}) exitWith {false};

private _getModuleValue = {
    params ["_logic", "_names", "_default"];
    private _resolved = _default;

    {
        private _value = _logic getVariable [_x, nil];
        if (!isNil "_value") exitWith {
            _resolved = _value;
        };
    } forEach _names;

    _resolved
};

private _shipClass = [
    _logic,
    [
        "ShipClass",
        "Para42_Module_CapitalShipJumpIn_ShipClass",
        "para42_module_capitalshipjumpin_shipclass"
    ],
    "ls_staticShip_venator_zeus"
] call _getModuleValue;
private _spawnHeight = parseNumber format [
    "%1",
    [
        _logic,
        [
            "SpawnHeight",
            "Para42_Module_CapitalShipJumpIn_SpawnHeight",
            "para42_module_capitalshipjumpin_spawnheight"
        ],
        2000
    ] call _getModuleValue
];
private _heading = parseNumber format [
    "%1",
    [
        _logic,
        [
            "Heading",
            "Para42_Module_CapitalShipJumpIn_Heading",
            "para42_module_capitalshipjumpin_heading"
        ],
        -1
    ] call _getModuleValue
];
private _cruiseSpeed = parseNumber format [
    "%1",
    [
        _logic,
        [
            "CruiseSpeed",
            "Para42_Module_CapitalShipJumpIn_CruiseSpeed",
            "para42_module_capitalshipjumpin_cruisespeed"
        ],
        40
    ] call _getModuleValue
];
private _moveForever = (parseNumber format [
    "%1",
    [
        _logic,
        [
            "MoveForever",
            "Para42_Module_CapitalShipJumpIn_MoveForever",
            "para42_module_capitalshipjumpin_moveforever"
        ],
        0
    ] call _getModuleValue
]) > 0.5;

[_logic, _shipClass, _spawnHeight, _heading, _cruiseSpeed, _moveForever] call Para42_fnc_spawnCapitalShipJumpInServer;

true
