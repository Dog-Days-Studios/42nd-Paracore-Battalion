class B_supplyCrate_F;

#define C42_RESUPPLY_BOX_COMMON \
    author = "Hound"; \
    scope = 2; \
    scopeEditor = 2; \
    scopeCurator = 2; \
    side = 1; \
    faction = "Fac42nd_INF"; \
    vehicleClass = "Ammo"; \
    editorCategory = "EdCat_42ndObjects"; \
    editorSubcategory = "SUB42ndOBJ";

    class ls_carrybox_base;
	class 42nd_Arsenal_Box: B_supplyCrate_F     // full arsenal box
	{
        author = "Hound";
        scopecurator = 2;
        displayName = "[42nd] Full Arsenal Box";
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
		class UserActions
		{
			class 42nd_Healstation_Heal
			{
				userActonID = 10; //Thank you SweMonkey for this code!
				displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Recieve Medical Attention</t>";
				radius = 15;
				priority = 100;
				onlyForPlayer=1;
				postition="";
				condition = "isNull objectParent player";
				statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
			};
			class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 11;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 1];";
			};
			class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 12;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 0];";
			};
			class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 1];";
			};
			class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 0];";
			};
			class 42nd_GiveEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 1];player setUnitTrait [""explosiveSpecialist"", 1];";
			};
			class 42nd_TakeEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 0];player setUnitTrait [""explosiveSpecialist"", 0];";
			};
			class 42nd_Arsenal: 42nd_Healstation_Heal
			{
				userActionIS = 15;
				displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>Ace Arsenal</t>";
				condition = "isNull objectParent player";
				statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
			};
		};
    };
	class 42nd_Arsenal_Supply: B_supplyCrate_F     // full arsenal box
	{
        author = "Hound";
        scopecurator = 2;
        displayName = "[42nd] Full Arsenal Supply Crate";
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
		class UserActions
		{
			class 42nd_Healstation_Heal
			{
				userActonID = 10; //Thank you SweMonkey for this code!
				displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Recieve Medical Attention</t>";
				radius = 15;
				priority = 100;
				onlyForPlayer=1;
				postition="";
				condition = "isNull objectParent player";
				statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
			};
			class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 11;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 1];";
			};
			class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 12;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 0];";
			};
			class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 1];";
			};
			class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 0];";
			};
			class 42nd_GiveEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 1];player setUnitTrait [""explosiveSpecialist"", 1];";
			};
			class 42nd_TakeEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 0];player setUnitTrait [""explosiveSpecialist"", 0];";
			};
			class 42nd_Arsenal: 42nd_Healstation_Heal
			{
				userActionIS = 15;
				displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>Ace Arsenal</t>";
				condition = "isNull objectParent player";
				statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
			};
		};
    };
    class 3as_Small_Box_9_Prop;
	class 42nd_Arsenal_Weapon_Crate: 3as_Small_Box_9_Prop     // full arsenal box
	{
        author = "Hound";
        scopecurator = 2;
        displayName = "[42nd] Full Arsenal Weapons Crate";
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
		class UserActions
		{
			class 42nd_Healstation_Heal
			{
				userActonID = 10; //Thank you SweMonkey for this code!
				displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Recieve Medical Attention</t>";
				radius = 15;
				priority = 100;
				onlyForPlayer=1;
				postition="";
				condition = "isNull objectParent player";
				statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
			};
			class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 11;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 1];";
			};
			class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
			{
				userActonID = 12;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
				statement = "player setUnitTrait [""medic"", 0];";
			};
			class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 1];";
			};
			class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""engineer "")";
				statement = "player setUnitTrait [""engineer"", 0];";
			};
			class 42nd_GiveEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 13;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
				condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 1];player setUnitTrait [""explosiveSpecialist"", 1];";
			};
			class 42nd_TakeEODPerms: 42nd_Healstation_Heal
			{
				userActonID = 14;
				displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
				condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist"")";
				statement = "player setUnitTrait [""engineer"", 0];player setUnitTrait [""explosiveSpecialist"", 0];";
			};
			class 42nd_Arsenal: 42nd_Healstation_Heal
			{
				userActionIS = 15;
				displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>Ace Arsenal</t>";
				condition = "isNull objectParent player";
				statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
			};
		};
    };

#define C42_TRANSPORT_MAGAZINE(CLASSNAME, AMMOCLASS, AMMOCOUNT) \
    class CLASSNAME \
    { \
        magazine = AMMOCLASS; \
        count = AMMOCOUNT; \
    };

