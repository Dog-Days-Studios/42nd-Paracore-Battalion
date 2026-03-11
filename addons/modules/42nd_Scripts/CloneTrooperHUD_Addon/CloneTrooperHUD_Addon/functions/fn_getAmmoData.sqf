private _weapon = currentWeapon player;
if (_weapon isEqualTo "") exitWith {[0,0,""]};

private _mag = currentMagazine player;
private _loaded = player ammo _weapon;

private _magCountCfg = getNumber (configFile >> "CfgMagazines" >> _mag >> "count");
if (_magCountCfg <= 0) then
{
    _magCountCfg = 0;
};

private _spareMagazines = magazines player select {_x isEqualTo _mag};
private _spareCount = count _spareMagazines;
private _reserveMags = _spareCount - 1;
if (_reserveMags < 0) then
{
    _reserveMags = 0;
};

private _reserveRounds = _reserveMags * _magCountCfg;
[_loaded, _reserveRounds, _mag]
