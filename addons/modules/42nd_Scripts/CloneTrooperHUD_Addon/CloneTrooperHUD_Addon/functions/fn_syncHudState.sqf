if (!hasInterface) exitWith {};
if (isNull player) exitWith {};

private _hudEnabled = missionNamespace getVariable ["CTHUD_enabled", true];
private _runtimeEnabled = missionNamespace getVariable ["CTHUD_runtimeEnabled", false];
private _hasHelmet = call CTHUD_fnc_hasHudHelmet;
private _useInteriorVisor = missionNamespace getVariable ["CTHUD_showInteriorVisor", true];
private _wantsOverlay = _hudEnabled && _runtimeEnabled && _hasHelmet && _useInteriorVisor;
private _overlayTexture = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\p2_hud_ca.paa";

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
    }
    else
    {
        private _visorCtrl = _display displayCtrl 9001;
        _visorCtrl ctrlSetText _overlayTexture;
        _visorCtrl ctrlShow _wantsOverlay;
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
