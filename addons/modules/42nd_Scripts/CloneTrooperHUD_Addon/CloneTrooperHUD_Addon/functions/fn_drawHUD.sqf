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

private _color = call CTHUD_fnc_getHudColor;
private _hudColorNoAlpha = [_color select 0, _color select 1, _color select 2, 1];
private _enemyColor = missionNamespace getVariable ["CTHUD_enemyColor", [1, 0.2, 0.2, 1]];
private _friendlyColor = missionNamespace getVariable ["CTHUD_friendlyColor", [0.15, 1, 0.35, 1]];

_weaponCtrl ctrlSetTextColor _color;
_magCtrl ctrlSetTextColor _color;
_modeCtrl ctrlSetTextColor _color;
_compassCtrl ctrlSetTextColor _color;
_bearingCtrl ctrlSetTextColor _color;
_mapFrameCtrl ctrlSetTextColor _color;
_weaponBgCtrl ctrlSetBackgroundColor [0.18, 0.18, 0.18, 0.45];
_compassBgCtrl ctrlSetBackgroundColor [0.12, 0.12, 0.12, 0.35];
_squadListBgCtrl ctrlSetBackgroundColor [0.12, 0.12, 0.12, 0.35];

private _weaponData = call CTHUD_fnc_getWeaponDisplay;
_weaponCtrl ctrlSetText ("WEAPON: " + (_weaponData select 0));
_modeCtrl ctrlSetText ("MODE: " + (_weaponData select 1));

private _ammoData = call CTHUD_fnc_getAmmoData;
_magCtrl ctrlSetText (("MAG: " + str (_ammoData select 0)) + (" | RES: " + str (_ammoData select 1)));

private _weaponClass = currentWeapon player;
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
if (_groupMembers isEqualTo []) then
{
    _squadListBgCtrl ctrlShow false;
    _squadListCtrl ctrlShow false;
}
else
{
    private _displayedGroupMembers = +_groupMembers;
    private _overflowCount = 0;
    if ((count _displayedGroupMembers) > 7) then
    {
        _overflowCount = (count _displayedGroupMembers) - 6;
        _displayedGroupMembers resize 6;
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

private _showMap = missionNamespace getVariable ["CTHUD_showMiniMap", true];
_mapCtrl ctrlShow _showMap;
_mapFrameCtrl ctrlShow _showMap;
_mapBgCtrl ctrlShow _showMap;
_mapMaskCtrl ctrlShow _showMap;
if (_showMap) then
{
    _mapCtrl ctrlMapAnimAdd [0, 0.04, getPosVisual player];
    ctrlMapAnimCommit _mapCtrl;
};

private _enemyMaxDist = ((missionNamespace getVariable ["CTHUD_enemyMaxDistance", 100]) max 0) min 100;
private _friendlyMaxDist = ((missionNamespace getVariable ["CTHUD_friendlyMaxDistance", 1000]) max 0) min 1000;

{
    private _unit = _x;

    if (_enemyMaxDist > 0 && {[_unit] call CTHUD_fnc_isEnemy}) then
    {
        private _dist = player distance _unit;
        if (_dist <= _enemyMaxDist) then
        {
            private _pos = ASLToAGL eyePos _unit;
            _pos set [2, (_pos select 2) + 0.55];

            private _alpha = 1 - (_dist / _enemyMaxDist);
            if (_alpha < 0.25) then {_alpha = 0.25;};

            private _drawColor = [_enemyColor select 0, _enemyColor select 1, _enemyColor select 2, _alpha];

            drawIcon3D [
                "\A3\ui_f\data\igui\cfg\Cursors\select_ca.paa",
                _drawColor,
                _pos,
                0.75,
                0.75,
                45,
                "",
                1,
                0.035,
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
                0.028,
                "RobotoCondensed"
            ];
        };
    };

    if (_friendlyMaxDist > 0 && {[_unit] call CTHUD_fnc_isFriendly}) then
    {
        private _dist = player distance _unit;
        if (_dist <= _friendlyMaxDist) then
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
