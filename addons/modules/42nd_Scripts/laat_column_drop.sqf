/*
    Backward-compatible wrapper for legacy mission init usage.
    Old usage:
    [this] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\laat_column_drop.sqf";

    The active implementation now lives in the resupply folder.
*/

params [["_laat", objNull, [objNull]]];
if (isNull _laat) exitWith {};

[_laat] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\laat_spawner.sqf";
