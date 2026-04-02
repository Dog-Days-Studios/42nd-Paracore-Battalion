params [
    ["_unit", objNull, [objNull]],
    ["_preserveVelocity", true, [true]]
];

if (isNull _unit) exitWith {};

private _velocity = velocity _unit;
(_unit getVariable ["Para42_activeGrappleObjects", []]) params [
    ["_rope", objNull],
    ["_anchor", objNull],
    ["_attached", objNull],
    ["_ropeVisual", objNull]
];

if !(isNull _rope) then {
    ropeDestroy _rope;
};

if !(isNull _ropeVisual) then {
    deleteVehicle _ropeVisual;
};

if !(isNull _attached) then {
    detach _attached;
    deleteVehicle _attached;
};

_unit setVariable ["Para42_grapplePulling", false];
_unit setVariable ["Para42_grappleRappelling", false];
_unit setVariable ["Para42_activeGrappleObjects", nil];
_unit setVariable ["Para42_activeVerticalAnchor", objNull];
_unit setVariable ["Para42_grappleBusy", false];

if (!alive _unit || {!isNull objectParent _unit}) exitWith {};

if (_preserveVelocity) then {
    if (isTouchingGround _unit) then {
        _unit setVelocity [0, 0, 0];
    } else {
        _unit setVelocity _velocity;
    };
} else {
    _unit setVelocity [0, 0, 0];
};
