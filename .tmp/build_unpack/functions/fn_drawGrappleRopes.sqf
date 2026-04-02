if (!hasInterface) exitWith {};

private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];
private _ropeColor = [0.18, 0.12, 0.07, 0.95];
private _ropeWidth = 13;

private _drawThickLine3D = {
    params ["_startPosAGL", "_endPosAGL"];

    drawLine3D [
        _startPosAGL,
        _endPosAGL,
        _ropeColor,
        _ropeWidth
    ];
};

(player getVariable ["Para42_activeGrappleObjects", []]) params [
    ["_rope", objNull],
    ["_activeAnchor", objNull],
    ["_attached", objNull],
    ["_ropeVisual", objNull]
];

{
    if (isNull _x) then {
        continue;
    };

    private _data = _x getVariable ["Para42_grappleData", []];
    if ((count _data) < 8) then {
        continue;
    };

    private _lineStartPosASL = +(_data select 6);
    private _climbTopPosASL = _data select 5;
    private _ledgePosASL = _data select 4;
    private _anchorPosASL = _data select 0;
    private _topPosASL = getPosASL _x;
    private _startHelper = _x getVariable ["Para42_grappleStartHelper", objNull];
    private _upperUsePosASL = [];

    if (
        !(_lineStartPosASL isEqualType []) ||
        {(count _lineStartPosASL) != 3}
    ) then {
        continue;
    };

    if !(isNull _startHelper) then {
        _lineStartPosASL = getPosASL _startHelper;
    };

    if (
        (_ledgePosASL isEqualType []) &&
        {(count _ledgePosASL) == 3}
    ) then {
        _upperUsePosASL = _ledgePosASL;
    } else {
        if (
            (_climbTopPosASL isEqualType []) &&
            {(count _climbTopPosASL) == 3}
        ) then {
            _upperUsePosASL = _climbTopPosASL;
        } else {
            if (
                (_anchorPosASL isEqualType []) &&
                {(count _anchorPosASL) == 3}
            ) then {
                _upperUsePosASL = _anchorPosASL;
            };
        };
    };

    if (
        ((player distance (ASLToAGL _lineStartPosASL)) <= 60) ||
        {(player distance (ASLToAGL _topPosASL)) <= 60}
    ) then {
        if (isNull _attached || {_x isNotEqualTo _activeAnchor}) then {
            [
                ASLToAGL _lineStartPosASL,
                ASLToAGL _topPosASL
            ] call _drawThickLine3D;
        };
    };

    if ((player distance (ASLToAGL _lineStartPosASL)) <= 25) then {
        drawIcon3D [
            "\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_Rangefinder_co.paa",
            [1, 1, 1, 0.8],
            ASLToAGL (_lineStartPosASL vectorAdd [0, 0, 0.35]),
            0.7,
            0.7,
            0,
            "Use Grapple Rope",
            2,
            0.03,
            "PuristaMedium"
        ];
    };

    if (
        (_upperUsePosASL isEqualType []) &&
        {(count _upperUsePosASL) == 3} &&
        {(player distance (ASLToAGL _upperUsePosASL)) <= 15}
    ) then {
        drawIcon3D [
            "\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_Rangefinder_co.paa",
            [0.85, 0.95, 1, 0.65],
            ASLToAGL (_upperUsePosASL vectorAdd [0, 0, 0.35]),
            0.6,
            0.6,
            0,
            "Use Grapple Rope",
            2,
            0.03,
            "PuristaMedium"
        ];
    };
} forEach _anchors;

if (!isNull _activeAnchor && {!isNull _attached}) then {
    [
        ASLToAGL (getPosASL _attached),
        ASLToAGL (getPosASL _activeAnchor)
    ] call _drawThickLine3D;
};
