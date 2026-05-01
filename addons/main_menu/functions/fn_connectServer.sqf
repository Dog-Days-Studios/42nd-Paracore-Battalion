private _msg = "Connect to the 42nd Airborne Division server?\n\n51.222.108.22:2302";
private _confirmed = [_msg, "42nd Paracore", true, true] call BIS_fnc_guiMessage;
if (_confirmed) then {
    connectToServer ["51.222.108.22", 2302, "42nd"];
};
