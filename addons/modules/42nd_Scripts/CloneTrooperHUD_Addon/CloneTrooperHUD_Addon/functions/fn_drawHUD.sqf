disableSerialization;

params [["_drawWorldMarkers", true, [true]]];

private _disp = uiNamespace getVariable ["CTHUD_Display", findDisplay 9000];
if (isNull _disp) then
{
    _disp = findDisplay 9000;
};
if (!isNull _disp) then
{
    uiNamespace setVariable ["CTHUD_Display", _disp];
};
if (isNull _disp) exitWith {};

private _weaponBgCtrl = _disp displayCtrl 1000;
private _weaponPreviewCtrl = _disp displayCtrl 1004;
private _weaponCtrl = _disp displayCtrl 1001;
private _magCtrl = _disp displayCtrl 1002;
private _modeCtrl = _disp displayCtrl 1003;
private _visorCtrl = _disp displayCtrl 9001;
private _mapCtrl = _disp displayCtrl 1200;
private _mapFrameCtrl = _disp displayCtrl 1201;
private _mapBgCtrl = _disp displayCtrl 1202;
private _trackerPanelCtrl = _disp displayCtrl 1210;
private _trackerVerticalCtrl = _disp displayCtrl 1211;
private _trackerHorizontalCtrl = _disp displayCtrl 1212;
private _trackerCenterCtrl = _disp displayCtrl 1213;
private _trackerSweepCtrl = _disp displayCtrl 1214;
private _trackerTitleCtrl = _disp displayCtrl 1215;
private _trackerStatusCtrl = _disp displayCtrl 1216;
private _trackerOuterRingCtrl = _disp displayCtrl 1217;
private _trackerMidRingCtrl = _disp displayCtrl 1218;
private _trackerInnerRingCtrl = _disp displayCtrl 1219;
private _compassCtrl = _disp displayCtrl 1300;
private _bearingCtrl = _disp displayCtrl 1301;
private _compassBgCtrl = _disp displayCtrl 1302;
private _compassCenterCtrl = _disp displayCtrl 1303;
private _healthBarBgCtrl = _disp displayCtrl 1310;
private _healthBarFillCtrl = _disp displayCtrl 1311;
private _healthTextCtrl = _disp displayCtrl 1312;
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
private _trackerBlipCtrls = [];
for "_idc" from 1220 to 1231 do {
    _trackerBlipCtrls pushBack (_disp displayCtrl _idc);
};

private _hideCtrl = {
    params ["_ctrl"];
    if (!isNull _ctrl) then {
        _ctrl ctrlShow false;
    };
};

private _resetTextCtrl = {
    params ["_ctrl"];
    if (!isNull _ctrl) then {
        _ctrl ctrlSetText "";
        _ctrl ctrlShow false;
    };
};

private _resetStructuredCtrl = {
    params ["_ctrl"];
    if (!isNull _ctrl) then {
        _ctrl ctrlSetStructuredText parseText "";
        _ctrl ctrlShow false;
    };
};

private _resetPictureCtrl = {
    params ["_ctrl"];
    if (!isNull _ctrl) then {
        _ctrl ctrlSetText "";
        _ctrl ctrlSetTextColor [1, 1, 1, 0];
        _ctrl ctrlShow false;
    };
};

private _resetTrackerBlipCtrl = {
    params ["_ctrl"];
    if (!isNull _ctrl) then {
        _ctrl ctrlSetPosition [0, 0, 0, 0];
        _ctrl ctrlSetBackgroundColor [0, 0, 0, 0];
        _ctrl ctrlCommit 0;
        _ctrl ctrlShow false;
    };
};

