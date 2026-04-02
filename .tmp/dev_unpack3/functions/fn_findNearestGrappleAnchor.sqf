params [
    ["_unit", player, [objNull]],
    ["_useCase", "rope", [""]],
    ["_maxDistance", -1, [0]]
];

_useCase = toLower _useCase;

if (_maxDistance < 0) then {
    _maxDistance = 4.5;
};

private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
private _bestAnchor = objNull;
private _bestDistance = _maxDistance + 0.001;
private _unitPosASL = getPosASL _unit;

private _isValidPos = {
    params ["_pos"];
    (_pos isEqualType []) && {(count _pos) == 3}
};

{
    if (isNull _x) then {
        continue;
    };

    private _data = _x getVariable ["Para42_grappleData", []];
    if ((count _data) < 8) then {
        continue;
    };

    private _lineStartPosASL = _data select 6;
    private _lineEndPosASL = _data select 7;

    if (
        !(_lineStartPosASL isEqualType []) ||
        {(count _lineStartPosASL) != 3} ||
        {!(_lineEndPosASL isEqualType [])} ||
        {(count _lineEndPosASL) != 3}
    ) then {
        continue;
    };

    private _ropeVector = _lineEndPosASL vectorDiff _lineStartPosASL;
    private _ropeLengthSquared = _ropeVector vectorDotProduct _ropeVector;
    private _nearestPointASL = _lineStartPosASL;
    private _distance = 1e9;

    if (_ropeLengthSquared > 0.01) then {
        private _ropeAlpha = ((_unitPosASL vectorDiff _lineStartPosASL) vectorDotProduct _ropeVector) / _ropeLengthSquared;
        _ropeAlpha = (_ropeAlpha max 0) min 1;
        _nearestPointASL = _lineStartPosASL vectorAdd (_ropeVector vectorMultiply _ropeAlpha);
    };

    _distance = _unit distance (ASLToAGL _nearestPointASL);

    private _topUsePosASL = [];
    private _ledgePosASL = _data select 4;
    private _climbTopPosASL = _data select 5;
    private _anchorPosASL = _data select 0;

    if ([_ledgePosASL] call _isValidPos) then {
        _topUsePosASL = _ledgePosASL;
    } else {
        if ([_climbTopPosASL] call _isValidPos) then {
            _topUsePosASL = _climbTopPosASL;
        } else {
            if ([_anchorPosASL] call _isValidPos) then {
                _topUsePosASL = _anchorPosASL;
            };
        };
    };

    if ([_topUsePosASL] call _isValidPos) then {
        _distance = _distance min (_unit distance (ASLToAGL _topUsePosASL));
    };

    if (_distance < _bestDistance) then {
        _bestAnchor = _x;
        _bestDistance = _distance;
    };
} forEach _anchors;

_bestAnchor
