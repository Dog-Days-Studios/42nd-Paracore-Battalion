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
            "42nd_Walker_Trooper",
            "42nd_CVT_Trooper",
            "42nd_NCO_Trooper",
            "42nd_EOD_Trooper",
            "42nd_EOD_Vet_Trooper",
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
            "42nd_Walker_P2_Helmet",
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
            "42nd_Walker_Trooper_Uniform",
            "42nd_CVT_Trooper_Uniform",
            "42nd_NCO_Trooper_Uniform",
            "42nd_EOD_Trooper_Uniform",
            "42nd_EOD_Vet_Trooper_Uniform",
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
            "42nd_EOD_P2_Helmet",
            "42nd_EOD_Vet_Helmet",
            "42nd_RPS6",
            "42nd_ls_weapon_dc15ac",
            "42nd_ls_weapon_dc15br_wooden",
            "42nd_ls_weapon_dc15br",
            "42nd_ls_weapon_dc15s",
            "42nd_3AS_DC15A_F",
            "42nd_3AS_DC15C_F",
            "42nd_3AS_DC15S_F",
            "42nd_DLT15",
            "42nd_DLT19",
            "42nd_DLT19D",
            "42nd_Z6",
            "42nd_JLTS_Z6",
            "42nd_ls_weapon_z6",
            "42nd_3AS_DLT19",
            "42nd_DC15S_UGL",
            "42nd_DC15LE",
            "42nd_JLTS_DC15A_ugl_plastic",
            "42nd_JLTS_DC15A_ugl",
            "42nd_3AS_DC15A_GL",
            "42nd_3AS_DC15C_GL",
            "42nd_3AS_DC15S_GL",
            "42nd_3AS_DP23_GL",
            "42nd_DC15P",
            "42nd_DC17",
            "42nd_ls_weapon_dc15sa",
            "42nd_ls_weapon_dc17s",
            "42nd_ls_weapon_dc17s_dual",
            "42nd_3AS_DC17S_F",
            "42nd_3AS_DC17S_Dual_F",
            "42nd_3AS_FusionCutter_F"
        };
        magazines[] = {
        };
        ammo[] = {
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
class Mode_SemiAuto;

class CBA_DisposableLaunchers

{

	IDA_RPS6_Base[] = {"IDA_RPS6_Disposable","IDA_RPS6_Used"};

};
class CfgWeapons
{
#include "/addons/Bluefor/42nd_Helmets/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Vests/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Uniforms/cfgWeapons.hpp"
#include "/addons/Bluefor/42nd_Weapons/Weapons/Weapon.hpp"
};
class CfgVehicles
{
#include "/addons/Bluefor/42nd_Uniforms/cfgVehicles.hpp"
#include "/addons/main/42nd_Objects.hpp"
#include "/addons/Vehicles/42nd_Gozanti/cfgvehicles.hpp"
#include "/addons/Vehicles/42nd_LAAT/cfgvehicles.hpp"
};
class CfgAmmo
{
#include "/addons/Bluefor/42nd_Weapons/Ammo/Ammo.hpp"
};
class CfgMagazines
{
    #include "/addons/Bluefor/42nd_Weapons/Ammo/cfgMagazines.hpp"
};
class CfgMagazineWells
{
    #include "/addons/Bluefor/42nd_Weapons/Ammo/cfgMagazineWells.hpp"
};
