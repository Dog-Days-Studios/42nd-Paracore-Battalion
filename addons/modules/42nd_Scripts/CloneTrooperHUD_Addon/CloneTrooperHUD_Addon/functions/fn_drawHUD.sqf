if !(call CTHUD_fnc_canShowHUD) exitWith {};
disableSerialization;

private _disp = uiNamespace getVariable ["CTHUD_Display", displayNull];
if (isNull _disp) exitWith {};

private _weaponBgCtrl = _disp displayCtrl 1000;
private _weaponPreviewCtrl = _disp displayCtrl 1004;
private _weaponCtrl = _disp displayCtrl 1001;
private _magCtrl = _disp displayCtrl 1002;
private _modeCtrl = _disp displayCtrl 1003;
private _mapCtrl = _disp displayCtrl 1200;
private _mapFrameCtrl = _disp displayCtrl 1201;
private _mapBgCtrl = _disp displayCtrl 1202;
private _mapMaskCtrl = _disp displayCtrl 1203;
private _compassCtrl = _disp displayCtrl 1300;
private _bearingCtrl = _disp displayCtrl 1301;
private _compassBgCtrl = _disp displayCtrl 1302;
private _squadListBgCtrl = _disp displayCtrl 1400;
private _squadListCtrl = _disp displayCtrl 1401;
private _startupPanelCtrl = _disp displayCtrl 1500;
private _startupMainCtrl = _disp displayCtrl 1501;
private _startupStatusCtrl = _disp displayCtrl 1502;
private _startupBarBgCtrl = _disp displayCtrl 1503;
private _startupBarFillCtrl = _disp displayCtrl 1504;
private _startupBlackoutCtrl = _disp displayCtrl 1505;
private _pilotBannerBgCtrl = _disp displayCtrl 1600;
private _pilotBannerCtrl = _disp displayCtrl 1601;
private _pilotTelemetryLeftBgCtrl = _disp displayCtrl 1602;
private _pilotTelemetryLeftCtrl = _disp displayCtrl 1603;
private _pilotTelemetryRightBgCtrl = _disp displayCtrl 1604;
private _pilotTelemetryRightCtrl = _disp displayCtrl 1605;

private _color = call CTHUD_fnc_getHudColor;
private _isPilotHud = call CTHUD_fnc_isPilotHudHelmet;
private _startupStartedAt = missionNamespace getVariable ["CTHUD_startupStartedAt", -1];
private _startupDuration = missionNamespace getVariable ["CTHUD_startupDuration", 1.35];
private _startupFadeDuration = missionNamespace getVariable ["CTHUD_startupFadeDuration", 0.32];
private _startupProgress = 1;
private _startupFadeProgress = 1;
private _startupActive = _startupStartedAt >= 0;
if (_startupActive) then
{
    private _startupElapsed = (diag_tickTime - _startupStartedAt) max 0;
    _startupProgress = (_startupElapsed / _startupDuration) max 0 min 1;
    _startupFadeProgress = linearConversion [
        _startupDuration,
        _startupDuration + _startupFadeDuration,
        _startupElapsed,
        0,
        1,
        true
    ];
};

private _hudRevealAlpha = _startupFadeProgress;
private _hudTextColor = [_color select 0, _color select 1, _color select 2, _hudRevealAlpha];
private _weaponBgColor = [0.18, 0.18, 0.18, 0.45 * _hudRevealAlpha];
private _panelBgColor = [0.12, 0.12, 0.12, 0.35 * _hudRevealAlpha];
private _mapBgColor = [0.08, 0.08, 0.08, 0.35 * _hudRevealAlpha];
private _enemyColor = missionNamespace getVariable ["CTHUD_enemyColor", [1, 0.05, 0.05, 1]];
private _friendlyColor = missionNamespace getVariable ["CTHUD_friendlyColor", [0.15, 1, 0.35, 1]];
private _hudLayout = call CTHUD_fnc_getHudLayout;
private _textScale = _hudLayout select 1;
private _maxSquadLines = _hudLayout select 2;

_weaponCtrl ctrlSetTextColor _hudTextColor;
_magCtrl ctrlSetTextColor _hudTextColor;
_modeCtrl ctrlSetTextColor _hudTextColor;
_compassCtrl ctrlSetTextColor _hudTextColor;
_bearingCtrl ctrlSetTextColor _hudTextColor;
_mapFrameCtrl ctrlSetTextColor _hudTextColor;
_weaponBgCtrl ctrlSetBackgroundColor _weaponBgColor;
_compassBgCtrl ctrlSetBackgroundColor _panelBgColor;
_squadListBgCtrl ctrlSetBackgroundColor _panelBgColor;
_mapBgCtrl ctrlSetBackgroundColor _mapBgColor;

