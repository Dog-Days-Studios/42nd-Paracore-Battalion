class CfgPatches
{
    class Aux_42nd_CIS
    {
        name = "42nd CIS";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] =
        {
            "A3_Characters_F",
            "A3_Weapons_F",
            "JLTS_characters_DroidArmor",
            "IDA_Ammo",
            "IDA_Republic",
            "Indecisive_Armoury_units",
            "3AS_Weapons",
            "Aux_42nd"
        };
        units[] =
        {
            "42nd_Woodland_B1_Droid",
            "42nd_Woodland_B1_Flame",
            "42nd_Woodland_B1_Heavy",
            "42nd_Woodland_B1_Sniper",
            "42nd_Woodland_B1_Lite_AT",
            "42nd_Woodland_B1_Heavy_AT",
            "42nd_Desert_B1_Droid",
            "42nd_Desert_B1_Flame",
            "42nd_Desert_B1_Heavy",
            "42nd_Desert_B1_Sniper",
            "42nd_Desert_B1_Lite_AT",
            "42nd_Desert_B1_Heavy_AT",
            "42nd_MC_B1_Droid",
            "42nd_MC_B1_Flame",
            "42nd_MC_B1_Heavy",
            "42nd_MC_B1_Sniper",
            "42nd_MC_B1_Lite_AT",
            "42nd_MC_B1_Heavy_AT",
            "42nd_Winter_B1_Droid",
            "42nd_Winter_B1_Flame",
            "42nd_Winter_B1_Heavy",
            "42nd_Winter_B1_Sniper",
            "42nd_Winter_B1_Lite_AT",
            "42nd_Winter_B1_Heavy_AT",
            "42nd_Night_B1_Droid",
            "42nd_Night_B1_Flame",
            "42nd_Night_B1_Heavy",
            "42nd_Night_B1_Sniper",
            "42nd_Night_B1_Lite_AT",
            "42nd_Night_B1_Heavy_AT",
            "42nd_CIS_CIWIS"
        };
        weapons[] =
        {
            "42nd_CIS_DroidB1_Woodland",
            "42nd_CIS_DroidB1_Desert",
            "42nd_CIS_DroidB1_MC",
            "42nd_CIS_DroidB1_Winter",
            "42nd_CIS_DroidB1_Night"
        };
        skipWhenMissingDependencies = 1;
    };
};

class CfgFactionClasses
{
    class FacCIS_42nd
    {
        displayName = "[42nd] CIS";
        side = 0;
        priority = 2;
    };
};

class CfgEditorSubcategories
{
    class Sub42ndCISWoodland
    {
        displayName = "Woodland Camo";
    };
    class Sub42ndCISDesert
    {
        displayName = "Desert Camo";
    };
    class Sub42ndCISWinter
    {
        displayName = "Winter Camo";
    };
    class Sub42ndCISMC
    {
        displayName = "Multi-Camo";
    };
    class Sub42ndCISNight
    {
        displayName = "Urban Camo";
    };
    class Sub42ndCISEmplacements
    {
        displayName = "Emplacements";
    };
};

