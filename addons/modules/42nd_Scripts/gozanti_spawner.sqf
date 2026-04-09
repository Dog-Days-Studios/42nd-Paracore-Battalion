/*
    Backward-compatible wrapper for legacy mission init usage.
    Old usage:
    [this] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\gozanti_spawner.sqf";

    The active implementation now lives in the resupply folder.
*/

params [["_gozanti", objNull, [objNull]]];
if (isNull _gozanti) exitWith {};

[_gozanti] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\gozanti_spawner.sqf";
