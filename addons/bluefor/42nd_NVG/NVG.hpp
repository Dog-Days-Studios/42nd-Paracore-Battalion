class IDA_Clone_Rangefinder;
class IDA_Clone_NVG;
class IDA_Clone_NVG_flipped;
class lsd_gar_artilleryGunner_nvg;

class 42nd_NVG: IDA_Clone_NVG
{
	scope = 2;
	scopeArsenal = 2;
	author = "Hound";
	displayName = "[42nd] Macrobinoculars";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {
		"\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_NVG_Macrobinoculars_co.paa"
	};
};

class 42nd_NVG_flipped: IDA_Clone_NVG_flipped
{
	scope = 2;
	scopeArsenal = 2;
	author = "Hound";
	displayName = "[42nd] Macrobinoculars (On)";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {
		"\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_NVG_Macrobinoculars_co.paa"
	};
};

class 42nd_Rangefinder: IDA_Clone_Rangefinder
{
	scope = 2;
	scopeArsenal = 2;
	author = "Hound";
	displayName = "[42nd] Rangefinder";
	hiddenSelections[] = {"camo"};
	hiddenSelectionsTextures[] = {
		"\42nd_para\42nd\addons\bluefor\42nd_NVG\42nd_Rangefinder_co.paa"
	};
};

class 42nd_Tanker_Gunner: lsd_gar_artilleryGunner_nvg
{
	author = "Hound";
	displayName = "[612th] Crewman NVG";
	visionMode[] = {"Normal","NVG","TI"};
	hiddenSelections[] = {"camo1"};
	modelOptics = "\lsd_equipment_bluefor\nvg\gar\visor\swlb_clone_nvg_optic_dummy.p3d";
};
