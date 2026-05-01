class CfgPatches
{
    class Para42_MainMenu
    {
        requiredVersion = 2.10;
        requiredAddons[] = {"A3_UI_F"};
        units[] = {};
        weapons[] = {};
        author = "HoundaCivic";
    };
};

class CfgFunctions
{
    class Para42
    {
        class MainMenu
        {
            file = "\42nd_para\42nd\addons\main_menu\functions";
            class connectServer {};
        };
    };
};

class RscPicture;
class RscButton;

class RscDisplayMain
{
    class controlsBackground
    {
        class Para42_MainMenu_Background: RscPicture
        {
            idc = 42420;
            text = "\42nd_para\42nd\addons\main_menu\images\Background_1.paa";
            x = "safezoneX";
            y = "safezoneY";
            w = "safezoneW";
            h = "safezoneH";
            onLoad = "(_this select 0) ctrlSetText (selectRandom ['\42nd_para\42nd\addons\main_menu\images\Background_1.paa','\42nd_para\42nd\addons\main_menu\images\Background_2.paa','\42nd_para\42nd\addons\main_menu\images\Background_3.paa']);";
        };
    };

    class controls
    {
        class Para42_MainMenu_Logo: RscPicture
        {
            idc = 42421;
            text = "\42nd_para\42nd\addons\main_menu\images\42nd_Airborne_Logo.paa";
            x = "safezoneX + safezoneW * 0.015";
            y = "safezoneY + safezoneH * 0.02";
            w = "0.12 * safezoneH";
            h = "0.12 * safezoneH";
        };

        class Para42_MainMenu_JoinButton: RscButton
        {
            idc = 42422;
            text = "JOIN 42ND SERVER";
            tooltip = "Connect to 51.222.108.22:2302";
            x = "safezoneX + safezoneW * 0.015";
            y = "safezoneY + safezoneH * 0.02 + 0.12 * safezoneH + 0.01 * safezoneH";
            w = "0.12 * safezoneH";
            h = "0.04 * safezoneH";
            sizeEx = "0.025 * safezoneH";
            colorText[] = {1, 1, 1, 1};
            colorBackground[] = {0.35, 0.1, 0.5, 0.9};
            colorBackgroundActive[] = {0.5, 0.15, 0.7, 1};
            colorFocused[] = {0.5, 0.15, 0.7, 1};
            colorShadow[] = {0, 0, 0, 0.5};
            colorBorder[] = {0, 0, 0, 1};
            borderSize = 0.003;
            soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1};
            soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1};
            soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
            soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
            action = "connectToServer ['51.222.108.22', 2302, '42nd'];";

        };
    };
};
