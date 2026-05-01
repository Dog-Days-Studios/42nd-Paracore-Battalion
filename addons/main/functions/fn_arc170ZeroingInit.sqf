if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["Para42_arc170ZeroingInitDone", false]) exitWith {};
missionNamespace setVariable ["Para42_arc170ZeroingInitDone", true];

// =============================================================
// ARC-170 Gunship: one-button "zero-on-target" for the WSO seat.
// Casts a ray from the gunner's optic centre, finds the impact
// point, sets weapon zeroing to the gun-to-impact distance.
// =============================================================

Para42_arc170Zeroing_minRange = 200;
Para42_arc170Zeroing_maxRange = 8000;

Para42_fnc_arc170Gunship_isGunnerTurret = {
    private _veh = vehicle player;
    if (_veh isEqualTo player) exitWith {false};
    if !(_veh isKindOf "42nd_Arc170_Gunship") exitWith {false};
    if (player isEqualTo (driver _veh)) exitWith {false};
    true
};

Para42_fnc_arc170Gunship_findPlayerTurretPath = {
    params ["_veh"];
    private _path = [];
    {
        if ((_x select 0) isEqualTo player) exitWith {
            _path = _x select 3;
        };
    } forEach (fullCrew [_veh, "", true]);
    _path
};

Para42_fnc_arc170Gunship_findAimPoint = {
    params ["_veh"];

    // Ray from the gunner camera straight forward (centre of reticle).
    private _camPos = positionCameraToWorld [0, 0, 0];
    private _camFwd = positionCameraToWorld [0, 0, 1];
    private _dir = _camFwd vectorDiff _camPos;
    if ((vectorMagnitude _dir) < 0.001) exitWith {[]};
    _dir = vectorNormalized _dir;

    private _start = _camPos;
    private _end = _camPos vectorAdd (_dir vectorMultiply Para42_arc170Zeroing_maxRange);

    private _hits = lineIntersectsSurfaces [
        AGLToASL _start,
        AGLToASL _end,
        _veh,
        objNull,
        true,
        1,
        "GEOM",
        "NONE"
    ];

    if (_hits isNotEqualTo []) exitWith { ASLToAGL ((_hits select 0) select 0) };

    // No solid hit - intersect with ground plane (Z=0 ASL).
    private _camASL = AGLToASL _camPos;
    private _dz = _dir select 2;
    if (_dz >= -0.001) exitWith {[]};   // not aiming downward, no orbit-style ground intercept
    private _t = -((_camASL select 2)) / _dz;
    if (_t < Para42_arc170Zeroing_minRange) exitWith {[]};
    private _hitASL = [
        (_camASL select 0) + (_dir select 0) * _t,
        (_camASL select 1) + (_dir select 1) * _t,
        0
    ];
    ASLToAGL _hitASL
};

Para42_fnc_arc170ZeroOnTarget = {
    if !(call Para42_fnc_arc170Gunship_isGunnerTurret) exitWith {
        hintSilent "ARC-170: must be in the WSO turret to zero on target.";
    };
    private _veh = vehicle player;
    private _aimPoint = [_veh] call Para42_fnc_arc170Gunship_findAimPoint;
    if (_aimPoint isEqualTo []) exitWith {
        hintSilent "ARC-170: no target under the reticle.";
    };

    private _turretPath = [_veh] call Para42_fnc_arc170Gunship_findPlayerTurretPath;
    if (_turretPath isEqualTo []) exitWith {
        hintSilent "ARC-170: could not resolve turret path.";
    };

    // Use the active turret's own gunBeg memory point so this works regardless
    // of which turret has the weapons.
    private _turretCfg = [typeOf _veh, _turretPath] call BIS_fnc_turretConfig;
    private _muzzleSel = getText (_turretCfg >> "gunBeg");
    if (_muzzleSel isEqualTo "") then { _muzzleSel = "usti hlavne b" };
    private _muzzlePos = _veh modelToWorld (_veh selectionPosition _muzzleSel);
    private _dist = _muzzlePos distance _aimPoint;
    _dist = (_dist max Para42_arc170Zeroing_minRange) min Para42_arc170Zeroing_maxRange;

    private _wep = currentWeapon _veh;
    private _muz = currentMuzzle _veh;
    _veh setWeaponZeroing [_wep, _muz, _dist, _turretPath];
    _veh setVariable ["Para42_arc170_zeroDistance", _dist, false];

    hintSilent format ["Zero set: %1 m\n%2", round _dist, _wep];
};

// ============================================================
// CBA keybind (rebindable in Options > Controls > Configure
// Addon Actions > 42nd Paracore Battalion > ARC-170 Gunship)
// ============================================================

[
    ["42nd Paracore Battalion", "ARC-170 Gunship"],
    "Para42_arc170_zeroOnTarget",
    "Zero on Target",
    { call Para42_fnc_arc170ZeroOnTarget },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
