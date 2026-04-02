params [
    ["_forceSave", false],
    ["_endpoint", ""],
    ["_records", createHashMap],
    ["_events", []]
];

private _historyLimit = missionNamespace getVariable ["Para42_playerTracker_maxEventHistory", 500];
private _trimmedEvents = +_events;

if ((count _trimmedEvents) > _historyLimit) then
{
    _trimmedEvents = _trimmedEvents select [(count _trimmedEvents) - _historyLimit, _historyLimit];
};

missionNamespace setVariable ["Para42_playerTracker_events", _trimmedEvents];

private _pendingChanges = (missionNamespace getVariable ["Para42_playerTracker_unsavedChanges", 0]) + 1;
missionNamespace setVariable ["Para42_playerTracker_unsavedChanges", _pendingChanges];

private _lastSaveTick = missionNamespace getVariable ["Para42_playerTracker_lastSaveTick", -1];
if (
    !_forceSave &&
    {_pendingChanges < 10} &&
    {_lastSaveTick >= 0} &&
    {(diag_tickTime - _lastSaveTick) < 30}
) exitWith {};

private _serializedRecords = [];
{
    private _record = _records get _x;
    _serializedRecords pushBack [
        _x,
        _record getOrDefault ["lastName", ""],
        +(_record getOrDefault ["names", []]),
        _record getOrDefault ["joins", 0],
        _record getOrDefault ["kills", 0],
        _record getOrDefault ["deaths", 0],
        +(_record getOrDefault ["firstSeen", []]),
        +(_record getOrDefault ["lastJoin", []]),
        +(_record getOrDefault ["lastSeen", []])
    ];
} forEach (keys _records);

private _store = +(profileNamespace getVariable ["Para42_playerTracker_store", []]);
if !(_store isEqualType []) then
{
    _store = [];
};

private _entry = [_endpoint, _serializedRecords, _trimmedEvents];
private _entryIndex = _store findIf {
    (_x isEqualType []) &&
    {count _x >= 1} &&
    {(_x select 0) isEqualTo _endpoint}
};

if (_entryIndex < 0) then
{
    _store pushBack _entry;
}
else
{
    _store set [_entryIndex, _entry];
};

profileNamespace setVariable ["Para42_playerTracker_store", _store];
saveProfileNamespace;

missionNamespace setVariable ["Para42_playerTracker_lastSaveTick", diag_tickTime];
missionNamespace setVariable ["Para42_playerTracker_unsavedChanges", 0];

true
