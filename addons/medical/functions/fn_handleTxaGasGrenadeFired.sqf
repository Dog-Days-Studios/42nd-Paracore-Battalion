params ["_unit", "", "_muzzle", "", "_ammoClass", "", "_projectile"];

if (!local _unit) exitWith {};
if (_muzzle != "42nd_TXAGas_Muzzle") exitWith {};
if (isNull _projectile) exitWith {};

[_projectile, _ammoClass] spawn Para42_fnc_trackTxaGasGrenade;