#define C42_TRANSPORT_ITEM(CLASSNAME, ITEMCLASS, ITEMCOUNT) \
    class CLASSNAME \
    { \
        name = ITEMCLASS; \
        count = ITEMCOUNT; \
    };

class 42nd_Ammo_Resupply_Crate: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Ammo Resupply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_Rifle100,"42nd_Rifle_Cell_100Round_Blue",40)
        C42_TRANSPORT_MAGAZINE(C42_Rifle200,"42nd_Rifle_Cell_200Round_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_LMG250,"42nd_LMG_Cell_250Round_Blue",16)
        C42_TRANSPORT_MAGAZINE(C42_LMG500,"42nd_LMG_Cell_500Round_Blue",8)
        C42_TRANSPORT_MAGAZINE(C42_Pistol20,"42nd_Pistol_Cell_20Round_Blue",16)
        C42_TRANSPORT_MAGAZINE(C42_Sniper10,"42nd_Sniper_Cell_10Round_Blue",12)
        C42_TRANSPORT_MAGAZINE(C42_HEGL,"42nd_IDA_HEGL_Shell",10)
        C42_TRANSPORT_MAGAZINE(C42_GLBlue,"42nd_40mm_Blue",12)
        C42_TRANSPORT_MAGAZINE(C42_GLRed,"42nd_40mm_red",12)
        C42_TRANSPORT_MAGAZINE(C42_GLRedSmoke,"42nd_40mm_red_smoke",8)
        C42_TRANSPORT_MAGAZINE(C42_GLGreenSmoke,"42nd_40mm_green_smoke",8)
        C42_TRANSPORT_MAGAZINE(C42_GLOrangeSmoke,"42nd_40mm_orange_smoke",8)
        C42_TRANSPORT_MAGAZINE(C42_Grapple40,"42nd_40mm_Grapple",6)
        C42_TRANSPORT_MAGAZINE(C42_RPS6,"42nd_RPS_Extended_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_SmokeWhite,"42nd_Smoke_Grenade",10)
        C42_TRANSPORT_MAGAZINE(C42_SmokeBlue,"42nd_Smoke_Grenade_blue",6)
        C42_TRANSPORT_MAGAZINE(C42_SmokeRed,"42nd_Smoke_Grenade_Red",6)
        C42_TRANSPORT_MAGAZINE(C42_SmokeGreen,"42nd_Smoke_Grenade_Green",6)
        C42_TRANSPORT_MAGAZINE(C42_SmokeOrange,"42nd_Smoke_Grenade_Orange",6)
        C42_TRANSPORT_MAGAZINE(C42_SmokePurple,"42nd_Smoke_Grenade_Purple",6)
        C42_TRANSPORT_MAGAZINE(C42_SmokeYellow,"42nd_Smoke_Grenade_Yellow",6)
    };
};

class 42nd_Medical_Resupply_Crate: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Medical Resupply Crate";

    class TransportItems
    {
        C42_TRANSPORT_ITEM(C42_Bacta,"42nd_Bacta",40)
        C42_TRANSPORT_ITEM(C42_BactaRed,"42nd_Bacta_Red",20)
        C42_TRANSPORT_ITEM(C42_MedKit,"42nd_MedKit",8)
        C42_TRANSPORT_ITEM(C42_Plasma1500,"42nd_PlasmaIV_1500",8)
        C42_TRANSPORT_ITEM(C42_Plasma2000,"42nd_PlasmaIV_2000",4)
        C42_TRANSPORT_ITEM(C42_Tourniquet,"ACE_tourniquet",30)
        C42_TRANSPORT_ITEM(C42_Splint,"ACE_Splint",20)
        C42_TRANSPORT_ITEM(C42_Morphine,"ACE_morphine",20)
        C42_TRANSPORT_ITEM(C42_Epinephrine,"ACE_epinephrine",20)
        C42_TRANSPORT_ITEM(C42_Adenosine,"ACE_adenosine",10)
    };
};

class 42nd_Engineer_Resupply_Crate: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Engineer Resupply Crate";

    class TransportItems
    {
        C42_TRANSPORT_ITEM(C42_EntrenchingTool,"ACE_EntrenchingTool",6)
        C42_TRANSPORT_ITEM(C42_DefusalKit,"ACE_DefusalKit",4)
        C42_TRANSPORT_ITEM(C42_Clacker,"ACE_Clacker",4)
        C42_TRANSPORT_ITEM(C42_ToolKit,"ToolKit",2)
        C42_TRANSPORT_ITEM(C42_MineDetector,"MineDetector",2)
        C42_TRANSPORT_ITEM(C42_CableTie,"ACE_CableTie",20)
    };

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_DemoCharge,"DemoCharge_Remote_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_SatchelCharge,"SatchelCharge_Remote_Mag",2)
        C42_TRANSPORT_MAGAZINE(C42_Claymore,"ClaymoreDirectionalMine_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_SLAM,"SLAMDirectionalMine_Wire_Mag",4)
    };
};

