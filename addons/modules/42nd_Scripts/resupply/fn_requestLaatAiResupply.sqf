params [
    ["_caller", objNull, [objNull]],
    ["_cargoClass", "", [""]],
    ["_cargoLabel", "", [""]],
    ["_dropPosATL", [], [[]]],
    ["_approachDir", -1, [0]],
    ["_enforceRank", true, [true]]
];

if (!canSuspend) exitWith {
    _this spawn Para42_fnc_requestLaatAiResupply;
    objNull
};

if (!isServer) exitWith {
    [_caller, _cargoClass, _cargoLabel, _dropPosATL, _approachDir, _enforceRank] remoteExecCall ["Para42_fnc_requestLaatAiResupply", 2];
};

private _notify = {
    params ["_unit", "_message"];

    if (_message isEqualTo "") exitWith {};

    if (!isNull _unit && {!isNil "para42_fnc_laatNotify"}) then {
        [_unit, _message] call para42_fnc_laatNotify;
    };
};

if (_cargoClass isEqualTo "") exitWith {
    [_caller, "No cargo class was provided for LAAT resupply."] call _notify;
};

if (_enforceRank && {!([_caller] call Para42_fnc_hasResupplyAccess)}) exitWith {
    [_caller, "Resupply is restricted to Sergeant and above."] call _notify;
};

private _cargoCfg = configFile >> "CfgVehicles" >> _cargoClass;
if !(isClass _cargoCfg) exitWith {
    [_caller, format ["%1 is not loaded.", _cargoClass]] call _notify;
};

if (_cargoClass isKindOf "Air") exitWith {
    [_caller, "LAAT resupply cannot airdrop aircraft cargo."] call _notify;
};

if (_cargoLabel isEqualTo "") then {
    _cargoLabel = getText (_cargoCfg >> "displayName");
};
if (_cargoLabel isEqualTo "") then {
    _cargoLabel = _cargoClass;
};

if (_dropPosATL isEqualTo [] && {!isNull _caller}) then {
    private _anchorPosATL = getPosATL (vehicle _caller);
    _dropPosATL = [_anchorPosATL select 0, _anchorPosATL select 1, 0];
};

if ((count _dropPosATL) < 2) exitWith {
    [_caller, "Unable to determine a drop position for LAAT resupply."] call _notify;
};

_dropPosATL = [
    _dropPosATL param [0, 0],
    _dropPosATL param [1, 0],
    0
];

if (missionNamespace getVariable ["para42_laatAiResupplyInProgress", false]) exitWith {
    [_caller, "AI LAAT resupply is already in progress."] call _notify;
};

missionNamespace setVariable ["para42_laatAiResupplyInProgress", true, true];

if (_approachDir < 0) then {
    _approachDir = if (!isNull _caller) then {
        getDirVisual (vehicle _caller)
    } else {
        random 360
    };
};

private _spawnPosATL = [
    (_dropPosATL select 0) - (sin _approachDir * 1200),
    (_dropPosATL select 1) - (cos _approachDir * 1200),
    170
];
private _approachPosATL = [
    (_dropPosATL select 0) - (sin _approachDir * 350),
    (_dropPosATL select 1) - (cos _approachDir * 350),
    150
];
private _dropFlyPosATL = [
    _dropPosATL select 0,
    _dropPosATL select 1,
    145
];
private _egressPosATL = [
    (_dropPosATL select 0) + (sin _approachDir * 1450),
    (_dropPosATL select 1) + (cos _approachDir * 1450),
    180
];

private _laat = createVehicle ["42nd_LAAT", _spawnPosATL, [], 0, "FLY"];
if (isNull _laat) exitWith {
    missionNamespace setVariable ["para42_laatAiResupplyInProgress", false, true];
    [_caller, "AI LAAT spawn failed."] call _notify;
};

_laat setDir _approachDir;
_laat setPosASL (ATLToASL _spawnPosATL);
_laat setVectorDirAndUp [[sin _approachDir, cos _approachDir, 0], [0, 0, 1]];
_laat allowDamage false;
_laat setFuel 1;
_laat engineOn true;
_laat lock 3;
_laat setVariable ["42nd_aiResupplyLaat", true, true];

{
    _x addCuratorEditableObjects [[_laat], false];
} forEach allCurators;

createVehicleCrew _laat;
if (isClass (configFile >> "CfgVehicles" >> "42nd_WO1_Pilot")) then {
    private _currentDriver = driver _laat;
    if (!isNull _currentDriver) then {
        deleteVehicle _currentDriver;
    };

    private _fallbackGroup = createGroup west;
    private _fallbackPilot = _fallbackGroup createUnit ["42nd_WO1_Pilot", ASLToATL (ATLToASL _spawnPosATL), [], 0, "NONE"];
    _fallbackPilot moveInDriver _laat;
};

[_caller, format ["AI LAAT inbound with %1.", _cargoLabel]] call _notify;

