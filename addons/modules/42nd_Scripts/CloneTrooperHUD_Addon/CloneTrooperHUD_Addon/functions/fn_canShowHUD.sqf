if (!hasInterface) exitWith {false};
if (isNull player) exitWith {false};
if (!alive player) exitWith {false};
if !(missionNamespace getVariable ["CTHUD_enabled", true]) exitWith {false};
if !(missionNamespace getVariable ["CTHUD_runtimeEnabled", false]) exitWith {false};
if (visibleMap) exitWith {false};
if (dialog) exitWith {false};
if !(isNull findDisplay 49) exitWith {false};
if !(call CTHUD_fnc_hasHudHelmet) exitWith {false};

true