class 42nd_Supply_Misc: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Misc Supply Crate";

    class TransportItems
    {
        C42_TRANSPORT_ITEM(C42_Deathstick,"JLTS_drugs_deathstick",20)
        C42_TRANSPORT_ITEM(C42_Electrolit,"JLTS_drugs_electrolit",20)
        C42_TRANSPORT_ITEM(C42_DrugBacta,"JLTS_drugs_bacta",20)
        C42_TRANSPORT_ITEM(C42_Kolto,"JLTS_drugs_kolto",20)
        C42_TRANSPORT_ITEM(C42_DrugMedikit,"JLTS_drugs_medikit",20)
        C42_TRANSPORT_ITEM(C42_DrugBactaRed,"JLTS_drugs_bacta_red",20)
        C42_TRANSPORT_ITEM(C42_Protein,"JLTS_drugs_protein",20)
        C42_TRANSPORT_ITEM(C42_StimAdrenal,"JLTS_drugs_stimulant_adrenal",15)
        C42_TRANSPORT_ITEM(C42_StimBattle,"JLTS_drugs_stimulant_battle",15)
        C42_TRANSPORT_ITEM(C42_StimEchani,"JLTS_drugs_stimulant_echaniBattle",15)
        C42_TRANSPORT_ITEM(C42_StimHyperAdr,"JLTS_drugs_stimulant_hyperAdrenal",15)
        C42_TRANSPORT_ITEM(C42_StimHyperBat,"JLTS_drugs_stimulant_hyperBattle",15)
        C42_TRANSPORT_ITEM(C42_ChalkBlack,"ACE_ChalkBlack",10)
        C42_TRANSPORT_ITEM(C42_ChalkBlue,"ACE_ChalkBlue",10)
        C42_TRANSPORT_ITEM(C42_ChalkGreen,"ACE_ChalkGreen",10)
        C42_TRANSPORT_ITEM(C42_ChalkRed,"ACE_ChalkRed",10)
        C42_TRANSPORT_ITEM(C42_ChalkWhite,"ACE_ChalkWhite",10)
        C42_TRANSPORT_ITEM(C42_ChalkYellow,"ACE_ChalkYellow",10)
    };
};

