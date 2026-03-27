if (!hasInterface) exitWith {};

private _anchors = missionNamespace getVariable ["Para42_grappleAnchors", []];

{
    if (isNull _x) then {
        continue;
    };

    private _data = _x getVariable ["Para42_grappleData", []];
    if ((count _data) < 8) then {
        continue;
    };

    private _lineStartPosASL = _data select 6;
    private _climbTopPosASL = _data select 5;

    if (
        !(_lineStartPosASL isEqualType []) ||
        {(count _lineStartPosASL) != 3}
    ) then {
        continue;
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
        (_climbTopPosASL isEqualType []) &&
        {(count _climbTopPosASL) == 3} &&
        {(player distance (ASLToAGL _climbTopPosASL)) <= 15}
    ) then {
        drawIcon3D [
            "\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_Rangefinder_co.paa",
            [0.85, 0.95, 1, 0.65],
            ASLToAGL (_climbTopPosASL vectorAdd [0, 0, 0.35]),
            0.6,
            0.6,
            0,
            "Grapple Exit",
            2,
            0.03,
            "PuristaMedium"
        ];
    };
} forEach _anchors;
