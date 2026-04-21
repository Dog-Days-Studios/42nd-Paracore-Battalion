private _msg = "Connect to the 42nd Paracore Battalion server?\n\n167.160.93.167:2316";
private _confirmed = [_msg, "42nd Paracore", true, true] call BIS_fnc_guiMessage;
if (_confirmed) then {
    connectToServer ["167.160.93.167", 2316, "42nd"];
};
