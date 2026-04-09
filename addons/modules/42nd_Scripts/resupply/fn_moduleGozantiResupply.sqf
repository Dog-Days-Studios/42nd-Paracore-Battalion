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

private _cargoClass = [
    _logic,
    [
        "CargoClass",
        "Para42_Module_GozantiResupply_CargoClass",
        "para42_module_gozantiresupply_cargoclass"
    ],
    "42nd_Ammo_Resupply_Crate"
] call _getModuleValue;
private _approachHeading = parseNumber format [
    "%1",
    [
        _logic,
        [
            "ApproachHeading",
            "Para42_Module_GozantiResupply_ApproachHeading",
            "para42_module_gozantiresupply_approachheading"
        ],
        -1
    ] call _getModuleValue
];

private _notifyUnit = objNull;
{
    if (!isNull _x) then {
        if (_x isKindOf "CAManBase") exitWith {
            _notifyUnit = _x;
        };

        if (_x isKindOf "AllVehicles") exitWith {
            private _crewLead = effectiveCommander _x;
            private _vehicleCrew = crew _x;
            if (isNull _crewLead) then {
                _crewLead = driver _x;
            };
            if (isNull _crewLead && {_vehicleCrew isNotEqualTo []}) then {
                _crewLead = _vehicleCrew select 0;
            };
            _notifyUnit = _crewLead;
        };
    };
} forEach _units;

[_logic, _notifyUnit, _cargoClass, _approachHeading] call Para42_fnc_spawnGozantiResupplyServer;

true
