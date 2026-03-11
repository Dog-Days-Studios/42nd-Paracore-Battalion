private _weapon = currentWeapon player;
if (_weapon isEqualTo "") exitWith {["UNARMED", "SAFE"]};

private _name = getText (configFile >> "CfgWeapons" >> _weapon >> "displayName");
if (_name isEqualTo "") then
{
    _name = _weapon;
};

private _mode = currentWeaponMode player;
if (_mode isEqualTo "") then
{
    _mode = "SAFE";
};

[_name, toUpper _mode]