class 42nd_Supply_Medical: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Medical Supply Crate";

    class TransportItems
    {
        C42_TRANSPORT_ITEM(C42_SupBacta,"42nd_Bacta",40)
        C42_TRANSPORT_ITEM(C42_SupIV16,"kat_IV_16",20)
        C42_TRANSPORT_ITEM(C42_SupMedKit,"42nd_MedKit",10)
        C42_TRANSPORT_ITEM(C42_SupPlasma1500,"42nd_PlasmaIV_1500",10)
        C42_TRANSPORT_ITEM(C42_SupPlasma2000,"42nd_PlasmaIV_2000",6)
        C42_TRANSPORT_ITEM(C42_SupBactaRed,"42nd_Bacta_Red",20)
        C42_TRANSPORT_ITEM(C42_SupAccuvac,"kat_accuvac",6)
        C42_TRANSPORT_ITEM(C42_SupAdenosine,"ACE_adenosine",15)
        C42_TRANSPORT_ITEM(C42_SupAFAK,"kat_AFAK",20)
        C42_TRANSPORT_ITEM(C42_SupXAED,"kat_X_AED",4)
        C42_TRANSPORT_ITEM(C42_SupAmiodarone,"kat_amiodarone",15)
        C42_TRANSPORT_ITEM(C42_SupCarbonate,"kat_Carbonate",15)
        C42_TRANSPORT_ITEM(C42_SupAtropine,"kat_atropine",15)
        C42_TRANSPORT_ITEM(C42_SupAED,"kat_AED",4)
        C42_TRANSPORT_ITEM(C42_SupFieldDress,"ACE_fieldDressing",40)
        C42_TRANSPORT_ITEM(C42_SupElasticBand,"ACE_elasticBandage",40)
        C42_TRANSPORT_ITEM(C42_SupPackBand,"ACE_packingBandage",40)
        C42_TRANSPORT_ITEM(C42_SupQuikclot,"ACE_quikclot",40)
        C42_TRANSPORT_ITEM(C42_SupBasicDiag,"kat_basicDiagnostic",10)
        C42_TRANSPORT_ITEM(C42_SupBattleStim,"IDA_BattleStim",15)
        C42_TRANSPORT_ITEM(C42_SupBPCuff,"kat_BPCuff",6)
        C42_TRANSPORT_ITEM(C42_SupBVM,"kat_BVM",6)
        C42_TRANSPORT_ITEM(C42_SupChestSeal,"kat_chestSeal",15)
        C42_TRANSPORT_ITEM(C42_SupPainkiller,"kat_Painkiller",20)
        C42_TRANSPORT_ITEM(C42_SupEACA,"kat_EACA",15)
        C42_TRANSPORT_ITEM(C42_SupEpinephrine,"ACE_epinephrine",20)
        C42_TRANSPORT_ITEM(C42_SupIOFAST,"kat_IO_FAST",10)
        C42_TRANSPORT_ITEM(C42_SupFentanyl,"kat_fentanyl",15)
        C42_TRANSPORT_ITEM(C42_SupCauterizer,"IDA_Cauterizer",6)
        C42_TRANSPORT_ITEM(C42_SupGuedel,"kat_guedel",10)
        C42_TRANSPORT_ITEM(C42_SupLarynx,"kat_larynx",10)
        C42_TRANSPORT_ITEM(C42_SupMorphine,"ACE_morphine",20)
        C42_TRANSPORT_ITEM(C42_SupMFAK,"kat_MFAK",15)
        C42_TRANSPORT_ITEM(C42_SupNaloxone,"kat_naloxone",15)
        C42_TRANSPORT_ITEM(C42_SupPAK,"ACE_personalAidKit",10)
        C42_TRANSPORT_ITEM(C42_SupPlasmaIV,"ACE_plasmaIV",15)
        C42_TRANSPORT_ITEM(C42_SupPlasma250,"ACE_plasmaIV_250",15)
        C42_TRANSPORT_ITEM(C42_SupPlasma500,"ACE_plasmaIV_500",15)
        C42_TRANSPORT_ITEM(C42_SupPocketBVM,"kat_pocketBVM",10)
        C42_TRANSPORT_ITEM(C42_SupPulseOx,"kat_Pulseoximeter",6)
        C42_TRANSPORT_ITEM(C42_SupSplint,"ACE_splint",20)
        C42_TRANSPORT_ITEM(C42_SupSurgKit,"ACE_surgicalKit",6)
        C42_TRANSPORT_ITEM(C42_SupTourniquet,"ACE_tourniquet",30)
        C42_TRANSPORT_ITEM(C42_SupTXA,"kat_TXA",15)
    };
};

class 42nd_Supply_Tools: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Tools Supply Crate";

    class TransportItems
    {
        C42_TRANSPORT_ITEM(C42_TlDAGR,"ACE_DAGR",4)
        C42_TRANSPORT_ITEM(C42_TlDeadMan,"ACE_DeadManSwitch",4)
        C42_TRANSPORT_ITEM(C42_TlDefKit,"ACE_DefusalKit",6)
        C42_TRANSPORT_ITEM(C42_TlEntrench,"ACE_EntrenchingTool",6)
        C42_TRANSPORT_ITEM(C42_TlHuntIR,"ACE_HuntIR_monitor",4)
        C42_TRANSPORT_ITEM(C42_TlFlashMX,"ACE_Flashlight_MX991",10)
        C42_TRANSPORT_ITEM(C42_TlFortify,"ACE_Fortify",4)
        C42_TRANSPORT_ITEM(C42_TlM26,"ACE_M26_Clacker",4)
        C42_TRANSPORT_ITEM(C42_TlClacker,"ACE_Clacker",4)
        C42_TRANSPORT_ITEM(C42_TlFlashXL,"ACE_Flashlight_XL50",10)
        C42_TRANSPORT_ITEM(C42_TlMapTools,"ACE_MapTools",6)
        C42_TRANSPORT_ITEM(C42_TlMicroDAGR,"ACE_microDAGR",6)
        C42_TRANSPORT_ITEM(C42_TlMineDet,"MineDetector",4)
        C42_TRANSPORT_ITEM(C42_TlWirecut,"ACE_wirecutter",6)
    };
};

