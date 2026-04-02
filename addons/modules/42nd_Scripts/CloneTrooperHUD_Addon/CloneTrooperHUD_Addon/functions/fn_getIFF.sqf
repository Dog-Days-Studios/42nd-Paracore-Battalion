params ["_unit"];

if (isNull _unit) exitWith {"none"};
if (_unit == player) exitWith {"none"};
if (!alive _unit) exitWith {"none"};
if !(_unit isKindOf "Man") exitWith {"none"};
if (side group _unit == civilian) exitWith {"none"};

private _relation = (side group player) getFriend (side group _unit);
["enemy", "friendly"] select (_relation >= 0.6)
