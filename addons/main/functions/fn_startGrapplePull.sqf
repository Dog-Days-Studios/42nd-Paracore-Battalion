params [
    ["_unit", objNull, [objNull]],
    ["_anchor", objNull, [objNull]],
    ["_fastAction", false, [false]],
    ["_detachDistance", 1, [0]],
    ["_autoTopOut", false, [false]]
];

if (!local _unit) exitWith {};
if (isNull _unit || {isNull _anchor}) exitWith {};
if (!alive _unit || {!isNull objectParent _unit}) exitWith {};
if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {};
if (_unit getVariable ["Para42_grapplePulling", false]) exitWith {};

private _attached = createVehicle ["B_static_AA_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
_attached allowDamage false;
_attached enableSimulationGlobal false;
_attached hideObjectGlobal true;
_attached disableCollisionWith _unit;
_attached attachTo [_unit, [0.25, 0.1, 0], "pelvis", true];

private _ropeLength = (_attached distance _anchor) + 2;
private _rope = ropeCreate [_anchor, [0, 0, 0], _attached, [0, 0, 0], _ropeLength];
ropeUnwind [_rope, ((_ropeLength max 1) * 20), 1, false];

private _initialVelocity = velocity _unit;
private _boostedVelocity = _initialVelocity vectorMultiply 1.5;
_boostedVelocity set [2, (_boostedVelocity select 2) max (_initialVelocity select 2)];

private _ropeVisual = _anchor getVariable ["Para42_grappleRopeVisual", objNull];

_unit setVariable ["Para42_grappleBusy", true];
_unit setVariable ["Para42_grapplePulling", true];
_unit setVariable ["Para42_grappleRappelling", !_fastAction];
_unit setVariable ["Para42_activeVerticalAnchor", _anchor];
_unit setVariable ["Para42_activeGrappleObjects", [_rope, _anchor, _attached, _ropeVisual]];
_unit allowDamage false;

[
    _unit,
    _anchor,
    _fastAction,
    _detachDistance,
    _autoTopOut,
    _boostedVelocity,
    diag_tickTime,
    diag_tickTime + 5,
    diag_tickTime + 0.5
] spawn {
    params [
        "_unit",
        "_anchor",
        "_fastAction",
        "_detachDistance",
        "_autoTopOut",
        "_boostedVelocity",
        "_startTime",
        "_endTimeInitVelocity",
        "_endTimeVelocityAcceleration"
    ];

    private _didReachAnchor = false;

    uiSleep 0.5;

    while {
        alive _unit &&
        {!isNull _anchor} &&
        {isNull objectParent _unit} &&
        {_unit getVariable ["Para42_grapplePulling", false]}
    } do {
        private _distance = _unit distance _anchor;
        private _speedCoef = if (_fastAction) then {
            linearConversion [_startTime, _endTimeVelocityAcceleration, diag_tickTime, 0.5, 20, true]
        } else {
            private _computedCoef = linearConversion [15, 0.75, _distance, 20, 0, true];
            _computedCoef max 0.2 // avoid zero velocity on long pull-distance
        };

        private _inVelocity = _boostedVelocity vectorMultiply (linearConversion [_startTime, _endTimeInitVelocity, diag_tickTime, 1, 0, true]);
        private _toHookVelocity = ((getPosWorld _unit) vectorFromTo (getPosWorld _anchor)) vectorMultiply _speedCoef;
        _unit setVelocity (_inVelocity vectorAdd _toHookVelocity vectorAdd [0, 0, (_toHookVelocity select 2)]);

        if (_distance <= _detachDistance) exitWith {
            _didReachAnchor = true;
        };

        if (_fastAction && {(diag_tickTime - _startTime) >= 5}) exitWith {};

        uiSleep 0.01;
    };

    private _shouldTopOut = (
        _didReachAnchor &&
        _autoTopOut &&
        alive _unit &&
        {isNull objectParent _unit}
    );

    [_unit, !_shouldTopOut] call Para42_fnc_stopGrapplePull;

    if (_shouldTopOut) then {
        [_unit, _anchor] call Para42_fnc_climbGrappleLedge;
    };

    uiSleep 0.5;

    if (alive _unit) then {
        _unit allowDamage true;
    };
};
