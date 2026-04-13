params [
    ["_caller", objNull, [objNull]],
    ["_cargoClass", "", [""]],
    ["_cargoLabel", "", [""]],
    ["_dropPosATL", [], [[]]],
    ["_approachDir", -1, [0]],
    ["_enforceRank", true, [true]]
];

if (!canSuspend) exitWith {
    _this spawn Para42_fnc_requestGozantiAiResupply;
    objNull
};

if (!isServer) exitWith {
    [_caller, _cargoClass, _cargoLabel, _dropPosATL, _approachDir, _enforceRank] remoteExecCall ["Para42_fnc_requestGozantiAiResupply", 2];
};

private _notify = {
    params ["_unit", "_message"];

    if (_message isEqualTo "") exitWith {};

    if (!isNull _unit && {!isNil "para42_fnc_gozantiNotify"}) then {
        [_unit, _message] call para42_fnc_gozantiNotify;
    };
};

if (_cargoClass isEqualTo "") exitWith {
    [_caller, "No cargo class was provided for AI resupply."] call _notify;
};

if (_enforceRank && {!([_caller] call Para42_fnc_hasResupplyAccess)}) exitWith {
    [_caller, "Resupply is restricted to Sergeant and above."] call _notify;
};

private _cargoCfg = configFile >> "CfgVehicles" >> _cargoClass;
if !(isClass _cargoCfg) exitWith {
    [_caller, format ["%1 is not loaded.", _cargoClass]] call _notify;
};
private _deferCargoSpawn = (_cargoClass isKindOf "LandVehicle") || {_cargoClass isKindOf "Air"};

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
    [_caller, "Unable to determine a drop position for AI resupply."] call _notify;
};

_dropPosATL = [
    _dropPosATL param [0, 0],
    _dropPosATL param [1, 0],
    0
];

if (missionNamespace getVariable ["para42_gozantiAiResupplyInProgress", false]) exitWith {
    [_caller, "AI Gozanti resupply is already in progress."] call _notify;
};

missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", true, true];

if (_approachDir < 0) then {
    _approachDir = if (!isNull _caller) then {
        getDir (vehicle _caller)
    } else {
        random 360
    };
};

private _spawnPosATL = [
    (_dropPosATL select 0) - (sin _approachDir * 1800),
    (_dropPosATL select 1) - (cos _approachDir * 1800),
    220
];
private _approachPosATL = [
    (_dropPosATL select 0) - (sin _approachDir * 450),
    (_dropPosATL select 1) - (cos _approachDir * 450),
    180
];
private _dropFlyPosATL = [
    _dropPosATL select 0,
    _dropPosATL select 1,
    180
];
private _egressPosATL = [
    (_dropPosATL select 0) + (sin _approachDir * 2200),
    (_dropPosATL select 1) + (cos _approachDir * 2200),
    220
];

private _gozanti = createVehicle ["42nd_Gozanti_Republic", _spawnPosATL, [], 0, "FLY"];
if (isNull _gozanti) exitWith {
    missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", false, true];
    [_caller, "AI Gozanti spawn failed."] call _notify;
};

_gozanti setDir _approachDir;
_gozanti setPosASL (ATLToASL _spawnPosATL);
_gozanti setVectorDirAndUp [[sin _approachDir, cos _approachDir, 0], [0, 0, 1]];
_gozanti allowDamage false;
_gozanti setFuel 1;
_gozanti engineOn true;
_gozanti lock 3;
_gozanti setVariable ["42nd_aiResupplyGozanti", true, true];
_gozanti setVariable ["42nd_loadedVehicles", [], true];
_gozanti setVariable ["42nd_dropAllInProgress", false, true];
_gozanti setVariable ["42nd_gozantiTroopDropInProgress", false, true];

{
    _x addCuratorEditableObjects [[_gozanti], false];
} forEach allCurators;

