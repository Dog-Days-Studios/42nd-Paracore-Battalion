params ["_projectile", "_ammoClass"];

private _ammoConfig = configFile >> "CfgAmmo" >> _ammoClass;
private _radius = getNumber (_ammoConfig >> "Para42_txaRadius");
private _fuseTime = getNumber (_ammoConfig >> "explosionTime");

if (_radius <= 0) then {
    _radius = 10;
};

if (_fuseTime <= 0) then {
    _fuseTime = 2;
};

private _deadline = CBA_missionTime + _fuseTime + 0.25;
private _lastPos = getPosASL _projectile;

while {CBA_missionTime < _deadline} do {
    if (!isNull _projectile) then {
        _lastPos = getPosASL _projectile;
    };

    uiSleep 0.05;
};

if (_lastPos isEqualTo [0, 0, 0]) exitWith {};

[_lastPos, _radius] remoteExecCall ["Para42_fnc_applyTxaGasServer", 2];
