
    class IDA_P2_Helmet;
    class HeadgearItem;
    class 42nd_Helmet_base: IDA_P2_Helmet
	{
		scope = 1;
        scopeArsenal = 1;
		ace_hearing_protection = 0.95;
		ace_hearing_lowervolume = 0.2;
        hiddenselections[] = {"Camo","visor"};
		class ItemInfo: HeadgearItem
		{
			mass = 10;
			uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Clone_P2_Helmet\IDA_Clone_P2_Helmet.p3d";
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
    class 42nd_CT_P2_Helmet: 42nd_Helmet_base
    {
		scope = 2;
        scopeArsenal = 2;
        author = "HoundaCivic";
        displayName = "42nd P2 Helmet";
        hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT\42nd_CT_Helmet.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT\42nd_CT_Helmet.paa"
            };
    };
	class 42nd_Medic_P2_Helmet: 42nd_Helmet_base
	{
		scope = 2;
		scopeArsenal = 2;
		author = "HoundaCivic";
		displayName = "42nd P2 Medic Helmet";
		hiddenSelectionsTextures[] = {
		"\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT_Medic\42nd_CT_Medic_Helmet_co.paa",
		"\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT_Medic\42nd_CT_Medic_Helmet_co.paa"
		};
	};



