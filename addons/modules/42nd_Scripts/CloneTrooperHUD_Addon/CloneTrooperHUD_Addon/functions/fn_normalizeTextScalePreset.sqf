private _validPresets =
[
    "compact",
    "default",
    "large",
    "xlarge"
];

private _preset = _this;

while {(typeName _preset) isEqualTo "ARRAY"} do
{
    if (_preset isEqualTo []) exitWith {
        _preset = "default";
    };

    private _matchingStringIndex = _preset findIf {
        (typeName _x) isEqualTo "STRING" &&
        {(toLower _x) in _validPresets}
    };
    if (_matchingStringIndex != -1) exitWith {
        _preset = _preset select _matchingStringIndex;
    };

    private _scalarIndex = _preset findIf {(typeName _x) isEqualTo "SCALAR"};
    if (_scalarIndex != -1) exitWith {
        _preset = _preset select _scalarIndex;
    };

    private _stringIndex = _preset findIf {(typeName _x) isEqualTo "STRING"};
    if (_stringIndex != -1) exitWith {
        _preset = _preset select _stringIndex;
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