private _resetHudDisplay = {
    [_visorCtrl] call _resetPictureCtrl;
    [_weaponPreviewCtrl] call _resetPictureCtrl;

    {
        [_x] call _hideCtrl;
    } forEach [
        _weaponBgCtrl,
        _mapCtrl,
        _mapFrameCtrl,
        _mapBgCtrl,
        _trackerPanelCtrl,
        _trackerOuterRingCtrl,
        _trackerMidRingCtrl,
        _trackerInnerRingCtrl,
        _startupPanelCtrl,
        _startupBarBgCtrl,
        _startupBarFillCtrl,
        _startupBlackoutCtrl,
        _pilotBannerBgCtrl,
        _pilotTelemetryLeftBgCtrl,
        _pilotTelemetryRightBgCtrl,
        _compassBgCtrl,
        _compassCenterCtrl,
        _healthBarBgCtrl,
        _healthBarFillCtrl,
        _squadListBgCtrl
    ];

    {
        [_x] call _resetTextCtrl;
    } forEach [
        _weaponCtrl,
        _magCtrl,
        _modeCtrl,
        _compassCtrl,
        _bearingCtrl,
        _healthTextCtrl,
        _trackerTitleCtrl,
        _trackerStatusCtrl,
        _startupMainCtrl,
        _startupStatusCtrl,
        _pilotBannerCtrl
    ];

    {
        [_x] call _resetStructuredCtrl;
    } forEach [
        _squadListCtrl,
        _pilotTelemetryLeftCtrl,
        _pilotTelemetryRightCtrl
    ];

    {
        if (!isNull _x) then {
            _x ctrlSetBackgroundColor [0, 0, 0, 0];
            _x ctrlShow false;
        };
    } forEach [
        _trackerVerticalCtrl,
        _trackerHorizontalCtrl,
        _trackerCenterCtrl,
        _trackerSweepCtrl
    ];

    {
        [_x] call _resetTrackerBlipCtrl;
    } forEach _trackerBlipCtrls;

    if (!isNull _startupBarBgCtrl && {!isNull _startupBarFillCtrl}) then {
        private _startupBarPos = ctrlPosition _startupBarBgCtrl;
        private _startupFillPos = +_startupBarPos;
        _startupFillPos set [2, 0];
        _startupBarFillCtrl ctrlSetPosition _startupFillPos;
        _startupBarFillCtrl ctrlCommit 0;
    };

    if (!isNull _healthBarBgCtrl && {!isNull _healthBarFillCtrl}) then {
        private _healthBarPos = ctrlPosition _healthBarBgCtrl;
        private _healthFillPos = +_healthBarPos;
        _healthFillPos set [2, 0];
        _healthBarFillCtrl ctrlSetPosition _healthFillPos;
        _healthBarFillCtrl ctrlCommit 0;
    };
};

if !(call CTHUD_fnc_canShowHUD) exitWith {
    call _resetHudDisplay;
};

private _color = call CTHUD_fnc_getHudColor;
private _isPilotHud = call CTHUD_fnc_isPilotHudHelmet;
private _cameraView = toUpper cameraView;
private _useInteriorVisor = missionNamespace getVariable ["CTHUD_showInteriorVisor", true];
private _wantsOverlay = _useInteriorVisor && {_cameraView in ["INTERNAL", "GUNNER", "OPTICS"]};
private _overlayTexture = [_isPilotHud] call CTHUD_fnc_getVisorTexture;
private _visorOpacity = (((missionNamespace getVariable ["CTHUD_interiorVisorOpacity", 100]) max 0) min 100) / 100;
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
private _weaponBgColor = [0.05, 0.07, 0.09, 0.26 * _hudRevealAlpha];
private _panelBgColor = [0.05, 0.07, 0.09, 0.24 * _hudRevealAlpha];
private _mapBgColor = [0.08, 0.08, 0.08, 0.35 * _hudRevealAlpha];
private _trackerPanelColor = [0, 0, 0, 0];
private _trackerLineColor = [_color select 0, _color select 1, _color select 2, 0.16 * _hudRevealAlpha];
private _trackerCenterColor = [_color select 0, _color select 1, _color select 2, 0.85 * _hudRevealAlpha];
private _compassCenterColor = [_color select 0, _color select 1, _color select 2, 0.82 * _hudRevealAlpha];
private _healthBarBgColor = [_color select 0, _color select 1, _color select 2, 0.14 * _hudRevealAlpha];
// Colors already validated in preInit — no per-frame normalization needed
private _enemyColor = missionNamespace getVariable ["CTHUD_enemyColor", [1, 0.05, 0.05, 1]];
private _friendlyColor = missionNamespace getVariable ["CTHUD_friendlyColor", [0.15, 1, 0.35, 1]];
private _hudLayout = call CTHUD_fnc_getHudLayout;
private _textScale = _hudLayout select 1;
private _maxSquadLines = _hudLayout select 2;
private _padNumber = {
    params ["_value", ["_width", 3]];
    private _valueText = str ((round _value) max 0);
    while {count _valueText < _width} do {
        _valueText = "0" + _valueText;
    };
    _valueText
};

if (!isNull _visorCtrl) then
{
    private _finalVisorAlpha = _visorOpacity * _startupFadeProgress;
    _visorCtrl ctrlSetText _overlayTexture;
    _visorCtrl ctrlSetTextColor [1, 1, 1, _finalVisorAlpha];
    _visorCtrl ctrlSetFade ([1, 0] select _wantsOverlay);
    _visorCtrl ctrlCommit 0;
    _visorCtrl ctrlShow _wantsOverlay;
};

