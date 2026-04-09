if (!hasInterface) exitWith {false};
if (isNull player) exitWith {false};
if (!alive player) exitWith {false};

if !(missionNamespace getVariable ["CTHUD_onlyWithHelmet", true]) exitWith {true};

private _helmet = headgear player;
if (_helmet isEqualTo "") exitWith {false};

private _raw = missionNamespace getVariable ["CTHUD_cloneHelmetClasses", ""];
private _cachedRaw = missionNamespace getVariable ["CTHUD_parsedHelmetRaw", ""];
private _classes = missionNamespace getVariable ["CTHUD_parsedHelmetClasses", []];
if (_raw isNotEqualTo _cachedRaw) then {
    _classes = (_raw splitString ",") apply {toLower (trim _x)} select {_x != ""};
    missionNamespace setVariable ["CTHUD_parsedHelmetRaw", _raw];
    missionNamespace setVariable ["CTHUD_parsedHelmetClasses", _classes];
};
private _helmetCfg = configFile >> "CfgWeapons" >> _helmet;
private _has42ndHud = false;

while {isClass _helmetCfg && {!_has42ndHud}} do
{
    if (getNumber (_helmetCfg >> "42nd_cloneHud") > 0) then
    {
        _has42ndHud = true;
    }
    else
    {
        _helmetCfg = inheritsFrom _helmetCfg;
    };
};

_has42ndHud || {(toLower _helmet) in _classes}
