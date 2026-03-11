params [
    ["_target", objNull, [objNull]],
    ["_leader", objNull, [objNull]]
];

if (isNull _target || {isNull _leader}) exitWith {};
if (!local _target) exitWith {
    [_target, _leader] remoteExecCall ["CTHUD_fnc_joinGroupLocal", owner _target];
};
if (!alive _target || {!alive _leader}) exitWith {};

[_target] joinSilent (group _leader);
