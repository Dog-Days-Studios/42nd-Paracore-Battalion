class CfgPatches
{
    class Aux_42nd_Modules
    {
        name = "42nd Modules";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] = {"Aux_42nd", "cba_main", "cba_settings", "cba_keybinding", "cba_xeh", "A3_UI_F", "A3_Data_F"};
        units[] = {};
        weapons[] = {};
    };
};

class CfgFunctions
{
    class CTHUD
    {
        class Main
        {
            file = "\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\functions";
            class preInit {};
            class postInit {};
            class initPlayerHUD {};
            class drawHUD {};
            class getHudColor {};
            class setColorPreset {};
            class isEnemy {};
            class isFriendly {};
            class getWeaponDisplay {};
            class getAmmoData {};
            class canShowHUD {};
            class hasHudHelmet {};
            class joinGroupLocal {};
            class requestJoinGroup {};
            class syncHudState {};
            class registerAceActions {};
            class toggleHUD {};
        };
    };
};

class Extended_PreInit_EventHandlers
{
    class CTHUD_PreInit
    {
        init = "call compile preprocessFileLineNumbers '\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\functions\fn_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers
{
    class CTHUD_PostInit
    {
        init = "call compile preprocessFileLineNumbers '\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\functions\fn_postInit.sqf'";
    };
    class Para42_VenatorSpawner_PostInit
    {
        init = "[] execVM '\42nd_para\42nd\addons\modules\42nd_Scripts\venator_spawner.sqf'";
    };
};

class Extended_InitPost_EventHandlers
{
    class 42nd_Gozanti_Republic
    {
        class para42_gozantiSpawner
        {
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\modules\42nd_Scripts\gozanti_spawner.sqf'";
        };
    };
    class 42nd_LAAT
    {
        class para42_laatColumnDrop
        {
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\modules\42nd_Scripts\laat_column_drop.sqf'";
        };
    };
};

class CfgSettings
{
    class CTHUD
    {
        displayName = "Clone Trooper HUD";
    };
};

class RscText;
class RscMapControl;
class RscPicture;
class RscStructuredText;

class RscTitles
{
    class CTHUD_Main
    {
        idd = 9000;
        movingEnable = 0;
        duration = 1e+10;
        fadeIn = 0;
        fadeOut = 0;
        onLoad = "uiNamespace setVariable ['CTHUD_Display', _this select 0]";
        onUnload = "uiNamespace setVariable ['CTHUD_Display', displayNull]";

        class controls
        {
            class WeaponInfoBg: RscText
            {
                idc = 1000;
                x = "0.72 * safezoneW + safezoneX";
                y = "0.865 * safezoneH + safezoneY";
                w = "0.26 * safezoneW";
                h = "0.12 * safezoneH";
                colorBackground[] = {0.18, 0.18, 0.18, 0.45};
            };

            class WeaponPreview: RscPicture
            {
                idc = 1004;
                x = "0.726 * safezoneW + safezoneX";
                y = "0.885 * safezoneH + safezoneY";
                w = "0.055 * safezoneW";
                h = "0.075 * safezoneH";
                text = "";
            };

            class WeaponText: RscText
            {
                idc = 1001;
                x = "0.79 * safezoneW + safezoneX";
                y = "0.885 * safezoneH + safezoneY";
                w = "0.175 * safezoneW";
                h = "0.03 * safezoneH";
                sizeEx = 0.028;
                text = "WEAPON";
                colorBackground[] = {0, 0, 0, 0};
            };

            class MagText: RscText
            {
                idc = 1002;
                x = "0.79 * safezoneW + safezoneX";
                y = "0.915 * safezoneH + safezoneY";
                w = "0.175 * safezoneW";
                h = "0.03 * safezoneH";
                sizeEx = 0.028;
                text = "MAG: 0 | RES: 0";
                colorBackground[] = {0, 0, 0, 0};
            };

            class FireModeText: RscText
            {
                idc = 1003;
                x = "0.79 * safezoneW + safezoneX";
                y = "0.945 * safezoneH + safezoneY";
                w = "0.175 * safezoneW";
                h = "0.025 * safezoneH";
                sizeEx = 0.024;
                text = "MODE: SAFE";
                colorBackground[] = {0, 0, 0, 0};
            };

            class CompassBg: RscText
            {
                idc = 1302;
                x = "0.37 * safezoneW + safezoneX";
                y = "0.014 * safezoneH + safezoneY";
                w = "0.26 * safezoneW";
                h = "0.06 * safezoneH";
                colorBackground[] = {0.12, 0.12, 0.12, 0.35};
            };

            class CompassText: RscText
            {
                idc = 1300;
                x = "0.38 * safezoneW + safezoneX";
                y = "0.016 * safezoneH + safezoneY";
                w = "0.24 * safezoneW";
                h = "0.026 * safezoneH";
                style = 2;
                sizeEx = 0.04;
                text = "COMPASS";
                colorBackground[] = {0, 0, 0, 0};
            };

            class BearingText: RscText
            {
                idc = 1301;
                x = "0.38 * safezoneW + safezoneX";
                y = "0.043 * safezoneH + safezoneY";
                w = "0.24 * safezoneW";
                h = "0.022 * safezoneH";
                style = 2;
                sizeEx = 0.034;
                text = "000";
                colorBackground[] = {0, 0, 0, 0};
            };

            class SquadListBg: RscText
            {
                idc = 1400;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.648 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.102 * safezoneH";
                colorBackground[] = {0.08, 0.08, 0.08, 0.35};
            };

            class SquadListText: RscStructuredText
            {
                idc = 1401;
                x = "0.046 * safezoneW + safezoneX";
                y = "0.655 * safezoneH + safezoneY";
                w = "0.148 * safezoneW";
                h = "0.09 * safezoneH";
                size = 0.028;
                text = "";
            };

            class MiniMapBg: RscText
            {
                idc = 1202;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.768 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.164 * safezoneH";
                colorBackground[] = {0.08, 0.08, 0.08, 0.35};
            };

            class MiniMap: RscMapControl
            {
                idc = 1200;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.768 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.164 * safezoneH";
                showCountourInterval = 0;
                scaleDefault = 0.08;
                alphaFadeStartScale = 10;
                alphaFadeEndScale = 10;
            };

            class MiniMapMask: RscPicture
            {
                idc = 1203;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.768 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.164 * safezoneH";
                text = "\A3\weapons_f\acc\Data\scope_inside_sharp_ca.paa";
            };

            class MiniMapFrame: RscPicture
            {
                idc = 1201;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.768 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.164 * safezoneH";
                text = "\a3\weapons_f\acc\data\collimdot_circle_red_ca.paa";
            };
        };
    };
};
