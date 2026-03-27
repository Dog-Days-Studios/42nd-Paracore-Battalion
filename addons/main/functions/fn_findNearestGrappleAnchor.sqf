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

    if (_ropeLengthSquared > 0.01) then {
        private _ropeAlpha = ((_unitPosASL vectorDiff _lineStartPosASL) vectorDotProduct _ropeVector) / _ropeLengthSquared;
        _ropeAlpha = (_ropeAlpha max 0) min 1;
        _nearestPointASL = _lineStartPosASL vectorAdd (_ropeVector vectorMultiply _ropeAlpha);
    };

    private _distance = _unit distance (ASLToAGL _nearestPointASL);

    if (_distance < _bestDistance) then {
        _bestAnchor = _x;
        _bestDistance = _distance;
    };
} forEach _anchors;

_bestAnchor
