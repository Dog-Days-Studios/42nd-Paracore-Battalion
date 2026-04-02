params [
    ["_actionArgs", [], [[]]],
    ["_useCase", "rope", [""]]
];

private _caller = _actionArgs param [1, player, [objNull]];

if (isNull _caller) exitWith {};
if (!local _caller) exitWith {};
if (_caller getVariable ["Para42_grappleBusy", false]) exitWith {};
if (_caller getVariable ["Para42_grapplePulling", false]) exitWith {};

_useCase = toLower _useCase;

private _anchor = [_caller, _useCase] call Para42_fnc_findNearestGrappleAnchor;
if (isNull _anchor) exitWith {};

[_caller, _anchor] spawn Para42_fnc_climbGrapple;
