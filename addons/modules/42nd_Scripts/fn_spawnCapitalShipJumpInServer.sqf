params [
    ["_logic", objNull, [objNull]],
    ["_shipClass", "ls_staticShip_venator_zeus", [""]],
    ["_spawnHeight", 2000, [0]],
    ["_heading", -1, [0]],
    ["_cruiseSpeed", 40, [0]],
    ["_moveForever", false, [false]]
];

if (!isServer) exitWith
{
    [_logic, _shipClass, _spawnHeight, _heading, _cruiseSpeed, _moveForever] remoteExecCall ["Para42_fnc_spawnCapitalShipJumpInServer", 2];
    objNull
};

if (isNull _logic || {_shipClass isEqualTo ""}) exitWith {objNull};
if (_logic getVariable ["42nd_capitalShipJumpQueued", false]) exitWith {objNull};

_logic setVariable ["42nd_capitalShipJumpQueued", true, true];

if !(isClass (configFile >> "CfgVehicles" >> _shipClass)) exitWith
{
    deleteVehicle _logic;
    objNull
};

private _modulePosASL = getPosASL _logic;
private _finalAltitude = _spawnHeight max 0;
private _anchorPosASL = _modulePosASL vectorAdd [0, 0, _finalAltitude];
private _travelDir = if (_heading < 0) then {getDir _logic} else {_heading};

private _jumpSettings = [_shipClass, _finalAltitude] call Para42_fnc_getCapitalShipJumpSettings;
_jumpSettings params [
    ["_startDistance", 5000, [0]],
    ["_jumpDistance", 1000, [0]],
    ["_jumpDuration", 0.4, [0]],
    ["_driftDuration", 6.5, [0]],
    ["_dirOffset", 0, [0]]
];

private _displayDir = (_travelDir + _dirOffset + 360) % 360;
private _travelVector = [sin _travelDir, cos _travelDir, 0];
private _displayVector = [sin _displayDir, cos _displayDir, 0];
private _startPosASL = _anchorPosASL vectorDiff (_travelVector vectorMultiply _startDistance);
private _jumpPosASL = _anchorPosASL vectorDiff (_travelVector vectorMultiply _jumpDistance);
private _animationDuration = _jumpDuration + _driftDuration;
private _safeCruiseSpeed = _cruiseSpeed max 0;

[
    _shipClass,
    +_startPosASL,
    +_jumpPosASL,
    +_anchorPosASL,
    _displayDir,
    _jumpDuration,
    _driftDuration
] remoteExec ["Para42_fnc_playCapitalShipJumpInLocal", 0, false];

[
    _logic,
    _shipClass,
    +_anchorPosASL,
    _travelDir,
    _displayDir,
    +_travelVector,
    _safeCruiseSpeed,
    _moveForever,
    _animationDuration
] spawn
{
    params [
        "_logic",
        "_shipClass",
        "_anchorPosASL",
        "_travelDir",
        "_displayDir",
        "_travelVector",
        "_cruiseSpeed",
        "_moveForever",
        "_animationDuration"
    ];

    private _displayVector = [sin _displayDir, cos _displayDir, 0];

    sleep _animationDuration;

    private _ship = createVehicle [_shipClass, ASLToATL _anchorPosASL, [], 0, "CAN_COLLIDE"];
    if (isNull _ship) exitWith
    {
        if (!isNull _logic) then
        {
            deleteVehicle _logic;
        };
    };

    _ship allowDamage false;
    _ship enableSimulationGlobal false;
    _ship setVariable ["42nd_capitalShipSpawned", true, true];
    _ship setVariable ["42nd_capitalShipCruiseSpeed", _cruiseSpeed, true];
    _ship setVariable ["42nd_capitalShipMoveForever", _moveForever, true];
    _ship setPosASL _anchorPosASL;
    _ship setDir _displayDir;
    _ship setVectorDirAndUp [_displayVector, [0, 0, 1]];
    _ship setVelocity [0, 0, 0];

    {
        _x addCuratorEditableObjects [[_ship], false];
    } forEach allCurators;

    if (!isNull _logic) then
    {
        deleteVehicle _logic;
    };

    if (_cruiseSpeed <= 0) exitWith {};

    private _holdPosASL = +_anchorPosASL;
    private _cruiseStart = diag_tickTime;
    private _lastTick = diag_tickTime;
    private _defaultCruiseDuration = 30;

    while {!isNull _ship} do
    {
        private _now = diag_tickTime;
        private _delta = (_now - _lastTick) max 0.01;
        _lastTick = _now;

        _holdPosASL = _holdPosASL vectorAdd (_travelVector vectorMultiply (_cruiseSpeed * _delta));
        _ship setPosASL _holdPosASL;
        _ship setDir _displayDir;
        _ship setVectorDirAndUp [_displayVector, [0, 0, 1]];
        _ship setVelocity [0, 0, 0];

        if (!_moveForever && {(_now - _cruiseStart) >= _defaultCruiseDuration}) exitWith {};
        sleep 0.05;
    };

    if (!isNull _ship) then
    {
        _ship setPosASL _holdPosASL;
        _ship setDir _displayDir;
        _ship setVectorDirAndUp [_displayVector, [0, 0, 1]];
        _ship setVelocity [0, 0, 0];
    };
};

objNull
