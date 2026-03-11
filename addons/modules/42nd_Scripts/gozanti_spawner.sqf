/*
    Usage on the Gozanti's init:
    [this] execVM "\42nd_para\42nd\addons\modules\42nd_Scripts\gozanti_spawner.sqf";
*/

params [["_gozanti", objNull, [objNull]]];
if (isNull _gozanti) exitWith {};

if (isNil "para42_gozantiCargoOffsets") then {
    para42_gozantiCargoOffsets = [
        [-4, -7, -4.5],
        [0, -7, -4.5],
        [4, -7, -4.5],
        [-4, -13, -4.5],
        [0, -13, -4.5],
        [4, -13, -4.5]
    ];
};

if (isNil "para42_fnc_gozantiNotify") then {
    para42_fnc_gozantiNotify = {
        params ["_unit", "_message"];
        if (isNull _unit) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_fnc_gozantiGetLoadedVehicles") then {
    para42_fnc_gozantiGetLoadedVehicles = {
        params [["_transport", objNull, [objNull]]];
        if (isNull _transport) exitWith {[]};

        private _loadedVehicles = _transport getVariable ["42nd_loadedVehicles", []];
        _loadedVehicles = _loadedVehicles select {
            !isNull _x && {attachedTo _x isEqualTo _transport}
        };

        _transport setVariable ["42nd_loadedVehicles", _loadedVehicles, true];
        _loadedVehicles
    };
};

if (isNil "para42_fnc_gozantiFindLoadCandidates") then {
    para42_fnc_gozantiFindLoadCandidates = {
        params [["_transport", objNull, [objNull]]];
        if (isNull _transport) exitWith {[]};

        private _candidates = nearestObjects [_transport, ["LandVehicle", "Car", "Tank", "Boat"], 30];
        _candidates select {
            alive _x &&
            {_x != _transport} &&
            {isNull attachedTo _x} &&
            {crew _x isEqualTo []} &&
            {(getPosATL _x select 2) < 3}
        }
    };
};

if (isNil "para42_fnc_gozantiLoadCargo") then {
    para42_fnc_gozantiLoadCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargo", objNull, [objNull]]
        ];

        if (isNull _transport || {isNull _cargo}) exitWith {false};

        private _loadedVehicles = [_transport] call para42_fnc_gozantiGetLoadedVehicles;
        private _slotIndex = count _loadedVehicles;

        if (_slotIndex >= count para42_gozantiCargoOffsets) exitWith {false};

        private _attachOffset = para42_gozantiCargoOffsets select _slotIndex;

        _cargo engineOn false;
        _cargo allowDamage false;
        _cargo enableSimulationGlobal false;
        _cargo setVelocity [0, 0, 0];
        _cargo attachTo [_transport, _attachOffset];

        _loadedVehicles pushBack _cargo;
        _transport setVariable ["42nd_loadedVehicles", _loadedVehicles, true];

        true
    };
};

if (isNil "para42_fnc_gozantiDropCargo") then {
    para42_fnc_gozantiDropCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargo", objNull, [objNull]]
        ];

        if (isNull _transport || {isNull _cargo}) exitWith {false};

        detach _cargo;
        _cargo enableSimulationGlobal true;

        private _dropPos = _transport modelToWorld [0, -12, -6];
        _cargo setPosATL _dropPos;

        private _parachute = createVehicle ["B_Parachute_02_F", _dropPos, [], 0, "CAN_COLLIDE"];
        _parachute setPosATL _dropPos;
        _parachute setDir getDir _transport;
        _parachute setVelocity velocity _transport;

        _cargo attachTo [_parachute, [0, 0, -1.5]];

        [_cargo, _parachute] spawn {
            params ["_cargo", "_parachute"];

            waitUntil {
                sleep 0.25;
                isNull _cargo || isNull _parachute || {(getPosATL _cargo select 2) < 3}
            };

            if (isNull _cargo) exitWith {};

            detach _cargo;
            _cargo setVelocity [0, 0, 0];
            _cargo allowDamage true;

            if (!isNull _parachute) then {
                deleteVehicle _parachute;
            };
        };

        true
    };
};

