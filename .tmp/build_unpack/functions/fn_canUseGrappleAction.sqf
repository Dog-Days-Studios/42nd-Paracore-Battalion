params [["_useCase", "rope", [""]]];

if (!hasInterface) exitWith {false};
if (isNull player) exitWith {false};
if (!alive player) exitWith {false};
if (!isNull objectParent player) exitWith {false};
if (player getVariable ["Para42_grappleBusy", false]) exitWith {false};

_useCase = toLower _useCase;

if (player getVariable ["Para42_grapplePulling", false]) exitWith {false};

!isNull ([player, _useCase] call Para42_fnc_findNearestGrappleAnchor)
