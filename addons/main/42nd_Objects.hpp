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
    C42_RESUPPLY_BOX_COMMON
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
    C42_RESUPPLY_BOX_COMMON
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
    C42_RESUPPLY_BOX_COMMON
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

#undef C42_TRANSPORT_ITEM
#undef C42_TRANSPORT_MAGAZINE
#undef C42_RESUPPLY_BOX_COMMON
#undef C42_ARSENAL_USER_ACTIONS
