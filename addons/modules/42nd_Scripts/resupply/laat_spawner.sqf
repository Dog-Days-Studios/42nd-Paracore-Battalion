params [["_laat", objNull, [objNull]]];
if (isNull _laat) exitWith {};

if (isNil "para42_fnc_laatNotify") then {
    para42_fnc_laatNotify = {
        params ["_unit", "_message"];
        if (isNull _unit) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_laatPresetCargo") then {
    para42_laatPresetCargo = [
        ["<t color='#9fd3ff'>Load Ammo Resupply Crate</t>", "42nd_Ammo_Resupply_Crate", "Ammo Resupply Crate"],
        ["<t color='#9fd3ff'>Load Medical Resupply Crate</t>", "42nd_Medical_Resupply_Crate", "Medical Resupply Crate"],
        ["<t color='#9fd3ff'>Load Engineer Resupply Crate</t>", "42nd_Engineer_Resupply_Crate", "Engineer Resupply Crate"],
        ["<t color='#9fd3ff'>Load Arsenal Supply Crate</t>", "42nd_Arsenal_Supply", "Arsenal Supply Crate"],
        ["<t color='#9fd3ff'>Load LRATV</t>", "42nd_LSV_Unarmed", "LRATV"],
        ["<t color='#9fd3ff'>Load LRATV (Z-6)</t>", "42nd_LSV_Armed", "LRATV (Z-6)"]
    ];
};

if (isNil "para42_fnc_laatGetLoadedCargo") then {
    para42_fnc_laatGetLoadedCargo = {
        params [["_transport", objNull, [objNull]]];
        if (isNull _transport) exitWith {objNull};

        private _cargo = _transport getVariable ["42nd_laatLoadedCargo", objNull];
        if (isNull _cargo || {attachedTo _cargo isNotEqualTo _transport}) exitWith {
            _transport setVariable ["42nd_laatLoadedCargo", objNull, true];
            objNull
        };

        _cargo
    };
};

if (isNil "para42_fnc_laatLoadCargo") then {
    para42_fnc_laatLoadCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargo", objNull, [objNull]]
        ];

        if (isNull _transport || {isNull _cargo}) exitWith {false};
        if (!isNull ([_transport] call para42_fnc_laatGetLoadedCargo)) exitWith {false};

        if (_cargo isKindOf "AllVehicles") then {
            _cargo engineOn false;
        };

        _cargo allowDamage false;
        _cargo enableSimulationGlobal false;
        _cargo setVelocity [0, 0, 0];
        _cargo attachTo [_transport, [0, -1.5, -6.2]];

        _transport setVariable ["42nd_laatLoadedCargo", _cargo, true];
        true
    };
};

if (isNil "para42_fnc_laatDropCargo") then {
    para42_fnc_laatDropCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_cargo", objNull, [objNull]],
            ["_target", objNull, [objNull]]
        ];

        if (isNull _transport) exitWith {false};
        if (isNull _cargo) then {
            _cargo = [_transport] call para42_fnc_laatGetLoadedCargo;
        };
        if (isNull _cargo) exitWith {false};

        _transport setVariable ["42nd_laatLoadedCargo", objNull, true];

        detach _cargo;
        _cargo enableSimulationGlobal true;

        private _dropPosATL = _transport modelToWorld [0, -1.5, -6.2];
        _cargo setPosATL _dropPosATL;

        private _bounds = boundingBoxReal _cargo;
        _bounds params ["_minBounds", "_maxBounds"];
        private _cargoHeight = (_maxBounds select 2) - (_minBounds select 2);
        private _attachOffsetZ = -((_cargoHeight * 0.5) + 0.35);

        private _parachute = createVehicle ["B_Parachute_02_F", _dropPosATL, [], 0, "CAN_COLLIDE"];
        if (isNull _parachute) exitWith {
            _cargo allowDamage true;
            false
        };

        _parachute setPosATL _dropPosATL;
        _parachute setDir getDir _transport;
        _parachute setVelocity velocity _transport;
        _cargo attachTo [_parachute, [0, 0, _attachOffsetZ]];

        [_cargo, _parachute, _target, "SmokeShellBlue", 7, 3] call Para42_fnc_beginGuidedAirdrop;

        true
    };
};

