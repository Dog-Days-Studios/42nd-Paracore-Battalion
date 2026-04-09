if (missionNamespace getVariable ["CTHUD_preInitRan", false]) exitWith {true};
missionNamespace setVariable ["CTHUD_preInitRan", true];

private _normalizeBoolSetting = {
    params ["_value", ["_default", true]];

    while {(typeName _value) isEqualTo "ARRAY"} do
    {
        if (_value isEqualTo []) exitWith {
            _value = _default;
        };

        _value = _value select 0;
    };

    if ((typeName _value) isEqualTo "SCALAR") exitWith {_value > 0};

    if ((typeName _value) isEqualTo "STRING") then
    {
        _value = toLower _value;
        _value = _value in ["true", "1", "yes", "on", "enabled"];
    };

    if ((typeName _value) isNotEqualTo "BOOL") exitWith {_default};

    _value
};

private _normalizeListSetting = {
    params ["_value", "_validValues", "_default"];

    while {(typeName _value) isEqualTo "ARRAY"} do
    {
        if (_value isEqualTo []) exitWith {
            _value = _default;
        };

        private _matchingStringIndex = _value findIf {
            (typeName _x) isEqualTo "STRING" &&
            {(toLower _x) in _validValues}
        };
        if (_matchingStringIndex != -1) exitWith {
            _value = _value select _matchingStringIndex;
        };

        private _scalarIndex = _value findIf {(typeName _x) isEqualTo "SCALAR"};
        if (_scalarIndex != -1) exitWith {
            _value = _value select _scalarIndex;
        };

        private _stringIndex = _value findIf {(typeName _x) isEqualTo "STRING"};
        if (_stringIndex != -1) exitWith {
            _value = _value select _stringIndex;
        };

        _value = _value select 0;
    };

    if ((typeName _value) isEqualTo "SCALAR") then
    {
        private _index = floor _value;
        if (_index >= 0 && {_index < count _validValues}) then
        {
            _value = _validValues select _index;
        }
        else
        {
            _value = _default;
        };
    };

    if ((typeName _value) isNotEqualTo "STRING") exitWith {_default};

    _value = toLower _value;
    [_default, _value] select (_value in _validValues)
};

private _normalizeColorSetting = {
    params ["_value", "_default"];

    while {
        (typeName _value) isEqualTo "ARRAY" &&
        {count _value isEqualTo 1} &&
        {(typeName (_value select 0)) isEqualTo "ARRAY"}
    } do {
        _value = _value select 0;
    };

    if ((typeName _value) isNotEqualTo "ARRAY" || {(count _value) < 3}) exitWith {+_default};

    private _normalized = [];
    private _invalid = false;
    {
        private _component = _value param [_forEachIndex, _x];
        if ((typeName _component) isNotEqualTo "SCALAR") exitWith {
            _invalid = true;
        };

        _normalized pushBack ((_component max 0) min 1);
    } forEach [(_default select 0), (_default select 1), (_default select 2)];

    if (_invalid) exitWith {+_default};

    private _alpha = _value param [3, _default param [3, 1]];
    if ((typeName _alpha) isNotEqualTo "SCALAR") then {
        _alpha = _default param [3, 1];
    };
    _normalized pushBack ((_alpha max 0) min 1);

    _normalized
};

