if (isNil "para42_fnc_laatNotify") then {
    para42_fnc_laatNotify = {
        params [
            ["_unit", objNull, [objNull]],
            ["_message", "", [""]]
        ];

        if (isNull _unit || {_message isEqualTo ""}) exitWith {};
        [_message] remoteExecCall ["hint", owner _unit];
    };
};

if (isNil "para42_laatPresetCargo") then {
    para42_laatPresetCargo = [
        ["<t color='#9fd3ff'>Drop Ammo Resupply Crate</t>", "42nd_Ammo_Resupply_Crate", "Ammo Resupply Crate"],
        ["<t color='#9fd3ff'>Drop Medical Resupply Crate</t>", "42nd_Medical_Resupply_Crate", "Medical Resupply Crate"],
        ["<t color='#9fd3ff'>Drop Engineer Resupply Crate</t>", "42nd_Engineer_Resupply_Crate", "Engineer Resupply Crate"],
        ["<t color='#9fd3ff'>Drop Arsenal Supply Crate</t>", "42nd_Arsenal_Supply", "Arsenal Supply Crate"],
        ["<t color='#9fd3ff'>Drop LRATV</t>", "42nd_LSV_Unarmed", "LRATV"],
        ["<t color='#9fd3ff'>Drop LRATV (Z-6)</t>", "42nd_LSV_Armed", "LRATV (Z-6)"]
    ];
};

missionNamespace setVariable [
    "para42_laatAiResupplyInProgress",
    missionNamespace getVariable ["para42_laatAiResupplyInProgress", false],
    true
];

if (!hasInterface) exitWith {true};

[] call Para42_fnc_registerLaatResupplyActions;

true