private _weaponClass = currentWeapon player;
private _weaponName = "UNARMED";
private _weaponMode = "SAFE";
private _loadedRounds = 0;
private _reserveRounds = 0;
if (_weaponClass != "") then
{
    _weaponName = getText (configFile >> "CfgWeapons" >> _weaponClass >> "displayName");
    if (_weaponName isEqualTo "") then {_weaponName = _weaponClass;};

    _weaponMode = currentWeaponMode player;
    if (_weaponMode isEqualTo "") then {_weaponMode = "SAFE";};

    private _magClass = currentMagazine player;
    private _magCountCfg = (getNumber (configFile >> "CfgMagazines" >> _magClass >> "count")) max 0;
    private _reserveMags = ((count (magazines player select {_x isEqualTo _magClass})) - 1) max 0;
    _loadedRounds = player ammo _weaponClass;
    _reserveRounds = _reserveMags * _magCountCfg;
};

_weaponCtrl ctrlSetText ("WEAPON: " + _weaponName);
_modeCtrl ctrlSetText ("MODE: " + toUpper _weaponMode);
_magCtrl ctrlSetText (("MAG: " + str _loadedRounds) + (" | RES: " + str _reserveRounds));

private _weaponPicture = "";
if (_weaponClass != "") then
{
    private _weaponCfg = configFile >> "CfgWeapons" >> _weaponClass;
    if (isClass _weaponCfg) then
    {
        _weaponPicture = getText (_weaponCfg >> "picture");
    };
};

if (_weaponPicture != "") then
{
    _weaponPreviewCtrl ctrlSetText _weaponPicture;
    _weaponPreviewCtrl ctrlShow true;
}
else
{
    _weaponPreviewCtrl ctrlSetText "";
    _weaponPreviewCtrl ctrlShow false;
};

private _bearing = round (getDirVisual player);
if (_bearing < 0) then {
    _bearing = _bearing + 360;
};
if (_bearing >= 360) then {
    _bearing = _bearing mod 360;
};

private _bearingText = str _bearing;
while {count _bearingText < 3} do {
    _bearingText = "0" + _bearingText;
};

private _cardinals = ["N", "NE", "E", "SE", "S", "SW", "W", "NW", "N"];
private _cardinal = _cardinals select (round (_bearing / 45));
_compassCtrl ctrlSetText format ["COMPASS %1", _cardinal];
_bearingCtrl ctrlSetText format ["BEARING %1", _bearingText];

private _hexDigits = "0123456789ABCDEF";
private _toHex = {
    params ["_component"];
    private _value = floor (((_component max 0) min 1) * 255);
    format [
        "%1%2",
        _hexDigits select [floor (_value / 16), 1],
        _hexDigits select [_value mod 16, 1]
    ]
};
private _colorHex = format [
    "#%1%2%3",
    [_color select 0] call _toHex,
    [_color select 1] call _toHex,
    [_color select 2] call _toHex
];
private _friendlyColorHex = format [
    "#%1%2%3",
    [_friendlyColor select 0] call _toHex,
    [_friendlyColor select 1] call _toHex,
    [_friendlyColor select 2] call _toHex
];

private _groupMembers = units group player select {alive _x};
if (_startupProgress < 0.68 || {_groupMembers isEqualTo []}) then
{
    _squadListBgCtrl ctrlShow false;
    _squadListCtrl ctrlShow false;
}
else
{
    private _displayedGroupMembers = +_groupMembers;
    private _overflowCount = 0;
    if ((count _displayedGroupMembers) > _maxSquadLines) then
    {
        _overflowCount = (count _displayedGroupMembers) - (_maxSquadLines - 1);
        _displayedGroupMembers resize (_maxSquadLines - 1);
    };

    private _squadLines = _displayedGroupMembers apply {
        private _prefix = ["", "&gt; "] select (_x isEqualTo player);
        private _leaderTag = ["", "L "] select (_x isEqualTo leader group player);
        format ["<t color='%1'>%2%3%4</t>", _friendlyColorHex, _prefix, _leaderTag, name _x]
    };
    if (_overflowCount > 0) then
    {
        _squadLines pushBack format ["<t color='%1'>+%2 more</t>", _friendlyColorHex, _overflowCount];
    };

    _squadListBgCtrl ctrlShow true;
    _squadListCtrl ctrlShow true;
    _squadListCtrl ctrlSetStructuredText parseText (_squadLines joinString "<br/>");
};

private _showMap = (missionNamespace getVariable ["CTHUD_showMiniMap", true]) && {_startupProgress >= 0.58};
_mapCtrl ctrlShow _showMap;
_mapFrameCtrl ctrlShow _showMap;
_mapBgCtrl ctrlShow _showMap;
_mapMaskCtrl ctrlShow _showMap;
if (_showMap) then
{
    _mapCtrl ctrlMapAnimAdd [0, 0.04, getPosVisual player];
    ctrlMapAnimCommit _mapCtrl;
};

