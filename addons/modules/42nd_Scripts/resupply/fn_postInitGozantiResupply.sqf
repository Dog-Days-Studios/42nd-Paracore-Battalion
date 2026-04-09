if (isNil "para42_fnc_gozantiNotify") then {
    para42_fnc_gozantiNotify = {
        params [
            ["_unit", objNull, [objNull]],
            ["_message", "", [""]]
        ];

        if (isNull _unit || {_message isEqualTo ""}) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_gozantiPresetCargo") then {
    para42_gozantiPresetCargo = [
        ["<t color='#9fd3ff'>Load Ammo Resupply Crate</t>", "42nd_Ammo_Resupply_Crate", "Ammo Resupply Crate"],
        ["<t color='#9fd3ff'>Load Medical Resupply Crate</t>", "42nd_Medical_Resupply_Crate", "Medical Resupply Crate"],
        ["<t color='#9fd3ff'>Load Engineer Resupply Crate</t>", "42nd_Engineer_Resupply_Crate", "Engineer Resupply Crate"],
        ["<t color='#9fd3ff'>Load Arsenal Supply Crate</t>", "42nd_Arsenal_Supply", "Arsenal Supply Crate"],
        ["<t color='#9fd3ff'>Load LRATV</t>", "42nd_LSV_Unarmed", "LRATV"],
        ["<t color='#9fd3ff'>Load LRATV (Z-6)</t>", "42nd_LSV_Armed", "LRATV (Z-6)"],
        ["<t color='#9fd3ff'>Load LAAT/I Gunship</t>", "42nd_LAAT", "LAAT/I Gunship"]
    ];
};

missionNamespace setVariable [
    "para42_gozantiAiResupplyInProgress",
    missionNamespace getVariable ["para42_gozantiAiResupplyInProgress", false],
    true
];

if (!hasInterface) exitWith {true};

[] call Para42_fnc_registerGozantiResupplyActions;

true
