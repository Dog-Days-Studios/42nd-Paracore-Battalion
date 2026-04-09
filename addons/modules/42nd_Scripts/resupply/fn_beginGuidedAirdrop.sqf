params [
    ["_cargo", objNull, [objNull]],
    ["_parachute", objNull, [objNull]],
    ["_target", objNull, [objNull]],
    ["_smokeAmmo", "SmokeShellBlue", [""]],
    ["_maxDriftSpeed", 7, [0]],
    ["_detachHeight", 3, [0]]
];

if (isNull _cargo || {isNull _parachute}) exitWith {false};

private _smoke = objNull;
if (_smokeAmmo isNotEqualTo "" && {isClass (configFile >> "CfgAmmo" >> _smokeAmmo)}) then {
    _smoke = createVehicle [_smokeAmmo, getPosATL _cargo, [], 0, "CAN_COLLIDE"];
    if (!isNull _smoke) then {
        _smoke attachTo [_cargo, [0.2, 0, 0.45]];
        _smoke allowDamage false;
    };
};

[
    _cargo,
    _parachute,
    _target,
    _maxDriftSpeed max 0,
    _detachHeight max 0
] spawn {
    params [
        ["_cargo", objNull, [objNull]],
        ["_parachute", objNull, [objNull]],
        ["_target", objNull, [objNull]],
        ["_maxDriftSpeed", 7, [0]],
        ["_detachHeight", 3, [0]]
    ];

    while {
        !isNull _cargo &&
        {!isNull _parachute} &&
        {attachedTo _cargo isEqualTo _parachute} &&
        {!isTouchingGround _cargo} &&
        {(getPosATL _cargo select 2) > _detachHeight}
    } do {
        if (!isNull _target) then {
            private _targetAnchor = vehicle _target;
            if (isNull _targetAnchor) then {
                _targetAnchor = _target;
            };

            private _targetPosATL = getPosATL _targetAnchor;
            private _cargoPosATL = getPosATL _cargo;
            private _dx = (_targetPosATL select 0) - (_cargoPosATL select 0);
            private _dy = (_targetPosATL select 1) - (_cargoPosATL select 1);
            private _distance2D = sqrt ((_dx * _dx) + (_dy * _dy));

            if (_distance2D > 5) then {
                private _driftSpeed = linearConversion [0, 300, _distance2D, 0, _maxDriftSpeed, true];
                private _verticalVelocity = (velocity _parachute) param [2, -1];
                _parachute setVelocity [
                    (_dx / _distance2D) * _driftSpeed,
                    (_dy / _distance2D) * _driftSpeed,
                    _verticalVelocity min -0.5
                ];
            };
        };

        sleep 0.25;
    };

    if (!isNull _cargo) then {
        detach _cargo;
        _cargo setVelocity [0, 0, 0];
        _cargo allowDamage true;

        if (_cargo isKindOf "LandVehicle") then {
            _cargo setVectorUp (surfaceNormal (getPosATL _cargo));
        };
    };

    if (!isNull _parachute) then {
        deleteVehicle _parachute;
    };
};

true
