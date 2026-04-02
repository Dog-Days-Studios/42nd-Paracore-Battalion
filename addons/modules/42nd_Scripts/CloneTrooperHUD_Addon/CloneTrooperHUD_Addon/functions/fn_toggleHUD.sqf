if (!hasInterface) exitWith {false};

if !(missionNamespace getVariable ["CTHUD_enabled", true]) exitWith {
    hint "Clone HUD is disabled in CBA settings.";
    false
};

private _newState = !(missionNamespace getVariable ["CTHUD_runtimeEnabled", false]);
missionNamespace setVariable ["CTHUD_runtimeEnabled", _newState];

if (_newState) then {
    if (isNil "CTHUD_EachFrameEH") then {
        [] spawn CTHUD_fnc_initPlayerHUD;
    };
};

[] call CTHUD_fnc_syncHudState;

true