_weaponCtrl ctrlSetTextColor _hudTextColor;
_magCtrl ctrlSetTextColor _hudTextColor;
_modeCtrl ctrlSetTextColor _hudTextColor;
_compassCtrl ctrlSetTextColor _hudTextColor;
_bearingCtrl ctrlSetTextColor _hudTextColor;
_healthTextCtrl ctrlSetTextColor _hudTextColor;
_mapFrameCtrl ctrlSetTextColor [1, 1, 1, 0];
_trackerTitleCtrl ctrlSetTextColor _hudTextColor;
_trackerStatusCtrl ctrlSetTextColor _hudTextColor;
_weaponBgCtrl ctrlSetBackgroundColor _weaponBgColor;
_compassBgCtrl ctrlSetBackgroundColor _panelBgColor;
_compassCenterCtrl ctrlSetBackgroundColor _compassCenterColor;
_healthBarBgCtrl ctrlSetBackgroundColor _healthBarBgColor;
_squadListBgCtrl ctrlSetBackgroundColor _panelBgColor;
_mapBgCtrl ctrlSetBackgroundColor _mapBgColor;
_trackerPanelCtrl ctrlSetBackgroundColor _trackerPanelColor;
_trackerVerticalCtrl ctrlSetBackgroundColor _trackerLineColor;
_trackerHorizontalCtrl ctrlSetBackgroundColor _trackerLineColor;
_trackerCenterCtrl ctrlSetBackgroundColor _trackerCenterColor;
_trackerOuterRingCtrl ctrlSetTextColor [_color select 0, _color select 1, _color select 2, 0.18 * _hudRevealAlpha];
_trackerMidRingCtrl ctrlSetTextColor [_color select 0, _color select 1, _color select 2, 0.12 * _hudRevealAlpha];
_trackerInnerRingCtrl ctrlSetTextColor [_color select 0, _color select 1, _color select 2, 0.1 * _hudRevealAlpha];
_weaponBgCtrl ctrlShow true;
_weaponCtrl ctrlShow true;
_magCtrl ctrlShow true;
_modeCtrl ctrlShow true;
_compassBgCtrl ctrlShow true;
_compassCtrl ctrlShow true;
_bearingCtrl ctrlShow true;
_compassCenterCtrl ctrlShow true;
_healthBarBgCtrl ctrlShow true;
_healthBarFillCtrl ctrlShow true;
_healthTextCtrl ctrlShow true;

private _weaponClass = currentWeapon player;
private _weaponName = "UNARMED";
private _weaponMode = "SAFE";
private _loadedRounds = 0;
private _reserveRounds = 0;
private _magCapacity = 0;
private _weaponPicture = "";
if (_weaponClass != "") then
{
    _weaponMode = currentWeaponMode player;
    if (_weaponMode isEqualTo "") then {_weaponMode = "SAFE"};

    private _magClass = currentMagazine player;
    _loadedRounds = player ammo _weaponClass;
    private _magCountCfg = (getNumber (configFile >> "CfgMagazines" >> _magClass >> "count")) max 0;
    _magCapacity = _magCountCfg;
    private _reserveMags = ((count (magazines player select {_x isEqualTo _magClass})) - 1) max 0;
    _reserveRounds = _reserveMags * _magCountCfg;

    // Cache weapon name + picture per classname to avoid config traversal every frame
    private _weaponCache = missionNamespace getVariable ["CTHUD_weaponInfoCache", createHashMap];
    private _cached = _weaponCache getOrDefault [_weaponClass, []];
    if (_cached isEqualTo []) then {
        private _cachedName = "";
        private _cachedPic = "";
        private _weaponCfg = configFile >> "CfgWeapons" >> _weaponClass;
        if (isClass _weaponCfg) then {
            _cachedName = getText (_weaponCfg >> "displayName");
            _cachedPic = getText (_weaponCfg >> "picture");
            if (_cachedPic isEqualTo "") then {_cachedPic = getText (_weaponCfg >> "UiPicture")};
            if (_cachedPic isEqualTo "") then {
                private _baseWeaponClass = getText (_weaponCfg >> "baseWeapon");
                if (_baseWeaponClass isNotEqualTo "" && {_baseWeaponClass isNotEqualTo _weaponClass}) then {
                    private _baseWeaponCfg = configFile >> "CfgWeapons" >> _baseWeaponClass;
                    if (isClass _baseWeaponCfg) then {
                        _cachedPic = getText (_baseWeaponCfg >> "picture");
                        if (_cachedPic isEqualTo "") then {_cachedPic = getText (_baseWeaponCfg >> "UiPicture")};
                    };
                };
            };
        };
        _cached = [_cachedName, _cachedPic];
        _weaponCache set [_weaponClass, _cached];
        missionNamespace setVariable ["CTHUD_weaponInfoCache", _weaponCache];
    };

    _weaponName = _cached select 0;
    if (_weaponName isEqualTo "") then {_weaponName = _weaponClass};
    _weaponPicture = _cached select 1;

    // Fallback to magazine picture if weapon has none
    if (_weaponPicture isEqualTo "") then {
        private _magClass = currentMagazine player;
        if (_magClass isNotEqualTo "") then {
            _weaponPicture = getText (configFile >> "CfgMagazines" >> _magClass >> "picture");
        };
    };
};

