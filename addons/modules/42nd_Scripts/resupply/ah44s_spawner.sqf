params [["_transport", objNull, [objNull]]];
if (isNull _transport) exitWith {};

if (isNil "para42_fnc_ah44Notify") then {
    para42_fnc_ah44Notify = {
        params ["_unit", "_message"];
        if (isNull _unit) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_fnc_ah44GetDropPassengers") then {
    para42_fnc_ah44GetDropPassengers = {
        params [["_vehicle", objNull, [objNull]]];
        if (isNull _vehicle) exitWith {[]};

        private _passengers = (fullCrew [_vehicle, "", false]) apply { _x select 0 };
        _passengers = _passengers arrayIntersect _passengers;

        private _driver = driver _vehicle;
        private _gunner = gunner _vehicle;
        private _commander = commander _vehicle;

        _passengers select {
            !isNull _x &&
            {alive _x} &&
            {_x != _driver} &&
            {_x != _gunner} &&
            {_x != _commander}
        }
    };
};

if (isNil "para42_fnc_ah44GetDropOffset") then {
    para42_fnc_ah44GetDropOffset = {
        params [
            ["_vehicle", objNull, [objNull]],
            ["_index", 0, [0]],
            ["_pairSize", 2, [0]]
        ];

        if (isNull _vehicle) exitWith {[0, -4.5, -3.2]};

        private _bounds = boundingBoxReal _vehicle;
        _bounds params ["_minBounds", "_maxBounds"];

        private _pairRow = floor (_index / 2);
        private _sideOffset = 0;
        if (_pairSize > 1) then {
            private _pairSpacing = (((_maxBounds select 0) - (_minBounds select 0)) * 0.18) max 0.85;
            _pairSpacing = _pairSpacing min 1.35;
            _sideOffset = [-_pairSpacing, _pairSpacing] select (_index mod 2);
        };

        private _rearOffset = (_minBounds select 1) - 1.1 - (_pairRow * 0.75);
        private _bottomOffset = (_minBounds select 2) - 1.1;
        private _centerOffset = ((_minBounds select 0) + (_maxBounds select 0)) * 0.5;

        [_centerOffset + _sideOffset, _rearOffset, _bottomOffset]
    };
};

if (isNil "para42_fnc_ah44StoreBackpackState") then {
    para42_fnc_ah44StoreBackpackState = {
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

if (isNil "para42_fnc_ah44RestoreBackpackState") then {
    para42_fnc_ah44RestoreBackpackState = {
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

if (isNil "para42_fnc_ah44DropPassengerLocal") then {
    para42_fnc_ah44DropPassengerLocal = {
        params [
            ["_unit", objNull, [objNull]],
            ["_vehicle", objNull, [objNull]],
            ["_dropOffset", [0, -4.5, -3.2], [[]]]
        ];

        if (isNull _unit || {isNull _vehicle}) exitWith {};
        if (!alive _unit || {!alive _vehicle}) exitWith {};

        private _savedState = [_unit] call para42_fnc_ah44StoreBackpackState;

        removeBackpackGlobal _unit;
        _unit addBackpackGlobal "ls_gar_hawkbat_backpack";

        unassignVehicle _unit;
        moveOut _unit;

        private _dropPos = _vehicle modelToWorld _dropOffset;
        private _chute = createVehicle ["Steerable_Parachute_F", _dropPos, [], 0, "FLY"];
        _chute setPosATL _dropPos;
        _chute setDir getDir _vehicle;
        _chute setVelocity velocity _vehicle;

        _unit moveInDriver _chute;
        if (vehicle _unit != _chute) then {
            [_unit, _chute] spawn {
                params ["_unit", "_chute"];
                sleep 0.25;
                if (alive _unit && !isNull _chute && {vehicle _unit != _chute}) then {
                    _unit moveInDriver _chute;
                };
            };
        };

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

            [_unit, _savedState] call para42_fnc_ah44RestoreBackpackState;
        };
    };
};

if (isNil "para42_fnc_ah44ColumnDrop") then {
    para42_fnc_ah44ColumnDrop = {
        params [["_vehicle", objNull, [objNull]], ["_caller", objNull, [objNull]]];

        if (!isServer) exitWith {
            [_vehicle, _caller] remoteExecCall ["para42_fnc_ah44ColumnDrop", 2];
        };

        if (isNull _vehicle || {isNull _caller}) exitWith {};
        if (!alive _vehicle || {!alive _caller}) exitWith {};
        if (_caller != driver _vehicle) exitWith {};

        if (_vehicle getVariable ["42nd_ah44DropInProgress", false]) exitWith {
            [_caller, "Passenger airdrop is already in progress."] call para42_fnc_ah44Notify;
        };

        private _passengers = [_vehicle] call para42_fnc_ah44GetDropPassengers;
        if (_passengers isEqualTo []) exitWith {
            [_caller, "There are no passengers to airdrop."] call para42_fnc_ah44Notify;
        };

        _vehicle setVariable ["42nd_ah44DropInProgress", true, true];

        [_vehicle, _caller, _passengers] spawn {
            params ["_vehicle", "_caller", "_passengers"];

            for "_i" from 0 to ((count _passengers) - 1) step 2 do {
                private _pairUnits = _passengers select [_i, 2];
                private _pairSize = count _pairUnits;

                {
                    if (alive _x && {_x in crew _vehicle}) then {
                        private _dropOffset = [_vehicle, _i + _forEachIndex, _pairSize] call para42_fnc_ah44GetDropOffset;
                        [_x, _vehicle, _dropOffset] remoteExecCall ["para42_fnc_ah44DropPassengerLocal", owner _x];
                    };
                } forEach _pairUnits;

                if ((_i + 2) < count _passengers) then {
                    sleep 0.7;
                };
            };

            _vehicle setVariable ["42nd_ah44DropInProgress", false, true];
            [_caller, format ["Airdropped %1 passenger(s).", count _passengers]] call para42_fnc_ah44Notify;
        };
    };
};

_transport setVariable ["42nd_ah44DropInProgress", _transport getVariable ["42nd_ah44DropInProgress", false], true];

if (!hasInterface) exitWith {};
if (_transport getVariable ["42nd_ah44ActionsAdded", false]) exitWith {};

_transport setVariable ["42nd_ah44ActionsAdded", true];

_transport addAction [
    "<t color='#9fd3ff'>Airdrop Passengers</t>",
    {
        params ["_target", "_caller"];
        [_target, _caller] remoteExecCall ["para42_fnc_ah44ColumnDrop", 2];
    },
    nil,
    1.5,
    true,
    true,
    "",
    "alive _target && alive _this && vehicle _this isEqualTo _target && driver _target isEqualTo _this && !(_target getVariable ['42nd_ah44DropInProgress', false]) && count ([_target] call para42_fnc_ah44GetDropPassengers) > 0"
];
