params ["_unit"];

if (isNull _unit) exitWith {"none"};
if (_unit == player) exitWith {"none"};
if (!alive _unit) exitWith {"none"};

private _sourceUnit = objNull;

if (_unit isKindOf "Man") then
{
    _sourceUnit = _unit;
}
else
{
    private _crew = crew _unit select {alive _x};
    if (_crew isEqualTo []) exitWith {
        // Uncrewed vehicle: use config side to determine IFF
        private _vehicleSide = getNumber (configOf _unit >> "side");
        // side values: 0=EAST, 1=WEST, 2=GUER, 3=CIV
        if (_vehicleSide == 3) exitWith {"none"};
        private _sideMap = [east, west, resistance, civilian];
        private _vSide = _sideMap param [_vehicleSide, civilian];
        private _relation = (side group player) getFriend _vSide;
        ["enemy", "friendly"] select (_relation >= 0.6)
    };

    _sourceUnit = effectiveCommander _unit;
    if (isNull _sourceUnit) then {
        _sourceUnit = _crew select 0;
    };
};

if (isNull _sourceUnit) exitWith {"none"};

private _sourceSide = side group _sourceUnit;
if (_sourceSide == civilian) exitWith {"none"};

private _relation = (side group player) getFriend _sourceSide;
["enemy", "friendly"] select (_relation >= 0.6)
