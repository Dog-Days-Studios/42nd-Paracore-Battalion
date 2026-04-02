params [["_endpoint", ""]];

private _records = createHashMap;
private _events = [];
private _store = profileNamespace getVariable ["Para42_playerTracker_store", []];

if !(_store isEqualType []) exitWith {[_records, _events]};

private _entryIndex = _store findIf {
    (_x isEqualType []) &&
    {count _x >= 3} &&
    {(_x select 0) isEqualTo _endpoint}
};

if (_entryIndex < 0) exitWith {[_records, _events]};

private _entry = _store select _entryIndex;
private _serializedRecords = _entry param [1, []];
private _serializedEvents = _entry param [2, []];

if (_serializedRecords isEqualType []) then
{
    {
        if ((_x isEqualType []) && {count _x >= 9}) then
        {
            _x params [
                ["_uid", ""],
                ["_lastName", ""],
                ["_names", []],
                ["_joins", 0],
                ["_kills", 0],
                ["_deaths", 0],
                ["_firstSeen", []],
                ["_lastJoin", []],
                ["_lastSeen", []]
            ];

            if (_uid isNotEqualTo "") then
            {
                _records set [
                    _uid,
                    createHashMapFromArray [
                        ["lastName", _lastName],
                        ["names", +_names],
                        ["joins", _joins],
                        ["kills", _kills],
                        ["deaths", _deaths],
                        ["firstSeen", +_firstSeen],
                        ["lastJoin", +_lastJoin],
                        ["lastSeen", +_lastSeen]
                    ]
                ];
            };
        };
    } forEach _serializedRecords;
};

if (_serializedEvents isEqualType []) then
{
    _events = +_serializedEvents;
};

[_records, _events]
