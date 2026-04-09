if (!hasInterface) exitWith {};
if (isNil "ace_interact_menu_fnc_createAction") exitWith {};
if (isNil "ace_interact_menu_fnc_addActionToClass") exitWith {};
if (missionNamespace getVariable ["para42_laatResupplyActionsAdded", false]) exitWith {};

missionNamespace setVariable ["para42_laatResupplyActionsAdded", true];

private _rootAction = [
    "Para42_LaatResupplyRoot",
    "LAAT Resupply",
    "",
    {},
    {
        params ["", "_player"];
        [_player] call Para42_fnc_hasResupplyAccess
    }
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions"], _rootAction, true] call ace_interact_menu_fnc_addActionToClass;

private _aiRootAction = [
    "Para42_LaatResupplyAiRoot",
    "AI Delivery",
    "",
    {},
    {
        params ["", "_player"];
        [_player] call Para42_fnc_hasResupplyAccess &&
        !(missionNamespace getVariable ["para42_laatAiResupplyInProgress", false])
    }
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions", "Para42_LaatResupplyRoot"], _aiRootAction, true] call ace_interact_menu_fnc_addActionToClass;

{
    _x params [
        ["_actionTitle", "", [""]],
        ["_cargoClass", "", [""]],
        ["_cargoLabel", "", [""]]
    ];

    if !(isClass (configFile >> "CfgVehicles" >> _cargoClass)) then {
        continue;
    };

    private _action = [
        format ["Para42_LaatResupply_%1", _cargoClass],
        _cargoLabel,
        "",
        {
            params ["", "_caller", "_params"];
            _params params [
                ["_cargoClass", "", [""]],
                ["_cargoLabel", "", [""]]
            ];

            private _anchor = vehicle _caller;
            private _anchorPosATL = getPosATL _anchor;
            private _dropPosATL = [_anchorPosATL select 0, _anchorPosATL select 1, 0];

            [_caller, _cargoClass, _cargoLabel, _dropPosATL] call Para42_fnc_requestLaatAiResupply;
        },
        {
            params ["", "_player"];
            [_player] call Para42_fnc_hasResupplyAccess &&
            !(missionNamespace getVariable ["para42_laatAiResupplyInProgress", false])
        },
        {},
        [_cargoClass, _cargoLabel]
    ] call ace_interact_menu_fnc_createAction;

    ["CAManBase", 1, ["ACE_SelfActions", "Para42_LaatResupplyRoot", "Para42_LaatResupplyAiRoot"], _action, true] call ace_interact_menu_fnc_addActionToClass;
} forEach (missionNamespace getVariable ["para42_laatPresetCargo", []]);
