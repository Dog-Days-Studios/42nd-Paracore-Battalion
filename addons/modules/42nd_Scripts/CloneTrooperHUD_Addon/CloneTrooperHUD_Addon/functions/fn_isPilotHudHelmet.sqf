if (!hasInterface) exitWith {false};
if (isNull player) exitWith {false};

private _helmet = headgear player;
if (_helmet isEqualTo "") exitWith {false};

private _helmetCfg = configFile >> "CfgWeapons" >> _helmet;
private _isPilotHudHelmet = false;

while {isClass _helmetCfg && {!_isPilotHudHelmet}} do
{
    if ((toLower getText (_helmetCfg >> "42nd_hudProfile")) isEqualTo "pilot") then
    {
        _isPilotHudHelmet = true;
    }
    else
    {
        _helmetCfg = inheritsFrom _helmetCfg;
    };
};

_isPilotHudHelmet