if (isNil "para42_fnc_gozantiLoadVehicle") then {
    para42_fnc_gozantiLoadVehicle = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_gozantiLoadVehicle", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};

        private _loadedVehicles = [_transport] call para42_fnc_gozantiGetLoadedVehicles;
        private _maxVehicles = count para42_gozantiCargoOffsets;
        if ((count _loadedVehicles) >= _maxVehicles) exitWith {
            [_caller, format ["Cargo bay full (%1/%2).", count _loadedVehicles, _maxVehicles]] call para42_fnc_gozantiNotify;
        };

        private _candidates = [_transport] call para42_fnc_gozantiFindLoadCandidates;
        if (_candidates isEqualTo []) exitWith {
            [_caller, "No empty vehicle is close enough to load."] call para42_fnc_gozantiNotify;
        };

        private _cargo = _candidates select 0;
        if ([_transport, _cargo] call para42_fnc_gozantiLoadCargo) then {
            private _cargoName = getText (configOf _cargo >> "displayName");
            if (_cargoName isEqualTo "") then {
                _cargoName = typeOf _cargo;
            };

            private _count = count ([_transport] call para42_fnc_gozantiGetLoadedVehicles);
            [_caller, format ["Loaded %1 (%2/%3).", _cargoName, _count, _maxVehicles]] call para42_fnc_gozantiNotify;
        };
    };
};

if (isNil "para42_fnc_gozantiLoadAllVehicles") then {
    para42_fnc_gozantiLoadAllVehicles = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_gozantiLoadAllVehicles", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};

        private _loadedVehicles = [_transport] call para42_fnc_gozantiGetLoadedVehicles;
        private _maxVehicles = count para42_gozantiCargoOffsets;
        private _freeSlots = _maxVehicles - (count _loadedVehicles);

        if (_freeSlots <= 0) exitWith {
            [_caller, format ["Cargo bay full (%1/%2).", count _loadedVehicles, _maxVehicles]] call para42_fnc_gozantiNotify;
        };

        private _candidates = [_transport] call para42_fnc_gozantiFindLoadCandidates;
        if (_candidates isEqualTo []) exitWith {
            [_caller, "No empty vehicles are close enough to load."] call para42_fnc_gozantiNotify;
        };

        private _loadedCount = 0;
        for "_i" from 0 to ((count _candidates) - 1) do {
            if (_loadedCount >= _freeSlots) exitWith {};

            if ([_transport, _candidates select _i] call para42_fnc_gozantiLoadCargo) then {
                _loadedCount = _loadedCount + 1;
            };
        };

        private _newCount = count ([_transport] call para42_fnc_gozantiGetLoadedVehicles);
        [_caller, format ["Loaded %1 vehicle(s) (%2/%3).", _loadedCount, _newCount, _maxVehicles]] call para42_fnc_gozantiNotify;
    };
};

if (isNil "para42_fnc_gozantiDropVehicle") then {
    para42_fnc_gozantiDropVehicle = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_gozantiDropVehicle", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};

        private _loadedVehicles = [_transport] call para42_fnc_gozantiGetLoadedVehicles;
        if (_loadedVehicles isEqualTo []) exitWith {
            [_caller, "There is no loaded vehicle to drop."] call para42_fnc_gozantiNotify;
        };

        private _cargo = _loadedVehicles deleteAt ((count _loadedVehicles) - 1);
        _transport setVariable ["42nd_loadedVehicles", _loadedVehicles, true];

        if ([_transport, _cargo] call para42_fnc_gozantiDropCargo) then {
            [_caller, format ["Vehicle dropped (%1 remaining).", count _loadedVehicles]] call para42_fnc_gozantiNotify;
        };
    };
};

if (isNil "para42_fnc_gozantiDropAllVehicles") then {
    para42_fnc_gozantiDropAllVehicles = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_gozantiDropAllVehicles", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};
        if (_transport getVariable ["42nd_dropAllInProgress", false]) exitWith {
            [_caller, "Airdrop all is already in progress."] call para42_fnc_gozantiNotify;
        };

        private _loadedVehicles = +([_transport] call para42_fnc_gozantiGetLoadedVehicles);
        if (_loadedVehicles isEqualTo []) exitWith {
            [_caller, "There are no loaded vehicles to drop."] call para42_fnc_gozantiNotify;
        };

        _transport setVariable ["42nd_dropAllInProgress", true, true];
        _transport setVariable ["42nd_loadedVehicles", [], true];

        [_transport, _caller, _loadedVehicles] spawn {
            params ["_transport", "_caller", "_loadedVehicles"];

            for "_i" from ((count _loadedVehicles) - 1) to 0 step -1 do {
                [_transport, _loadedVehicles select _i] call para42_fnc_gozantiDropCargo;
                [_caller, format ["Airdropped %1/%2 vehicle(s).", (count _loadedVehicles) - _i, count _loadedVehicles]] call para42_fnc_gozantiNotify;

                if (_i > 0) then {
                    sleep 2;
                };
            };

            _transport setVariable ["42nd_dropAllInProgress", false, true];
        };
    };
};

_gozanti setVariable ["42nd_loadedVehicles", _gozanti getVariable ["42nd_loadedVehicles", []], true];
_gozanti setVariable ["42nd_dropAllInProgress", _gozanti getVariable ["42nd_dropAllInProgress", false], true];
_gozanti setVariable ["42nd_gozantiTroopDropInProgress", _gozanti getVariable ["42nd_gozantiTroopDropInProgress", false], true];

