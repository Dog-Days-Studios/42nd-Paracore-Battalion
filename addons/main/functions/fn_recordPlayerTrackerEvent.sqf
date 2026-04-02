params [
    ["_eventType", ""],
    ["_uid", ""],
    ["_name", ""],
    ["_extra", []]
];

private _endpoint = missionNamespace getVariable ["Para42_playerTracker_endpoint", ""];
if (
    !(missionNamespace getVariable ["Para42_playerTracker_enabled", false]) ||
    {_endpoint isEqualTo ""} ||
    {_uid isEqualTo ""} ||
    {(count _uid) >= 2 && {(_uid select [0, 2]) isEqualTo "HC"}}
) exitWith {false};

private _records = missionNamespace getVariable ["Para42_playerTracker_records", createHashMap];
private _events = missionNamespace getVariable ["Para42_playerTracker_events", []];
private _timestamp = systemTimeUTC;
private _record = _records getOrDefault [
    _uid,
    createHashMapFromArray [
        ["lastName", ""],
        ["names", []],
        ["joins", 0],
        ["kills", 0],
        ["deaths", 0],
        ["firstSeen", +_timestamp],
        ["lastJoin", []],
        ["lastSeen", []]
    ]
];

if (_name isNotEqualTo "") then
{
    _record set ["lastName", _name];

    private _knownNames = +(_record getOrDefault ["names", []]);
    if !(_name in _knownNames) then
    {
        _knownNames pushBack _name;
        _record set ["names", _knownNames];
    };
};

switch (_eventType) do
{
    case "join":
    {
        _record set ["joins", (_record getOrDefault ["joins", 0]) + 1];
        _record set ["lastJoin", +_timestamp];
        _record set ["lastSeen", +_timestamp];
    };
    case "disconnect":
    {
        _record set ["lastSeen", +_timestamp];
    };
    case "kill":
    {
        _record set ["kills", (_record getOrDefault ["kills", 0]) + 1];
        _record set ["lastSeen", +_timestamp];
    };
    case "death":
    {
        _record set ["deaths", (_record getOrDefault ["deaths", 0]) + 1];
        _record set ["lastSeen", +_timestamp];
    };
    default
    {
        _record set ["lastSeen", +_timestamp];
    };
};

_records set [_uid, _record];
_events pushBack [
    +_timestamp,
    _eventType,
    _uid,
    _record getOrDefault ["lastName", _name],
    _endpoint,
    +_extra
];

missionNamespace setVariable ["Para42_playerTracker_records", _records];
missionNamespace setVariable ["Para42_playerTracker_events", _events];

private _forceSave = _eventType in ["join", "disconnect"];
[_forceSave, _endpoint, _records, _events] call Para42_fnc_persistPlayerTrackerData;

diag_log format [
    "[42nd Player Tracker] endpoint=%1 event=%2 uid=%3 name=%4 extra=%5",
    _endpoint,
    toUpper _eventType,
    _uid,
    _record getOrDefault ["lastName", _name],
    _extra
];

true
