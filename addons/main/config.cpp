class CfgPatches {
    class Aux_42nd {
        //requiredAddons[] = {"ace_common"};
        units[] = {
            "42nd_Trooper",
            "42nd_CPLTL_Trooper",
            "42nd_CSGT_Trooper",
            "42nd_CST_Trooper",
            "42nd_medic_Trooper",
            "42nd_Rose_Trooper",
            "42nd_CVT_Trooper",
            "42nd_NCO_Trooper",
            "42nd_LAAT",
            "42nd_Gozanti_Republic",
            "42nd_Arsenal_Box",
            "42nd_Arsenal_Supply",
            "42nd_Arsenal_Weapon_Crate"
        };
        weapons[] = {
            "42nd_CT_P2_Helmet",
            "42nd_CPLTL_P2_Helmet",
            "42nd_CSGT_P2_Helmet",
            "42nd_CST_P2_Helmet",
            "42nd_ARF_Helmet",
            "42nd_Medic_P2_Helmet",
            "42nd_Rose_P2_Helmet",
            "42nd_CVT_P2_Helmet",
            "42nd_NCO_P2_Helmet",
            "42nd_Trooper_Uniform",
            "42nd_CPLTL_Trooper_Uniform",
            "42nd_CSGT_Trooper_Uniform",
            "42nd_CST_Trooper_Uniform",
            "42nd_medic_Trooper_Uniform",
            "42nd_Rose_Trooper_Uniform",
            "42nd_CVT_Trooper_Uniform",
            "42nd_NCO_Trooper_Uniform"
        };
        skipWhenMissingDependencies = 1;
    };
};
class cfgFactionClasses
{
    class Fac42nd
    {
        displayName = "42nd Paracore Battalion";
    };
};
zeusCompositionScriptLevel = 2;

class CfgEditorCategories
{
    class 42nd_Objects
    {
        displayName = "[42nd] Objects";
    };
};
class cfgEditorSubcategories {
    class Sub42ndMen
    {
        displayName = "Infantry";
    };
    class Sub42ndCustom
    {
        displayName = "Customs";
    };
    class Sub42ndVics
    {
        displayName = "Trucks";
    };
    class Sub42ndLightVic
    {
        displayName = "Cars";
    };
    class Sub42ndDrone
    {
        displayName = "Drone";
    };
    class Sub42ndTanks
    {
        displayName = "Tanks";
    };
    class Sub42ndBoats
    {
        displayName = "Boats";
    };
    class SUB42ndAir
    {
        displayName = "Aircraft";
    };
    class SUB42ndOBJ
    {
        displayName = "Objects";
    };
};
class CfgWeapons
{
#include "/addons/Bluefor/42nd_Helmets/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Uniforms/cfgWeapons.hpp"
};
class CfgVehicles
{
#include "/addons/Bluefor/42nd_Uniforms/cfgVehicles.hpp"
#include "/addons/main/objects/arsenal_box/cfgVehicles.hpp"
#include "/addons/Vehicles/42nd_Gozanti/cfgvehicles.hpp"
#include "/addons/Vehicles/42nd_LAAT/cfgvehicles.hpp"
};

class Extended_InitPost_EventHandlers
{
    class 42nd_Gozanti_Republic
    {
        class para42_gozantiSpawner
        {
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\Modules\42nd_Scripts\gozanti_spawner'";
        };
    };
    class 42nd_LAAT
    {
        class para42_laatColumnDrop
        {
            init = "[_this select 0] execVM '\42nd_para\42nd\addons\Modules\42nd_Scripts\laat_column_drop'";
        };
    };
};
