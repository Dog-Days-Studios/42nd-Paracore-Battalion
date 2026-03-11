class CfgPatches {
    class Aux_42nd {
        //requiredAddons[] = {"ace_common"};
        units[] = {
            "42nd_Trooper",
            "42nd_CPLTL_Trooper",
            "42nd_CSGT_Trooper",
            "42nd_CST_Trooper",
            "42nd_medic_Trooper",
            "42nd_CVT_Medic_Trooper",
            "42nd_Squad_Medic_Trooper",
            "42nd_Rose_Trooper",
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
            "42nd_CVT_P2_Helmet",
            "42nd_NCO_P2_Helmet",
            "42nd_Trainee_Pilot_Helmet",
            "42nd_WO1_Pilot_Helmet",
            "42nd_WO2_Pilot_Helmet",
            "42nd_WO3_Pilot_Helmet",
            "42nd_Trooper_Uniform",
            "42nd_CPLTL_Trooper_Uniform",
            "42nd_CSGT_Trooper_Uniform",
            "42nd_CST_Trooper_Uniform",
            "42nd_medic_Trooper_Uniform",
            "42nd_CVT_Medic_Trooper_Uniform",
            "42nd_Squad_Medic_Trooper_Uniform",
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
    class Sub42ndAirCrew
    {
        displayName = "Air Crew";
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
    class West
    {
        name = "BLUFOR";
        class Fac42nd
        {
            name = "[42nd] Paracore Battalion";
            class Infantry
            {
                name = "Infantry";
                class 42nd_Fireteam
                {
                    name = "[42nd] Fireteam";
                    side = 1;
                    faction = "Fac42nd";
                    class Unit0
                    {
                        side = 1;
                        vehicle = "42nd_CSGT_Trooper";
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "42nd_Trooper";
                        rank = "CORPORAL";
                        position[] = {5, -5, 0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "42nd_Trooper";
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Unit3
                    {
                        side = 1;
                        vehicle = "42nd_medic_Trooper";
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                };
                class 42nd_RifleSquad
                {
                    name = "[42nd] Rifle Squad";
                    side = 1;
                    faction = "Fac42nd";
                    class Unit0
                    {
                        side = 1;
                        vehicle = "42nd_CPLTL_Trooper";
                        rank = "LIEUTENANT";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "42nd_CSGT_Trooper";
                        rank = "SERGEANT";
                        position[] = {5, -5, 0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "42nd_CST_Trooper";
                        rank = "CORPORAL";
                        position[] = {-5, -5, 0};
                    };
                    class Unit3
                    {
                        side = 1;
                        vehicle = "42nd_Trooper";
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                    class Unit4
                    {
                        side = 1;
                        vehicle = "42nd_Trooper";
                        rank = "PRIVATE";
                        position[] = {-10, -10, 0};
                    };
                    class Unit5
                    {
                        side = 1;
                        vehicle = "42nd_Trooper";
                        rank = "PRIVATE";
                        position[] = {15, -15, 0};
                    };
                    class Unit6
                    {
                        side = 1;
                        vehicle = "42nd_medic_Trooper";
                        rank = "PRIVATE";
                        position[] = {-15, -15, 0};
                    };
                    class Unit7
                    {
                        side = 1;
                        vehicle = "42nd_CVT_Trooper";
                        rank = "PRIVATE";
                        position[] = {20, -20, 0};
                    };
                };
                class 42nd_MedicalTeam
                {
                    name = "[42nd] Medical Team";
                    side = 1;
                    faction = "Fac42nd";
                    class Unit0
                    {
                        side = 1;
                        vehicle = "42nd_Squad_Medic_Trooper";
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "42nd_medic_Trooper";
                        rank = "CORPORAL";
                        position[] = {5, -5, 0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "42nd_CVT_Medic_Trooper";
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                };
                class 42nd_CommandElement
                {
                    name = "[42nd] Command Element";
                    side = 1;
                    faction = "Fac42nd";
                    class Unit0
                    {
                        side = 1;
                        vehicle = "42nd_CPLTL_Trooper";
                        rank = "LIEUTENANT";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "42nd_CSGT_Trooper";
                        rank = "SERGEANT";
                        position[] = {5, -5, 0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "42nd_CVT_Trooper";
                        rank = "CORPORAL";
                        position[] = {-5, -5, 0};
                    };
                    class Unit3
                    {
                        side = 1;
                        vehicle = "42nd_NCO_Trooper";
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                };
            };
            class Air
            {
                name = "Air";
                class 42nd_Pilot_Element
                {
                    name = "[42nd] Pilot Element";
                    side = 1;
                    faction = "Fac42nd";
                    class Unit0
                    {
                        side = 1;
                        vehicle = "42nd_WO3_Pilot";
                        rank = "CAPTAIN";
                        position[] = {0, 0, 0};
                    };
                    class Unit1
                    {
                        side = 1;
                        vehicle = "42nd_WO2_Pilot";
                        rank = "LIEUTENANT";
                        position[] = {5, -5, 0};
                    };
                    class Unit2
                    {
                        side = 1;
                        vehicle = "42nd_WO1_Pilot";
                        rank = "SERGEANT";
                        position[] = {-5, -5, 0};
                    };
                    class Unit3
                    {
                        side = 1;
                        vehicle = "42nd_Trainee_Pilot";
                        rank = "CORPORAL";
                        position[] = {10, -10, 0};
                    };
                };
            };
        };
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
