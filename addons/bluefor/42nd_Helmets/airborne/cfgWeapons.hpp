    class IDA_AB_Helmet;
    class 42nd_Airborne_Base: IDA_AB_Helmet
    {
		scope = 1;
		author = "Hound";
        scopeArsenal = 1;
		ace_hearing_protection = 0.95;
		ace_hearing_lowervolume = 0.2;
		subItems[] = {""};
		hiddenselections[] = {"Camo","visor"};
		picture = "\Indecisive_Armoury_units\REPUBLIC\Clone_AB_Helmet\AB_Helmet_UI.paa";
		42nd_cloneHud = 1;
		42nd_hudVisorTexture = "\MRC\JLTS\characters\CloneArmor\data\ui\CloneHelmetAB_interior_ca.paa";
		
        class ItemInfo: HeadgearItem {
            uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Clone_AB_Helmet\IDA_Clone_AB_Helmet.p3d";
            hiddenselections[] = {"Camo","visor"};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=15;
					passThrough=0.1;
					explosiveShielding= 6;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=15;
					passThrough=0.1;
					explosiveShielding= 6;
				};
				class Neck
				{
					hitpointName = "HitNeck";
					armor=15;
					passThrough = 0.2; 
					explosiveShielding= 12; 
				};
			};
		};
	};
	class 42nd_Hound_AB_Helmet: 42nd_Airborne_Base
	{
		scope = 2;
		scopeArsenal = 2;
		displayname = "[42nd] Hound Airborne Helmet";
		hiddenSelectionsMaterials[] = {"","a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"};
		hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Helmets\airborne\42nd_Hound_AB_Helmet_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Helmets\airborne\42nd_Hound_AB_Helmet_co.paa"};
	};