createVehicleCrew _gozanti;
if (isNull driver _gozanti && {isClass (configFile >> "CfgVehicles" >> "42nd_WO1_Pilot")}) then {
    private _fallbackGroup = createGroup west;
    private _fallbackPilot = _fallbackGroup createUnit ["42nd_WO1_Pilot", ASLToATL (ATLToASL _spawnPosATL), [], 0, "NONE"];
    _fallbackPilot moveInDriver _gozanti;
};

if (isNil "para42_fnc_gozantiLoadCargo" || {isNil "para42_fnc_gozantiDropVehicle"} || {isNil "para42_fnc_gozantiDropCargo"}) then {
    [_gozanti] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\gozanti_spawner.sqf";

    private _supportDeadline = time + 5;
    waitUntil {
        sleep 0.1;
        (!isNil "para42_fnc_gozantiLoadCargo" && {!isNil "para42_fnc_gozantiDropVehicle"} && {!isNil "para42_fnc_gozantiDropCargo"}) ||
        {time > _supportDeadline}
    };
};

if (isNil "para42_fnc_gozantiLoadCargo" || {isNil "para42_fnc_gozantiDropVehicle"} || {isNil "para42_fnc_gozantiDropCargo"}) exitWith {
    { deleteVehicle _x; } forEach crew _gozanti;
    deleteVehicle _gozanti;
    missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", false, true];
    [_caller, "AI Gozanti support functions were not ready."] call _notify;
};

private _cargo = objNull;
if (!_deferCargoSpawn) then
{
    private _cargoSpawnPos = _gozanti modelToWorld [0, -4, -8];
    _cargo = createVehicle [_cargoClass, _cargoSpawnPos, [], 0, "CAN_COLLIDE"];
    if (isNull _cargo) exitWith {
        { deleteVehicle _x; } forEach crew _gozanti;
        deleteVehicle _gozanti;
        missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", false, true];
        [_caller, format ["Unable to spawn %1.", _cargoLabel]] call _notify;
    };

    _cargo setDir _approachDir;
    _cargo setPosATL _cargoSpawnPos;
    if (_cargo isKindOf "LandVehicle") then {
        _cargo lock 2;
    };

    {
        _x addCuratorEditableObjects [[_cargo], false];
    } forEach allCurators;

    if !([_gozanti, _cargo] call para42_fnc_gozantiLoadCargo) exitWith {
        deleteVehicle _cargo;
        { deleteVehicle _x; } forEach crew _gozanti;
        deleteVehicle _gozanti;
        missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", false, true];
        [_caller, format ["Unable to load %1 into the AI Gozanti.", _cargoLabel]] call _notify;
    };
};

[_caller, format ["AI Gozanti inbound with %1.", _cargoLabel]] call _notify;

