/*
    Usage:
    [] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\venator_spawner.sqf";

    Manual usage:
    [player, "ls_staticShip_venator"] call para42_fnc_spawnVenatorServer;
*/

if (isNil "para42_venatorVariants") then {
    para42_venatorVariants = [
        ["Closed", "ls_staticShip_venator"],
        ["Closed Hollow", "ls_staticShip_venator_hollow"],
        ["Closed Full Hollow", "ls_staticShip_venator_fullHollow"],
        ["Open", "ls_staticShip_venator_open"],
        ["Open Hollow", "ls_staticShip_venator_open_hollow"],
        ["Open Full Hollow", "ls_staticShip_venator_open_fullHollow"],
        ["Zeus", "ls_staticShip_venator_zeus"]
    ];
};

if (isNil "para42_fnc_venatorNotify") then {
    para42_fnc_venatorNotify = {
        params [
            ["_unit", objNull, [objNull]],
            ["_message", "", [""]]
        ];

        if (isNull _unit || {_message isEqualTo ""}) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_fnc_spawnVenatorServer") then {
    para42_fnc_spawnVenatorServer = {
        params [
            ["_caller", objNull, [objNull]],
            ["_className", "", [""]]
        ];

        if (!isServer) exitWith {
            [_caller, _className] remoteExecCall ["para42_fnc_spawnVenatorServer", 2];
        };

        if (isNull _caller || {_className isEqualTo ""}) exitWith {};

        private _cfg = configFile >> "CfgVehicles" >> _className;
        if !(isClass _cfg) exitWith {
            [_caller, format ["%1 is not loaded.", _className]] call para42_fnc_venatorNotify;
        };

        private _dir = getDirVisual _caller;
        private _spawnPosASL = (getPosASL _caller) vectorAdd [1500 * sin _dir, 1500 * cos _dir, 300];
        private _spawnPosATL = ASLToATL _spawnPosASL;
        private _venator = createVehicle [_className, _spawnPosATL, [], 0, "CAN_COLLIDE"];

        if (isNull _venator) exitWith {
            [_caller, "Venator spawn failed."] call para42_fnc_venatorNotify;
        };

        _venator setDir _dir;
        _venator setPosASL _spawnPosASL;
        _venator setVectorDirAndUp [[sin _dir, cos _dir, 0], [0, 0, 1]];
        _venator allowDamage false;
        _venator setVariable ["42nd_spawnedVenator", true, true];

        private _displayName = getText (_cfg >> "displayName");
        if (_displayName isEqualTo "") then {
            _displayName = _className;
        };

        [_caller, format ["Spawned %1 1500m ahead.", _displayName]] call para42_fnc_venatorNotify;
    };
};

if (!hasInterface) exitWith {};
if (isNil "ace_interact_menu_fnc_createAction") exitWith {};
if (isNil "ace_interact_menu_fnc_addActionToClass") exitWith {};
if (missionNamespace getVariable ["para42_venatorSpawnerActionsAdded", false]) exitWith {};
if !(isClass (configFile >> "CfgVehicles" >> "ls_staticShip_venator")) exitWith {};

missionNamespace setVariable ["para42_venatorSpawnerActionsAdded", true];

private _utilityRoot = [
    "Para42_UtilityRoot",
    "42nd Utilities",
    "",
    {},
    {true}
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions"], _utilityRoot, true] call ace_interact_menu_fnc_addActionToClass;

private _venatorRoot = [
    "Para42_VenatorRoot",
    "Venator Spawner",
    "",
    {},
    {true}
] call ace_interact_menu_fnc_createAction;

["CAManBase", 1, ["ACE_SelfActions", "Para42_UtilityRoot"], _venatorRoot, true] call ace_interact_menu_fnc_addActionToClass;

{
    _x params ["_label", "_className"];

    private _action = [
        format ["Para42_Venator_%1", _className],
        _label,
        "",
        {
            params ["", "_caller", "_params"];
            _params params ["_venatorClass"];
            [_caller, _venatorClass] call para42_fnc_spawnVenatorServer;
        },
        {true},
        {},
        [_className]
    ] call ace_interact_menu_fnc_createAction;

    ["CAManBase", 1, ["ACE_SelfActions", "Para42_UtilityRoot", "Para42_VenatorRoot"], _action, true] call ace_interact_menu_fnc_addActionToClass;
} forEach para42_venatorVariants;
