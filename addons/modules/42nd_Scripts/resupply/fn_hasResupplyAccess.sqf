params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

private _rankId = rankId _unit;
if (_rankId < 0) then {
    private _fallbackRanks = [
        "PRIVATE",
        "CORPORAL",
        "SERGEANT",
        "LIEUTENANT",
        "CAPTAIN",
        "MAJOR",
        "COLONEL",
        "GENERAL"
    ];

    _rankId = _fallbackRanks find (toUpper (rank _unit));
};

_rankId >= 2
