class CfgPatches
{
    class Aux_42nd_Modules
    {
        name = "42nd Modules";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] = {"Aux_42nd", "cba_main", "cba_settings", "cba_keybinding", "cba_xeh", "A3_UI_F", "A3_Data_F", "A3_Modules_F", "ls_props_staticships"};
        units[] = {"Para42_Module_CapitalShipJumpIn"};
        weapons[] = {};
    };
};

class CfgFunctions
{
    class Para42
    {
        class Modules
        {
            file = "\42nd_para\42nd\addons\modules\42nd_Scripts";
            class getCapitalShipJumpSettings {};
            class moduleCapitalShipJumpIn {};
            class playCapitalShipJumpInLocal {};
            class spawnCapitalShipJumpInServer {};
        };
    };

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

class CfgFactionClasses
{
    class NO_CATEGORY;
    class Para42_Modules: NO_CATEGORY
    {
        displayName = "[42nd] Modules";
    };
};

class Logic;
class Module_F: Logic
{
    class ModuleDescription;
};

class CfgVehicles
{
    class Para42_Module_CapitalShipJumpIn: Module_F
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] Capital Ship Jump-In";
        category = "Para42_Modules";
        model = "\a3\Modules_F_Curator\Ordnance\surfaceMortar.p3d";
        icon = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        simulation = "house";
        function = "Para42_fnc_moduleCapitalShipJumpIn";
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 1;
        curatorCanAttach = 0;
        canSetArea = 0;
        canSetAreaShape = 0;
        canSetAreaHeight = 0;

        class Arguments
        {
            class ShipClass
            {
                displayName = "Capital Ship";
                description = "Ship variant to spawn at this module position.";
                typeName = "STRING";

