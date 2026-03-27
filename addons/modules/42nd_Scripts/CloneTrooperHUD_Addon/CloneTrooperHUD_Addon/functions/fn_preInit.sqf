missionNamespace setVariable ["CTHUD_enabled", missionNamespace getVariable ["CTHUD_enabled", true]];
missionNamespace setVariable ["CTHUD_onlyWithHelmet", missionNamespace getVariable ["CTHUD_onlyWithHelmet", true]];
missionNamespace setVariable [
    "CTHUD_cloneHelmetClasses",
    missionNamespace getVariable [
        "CTHUD_cloneHelmetClasses",
        "42nd_CT_P2_Helmet,42nd_CPLTL_P2_Helmet,42nd_CSGT_P2_Helmet,42nd_CST_P2_Helmet,42nd_ARF_Helmet,42nd_Medic_P2_Helmet,42nd_CVT_Medic_P2_Helmet,42nd_Squad_Medic_P2_Helmet,42nd_Rose_P2_Helmet,42nd_CVT_P2_Helmet,42nd_NCO_P2_Helmet"
    ]
];
missionNamespace setVariable [
    "CTHUD_enemyMaxDistance",
    ((missionNamespace getVariable ["CTHUD_enemyMaxDistance", 100]) max 0) min 100
];
missionNamespace setVariable [
    "CTHUD_friendlyMaxDistance",
    ((missionNamespace getVariable ["CTHUD_friendlyMaxDistance", 1000]) max 0) min 1000
];
missionNamespace setVariable ["CTHUD_showMiniMap", missionNamespace getVariable ["CTHUD_showMiniMap", true]];
missionNamespace setVariable ["CTHUD_showInteriorVisor", missionNamespace getVariable ["CTHUD_showInteriorVisor", true]];
missionNamespace setVariable ["CTHUD_colorPreset", missionNamespace getVariable ["CTHUD_colorPreset", "default"]];
missionNamespace setVariable ["CTHUD_customColor", missionNamespace getVariable ["CTHUD_customColor", [0.15, 0.65, 1, 1]]];
missionNamespace setVariable ["CTHUD_enemyColor", missionNamespace getVariable ["CTHUD_enemyColor", [1, 0.2, 0.2, 1]]];
missionNamespace setVariable ["CTHUD_friendlyColor", missionNamespace getVariable ["CTHUD_friendlyColor", [0.15, 1, 0.35, 1]]];
missionNamespace setVariable ["CTHUD_runtimeEnabled", missionNamespace getVariable ["CTHUD_runtimeEnabled", false]];

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
    [0, 100, 100, 0],
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
    ["Show Mini Map", "Displays the lower-left minimap."],
    ["Clone Trooper HUD", "Layout"],
    true,
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
    "CTHUD_colorPreset",
    "LIST",
    ["HUD Color Preset", "Choose a standard or colorblind preset."],
    ["Clone Trooper HUD", "Colors"],
    [["default", "green", "amber", "red", "protanopia", "deuteranopia", "tritanopia", "mono", "custom"], ["Default Blue", "Green", "Amber", "Red", "Protanopia", "Deuteranopia", "Tritanopia", "Monochrome", "Custom"], 0],
    1,
    {
        [_this] call CTHUD_fnc_setColorPreset;
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
    [1, 0.2, 0.2, 1],
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
