params ["_unit", "_anchor"];

if (!local _unit) exitWith {};
if (isNull _anchor) exitWith {};
if (_unit getVariable ["Para42_grappleBusy", false]) exitWith {};

private _data = _anchor getVariable ["Para42_grappleData", []];
if ((count _data) < 8) exitWith {};

private _isValidPos = {
    params ["_pos"];
    (_pos isEqualType []) && {(count _pos) == 3}
};

private _surfaceNormal = _data select 3;
private _anchorPosASL = _data select 0;
private _ledgePosASL = _data select 4;
private _climbTopPosASL = _data select 5;
private _lineStartPosASL = _data select 6;
private _bottomPosASL = _data select 2;
private _startHelper = _anchor getVariable ["Para42_grappleStartHelper", objNull];

private _lowerUsePosASL = [];
if !(isNull _startHelper) then {
    _lowerUsePosASL = getPosASL _startHelper;
} else {
    if ([_lineStartPosASL] call _isValidPos) then {
        _lowerUsePosASL = _lineStartPosASL;
    } else {
        if ([_bottomPosASL] call _isValidPos) then {
            _lowerUsePosASL = _bottomPosASL;
        };
    };
};

private _upperUsePosASL = [];
if ([_ledgePosASL] call _isValidPos) then {
    _upperUsePosASL = _ledgePosASL;
} else {
    if ([_climbTopPosASL] call _isValidPos) then {
        _upperUsePosASL = _climbTopPosASL;
    } else {
        if ([_anchorPosASL] call _isValidPos) then {
            _upperUsePosASL = _anchorPosASL;
        };
    };
};

private _moveUnitToTarget = {
    params ["_unit", "_anchor", "_endPosASL"];

    if (!local _unit) exitWith {};
    if (
        !(_endPosASL isEqualType []) ||
        {(count _endPosASL) != 3}
    ) exitWith {};

    private _startPosASL = getPosASL _unit;
    private _travelVector = _endPosASL vectorDiff _startPosASL;
    private _travelDistance = vectorMagnitude _travelVector;

    _unit setVariable ["Para42_grappleBusy", true];
    _unit setVariable ["Para42_grappleRappelling", true];
    _unit setVariable ["Para42_activeVerticalAnchor", _anchor];
    _unit allowDamage false;

    if (_travelDistance < 0.15) exitWith {
        _unit setVariable ["Para42_grappleBusy", false];
        _unit setVariable ["Para42_grappleRappelling", false];
        _unit setVariable ["Para42_activeVerticalAnchor", objNull];
        if (alive _unit) then {
            _unit allowDamage true;
        };
    };

    private _duration = _travelDistance / 2.8;
    if (_duration < 0.6) then {
        _duration = 0.6;
    };
    if (_duration > 2.5) then {
        _duration = 2.5;
    };

    _unit playMoveNow "AmovPercMstpSrasWrflDnon";

    private _startTime = time;

    while {alive _unit && {(time - _startTime) < _duration}} do {
        if (!isNull objectParent _unit) exitWith {};

        private _alpha = (time - _startTime) / _duration;
        private _currentPosASL = _startPosASL vectorAdd (_travelVector vectorMultiply _alpha);

        _unit setVelocity [0, 0, 0];
        _unit setPosASL _currentPosASL;

        uiSleep 0.01;
    };

    if (alive _unit && {isNull objectParent _unit}) then {
        _unit setVelocity [0, 0, 0];
        _unit setPosASL _endPosASL;
    };

    _unit setVariable ["Para42_grappleBusy", false];
    _unit setVariable ["Para42_grappleRappelling", false];
    _unit setVariable ["Para42_activeVerticalAnchor", objNull];

    uiSleep 0.5;

    if (alive _unit) then {
        _unit allowDamage true;
    };
};

private _unitPosASL = getPosASL _unit;
private _distToLower = if ([_lowerUsePosASL] call _isValidPos) then {_unitPosASL distance _lowerUsePosASL} else {1e9};
private _distToUpper = if ([_upperUsePosASL] call _isValidPos) then {_unitPosASL distance _upperUsePosASL} else {1e9};

if (_distToUpper < _distToLower) exitWith {
    [_unit, _anchor, _lowerUsePosASL] spawn _moveUnitToTarget;
};

[_unit, _anchor, false, 1.25, true] call Para42_fnc_startGrapplePull;
