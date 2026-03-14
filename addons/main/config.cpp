class CfgPatches {
    class Aux_42nd {
        requiredVersion = 2.10;
        requiredAddons[] = {
            "A3_Weapons_F_Ammoboxes",
            "ace_main",
        };
        units[] = {
            "42nd_Trooper",
            "42nd_CPLTL_Trooper",
            "42nd_CSGT_Trooper",
            "42nd_CST_Trooper",
            "42nd_medic_Trooper",
            "42nd_CVT_Medic_Trooper",
            "42nd_Squad_Medic_Trooper",
            "42nd_Rose_Trooper",
            "42nd_Hound_Trooper",
            "42nd_CVT_Trooper",
            "42nd_NCO_Trooper",
            "42nd_Trainee_Pilot",
            "42nd_WO1_Pilot",
            "42nd_WO2_Pilot",
            "42nd_WO3_Pilot",
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
            "42nd_CVT_Medic_P2_Helmet",
            "42nd_Squad_Medic_P2_Helmet",
            "42nd_Rose_P2_Helmet",
            "42nd_Hound_P2_Helmet",
            "42nd_CVT_P2_Helmet",
            "42nd_NCO_P2_Helmet",
            "42nd_Trainee_Pilot_Helmet",
            "42nd_WO1_Pilot_Helmet",
            "42nd_WO2_Pilot_Helmet",
            "42nd_WO3_Pilot_Helmet",
            "42nd_Dual_Holsters",
            "42nd_Knife_Holster",
            "42nd_Holster",
            "42nd_Hidden_Vest",
            "42nd_Hidden_Medical_Vest",
            "42nd_Trooper_Uniform",
            "42nd_CPLTL_Trooper_Uniform",
            "42nd_CSGT_Trooper_Uniform",
            "42nd_CST_Trooper_Uniform",
            "42nd_medic_Trooper_Uniform",
            "42nd_CVT_Medic_Trooper_Uniform",
            "42nd_Squad_Medic_Trooper_Uniform",
            "42nd_Rose_Trooper_Uniform",
            "42nd_Hound_Trooper_Uniform",
            "42nd_CVT_Trooper_Uniform",
            "42nd_NCO_Trooper_Uniform",
            "42nd_HH12",
            "42nd_RPS6",
            "42nd_DC15S",
            "42nd_DC15S_UGL",
            "42nd_DC15A",
            "42nd_DC15C",
            "42nd_DC15C_UGL",
            "42nd_DC15LE",
            "42nd_T15",
            "42nd_DLT15",
            "42nd_DC15SX",
            "42nd_DC15HX",
            "42nd_DC15_Vintage",
            "42nd_773_FirePunch",
            "42nd_Z6",
            "42nd_Z6_GL",
            "42nd_Space_Intervention"
        };
        magazines[] = {
            "42nd_Stun_mag",
            "42nd_CIWIS_Magazine",
            "42nd_GL_Ext_Cell",
            "42nd_Imploder_Cell",
            "42nd_BlasterCell_High_Cap",
            "42nd_BlasterCell_308",
            "42nd_BlasterCell_308_EXT",
            "42nd_IDA_HEGL_Shell",
            "42nd_40mm_Blue",
            "42nd_40mm_red_smoke",
            "42nd_40mm_orange_smoke",
            "42nd_40mm_green_smoke",
            "42nd_40mm_red",
            "42nd_RPS_Extended_Mag",
            "42nd_Manta_Tow_Mag",
            "42nd_blaster_cell",
            "42nd_blaster_cell_High",
            "42nd_blaster_cell_Vintage",
            "42nd_blaster_cell_low",
            "42nd_blaster_cell_Amp",
            "42nd_blaster_cell_OC",
            "42nd_blaster_cell_HOC",
            "42nd_blaster_cell_APEX",
            "42nd_blaster_scatter_cell",
            "42nd_LP_blaster_battery",
            "42nd_HP_blaster_battery",
            "42nd_thermal_coil_AMP",
            "42nd_thermal_coil_HP"
        };
        ammo[] = {
            "42nd_blasterbolt_OC",
            "42nd_blasterbolt",
            "42nd_blasterbolt_High",
            "42nd_blasterbolt_Overcharged_VEHICLE",
            "42nd_Heavy_blasterbolt",
            "42nd_Apex_Blasterbolt"
        };
    };
};
class CfgFactionClasses
{
    class Fac42nd
    {
        displayName = "42nd Paracore Battalion";
    };
};
zeusCompositionScriptLevel = 2;

class CfgEditorCategories
{
    class EdCat_42ndObjects
    {
        displayName = "[42nd] Objects";
    };
    class 42nd_Objects
    {
        displayName = "[42nd] Objects";
    };
    class Fac42nd
    {
        displayName = "[42nd] Objects";
    };
};
class CfgEditorSubcategories {
    class Sub42ndMen
    {
        displayName = "Infantry";
    };
    class Sub42ndCustom
    {
        displayName = "Customs";
    };
    class Sub42ndAirCrew
    {
        displayName = "Air Crew";
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
class CfgFaces
{
    class Default;
    class Man_A3: Default
    {
        class WhiteHead_10;
        class 42nd_CloneFace: WhiteHead_10
        {
            author = "HoundaCivic";
            displayName = "[42nd] Clone Face";
            identityTypes[] = {"42nd_Clone_Face"};
        };
    };
};
class CfgGroups
{
    #include "/addons/Bluefor/42nd_Groups/42nd_Groups.hpp"
};
#include "/addons/Bluefor/42nd_Weapons/42nd_WeaponDecls.hpp"
class CfgAmmo
{
#include "/addons/Bluefor/42nd_Weapons/42nd_Ammo.hpp"
};
class CfgMagazines
{
#include "/addons/Bluefor/42nd_Weapons/42nd_Magazines.hpp"
};
class CfgMagazineWells
{
#include "/addons/Bluefor/42nd_Weapons/42nd_MagazineWells.hpp"
};
class CfgWeapons
{
#include "/addons/Bluefor/42nd_Weapons/42nd_Weapons.hpp"
#include "/addons/Bluefor/42nd_Helmets/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Vests/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Uniforms/cfgWeapons.hpp"
};
class CfgVehicles
{
#include "/addons/Bluefor/42nd_Uniforms/cfgVehicles.hpp"
#include "/addons/main/42nd_Objects.hpp"
#include "/addons/Vehicles/42nd_Gozanti/cfgvehicles.hpp"
#include "/addons/Vehicles/42nd_LAAT/cfgvehicles.hpp"
};
