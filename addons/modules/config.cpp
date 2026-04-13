class CfgPatches
{
    class Aux_42nd_Modules
    {
        name = "42nd Modules";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] = {"Aux_42nd", "cba_main", "cba_settings", "cba_keybinding", "cba_xeh", "A3_UI_F", "A3_Data_F", "A3_Modules_F", "A3_Modules_F_Curator", "A3_UI_F_Curator", "ls_props_staticships"};
        units[] = {"Para42_Module_CapitalShipJumpIn", "Para42_Module_GozantiResupply", "Para42_Module_LaatResupply"};
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
            class getCapitalShipJumpSettings
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\fn_getCapitalShipJumpSettings.sqf";
            };
            class moduleCapitalShipJumpIn
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\fn_moduleCapitalShipJumpIn.sqf";
            };
            class moduleGozantiResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_moduleGozantiResupply.sqf";
            };
            class moduleLaatResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_moduleLaatResupply.sqf";
            };
            class postInitGozantiResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_postInitGozantiResupply.sqf";
                postInit = 1;
            };
            class postInitLaatResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_postInitLaatResupply.sqf";
                postInit = 1;
            };
            class playCapitalShipJumpInLocal {};
            class registerGozantiResupplyActions
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_registerGozantiResupplyActions.sqf";
            };
            class registerLaatResupplyActions
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_registerLaatResupplyActions.sqf";
            };
            class requestGozantiAiResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_requestGozantiAiResupply.sqf";
            };
            class requestLaatAiResupply
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_requestLaatAiResupply.sqf";
            };
            class hasResupplyAccess
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_hasResupplyAccess.sqf";
            };
            class beginGuidedAirdrop
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_beginGuidedAirdrop.sqf";
            };
            class spawnGozantiResupplyServer
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_spawnGozantiResupplyServer.sqf";
            };
            class spawnLaatResupplyServer
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\fn_spawnLaatResupplyServer.sqf";
            };
            class spawnCapitalShipJumpInServer
            {
                file = "\42nd_para\42nd\addons\modules\42nd_Scripts\fn_spawnCapitalShipJumpInServer.sqf";
            };
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
            class updateTrackerContacts {};
            class getHudColor {};
            class normalizeColorPreset {};
            class normalizeTextScalePreset {};
            class getHudLayout {};
            class setColorPreset {};
            class setTextScalePreset {};
            class getIFF {};
            class hasDirectLineOfSight {};
            class isPilotHudHelmet {};
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
    class AttributesBase
    {
        class Default;
        class Edit;
        class Combo;
        class Checkbox;
        class CheckboxNumber;
        class ModuleDescription;
        class Units;
    };
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
        is3DEN = 1;
        curatorCanAttach = 0;
        curatorInfoType = "RscDisplayAttributeModuleNuke";
        canSetArea = 0;
        canSetAreaShape = 0;
        canSetAreaHeight = 0;

        class Attributes: AttributesBase
        {
            class ShipClass: Combo
            {
                property = "Para42_Module_CapitalShipJumpIn_ShipClass";
                displayName = "Capital Ship";
                tooltip = "Ship variant to spawn at this module position.";
                typeName = "STRING";
                defaultValue = """ls_staticShip_venator_zeus""";

                class Values
                {
                    class RepublicVenatorZeus
                    {
                        name = "[Republic] Venator (Zeus)";
                        value = """ls_staticShip_venator_zeus""";
                        default = 1;
                    };
                    class RepublicVenatorClosed
                    {
                        name = "[Republic] Venator";
                        value = """ls_staticShip_venator""";
                    };
                    class RepublicVenatorClosedHollow
                    {
                        name = "[Republic] Venator Hollow";
                        value = """ls_staticShip_venator_hollow""";
                    };
                    class RepublicVenatorFullHollow
                    {
                        name = "[Republic] Venator Full Hollow";
                        value = """ls_staticShip_venator_fullHollow""";
                    };
                    class RepublicVenatorOpen
                    {
                        name = "[Republic] Venator Open";
                        value = """ls_staticShip_venator_open""";
                    };
                    class RepublicVenatorOpenHollow
                    {
                        name = "[Republic] Venator Open Hollow";
                        value = """ls_staticShip_venator_open_hollow""";
                    };
                    class RepublicVenatorOpenFullHollow
                    {
                        name = "[Republic] Venator Open Full Hollow";
                        value = """ls_staticShip_venator_open_fullHollow""";
                    };
                    class RepublicAcclamator
                    {
                        name = "[Republic] Acclamator";
                        value = """ls_staticShip_acclamator""";
                    };
                    class RepublicAcclamatorHollow
                    {
                        name = "[Republic] Acclamator Hollow";
                        value = """ls_staticShip_acclamator_hollow""";
                    };
                    class RepublicC9LightCruiser
                    {
                        name = "[Republic] C-9 Light Cruiser";
                        value = """ls_staticShip_c9LightCruiser_republic""";
                    };
                    class RepublicFg40SupportFrigate
                    {
                        name = "[Republic] FG-40 Support Frigate";
                        value = """ls_staticShip_fg40SupportFrigate""";
                    };
                    class RepublicQuasar
                    {
                        name = "[Republic] Quasar";
                        value = """ls_staticShip_quasar""";
                    };
                    class RepublicMandator
                    {
                        name = "[Republic] Mandator";
                        value = """ls_staticShip_mandator""";
                    };
                    class CisProvidenceZeus
                    {
                        name = "[CIS] Providence (Zeus)";
                        value = """ls_staticShip_providence_zeus""";
                    };
                    class CisProvidence
                    {
                        name = "[CIS] Providence";
                        value = """ls_staticShip_providence""";
                    };
                    class CisProvidenceHollow
                    {
                        name = "[CIS] Providence Hollow";
                        value = """ls_staticShip_providence_hollow""";
                    };
                    class CisProvidenceDreadnoughtZeus
                    {
                        name = "[CIS] Providence Dreadnought (Zeus)";
                        value = """ls_staticShip_providence_dreadnought_zeus""";
                    };
                    class CisProvidenceDreadnought
                    {
                        name = "[CIS] Providence Dreadnought";
                        value = """ls_staticShip_providence_dreadnought""";
                    };
                    class CisProvidenceDreadnoughtHollow
                    {
                        name = "[CIS] Providence Dreadnought Hollow";
                        value = """ls_staticShip_providence_dreadnought_hollow""";
                    };
                    class CisRecusantZeus
                    {
                        name = "[CIS] Recusant (Zeus)";
                        value = """ls_staticShip_recusant_zeus""";
                    };
                    class CisRecusant
                    {
                        name = "[CIS] Recusant";
                        value = """ls_staticShip_recusant""";
                    };
                    class CisRecusantDreadnoughtZeus
                    {
                        name = "[CIS] Recusant Dreadnought (Zeus)";
                        value = """ls_staticShip_recusant_zeus_dreadnought""";
                    };
                    class CisRecusantDreadnought
                    {
                        name = "[CIS] Recusant Dreadnought";
                        value = """ls_staticShip_recusant_dreadnought""";
                    };
                    class CisMunificent
                    {
                        name = "[CIS] Munificent";
                        value = """ls_staticShip_munificent""";
                    };
                    class CisLucrehulk
                    {
                        name = "[CIS] Lucrehulk";
                        value = """ls_staticShip_lucrehulk""";
                    };
                    class CisHardcell
                    {
                        name = "[CIS] Hardcell";
                        value = """ls_staticShip_hardcell""";
                    };
                    class CisCoreShip
                    {
                        name = "[CIS] Core Ship";
                        value = """ls_staticShip_coreShip""";
                    };
                    class CisDiamondCruiser
                    {
                        name = "[CIS] Diamond-Class Cruiser";
                        value = """ls_staticShip_diamondClassCruiser_cis""";
                    };
                    class CisDby827
                    {
                        name = "[CIS] DBY-827";
                        value = """ls_staticShip_dby827""";
                    };
                    class CisSubjugator
                    {
                        name = "[CIS] Subjugator";
                        value = """ls_staticShip_subjugator""";
                    };
                    class CisStealthShip
                    {
                        name = "[CIS] SDS Stealth Ship";
                        value = """ls_staticShip_sdsStealthShip""";
                    };
                };
            };

            class SpawnHeight: Edit
            {
                property = "Para42_Module_CapitalShipJumpIn_SpawnHeight";
                displayName = "Spawn Height";
                tooltip = "Meters above the module position where the ship settles after the jump-in.";
                typeName = "NUMBER";
                defaultValue = "2000";
            };

            class Heading: Edit
            {
                property = "Para42_Module_CapitalShipJumpIn_Heading";
                displayName = "Heading";
                tooltip = "Facing in degrees. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };

            class CruiseSpeed: Edit
            {
                property = "Para42_Module_CapitalShipJumpIn_CruiseSpeed";
                displayName = "Cruise Speed";
                tooltip = "Forward movement speed in meters per second after the jump-in. Use 0 to hold position.";
                typeName = "NUMBER";
                defaultValue = "40";
            };

            class MoveForever: CheckboxNumber
            {
                property = "Para42_Module_CapitalShipJumpIn_MoveForever";
                displayName = "Move Forever";
                tooltip = "If enabled, the ship keeps cruising along its facing direction indefinitely.";
                defaultValue = "0";
            };

            class ModuleDescription: ModuleDescription {};
        };

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

    class Para42_Module_GozantiResupply: Module_F
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] Gozanti Resupply Drop";
        category = "Para42_Modules";
        model = "\a3\Modules_F_Curator\Ordnance\surfaceMortar.p3d";
        icon = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        simulation = "house";
        function = "Para42_fnc_moduleGozantiResupply";
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 1;
        is3DEN = 1;
        curatorCanAttach = 0;
        curatorInfoType = "RscDisplayAttributeModuleNuke";
        canSetArea = 0;
        canSetAreaShape = 0;
        canSetAreaHeight = 0;

        class Attributes: AttributesBase
        {
            class CargoClass: Combo
            {
                property = "Para42_Module_GozantiResupply_CargoClass";
                displayName = "Cargo";
                tooltip = "Cargo variant for the AI Gozanti to airdrop at this module position.";
                typeName = "STRING";
                defaultValue = """42nd_Ammo_Resupply_Crate""";

                class Values
                {
                    class AmmoCrate
                    {
                        name = "Ammo Resupply Crate";
                        value = """42nd_Ammo_Resupply_Crate""";
                        default = 1;
                    };
                    class MedicalCrate
                    {
                        name = "Medical Resupply Crate";
                        value = """42nd_Medical_Resupply_Crate""";
                    };
                    class EngineerCrate
                    {
                        name = "Engineer Resupply Crate";
                        value = """42nd_Engineer_Resupply_Crate""";
                    };
                    class ArsenalCrate
                    {
                        name = "Arsenal Supply Crate";
                        value = """42nd_Arsenal_Supply""";
                    };
                    class Lratv
                    {
                        name = "LRATV";
                        value = """42nd_LSV_Unarmed""";
                    };
                    class LratvZ6
                    {
                        name = "LRATV (Z-6)";
                        value = """42nd_LSV_Armed""";
                    };
                    class LaatGunship
                    {
                        name = "LAAT/I Gunship";
                        value = """42nd_LAAT""";
                    };
                };
            };

            class ApproachHeading: Edit
            {
                property = "Para42_Module_GozantiResupply_ApproachHeading";
                displayName = "Approach Heading";
                tooltip = "Direction in degrees for the drop run. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };

            class ModuleDescription: ModuleDescription {};
        };

        class Arguments
        {
            class CargoClass
            {
                displayName = "Cargo";
                description = "Cargo variant for the AI Gozanti to airdrop at this module position.";
                typeName = "STRING";

                class values
                {
                    class AmmoCrate
                    {
                        name = "Ammo Resupply Crate";
                        value = "42nd_Ammo_Resupply_Crate";
                        default = 1;
                    };
                    class MedicalCrate
                    {
                        name = "Medical Resupply Crate";
                        value = "42nd_Medical_Resupply_Crate";
                    };
                    class EngineerCrate
                    {
                        name = "Engineer Resupply Crate";
                        value = "42nd_Engineer_Resupply_Crate";
                    };
                    class ArsenalCrate
                    {
                        name = "Arsenal Supply Crate";
                        value = "42nd_Arsenal_Supply";
                    };
                    class Lratv
                    {
                        name = "LRATV";
                        value = "42nd_LSV_Unarmed";
                    };
                    class LratvZ6
                    {
                        name = "LRATV (Z-6)";
                        value = "42nd_LSV_Armed";
                    };
                    class LaatGunship
                    {
                        name = "LAAT/I Gunship";
                        value = "42nd_LAAT";
                    };
                };
            };

            class ApproachHeading
            {
                displayName = "Approach Heading";
                description = "Direction in degrees for the drop run. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };
        };

        class ModuleDescription: ModuleDescription
        {
            position = 1;
            direction = 1;
            sync[] = {"AnyPerson", "AnyVehicle"};
            description = "Calls an AI Gozanti to drop the selected supply crate or vehicle at this module position. If synced to a player or occupied vehicle, that unit receives delivery status hints.";
        };
    };

    class Para42_Module_LaatResupply: Module_F
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] LAAT Resupply Drop";
        category = "Para42_Modules";
        model = "\a3\Modules_F_Curator\Ordnance\surfaceMortar.p3d";
        icon = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa";
        simulation = "house";
        function = "Para42_fnc_moduleLaatResupply";
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 1;
        is3DEN = 1;
        curatorCanAttach = 0;
        curatorInfoType = "RscDisplayAttributeModuleNuke";
        canSetArea = 0;
        canSetAreaShape = 0;
        canSetAreaHeight = 0;

        class Attributes: AttributesBase
        {
            class CargoClass: Combo
            {
                property = "Para42_Module_LaatResupply_CargoClass";
                displayName = "Cargo";
                tooltip = "Cargo variant for the AI LAAT to airdrop at this module position.";
                typeName = "STRING";
                defaultValue = """42nd_Ammo_Resupply_Crate""";

                class Values
                {
                    class AmmoCrate
                    {
                        name = "Ammo Resupply Crate";
                        value = """42nd_Ammo_Resupply_Crate""";
                        default = 1;
                    };
                    class MedicalCrate
                    {
                        name = "Medical Resupply Crate";
                        value = """42nd_Medical_Resupply_Crate""";
                    };
                    class EngineerCrate
                    {
                        name = "Engineer Resupply Crate";
                        value = """42nd_Engineer_Resupply_Crate""";
                    };
                    class ArsenalCrate
                    {
                        name = "Arsenal Supply Crate";
                        value = """42nd_Arsenal_Supply""";
                    };
                    class Lratv
                    {
                        name = "LRATV";
                        value = """42nd_LSV_Unarmed""";
                    };
                    class LratvZ6
                    {
                        name = "LRATV (Z-6)";
                        value = """42nd_LSV_Armed""";
                    };
                };
            };

            class ApproachHeading: Edit
            {
                property = "Para42_Module_LaatResupply_ApproachHeading";
                displayName = "Approach Heading";
                tooltip = "Direction in degrees for the drop run. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };

            class ModuleDescription: ModuleDescription {};
        };

        class Arguments
        {
            class CargoClass
            {
                displayName = "Cargo";
                description = "Cargo variant for the AI LAAT to airdrop at this module position.";
                typeName = "STRING";

                class values
                {
                    class AmmoCrate
                    {
                        name = "Ammo Resupply Crate";
                        value = "42nd_Ammo_Resupply_Crate";
                        default = 1;
                    };
                    class MedicalCrate
                    {
                        name = "Medical Resupply Crate";
                        value = "42nd_Medical_Resupply_Crate";
                    };
                    class EngineerCrate
                    {
                        name = "Engineer Resupply Crate";
                        value = "42nd_Engineer_Resupply_Crate";
                    };
                    class ArsenalCrate
                    {
                        name = "Arsenal Supply Crate";
                        value = "42nd_Arsenal_Supply";
                    };
                    class Lratv
                    {
                        name = "LRATV";
                        value = "42nd_LSV_Unarmed";
                    };
                    class LratvZ6
                    {
                        name = "LRATV (Z-6)";
                        value = "42nd_LSV_Armed";
                    };
                };
            };

            class ApproachHeading
            {
                displayName = "Approach Heading";
                description = "Direction in degrees for the drop run. Use -1 to inherit the module rotation.";
                typeName = "NUMBER";
                defaultValue = -1;
            };
        };

        class ModuleDescription: ModuleDescription
        {
            position = 1;
            direction = 1;
            sync[] = {"AnyPerson", "AnyVehicle"};
            description = "Calls an AI LAAT to drop the selected supply crate or light vehicle at this module position. If synced to a player or occupied vehicle, that unit receives delivery status hints.";
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
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\gozanti_spawner.sqf'";
        };
    };
    class 42nd_LAAT
    {
        class para42_laatColumnDrop
        {
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\modules\42nd_Scripts\resupply\laat_spawner.sqf'";
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

class CfgSounds
{
    sounds[] =
    {
        "CTHUD_PowerOn",
        "CTHUD_PowerOff"
    };

    class CTHUD_PowerOn
    {
        name = "CTHUD_PowerOn";
        sound[] = {"\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\sounds\cthud_power_on.wav", 1, 1};
        titles[] = {};
    };

    class CTHUD_PowerOff
    {
        name = "CTHUD_PowerOff";
        sound[] = {"\42nd_para\42nd\addons\modules\42nd_Scripts\CloneTrooperHUD_Addon\CloneTrooperHUD_Addon\sounds\cthud_power_off.wav", 1, 1};
        titles[] = {};
    };
};

class RscText;
class RscMapControl;
class RscPicture;
class RscStructuredText;

class RscTitles
{
    class CTHUD_Main_Base
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
                style = 48;
                text = "";
                colorText[] = {1, 1, 1, 1};
            };

            class PilotBannerBg: RscText
            {
                idc = 1600;
                x = "0.34 * safezoneW + safezoneX";
                y = "0.084 * safezoneH + safezoneY";
                w = "0.32 * safezoneW";
                h = "0.028 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class PilotBannerText: RscText
            {
                idc = 1601;
                x = "0.35 * safezoneW + safezoneX";
                y = "0.087 * safezoneH + safezoneY";
                w = "0.30 * safezoneW";
                h = "0.022 * safezoneH";
                style = 2;
                sizeEx = 0.026;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class PilotTelemetryLeftBg: RscText
            {
                idc = 1602;
                x = "0.038 * safezoneW + safezoneX";
                y = "0.592 * safezoneH + safezoneY";
                w = "0.164 * safezoneW";
                h = "0.048 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class PilotTelemetryLeft: RscStructuredText
            {
                idc = 1603;
                x = "0.046 * safezoneW + safezoneX";
                y = "0.599 * safezoneH + safezoneY";
                w = "0.148 * safezoneW";
                h = "0.034 * safezoneH";
                size = 0.024;
                text = "";
            };

            class PilotTelemetryRightBg: RscText
            {
                idc = 1604;
                x = "0.776 * safezoneW + safezoneX";
                y = "0.648 * safezoneH + safezoneY";
                w = "0.204 * safezoneW";
                h = "0.048 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class PilotTelemetryRight: RscStructuredText
            {
                idc = 1605;
                x = "0.784 * safezoneW + safezoneX";
                y = "0.655 * safezoneH + safezoneY";
                w = "0.188 * safezoneW";
                h = "0.034 * safezoneH";
                size = 0.024;
                text = "";
            };

            class WeaponInfoBg: RscText
            {
                idc = 1000;
                x = "0.782 * safezoneW + safezoneX";
                y = "0.764 * safezoneH + safezoneY";
                w = "0.198 * safezoneW";
                h = "0.145 * safezoneH";
                colorBackground[] = {0.08, 0.08, 0.08, 0.26};
            };

            class WeaponPreview: RscPicture
            {
                idc = 1004;
                x = "0.892 * safezoneW + safezoneX";
                y = "0.803 * safezoneH + safezoneY";
                w = "0.072 * safezoneW";
                h = "0.082 * safezoneH";
                text = "";
            };

            class WeaponText: RscText
            {
                idc = 1001;
                x = "0.794 * safezoneW + safezoneX";
                y = "0.781 * safezoneH + safezoneY";
                w = "0.172 * safezoneW";
                h = "0.024 * safezoneH";
                sizeEx = 0.022;
                font = "EtelkaMonospacePro";
                text = "WEAPON";
                colorBackground[] = {0, 0, 0, 0};
            };

            class MagText: RscText
            {
                idc = 1002;
                x = "0.794 * safezoneW + safezoneX";
                y = "0.812 * safezoneH + safezoneY";
                w = "0.096 * safezoneW";
                h = "0.038 * safezoneH";
                sizeEx = 0.04;
                font = "EtelkaMonospacePro";
                text = "MAG: 0 | RES: 0";
                colorBackground[] = {0, 0, 0, 0};
            };

            class FireModeText: RscText
            {
                idc = 1003;
                x = "0.794 * safezoneW + safezoneX";
                y = "0.86 * safezoneH + safezoneY";
                w = "0.096 * safezoneW";
                h = "0.022 * safezoneH";
                sizeEx = 0.022;
                font = "EtelkaMonospacePro";
                text = "MODE: SAFE";
                colorBackground[] = {0, 0, 0, 0};
            };

            class CompassBg: RscText
            {
                idc = 1302;
                x = "0.215 * safezoneW + safezoneX";
                y = "0.018 * safezoneH + safezoneY";
                w = "0.57 * safezoneW";
                h = "0.072 * safezoneH";
                colorBackground[] = {0.05, 0.07, 0.09, 0.26};
            };

            class CompassText: RscText
            {
                idc = 1300;
                x = "0.233 * safezoneW + safezoneX";
                y = "0.024 * safezoneH + safezoneY";
                w = "0.534 * safezoneW";
                h = "0.022 * safezoneH";
                style = 2;
                sizeEx = 0.026;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class CompassCenterMark: RscText
            {
                idc = 1303;
                x = "0.499 * safezoneW + safezoneX";
                y = "0.049 * safezoneH + safezoneY";
                w = "0.002 * safezoneW";
                h = "0.013 * safezoneH";
                colorBackground[] = {1, 1, 1, 0.8};
            };

            class BearingText: RscText
            {
                idc = 1301;
                x = "0.438 * safezoneW + safezoneX";
                y = "0.056 * safezoneH + safezoneY";
                w = "0.124 * safezoneW";
                h = "0.016 * safezoneH";
                style = 2;
                sizeEx = 0.028;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class HealthBarBg: RscText
            {
                idc = 1310;
                x = "0.302 * safezoneW + safezoneX";
                y = "0.076 * safezoneH + safezoneY";
                w = "0.396 * safezoneW";
                h = "0.006 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class HealthBarFill: HealthBarBg
            {
                idc = 1311;
                w = "0";
            };

            class HealthText: RscText
            {
                idc = 1312;
                x = "0.41 * safezoneW + safezoneX";
                y = "0.081 * safezoneH + safezoneY";
                w = "0.18 * safezoneW";
                h = "0.016 * safezoneH";
                style = 2;
                sizeEx = 0.018;
                font = "EtelkaMonospacePro";
                text = "";
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
                x = "0.026 * safezoneW + safezoneX";
                y = "0.756 * safezoneH + safezoneY";
                w = "0.19 * safezoneW";
                h = "0.19 * safezoneH";
                colorBackground[] = {0.08, 0.08, 0.08, 0.35};
            };

            class MiniMap: RscMapControl
            {
                idc = 1200;
                x = "0.026 * safezoneW + safezoneX";
                y = "0.756 * safezoneH + safezoneY";
                w = "0.19 * safezoneW";
                h = "0.19 * safezoneH";
                showCountourInterval = 0;
                scaleDefault = 0.08;
                alphaFadeStartScale = 10;
                alphaFadeEndScale = 10;
            };

            class MiniMapFrame: RscPicture
            {
                idc = 1201;
                x = "0.026 * safezoneW + safezoneX";
                y = "0.756 * safezoneH + safezoneY";
                w = "0.19 * safezoneW";
                h = "0.19 * safezoneH";
                text = "";
                colorText[] = {1, 1, 1, 0};
            };

            class TrackerTitle: RscText
            {
                idc = 1215;
                x = "0.032 * safezoneW + safezoneX";
                y = "0.764 * safezoneH + safezoneY";
                w = "0.178 * safezoneW";
                h = "0.015 * safezoneH";
                style = 2;
                sizeEx = 0.021;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerPanel: RscText
            {
                idc = 1210;
                x = "0.042 * safezoneW + safezoneX";
                y = "0.784 * safezoneH + safezoneY";
                w = "0.158 * safezoneW";
                h = "0.13 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerCrossVertical: RscText
            {
                idc = 1211;
                x = "0.1204 * safezoneW + safezoneX";
                y = "0.784 * safezoneH + safezoneY";
                w = "0.0012 * safezoneW";
                h = "0.13 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerCrossHorizontal: RscText
            {
                idc = 1212;
                x = "0.042 * safezoneW + safezoneX";
                y = "0.8482 * safezoneH + safezoneY";
                w = "0.158 * safezoneW";
                h = "0.0016 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerCenterDot: RscText
            {
                idc = 1213;
                x = "0.1189 * safezoneW + safezoneX";
                y = "0.8462 * safezoneH + safezoneY";
                w = "0.0042 * safezoneW";
                h = "0.0056 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerSweepLine: RscText
            {
                idc = 1214;
                x = "0.121 * safezoneW + safezoneX";
                y = "0.847 * safezoneH + safezoneY";
                w = "0.07 * safezoneW";
                h = "0.0015 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerStatus: RscText
            {
                idc = 1216;
                x = "0.032 * safezoneW + safezoneX";
                y = "0.918 * safezoneH + safezoneY";
                w = "0.178 * safezoneW";
                h = "0.015 * safezoneH";
                style = 2;
                sizeEx = 0.019;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerRingOuter: RscPicture
            {
                idc = 1217;
                x = "0.042 * safezoneW + safezoneX";
                y = "0.784 * safezoneH + safezoneY";
                w = "0.158 * safezoneW";
                h = "0.13 * safezoneH";
                text = "\A3\ui_f\data\map\markers\military\circle_CA.paa";
                colorText[] = {1, 1, 1, 1};
            };

            class TrackerRingMid: RscPicture
            {
                idc = 1218;
                x = "0.067 * safezoneW + safezoneX";
                y = "0.805 * safezoneH + safezoneY";
                w = "0.108 * safezoneW";
                h = "0.088 * safezoneH";
                text = "\A3\ui_f\data\map\markers\military\circle_CA.paa";
                colorText[] = {1, 1, 1, 1};
            };

            class TrackerRingInner: RscPicture
            {
                idc = 1219;
                x = "0.092 * safezoneW + safezoneX";
                y = "0.826 * safezoneH + safezoneY";
                w = "0.058 * safezoneW";
                h = "0.046 * safezoneH";
                text = "\A3\ui_f\data\map\markers\military\circle_CA.paa";
                colorText[] = {1, 1, 1, 1};
            };

            class TrackerBlip01: RscText
            {
                idc = 1220;
                x = "0";
                y = "0";
                w = "0";
                h = "0";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class TrackerBlip02: TrackerBlip01 { idc = 1221; };
            class TrackerBlip03: TrackerBlip01 { idc = 1222; };
            class TrackerBlip04: TrackerBlip01 { idc = 1223; };
            class TrackerBlip05: TrackerBlip01 { idc = 1224; };
            class TrackerBlip06: TrackerBlip01 { idc = 1225; };
            class TrackerBlip07: TrackerBlip01 { idc = 1226; };
            class TrackerBlip08: TrackerBlip01 { idc = 1227; };
            class TrackerBlip09: TrackerBlip01 { idc = 1228; };
            class TrackerBlip10: TrackerBlip01 { idc = 1229; };
            class TrackerBlip11: TrackerBlip01 { idc = 1230; };
            class TrackerBlip12: TrackerBlip01 { idc = 1231; };

            class StartupBlackout: RscText
            {
                idc = 1505;
                x = "safezoneX";
                y = "safezoneY";
                w = "safezoneW";
                h = "safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class StartupPanel: RscText
            {
                idc = 1500;
                x = "0.29 * safezoneW + safezoneX";
                y = "0.44 * safezoneH + safezoneY";
                w = "0.42 * safezoneW";
                h = "0.11 * safezoneH";
                colorBackground[] = {0.02, 0.05, 0.07, 0};
            };

            class StartupMainText: RscText
            {
                idc = 1501;
                x = "0.31 * safezoneW + safezoneX";
                y = "0.462 * safezoneH + safezoneY";
                w = "0.38 * safezoneW";
                h = "0.03 * safezoneH";
                style = 2;
                sizeEx = 0.04;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class StartupStatusText: RscText
            {
                idc = 1502;
                x = "0.31 * safezoneW + safezoneX";
                y = "0.497 * safezoneH + safezoneY";
                w = "0.38 * safezoneW";
                h = "0.022 * safezoneH";
                style = 2;
                sizeEx = 0.026;
                font = "EtelkaMonospacePro";
                text = "";
                colorBackground[] = {0, 0, 0, 0};
            };

            class StartupBarBg: RscText
            {
                idc = 1503;
                x = "0.33 * safezoneW + safezoneX";
                y = "0.531 * safezoneH + safezoneY";
                w = "0.34 * safezoneW";
                h = "0.012 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };

            class StartupBarFill: RscText
            {
                idc = 1504;
                x = "0.33 * safezoneW + safezoneX";
                y = "0.531 * safezoneH + safezoneY";
                w = "0";
                h = "0.012 * safezoneH";
                colorBackground[] = {0, 0, 0, 0};
            };
        };
    };

    class CTHUD_Main: CTHUD_Main_Base {};

    class CTHUD_Main_Compact: CTHUD_Main_Base
    {
        class controls: controls
        {
            class PilotBannerText: PilotBannerText
            {
                sizeEx = 0.023;
            };

            class PilotTelemetryLeft: PilotTelemetryLeft
            {
                size = 0.021;
            };

            class PilotTelemetryRight: PilotTelemetryRight
            {
                size = 0.021;
            };

            class WeaponText: WeaponText
            {
                sizeEx = 0.02;
            };

            class MagText: MagText
            {
                sizeEx = 0.034;
            };

            class FireModeText: FireModeText
            {
                sizeEx = 0.019;
            };

            class CompassText: CompassText
            {
                sizeEx = 0.024;
            };

            class BearingText: BearingText
            {
                sizeEx = 0.025;
            };

            class HealthText: HealthText
            {
                sizeEx = 0.016;
            };

            class SquadListText: SquadListText
            {
                size = 0.025;
            };

            class StartupMainText: StartupMainText
            {
                sizeEx = 0.036;
            };

            class StartupStatusText: StartupStatusText
            {
                sizeEx = 0.023;
            };
        };
    };

    class CTHUD_Main_Large: CTHUD_Main_Base
    {
        class controls: controls
        {
            class PilotBannerText: PilotBannerText
            {
                sizeEx = 0.03;
            };

            class PilotTelemetryLeft: PilotTelemetryLeft
            {
                size = 0.028;
            };

            class PilotTelemetryRight: PilotTelemetryRight
            {
                size = 0.028;
            };

            class WeaponText: WeaponText
            {
                sizeEx = 0.024;
            };

            class MagText: MagText
            {
                sizeEx = 0.046;
            };

            class FireModeText: FireModeText
            {
                sizeEx = 0.024;
            };

            class CompassText: CompassText
            {
                sizeEx = 0.03;
            };

            class BearingText: BearingText
            {
                sizeEx = 0.032;
            };

            class HealthText: HealthText
            {
                sizeEx = 0.02;
            };

            class SquadListText: SquadListText
            {
                size = 0.032;
            };

            class StartupMainText: StartupMainText
            {
                sizeEx = 0.046;
            };

            class StartupStatusText: StartupStatusText
            {
                sizeEx = 0.03;
            };
        };
    };

    class CTHUD_Main_XLarge: CTHUD_Main_Base
    {
        class controls: controls
        {
            class PilotBannerText: PilotBannerText
            {
                sizeEx = 0.034;
            };

            class PilotTelemetryLeft: PilotTelemetryLeft
            {
                size = 0.031;
            };

            class PilotTelemetryRight: PilotTelemetryRight
            {
                size = 0.031;
            };

            class WeaponText: WeaponText
            {
                sizeEx = 0.027;
            };

            class MagText: MagText
            {
                sizeEx = 0.05;
            };

            class FireModeText: FireModeText
            {
                sizeEx = 0.026;
            };

            class CompassText: CompassText
            {
                sizeEx = 0.034;
            };

            class BearingText: BearingText
            {
                sizeEx = 0.036;
            };

            class HealthText: HealthText
            {
                sizeEx = 0.023;
            };

            class SquadListText: SquadListText
            {
                size = 0.036;
            };

            class StartupMainText: StartupMainText
            {
                sizeEx = 0.052;
            };

            class StartupStatusText: StartupStatusText
            {
                sizeEx = 0.034;
            };
        };
    };
};