[
    _laat,
    _caller,
    _cargoClass,
    _cargoLabel,
    _approachPosATL,
    _dropFlyPosATL,
    _egressPosATL
] spawn {
    params [
        ["_laat", objNull, [objNull]],
        ["_caller", objNull, [objNull]],
        ["_cargoClass", "", [""]],
        ["_cargoLabel", "", [""]],
        ["_approachPosATL", [], [[]]],
        ["_dropFlyPosATL", [], [[]]],
        ["_egressPosATL", [], [[]]]
    ];

    private _notify = {
        params ["_unit", "_message"];

        if (_message isEqualTo "") exitWith {};

        if (!isNull _unit && {!isNil "para42_fnc_laatNotify"}) then {
            [_unit, _message] call para42_fnc_laatNotify;
        };
    };

    private _spawnDropCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargoClass", "", [""]],
            ["_target", objNull, [objNull]]
        ];

        if (isNull _transport || {_cargoClass isEqualTo ""}) exitWith {objNull};

        private _spawnPosATL = _transport modelToWorld [0, -1.5, -6.2];
        private _cargo = createVehicle [_cargoClass, _spawnPosATL, [], 0, "CAN_COLLIDE"];
        if (isNull _cargo) exitWith {objNull};

        _cargo setDir getDir _transport;
        _cargo setPosATL _spawnPosATL;
        _cargo allowDamage false;

        if (_cargo isKindOf "AllVehicles") then {
            _cargo engineOn false;
        };
        if (_cargo isKindOf "LandVehicle") then {
            _cargo lock 2;
        };

        {
            _x addCuratorEditableObjects [[_cargo], false];
        } forEach allCurators;

        private _bounds = boundingBoxReal _cargo;
        _bounds params [
            ["_minBounds", [0, 0, 0], [[]]],
            ["_maxBounds", [0, 0, 0], [[]]]
        ];

        private _cargoHeight = (_maxBounds select 2) - (_minBounds select 2);
        private _attachOffsetZ = -((_cargoHeight * 0.5) + 0.35);

        private _parachute = createVehicle ["B_Parachute_02_F", _spawnPosATL, [], 0, "CAN_COLLIDE"];
        if (isNull _parachute) exitWith {
            deleteVehicle _cargo;
            objNull
        };

        _parachute setPosATL _spawnPosATL;
        _parachute setDir getDir _transport;
        _parachute setVelocity velocity _transport;
        _cargo attachTo [_parachute, [0, 0, _attachOffsetZ]];

        [_cargo, _parachute, _target, "SmokeShellBlue", 7, 3] call Para42_fnc_beginGuidedAirdrop;

        _cargo
    };

    private _pilot = driver _laat;
    private _pilotGroup = grpNull;
    if (!isNull _pilot) then {
        _pilotGroup = group _pilot;
        {
            _x allowDamage false;
            _x disableAI "TARGET";
            _x disableAI "AUTOTARGET";
        } forEach crew _laat;
        _pilotGroup setBehaviour "CARELESS";
        _pilotGroup setCombatMode "BLUE";
        _pilotGroup setSpeedMode "FULL";
    };

    _laat flyInHeight 145;
    _laat limitSpeed 250;

    private _moveTo = {
        params [
            ["_vehicle", objNull, [objNull]],
            ["_group", grpNull],
            ["_destinationATL", [], [[]]],
            ["_threshold", 180, [0]],
            ["_timeout", 45, [0]]
        ];

        if (isNull _vehicle || {!alive _vehicle}) exitWith {false};

        private _pilotUnit = driver _vehicle;

        if (!isNull _group) then {
            _group move _destinationATL;
        };
        if (!isNull _pilotUnit) then {
            _pilotUnit commandMove _destinationATL;
            _pilotUnit doMove _destinationATL;
        };

        private _deadline = time + _timeout;
        waitUntil {
            sleep 0.5;
            isNull _vehicle ||
            {!alive _vehicle} ||
            {_vehicle distance2D _destinationATL < _threshold} ||
            {time > _deadline}
        };

        !isNull _vehicle && {alive _vehicle && {_vehicle distance2D _destinationATL < _threshold}}
    };

    private _cleanup = {
        params [["_vehicle", objNull, [objNull]]];

        if (!isNull _vehicle) then {
            private _crewGroups = (crew _vehicle apply {group _x}) arrayIntersect (crew _vehicle apply {group _x});
            { deleteVehicle _x; } forEach crew _vehicle;
            {
                if (!isNull _x && {units _x isEqualTo []}) then {
                    deleteGroup _x;
                };
            } forEach _crewGroups;
            deleteVehicle _vehicle;
        };

        missionNamespace setVariable ["para42_laatAiResupplyInProgress", false, true];
    };

    private _reachedApproach = [_laat, _pilotGroup, _approachPosATL, 320, 70] call _moveTo;
    if (!_reachedApproach && {!isNull _laat && {alive _laat}}) then {
        _laat setPosASL (ATLToASL _approachPosATL);
        _laat setVectorDirAndUp [[sin (getDir _laat), cos (getDir _laat), 0], [0, 0, 1]];
        sleep 0.5;
    };

    private _reachedDrop = [_laat, _pilotGroup, _dropFlyPosATL, 180, 60] call _moveTo;
    if (!_reachedDrop && {!isNull _laat && {alive _laat}}) then {
        _laat setPosASL (ATLToASL _dropFlyPosATL);
        _laat setVectorDirAndUp [[sin (getDir _laat), cos (getDir _laat), 0], [0, 0, 1]];
        sleep 0.5;
    };

    if (isNull _laat || {!alive _laat}) exitWith {
        [_caller, format ["AI LAAT was lost before dropping %1.", _cargoLabel]] call _notify;
        [_laat] call _cleanup;
    };

    private _cargo = [_laat, _cargoClass, _caller] call _spawnDropCargo;
    if (isNull _cargo) exitWith {
        [_caller, format ["Unable to spawn %1 for release.", _cargoLabel]] call _notify;
        [_laat] call _cleanup;
    };

    [_caller, format ["AI LAAT dropped %1.", _cargoLabel]] call _notify;

    [_laat, _pilotGroup, _egressPosATL, 240, 45] call _moveTo;
    sleep 5;

    [_laat] call _cleanup;
};