missionNamespace setVariable [
    "CTHUD_enabled",
    [missionNamespace getVariable ["CTHUD_enabled", true], true] call _normalizeBoolSetting
];
missionNamespace setVariable [
    "CTHUD_onlyWithHelmet",
    [missionNamespace getVariable ["CTHUD_onlyWithHelmet", true], true] call _normalizeBoolSetting
];
missionNamespace setVariable [
    "CTHUD_cloneHelmetClasses",
    missionNamespace getVariable [
        "CTHUD_cloneHelmetClasses",
        "42nd_CT_P2_Helmet,42nd_CPLTL_P2_Helmet,42nd_CSGT_P2_Helmet,42nd_CST_P2_Helmet,42nd_ARF_Helmet,42nd_Medic_P2_Helmet,42nd_CVT_Medic_P2_Helmet,42nd_Squad_Medic_P2_Helmet,42nd_Rose_P2_Helmet,42nd_CVT_P2_Helmet,42nd_NCO_P2_Helmet"
    ]
];
missionNamespace setVariable [
    "CTHUD_enemyMaxDistance",
    ((missionNamespace getVariable ["CTHUD_enemyMaxDistance", 150]) max 0) min 150
];
missionNamespace setVariable [
    "CTHUD_pilotEnemyMaxDistance",
    ((missionNamespace getVariable ["CTHUD_pilotEnemyMaxDistance", 1000]) max 0) min 1000
];
missionNamespace setVariable [
    "CTHUD_friendlyMaxDistance",
    ((missionNamespace getVariable ["CTHUD_friendlyMaxDistance", 1000]) max 0) min 1000
];
missionNamespace setVariable [
    "CTHUD_showMiniMap",
    [missionNamespace getVariable ["CTHUD_showMiniMap", true], true] call _normalizeBoolSetting
];
private _sensorPaneMode = [
    missionNamespace getVariable ["CTHUD_sensorPaneMode", "sensor"],
    ["sensor", "minimap"],
    "sensor"
] call _normalizeListSetting;
missionNamespace setVariable ["CTHUD_sensorPaneMode", _sensorPaneMode];
missionNamespace setVariable [
    "CTHUD_trackerRange",
    ((missionNamespace getVariable ["CTHUD_trackerRange", 60]) max 15) min 150
];
missionNamespace setVariable [
    "CTHUD_trackerPilotRange",
    ((missionNamespace getVariable ["CTHUD_trackerPilotRange", 450]) max 100) min 1500
];
missionNamespace setVariable [
    "CTHUD_trackerRefresh",
    ((missionNamespace getVariable ["CTHUD_trackerRefresh", 0.25]) max 0.05) min 1
];
missionNamespace setVariable [
    "CTHUD_trackerFadeTime",
    ((missionNamespace getVariable ["CTHUD_trackerFadeTime", 1.5]) max 0) min 5
];
missionNamespace setVariable [
    "CTHUD_showInteriorVisor",
    [missionNamespace getVariable ["CTHUD_showInteriorVisor", true], true] call _normalizeBoolSetting
];
missionNamespace setVariable [
    "CTHUD_textScalePreset",
    [
        missionNamespace getVariable ["CTHUD_textScalePreset", "default"],
        ["compact", "default", "large", "xlarge"],
        "default"
    ] call _normalizeListSetting
];
missionNamespace setVariable [
    "CTHUD_interiorVisorOpacity",
    ((missionNamespace getVariable ["CTHUD_interiorVisorOpacity", 100]) max 0) min 100
];
missionNamespace setVariable [
    "CTHUD_powerSounds",
    [missionNamespace getVariable ["CTHUD_powerSounds", true], true] call _normalizeBoolSetting
];
missionNamespace setVariable [
    "CTHUD_colorPreset",
    [
        missionNamespace getVariable ["CTHUD_colorPreset", "default"],
        ["default", "green", "amber", "red", "protanopia", "deuteranopia", "tritanopia", "mono", "custom"],
        "default"
    ] call _normalizeListSetting
];
missionNamespace setVariable [
    "CTHUD_customColor",
    [missionNamespace getVariable ["CTHUD_customColor", [0.15, 0.65, 1, 1]], [0.15, 0.65, 1, 1]] call _normalizeColorSetting
];
missionNamespace setVariable [
    "CTHUD_enemyColor",
    [missionNamespace getVariable ["CTHUD_enemyColor", [1, 0.05, 0.05, 1]], [1, 0.05, 0.05, 1]] call _normalizeColorSetting
];
missionNamespace setVariable [
    "CTHUD_friendlyColor",
    [missionNamespace getVariable ["CTHUD_friendlyColor", [0.15, 1, 0.35, 1]], [0.15, 1, 0.35, 1]] call _normalizeColorSetting
];
missionNamespace setVariable [
    "CTHUD_runtimeEnabled",
    [missionNamespace getVariable ["CTHUD_runtimeEnabled", false], false] call _normalizeBoolSetting
];

