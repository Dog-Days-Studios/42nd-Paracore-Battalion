params ["_unit", "_anchor"];

if (!local _unit) exitWith {};
if (isNull _anchor) exitWith {};
[_unit, _anchor, false, 1.25, true] call Para42_fnc_startGrapplePull;
