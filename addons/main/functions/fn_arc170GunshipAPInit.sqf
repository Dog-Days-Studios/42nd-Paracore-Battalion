if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["Para42_arc170GunshipAPInitDone", false]) exitWith {};
missionNamespace setVariable ["Para42_arc170GunshipAPInitDone", true];

// =============================================================
// ARC-170 Gunship Autopilot (orbit/hold) + crew utility keybinds
// Custom-coded replication of the AC-130 BETA gunship autopilot
// behaviour. All keybinds are registered through CBA so they are
// rebindable from Arma's controls menu (Configure Addon Actions).
// =============================================================

// Use the vanilla pilot — custom 42nd unit classes don't always satisfy the
// gunship's driverConfig and can refuse to take the seat. Override at runtime
// by setting `Para42_arc170Gunship_pilotType = "your_class";` if you want a
// different look.
Para42_arc170Gunship_pilotType = "B_Pilot_F";

Para42_arc170Gunship_apAltDefault = 1500;
Para42_arc170Gunship_apAltMin = 500;
Para42_arc170Gunship_apAltMax = 5000;
Para42_arc170Gunship_apAltStep = 100;

Para42_arc170Gunship_apRadiusDefault = 1500;
Para42_arc170Gunship_apRadiusMin = 300;
Para42_arc170Gunship_apRadiusMax = 5000;
Para42_arc170Gunship_apRadiusStep = 100;

// ============================================================
// Helpers
// ============================================================

Para42_fnc_arc170Gunship_isGunship = {
    params [["_veh", objNull, [objNull]]];
    !isNull _veh && {_veh isKindOf "42nd_Arc170_Gunship"}
};

Para42_fnc_arc170Gunship_playerVehicle = {
    private _veh = vehicle player;
    if (_veh isEqualTo player) exitWith {objNull};
    if !([_veh] call Para42_fnc_arc170Gunship_isGunship) exitWith {objNull};
    _veh
};

Para42_fnc_arc170Gunship_isDriver = {
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    if (isNull _veh) exitWith {false};
    player isEqualTo (driver _veh)
};

Para42_fnc_arc170Gunship_anyCrew = {
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    !isNull _veh
};

Para42_fnc_arc170Gunship_getOrCreateMarker = {
    params ["_veh", "_pos"];
    private _name = format ["Para42_arc170Gunship_apMkr_%1", _veh];
    private _ring = format ["%1_ring", _name];
    if ((getMarkerColor _name) isEqualTo "") then {
        createMarkerLocal [_name, _pos];
        _name setMarkerTypeLocal "hd_dot";
        _name setMarkerColorLocal "ColorRed";
        _name setMarkerTextLocal "ARC-170 Orbit";

        createMarkerLocal [_ring, _pos];
        _ring setMarkerShapeLocal "ELLIPSE";
        _ring setMarkerBrushLocal "Border";
        _ring setMarkerColorLocal "ColorRed";
    } else {
        _name setMarkerPosLocal _pos;
        _ring setMarkerPosLocal _pos;
    };
    private _r = _veh getVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault];
    _ring setMarkerSizeLocal [_r, _r];
};

Para42_fnc_arc170Gunship_clearMarker = {
    params ["_veh"];
    private _name = format ["Para42_arc170Gunship_apMkr_%1", _veh];
    private _ring = format ["%1_ring", _name];
    if ((getMarkerColor _name) isNotEqualTo "") then { deleteMarkerLocal _name };
    if ((getMarkerColor _ring) isNotEqualTo "") then { deleteMarkerLocal _ring };
};

// ============================================================
// Mark loiter target via map click
// ============================================================

Para42_fnc_arc170GunshipMarkTarget = {
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {};
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    missionNamespace setVariable ["Para42_arc170Gunship_pendingMarkVeh", _veh];

    openMap [true, false];
    hintSilent "Click the map to set ARC-170 orbit centre.\nESC / right-click cancels.";

    onMapSingleClick {
        params ["_units", "_pos", "_alt", "_shift"];
        private _veh = missionNamespace getVariable ["Para42_arc170Gunship_pendingMarkVeh", objNull];
        if (isNull _veh) exitWith { onMapSingleClick ""; openMap [false,false]; true };
        if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith { onMapSingleClick ""; openMap [false,false]; true };

        _veh setVariable ["Para42_arc170Gunship_apTargetPos", _pos, true];
        [_veh, _pos] call Para42_fnc_arc170Gunship_getOrCreateMarker;

        if (_veh getVariable ["Para42_arc170Gunship_apOn", false]) then {
            [_veh] call Para42_fnc_arc170Gunship_refreshWaypoint;
        };

        hintSilent format ["Orbit centre set: %1\nAlt %2m  Rad %3m  Dir %4",
            mapGridPosition _pos,
            _veh getVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault],
            _veh getVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault],
            ["CCW","CW"] select (_veh getVariable ["Para42_arc170Gunship_apDirCW", false])
        ];

        onMapSingleClick "";
        openMap [false, false];
        missionNamespace setVariable ["Para42_arc170Gunship_pendingMarkVeh", nil];
        true
    };
};