if (isNil "para42_fnc_gozantiGetDropPassengers") then {
    para42_fnc_gozantiGetDropPassengers = {
        params [["_transport", objNull, [objNull]]];
        if (isNull _transport) exitWith {[]};

        private _passengers = (fullCrew [_transport, "", false]) apply { _x select 0 };
        _passengers = _passengers arrayIntersect _passengers;

        private _driver = driver _transport;
        private _gunner = gunner _transport;
        private _commander = commander _transport;

        _passengers select {
            !isNull _x &&
            {alive _x} &&
            {_x != _driver} &&
            {_x != _gunner} &&
            {_x != _commander}
        }
    };
};

if (isNil "para42_fnc_gozantiGetDropOffset") then {
    para42_fnc_gozantiGetDropOffset = {
        params [
            ["_transport", objNull, [objNull]],
            ["_index", 0, [0]],
            ["_pairSize", 2, [0]]
        ];

        if (isNull _transport) exitWith {[0, -8, -6]};

        private _bounds = boundingBoxReal _transport;
        _bounds params ["_minBounds", "_maxBounds"];

        private _pairRow = floor (_index / 2);
        private _sideOffset = 0;
        if (_pairSize > 1) then {
            private _pairSpacing = (((_maxBounds select 0) - (_minBounds select 0)) * 0.14) max 1.4;
            _pairSpacing = _pairSpacing min 2.8;
            _sideOffset = [-_pairSpacing, _pairSpacing] select (_index mod 2);
        };

        private _rearOffset = (_minBounds select 1) - 1.75 - (_pairRow * 1.1);
        private _bottomOffset = (_minBounds select 2) - 1.75;
        private _centerOffset = ((_minBounds select 0) + (_maxBounds select 0)) * 0.5;

        [_centerOffset + _sideOffset, _rearOffset, _bottomOffset]
    };
};

if (isNil "para42_fnc_gozantiStoreBackpackState") then {
    para42_fnc_gozantiStoreBackpackState = {
        params ["_unit"];

        private _backpackClass = backpack _unit;
        private _itemCargo = [[], []];
        private _magazineCargo = [[], []];
        private _weaponCargo = [[], []];
        private _backpackCargo = [[], []];

        private _container = backpackContainer _unit;
        if (!isNull _container) then {
            _itemCargo = getItemCargo _container;
            _magazineCargo = getMagazineCargo _container;
            _weaponCargo = getWeaponCargo _container;
            _backpackCargo = getBackpackCargo _container;
        };

        [
            _backpackClass,
            _itemCargo,
            _magazineCargo,
            _weaponCargo,
            _backpackCargo
        ]
    };
};

if (isNil "para42_fnc_gozantiRestoreBackpackState") then {
    para42_fnc_gozantiRestoreBackpackState = {
        params ["_unit", "_savedState"];

        _savedState params [
            ["_backpackClass", "", [""]],
            ["_itemCargo", [[], []], [[]]],
            ["_magazineCargo", [[], []], [[]]],
            ["_weaponCargo", [[], []], [[]]],
            ["_backpackCargo", [[], []], [[]]]
        ];

        removeBackpackGlobal _unit;

        if (_backpackClass != "") then {
            _unit addBackpackGlobal _backpackClass;

            private _container = backpackContainer _unit;
            if (!isNull _container) then {
                _itemCargo params ["_itemClasses", "_itemCounts"];
                for "_i" from 0 to ((count _itemClasses) - 1) do {
                    _container addItemCargoGlobal [_itemClasses select _i, _itemCounts select _i];
                };

                _magazineCargo params ["_magClasses", "_magCounts"];
                for "_i" from 0 to ((count _magClasses) - 1) do {
                    _container addMagazineCargoGlobal [_magClasses select _i, _magCounts select _i];
                };

                _weaponCargo params ["_weaponClasses", "_weaponCounts"];
                for "_i" from 0 to ((count _weaponClasses) - 1) do {
                    _container addWeaponCargoGlobal [_weaponClasses select _i, _weaponCounts select _i];
                };

                _backpackCargo params ["_nestedClasses", "_nestedCounts"];
                for "_i" from 0 to ((count _nestedClasses) - 1) do {
                    _container addBackpackCargoGlobal [_nestedClasses select _i, _nestedCounts select _i];
                };
            };
        };
    };
};

