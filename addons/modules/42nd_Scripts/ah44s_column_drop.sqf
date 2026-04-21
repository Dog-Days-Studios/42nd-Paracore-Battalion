/*
    Backward-compatible wrapper for mission init usage.
    Usage:
    [this] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\ah44s_column_drop.sqf";

    The active implementation lives in the resupply folder.
*/

params [["_ah44", objNull, [objNull]]];
if (isNull _ah44) exitWith {};

[_ah44] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\ah44s_spawner.sqf";
