params [
    ["_unit", objNull, [objNull]],
    ["_anchor", objNull, [objNull]]
];

if (isNull _unit || {isNull _anchor}) exitWith {};
if (!local _unit) exitWith {};

[
    _unit,
    _anchor,
    diag_tickTime + 2
] spawn {
    params ["_unit", "_anchor", "_timeoutAt"];

    waitUntil {
        uiSleep 0.02;
        diag_tickTime >= _timeoutAt ||
        (
            !isNull _unit &&
            {!isNull _anchor} &&
            {count (_anchor getVariable ["Para42_grappleData", []]) >= 8}
        )
    };

    if (
        isNull _unit ||
        {isNull _anchor} ||
        {!alive _unit} ||
        {!isNull objectParent _unit}
    ) exitWith {};

    if (_unit getVariable ["Para42_grapplePulling", false]) then {
        [_unit, false] call Para42_fnc_stopGrapplePull;
        uiSleep 0.05;
    };

    if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {};

    [_unit, _anchor] call Para42_fnc_climbGrapple;
};