if (isNil "para42_fnc_laatLoadPresetCargo") then {
    para42_fnc_laatLoadPresetCargo = {
        params [
            ["_transport", objNull, [objNull]],
            ["_caller", objNull, [objNull]],
            ["_cargoClass", "", [""]],
            ["_cargoLabel", "", [""]]
        ];

        if (!isServer) exitWith {
            [_transport, _caller, _cargoClass, _cargoLabel] remoteExecCall ["para42_fnc_laatLoadPresetCargo", 2];
        };

        if (isNull _transport || {isNull _caller} || {_cargoClass isEqualTo ""}) exitWith {};
        if !([_caller] call Para42_fnc_hasResupplyAccess) exitWith {
            [_caller, "Resupply is restricted to Sergeant and above."] call para42_fnc_laatNotify;
        };
        if (_cargoClass isKindOf "Air") exitWith {
            [_caller, "LAAT cargo cannot load aircraft."] call para42_fnc_laatNotify;
        };
        if (!isNull ([_transport] call para42_fnc_laatGetLoadedCargo)) exitWith {
            [_caller, "The LAAT already has cargo loaded."] call para42_fnc_laatNotify;
        };

        private _spawnPosATL = _transport modelToWorld [0, -1.5, -6.2];
        private _cargo = createVehicle [_cargoClass, _spawnPosATL, [], 0, "CAN_COLLIDE"];
        if (isNull _cargo) exitWith {
            [_caller, format ["Unable to spawn %1.", _cargoLabel]] call para42_fnc_laatNotify;
        };

        _cargo setDir getDir _transport;
        _cargo setPosATL _spawnPosATL;
        if (_cargo isKindOf "LandVehicle") then {
            _cargo lock 2;
        };

        if ([_transport, _cargo] call para42_fnc_laatLoadCargo) then {
            [_caller, format ["Loaded %1.", _cargoLabel]] call para42_fnc_laatNotify;
        } else {
            deleteVehicle _cargo;
            [_caller, format ["Unable to load %1.", _cargoLabel]] call para42_fnc_laatNotify;
        };
    };
};

if (isNil "para42_fnc_laatDropLoadedCargo") then {
    para42_fnc_laatDropLoadedCargo = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_laatDropLoadedCargo", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};
        if !([_caller] call Para42_fnc_hasResupplyAccess) exitWith {
            [_caller, "Resupply is restricted to Sergeant and above."] call para42_fnc_laatNotify;
        };
        if (_transport getVariable ["42nd_laatCargoDropInProgress", false]) exitWith {
            [_caller, "Cargo airdrop is already in progress."] call para42_fnc_laatNotify;
        };

        private _cargo = [_transport] call para42_fnc_laatGetLoadedCargo;
        if (isNull _cargo) exitWith {
            [_caller, "There is no loaded cargo to drop."] call para42_fnc_laatNotify;
        };

        _transport setVariable ["42nd_laatCargoDropInProgress", true, true];

        if ([_transport, _cargo, _caller] call para42_fnc_laatDropCargo) then {
            private _cargoLabel = getText (configOf _cargo >> "displayName");
            if (_cargoLabel isEqualTo "") then {
                _cargoLabel = typeOf _cargo;
            };
            [_caller, format ["Airdropped %1.", _cargoLabel]] call para42_fnc_laatNotify;
        } else {
            [_caller, "Unable to airdrop the loaded cargo."] call para42_fnc_laatNotify;
        };

        _transport setVariable ["42nd_laatCargoDropInProgress", false, true];
    };
};

