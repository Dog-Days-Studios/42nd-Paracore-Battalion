if (!hasInterface) exitWith {};
if (isNull player) exitWith {};

private _hudEnabled = missionNamespace getVariable ["CTHUD_enabled", true];
private _runtimeEnabled = missionNamespace getVariable ["CTHUD_runtimeEnabled", false];
private _hasHelmet = call CTHUD_fnc_hasHudHelmet;
private _useInteriorVisor = missionNamespace getVariable ["CTHUD_showInteriorVisor", true];
private _overlayClass = "ls_clone_phase2_hud";
private _currentFacewear = goggles player;
private _wantsOverlay = _hudEnabled && _runtimeEnabled && _hasHelmet && _useInteriorVisor;

if (_wantsOverlay) then
{
    if (_currentFacewear != _overlayClass) then
    {
        if (_currentFacewear != "") then
        {
            player setVariable ["CTHUD_savedFacewear", _currentFacewear];
            removeGoggles player;
        };

        player addGoggles _overlayClass;
    };
}
else
{
    if (_currentFacewear == _overlayClass) then
    {
        removeGoggles player;

        private _savedFacewear = player getVariable ["CTHUD_savedFacewear", ""];
        if (_savedFacewear != "") then
        {
            player addGoggles _savedFacewear;
        };

        player setVariable ["CTHUD_savedFacewear", ""];
    };
};

private _shouldShowHud = call CTHUD_fnc_canShowHUD;
private _display = uiNamespace getVariable ["CTHUD_Display", displayNull];
private _hudShown = missionNamespace getVariable ["CTHUD_defaultHudHidden", false];

if (_shouldShowHud) then
{
    if (!_hudShown) then
    {
        private _hudState = +shownHUD;
        if ((count _hudState) < 11) then
        {
            _hudState = [true, true, true, true, true, true, true, true, true, true, true];
        };

        missionNamespace setVariable ["CTHUD_savedHudState", +_hudState];
        _hudState set [1, false];
        if ((count _hudState) > 8) then
        {
            _hudState set [8, false];
        };
        showHUD _hudState;
        missionNamespace setVariable ["CTHUD_defaultHudHidden", true];
    };

    if (isNull _display) then
    {
        cutRsc ["CTHUD_Main", "PLAIN"];
    };
}
else
{
    if (_hudShown) then
    {
        private _restoreHudState = missionNamespace getVariable [
            "CTHUD_savedHudState",
            [true, true, true, true, true, true, true, true, true, true, true]
        ];
        showHUD _restoreHudState;
        missionNamespace setVariable ["CTHUD_defaultHudHidden", false];
    };

    if (!isNull _display) then
    {
        _display closeDisplay 2;
        uiNamespace setVariable ["CTHUD_Display", displayNull];
    };
};