if (isNil "para42_fnc_gozantiDropPassengerLocal") then {
    para42_fnc_gozantiDropPassengerLocal = {
        params [
            ["_unit", objNull, [objNull]],
            ["_transport", objNull, [objNull]],
            ["_dropOffset", [0, -8, -6], [[]]]
        ];

        if (isNull _unit || {isNull _transport}) exitWith {};
        if (!alive _unit || {!alive _transport}) exitWith {};

        private _savedState = [_unit] call para42_fnc_gozantiStoreBackpackState;

        removeBackpackGlobal _unit;
        _unit addBackpackGlobal "ls_gar_hawkbat_backpack";

        unassignVehicle _unit;
        moveOut _unit;

        private _dropPos = _transport modelToWorld _dropOffset;
        private _chute = createVehicle ["Steerable_Parachute_F", _dropPos, [], 0, "FLY"];
        _chute setPosATL _dropPos;
        _chute setDir getDir _transport;
        _chute setVelocity velocity _transport;

        _unit moveInDriver _chute;

        [_unit, _chute, _savedState] spawn {
            params ["_unit", "_chute", "_savedState"];

            waitUntil {
                sleep 0.5;
                !alive _unit ||
                isNull _chute ||
                {isTouchingGround _chute} ||
                {(getPosATL _unit select 2) < 1}
            };

            if (!alive _unit) exitWith {};

            sleep 1;

            if (!isNull _chute) then {
                unassignVehicle _unit;
                moveOut _unit;
                deleteVehicle _chute;
            };

            [_unit, _savedState] call para42_fnc_gozantiRestoreBackpackState;
        };
    };
};

if (isNil "para42_fnc_gozantiDropPassengers") then {
    para42_fnc_gozantiDropPassengers = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_gozantiDropPassengers", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};
        if (!alive _transport || {!alive _caller}) exitWith {};
        if (_caller != driver _transport) exitWith {};

        if (_transport getVariable ["42nd_gozantiTroopDropInProgress", false]) exitWith {
            [_caller, "Troop airdrop is already in progress."] call para42_fnc_gozantiNotify;
        };

        private _passengers = [_transport] call para42_fnc_gozantiGetDropPassengers;
        if (_passengers isEqualTo []) exitWith {
            [_caller, "There are no passengers to airdrop."] call para42_fnc_gozantiNotify;
        };

        _transport setVariable ["42nd_gozantiTroopDropInProgress", true, true];

        [_transport, _caller, _passengers] spawn {
            params ["_transport", "_caller", "_passengers"];

            for "_i" from 0 to ((count _passengers) - 1) step 2 do {
                private _pairUnits = _passengers select [_i, 2];
                private _pairSize = count _pairUnits;

                {
                    if (alive _x && {_x in crew _transport}) then {
                        private _dropOffset = [_transport, _i + _forEachIndex, _pairSize] call para42_fnc_gozantiGetDropOffset;
                        [_x, _transport, _dropOffset] remoteExecCall ["para42_fnc_gozantiDropPassengerLocal", owner _x];
                    };
                } forEach _pairUnits;

                if ((_i + 2) < count _passengers) then {
                    sleep 0.85;
                };
            };

            _transport setVariable ["42nd_gozantiTroopDropInProgress", false, true];
            [_caller, format ["Airdropped %1 passenger(s).", count _passengers]] call para42_fnc_gozantiNotify;
        };
    };
};

if (!hasInterface) exitWith {};
if (_gozanti getVariable ["42nd_gozantiActionsAdded", false]) exitWith {};

_gozanti setVariable ["42nd_gozantiActionsAdded", true];

_gozanti addAction [
    "<t color='#9fd3ff'>Load Nearby Vehicle</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_gozantiLoadVehicle", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_dropAllInProgress', false]) && !(_target getVariable ['42nd_gozantiTroopDropInProgress', false]) && count (_target getVariable ['42nd_loadedVehicles', []]) < 6"
];

_gozanti addAction [
    "<t color='#9fd3ff'>Load All Nearby Vehicles</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_gozantiLoadAllVehicles", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_dropAllInProgress', false]) && !(_target getVariable ['42nd_gozantiTroopDropInProgress', false]) && count (_target getVariable ['42nd_loadedVehicles', []]) < 6"
];

_gozanti addAction [
    "<t color='#9fd3ff'>Airdrop Loaded Vehicle</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_gozantiDropVehicle", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_dropAllInProgress', false]) && !(_target getVariable ['42nd_gozantiTroopDropInProgress', false]) && count (_target getVariable ['42nd_loadedVehicles', []]) > 0"
];

_gozanti addAction [
    "<t color='#9fd3ff'>Airdrop All Vehicles</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_gozantiDropAllVehicles", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_dropAllInProgress', false]) && !(_target getVariable ['42nd_gozantiTroopDropInProgress', false]) && count (_target getVariable ['42nd_loadedVehicles', []]) > 0"
];

_gozanti addAction [
    "<t color='#9fd3ff'>Airdrop Passengers</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_gozantiDropPassengers", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_dropAllInProgress', false]) && !(_target getVariable ['42nd_gozantiTroopDropInProgress', false]) && count ([_target] call para42_fnc_gozantiGetDropPassengers) > 0"
];
