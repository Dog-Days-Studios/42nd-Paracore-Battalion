if (!isServer) exitWith {false};

private _enabled = missionNamespace getVariable ["Para42_playerTracker_enabled", false];
private _endpoint = missionNamespace getVariable ["Para42_playerTracker_targetServerEndpoint", ""];

if (!_enabled) exitWith
{
    diag_log "[42nd Player Tracker] Tracker disabled in addon options.";
    false
};

if (_endpoint isEqualTo "") exitWith
{
    diag_log "[42nd Player Tracker] Tracker enabled but no server endpoint was configured. Tracker will stay inactive.";
    false
};

private _trackerData = [_endpoint] call Para42_fnc_loadPlayerTrackerData;
missionNamespace setVariable ["Para42_playerTracker_endpoint", _endpoint];
missionNamespace setVariable ["Para42_playerTracker_records", _trackerData param [0, createHashMap]];
missionNamespace setVariable ["Para42_playerTracker_events", _trackerData param [1, []]];
missionNamespace setVariable ["Para42_playerTracker_lastSaveTick", -1];
missionNamespace setVariable ["Para42_playerTracker_unsavedChanges", 0];

diag_log format [
    "[42nd Player Tracker] Started for endpoint %1 on server '%2'.",
    _endpoint,
    serverName
];

addMissionEventHandler [
    "PlayerConnected",
    {
        params ["_id", "_uid", "_name", "_jip", "_owner", "_idStr"];
        ["join", _uid, _name, [_id, _jip, _owner, _idStr]] call Para42_fnc_recordPlayerTrackerEvent;
    }
];

addMissionEventHandler [
    "PlayerDisconnected",
    {
        params ["_id", "_uid", "_name", "_jip", "_owner", "_idStr"];
        ["disconnect", _uid, _name, [_id, _jip, _owner, _idStr]] call Para42_fnc_recordPlayerTrackerEvent;
    }
];

addMissionEventHandler [
    "EntityKilled",
    {
        params ["_unit", "_killer", "_instigator", "_useEffects"];

        private _killerPlayer = objNull;
        if (!isNull _instigator && {isPlayer _instigator}) then
        {
            _killerPlayer = _instigator;
        };

        if (isNull _killerPlayer && {!isNull _killer}) then
        {
            if (isPlayer _killer) then
            {
                _killerPlayer = _killer;
            };

            if (isNull _killerPlayer && {!(_killer isKindOf "CAManBase")}) then
            {
                {
                    if (isNull _killerPlayer && {!isNull _x} && {isPlayer _x}) then
                    {
                        _killerPlayer = _x;
                    };
                } forEach [effectiveCommander _killer, gunner _killer, driver _killer, commander _killer];
            };
        };

        if (
            !isNull _killerPlayer &&
            {_killerPlayer != _unit} &&
            {_unit isKindOf "CAManBase"}
        ) then
        {
            ["kill", getPlayerUID _killerPlayer, name _killerPlayer, [
                if (isPlayer _unit) then {getPlayerUID _unit} else {""},
                if (_unit isKindOf "CAManBase") then {typeOf _unit} else {typeOf vehicle _unit}
            ]] call Para42_fnc_recordPlayerTrackerEvent;
        };

        if (_unit isKindOf "CAManBase" && {isPlayer _unit}) then
        {
            ["death", getPlayerUID _unit, name _unit, [
                if (!isNull _killerPlayer) then {getPlayerUID _killerPlayer} else {""},
                if (!isNull _killerPlayer) then {name _killerPlayer} else {typeOf _killer}
            ]] call Para42_fnc_recordPlayerTrackerEvent;
        };
    }
];

if (!isDedicated) then
{
    {
        if (isPlayer _x) then
        {
            ["join", getPlayerUID _x, name _x, ["startup-scan"]] call Para42_fnc_recordPlayerTrackerEvent;
        };
    } forEach allPlayers;
};

[
    true,
    _endpoint,
    missionNamespace getVariable ["Para42_playerTracker_records", createHashMap],
    missionNamespace getVariable ["Para42_playerTracker_events", []]
] call Para42_fnc_persistPlayerTrackerData;

true
