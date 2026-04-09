if (!hasInterface) exitWith {};
waitUntil {!isNull player};
waitUntil {time > 0};

if (!isNil "CTHUD_Draw3DEH") then
{
    removeMissionEventHandler ["Draw3D", CTHUD_Draw3DEH];
};

if (!isNil "CTHUD_EachFrameEH") then
{
    removeMissionEventHandler ["EachFrame", CTHUD_EachFrameEH];
    CTHUD_EachFrameEH = nil;
};

CTHUD_Draw3DEH = addMissionEventHandler
[
    "Draw3D",
    {
        [] call CTHUD_fnc_syncHudState;
        [true] call CTHUD_fnc_drawHUD;
    }
];

[] call CTHUD_fnc_syncHudState;