#define C42_LINKED_ITEMS "IDA_vest_attachment_base","JLTS_NVG_droid_chip_2","IDA_Electrobinoculars_Rep","JLTS_droid_comlink"
#define C42_B1_UNIT(CLASS,PARENT,NAME,UNIFORM,SUBCAT,TEXTURE) class CLASS: PARENT { scope = 2; scopeCurator = 2; displayName = NAME; uniformClass = UNIFORM; editorSubcategory = SUBCAT; hiddenSelectionsTextures[] = {TEXTURE}; };
#define C42_GROUP_UNIT(NUM,VEHICLE,RANKNAME,POSX,POSY) class Unit##NUM { side = 0; vehicle = VEHICLE; rank = RANKNAME; position[] = {POSX,POSY,0}; };
#define C42_GROUP_SENTRY(CLASS,NAME,RIFLE) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,RIFLE,"SERGEANT",1,0) C42_GROUP_UNIT(1,RIFLE,"PRIVATE",1,-1) };
#define C42_GROUP_SNIPER(CLASS,NAME,SNIPER) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,SNIPER,"SERGEANT",1,0) C42_GROUP_UNIT(1,SNIPER,"PRIVATE",1,-1) };
#define C42_GROUP_FIRETEAM(CLASS,NAME,RIFLE,HEAVY,LAT) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,RIFLE,"SERGEANT",1,0) C42_GROUP_UNIT(1,RIFLE,"PRIVATE",1,-1) C42_GROUP_UNIT(2,RIFLE,"PRIVATE",1,-2) C42_GROUP_UNIT(3,RIFLE,"PRIVATE",0,0) C42_GROUP_UNIT(4,HEAVY,"PRIVATE",0,-1) C42_GROUP_UNIT(5,LAT,"PRIVATE",0,-2) };
#define C42_GROUP_AT(CLASS,NAME,RIFLE,HAT,LAT) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,RIFLE,"SERGEANT",1,0) C42_GROUP_UNIT(1,RIFLE,"PRIVATE",1,-1) C42_GROUP_UNIT(2,HAT,"PRIVATE",1,-2) C42_GROUP_UNIT(3,HAT,"PRIVATE",0,0) C42_GROUP_UNIT(4,LAT,"PRIVATE",0,-1) C42_GROUP_UNIT(5,LAT,"PRIVATE",0,-2) };
#define C42_GROUP_FLAME(CLASS,NAME,RIFLE,FLAME) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,RIFLE,"SERGEANT",1,0) C42_GROUP_UNIT(1,RIFLE,"PRIVATE",1,-1) C42_GROUP_UNIT(2,FLAME,"PRIVATE",1,-2) C42_GROUP_UNIT(3,FLAME,"PRIVATE",0,0) C42_GROUP_UNIT(4,FLAME,"PRIVATE",0,-1) C42_GROUP_UNIT(5,FLAME,"PRIVATE",0,-2) };
#define C42_GROUP_SQUAD(CLASS,NAME,RIFLE,HEAVY,SNIPER,LAT) class CLASS { name = NAME; faction = "FacCIS_42nd"; side = 0; C42_GROUP_UNIT(0,RIFLE,"SERGEANT",1,0) C42_GROUP_UNIT(1,HEAVY,"PRIVATE",1,-1) C42_GROUP_UNIT(2,RIFLE,"PRIVATE",1,-2) C42_GROUP_UNIT(3,RIFLE,"PRIVATE",1,-3) C42_GROUP_UNIT(4,RIFLE,"PRIVATE",1,-4) C42_GROUP_UNIT(5,RIFLE,"PRIVATE",1,-5) C42_GROUP_UNIT(6,HEAVY,"PRIVATE",0,0) C42_GROUP_UNIT(7,RIFLE,"PRIVATE",0,-1) C42_GROUP_UNIT(8,RIFLE,"PRIVATE",0,-2) C42_GROUP_UNIT(9,SNIPER,"PRIVATE",0,-3) C42_GROUP_UNIT(10,SNIPER,"PRIVATE",0,-4) C42_GROUP_UNIT(11,LAT,"PRIVATE",0,-5) };

class CfgWeapons
{
    class UniformItem;
    class JLTS_DroidB1;

    class 42nd_CIS_DroidB1_Woodland: JLTS_DroidB1
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] B1 Droid Armor (Woodland)";
        picture = "\MRC\JLTS\characters\DroidArmor\data\ui\b1_uniform_ui_ca.paa";
        class ItemInfo: UniformItem
        {
            uniformModel = "-";
            uniformClass = "42nd_Woodland_B1_Droid";
            containerClass = "Supply250";
            mass = 40;
        };
    };

    class 42nd_CIS_DroidB1_Desert: 42nd_CIS_DroidB1_Woodland
    {
        displayName = "[42nd] B1 Droid Armor (Desert)";
        class ItemInfo: ItemInfo
        {
            uniformClass = "42nd_Desert_B1_Droid";
        };
    };

    class 42nd_CIS_DroidB1_MC: 42nd_CIS_DroidB1_Woodland
    {
        displayName = "[42nd] B1 Droid Armor (Multi-Camo)";
        class ItemInfo: ItemInfo
        {
            uniformClass = "42nd_MC_B1_Droid";
        };
    };

    class 42nd_CIS_DroidB1_Winter: 42nd_CIS_DroidB1_Woodland
    {
        displayName = "[42nd] B1 Droid Armor (Winter)";
        class ItemInfo: ItemInfo
        {
            uniformClass = "42nd_Winter_B1_Droid";
        };
    };

    class 42nd_CIS_DroidB1_Night: 42nd_CIS_DroidB1_Woodland
    {
        displayName = "[42nd] B1 Droid Armor (Urban)";
        class ItemInfo: ItemInfo
        {
            uniformClass = "42nd_Night_B1_Droid";
        };
    };
};