private _defaultEnemyMaxDist = ((missionNamespace getVariable ["CTHUD_enemyMaxDistance", 150]) max 0) min 150;
private _pilotEnemyMaxDist = ((missionNamespace getVariable ["CTHUD_pilotEnemyMaxDistance", 1000]) max 0) min 1000;
private _enemyMaxDist = [_defaultEnemyMaxDist, _pilotEnemyMaxDist] select _isPilotHud;
private _friendlyMaxDist = ((missionNamespace getVariable ["CTHUD_friendlyMaxDistance", 1000]) max 0) min 1000;
private _markersReady = _startupProgress >= 0.72;
private _enemyMarkerMinAlpha = [0.35, 0.18] select _isPilotHud;
private _enemyMarkerSize = [0.75, 0.58] select _isPilotHud;
private _enemyMarkerTextSize = ([0.028, 0.022] select _isPilotHud) * _textScale;
private _enemyMarkerIconTextSize = ([0.035, 0.028] select _isPilotHud) * _textScale;

{
    private _unit = _x;
    private _iff = [_unit] call CTHUD_fnc_getIFF;

    if (_markersReady && _enemyMaxDist > 0 && {_iff isEqualTo "enemy"}) then
    {
        private _dist = player distance _unit;
        if (_dist <= _enemyMaxDist && {[_unit] call CTHUD_fnc_hasDirectLineOfSight}) then
        {
            private _pos = ASLToAGL eyePos _unit;
            _pos set [2, (_pos select 2) + 0.55];

            private _alpha = 1 - (_dist / _enemyMaxDist);
            if (_alpha < _enemyMarkerMinAlpha) then {_alpha = _enemyMarkerMinAlpha;};

            private _drawColor = [_enemyColor select 0, _enemyColor select 1, _enemyColor select 2, _alpha];

            drawIcon3D [
                "\A3\ui_f\data\igui\cfg\Cursors\select_ca.paa",
                _drawColor,
                _pos,
                _enemyMarkerSize,
                _enemyMarkerSize,
                45,
                "",
                1,
                _enemyMarkerIconTextSize,
                "RobotoCondensed"
            ];

            drawIcon3D [
                "",
                _drawColor,
                [_pos select 0, _pos select 1, (_pos select 2) + 0.2],
                0,
                0,
                0,
                (str (round _dist)) + "m",
                1,
                _enemyMarkerTextSize,
                "RobotoCondensed"
            ];
        };
    };

    if (_markersReady && _friendlyMaxDist > 0 && {_iff isEqualTo "friendly"}) then
    {
        private _dist = player distance _unit;
        if (_dist <= _friendlyMaxDist && {[_unit] call CTHUD_fnc_hasDirectLineOfSight}) then
        {
            private _pos = ASLToAGL eyePos _unit;
            _pos set [2, (_pos select 2) + 0.35];

            private _alpha = 1 - (_dist / _friendlyMaxDist);
            if (_alpha < 0.2) then {_alpha = 0.2;};

            private _drawColor = [_friendlyColor select 0, _friendlyColor select 1, _friendlyColor select 2, _alpha];

            drawIcon3D [
                "\A3\ui_f\data\map\markers\military\warning_CA.paa",
                _drawColor,
                _pos,
                0.5,
                0.5,
                0,
                "",
                1,
                0.025,
                "RobotoCondensed"
            ];
        };
    };
} forEach allUnits;