class 42nd_Supply_Explosives: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Explosives Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_ExDetPack,"3AS_DetPack",6)
        C42_TRANSPORT_MAGAZINE(C42_ExEC01,"EC01_RemoteMagazine",6)
        C42_TRANSPORT_MAGAZINE(C42_ExHXAT,"HX_AT_Mine_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExRTX,"RTX_RemoteMagazine",6)
        C42_TRANSPORT_MAGAZINE(C42_ExAPERSDisp,"APERSMineDispenser_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExBreachCh,"ls_explosive_breachCharge_magazine",6)
        C42_TRANSPORT_MAGAZINE(C42_ExC7,"C7_Remote_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExC12,"C12_Remote_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExCaltrops,"ls_explosive_caltropsDispenser_magazine",4)
        C42_TRANSPORT_MAGAZINE(C42_ExDemo,"ls_explosive_demoCharge_magazine",6)
        C42_TRANSPORT_MAGAZINE(C42_ExLsDet,"ls_explosive_detpack_magazine",6)
        C42_TRANSPORT_MAGAZINE(C42_ExIDADet,"IDA_explosive_Detpack_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExIDADet2,"IDA_explosive_Detpack2_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExEMP10,"JLTS_explosive_emp_10_mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExEMP20,"JLTS_explosive_emp_20_mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExEMP50,"JLTS_explosive_emp_50_mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExIEDLand,"IEDLandBig_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExIEDUrban,"IEDUrbanBig_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExDemoCh,"DemoCharge_Remote_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExATMine,"ATMine_Range_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExM168,"M168_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExSatchel,"SatchelCharge_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExClaymore,"ClaymoreDirectionalMine_Remote_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_ExAPERSBound,"APERSBoundingMine_Range_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExM41C,"M41_IED_C_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExM41,"M41_IED_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExM41B,"M41_IED_B_Remote_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExSLAM,"SLAMDirectionalMine_Wire_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExAPERS,"APERSMine_Range_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_ExToePop,"ACE_APERSMine_ToePopper_Mag",4)
    };
};

class 42nd_Supply_Grenades: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Grenade Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_GrBaridum,"3AS_BaridumCore",10)
        C42_TRANSPORT_MAGAZINE(C42_GrLumaBlue,"Luma_Blue",10)
        C42_TRANSPORT_MAGAZINE(C42_GrLumaGreen,"Luma_Green",10)
        C42_TRANSPORT_MAGAZINE(C42_GrLumaRed,"Luma_Red",10)
        C42_TRANSPORT_MAGAZINE(C42_GrLumaYellow,"Luma_Yellow",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeBlue,"3AS_SmokeBlue",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeGreen,"3AS_SmokeGreen",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeOrange,"3AS_SmokeOrange",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokePurple,"3AS_SmokePurple",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeRed,"3AS_SmokeRed",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeWhite,"3AS_SmokeWhite",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmokeYellow,"3AS_SmokeYellow",8)
        C42_TRANSPORT_MAGAZINE(C42_GrShield,"ShieldGrenade_Mag",4)
        C42_TRANSPORT_MAGAZINE(C42_GrSonicDet,"3AS_SonicDet",6)
        C42_TRANSPORT_MAGAZINE(C42_GrSquadShield,"SquadShieldMagazine",4)
        C42_TRANSPORT_MAGAZINE(C42_GrThermDet,"3AS_ThermalDetonator",8)
        C42_TRANSPORT_MAGAZINE(C42_GrThrowCharge,"3AS_ThrowableCharge",6)
        C42_TRANSPORT_MAGAZINE(C42_GrTXA,"42nd_TXAGas_Grenade",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkBlue42,"42nd_Smoke_Grenade_blue",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkGreen42,"42nd_Smoke_Grenade_Green",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkOrange42,"42nd_Smoke_Grenade_Orange",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkPurple42,"42nd_Smoke_Grenade_Purple",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkRed42,"42nd_Smoke_Grenade_Red",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkWhite42,"42nd_Smoke_Grenade",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkYellow42,"42nd_Smoke_Grenade_Yellow",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSonicIDA,"IDA_grenade_Sonic_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrCTS9,"ACE_CTS9",8)
        C42_TRANSPORT_MAGAZINE(C42_GrEMP,"JLTS_grenade_emp_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_GrHandFlrGreen,"ACE_HandFlare_Green",8)
        C42_TRANSPORT_MAGAZINE(C42_GrHandFlrRed,"ACE_HandFlare_Red",8)
        C42_TRANSPORT_MAGAZINE(C42_GrHandFlrWhite,"ACE_HandFlare_White",8)
        C42_TRANSPORT_MAGAZINE(C42_GrHandFlrYel,"ACE_HandFlare_Yellow",8)
        C42_TRANSPORT_MAGAZINE(C42_GrHand,"HandGrenade",15)
        C42_TRANSPORT_MAGAZINE(C42_GrN20,"ls_grenade_n20_magazine",10)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkIDABlue,"IDA_grenade_Smoke_Blue_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkIDAGreen,"IDA_grenade_Smoke_Green_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkIDAPurple,"IDA_grenade_Smoke_Purple_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkIDARed,"IDA_grenade_Smoke_Red_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrSmkIDA,"IDA_grenade_Smoke_mag",8)
        C42_TRANSPORT_MAGAZINE(C42_GrDetIDA,"IDA_grenade_Detonator_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_GrThermA,"ls_grenade_thermalDetClassA_magazine",8)
        C42_TRANSPORT_MAGAZINE(C42_GrThermB,"ls_grenade_thermalDetClassB_magazine",8)
        C42_TRANSPORT_MAGAZINE(C42_GrThermC,"ls_grenade_thermalDetClassC_magazine",8)
        C42_TRANSPORT_MAGAZINE(C42_GrImploder,"IDA_grenade_Imploder_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_GrPenetrator,"IDA_grenade_Penetrator_mag",6)
    };
};

class 42nd_Supply_Mags_42ndCells: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] 42nd Weapon Cells Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_MgPistol10,"42nd_Pistol_Cell_10Round_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_MgPistol15,"42nd_Pistol_Cell_15Round_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_MgPistol20,"42nd_Pistol_Cell_20Round_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_MgSniper10,"42nd_Sniper_Cell_10Round_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_MgSniper15,"42nd_Sniper_Cell_15Round_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_MgSniper20,"42nd_Sniper_Cell_20Round_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_MgRifle100,"42nd_Rifle_Cell_100Round_Blue",30)
        C42_TRANSPORT_MAGAZINE(C42_MgRifle150,"42nd_Rifle_Cell_150Round_Blue",25)
        C42_TRANSPORT_MAGAZINE(C42_MgRifle200,"42nd_Rifle_Cell_200Round_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_MgLMG250,"42nd_LMG_Cell_250Round_Blue",16)
        C42_TRANSPORT_MAGAZINE(C42_MgLMG500,"42nd_LMG_Cell_500Round_Blue",10)
        C42_TRANSPORT_MAGAZINE(C42_MgLMG750,"42nd_LMG_Cell_750Round_Blue",8)
        C42_TRANSPORT_MAGAZINE(C42_MgLMG1000,"42nd_LMG_Cell_1000Round_Blue",6)
    };
};

