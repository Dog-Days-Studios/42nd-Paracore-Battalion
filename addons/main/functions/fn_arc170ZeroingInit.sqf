if (!hasInterface) exitWith {};

private _zeroDistances = [1000, 1500, 2000, 2500, 3000, 3500, 4000];

private _isInArc170GunshipTurret = {
    if (isNull objectParent player) exitWith {false};
    private _vehicle = vehicle player;
    if !(_vehicle isKindOf "42nd_Arc170_Gunship") exitWith {false};
    if (player == driver _vehicle) exitWith {false};
    true
};

Para42_fnc_arc170ZeroUp = compileFinal str {
    if !([] call Para42_arc170_isInTurret) exitWith {};
    private _vehicle = vehicle player;
    private _currentZero = _vehicle getVariable ["Para42_arc170_zeroIndex", 2];
    private _distances = [1000, 1500, 2000, 2500, 3000, 3500, 4000];
    private _newIndex = (_currentZero + 1) min ((count _distances) - 1);
    _vehicle setVariable ["Para42_arc170_zeroIndex", _newIndex];
    private _turretPath = [];
    {
        if ((_x select 0) isEqualTo player) exitWith {
            _turretPath = _x select 3;
        };
    } forEach fullCrew [_vehicle, "", true];
    if (_turretPath isNotEqualTo []) then {
        _vehicle setWeaponZeroing [currentWeapon _vehicle, currentMuzzle (vehicle player), _distances select _newIndex, _turretPath];
    };
    hint format ["Zeroing: %1m", _distances select _newIndex];
};

Para42_fnc_arc170ZeroDown = compileFinal str {
    if !([] call Para42_arc170_isInTurret) exitWith {};
    private _vehicle = vehicle player;
    private _currentZero = _vehicle getVariable ["Para42_arc170_zeroIndex", 2];
    private _distances = [1000, 1500, 2000, 2500, 3000, 3500, 4000];
    private _newIndex = (_currentZero - 1) max 0;
    _vehicle setVariable ["Para42_arc170_zeroIndex", _newIndex];
    private _turretPath = [];
    {
        if ((_x select 0) isEqualTo player) exitWith {
            _turretPath = _x select 3;
        };
    } forEach fullCrew [_vehicle, "", true];
    if (_turretPath isNotEqualTo []) then {
        _vehicle setWeaponZeroing [currentWeapon _vehicle, currentMuzzle (vehicle player), _distances select _newIndex, _turretPath];
    };
    hint format ["Zeroing: %1m", _distances select _newIndex];
};

Para42_arc170_isInTurret = compileFinal str _isInArc170GunshipTurret;

[
    "Para42_Keybinds",
    "Para42_arc170_zeroUp",
    ["[42nd] ARC-170 Zeroing Up", "[42nd] ARC-170 Gunship"],
    { call Para42_fnc_arc170ZeroUp },
    {},
    [0x21, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    "Para42_Keybinds",
    "Para42_arc170_zeroDown",
    ["[42nd] ARC-170 Zeroing Down", "[42nd] ARC-170 Gunship"],
    { call Para42_fnc_arc170ZeroDown },
    {},
    [0x22, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