                class values
                {
                    class RepublicVenatorZeus
                    {
                        name = "[Republic] Venator (Zeus)";
                        value = "ls_staticShip_venator_zeus";
                        default = 1;
                    };
                    class RepublicVenatorClosed
                    {
                        name = "[Republic] Venator";
                        value = "ls_staticShip_venator";
                    };
                    class RepublicVenatorClosedHollow
                    {
                        name = "[Republic] Venator Hollow";
                        value = "ls_staticShip_venator_hollow";
                    };
                    class RepublicVenatorFullHollow
                    {
                        name = "[Republic] Venator Full Hollow";
                        value = "ls_staticShip_venator_fullHollow";
                    };
                    class RepublicVenatorOpen
                    {
                        name = "[Republic] Venator Open";
                        value = "ls_staticShip_venator_open";
                    };
                    class RepublicVenatorOpenHollow
                    {
                        name = "[Republic] Venator Open Hollow";
                        value = "ls_staticShip_venator_open_hollow";
                    };
                    class RepublicVenatorOpenFullHollow
                    {
                        name = "[Republic] Venator Open Full Hollow";
                        value = "ls_staticShip_venator_open_fullHollow";
                    };
                    class RepublicAcclamator
                    {
                        name = "[Republic] Acclamator";
                        value = "ls_staticShip_acclamator";
                    };
                    class RepublicAcclamatorHollow
                    {
                        name = "[Republic] Acclamator Hollow";
                        value = "ls_staticShip_acclamator_hollow";
                    };
                    class RepublicC9LightCruiser
                    {
                        name = "[Republic] C-9 Light Cruiser";
                        value = "ls_staticShip_c9LightCruiser_republic";
                    };
                    class RepublicFg40SupportFrigate
                    {
                        name = "[Republic] FG-40 Support Frigate";
                        value = "ls_staticShip_fg40SupportFrigate";
                    };
                    class RepublicQuasar
                    {
                        name = "[Republic] Quasar";
                        value = "ls_staticShip_quasar";
                    };
                    class RepublicMandator
                    {
                        name = "[Republic] Mandator";
                        value = "ls_staticShip_mandator";
                    };
                    class CisProvidenceZeus
                    {
                        name = "[CIS] Providence (Zeus)";
                        value = "ls_staticShip_providence_zeus";
                    };
                    class CisProvidence
                    {
                        name = "[CIS] Providence";
                        value = "ls_staticShip_providence";
                    };
                    class CisProvidenceHollow
                    {
                        name = "[CIS] Providence Hollow";
                        value = "ls_staticShip_providence_hollow";
                    };
                    class CisProvidenceDreadnoughtZeus
                    {
                        name = "[CIS] Providence Dreadnought (Zeus)";
                        value = "ls_staticShip_providence_dreadnought_zeus";
                    };
                    class CisProvidenceDreadnought
                    {
                        name = "[CIS] Providence Dreadnought";
                        value = "ls_staticShip_providence_dreadnought";
                    };
                    class CisProvidenceDreadnoughtHollow
                    {
                        name = "[CIS] Providence Dreadnought Hollow";
                        value = "ls_staticShip_providence_dreadnought_hollow";
                    };
                    class CisRecusantZeus
                    {
                        name = "[CIS] Recusant (Zeus)";
                        value = "ls_staticShip_recusant_zeus";
                    };
                    class CisRecusant
                    {
                        name = "[CIS] Recusant";
                        value = "ls_staticShip_recusant";
                    };
                    class CisRecusantDreadnoughtZeus
                    {
                        name = "[CIS] Recusant Dreadnought (Zeus)";
                        value = "ls_staticShip_recusant_zeus_dreadnought";
                    };
                    class CisRecusantDreadnought
                    {
                        name = "[CIS] Recusant Dreadnought";
                        value = "ls_staticShip_recusant_dreadnought";
                    };
                    class CisMunificent
                    {
                        name = "[CIS] Munificent";
                        value = "ls_staticShip_munificent";
                    };
                    class CisLucrehulk
                    {
                        name = "[CIS] Lucrehulk";
                        value = "ls_staticShip_lucrehulk";
                    };
                    class CisHardcell
                    {
                        name = "[CIS] Hardcell";
                        value = "ls_staticShip_hardcell";
                    };
                    class CisCoreShip
                    {
                        name = "[CIS] Core Ship";
                        value = "ls_staticShip_coreShip";
                    };
                    class CisDiamondCruiser
                    {
                        name = "[CIS] Diamond-Class Cruiser";
                        value = "ls_staticShip_diamondClassCruiser_cis";
                    };
                    class CisDby827
                    {
                        name = "[CIS] DBY-827";
                        value = "ls_staticShip_dby827";
                    };
                    class CisSubjugator
                    {
                        name = "[CIS] Subjugator";
                        value = "ls_staticShip_subjugator";
                    };
                    class CisStealthShip
                    {
                        name = "[CIS] SDS Stealth Ship";
                        value = "ls_staticShip_sdsStealthShip";
                    };
                };
            };

            class SpawnHeight
            {
                displayName = "Spawn Height";
                description = "Meters above the module position where the ship will settle after the jump-in.";
                typeName = "NUMBER";
                defaultValue = 2000;
            };

            class Heading
            {
                displayName = "Heading";
                description = "Facing in degrees. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };

            class CruiseSpeed
            {
                displayName = "Cruise Speed";
                description = "Forward movement speed in meters per second after the jump-in. Set to 0 to hold position.";
                typeName = "NUMBER";
                defaultValue = 40;
            };

            class MoveForever
            {
                displayName = "Move Forever";
                description = "If enabled, the ship keeps cruising along its facing direction indefinitely.";
                typeName = "NUMBER";
                class values
                {
                    class Disabled
                    {
                        name = "Disabled";
                        value = 0;
                        default = 1;
                    };
                    class Enabled
                    {
                        name = "Enabled";
                        value = 1;
                    };
                };
            };
        };

        class ModuleDescription: ModuleDescription
        {
            position = 1;
            direction = 1;
            description = "Spawns a Republic or CIS Legion Studios capital ship at the chosen altitude, plays a local jump-in approach into the module position, then leaves a persistent ship holding or cruising in the chosen direction.";
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
            class InteriorVisor: RscPicture
            {
                idc = 9001;
                x = "safezoneX";
                y = "safezoneY";
                w = "safezoneW";
                h = "safezoneH";
                text = "";
                colorText[] = {1, 1, 1, 1};
            };

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