class 42nd_Supply_Mags_GL: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Grenade Launcher Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_MgGL40Blue,"42nd_40mm_Blue",12)
        C42_TRANSPORT_MAGAZINE(C42_MgGL40Red,"42nd_40mm_red",12)
        C42_TRANSPORT_MAGAZINE(C42_MgGL40SmkGreen,"42nd_40mm_green_smoke",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL40SmkOrange,"42nd_40mm_orange_smoke",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL40SmkRed,"42nd_40mm_red_smoke",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLHEGL,"42nd_IDA_HEGL_Shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLGrapple,"42nd_40mm_Grapple",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3HE,"3Rnd_HE_Grenade_shell",12)
        C42_TRANSPORT_MAGAZINE(C42_MgGL1HE,"1Rnd_HE_Grenade_shell",12)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDAHE,"IDA_HE_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDAHERifle,"IDA_HE_RifleGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDASmk,"IDA_Smoke_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDASmkBlue,"IDA_SmokeBlue_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDASmkGreen,"IDA_SmokeGreen_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDASmkPurple,"IDA_SmokePurple_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLIDASmkRed,"IDA_SmokeRed_LauncherGrenade",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLLsG75,"ls_magazine_3Rnd_40mw_G75_HE",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLLsG76,"ls_magazine_3Rnd_40mw_G76_HEF",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGLLsIM973B,"ls_magazine_2Rnd_40mw_IM973B",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1AP,"3AS_1UGL_MK54_AP_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1HE,"3AS_1UGL_MK54_HE_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3AP,"3AS_3UGL_MK54_AP_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3HE,"3AS_3UGL_MK54_HE_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1APGr,"3AS_1Rnd_AP_Grenade_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3APGr,"3AS_3Rnd_AP_Grenade_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS6HE,"3AS_6Rnd_HE_Grenade_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkBlu,"3AS_1UGL_MK55_Smoke_Blue_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkGrn,"3AS_1UGL_MK55_Smoke_Green_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkOrn,"3AS_1UGL_MK55_Smoke_Orange_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkPur,"3AS_1UGL_MK55_Smoke_Purple_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkRed,"3AS_1UGL_MK55_Smoke_Red_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkWht,"3AS_1UGL_MK55_Smoke_White_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS1SmkYel,"3AS_1UGL_MK55_Smoke_Yellow_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkBlu,"3AS_3UGL_MK55_Smoke_Blue_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkGrn,"3AS_3UGL_MK55_Smoke_Green_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkOrn,"3AS_3UGL_MK55_Smoke_Orange_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkPur,"3AS_3UGL_MK55_Smoke_Purple_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkRed,"3AS_3UGL_MK55_Smoke_Red_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkWht,"3AS_3UGL_MK55_Smoke_White_shell",8)
        C42_TRANSPORT_MAGAZINE(C42_MgGL3AS3SmkYel,"3AS_3UGL_MK55_Smoke_Yellow_shell",8)
    };
};

