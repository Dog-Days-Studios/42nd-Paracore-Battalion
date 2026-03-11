params [
    ["_target", objNull, [objNull]],
    ["_caller", objNull, [objNull]]
];

if (!isServer) exitWith {
    [_target, _caller] remoteExecCall ["CTHUD_fnc_requestJoinGroup", 2];
};

if (isNull _target || {isNull _caller}) exitWith {};
if (!alive _target || {!alive _caller}) exitWith {};
if (_target isEqualTo _caller) exitWith {};

if (leader group _caller != _caller) exitWith {
    ["Only the group leader can add members."] remoteExecCall ["hint", owner _caller];
};

if (group _target isEqualTo group _caller) exitWith {
    [format ["%1 is already in your group.", name _target]] remoteExecCall ["hint", owner _caller];
};

if (local _target) then
{
    [_target, _caller] call CTHUD_fnc_joinGroupLocal;
}
else
{
    [_target, _caller] remoteExecCall ["CTHUD_fnc_joinGroupLocal", owner _target];
};

[format ["%1 joined your group.", name _target]] remoteExecCall ["hint", owner _caller];
if (isPlayer _target) then
{
    [format ["You joined %1's group.", name _caller]] remoteExecCall ["hint", owner _target];
}