// ============================================================
// Waypoint creation / refresh
// ============================================================

Para42_fnc_arc170Gunship_refreshWaypoint = {
    params ["_veh"];
    if (isNull _veh) exitWith {};
    private _aiPilot = _veh getVariable ["Para42_arc170Gunship_apPilot", objNull];
    if (isNull _aiPilot) exitWith {};

    private _grp = group _aiPilot;
    private _pos = _veh getVariable ["Para42_arc170Gunship_apTargetPos", []];
    private _radius = _veh getVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault];
    private _altASL = _veh getVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault];
    private _dirCW = _veh getVariable ["Para42_arc170Gunship_apDirCW", false];

    if (count _pos < 2) exitWith {};

    // remove any existing waypoints
    while {waypoints _grp isNotEqualTo []} do { deleteWaypoint ((waypoints _grp) select 0) };

    private _wp = _grp addWaypoint [_pos, 0];
    _wp setWaypointType "LOITER";
    _wp setWaypointLoiterRadius _radius;
    _wp setWaypointLoiterType (["CIRCLE_L","CIRCLE"] select _dirCW);
    _wp setWaypointSpeed "NORMAL";
    _wp setWaypointBehaviour "CARELESS";
    _wp setWaypointCombatMode "BLUE";
    _grp setCurrentWaypoint _wp;
    _grp setSpeedMode "NORMAL";
    _grp setBehaviour "CARELESS";

    if (local _veh) then {
        _veh flyInHeightASL [_altASL, _altASL, _altASL];
    } else {
        [_veh, _altASL] remoteExec ["Para42_fnc_arc170Gunship_setHeightASL", _veh, false];
    };
};

Para42_fnc_arc170Gunship_setHeightASL = {
    params ["_veh", "_altASL"];
    if (local _veh) then { _veh flyInHeightASL [_altASL, _altASL, _altASL] };
};

// ============================================================
// Toggle autopilot
// ============================================================

Para42_fnc_arc170GunshipToggleAP = {
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {
        hintSilent "ARC-170 Autopilot: must be inside the gunship.";
    };
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    private _on = _veh getVariable ["Para42_arc170Gunship_apOn", false];

    if (_on) then {
        [_veh] call Para42_fnc_arc170Gunship_apOff;
    } else {
        [_veh] call Para42_fnc_arc170Gunship_apOn;
    };
};

