params [["_isPilotHud", false, [false]]];

private _defaults = [
    "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\p2_hud_ca.paa",
    "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\pilot_hud_ca.paa"
];

if (!hasInterface || {isNull player}) exitWith { _defaults select _isPilotHud };

private _helmet = headgear player;
if (_helmet isEqualTo "") exitWith { _defaults select _isPilotHud };

private _cfg = configFile >> "CfgWeapons" >> _helmet;
private _custom = "";

while {isClass _cfg && {_custom isEqualTo ""}} do
{
    private _val = getText (_cfg >> "42nd_hudVisorTexture");
    if (_val isNotEqualTo "") then
    {
        _custom = _val;
    }
    else
    {
        _cfg = inheritsFrom _cfg;
    };
};

if (_custom isNotEqualTo "") exitWith { _custom };

_defaults select _isPilotHud
