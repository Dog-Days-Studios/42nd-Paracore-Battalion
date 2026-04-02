missionNamespace setVariable [
    "Para42_playerTracker_enabled",
    missionNamespace getVariable ["Para42_playerTracker_enabled", false]
];
missionNamespace setVariable [
    "Para42_playerTracker_targetServerEndpoint",
    missionNamespace getVariable ["Para42_playerTracker_targetServerEndpoint", ""]
];
missionNamespace setVariable [
    "Para42_playerTracker_maxEventHistory",
    ((missionNamespace getVariable ["Para42_playerTracker_maxEventHistory", 500]) max 50) min 5000
];

if (!isNil "CBA_fnc_addSetting") then
{
    [
        "Para42_playerTracker_enabled",
        "CHECKBOX",
        ["Enable Player Tracker", "Tracks player joins, kills, deaths, and names for the configured server endpoint."],
        ["42nd Player Tracker", "General"],
        false,
        1
    ] call CBA_fnc_addSetting;

    [
        "Para42_playerTracker_targetServerEndpoint",
        "EDITBOX",
        ["Tracked Server Endpoint", "Exact IP:port label for the server this tracker belongs to, for example 1.2.3.4:2302. Leave blank to keep the tracker inactive."],
        ["42nd Player Tracker", "General"],
        "",
        1
    ] call CBA_fnc_addSetting;

    [
        "Para42_playerTracker_maxEventHistory",
        "SLIDER",
        ["Stored Event History", "Maximum number of tracker events persisted to the server profile."],
        ["42nd Player Tracker", "Advanced"],
        [50, 5000, 500, 0],
        1
    ] call CBA_fnc_addSetting;
};

true