Para42_fnc_arc170Gunship_apOn = {
    params ["_veh"];
    if (isNull _veh) exitWith {};
    if (_veh getVariable ["Para42_arc170Gunship_apOn", false]) exitWith {};
    if (_veh getVariable ["Para42_arc170Gunship_apStarting", false]) exitWith {};
    _veh setVariable ["Para42_arc170Gunship_apStarting", true, true];

    [_veh] spawn {
        params ["_veh"];

        // Default loiter pos = current vehicle position if none set
        private _pos = _veh getVariable ["Para42_arc170Gunship_apTargetPos", []];
        if (count _pos < 2) then {
            _pos = getPosWorld _veh;
            _pos = [_pos select 0, _pos select 1, 0];
            _veh setVariable ["Para42_arc170Gunship_apTargetPos", _pos, true];
            [_veh, _pos] call Para42_fnc_arc170Gunship_getOrCreateMarker;
        };

        if ((_veh getVariable ["Para42_arc170Gunship_apAlt", -1]) < 0) then {
            _veh setVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault, true];
        };
        if ((_veh getVariable ["Para42_arc170Gunship_apRadius", -1]) < 0) then {
            _veh setVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault, true];
        };

        private _humanDriver = driver _veh;
        _veh setVariable ["Para42_arc170Gunship_apOrigDriver", _humanDriver, true];

        // Move human pilot out of driver seat to a free turret/cargo (if any).
        // Arma's `moveInTurret` silently fails when the unit is already in the
        // same vehicle, so we have to vacate the seat first. `unassignVehicle`
        // + `moveOut` clears the assignment; the immediately-following
        // `moveInTurret` teleports them in the same engine tick, so there's no
        // visible mid-air ejection.
        if (!isNull _humanDriver) then {
            private _seatPath = [];
            private _seatType = "";   // "turret" or "cargo"

            // Prefer the primary-gunner (WSO) seat first - that's where a pilot
            // wants to land so they can immediately operate the weapons.
            {
                if (isNull (_veh turretUnit _x)) then {
                    private _cfg = [typeOf _veh, _x] call BIS_fnc_turretConfig;
                    if ((getNumber (_cfg >> "primaryGunner")) == 1) exitWith {
                        _seatPath = _x;
                        _seatType = "turret";
                    };
                };
            } forEach (allTurrets [_veh, true]);

            // Fallback: any other empty turret.
            if (_seatType isEqualTo "") then {
                {
                    if (isNull (_veh turretUnit _x)) exitWith {
                        _seatPath = _x;
                        _seatType = "turret";
                    };
                } forEach (allTurrets [_veh, true]);
            };

            if (_seatType isEqualTo "" && {(_veh emptyPositions "cargo") > 0}) then {
                _seatType = "cargo";
            };
            if (_seatType isEqualTo "") exitWith {
                _veh setVariable ["Para42_arc170Gunship_apStarting", false, true];
                hintSilent "ARC-170 Autopilot: no free seat to relocate the pilot. AP cancelled.";
            };

            // Atomic swap: clear driver assignment, eject, immediately re-seat.
            unassignVehicle _humanDriver;
            moveOut _humanDriver;
            switch (_seatType) do {
                case "turret":   { _humanDriver moveInTurret [_veh, _seatPath] };
                case "cargo":    { _humanDriver moveInCargo _veh };
            };

            // Brief wait to let the engine register the swap before the AI moves in.
            private _t0 = diag_tickTime;
            waitUntil {
                sleep 0.1;
                ((driver _veh) isNotEqualTo _humanDriver) || {(diag_tickTime - _t0) > 3}
            };

            if ((driver _veh) isEqualTo _humanDriver) exitWith {
                _veh setVariable ["Para42_arc170Gunship_apStarting", false, true];
                hintSilent "ARC-170 Autopilot: failed to vacate driver seat. AP cancelled.";
            };
        };

        // Create AI pilot in its own group so it carries its own waypoints
        private _grp = createGroup [side group player, true];
        private _aiPilot = _grp createUnit [Para42_arc170Gunship_pilotType, [0,0,0], [], 0, "NONE"];
        if (isNull _aiPilot) exitWith {
            _veh setVariable ["Para42_arc170Gunship_apStarting", false, true];
            hintSilent format ["ARC-170 Autopilot: failed to spawn AI pilot of type '%1'.", Para42_arc170Gunship_pilotType];
        };

        _aiPilot moveInDriver _veh;
        _aiPilot assignAsDriver _veh;

        // Wait for the AI to actually occupy driver. If the moveIn fails (e.g.
        // wrong unit class), the AI stays at world origin — bail and clean up.
        private _t1 = diag_tickTime;
        waitUntil {
            sleep 0.1;
            (driver _veh) isEqualTo _aiPilot || {(diag_tickTime - _t1) > 3}
        };

        if ((driver _veh) isNotEqualTo _aiPilot) exitWith {
            deleteVehicle _aiPilot;
            _veh setVariable ["Para42_arc170Gunship_apStarting", false, true];
            hintSilent format ["ARC-170 Autopilot: AI pilot ('%1') refused to enter the driver seat. AP cancelled.", Para42_arc170Gunship_pilotType];
        };

        _grp setBehaviour "CARELESS";
        _grp setCombatMode "BLUE";
        _grp setSpeedMode "NORMAL";
        _grp setFormation "FILE";

        // Don't disable FSM — that breaks waypoint following on planes.
        {_aiPilot disableAI _x} forEach ["AUTOCOMBAT","AUTOTARGET","TARGET","COVER","SUPPRESSION","WEAPONAIM","CHECKVISIBLE","MINEDETECTION","LIGHTS"];
        _aiPilot allowFleeing 0;
        _aiPilot setSkill 1;

        _veh setCollisionLight false;
        _veh engineOn true;

        _veh setVariable ["Para42_arc170Gunship_apPilot", _aiPilot, true];
        _veh setVariable ["Para42_arc170Gunship_apOn", true, true];
        _veh setVariable ["Para42_arc170Gunship_apStarting", false, true];

        [_veh] call Para42_fnc_arc170Gunship_refreshWaypoint;

        // Altitude-hold loop: re-issues flyInHeightASL each tick so a new waypoint
        // (radius/dir change) doesn't reset the held altitude.
        [_veh, _aiPilot] spawn {
            params ["_veh","_aiPilot"];
            while {alive _veh && {!isNull _aiPilot} && {alive _aiPilot} && {_veh getVariable ["Para42_arc170Gunship_apOn", false]}} do {
                if ((driver _veh) isEqualTo _aiPilot) then {
                    private _altASL = _veh getVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault];
                    if (local _veh) then {
                        _veh flyInHeightASL [_altASL, _altASL, _altASL];
                    };
                    if (!isEngineOn _veh) then { _veh engineOn true };
                };
                sleep 2;
            };
        };

        hintSilent format ["ARC-170 Autopilot: ON\nAlt %1m ASL  Rad %2m  Dir %3",
            _veh getVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault],
            _veh getVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault],
            ["CCW","CW"] select (_veh getVariable ["Para42_arc170Gunship_apDirCW", false])
        ];
    };
};