if (_isPilotHud && {_hudRevealAlpha > 0.01}) then
{
    private _pilotPanelAlpha = _hudRevealAlpha;
    private _pilotPanelBgColor = [0.05, 0.08, 0.11, 0.26 * _pilotPanelAlpha];
    private _pilotBannerBgColor = [0.03, 0.06, 0.08, 0.28 * _pilotPanelAlpha];
    private _pilotTextColor = [_color select 0, _color select 1, _color select 2, 0.95 * _pilotPanelAlpha];
    private _vehicle = vehicle player;
    private _displayVehicle = if (_vehicle isEqualTo player) then {"STANDBY"} else {getText (configOf _vehicle >> "displayName")};
    private _speed = round (speed _vehicle);
    private _asl = round ((getPosASL _vehicle) select 2);
    private _agl = round ((getPosATL _vehicle) select 2);
    private _rangeLabel = if (_enemyMaxDist >= 1000) then {"1.0KM"} else {format ["%1M", round _enemyMaxDist]};
    private _pilotLeftText = parseText format [
        "<t color='%1' shadow='0'>SPD %2 km/h<br/>ASL %3 m</t>",
        _colorHex,
        _speed,
        _asl
    ];
    private _pilotRightText = parseText format [
        "<t color='%1' shadow='0'>HDG %2<br/>AGL %3 m</t>",
        _colorHex,
        _bearingText,
        _agl
    ];

    _pilotBannerBgCtrl ctrlSetBackgroundColor _pilotBannerBgColor;
    _pilotBannerCtrl ctrlSetText format ["PILOT HUD // %1 // SENSOR %2", _displayVehicle, _rangeLabel];
    _pilotBannerCtrl ctrlSetTextColor _pilotTextColor;
    _pilotTelemetryLeftBgCtrl ctrlSetBackgroundColor _pilotPanelBgColor;
    _pilotTelemetryRightBgCtrl ctrlSetBackgroundColor _pilotPanelBgColor;
    _pilotTelemetryLeftCtrl ctrlSetStructuredText _pilotLeftText;
    _pilotTelemetryRightCtrl ctrlSetStructuredText _pilotRightText;

    _pilotBannerBgCtrl ctrlShow true;
    _pilotBannerCtrl ctrlShow true;
    _pilotTelemetryLeftBgCtrl ctrlShow true;
    _pilotTelemetryLeftCtrl ctrlShow true;
    _pilotTelemetryRightBgCtrl ctrlShow true;
    _pilotTelemetryRightCtrl ctrlShow true;
}
else
{
    _pilotBannerBgCtrl ctrlShow false;
    _pilotBannerCtrl ctrlShow false;
    _pilotTelemetryLeftBgCtrl ctrlShow false;
    _pilotTelemetryLeftCtrl ctrlShow false;
    _pilotTelemetryRightBgCtrl ctrlShow false;
    _pilotTelemetryRightCtrl ctrlShow false;
};

if (_startupActive) then
{
    private _startupOverlayAlpha = 1 - _startupFadeProgress;
    private _startupStage = "VISOR LINK";
    private _startupStatus = "Synchronizing helmet systems";

    if (_startupProgress < 0.2) then
    {
        _startupStage = "OPTICS CAL";
        _startupStatus = "Calibrating visor optics";
    }
    else
    {
        if (_startupProgress < 0.42) then
        {
            _startupStage = "IFF CHECK";
            _startupStatus = "Building friendly / enemy filter";
        }
        else
        {
            if (_startupProgress < 0.68) then
            {
                _startupStage = "TACNET SYNC";
                _startupStatus = "Linking range, compass, and feed";
            }
            else
            {
                _startupStage = "HUD ONLINE";
                _startupStatus = "Mission overlay ready";
            };
        };
    };

    private _startupColor = [_color select 0, _color select 1, _color select 2, 0.92 * _startupOverlayAlpha];
    private _startupPanelColor = [0.02, 0.05, 0.07, 0.6 * _startupOverlayAlpha];
    private _startupBarBgColor = [_color select 0, _color select 1, _color select 2, 0.2 * _startupOverlayAlpha];
    private _startupBarFillColor = [_color select 0, _color select 1, _color select 2, 0.94 * _startupOverlayAlpha];
    private _startupBlackoutColor = [0, 0, 0, _startupOverlayAlpha];
    private _startupBarPos = ctrlPosition _startupBarBgCtrl;
    private _startupFillPos = +_startupBarPos;
    _startupFillPos set [2, (_startupBarPos select 2) * _startupProgress];

    _startupBlackoutCtrl ctrlSetBackgroundColor _startupBlackoutColor;
    _startupPanelCtrl ctrlSetBackgroundColor _startupPanelColor;
    _startupMainCtrl ctrlSetText _startupStage;
    _startupMainCtrl ctrlSetTextColor _startupColor;
    _startupStatusCtrl ctrlSetText format ["%1%%  //  %2", round (_startupProgress * 100), _startupStatus];
    _startupStatusCtrl ctrlSetTextColor _startupColor;
    _startupBarBgCtrl ctrlSetBackgroundColor _startupBarBgColor;
    _startupBarFillCtrl ctrlSetBackgroundColor _startupBarFillColor;
    _startupBarFillCtrl ctrlSetPosition _startupFillPos;
    _startupBarFillCtrl ctrlCommit 0;

    _startupBlackoutCtrl ctrlShow true;
    _startupPanelCtrl ctrlShow true;
    _startupMainCtrl ctrlShow true;
    _startupStatusCtrl ctrlShow true;
    _startupBarBgCtrl ctrlShow true;
    _startupBarFillCtrl ctrlShow true;
}
else
{
    _startupBlackoutCtrl ctrlShow false;
    _startupPanelCtrl ctrlShow false;
    _startupMainCtrl ctrlShow false;
    _startupStatusCtrl ctrlShow false;
    _startupBarBgCtrl ctrlShow false;
    _startupBarFillCtrl ctrlShow false;
};
