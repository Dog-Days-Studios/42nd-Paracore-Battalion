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

    [] spawn {
        cutText ["....Initializing", "BLACK OUT", 0.05, true, true];
        sleep 0.2;
        cutText ["....Initializing", "BLACK FADED", 0, true, true];
        sleep 0.55;
        cutText ["", "BLACK IN", 0.2, true, true];
        [] call CTHUD_fnc_syncHudState;
    };
} else {
    [] call CTHUD_fnc_syncHudState;
};

true