Para42_fnc_arc170Gunship_apOff = {
    params ["_veh"];
    if (isNull _veh) exitWith {};
    private _aiPilot = _veh getVariable ["Para42_arc170Gunship_apPilot", objNull];
    private _origDriver = _veh getVariable ["Para42_arc170Gunship_apOrigDriver", objNull];

    _veh setVariable ["Para42_arc170Gunship_apOn", false, true];

    if (!isNull _aiPilot) then {
        // delete the AI's group's waypoints so they don't keep flying
        private _grp = group _aiPilot;
        while {waypoints _grp isNotEqualTo []} do { deleteWaypoint ((waypoints _grp) select 0) };
        moveOut _aiPilot;
        deleteVehicle _aiPilot;
    };
    _veh setVariable ["Para42_arc170Gunship_apPilot", objNull, true];

    // Only auto-restore the original human driver back into the cockpit. If a
    // gunner toggled AP off, leave them in their gunner seat.
    if (!isNull _origDriver && {alive _origDriver} && {(vehicle _origDriver) isEqualTo _veh} && {isNull (driver _veh)}) then {
        moveOut _origDriver;
        _origDriver moveInDriver _veh;
        _origDriver assignAsDriver _veh;
    };
    _veh setVariable ["Para42_arc170Gunship_apOrigDriver", objNull, true];

    _veh engineOn true;

    [_veh] call Para42_fnc_arc170Gunship_clearMarker;

    hintSilent "ARC-170 Autopilot: OFF";
};

// ============================================================
// Adjust orbit parameters
// ============================================================

Para42_fnc_arc170GunshipAdjAlt = {
    params ["_delta"];
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {};
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    private _alt = _veh getVariable ["Para42_arc170Gunship_apAlt", Para42_arc170Gunship_apAltDefault];
    _alt = ((_alt + (_delta * Para42_arc170Gunship_apAltStep)) max Para42_arc170Gunship_apAltMin) min Para42_arc170Gunship_apAltMax;
    _veh setVariable ["Para42_arc170Gunship_apAlt", _alt, true];
    if (_veh getVariable ["Para42_arc170Gunship_apOn", false]) then {
        if (local _veh) then {
            _veh flyInHeightASL [_alt, _alt, _alt];
        } else {
            [_veh, _alt] remoteExec ["Para42_fnc_arc170Gunship_setHeightASL", _veh, false];
        };
    };
    hintSilent format ["ARC-170 Orbit Alt: %1m ASL", _alt];
};

Para42_fnc_arc170GunshipAdjRad = {
    params ["_delta"];
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {};
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    private _r = _veh getVariable ["Para42_arc170Gunship_apRadius", Para42_arc170Gunship_apRadiusDefault];
    _r = ((_r + (_delta * Para42_arc170Gunship_apRadiusStep)) max Para42_arc170Gunship_apRadiusMin) min Para42_arc170Gunship_apRadiusMax;
    _veh setVariable ["Para42_arc170Gunship_apRadius", _r, true];
    private _pos = _veh getVariable ["Para42_arc170Gunship_apTargetPos", []];
    if (count _pos >= 2) then {
        [_veh, _pos] call Para42_fnc_arc170Gunship_getOrCreateMarker;
    };
    if (_veh getVariable ["Para42_arc170Gunship_apOn", false]) then {
        [_veh] call Para42_fnc_arc170Gunship_refreshWaypoint;
    };
    hintSilent format ["ARC-170 Orbit Radius: %1m", _r];
};

