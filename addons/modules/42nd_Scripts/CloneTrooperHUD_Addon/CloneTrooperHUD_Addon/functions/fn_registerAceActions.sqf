if (!hasInterface) exitWith {};
if (isNil "ace_interact_menu_fnc_createAction") exitWith {};
if (isNil "ace_interact_menu_fnc_addActionToClass") exitWith {};
if (missionNamespace getVariable ["CTHUD_aceActionsAdded", false]) exitWith {};

missionNamespace setVariable ["CTHUD_aceActionsAdded", true];

private _rootAction = [
    "CTHUD_Root",
    "Clone HUD",
    "",
    {},
    {true}
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions"], _rootAction, true] call ace_interact_menu_fnc_addActionToClass;

private _toggleAction = [
    "CTHUD_Toggle",
    "Toggle HUD",
    "",
    { [] call CTHUD_fnc_toggleHUD; },
    {true}
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions", "CTHUD_Root"], _toggleAction, true] call ace_interact_menu_fnc_addActionToClass;

private _colorRootAction = [
    "CTHUD_ColorRoot",
    "HUD Color",
    "",
    {},
    {true}
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions", "CTHUD_Root"], _colorRootAction, true] call ace_interact_menu_fnc_addActionToClass;

{
    _x params ["_id", "_label", "_preset"];

    private _colorAction = [
        _id,
        _label,
        "",
        {
            params ["", "", "_params"];
            [_params select 0] call CTHUD_fnc_setColorPreset;
        },
        {true},
        {},
        [_preset]
    ] call ace_interact_menu_fnc_createAction;

    ["CAManBase", 1, ["ACE_SelfActions", "CTHUD_Root", "CTHUD_ColorRoot"], _colorAction, true] call ace_interact_menu_fnc_addActionToClass;
} forEach [
    ["CTHUD_Color_Default", "Default Blue", "default"],
    ["CTHUD_Color_Green", "Green", "green"],
    ["CTHUD_Color_Amber", "Amber", "amber"],
    ["CTHUD_Color_Red", "Red", "red"],
    ["CTHUD_Color_Mono", "Monochrome", "mono"]
];

private _joinGroupAction = [
    "CTHUD_JoinMyGroup",
    "Join My Group",
    "",
    {
        params ["_target", "_caller"];
        [_target, _caller] call CTHUD_fnc_requestJoinGroup;
    },
    {
        params ["_target", "_caller"];
        alive _target &&
        {alive _caller} &&
        {_target != _caller} &&
        {group _target != group _caller} &&
        {leader group _caller == _caller}
    }
] call ace_interact_menu_fnc_createAction;

["CAManBase", 0, ["ACE_MainActions"], _joinGroupAction, true] call ace_interact_menu_fnc_addActionToClass;
