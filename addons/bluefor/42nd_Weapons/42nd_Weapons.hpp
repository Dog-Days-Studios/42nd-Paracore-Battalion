	class NVGoggles;
	class InventoryOpticsItem_Base_F;
	class optic_lrps;
	class UGL_F;
	class ItemCore;
	class WeaponSlotsInfo;
	class Launcher_Base_F;
	class Pistol_Base_F;
	class 3as_Valken38x_F;
	class 3AS_DC15C_F;
	class IDA_DC15S;
	class IDA_DC15A;
	class IDA_RPS6_Base;
	class IDA_RPS6HP;
	class IDA_773Firepuncher;
	class IDA_Z6;
	class IDA_DC15S_UGL;
	class EGLM;
	class IDA_DC15X;
	class IDA_DLT15;
	class JLTS_DC15X;
	class JLTS_stun_muzzle;
	class IDA_DC15S_UGL_Shield;
	class weapon_Cannon_Phalanx;
	class ls_weapon_CMFlareLauncher;
	class IDA_T15;
	class launch_RPG7_F;
	class 3AS_HH12_F;
	class launch_RPG32_F: Launcher_Base_F
	{
		class WeaponSlotsInfo;
	};
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class launch_B_Titan_Short_F;
	class 42nd_HH12: 3AS_HH12_F
	{
		scope = 2;
		displayName = "[42nd] HH12 Rocket Launcher";
		baseWeapon = "42nd_HH12";
	};
	class 42nd_CIWIS_Cannon: weapon_Cannon_Phalanx
	{
		scope = 1;
		displayName = "CIS CWIS Cannon";
		magazines[] = {"42nd_CIWIS_Magazine"};
		baseWeapon = "42nd_CIWIS_Cannon";
	};
	class 42nd_weapon_CMFlareLauncher: ls_weapon_CMFlareLauncher
	{
		magazines[] = {"60Rnd_CMFlareMagazine","120Rnd_CMFlareMagazine","240Rnd_CMFlareMagazine","60Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine",
		"240Rnd_CMFlare_Chaff_Magazine","192Rnd_CMFlare_Chaff_Magazine","168Rnd_CMFlare_Chaff_Magazine","300Rnd_CMFlare_Chaff_Magazine","ls_mag_60rnd_CMFlare_red",
		"ls_mag_120rnd_CMFlare_red","ls_mag_240rnd_CMFlare_red","ls_mag_60rnd_CMFlareChaff_red","ls_mag_120rnd_CMFlareChaff_red","ls_mag_168rnd_CMFlareChaff_red",
		"ls_mag_192rnd_CMFlareChaff_red","ls_mag_240rnd_CMFlareChaff_red","ls_mag_300rnd_CMFlareChaff_red","ls_mag_60rnd_CMFlare_yellow","ls_mag_120rnd_CMFlare_yellow",
		"ls_mag_240rnd_CMFlare_yellow","ls_mag_60rnd_CMFlareChaff_yellow","ls_mag_120rnd_CMFlareChaff_yellow","ls_mag_168rnd_CMFlareChaff_yellow","ls_mag_192rnd_CMFlareChaff_yellow",
		"ls_mag_240rnd_CMFlareChaff_yellow","ls_mag_300rnd_CMFlareChaff_yellow","ls_mag_60rnd_CMFlare_green","ls_mag_120rnd_CMFlare_green","ls_mag_240rnd_CMFlare_green","ls_mag_60rnd_CMFlareChaff_green",
		"ls_mag_120rnd_CMFlareChaff_green","ls_mag_168rnd_CMFlareChaff_green","ls_mag_192rnd_CMFlareChaff_green","ls_mag_240rnd_CMFlareChaff_green","ls_mag_300rnd_CMFlareChaff_green",
		"ls_mag_60rnd_CMFlare_blue","ls_mag_120rnd_CMFlare_blue","ls_mag_240rnd_CMFlare_blue","ls_mag_60rnd_CMFlareChaff_blue","ls_mag_120rnd_CMFlareChaff_blue","ls_mag_168rnd_CMFlareChaff_blue",
		"ls_mag_192rnd_CMFlareChaff_blue","ls_mag_240rnd_CMFlareChaff_blue","ls_mag_300rnd_CMFlareChaff_blue","ls_mag_60rnd_CMFlare_cyan","ls_mag_120rnd_CMFlare_cyan","ls_mag_240rnd_CMFlare_cyan",
		"ls_mag_60rnd_CMFlareChaff_cyan","ls_mag_120rnd_CMFlareChaff_cyan","ls_mag_168rnd_CMFlareChaff_cyan","ls_mag_192rnd_CMFlareChaff_cyan","ls_mag_240rnd_CMFlareChaff_cyan","ls_mag_300rnd_CMFlareChaff_cyan",
		"ls_mag_60rnd_CMFlare_purple","ls_mag_120rnd_CMFlare_purple","ls_mag_240rnd_CMFlare_purple","ls_mag_60rnd_CMFlareChaff_purple","ls_mag_120rnd_CMFlareChaff_purple","ls_mag_168rnd_CMFlareChaff_purple",
		"ls_mag_192rnd_CMFlareChaff_purple","ls_mag_240rnd_CMFlareChaff_purple","ls_mag_300rnd_CMFlareChaff_purple"};
	};
	class 42nd_Stun_Muzzle: JLTS_stun_muzzle
    {
        aiDispersionCoefX=2;
        aiDispersionCoefY=2;
        autoFire=0;
        ballisticsComputer=0;
        discreteDistance[]={50};
        discreteDistanceInitIndex=0;
        displayName="Stun";
        drySound[]=
        {
            "MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
            5,
            1,
            10
        };
        fireSpreadAngle=0.94999999;
        magazines[]=
        {
            "42nd_Stun_mag"
        };
        magazineWell[]={};
        maxZeroing=50;
        reloadAction = "ReloadMagazine";
        reloadMagazineSound[] = {"swlw_rework\sounds\dc\15\DC15A_reload.wss",0.562341,1,30};
        modes[]=
        {
            "Single"
        };
        class Single: Mode_SemiAuto
        {
            sounds[]=
            {
                "StandardSound"
            };
            class BaseSoundModeType
            {
                weaponSoundEffect="";
                closure1[]={};
                closure2[]={};
                soundClosure[]={};
            };
            class StandardSound: BaseSoundModeType
            {
                weaponSoundEffect="";
                begin1[]=
                {
                    "MRC\JLTS\weapons\DC17SA\sounds\dc17sa_fire_2",
                    3,
                    0.89999998,
                    1800
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
            };
            reloadTime=0.5;
            dispersion=2.9e-006;
            minRange=10;
            minRangeProbab=0.30000001;
            midRange=400;
            midRangeProbab=0.60000002;
            maxRange=1000;
            maxRangeProbab=0.1;
            aiRateOfFire=2;
            aiRateOfFireDistance=25;
        };
    };
	class 42nd_GL_Muzzle: JLTS_stun_muzzle
    {
        aiDispersionCoefX=2;
        aiDispersionCoefY=2;
        autoFire=0;
        ballisticsComputer=0;
        discreteDistance[]={50};
        discreteDistanceInitIndex=0;
        displayName="Grenade Launcher";
        drySound[]=
        {
            "MRC\JLTS\weapons\Core\sounds\weapon_dry.wss",
            5,
            1,
            10
        };
        fireSpreadAngle=0.94999999;
        magazineWell[] = {"42nd_GL_Magwell"};
        maxZeroing=500;
        reloadAction = "ReloadMagazine";
        reloadMagazineSound[] = {"swlw_rework\sounds\dc\15\DC15A_reload.wss",0.562341,1,30};
        modes[]=
        {
            "Single"
        };
        class Single: Mode_SemiAuto
        {
            sounds[]=
            {
                "StandardSound"
            };
            class BaseSoundModeType
            {
                weaponSoundEffect="";
                closure1[]={};
                closure2[]={};
                soundClosure[]={};
            };
            class StandardSound: BaseSoundModeType
            {
                weaponSoundEffect="";
                begin1[]=
                {
                    "MRC\JLTS\weapons\DC17SA\sounds\dc17sa_fire_2",
                    3,
                    0.89999998,
                    1800
                };
                soundBegin[]=
                {
                    "begin1",
                    1
                };
            };
            reloadTime=0.5;
            dispersion=2.9e-006;
            minRange=10;
            minRangeProbab=0.30000001;
            midRange=400;
            midRangeProbab=0.60000002;
            maxRange=1000;
            maxRangeProbab=0.1;
            aiRateOfFire=2;
            aiRateOfFireDistance=25;
        };
    };
	class 42nd_RPS6: IDA_RPS6HP
	{
		author="Hound";
		canShootInWater=1;
		displayname="[42nd] RPS-6 Launcher";
		scope = 2;
		magazineWell[] = {"42nd_RPS_MagWell"};
		baseweapon = "42nd_RPS6";
	};
    class 42nd_DC15S: IDA_DC15S
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		
		displayName = "[42nd] DC-15S Carbine";
		magazines[] = {"42nd_blaster_cell"};
		magazineWell[] = {};
		muzzles[]= { "this", "Stun"};
		baseweapon= "42nd_DC15S";
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_Imp_Optic_1"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_DC15S_UGL: IDA_DC15S_UGL
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		IDA_AltWeapon = "42nd_DC15s_UGL_Shield";
		IDA_AltWeaponItem = "IDA_Shield_Rep_item";
		IDA_AltWeaponSwap = "false";
		IDA_SwitchText = "Swapping Shield";
		displayName = "[42nd] DC-15S Carbine (UGL)";
		magazines[] = {"42nd_blaster_cell"};
		magazineWell[] = {"42nd_Blaster_Magwell"};
		muzzles[]= { "this", "Grenade_Launcher"};
		baseweapon= "42nd_DC15S_UGL";
		class Grenade_Launcher: 42nd_GL_Muzzle
		{

			magazines[] = {"IDA_HE_LauncherGrenade", "IDA_Stun_cell", "IDA_Smoke_LauncherGrenade","IDA_SmokeRed_LauncherGrenade","IDA_SmokeGreen_LauncherGrenade","IDA_SmokeBlue_LauncherGrenade","IDA_SmokePurple_LauncherGrenade","ACE_40mm_Flare_Red","ACE_40mm_Flare_White","ACE_HuntIR_M203"};
			magazineWell[] = {"42nd_GL_Magwell"};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_Imp_Optic_1","Optre_Evo_Sight_Riser","Optre_Evo_Sight","OPTRE_M12_Optic","OPTRE_M12_Optic_Green", "OPTRE_M12_Optic_Red"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_DC15s_UGL_Shield: IDA_DC15S_UGL_Shield
	{
		IDA_AltWeapon = "42nd_DC15S_UGL";
		IDA_AltWeaponItem = "IDA_Shield_Rep_item";
		IDA_AltWeaponSwap = "true";
		IDA_SwitchText = "Switching Shield";
		IDA_StunWeapon = "IDA_DC15S_UGL_Stun_Shield";
		displayName = "[42nd] DC-15S UGL carbine + Shield";
		scope = 1;
		baseWeapon = "42nd_DC15s_UGL_Shield";
		model = "Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15S\Model\IDA_DC15S_UGL_Shield.p3d";
		handAnim[] = {"OFP2_ManSkeleton","Indecisive_Armoury_Anims\Republic\Shield_Rep.rtm"};
	};
	class 42nd_DC15A: IDA_DC15A
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15A Rifle";
		magazines[] = {"42nd_blaster_cell_High"};
		magazineWell[] = {};
		modes[] = {"Single","FullAuto"};
		baseweapon= "42nd_DC15A";
		fireLightDiffuse[] = {0.1,0.25,1};
		drySound[] = {"\Indecisive_Armoury_Sounds\weapon_dry.ogg",5,1,10};
		muzzles[]= { "this", "Stun"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_DC15C: 3AS_DC15C_F 
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15C Rifle";
		descriptionShort = "Long range, slow rate of fire.";
		magazines[] = {"42nd_blaster_cell_High"};
		magazineWell[] = {};
		baseweapon= "42nd_DC15C";
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_optic_acog_DC15C","3AS_optic_reflex_DC15C","3AS_Optic_Scope_WestarM5","OPTRE_M7_Sight","OPTRE_HMG38_CarryHandle","OPTRE_M12_Optic","OPTRE_M12_Optic_Red","OPTRE_M12_Optic_Green",
				"Optre_Recon_Sight","Optre_Recon_Sight_Red","Optre_Recon_Sight_Green","Optre_Recon_Sight_Desert","Optre_Recon_Sight_UNSC","Optre_Recon_Sight_Snow",	"OPTRE_BR45_Scope","OPTRE_BR55HB_Scope","OPTRE_BR55HB_Scope_Grey",
				"OPTRE_BMR_Scope","OPTRE_M392_Scope","OPTRE_M393_Scope","OPTRE_M393_ACOG","OPTRE_M393_EOTECH","OPTRE_SRM_Sight","OPTRE_SRS99C_Scope","OPTRE_SRS99_Scope","OPTRE_M73_SmartLink","OPTRE_MA5_SmartLink","OPTRE_MA5C_SmartLink","OPTRE_MA5_BUIS"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_DC15C_UGL: 3AS_DC15C_F 
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15C Rifle (UGL)";
		descriptionShort = "Long range, slow rate of fire.";
		magazines[] = {"42nd_blaster_cell_High"};
		magazineWell[] = {};
		baseweapon= "42nd_DC15C_UGL";
		muzzles[]= { "this", "Grenade_Launcher"};
		class Grenade_Launcher: 42nd_GL_Muzzle
		{

			magazineWell[] = {"42nd_GL_Magwell"};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_optic_acog_DC15C","3AS_optic_reflex_DC15C","3AS_Optic_Scope_WestarM5","OPTRE_M7_Sight","OPTRE_HMG38_CarryHandle","OPTRE_M12_Optic","OPTRE_M12_Optic_Red","OPTRE_M12_Optic_Green",
				"Optre_Recon_Sight","Optre_Recon_Sight_Red","Optre_Recon_Sight_Green","Optre_Recon_Sight_Desert","Optre_Recon_Sight_UNSC","Optre_Recon_Sight_Snow",	"OPTRE_BR45_Scope","OPTRE_BR55HB_Scope","OPTRE_BR55HB_Scope_Grey",
				"OPTRE_BMR_Scope","OPTRE_M392_Scope","OPTRE_M393_Scope","OPTRE_M393_ACOG","OPTRE_M393_EOTECH","OPTRE_SRM_Sight","OPTRE_SRS99C_Scope","OPTRE_SRS99_Scope","OPTRE_M73_SmartLink","OPTRE_MA5_SmartLink","OPTRE_MA5C_SmartLink","OPTRE_MA5_BUIS"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_DC15LE: IDA_DC15A
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15 LE Rifle";
		descriptionShort = "Long Range Precision Modified Rifle. Semi Auto";
		magazines[] = {"42nd_blaster_cell_Amp"};
		baseweapon= "42nd_DC15LE";
		muzzles[]= { "this", "Stun"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"IDA_773_scope"};
                iconPicture="";
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {"3AS_Muzzle_LE_DC15A"};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};

	class 42nd_T15: IDA_T15
	{
		author = "Indecisive Armoury Team";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] T-15 Blaster Cannon";
		magazines[] = {"42nd_thermal_coil_AMP","42nd_thermal_coil_HP"};
		magazineWell[] = {};
		muzzles[] = {"this"};
		baseweapon= "42nd_T15";
		modes[] = {"Single"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 85;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_Optic_Scope_WestarM5", "3AS_optic_reflex_DC15C", "3AS_optic_acog_DC15C"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 42nd_DLT15: IDA_DLT15
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DLT-15 Light Repeating Blaster";
		descriptionShort = "Heavy Support Weapon, Squad Suppression";
		magazines[] = {"42nd_LP_blaster_battery", "42nd_HP_blaster_battery"};
		baseweapon= "42nd_DLT15";
		magazineWell[] = {};
		muzzles[] = {"this","Stun"};
		modes[] = {"FullAuto"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 85;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"3AS_Optic_DC15L","IDA_773_scope"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 42nd_DC15SX: JLTS_DC15X
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15SX Sniper Rifle";
		magazines[] = {"42nd_blaster_cell_OC"};
		magazineWell[] = {};
		baseweapon= "42nd_DC15SX";
		muzzles[] = {"this", "Stun"};
		modes[] = {"Single"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 85;
			class CowsSlot: CowsSlot
			{
			compatibleItems[] = {"JLTS_DC15X_scope","3AS_Imp_Optic_DLT19x","Optic_Nightstalker"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
	};
	class 42nd_DC15HX: IDA_DC15X
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = "[42nd] DC-15HX Sniper Rifle";
		magazines[] = {"42nd_blaster_cell_HOC"};
		magazineWell[] = {};
		muzzles[] = {"this", "Stun"};
		baseweapon= "42nd_DC15HX";
		modes[] = {"Single"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 85;
			class CowsSlot: CowsSlot
			{
			compatibleItems[] = {"IDA_DC15X_Scope"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {"3AS_Bipod_VK38X_f"};
			};
		};
	};
	class 42nd_DC15_Vintage: IDA_DC15A
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = " [42nd] DC-15 rifle (BF2 Vintage)";
		baseWeapon = "42nd_DC15_Vintage";
		magazines[] = {"42nd_blaster_cell_Vintage"};
		magazineWell[] = {};
		muzzles[] = {"this","Stun"};
		modes[] = {"Single","FullAuto"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_773_FirePunch: IDA_773Firepuncher
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = " [42nd] 773 Firepuncher Sniper Rifle";
		descriptionShort = "Used by Snipers Everywhere";
		magazines[] = {"42nd_blaster_cell_OC","IDA_blaster_cell_Amp"};
		magazineWell[] = {};
		muzzles[] = {"this","Stun"};
		baseWeapon = "42nd_773_FirePunch";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"IDA_773_scope", "3AS_optic_holo_DC15S", "3AS_optic_acog_DC15C", "optic_Nightstalker"};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight", "ACE_acc_pointer_green", "OPTRE_M6D_Carbine_Flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
	};
	class 42nd_Z6: IDA_Z6
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = " [42nd] Z-6";
		magazines[] = {"IDA_blaster_battery","42nd_BlasterCell_High_Cap"};
		magazineWell[] = {};
		baseWeapon = "42nd_Z6";
		muzzles[] = {"this","Stun"};
		modes[] = {"FullAuto","FasterAuto", "BARAuto"};
		class Stun: 42nd_Stun_Muzzle
        {
            reloadAction = "ReloadMagazine";
            reloadMagazineSound[]=
            {
                "A3\Sounds_F\arsenal\weapons\Pistols\P07\reload_P07.wss",
                1,
                1,
                10
            };
        };
		class FullAuto: Mode_FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1,1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.015,1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.985,1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.01,1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.995,1800};
				soundBegin[] = {"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1,1,400};
				soundBeginWater[] = {"beginwater1",1};
			};
			reloadTime = 0.05;
			dispersion = 0.0014;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 10000;
			maxRangeProbab = 0.3;
		};
		class FasterAuto: FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1,1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.015,1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.985,1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.01,1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.995,1800};
				soundBegin[] = {"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1,1,400};
				soundBeginWater[] = {"beginwater1",1};
			};
			reloadTime = 0.02;
			dispersion = 0.0014;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 10000;
			maxRangeProbab = 0.3;
		};
		class BARAuto: FullAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1,1800};
				begin2[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.015,1800};
				begin3[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.985,1800};
				begin4[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,1.01,1800};
				begin5[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1.25,0.995,1800};
				soundBegin[] = {"begin1",0.2,"begin2",0.2,"begin3",0.2,"begin4",0.2,"begin5",0.2};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\DLT-15\DLT15.ogg",1,1,400};
				soundBeginWater[] = {"beginwater1",1};
			};
			reloadTime = 0.15;
			dispersion = 0.0014;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 10000;
			maxRangeProbab = 0.3;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight", "ACE_acc_pointer_green", "OPTRE_M6D_Carbine_Flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	class 42nd_Z6_GL: IDA_Z6
	{
		author = "Hound";
		scope = 2;
		inertia = 0;
		canShootInWater = 1;
		displayName = " [42nd] Z-6 (Test)";
		magazines[] = {"IDA_blaster_battery","42nd_GL_Ext_Cell","42nd_Imploder_Cell"};
		magazineWell[] = {};
		baseWeapon = "42nd_Z6_GL";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight", "ACE_acc_pointer_green", "OPTRE_M6D_Carbine_Flashlight"};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[] = {};
			};
		};
	};
	
	class srifle_LRR_camo_F;
	class 42nd_Space_Intervention: srifle_LRR_camo_F
	{
		displayname = "DC-23XTL";
		scope = 2;
		author = "Hound";
		hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Weapons\Space_Intervention\Space_Intervention_co.paa"};
		magazines[] = {"42nd_blaster_cell_OC","IDA_blaster_cell_Amp"};
		baseweapon = "42nd_Space_Intervention";
		magazineWell[] = {};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "";
				closure1[] = {};
				closure2[] = {};
				soundClosure[] = {};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect = "";
				begin1[] = {"\Indecisive_Armoury_Sounds\Republic\DC-15x\DC15x.ogg",2.5,1,1800};
				soundBegin[] = {"begin1",1};
				beginwater1[] = {"\Indecisive_Armoury_Sounds\Republic\DC-15x\DC15x.ogg",1,1,400};
				soundBeginWater[] = {"beginwater1",1};
			};
			reloadTime = 0.9;
			dispersion = 0.00010;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 10000;
			maxRangeProbab = 0.3;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
			class CowsSlot: CowsSlot
			{
				compatibleItems[] = {"IDA_773_scope", "3AS_optic_holo_DC15S", "3AS_optic_acog_DC15C", "optic_Nightstalker"};
			};

			class PointerSlot: PointerSlot
			{
				compatibleItems[] = {"acc_flashlight", "ACE_acc_pointer_green", "OPTRE_M6D_Carbine_Flashlight"};
			};
		};
	};
