params [
    ["_shipClass", "", [""]],
    ["_startPosASL", [0, 0, 0], [[]]],
    ["_jumpPosASL", [0, 0, 0], [[]]],
    ["_anchorPosASL", [0, 0, 0], [[]]],
    ["_displayDir", 0, [0]],
    ["_jumpDuration", 0.5, [0]],
    ["_driftDuration", 8, [0]]
];

if (!hasInterface) exitWith {false};
if (_shipClass isEqualTo "") exitWith {false};
if !(isClass (configFile >> "CfgVehicles" >> _shipClass)) exitWith {false};

[
    _shipClass,
    +_startPosASL,
    +_jumpPosASL,
    +_anchorPosASL,
    _displayDir,
    _jumpDuration,
    _driftDuration
] spawn
{
    params [
        "_shipClass",
        "_startPosASL",
        "_jumpPosASL",
        "_anchorPosASL",
        "_displayDir",
        "_jumpDuration",
        "_driftDuration"
    ];

    private _ship = createVehicleLocal [_shipClass, ASLToATL _startPosASL, [], 0, "CAN_COLLIDE"];
    if (isNull _ship) exitWith {};

    private _displayVector = [sin _displayDir, cos _displayDir, 0];

    _ship allowDamage false;
    _ship enableSimulation false;
    _ship setFeatureType 2;
    _ship setPosASL _startPosASL;
    _ship setDir _displayDir;
    _ship setVectorDirAndUp [_displayVector, [0, 0, 1]];

    private _animateSegment =
    {
        params ["_object", "_from", "_to", "_duration", ["_easeOut", false]];

        if (_duration <= 0) exitWith
        {
            if (!isNull _object) then
            {
                _object setPosASL _to;
            };
        };

        private _travel = _to vectorDiff _from;
        private _segmentStart = diag_tickTime;

        while {!isNull _object} do
        {
            private _alpha = ((diag_tickTime - _segmentStart) / _duration) min 1;
            private _progress = if (_easeOut) then {1 - ((1 - _alpha) ^ 3)} else {_alpha};

            _object setPosASL (_from vectorAdd (_travel vectorMultiply _progress));

            if (_alpha >= 1) exitWith {};
            sleep 0.01;
        };

        if (!isNull _object) then
        {
            _object setPosASL _to;
        };
    };

    private _jumpFlash =
    {
        params ["_positionASL"];

        private _light = "#lightpoint" createVehicleLocal [0, 0, 0];
        _light setPosASL _positionASL;
        _light setLightDayLight true;
        _light setLightUseFlare true;
        _light setLightFlareSize 80;
        _light setLightFlareMaxDistance 6000;
        _light setLightBrightness 120;
        _light setLightAmbient [0.1, 0.35, 0.8];
        _light setLightColor [0.35, 0.7, 1];
        _light setLightAttenuation [0, 0, 0.15, 0, 900, 1400];

        if ((eyePos player vectorDistance _positionASL) < 6000) then
        {
            addCamShake [5, 0.8, 30];
        };

        [_light] spawn
        {
            params ["_flashLight"];
            sleep 0.2;

            if (!isNull _flashLight) then
            {
                deleteVehicle _flashLight;
            };
        };
    };

    [_ship, _startPosASL, _jumpPosASL, _jumpDuration, false] call _animateSegment;
    [_jumpPosASL] call _jumpFlash;
    [_ship, _jumpPosASL, _anchorPosASL, _driftDuration, true] call _animateSegment;

    if (!isNull _ship) then
    {
        deleteVehicle _ship;
    };
};

true