[
    _gozanti,
    _caller,
    _cargo,
    _cargoClass,
    _cargoLabel,
    _approachPosATL,
    _dropFlyPosATL,
    _egressPosATL
] spawn {
    params [
        ["_gozanti", objNull, [objNull]],
        ["_caller", objNull, [objNull]],
        ["_cargo", objNull, [objNull]],
        ["_cargoClass", "", [""]],
        ["_cargoLabel", "", [""]],
        ["_approachPosATL", [], [[]]],
        ["_dropFlyPosATL", [], [[]]],
        ["_egressPosATL", [], [[]]]
    ];

    private _notify = {
        params ["_unit", "_message"];

        if (_message isEqualTo "") exitWith {};

        if (!isNull _unit && {!isNil "para42_fnc_gozantiNotify"}) then {
            [_unit, _message] call para42_fnc_gozantiNotify;
        };
    };

    private _spawnDeferredCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargoClass", "", [""]]
        ];

        if (isNull _transport || {_cargoClass isEqualTo ""}) exitWith {objNull};

        private _spawnPosATL = _transport modelToWorld [0, -12, -6];
        private _spawnedCargo = createVehicle [_cargoClass, _spawnPosATL, [], 0, "CAN_COLLIDE"];
        if (isNull _spawnedCargo) exitWith {objNull};

        _spawnedCargo setDir getDir _transport;
        _spawnedCargo setPosATL _spawnPosATL;
        _spawnedCargo allowDamage false;
        if (_spawnedCargo isKindOf "AllVehicles") then {
            _spawnedCargo engineOn false;
        };
        if (_spawnedCargo isKindOf "LandVehicle") then {
            _spawnedCargo lock 2;
        };

        {
            _x addCuratorEditableObjects [[_spawnedCargo], false];
        } forEach allCurators;

        _spawnedCargo
    };

    private _pilot = driver _gozanti;
    private _pilotGroup = grpNull;
    if (!isNull _pilot) then {
        _pilotGroup = group _pilot;
        {
            _x allowDamage false;
            _x disableAI "TARGET";
            _x disableAI "AUTOTARGET";
        } forEach crew _gozanti;
        _pilotGroup setBehaviour "CARELESS";
        _pilotGroup setCombatMode "BLUE";
        _pilotGroup setSpeedMode "FULL";
    };

    _gozanti flyInHeight 180;
    _gozanti limitSpeed 450;

    private _moveTo = {
        params [
            ["_vehicle", objNull, [objNull]],
            ["_group", grpNull],
            ["_destinationATL", [], [[]]],
            ["_threshold", 250, [0]],
            ["_timeout", 60, [0]]
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
        params [
            ["_vehicle", objNull, [objNull]],
            ["_cargo", objNull, [objNull]],
            ["_deleteCargo", false, [false]]
        ];

        if (_deleteCargo && {!isNull _cargo}) then {
            deleteVehicle _cargo;
        };

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

        missionNamespace setVariable ["para42_gozantiAiResupplyInProgress", false, true];
    };

    private _reachedApproach = [_gozanti, _pilotGroup, _approachPosATL, 500, 75] call _moveTo;
    if (!_reachedApproach && {_gozanti distance2D _dropFlyPosATL > 1200}) exitWith {
        [_caller, format ["AI Gozanti could not reach the drop run for %1.", _cargoLabel]] call _notify;
        [_gozanti, _cargo, true] call _cleanup;
    };

    private _reachedDrop = [_gozanti, _pilotGroup, _dropFlyPosATL, 250, 60] call _moveTo;
    if (!_reachedDrop && {!isNull _gozanti && {alive _gozanti}}) then {
        _gozanti setPosASL (ATLToASL _dropFlyPosATL);
        _gozanti setVectorDirAndUp [[sin (getDir _gozanti), cos (getDir _gozanti), 0], [0, 0, 1]];
    };

    if (isNull _gozanti || {!alive _gozanti}) exitWith {
        [_caller, format ["AI Gozanti was lost before dropping %1.", _cargoLabel]] call _notify;
        [_gozanti, _cargo, true] call _cleanup;
    };

    if (isNull _cargo && {_cargoClass isNotEqualTo ""}) then
    {
        _cargo = [_gozanti, _cargoClass] call _spawnDeferredCargo;
        if (isNull _cargo) exitWith
        {
            [_caller, format ["Unable to spawn %1 for release.", _cargoLabel]] call _notify;
            [_gozanti, _cargo, true] call _cleanup;
        };
    };

    private _loadedVehicles = [_gozanti] call para42_fnc_gozantiGetLoadedVehicles;
    _loadedVehicles = _loadedVehicles select {_x isNotEqualTo _cargo};
    _gozanti setVariable ["42nd_loadedVehicles", _loadedVehicles, true];

    private _dropSucceeded = [_gozanti, _cargo] call para42_fnc_gozantiDropCargo;
    if (!_dropSucceeded) exitWith
    {
        [_caller, format ["AI Gozanti failed to drop %1.", _cargoLabel]] call _notify;
        [_gozanti, _cargo, true] call _cleanup;
    };

    [_caller, format ["AI Gozanti dropped %1.", _cargoLabel]] call _notify;

    [_gozanti, _pilotGroup, _egressPosATL, 400, 45] call _moveTo;
    sleep 5;

    [_gozanti, _cargo, false] call _cleanup;
};