if (isNil "para42_fnc_laatGetDropPassengers") then {
    para42_fnc_laatGetDropPassengers = {
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

if (isNil "para42_fnc_laatGetDropOffset") then {
    para42_fnc_laatGetDropOffset = {
        params [
            ["_transport", objNull, [objNull]],
            ["_index", 0, [0]],
            ["_pairSize", 2, [0]]
        ];

        if (isNull _transport) exitWith {[0, -6, -4]};

        private _bounds = boundingBoxReal _transport;
        _bounds params ["_minBounds", "_maxBounds"];

        private _pairRow = floor (_index / 2);
        private _sideOffset = 0;
        if (_pairSize > 1) then {
            private _pairSpacing = (((_maxBounds select 0) - (_minBounds select 0)) * 0.18) max 1.1;
            _pairSpacing = _pairSpacing min 1.8;
            _sideOffset = [-_pairSpacing, _pairSpacing] select (_index mod 2);
        };

        private _rearOffset = (_minBounds select 1) - 1.5 - (_pairRow * 0.85);
        private _bottomOffset = (_minBounds select 2) - 1.25;
        private _centerOffset = ((_minBounds select 0) + (_maxBounds select 0)) * 0.5;

        [_centerOffset + _sideOffset, _rearOffset, _bottomOffset]
    };
};

if (isNil "para42_fnc_laatStoreBackpackState") then {
    para42_fnc_laatStoreBackpackState = {
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

if (isNil "para42_fnc_laatRestoreBackpackState") then {
    para42_fnc_laatRestoreBackpackState = {
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

if (isNil "para42_fnc_laatDropPassengerLocal") then {
    para42_fnc_laatDropPassengerLocal = {
        params [
            ["_unit", objNull, [objNull]],
            ["_transport", objNull, [objNull]],
            ["_dropOffset", [0, -6, -4], [[]]]
        ];

        if (isNull _unit || {isNull _transport}) exitWith {};
        if (!alive _unit || {!alive _transport}) exitWith {};

        private _savedState = [_unit] call para42_fnc_laatStoreBackpackState;

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

            [_unit, _savedState] call para42_fnc_laatRestoreBackpackState;
        };
    };
};

if (isNil "para42_fnc_laatColumnDrop") then {
    para42_fnc_laatColumnDrop = {
        params [["_transport", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_transport, _caller] remoteExecCall ["para42_fnc_laatColumnDrop", 2];
        };

        if (isNull _transport || {isNull _caller}) exitWith {};
        if (!alive _transport || {!alive _caller}) exitWith {};
        if (_caller != driver _transport) exitWith {};

        if (_transport getVariable ["42nd_laatDropInProgress", false]) exitWith {
            [_caller, "Column airdrop is already in progress."] call para42_fnc_laatNotify;
        };

        private _passengers = [_transport] call para42_fnc_laatGetDropPassengers;
        if (_passengers isEqualTo []) exitWith {
            [_caller, "There are no passengers to airdrop."] call para42_fnc_laatNotify;
        };

        _transport setVariable ["42nd_laatDropInProgress", true, true];

        [_transport, _caller, _passengers] spawn {
            params ["_transport", "_caller", "_passengers"];

            for "_i" from 0 to ((count _passengers) - 1) step 2 do {
                private _pairUnits = _passengers select [_i, 2];
                private _pairSize = count _pairUnits;

                {
                    if (alive _x && {_x in crew _transport}) then {
                        private _dropOffset = [_transport, _i + _forEachIndex, _pairSize] call para42_fnc_laatGetDropOffset;
                        [_x, _transport, _dropOffset] remoteExecCall ["para42_fnc_laatDropPassengerLocal", owner _x];
                    };
                } forEach _pairUnits;

                if ((_i + 2) < count _passengers) then {
                    sleep 0.75;
                };
            };

            _transport setVariable ["42nd_laatDropInProgress", false, true];
            [_caller, format ["Airdropped %1 passenger(s).", count _passengers]] call para42_fnc_laatNotify;
        };
    };
};

_laat setVariable ["42nd_laatDropInProgress", _laat getVariable ["42nd_laatDropInProgress", false], true];
_laat setVariable ["42nd_laatCargoDropInProgress", _laat getVariable ["42nd_laatCargoDropInProgress", false], true];
_laat setVariable ["42nd_laatLoadedCargo", _laat getVariable ["42nd_laatLoadedCargo", objNull], true];

if (!hasInterface) exitWith {};
if (_laat getVariable ["42nd_laatActionsAdded", false]) exitWith {};

_laat setVariable ["42nd_laatActionsAdded", true];

{
    _x params ["_actionTitle", "_cargoClass", "_cargoLabel"];

    _laat addAction [
        _actionTitle,
        {
            params ["_target", "_caller", "", "_arguments"];
            _arguments params [
                ["_cargoClass", "", [""]],
                ["_cargoLabel", "", [""]]
            ];

            [_target, _caller, _cargoClass, _cargoLabel] remoteExecCall ["para42_fnc_laatLoadPresetCargo", 2];
        },
        [_cargoClass, _cargoLabel],
        1.5,
        true,
        true,
        "",
        "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && ([_this] call Para42_fnc_hasResupplyAccess) && isNull ([_target] call para42_fnc_laatGetLoadedCargo) && !(_target getVariable ['42nd_laatCargoDropInProgress', false]) && !(_target getVariable ['42nd_laatDropInProgress', false])"
    ];
} forEach para42_laatPresetCargo;

_laat addAction [
    "<t color='#9fd3ff'>Airdrop Loaded Cargo</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_laatDropLoadedCargo", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && ([_this] call Para42_fnc_hasResupplyAccess) && !isNull ([_target] call para42_fnc_laatGetLoadedCargo) && !(_target getVariable ['42nd_laatCargoDropInProgress', false]) && !(_target getVariable ['42nd_laatDropInProgress', false])"
];

_laat addAction [
    "<t color='#9fd3ff'>Airdrop Passengers</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_laatColumnDrop", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_laatDropInProgress', false]) && !(_target getVariable ['42nd_laatCargoDropInProgress', false]) && count ([_target] call para42_fnc_laatGetDropPassengers) > 0"
];