if (!isNil "CBA_fnc_addSetting") then
{
[
    "CTHUD_enabled",
    "CHECKBOX",
    ["Enable Clone HUD", "Master toggle for the clone trooper HUD."],
    ["Clone Trooper HUD", "General"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_onlyWithHelmet",
    "CHECKBOX",
    ["Only With Clone Helmet", "Show the HUD only when wearing an approved clone helmet."],
    ["Clone Trooper HUD", "General"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_cloneHelmetClasses",
    "EDITBOX",
    ["Clone Helmet Classnames", "Comma-separated list of helmet classnames that enable the HUD when helmet restriction is on."],
    ["Clone Trooper HUD", "General"],
    "42nd_CT_P2_Helmet,42nd_CPLTL_P2_Helmet,42nd_CSGT_P2_Helmet,42nd_CST_P2_Helmet,42nd_ARF_Helmet,42nd_Medic_P2_Helmet,42nd_CVT_Medic_P2_Helmet,42nd_Squad_Medic_P2_Helmet,42nd_Rose_P2_Helmet,42nd_CVT_P2_Helmet,42nd_NCO_P2_Helmet",
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_enemyMaxDistance",
    "SLIDER",
    ["Enemy Marker Distance", "Maximum range for enemy diamond markers."],
    ["Clone Trooper HUD", "Markers"],
    [0, 150, 150, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_pilotEnemyMaxDistance",
    "SLIDER",
    ["Pilot Enemy Marker Distance", "Maximum range for enemy markers while using the pilot HUD profile."],
    ["Clone Trooper HUD", "Markers"],
    [0, 1000, 1000, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_friendlyMaxDistance",
    "SLIDER",
    ["Friendly Marker Distance", "Maximum range for friendly force triangle markers."],
    ["Clone Trooper HUD", "Markers"],
    [0, 1000, 1000, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_showMiniMap",
    "CHECKBOX",
    ["Show Sensor Pane", "Displays the lower-left motion tracker or pilot radar pane."],
    ["Clone Trooper HUD", "Layout"],
    true,
    1,
    {
        private _value = _this;

        while {(typeName _value) isEqualTo "ARRAY"} do
        {
            if (_value isEqualTo []) exitWith {
                _value = true;
            };

            _value = _value select 0;
        };

        if ((typeName _value) isEqualTo "SCALAR") then
        {
            _value = _value > 0;
        };

        if ((typeName _value) isEqualTo "STRING") then
        {
            _value = (toLower _value) in ["true", "1", "yes", "on", "enabled"];
        };

        if ((typeName _value) isNotEqualTo "BOOL") then
        {
            _value = true;
        };

        missionNamespace setVariable ["CTHUD_showMiniMap", _value];
    }
] call CBA_fnc_addSetting;

[
    "CTHUD_sensorPaneMode",
    "LIST",
    ["Sensor Pane Mode", "Choose whether the lower-left pane shows the tactical sensor feed or a live minimap."],
    ["Clone Trooper HUD", "Layout"],
    [["sensor", "minimap"], ["Sensor Display", "Minimap"], 0],
    1,
    {
        private _value = _this;
        private _validValues = ["sensor", "minimap"];

        while {(typeName _value) isEqualTo "ARRAY"} do
        {
            if (_value isEqualTo []) exitWith {
                _value = "sensor";
            };

            private _stringIndex = _value findIf {(typeName _x) isEqualTo "STRING"};
            if (_stringIndex != -1) exitWith {
                _value = _value select _stringIndex;
            };

            private _scalarIndex = _value findIf {(typeName _x) isEqualTo "SCALAR"};
            if (_scalarIndex != -1) exitWith {
                _value = _value select _scalarIndex;
            };

            _value = _value select 0;
        };

        if ((typeName _value) isEqualTo "SCALAR") then
        {
            private _index = floor _value;
            if (_index >= 0 && {_index < count _validValues}) then
            {
                _value = _validValues select _index;
            }
            else
            {
                _value = "sensor";
            };
        };

        if ((typeName _value) isNotEqualTo "STRING") then
        {
            _value = "sensor";
        };

        _value = toLower _value;
        if !(_value in _validValues) then
        {
            _value = "sensor";
        };

        missionNamespace setVariable [
            "CTHUD_sensorPaneMode",
            _value
        ];
    }
] call CBA_fnc_addSetting;

[
    "CTHUD_trackerRange",
    "SLIDER",
    ["Tracker Range", "Maximum range for the infantry motion tracker pane."],
    ["Clone Trooper HUD", "Layout"],
    [15, 150, 60, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_trackerPilotRange",
    "SLIDER",
    ["Pilot Radar Range", "Maximum range for the pilot radar contact pane."],
    ["Clone Trooper HUD", "Layout"],
    [100, 1500, 450, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_trackerRefresh",
    "SLIDER",
    ["Sensor Refresh", "How often the motion tracker or radar refreshes its contact cache in seconds."],
    ["Clone Trooper HUD", "Layout"],
    [0.05, 1, 0.25, 2],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_trackerFadeTime",
    "SLIDER",
    ["Sensor Contact Fade", "How long lost contacts linger on the sensor pane in seconds."],
    ["Clone Trooper HUD", "Layout"],
    [0, 5, 1.5, 1],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_showInteriorVisor",
    "CHECKBOX",
    ["Show Interior Visor", "Displays the clone visor overlay texture while the HUD is active."],
    ["Clone Trooper HUD", "Layout"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_textScalePreset",
    "LIST",
    ["HUD Text Preset", "Adjusts HUD text size and swaps to a matching layout preset."],
    ["Clone Trooper HUD", "Layout"],
    [["compact", "default", "large", "xlarge"], ["Compact", "Default", "Large", "Extra Large"], 1],
    1,
    {
        _this call CTHUD_fnc_setTextScalePreset;
    }
] call CBA_fnc_addSetting;

[
    "CTHUD_interiorVisorOpacity",
    "SLIDER",
    ["Interior Visor Opacity", "Adjusts the opacity of the P2 interior visor overlay while the HUD is active."],
    ["Clone Trooper HUD", "Layout"],
    [0, 100, 100, 0],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_powerSounds",
    "CHECKBOX",
    ["Power Effects Sounds", "Plays local helmet power-up and power-down sounds when the HUD turns on or off."],
    ["Clone Trooper HUD", "Audio"],
    true,
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_colorPreset",
    "LIST",
    ["HUD Color Preset", "Choose a standard or colorblind preset."],
    ["Clone Trooper HUD", "Colors"],
    [["default", "green", "amber", "red", "protanopia", "deuteranopia", "tritanopia", "mono", "custom"], ["Default Blue", "Green", "Amber", "Red", "Protanopia", "Deuteranopia", "Tritanopia", "Monochrome", "Custom"], 0],
    1,
    {
        _this call CTHUD_fnc_setColorPreset;
    }
] call CBA_fnc_addSetting;

[
    "CTHUD_customColor",
    "COLOR",
    ["Custom HUD Color", "Used when the preset is set to Custom."],
    ["Clone Trooper HUD", "Colors"],
    [0.15, 0.65, 1, 1],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_enemyColor",
    "COLOR",
    ["Enemy Marker Color", "Color used for enemy HUD markers."],
    ["Clone Trooper HUD", "Colors"],
    [1, 0.05, 0.05, 1],
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_friendlyColor",
    "COLOR",
    ["Friendly Marker Color", "Color used for friendly HUD markers and squad list text."],
    ["Clone Trooper HUD", "Colors"],
    [0.15, 1, 0.35, 1],
    1
] call CBA_fnc_addSetting;
};

if (!isNil "CBA_fnc_addKeybind") then
{
[
    ["42nd Paracore Battalion", "Clone HUD"],
    "CTHUD_ToggleHUD",
    ["Toggle Clone HUD", "Show or hide the clone trooper HUD."],
    {
        [] call CTHUD_fnc_toggleHUD;
    },
    {},
    [0x44, [false, false, false]]
] call CBA_fnc_addKeybind;
};

true
