params ["_anchor"];

if (!isServer) exitWith {
    _this remoteExecCall ["Para42_fnc_removeGrappleServer", 2];
};

if (isNull _anchor) exitWith {};

private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
_anchors = _anchors select {!isNull _x && {_x isNotEqualTo _anchor}};
missionNamespace setVariable ["Para42_grappleAnchors", _anchors, true];

private _startHelper = _anchor getVariable ["Para42_grappleStartHelper", objNull];
private _persistentRope = _anchor getVariable ["Para42_grapplePersistentRope", objNull];
private _ropeVisual = _anchor getVariable ["Para42_grappleRopeVisual", objNull];

if !(isNull _persistentRope) then {
    ropeDestroy _persistentRope;
};

if !(isNull _ropeVisual) then {
    deleteVehicle _ropeVisual;
};

if !(isNull _startHelper) then {
    deleteVehicle _startHelper;
};

detach _anchor;
deleteVehicle _anchor;
