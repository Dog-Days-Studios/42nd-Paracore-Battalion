if (isNil "CBA_fnc_addSetting") exitWith {};

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
    false,
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_cloneHelmetClasses",
    "EDITBOX",
    ["Clone Helmet Classnames", "Comma-separated list of helmet classnames that enable the HUD when helmet restriction is on."],
    ["Clone Trooper HUD", "General"],
    "",
    1
] call CBA_fnc_addSetting;

[
    "CTHUD_enemyMaxDistance",
    "SLIDER",
    ["Enemy Marker Distance", "Maximum range for enemy diamond markers."],
    ["Clone Trooper HUD", "Markers"],
    [100, 2000, 800, 0],
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
    "CTHUD_colorPreset",
    "LIST",
    ["HUD Color Preset", "Choose a standard or colorblind preset."],
    ["Clone Trooper HUD", "Colors"],
    [["default","green","amber","red","protanopia","deuteranopia","tritanopia","mono","custom"],["Default Blue","Green","Amber","Red","Protanopia","Deuteranopia","Tritanopia","Monochrome","Custom"],0],
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
