params ["_unit", "", "", "", "_ammoClass", "", "_projectile"];

if (!local _unit) exitWith {};
if (isNull _projectile) exitWith {};
if (getNumber (configFile >> "CfgAmmo" >> _ammoClass >> "Para42_isGrapple") != 1) exitWith {};

[_unit, _projectile, _ammoClass] spawn Para42_fnc_trackGrappleProjectile;