class 42nd_Supply_Mags_Flares: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Flares Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_FlrGreen,"FlareGreen_F",15)
        C42_TRANSPORT_MAGAZINE(C42_FlrRed,"FlareRed_F",15)
        C42_TRANSPORT_MAGAZINE(C42_FlrWhite,"FlareWhite_F",15)
        C42_TRANSPORT_MAGAZINE(C42_FlrYellow,"FlareYellow_F",15)
        C42_TRANSPORT_MAGAZINE(C42_UFlrGreen,"UGL_FlareGreen_F",12)
        C42_TRANSPORT_MAGAZINE(C42_UFlrCIR,"UGL_FlareCIR_F",12)
        C42_TRANSPORT_MAGAZINE(C42_UFlrRed,"UGL_FlareRed_F",12)
        C42_TRANSPORT_MAGAZINE(C42_UFlrWhite,"UGL_FlareWhite_F",12)
        C42_TRANSPORT_MAGAZINE(C42_UFlrYellow,"UGL_FlareYellow_F",12)
        C42_TRANSPORT_MAGAZINE(C42_3ASFlrGreen,"3AS_3UGL_MK56_Flare_Green_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_3ASFlrRed,"3AS_3UGL_MK56_Flare_Red_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_3ASFlrWhite,"3AS_3UGL_MK56_Flare_White_shell",10)
        C42_TRANSPORT_MAGAZINE(C42_3ASFlrYellow,"3AS_3UGL_MK56_Flare_Yellow_shell",10)
    };
};

class 42nd_Supply_Mags_Rockets: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] Rockets & Heavy Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_RkRPS,"42nd_RPS_Extended_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_RkFuel,"IDA_FuelTank",6)
        C42_TRANSPORT_MAGAZINE(C42_RkPLX1,"IDA_PLX1_Rocket",6)
        C42_TRANSPORT_MAGAZINE(C42_RkStunCell,"IDA_Stun_Cell",10)
        C42_TRANSPORT_MAGAZINE(C42_RkAntiArm,"3AS_AntiArmour_mag",6)
        C42_TRANSPORT_MAGAZINE(C42_RkDWAT,"3AS_DWRockets_AT",6)
        C42_TRANSPORT_MAGAZINE(C42_RkFlamer,"3AS_FlamerFuel",6)
        C42_TRANSPORT_MAGAZINE(C42_RkStun,"3AS_5Rnd_Stun_Mag",8)
        C42_TRANSPORT_MAGAZINE(C42_RkMortar,"ls_5Rnd_82mm_mortar_HE_csw",6)
        C42_TRANSPORT_MAGAZINE(C42_RkCSW30mw,"ls_magazine_30mw_500Rnd_blue_csw",4)
    };
};

class 42nd_Supply_Mags_IDA: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] IDA Blaster Cells Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_IDAP2_100,"IDA_Blaster_Cell_Power2_100Rnd_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_IDAP4_10,"IDA_Blaster_Cell_Power4_10Rnd_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_IDAP5_120,"IDA_Blaster_Cell_Power5_120Rnd_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_IDAP2_20,"IDA_Blaster_Cell_Power2_20Rnd_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_IDAP1_300,"IDA_Blaster_Cell_Power1_300Rnd_Blue",10)
        C42_TRANSPORT_MAGAZINE(C42_IDAP3_40,"IDA_Blaster_Cell_Power3_40Rnd_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_IDAP5_5,"IDA_Blaster_Cell_Power5_5Rnd_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_IDAP3_60,"IDA_Blaster_Cell_Power3_60Rnd_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_IDAClipP2_60,"IDA_Blaster_Clip_Power2_60Rnd_Blue",20)
        C42_TRANSPORT_MAGAZINE(C42_IDAScatter,"IDA_Blaster_Cell_Scatter_6Rnd_Blue",15)
        C42_TRANSPORT_MAGAZINE(C42_IDAClipGr,"IDA_Blaster_Clip_Grenade",10)
        C42_TRANSPORT_MAGAZINE(C42_IDALaserBat,"Laserbatteries",10)
        C42_TRANSPORT_MAGAZINE(C42_IDAZ6,"JLTS_Z6_mag",8)
    };
};

