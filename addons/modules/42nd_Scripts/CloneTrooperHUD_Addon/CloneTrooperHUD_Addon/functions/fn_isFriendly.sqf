params ["_unit"];

if (isNull _unit) exitWith {false};
if (_unit == player) exitWith {false};
if (!alive _unit) exitWith {false};
if !(_unit isKindOf "Man") exitWith {false};
if (side group _unit == civilian) exitWith {false};

((side group player) getFriend (side group _unit)) >= 0.6