class CfgVehicles
{
    class JLTS_Droid_B1_E5;
    class JLTS_Droid_B1_AR;
    class JLTS_Droid_B1_Sniper;
    class JLTS_Droid_B1_AT;
    class B_AAA_System_01_F
    {
        class Turrets
        {
            class MainTurret;
        };
    };

    class 42nd_CIS_Rifleman_Base: JLTS_Droid_B1_E5
    {
        author = "HoundaCivic";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "FacCIS_42nd";
        backpack = "JLTS_B1_backpack";
        weapons[] = {"IDA_E5", "Throw", "Put"};
        respawnWeapons[] = {"IDA_E5", "Throw", "Put"};
        linkedItems[] = {C42_LINKED_ITEMS};
        respawnLinkedItems[] = {C42_LINKED_ITEMS};
        magazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    class 42nd_CIS_Flame_Base: 42nd_CIS_Rifleman_Base
    {
        weapons[] = {"3AS_Flamer_Base", "Throw", "Put"};
        respawnWeapons[] = {"3AS_Flamer_Base", "Throw", "Put"};
        magazines[] = {"3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "3AS_FlamerFuel", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    class 42nd_CIS_Heavy_Base: JLTS_Droid_B1_AR
    {
        author = "HoundaCivic";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "FacCIS_42nd";
        backpack = "JLTS_B1_backpack";
        weapons[] = {"IDA_E5C_Stock", "Throw", "Put"};
        respawnWeapons[] = {"IDA_E5C_Stock", "Throw", "Put"};
        linkedItems[] = {C42_LINKED_ITEMS};
        respawnLinkedItems[] = {C42_LINKED_ITEMS};
        magazines[] = {"IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_blaster_battery_Red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    class 42nd_CIS_Sniper_Base: JLTS_Droid_B1_Sniper
    {
        author = "HoundaCivic";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "FacCIS_42nd";
        backpack = "JLTS_B1_backpack";
        weapons[] = {"IDA_E5S", "Throw", "Put"};
        respawnWeapons[] = {"IDA_E5S", "Throw", "Put"};
        linkedItems[] = {C42_LINKED_ITEMS};
        respawnLinkedItems[] = {C42_LINKED_ITEMS};
        magazines[] = {"IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_blaster_cell_Overcharged_Red", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    class 42nd_CIS_LiteAT_Base: JLTS_Droid_B1_AT
    {
        author = "HoundaCivic";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "FacCIS_42nd";
        backpack = "JLTS_B1_backpack";
        weapons[] = {"IDA_E5", "IDA_RPS6HP", "Throw", "Put"};
        respawnWeapons[] = {"IDA_E5", "IDA_RPS6HP", "Throw", "Put"};
        linkedItems[] = {C42_LINKED_ITEMS};
        respawnLinkedItems[] = {C42_LINKED_ITEMS};
        magazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_RPS6_rocket", "IDA_RPS6_rocket", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_RPS6_rocket", "IDA_RPS6_rocket", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    class 42nd_CIS_HeavyAT_Base: JLTS_Droid_B1_AT
    {
        author = "HoundaCivic";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "FacCIS_42nd";
        backpack = "JLTS_B1_backpack";
        weapons[] = {"IDA_E5", "3AS_E60R_F", "Throw", "Put"};
        respawnWeapons[] = {"IDA_E5", "3AS_E60R_F", "Throw", "Put"};
        linkedItems[] = {C42_LINKED_ITEMS};
        respawnLinkedItems[] = {C42_LINKED_ITEMS};
        magazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "3AS_E60R_AT", "3AS_E60R_AT", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
        respawnMagazines[] = {"IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "IDA_blaster_cell_red", "3AS_E60R_AT", "3AS_E60R_AT", "IDA_grenade_Penetrator_mag", "IDA_grenade_Penetrator_mag"};
    };

    C42_B1_UNIT(42nd_Woodland_B1_Droid,42nd_CIS_Rifleman_Base,"[42nd] B1 Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Woodland_co.paa")
    C42_B1_UNIT(42nd_Woodland_B1_Flame,42nd_CIS_Flame_Base,"[42nd] B1 Flame Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Flame_Droid_co.paa")
    C42_B1_UNIT(42nd_Woodland_B1_Heavy,42nd_CIS_Heavy_Base,"[42nd] B1 Heavy Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Woodland_co.paa")
    C42_B1_UNIT(42nd_Woodland_B1_Sniper,42nd_CIS_Sniper_Base,"[42nd] B1 Sniper Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Woodland_co.paa")
    C42_B1_UNIT(42nd_Woodland_B1_Lite_AT,42nd_CIS_LiteAT_Base,"[42nd] B1 Light AT Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Woodland_co.paa")
    C42_B1_UNIT(42nd_Woodland_B1_Heavy_AT,42nd_CIS_HeavyAT_Base,"[42nd] B1 Heavy AT Droid","42nd_CIS_DroidB1_Woodland","Sub42ndCISWoodland","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Woodland_co.paa")

    C42_B1_UNIT(42nd_Desert_B1_Droid,42nd_CIS_Rifleman_Base,"[42nd] B1 Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Desert_co.paa")
    C42_B1_UNIT(42nd_Desert_B1_Flame,42nd_CIS_Flame_Base,"[42nd] B1 Flame Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Flame_Droid_Desert_co.paa")
    C42_B1_UNIT(42nd_Desert_B1_Heavy,42nd_CIS_Heavy_Base,"[42nd] B1 Heavy Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Desert_co.paa")
    C42_B1_UNIT(42nd_Desert_B1_Sniper,42nd_CIS_Sniper_Base,"[42nd] B1 Sniper Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Desert_co.paa")
    C42_B1_UNIT(42nd_Desert_B1_Lite_AT,42nd_CIS_LiteAT_Base,"[42nd] B1 Light AT Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Desert_co.paa")
    C42_B1_UNIT(42nd_Desert_B1_Heavy_AT,42nd_CIS_HeavyAT_Base,"[42nd] B1 Heavy AT Droid","42nd_CIS_DroidB1_Desert","Sub42ndCISDesert","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Desert_co.paa")

    C42_B1_UNIT(42nd_MC_B1_Droid,42nd_CIS_Rifleman_Base,"[42nd] B1 Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_MC_co.paa")
    C42_B1_UNIT(42nd_MC_B1_Flame,42nd_CIS_Flame_Base,"[42nd] B1 Flame Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Flame_Droid_MC_co.paa")
    C42_B1_UNIT(42nd_MC_B1_Heavy,42nd_CIS_Heavy_Base,"[42nd] B1 Heavy Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_MC_co.paa")
    C42_B1_UNIT(42nd_MC_B1_Sniper,42nd_CIS_Sniper_Base,"[42nd] B1 Sniper Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_MC_co.paa")
    C42_B1_UNIT(42nd_MC_B1_Lite_AT,42nd_CIS_LiteAT_Base,"[42nd] B1 Light AT Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_MC_co.paa")
    C42_B1_UNIT(42nd_MC_B1_Heavy_AT,42nd_CIS_HeavyAT_Base,"[42nd] B1 Heavy AT Droid","42nd_CIS_DroidB1_MC","Sub42ndCISMC","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_MC_co.paa")

    C42_B1_UNIT(42nd_Winter_B1_Droid,42nd_CIS_Rifleman_Base,"[42nd] B1 Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Winter_co.paa")
    C42_B1_UNIT(42nd_Winter_B1_Flame,42nd_CIS_Flame_Base,"[42nd] B1 Flame Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Flame_Droid_Winter_co.paa")
    C42_B1_UNIT(42nd_Winter_B1_Heavy,42nd_CIS_Heavy_Base,"[42nd] B1 Heavy Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Winter_co.paa")
    C42_B1_UNIT(42nd_Winter_B1_Sniper,42nd_CIS_Sniper_Base,"[42nd] B1 Sniper Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Winter_co.paa")
    C42_B1_UNIT(42nd_Winter_B1_Lite_AT,42nd_CIS_LiteAT_Base,"[42nd] B1 Light AT Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Winter_co.paa")
    C42_B1_UNIT(42nd_Winter_B1_Heavy_AT,42nd_CIS_HeavyAT_Base,"[42nd] B1 Heavy AT Droid","42nd_CIS_DroidB1_Winter","Sub42ndCISWinter","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Winter_co.paa")

    C42_B1_UNIT(42nd_Night_B1_Droid,42nd_CIS_Rifleman_Base,"[42nd] B1 Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Night_co.paa")
    C42_B1_UNIT(42nd_Night_B1_Flame,42nd_CIS_Flame_Base,"[42nd] B1 Flame Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Flame_Droid_Night_co.paa")
    C42_B1_UNIT(42nd_Night_B1_Heavy,42nd_CIS_Heavy_Base,"[42nd] B1 Heavy Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Night_co.paa")
    C42_B1_UNIT(42nd_Night_B1_Sniper,42nd_CIS_Sniper_Base,"[42nd] B1 Sniper Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Night_co.paa")
    C42_B1_UNIT(42nd_Night_B1_Lite_AT,42nd_CIS_LiteAT_Base,"[42nd] B1 Light AT Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Night_co.paa")
    C42_B1_UNIT(42nd_Night_B1_Heavy_AT,42nd_CIS_HeavyAT_Base,"[42nd] B1 Heavy AT Droid","42nd_CIS_DroidB1_Night","Sub42ndCISNight","\42nd_para\42nd\addons\Opfor\42nd_CIS\B1\612thABD_B1_Night_co.paa")

    class 42nd_CIS_CIWIS: B_AAA_System_01_F
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        side = 0;
        faction = "FacCIS_42nd";
        editorSubcategory = "Sub42ndCISEmplacements";
        crew = "O_UAV_AI";
        typicalCargo[] = {"O_UAV_AI"};
        displayName = "[42nd] CIS CIWS";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                weapons[] = {"42nd_CIWIS_Cannon"};
                magazines[] = {"42nd_CIWIS_Magazine", "42nd_CIWIS_Magazine"};
            };
        };
    };
};

class CfgGroups
{
    class East
    {
        name = "OPFOR";
        class FacCIS_42nd
        {
            name = "[42nd] CIS Battledroids";
            class Infantry
            {
                name = "Infantry";

                C42_GROUP_SQUAD(42nd_Woodland_B1_Squad,"[42nd] Woodland B1 Squad","42nd_Woodland_B1_Droid","42nd_Woodland_B1_Heavy","42nd_Woodland_B1_Sniper","42nd_Woodland_B1_Lite_AT")
                C42_GROUP_FIRETEAM(42nd_Woodland_B1_FireTeam,"[42nd] Woodland B1 Fireteam","42nd_Woodland_B1_Droid","42nd_Woodland_B1_Heavy","42nd_Woodland_B1_Lite_AT")
                C42_GROUP_AT(42nd_Woodland_B1_AT_FireTeam,"[42nd] Woodland B1 AT Fireteam","42nd_Woodland_B1_Droid","42nd_Woodland_B1_Heavy_AT","42nd_Woodland_B1_Lite_AT")
                C42_GROUP_FLAME(42nd_Woodland_B1_Flame_FireTeam,"[42nd] Woodland B1 Flame Team","42nd_Woodland_B1_Droid","42nd_Woodland_B1_Flame")
                C42_GROUP_SENTRY(42nd_Woodland_B1_Sentry,"[42nd] Woodland B1 Sentry Team","42nd_Woodland_B1_Droid")
                C42_GROUP_SNIPER(42nd_Woodland_B1_SniperTeam,"[42nd] Woodland B1 Sniper Team","42nd_Woodland_B1_Sniper")

                C42_GROUP_SQUAD(42nd_Desert_B1_Squad,"[42nd] Desert B1 Squad","42nd_Desert_B1_Droid","42nd_Desert_B1_Heavy","42nd_Desert_B1_Sniper","42nd_Desert_B1_Lite_AT")
                C42_GROUP_FIRETEAM(42nd_Desert_B1_FireTeam,"[42nd] Desert B1 Fireteam","42nd_Desert_B1_Droid","42nd_Desert_B1_Heavy","42nd_Desert_B1_Lite_AT")
                C42_GROUP_AT(42nd_Desert_B1_AT_FireTeam,"[42nd] Desert B1 AT Fireteam","42nd_Desert_B1_Droid","42nd_Desert_B1_Heavy_AT","42nd_Desert_B1_Lite_AT")
                C42_GROUP_FLAME(42nd_Desert_B1_Flame_FireTeam,"[42nd] Desert B1 Flame Team","42nd_Desert_B1_Droid","42nd_Desert_B1_Flame")
                C42_GROUP_SENTRY(42nd_Desert_B1_Sentry,"[42nd] Desert B1 Sentry Team","42nd_Desert_B1_Droid")
                C42_GROUP_SNIPER(42nd_Desert_B1_SniperTeam,"[42nd] Desert B1 Sniper Team","42nd_Desert_B1_Sniper")

                C42_GROUP_SQUAD(42nd_MC_B1_Squad,"[42nd] Multi-Camo B1 Squad","42nd_MC_B1_Droid","42nd_MC_B1_Heavy","42nd_MC_B1_Sniper","42nd_MC_B1_Lite_AT")
                C42_GROUP_FIRETEAM(42nd_MC_B1_FireTeam,"[42nd] Multi-Camo B1 Fireteam","42nd_MC_B1_Droid","42nd_MC_B1_Heavy","42nd_MC_B1_Lite_AT")
                C42_GROUP_AT(42nd_MC_B1_AT_FireTeam,"[42nd] Multi-Camo B1 AT Fireteam","42nd_MC_B1_Droid","42nd_MC_B1_Heavy_AT","42nd_MC_B1_Lite_AT")
                C42_GROUP_FLAME(42nd_MC_B1_Flame_FireTeam,"[42nd] Multi-Camo B1 Flame Team","42nd_MC_B1_Droid","42nd_MC_B1_Flame")
                C42_GROUP_SENTRY(42nd_MC_B1_Sentry,"[42nd] Multi-Camo B1 Sentry Team","42nd_MC_B1_Droid")
                C42_GROUP_SNIPER(42nd_MC_B1_SniperTeam,"[42nd] Multi-Camo B1 Sniper Team","42nd_MC_B1_Sniper")

                C42_GROUP_SQUAD(42nd_Winter_B1_Squad,"[42nd] Winter B1 Squad","42nd_Winter_B1_Droid","42nd_Winter_B1_Heavy","42nd_Winter_B1_Sniper","42nd_Winter_B1_Lite_AT")
                C42_GROUP_FIRETEAM(42nd_Winter_B1_FireTeam,"[42nd] Winter B1 Fireteam","42nd_Winter_B1_Droid","42nd_Winter_B1_Heavy","42nd_Winter_B1_Lite_AT")
                C42_GROUP_AT(42nd_Winter_B1_AT_FireTeam,"[42nd] Winter B1 AT Fireteam","42nd_Winter_B1_Droid","42nd_Winter_B1_Heavy_AT","42nd_Winter_B1_Lite_AT")
                C42_GROUP_FLAME(42nd_Winter_B1_Flame_FireTeam,"[42nd] Winter B1 Flame Team","42nd_Winter_B1_Droid","42nd_Winter_B1_Flame")
                C42_GROUP_SENTRY(42nd_Winter_B1_Sentry,"[42nd] Winter B1 Sentry Team","42nd_Winter_B1_Droid")
                C42_GROUP_SNIPER(42nd_Winter_B1_SniperTeam,"[42nd] Winter B1 Sniper Team","42nd_Winter_B1_Sniper")

                C42_GROUP_SQUAD(42nd_Night_B1_Squad,"[42nd] Urban B1 Squad","42nd_Night_B1_Droid","42nd_Night_B1_Heavy","42nd_Night_B1_Sniper","42nd_Night_B1_Lite_AT")
                C42_GROUP_FIRETEAM(42nd_Night_B1_FireTeam,"[42nd] Urban B1 Fireteam","42nd_Night_B1_Droid","42nd_Night_B1_Heavy","42nd_Night_B1_Lite_AT")
                C42_GROUP_AT(42nd_Night_B1_AT_FireTeam,"[42nd] Urban B1 AT Fireteam","42nd_Night_B1_Droid","42nd_Night_B1_Heavy_AT","42nd_Night_B1_Lite_AT")
                C42_GROUP_FLAME(42nd_Night_B1_Flame_FireTeam,"[42nd] Urban B1 Flame Team","42nd_Night_B1_Droid","42nd_Night_B1_Flame")
                C42_GROUP_SENTRY(42nd_Night_B1_Sentry,"[42nd] Urban B1 Sentry Team","42nd_Night_B1_Droid")
                C42_GROUP_SNIPER(42nd_Night_B1_SniperTeam,"[42nd] Urban B1 Sniper Team","42nd_Night_B1_Sniper")
            };
        };
    };
};
