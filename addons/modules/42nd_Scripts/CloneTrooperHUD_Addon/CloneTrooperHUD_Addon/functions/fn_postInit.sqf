if (!hasInterface) exitWith {};
missionNamespace setVariable ["CTHUD_runtimeEnabled", false];
missionNamespace setVariable ["CTHUD_savedFacewear", ""];
missionNamespace setVariable ["CTHUD_defaultHudHidden", false];
missionNamespace setVariable ["CTHUD_savedHudState", []];
[] call CTHUD_fnc_registerAceActions;
[] spawn CTHUD_fnc_initPlayerHUD;