private _weaponDisplayName = toUpper _weaponName;
if ((count _weaponDisplayName) > 26) then {
    _weaponDisplayName = (_weaponDisplayName select [0, 23]) + "...";
};

private _ammoTextColor = +_hudTextColor;
if (_magCapacity > 0) then {
    if (_loadedRounds <= 0) then {
        _ammoTextColor = [1, 0.12, 0.08, _hudRevealAlpha];
    } else {
        if (_loadedRounds <= ceil (_magCapacity * 0.25)) then {
            _ammoTextColor = [1, 0.68, 0.12, _hudRevealAlpha];
        };
    };
};

_weaponCtrl ctrlSetText _weaponDisplayName;
_weaponCtrl ctrlSetTextColor _hudTextColor;
_magCtrl ctrlSetTextColor _ammoTextColor;
_modeCtrl ctrlSetTextColor _ammoTextColor;
_magCtrl ctrlSetText format [
    "%1 / %2",
    [_loadedRounds, 3] call _padNumber,
    [_magCapacity, 3] call _padNumber
];
_modeCtrl ctrlSetText format ["%1 // RES %2", toUpper _weaponMode, _reserveRounds];

if (_weaponPicture != "") then
{
    _weaponPreviewCtrl ctrlSetText _weaponPicture;
    _weaponPreviewCtrl ctrlSetTextColor [1, 1, 1, _hudRevealAlpha];
    _weaponPreviewCtrl ctrlShow true;
}
else
{
    _weaponPreviewCtrl ctrlSetText "";
    _weaponPreviewCtrl ctrlSetTextColor [1, 1, 1, 0];
    _weaponPreviewCtrl ctrlShow false;
};

private _bearing = round (getDirVisual player);
if (_bearing < 0) then {
    _bearing = _bearing + 360;
};
if (_bearing >= 360) then {
    _bearing = _bearing mod 360;
};

private _bearingText = [_bearing, 3] call _padNumber;

private _formatCompassMarker = {
    params ["_bearingValue"];
    private _normalized = round _bearingValue;
    while {_normalized < 0} do {
        _normalized = _normalized + 360;
    };
    if (_normalized >= 360) then {
        _normalized = _normalized mod 360;
    };

    switch (_normalized) do {
        case 0: {"N"};
        case 45: {"NE"};
        case 90: {"E"};
        case 135: {"SE"};
        case 180: {"S"};
        case 225: {"SW"};
        case 270: {"W"};
        case 315: {"NW"};
        default { [_normalized, 3] call _padNumber };
    };
};

private _compassMarks = [-60, -30, 0, 30, 60] apply {
    private _marker = [_bearing + _x] call _formatCompassMarker;
    if (_x isEqualTo 0) then {
        format [">%1<", _marker]
    } else {
        _marker
    };
};
_compassCtrl ctrlSetText (_compassMarks joinString "   ");
_bearingCtrl ctrlSetText format ["AZ %1", _bearingText];