class 42nd_Supply_Mags_LS: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] LS Weapon Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_Ls22mw,"ls_magazine_22mw_15Rnd_blue",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc15a,"ls_magazine_dc15a",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc15br,"ls_magazine_dc15br",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc15s,"ls_magazine_dc15s",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc15sa,"ls_magazine_dc15sa",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc15x,"ls_magazine_dc15x",15)
        C42_TRANSPORT_MAGAZINE(C42_LsDc17mAA,"ls_magazine_dc17m_antiArmor",10)
        C42_TRANSPORT_MAGAZINE(C42_LsDc17m,"ls_magazine_dc17m",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDc17mSn,"ls_magazine_dc17m_sniper",15)
        C42_TRANSPORT_MAGAZINE(C42_LsDc17s,"ls_magazine_dc17s",20)
        C42_TRANSPORT_MAGAZINE(C42_LsDp20Slug,"ls_magazine_dp20_slug",15)
        C42_TRANSPORT_MAGAZINE(C42_LsDp20,"ls_magazine_dp20",15)
        C42_TRANSPORT_MAGAZINE(C42_LsFire,"ls_magazine_firepuncher",10)
        C42_TRANSPORT_MAGAZINE(C42_LsValken,"ls_magazine_valken",15)
        C42_TRANSPORT_MAGAZINE(C42_LsZ6,"ls_magazine_z6",10)
        C42_TRANSPORT_MAGAZINE(C42_LsWestar,"ls_magazine_westarM5",15)
    };
};

class 42nd_Supply_Mags_3AS: B_supplyCrate_F
{
		editorCategory = "EdCat_42ndObjects";
        editorSubcategory = "SUB42ndOBJ";
    displayName = "[42nd] 3AS EC Magazines Supply Crate";

    class TransportMagazines
    {
        C42_TRANSPORT_MAGAZINE(C42_3AS10EC100,"3AS_10Rnd_EC100_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS10DLT19X,"3AS_10Rnd_EC100_DLT19X_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS10EC80,"3AS_10Rnd_EC80_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS100EC40,"3AS_100Rnd_EC40_mag",10)
        C42_TRANSPORT_MAGAZINE(C42_3AS15EC30,"3AS_15Rnd_EC30_mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS15SE14R,"3AS_15Rnd_EC20_SE14R_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS16EC20,"3AS_16Rnd_EC20_Mag",20)
        C42_TRANSPORT_MAGAZINE(C42_3AS18RK3,"3AS_18Rnd_EC20_RK3_Mag",20)
        C42_TRANSPORT_MAGAZINE(C42_3AS200EC40,"3AS_200Rnd_EC40_Mag",8)
        C42_TRANSPORT_MAGAZINE(C42_3AS200DLT19,"3AS_200Rnd_EC40_DLT19_Mag",8)
        C42_TRANSPORT_MAGAZINE(C42_3AS300EC60,"3AS_300Rnd_EC60_Mag",6)
        C42_TRANSPORT_MAGAZINE(C42_3AS32Dual,"3AS_32Rnd_EC20_Dual_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS40EC40,"3AS_40Rnd_EC40_Mag",20)
        C42_TRANSPORT_MAGAZINE(C42_3AS40E11,"3AS_40Rnd_EC40_E11_Mag",20)
        C42_TRANSPORT_MAGAZINE(C42_3AS45EC50,"3AS_45Rnd_EC50_Mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS5EC80,"3AS_5Rnd_EC80_mag",15)
        C42_TRANSPORT_MAGAZINE(C42_3AS60EC30,"3AS_60Rnd_EC30_mag",12)
        C42_TRANSPORT_MAGAZINE(C42_3AS60EC50,"3AS_60Rnd_EC50_Mag",12)
    };
};

#undef C42_TRANSPORT_ITEM
#undef C42_TRANSPORT_MAGAZINE
#undef C42_RESUPPLY_BOX_COMMON
