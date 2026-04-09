if (!hasInterface) exitWith {};
if (isNull player) exitWith {};
disableSerialization;

// Trust preInit-validated values directly — no per-frame re-normalization
private _hudEnabled = missionNamespace getVariable ["CTHUD_enabled", true];
private _runtimeEnabled = missionNamespace getVariable ["CTHUD_runtimeEnabled", false];
private _hasHelmet = call CTHUD_fnc_hasHudHelmet;
private _isPilotHud = call CTHUD_fnc_isPilotHudHelmet;
private _useInteriorVisor = missionNamespace getVariable ["CTHUD_showInteriorVisor", true];
private _cameraView = toUpper cameraView;
private _isFirstPerson = _cameraView in ["INTERNAL", "GUNNER", "OPTICS"];
private _visorOpacity = (((missionNamespace getVariable ["CTHUD_interiorVisorOpacity", 100]) max 0) min 100) / 100;
private _powerSoundsEnabled = missionNamespace getVariable ["CTHUD_powerSounds", true];
private _wantsOverlay = _hudEnabled && _runtimeEnabled && _hasHelmet && _useInteriorVisor && _isFirstPerson;
private _powerState = _hudEnabled && _runtimeEnabled && _hasHelmet && alive player;
private _overlayTexture = [
    "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\p2_hud_ca.paa",
    "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\pilot_hud_ca.paa"
] select _isPilotHud;
private _hudLayout = call CTHUD_fnc_getHudLayout;
private _displayClass = _hudLayout select 0;

private _shouldShowHud = call CTHUD_fnc_canShowHUD;
private _display = uiNamespace getVariable ["CTHUD_Display", findDisplay 9000];
if (isNull _display) then
{
    _display = findDisplay 9000;
};
if (!isNull _display) then
{
    uiNamespace setVariable ["CTHUD_Display", _display];
};
private _hudShown = missionNamespace getVariable ["CTHUD_defaultHudHidden", false];
private _lastPowerState = missionNamespace getVariable ["CTHUD_lastPowerState", false];
private _activeDisplayClass = missionNamespace getVariable ["CTHUD_activeDisplayClass", ""];
private _displayRequestAt = missionNamespace getVariable ["CTHUD_displayRequestAt", -1];
private _needsDisplaySwitch = _activeDisplayClass isNotEqualTo _displayClass;
private _temporarilySuppressed = _powerState && {!_shouldShowHud};

if (_powerState != _lastPowerState) then
{
    if (_powerSoundsEnabled) then
    {
        if (_powerState) then
        {
            playSound "CTHUD_PowerOn";
        }
        else
        {
            playSound "CTHUD_PowerOff";
        };
    };

    missionNamespace setVariable ["CTHUD_lastPowerState", _powerState];
    missionNamespace setVariable ["CTHUD_startupStartedAt", [-1, diag_tickTime] select _powerState];
};

private _startupStartedAt = missionNamespace getVariable ["CTHUD_startupStartedAt", -1];
private _startupDuration = missionNamespace getVariable ["CTHUD_startupDuration", 1.35];
private _startupFadeDuration = missionNamespace getVariable ["CTHUD_startupFadeDuration", 0.32];
private _startupFadeProgress = 1;

if (_startupStartedAt >= 0) then
{
    private _startupElapsed = (diag_tickTime - _startupStartedAt) max 0;
    _startupFadeProgress = linearConversion [
        _startupDuration,
        _startupDuration + _startupFadeDuration,
        _startupElapsed,
        0,
        1,
        true
    ];

    if (_startupElapsed >= (_startupDuration + _startupFadeDuration)) then
    {
        missionNamespace setVariable ["CTHUD_startupStartedAt", -1];
    };
};

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

    if (_needsDisplaySwitch || {_activeDisplayClass isEqualTo ""}) then
    {
        cutRsc [_displayClass, "PLAIN"];
        missionNamespace setVariable ["CTHUD_activeDisplayClass", _displayClass];
        missionNamespace setVariable ["CTHUD_displayRequestAt", diag_tickTime];
        missionNamespace setVariable ["CTHUD_displayRetryCount", 0];
        _display = displayNull;
    }
    else
    {
        private _displayRetries = missionNamespace getVariable ["CTHUD_displayRetryCount", 0];
        if (isNull _display && {_displayRequestAt >= 0} && {(diag_tickTime - _displayRequestAt) > 0.5} && {_displayRetries < 10}) then
        {
            cutRsc [_displayClass, "PLAIN"];
            missionNamespace setVariable ["CTHUD_displayRequestAt", diag_tickTime];
            missionNamespace setVariable ["CTHUD_displayRetryCount", _displayRetries + 1];
        };
    };

    if (isNull _display) then
    {
        _display = uiNamespace getVariable ["CTHUD_Display", findDisplay 9000];
        if (isNull _display) then
        {
            _display = findDisplay 9000;
        };
        if (!isNull _display) then
        {
            uiNamespace setVariable ["CTHUD_Display", _display];
        };
    };

    if (!isNull _display) then
    {
        private _visorCtrl = _display displayCtrl 9001;
        if (!isNull _visorCtrl) then
        {
            private _startupVisorOpacity = _visorOpacity * _startupFadeProgress;
            _visorCtrl ctrlSetText _overlayTexture;
            _visorCtrl ctrlSetTextColor [1, 1, 1, _startupVisorOpacity];
            _visorCtrl ctrlCommit 0;
            _visorCtrl ctrlShow _wantsOverlay;
        };
    };
}
else
{
    if (_temporarilySuppressed) then
    {
        if (!isNull _display) then
        {
            private _visorCtrl = _display displayCtrl 9001;
            if (!isNull _visorCtrl) then
            {
                _visorCtrl ctrlSetTextColor [1, 1, 1, 0];
                _visorCtrl ctrlShow false;
            };
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

        missionNamespace setVariable ["CTHUD_activeDisplayClass", ""];
        missionNamespace setVariable ["CTHUD_displayRequestAt", -1];
        missionNamespace setVariable ["CTHUD_trackerContacts", []];
        missionNamespace setVariable ["CTHUD_trackerNextUpdate", -1];
    };
};
