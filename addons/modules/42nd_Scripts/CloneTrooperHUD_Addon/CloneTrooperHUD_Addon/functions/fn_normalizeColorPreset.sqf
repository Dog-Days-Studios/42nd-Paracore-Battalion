private _validPresets =
[
    "default",
    "green",
    "amber",
    "red",
    "protanopia",
    "deuteranopia",
    "tritanopia",
    "mono",
    "custom"
];

private _preset = _this;

while {(typeName _preset) isEqualTo "ARRAY"} do
{
    if (_preset isEqualTo []) exitWith {
        _preset = "default";
    };

    private _stringIndex = _preset findIf {(typeName _x) isEqualTo "STRING"};
    if (_stringIndex != -1) exitWith {
        _preset = _preset select _stringIndex;
    };

    private _scalarIndex = _preset findIf {(typeName _x) isEqualTo "SCALAR"};
    if (_scalarIndex != -1) exitWith {
        _preset = _preset select _scalarIndex;
    };

    _preset = _preset select 0;
};

if ((typeName _preset) isEqualTo "SCALAR") then
{
    private _index = floor _preset;
    if (_index >= 0 && {_index < count _validPresets}) then
    {
        _preset = _validPresets select _index;
    }
    else
    {
        _preset = "default";
    };
};

if ((typeName _preset) isNotEqualTo "STRING") exitWith {"default"};

_preset = toLower _preset;

["default", _preset] select (_preset in _validPresets)