Para42_fnc_arc170GunshipToggleDir = {
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {};
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    private _cw = _veh getVariable ["Para42_arc170Gunship_apDirCW", false];
    _cw = !_cw;
    _veh setVariable ["Para42_arc170Gunship_apDirCW", _cw, true];
    if (_veh getVariable ["Para42_arc170Gunship_apOn", false]) then {
        [_veh] call Para42_fnc_arc170Gunship_refreshWaypoint;
    };
    hintSilent format ["ARC-170 Orbit Direction: %1", ["CCW","CW"] select _cw];
};

// ============================================================
// Visible laser marker (faithful to AC-130 overt-laser feature)
// Uses the laser designator the Sensor Operator carries; just
// renders a visible green flare/beam pair while the laser is on.
// ============================================================

Para42_fnc_arc170GunshipToggleLaser = {
    if !(call Para42_fnc_arc170Gunship_anyCrew) exitWith {};
    private _veh = call Para42_fnc_arc170Gunship_playerVehicle;
    private _state = _veh getVariable ["Para42_arc170Gunship_overtLaser", false];
    if (_state) then {
        _veh setVariable ["Para42_arc170Gunship_overtLaser", false, true];
        private _flare = _veh getVariable ["Para42_arc170Gunship_overtLaserLight", objNull];
        if (!isNull _flare) then { deleteVehicle _flare };
        _veh setVariable ["Para42_arc170Gunship_overtLaserLight", objNull, true];
        hintSilent "Overt Laser: OFF";
    } else {
        if (isNull (laserTarget _veh)) exitWith {
            hintSilent "Overt Laser: laser designator must be active first.";
        };
        _veh setVariable ["Para42_arc170Gunship_overtLaser", true, true];
        hintSilent "Overt Laser: ON";

        [_veh] spawn {
            params ["_veh"];
            while {alive _veh && {_veh getVariable ["Para42_arc170Gunship_overtLaser", false]} && {!isNull (laserTarget _veh)}} do {
                private _tgt = laserTarget _veh;
                private _light = _veh getVariable ["Para42_arc170Gunship_overtLaserLight", objNull];
                if (isNull _light) then {
                    _light = "#lightpoint" createVehicleLocal getPosASL _tgt;
                    _light setLightAmbient [0.3,1,0.3];
                    _light setLightColor [0.3,1,0.3];
                    _light setLightIntensity 500;
                    _light setLightAttenuation [0,1,0,0.1,0.1,20];
                    _light setLightDayLight true;
                    _light setLightUseFlare true;
                    _light setLightFlareSize 8;
                    _light setLightFlareMaxDistance 50000;
                    _veh setVariable ["Para42_arc170Gunship_overtLaserLight", _light, true];
                };
                _light setPosASL ((getPosASL _tgt) vectorAdd [0,0,0.1]);
                sleep 0.1;
            };
            private _light = _veh getVariable ["Para42_arc170Gunship_overtLaserLight", objNull];
            if (!isNull _light) then { deleteVehicle _light };
            _veh setVariable ["Para42_arc170Gunship_overtLaserLight", objNull, true];
            _veh setVariable ["Para42_arc170Gunship_overtLaser", false, true];
        };
    };
};

// ============================================================
// CBA keybinds (rebindable in OPTIONS > CONTROLS > Configure
// Addon Actions > 42nd Paracore Battalion > ARC-170 Gunship)
// ============================================================

private _cat = ["42nd Paracore Battalion", "ARC-170 Gunship"];

[
    _cat,
    "Para42_arc170Gunship_markTarget",
    "Place Orbit Target on Map",
    { call Para42_fnc_arc170GunshipMarkTarget },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_toggleAP",
    "Toggle Orbit Autopilot",
    { call Para42_fnc_arc170GunshipToggleAP },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_altUp",
    "Orbit Altitude +100m",
    { [1] call Para42_fnc_arc170GunshipAdjAlt },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_altDown",
    "Orbit Altitude -100m",
    { [-1] call Para42_fnc_arc170GunshipAdjAlt },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_radUp",
    "Orbit Radius +100m",
    { [1] call Para42_fnc_arc170GunshipAdjRad },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_radDown",
    "Orbit Radius -100m",
    { [-1] call Para42_fnc_arc170GunshipAdjRad },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_toggleDir",
    "Toggle Orbit Direction (CW/CCW)",
    { call Para42_fnc_arc170GunshipToggleDir },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;

[
    _cat,
    "Para42_arc170Gunship_overtLaser",
    "Toggle Overt Laser Marker",
    { call Para42_fnc_arc170GunshipToggleLaser },
    {},
    [-1, [false, false, false]],
    false
] call CBA_fnc_addKeybind;
