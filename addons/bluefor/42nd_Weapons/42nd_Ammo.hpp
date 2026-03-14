	class B_762x51_Ball;
	class G_40mm_HE;
	class RocketBase;
	class BulletBase;
	class GrenadeHand_stone;
	class GrenadeHand;
	class SmokeShell;
	class SmokeLauncherAmmo;
	class FlameRound;
	class FlameRound_sub;
	class R_PG32V_F;
	class M_Titan_AT;
	class PLX_Javelin;
	class B_40mm_APFSDS;
	class B_12Gauge_Pellets_Submunition;
	class SatchelCharge_Remote_Ammo;
	class IDA_blasterbolt;
	class IDA_blasterbolt_High;
	class IDA_blasterbolt_Overcharged;
	class IDA_blasterbolt_Overcharged_VEHICLE;
	class 3AS_FlakCannon_AA;
	class 42nd_blasterbolt_OC: IDA_blasterbolt_Overcharged
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType = "plasma";
		hit = 45;
		caliber = 6;
		coefGravity = 0.02;
	};
	class 42nd_blasterbolt: IDA_blasterbolt
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType = "plasma";
		cartridge = "";
		lightcolor[] = {0,0.3,1};
		hit = 20;
		caliber = 6;
		coefGravity = 0.02;
	};
	class 42nd_blasterbolt_High: IDA_blasterbolt_High
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly = "IDA_BlasterBoltGlow_Blue_Fly";
		hit = 100;
		caliber = 6;
		coefGravity = 0.02;
	};
	class 42nd_blasterbolt_Overcharged_VEHICLE: IDA_blasterbolt_Overcharged_VEHICLE
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Yellow.p3d";
		effectFly = "IDA_BlasterBoltGlow_Medium_Yellow_Fly";
		ACE_damageType = "plasmashell";
		hit = 800;
		indirectHit = 150;
		explosive = 1;
		indirectHitRange = 2.5;
		caliber = 2;
	};
	class 42nd_Heavy_blasterbolt: 42nd_blasterbolt
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType = "plasma";
		cartridge = "";
		lightcolor[] = {0,0.3,1};
		hit = 300;
		caliber = 6;
		coefGravity = 0.02;
	};
	class 42nd_Apex_Blasterbolt: 42nd_Heavy_blasterbolt
	{
		model = "\Indecisive_Armoury_Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		ACE_damageType = "plasma";
		cartridge = "";
		lightcolor[] = {0,0.3,1};
		hit = 350;
		caliber = 2;
		coefGravity = 0.02;
	};
	/*class 3AS_FlakCannon_AA: 3AS_FlakCannon_AA
	{
		hit = 60;
		indirectHit = 25;
		indirectHitRange = 2.4;
		warheadName = "HE";
		visibleFire = 38;
		audibleFire = 200;
		visibleFireTime = 5;
		proximityExplosionDistance = 50;
		dangerRadiusBulletClose = 20;
		dangerRadiusHit = 60;
		suppressionRadiusBulletClose = 12;
		simulation = "shotBullet";
		suppressionRadiusHit = 24;
		deflecting = 0;
		explosive = 0.6;
		airLock = 1;
		aiAmmoUsageFlags = "64 + 128 + 256";
		cost = 42;
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "GrenadeExplosion";
		explosionSoundEffect = "DefaultExplosion";
		model = "\3AS\3AS_Weapons\Data\tracer_shell_red.p3d";
		tracerScale = 1.85;
		tracerStartTime = 0;
		tracerEndTime = 10;
		timeToLive = 10;
		airFriction = -0.0005;
		muzzleEffect = "";
		caliber = 2.8;
		typicalSpeed = 960;
		effectFly = "3AS_PlasmaBolt_Large_Red_Fly";
		soundSetSonicCrack[] = {"3AS_HeavyPlasma_Flyby_SoundSet"};
		soundDefault1[] = {"3AS\3AS_VehicleWeapons\Impacts\Flak\FLAK_Explosion_1.ogg",6,1,500};
		soundDefault2[] = {"3AS\3AS_VehicleWeapons\Impacts\Flak\FLAK_Explosion_2.ogg",6,1,500};
		soundDefault3[] = {"3AS\3AS_VehicleWeapons\Impacts\Flak\FLAK_Explosion_3.ogg",6,1,500};
		soundDefault4[] = {"3AS\3AS_VehicleWeapons\Impacts\Flak\FLAK_Explosion_3.ogg",6,1,500};
		hitDefault[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitGround[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitGroundHard[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitGroundSoft[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitConcrete[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitBuilding[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitFoliage[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitWood[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitPlastic[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitRubber[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitTyre[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitMetal[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitIron[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitMetalInt[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitMetalPlate[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitArmor[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		hitArmorInt[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault4",0.25};
		multiSoundHit[] = {"soundDefault1",0.25,"soundDefault2",0.25,"soundDefault3",0.25,"soundDefault3",0.25};
		class CamShakeExplode
		{
			power = 3.6;
			duration = 0.8;
			frequency = 20;
			distance = 41.9411;
		};
		class CamShakeHit
		{
			power = 18;
			duration = 0.4;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 1.49535;
			duration = 0.4;
			frequency = 20;
			distance = 17.8885;
		};
		class CamShakePlayerFire
		{
			power = 0.001;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
	}; */