private _healthFraction = (1 - damage player) max 0 min 1;
private _healthPercent = round (_healthFraction * 100);
private _healthFillColor = switch true do {
    case (_healthFraction < 0.3): { [1, 0.12, 0.08, 0.94 * _hudRevealAlpha] };
    case (_healthFraction < 0.6): { [1, 0.68, 0.12, 0.92 * _hudRevealAlpha] };
    default { [_color select 0, _color select 1, _color select 2, 0.94 * _hudRevealAlpha] };
};
private _healthFillPos = ctrlPosition _healthBarBgCtrl;
_healthFillPos set [2, (_healthFillPos select 2) * _healthFraction];
_healthBarFillCtrl ctrlSetBackgroundColor _healthFillColor;
_healthBarFillCtrl ctrlSetPosition _healthFillPos;
_healthBarFillCtrl ctrlCommit 0;
_healthTextCtrl ctrlSetText format ["VITALS %1%%", _healthPercent];
_healthTextCtrl ctrlSetTextColor _healthFillColor;

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
if (_startupProgress < 0.68 || {_groupMembers isEqualTo []}) then // squad list appears at 68% startup
{
    _squadListBgCtrl ctrlShow false;
    _squadListCtrl ctrlShow false;
    _squadListCtrl ctrlSetStructuredText parseText "";
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

// Sensor pane settings already validated in preInit + CBA callbacks
private _showSensorPane = missionNamespace getVariable ["CTHUD_showMiniMap", true];
private _sensorPaneMode = missionNamespace getVariable ["CTHUD_sensorPaneMode", "sensor"];

private _sensorPaneVisible = _showSensorPane && {_startupProgress >= 0.58}; // sensor pane appears at 58% startup

private _sensorVehicle = objectParent player;
private _sensorObject = if (isNull _sensorVehicle) then {player} else {_sensorVehicle};
private _isRadarMode = _isPilotHud && {!isNull _sensorVehicle};
private _showMiniMapPane = _sensorPaneVisible && {_sensorPaneMode isEqualTo "minimap"};
private _showTrackerPane = _sensorPaneVisible && {_sensorPaneMode isEqualTo "sensor"};

_mapCtrl ctrlShow _showMiniMapPane;
_mapFrameCtrl ctrlShow false;
_mapBgCtrl ctrlShow _sensorPaneVisible;
_trackerPanelCtrl ctrlShow _showTrackerPane;
_trackerVerticalCtrl ctrlShow _showTrackerPane;
_trackerHorizontalCtrl ctrlShow _showTrackerPane;
_trackerCenterCtrl ctrlShow _showTrackerPane;
_trackerSweepCtrl ctrlShow _showTrackerPane;
_trackerTitleCtrl ctrlShow _showTrackerPane;
_trackerStatusCtrl ctrlShow _showTrackerPane;
_trackerOuterRingCtrl ctrlShow _showTrackerPane;
_trackerMidRingCtrl ctrlShow _showTrackerPane;
_trackerInnerRingCtrl ctrlShow _showTrackerPane;
{
    _x ctrlShow false;
} forEach _trackerBlipCtrls;

if (_showMiniMapPane) then
{
    private _mapFocus = _sensorObject;
    private _mapScale = [0.05, 0.12] select _isRadarMode;
    _mapCtrl ctrlMapAnimAdd [0, _mapScale, getPosVisual _mapFocus];
    ctrlMapAnimCommit _mapCtrl;
};

if (_showTrackerPane) then
{
    private _trackerContacts = call CTHUD_fnc_updateTrackerContacts;
    private _activeTrackerContacts = _trackerContacts select {(_x select 6) isEqualTo "active"};
    private _trackerRange = if (_isRadarMode) then {
        ((missionNamespace getVariable ["CTHUD_trackerPilotRange", 450]) max 100) min 1500
    } else {
        ((missionNamespace getVariable ["CTHUD_trackerRange", 60]) max 15) min 150
    };
    private _trackerAreaPos = ctrlPosition _trackerPanelCtrl;
    private _trackerX = _trackerAreaPos select 0;
    private _trackerY = _trackerAreaPos select 1;
    private _trackerW = _trackerAreaPos select 2;
    private _trackerH = _trackerAreaPos select 3;
    private _trackerCenterX = _trackerX + (_trackerW / 2);
    private _trackerCenterY = _trackerY + (_trackerH / 2);
    private _trackerRadius = ((_trackerW min _trackerH) / 2) * 0.78;
    private _sweepLength = _trackerRadius * 0.98;
    private _sweepThickness = (_trackerW min _trackerH) * 0.01;
    private _sweepSpeed = [145, 95] select _isRadarMode;
    private _sweepAngle = (diag_tickTime * _sweepSpeed) mod 360;
    private _sweepAlpha = [0.18, 0.12] select _isRadarMode;
    private _sweepColor = [_color select 0, _color select 1, _color select 2, _sweepAlpha * _hudRevealAlpha];
    private _contactCount = count _activeTrackerContacts;
    private _trackerTitle = ["MOTION TRACKER", "TACTICAL RADAR"] select _isRadarMode;
    private _contactLabel = ["CONTACT", "TRACK"] select _isRadarMode;
    private _contactSuffix = ["S", ""] select (_contactCount isEqualTo 1);

    _trackerTitleCtrl ctrlSetText _trackerTitle;
    _trackerStatusCtrl ctrlSetText format ["RNG %1M // %2 %3%4", round _trackerRange, _contactCount, _contactLabel, _contactSuffix];
    _trackerSweepCtrl ctrlSetBackgroundColor _sweepColor;
    _trackerSweepCtrl ctrlSetPosition [
        _trackerCenterX,
        _trackerCenterY - (_sweepThickness / 2),
        _sweepLength,
        _sweepThickness
    ];
    _trackerSweepCtrl ctrlCommit 0;
    _trackerSweepCtrl ctrlSetAngle [_sweepAngle, 0, 0.5];

    {
        if (_forEachIndex >= count _trackerContacts) then {
            continue;
        };

        private _contact = _trackerContacts select _forEachIndex;
        _contact params ["", "_contactType", "_localRight", "_localForward", "", "", "_contactState", ["_contactCategory", "man"]];

        private _normalizedRight = (_localRight / _trackerRange) max -1 min 1;
        private _normalizedForward = (_localForward / _trackerRange) max -1 min 1;
        private _blipSize = (_trackerW min _trackerH) * 0.032;
        private _blipAlpha = 0.95 * _hudRevealAlpha;
        private _blipColor = +_hudTextColor;

        if (_contactCategory isEqualTo "vehicle") then {
            _blipSize = _blipSize * 1.45;
        };

        switch (_contactType) do {
            case "enemy": {
                _blipSize = _blipSize * 1.1;
                _blipColor = [_enemyColor select 0, _enemyColor select 1, _enemyColor select 2, _blipAlpha];
            };
            case "friendly": {
                _blipSize = _blipSize * 0.9;
                _blipColor = [_friendlyColor select 0, _friendlyColor select 1, _friendlyColor select 2, _blipAlpha];
            };
            default {
                _blipColor = [_color select 0, _color select 1, _color select 2, 0.8 * _hudRevealAlpha];
            };
        };

        if (_contactState isEqualTo "lost") then {
            _blipSize = _blipSize * 0.8;
            _blipColor set [3, (_blipColor param [3, 1]) * 0.35];
        };

        private _vectorLength = sqrt ((_normalizedRight * _normalizedRight) + (_normalizedForward * _normalizedForward));
        if (_vectorLength > 1) then {
            _normalizedRight = _normalizedRight / _vectorLength;
            _normalizedForward = _normalizedForward / _vectorLength;
        };

        private _blipPos = [
            _trackerCenterX + (_normalizedRight * _trackerRadius) - (_blipSize / 2),
            _trackerCenterY - (_normalizedForward * _trackerRadius) - (_blipSize / 2),
            _blipSize,
            _blipSize
        ];

        _x ctrlSetPosition _blipPos;
        _x ctrlSetBackgroundColor _blipColor;
        _x ctrlCommit 0;
        _x ctrlShow true;
    } forEach _trackerBlipCtrls;
};
if (!_showTrackerPane) then
{
    _trackerTitleCtrl ctrlSetText "";
    _trackerStatusCtrl ctrlSetText "";
    _trackerSweepCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
};

private _defaultEnemyMaxDist = ((missionNamespace getVariable ["CTHUD_enemyMaxDistance", 150]) max 0) min 150;
private _pilotEnemyMaxDist = ((missionNamespace getVariable ["CTHUD_pilotEnemyMaxDistance", 1000]) max 0) min 1000;
private _enemyMaxDist = [_defaultEnemyMaxDist, _pilotEnemyMaxDist] select _isPilotHud;
private _friendlyMaxDist = ((missionNamespace getVariable ["CTHUD_friendlyMaxDistance", 1000]) max 0) min 1000;
private _markersReady = _startupProgress >= 0.72; // IFF markers appear at 72% of startup sequence
private _enemyMarkerMinAlpha = [0.35, 0.18] select _isPilotHud; // pilot markers fade more at distance
private _enemyMarkerSize = [0.75, 0.58] select _isPilotHud;
private _enemyMarkerTextSize = ([0.028, 0.022] select _isPilotHud) * _textScale;
private _enemyMarkerIconTextSize = ([0.035, 0.028] select _isPilotHud) * _textScale;
private _enemyMarkerIcon = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\IFF_Enemy_Diamond.paa";
private _enemyVehicleAirIcon = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\IFF_Vehicle_enemy_Aircraft _Icon.paa";
private _enemyVehicleCarIcon = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\IFF_Vehicle_enemy_Car _Icon.paa";
private _enemyVehicleArmorIcon = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\ui\IFF_Vehicle_Tank_Icon.paa";
private _getVehicleMarkerIcon = {
    params ["_vehicle"];
    if (_vehicle isKindOf "Air") exitWith {_enemyVehicleAirIcon};
    if (_vehicle isKindOf "Tank" || {_vehicle isKindOf "Wheeled_APC_F"} || {_vehicle isKindOf "Tracked_APC_F"}) exitWith {_enemyVehicleArmorIcon};
    _enemyVehicleCarIcon
};

private _bracketsEnabled = missionNamespace getVariable ["CTHUD_iffBrackets", true];
private _camPos = positionCameraToWorld [0, 0, 0];
private _camForwardPos = positionCameraToWorld [0, 0, 1];
private _camForward = vectorNormalized (_camForwardPos vectorDiff _camPos);
private _camRight = vectorNormalized (_camForward vectorCrossProduct [0, 0, -1]);
private _bracketPulse = 0.75 + 0.25 * (sin (diag_tickTime * 240));

// Shared helper: draw an IFF icon + distance label above a world position
private _drawIFFMarker = {
    params ["_pos", "_drawColor", "_icon", "_iconSize", "_distText", "_iconTextSize", "_distTextSize"];
    drawIcon3D [_icon, _drawColor, _pos, _iconSize, _iconSize, 0, "", 1, _iconTextSize, "RobotoCondensed"];
    if (_distText isNotEqualTo "") then {
        drawIcon3D ["", _drawColor, [_pos select 0, _pos select 1, (_pos select 2) + 0.2], 0, 0, 0, _distText, 1, _distTextSize, "RobotoCondensed"];
    };

    if (_bracketsEnabled) then {
        private _bracketOffset = (_iconSize * 0.9) max 0.45;
        private _leftPos = _pos vectorAdd (_camRight vectorMultiply -_bracketOffset);
        private _rightPos = _pos vectorAdd (_camRight vectorMultiply _bracketOffset);
        private _bracketColor = [_drawColor select 0, _drawColor select 1, _drawColor select 2, (_drawColor param [3, 1]) * _bracketPulse];
        private _bracketSize = _iconTextSize * 1.35;
        drawIcon3D ["", _bracketColor, _leftPos, 0, 0, 0, "[", 1, _bracketSize, "RobotoCondensed"];
        drawIcon3D ["", _bracketColor, _rightPos, 0, 0, 0, "]", 1, _bracketSize, "RobotoCondensed"];
    };
};

if (_drawWorldMarkers) then
{
    {
        private _unit = _x;
        private _iff = [_unit] call CTHUD_fnc_getIFF;

        if (_markersReady && _enemyMaxDist > 0 && {_iff isEqualTo "enemy"}) then
        {
            private _dist = player distance _unit;
            if (_dist <= _enemyMaxDist && {[_unit] call CTHUD_fnc_hasDirectLineOfSight}) then
            {
                private _pos = ASLToAGL eyePos _unit;
                _pos set [2, (_pos select 2) + 0.55]; // offset above head for enemy diamond
                private _alpha = (1 - (_dist / _enemyMaxDist)) max _enemyMarkerMinAlpha;
                private _drawColor = [_enemyColor select 0, _enemyColor select 1, _enemyColor select 2, _alpha];
                [_pos, _drawColor, _enemyMarkerIcon, _enemyMarkerSize, (str (round _dist)) + "m", _enemyMarkerIconTextSize, _enemyMarkerTextSize] call _drawIFFMarker;
            };
        };

        if (_markersReady && _friendlyMaxDist > 0 && {_iff isEqualTo "friendly"}) then
        {
            private _dist = player distance _unit;
            if (_dist <= _friendlyMaxDist && {[_unit] call CTHUD_fnc_hasDirectLineOfSight}) then
            {
                private _pos = ASLToAGL eyePos _unit;
                _pos set [2, (_pos select 2) + 0.35]; // offset above head for friendly triangle (lower than enemy)
                private _alpha = (1 - (_dist / _friendlyMaxDist)) max 0.2;
                private _drawColor = [_friendlyColor select 0, _friendlyColor select 1, _friendlyColor select 2, _alpha];
                [_pos, _drawColor, "\A3\ui_f\data\map\markers\military\warning_CA.paa", 0.5, "", 0.025, 0.025] call _drawIFFMarker;
            };
        };
    } forEach allUnits;

    // Pilot HUD: draw enemy vehicle markers with type-specific icons
    if (_markersReady && {_isPilotHud} && {_enemyMaxDist > 0}) then
    {
        {
            if (!alive _x) then {continue};
            if (_x isEqualTo _sensorObject) then {continue};

            private _iff = [_x] call CTHUD_fnc_getIFF;
            if (_iff isNotEqualTo "enemy") then {continue};

            private _dist = player distance _x;
            if (_dist > _enemyMaxDist) then {continue};

            private _hasLos = lineIntersectsSurfaces [eyePos player, visiblePositionASL _x, player, _x, true, 1, "GEOM", "NONE"] isEqualTo [];
            if (!_hasLos) then {continue};

            private _alpha = (1 - (_dist / _enemyMaxDist)) max _enemyMarkerMinAlpha;
            private _drawColor = [_enemyColor select 0, _enemyColor select 1, _enemyColor select 2, _alpha];
            private _icon = [_x] call _getVehicleMarkerIcon;
            private _markerHeight = (((sizeOf typeOf _x) * 0.08) max 1.2) min 4; // scale marker height by vehicle bounding box
            private _vehiclePos = ASLToAGL (visiblePositionASL _x);
            _vehiclePos set [2, (_vehiclePos select 2) + _markerHeight];
            [_vehiclePos, _drawColor, _icon, _enemyMarkerSize * 0.92, (str (round _dist)) + "m", _enemyMarkerIconTextSize, _enemyMarkerTextSize] call _drawIFFMarker;
        } forEach (vehicles select {!(_x isKindOf "Man")});
    };
};

if (_isPilotHud && {_hudRevealAlpha > 0.01}) then
{
    private _pilotPanelAlpha = _hudRevealAlpha;
    private _pilotPanelBgColor = [0.05, 0.08, 0.11, 0.26 * _pilotPanelAlpha];
    private _pilotBannerBgColor = [0.03, 0.06, 0.08, 0.28 * _pilotPanelAlpha];
    private _pilotTextColor = [_color select 0, _color select 1, _color select 2, 0.95 * _pilotPanelAlpha];
    private _vehicle = vehicle player;
    private _inVehicle = _vehicle isNotEqualTo player;
    private _displayVehicle = if (!_inVehicle) then {"STANDBY"} else {getText (configOf _vehicle >> "displayName")};
    private _speed = round (speed _vehicle);
    private _asl = round ((getPosASL _vehicle) select 2);
    private _agl = round ((getPosATL _vehicle) select 2);
    private _rangeLabel = if (_enemyMaxDist >= 1000) then {"1.0KM"} else {format ["%1M", round _enemyMaxDist]};

    private _airspeed = 0;
    private _vertSpeed = 0;
    if (_inVehicle) then {
        private _velMS = velocityModelSpace _vehicle;
        _airspeed = round ((_velMS select 1) * 3.6);
        _vertSpeed = round ((velocity _vehicle) select 2);
    };
    private _vertSign = if (_vertSpeed >= 0) then {"+"} else {""};

    private _armamentLine = "NO ARMAMENT";
    private _ammoLine = "";
    if (_inVehicle) then {
        private _vehWeapons = weapons _vehicle select {_x isNotEqualTo "FakeWeapon" && {_x isNotEqualTo ""}};
        private _currentWep = currentWeapon _vehicle;
        if (_currentWep isEqualTo "" && {count _vehWeapons > 0}) then {_currentWep = _vehWeapons select 0};
        if (_currentWep isNotEqualTo "") then {
            private _wepCfg = configFile >> "CfgWeapons" >> _currentWep;
            private _wepName = getText (_wepCfg >> "displayName");
            if (_wepName isEqualTo "") then {_wepName = _currentWep};
            if ((count _wepName) > 22) then {_wepName = (_wepName select [0, 19]) + "..."};
            _armamentLine = toUpper _wepName;
            private _ammo = _vehicle ammo _currentWep;
            private _totalCount = count _vehWeapons;
            _ammoLine = format ["AMMO %1 // ARM %2", _ammo, _totalCount];
        };
    };

    private _speedBarWidth = 10;
    private _speedBarMax = 600;
    private _speedBarFilled = (round ((_speed / _speedBarMax) * _speedBarWidth)) max 0 min _speedBarWidth;
    private _speedBar = "";
    for "_i" from 1 to _speedBarWidth do {
        _speedBar = _speedBar + ([".", "|"] select (_i <= _speedBarFilled));
    };

    private _pilotLeftText = parseText format [
        "<t color='%1' shadow='0' size='0.9'>ARM %2<br/>%3<br/>SPD %4 km/h<br/>AS %5 km/h<br/>VS %6%7 m/s<br/>[%8]</t>",
        _colorHex,
        _armamentLine,
        _ammoLine,
        _speed,
        _airspeed,
        _vertSign,
        _vertSpeed,
        _speedBar
    ];
    private _pilotRightText = parseText format [
        "<t color='%1' shadow='0' size='0.9'>HDG %2<br/>ASL %3 m<br/>AGL %4 m</t>",
        _colorHex,
        _bearingText,
        _asl,
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
    _pilotBannerCtrl ctrlSetText "";
    _pilotTelemetryLeftCtrl ctrlSetStructuredText parseText "";
    _pilotTelemetryRightCtrl ctrlSetStructuredText parseText "";
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
    _startupMainCtrl ctrlSetText "";
    _startupStatusCtrl ctrlSetText "";

    private _startupBarPos = ctrlPosition _startupBarBgCtrl;
    private _startupFillPos = +_startupBarPos;
    _startupFillPos set [2, 0];
    _startupBarFillCtrl ctrlSetPosition _startupFillPos;
    _startupBarFillCtrl ctrlCommit 0;
};
