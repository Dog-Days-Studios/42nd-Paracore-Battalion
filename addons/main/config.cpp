class CfgPatches {
	class Aux_42nd {
		//requiredAddons[] = {"ace_common"};
		units[] = {"42nd_Trooper","42nd_medic_Trooper"};
		weapons[] ={"42nd_Medic_P2_Helmet","42nd_CT_P2_Helmet","42nd_Trooper_Uniform","42nd_medic_Trooper_Uniform"};
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
        displayName="[42nd] Objects";
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
//#include /addons/42nd_Bluefor/42nd_backpacks/42nd_backpacks.hpp
//#include /addons/42nd_Bluefor/42nd_Weapons/42nd_weapons.hpp
};

