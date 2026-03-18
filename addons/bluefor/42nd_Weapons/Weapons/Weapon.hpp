// 42nds Weapons - Sniper Rifle congfig section. //
 class IDA_Galaar90;
 class IDA_IQA11;
 class IDA_DC15X;
 class IDA_774CX;
 class IDA_773Firepuncher;
 class JLTS_DC15X;
 class JLTS_DW32S;
 class ls_weapon_firepuncher;
 class ls_weapon_dc15x;
 class 3AS_Valken38X_F;
 class IDA_DLT15;
class IDA_DLT19;
class IDA_DLT19D;
class IDA_Z6;
class JLTS_Z6;
class ls_weapon_z6;
class 3AS_DLT19;
class IDA_DC15S_UGL;
class IDA_DC15LE;
class JLTS_DC15A_ugl_plastic;
class JLTS_DC15A_ugl;
class 3AS_DC15A_GL;
class 3AS_DC15C_GL;
class 3AS_DC15S_GL;
class 3AS_DP23_GL;
class IDA_DC15P;
class IDA_DC17;
class ls_weapon_dc15sa;
class ls_weapon_dc17s;
class ls_weapon_dc17s_dual;
class 3AS_DC17S_F;
class 3AS_DC17S_Dual_F;
class 3AS_FusionCutter_F;
class IDA_RPS6HP;
class JLTS_stun_muzzle;
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
// Sniper Config Section //
 class 42nd_Valken38X: 3AS_Valken38X_F
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] Valken-38X";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_Valken38X";
 };
 class 42nd_Galaar90: IDA_Galaar90
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] Galaar-90";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_Galaar90";
 };
 class 42nd_IQA11: IDA_IQA11
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] IQA-11";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_IQA11";
 };
 class 42nd_DC15X: IDA_DC15X
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] DC-15X";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_DC15X";
 };
 class 42nd_774CX: IDA_774CX
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] 774-CX";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_774CX";
 };
 class 42nd_773Firepuncher: IDA_773Firepuncher
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] 773-Firepuncher";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_773Firepuncher";
 };
 class 42nd_JLTS_DC15X: JLTS_DC15X
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] JLTS DC-15X";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_JLTS_DC15X";
 };
 class 42nd_JLTS_DW32S: JLTS_DW32S
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] JLTS DW-32S";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_JLTS_DW32S";
 };
 class 42nd_ls_weapon_firepuncher: ls_weapon_firepuncher
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] LS Firepuncher";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_ls_weapon_firepuncher";
 };
 class 42nd_ls_weapon_dc15x: ls_weapon_dc15x
 {
	 author = "HoundaCivic";
	 displayName = "[42nd] LS DC-15X";
	 magazines[] = {};
	 magazineWell[] = {"42nd_Sniper_Magwell"};
	 baseWeapon = "42nd_ls_weapon_dc15x";
 };
// 42nd Rifles - Config Section //
class IDA_DC15A;
class IDA_DC15S;
class IDA_FA11;
class JLTS_DC15A_plastic;
class JLTS_DC15A;
class JLTS_DC15S;
class ls_weapon_dc15a;
class ls_weapon_dc15a_wooden;
class ls_weapon_dc15ac;
class ls_weapon_dc15br_wooden;
class ls_weapon_dc15br;
class ls_weapon_dc15s;
class 3AS_DC15A_F;
class 3AS_DC15C_F;
class 3AS_DC15S_F;
class 42nd_DC15A: IDA_DC15A
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-15A Rifle";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_DC15A";
};
class 42nd_DC15S: IDA_DC15S
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-15S Carbine";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_DC15S";
};
class 42nd_FA11: IDA_FA11
{
	author = "HoundaCivic";
	displayName = "[42nd] FA-11";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_FA11";
};
class 42nd_JLTS_DC15A_plastic: JLTS_DC15A_plastic
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS DC-15A Plastic";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_JLTS_DC15A_plastic";
};
class 42nd_JLTS_DC15A: JLTS_DC15A
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS DC-15A";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_JLTS_DC15A";
};
class 42nd_JLTS_DC15S: JLTS_DC15S
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS DC-15S";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_JLTS_DC15S";
};
class 42nd_ls_weapon_dc15a: ls_weapon_dc15a
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15A";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15a";
};
class 42nd_ls_weapon_dc15a_wooden: ls_weapon_dc15a_wooden
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15A Wooden";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15a_wooden";
};
class 42nd_ls_weapon_dc15ac: ls_weapon_dc15ac
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15AC";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15ac";
};
class 42nd_ls_weapon_dc15br_wooden: ls_weapon_dc15br_wooden
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15BR Wooden";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15br_wooden";
};
class 42nd_ls_weapon_dc15br: ls_weapon_dc15br
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15BR";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15br";
};
class 42nd_ls_weapon_dc15s: ls_weapon_dc15s
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15S";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_ls_weapon_dc15s";
};
class 42nd_3AS_DC15A_F: 3AS_DC15A_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15A";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15A_F";
};
class 42nd_3AS_DC15C_F: 3AS_DC15C_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15C";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15C_F";
};
class 42nd_3AS_DC15S_F: 3AS_DC15S_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15S";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15S_F";
};
///  42nd LMGs - Config Section ///
class 42nd_DLT15: IDA_DLT15
{
	author = "HoundaCivic";
	displayName = "[42nd] DLT-15";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_DLT15";
};
class 42nd_DLT19: IDA_DLT19
{
	author = "HoundaCivic";
	displayName = "[42nd] DLT-19";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_DLT19";
};
class 42nd_DLT19D: IDA_DLT19D
{
	author = "HoundaCivic";
	displayName = "[42nd] DLT-19D";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_DLT19D";
};
class 42nd_Z6: IDA_Z6
{
	author = "HoundaCivic";
	displayName = "[42nd] Z-6";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_Z6";
};
class 42nd_JLTS_Z6: JLTS_Z6
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS Z-6";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_JLTS_Z6";
};
class 42nd_ls_weapon_z6: ls_weapon_z6
{
	author = "HoundaCivic";
	displayName = "[42nd] LS Z-6";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_ls_weapon_z6";
};
class 42nd_3AS_DLT19: 3AS_DLT19
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DLT-19";
	magazines[] = {"42nd_LMG_Cell_250Round_Blue", "42nd_LMG_Cell_500Round_Blue", "42nd_LMG_Cell_750Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
	magazineWell[] = {"42nd_LMG_Magwell"};
	baseWeapon = "42nd_3AS_DLT19";
};

// Grenade Launchers
class 42nd_DC15S_UGL: IDA_DC15S_UGL
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-15S UGL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_DC15S_UGL";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_DC15LE: IDA_DC15LE
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-15LE";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_DC15LE";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_JLTS_DC15A_ugl_plastic: JLTS_DC15A_ugl_plastic
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS DC-15A UGL Plastic";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_JLTS_DC15A_ugl_plastic";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_JLTS_DC15A_ugl: JLTS_DC15A_ugl
{
	author = "HoundaCivic";
	displayName = "[42nd] JLTS DC-15A UGL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_JLTS_DC15A_ugl";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_3AS_DC15A_GL: 3AS_DC15A_GL
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15A GL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15A_GL";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_3AS_DC15C_GL: 3AS_DC15C_GL
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15C GL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15C_GL";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_3AS_DC15S_GL: 3AS_DC15S_GL
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-15S GL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DC15S_GL";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};
class 42nd_3AS_DP23_GL: 3AS_DP23_GL
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DP-23 GL";
	magazines[] = {};
	magazineWell[] = {"42nd_Rifle_Magwell"};
	baseWeapon = "42nd_3AS_DP23_GL";
	muzzles[]= { "this", "Grenade_Launcher"};
	class Grenade_Launcher: 42nd_GL_Muzzle
	{
		magazineWell[] = {"42nd_GL_Magwell"};
	};
};

/// 42nd Pistols - Config Section ///
class 42nd_DC15P: IDA_DC15P
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-15P";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_DC15P";
};
class 42nd_DC17: IDA_DC17
{
	author = "HoundaCivic";
	displayName = "[42nd] DC-17";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_DC17";
};
class 42nd_ls_weapon_dc15sa: ls_weapon_dc15sa
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-15SA";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_ls_weapon_dc15sa";
};
class 42nd_ls_weapon_dc17s: ls_weapon_dc17s
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-17S";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_ls_weapon_dc17s";
};
class 42nd_ls_weapon_dc17s_dual: ls_weapon_dc17s_dual
{
	author = "HoundaCivic";
	displayName = "[42nd] LS DC-17S Dual";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_ls_weapon_dc17s_dual";
};
class 42nd_3AS_DC17S_F: 3AS_DC17S_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-17S";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_3AS_DC17S_F";
};
class 42nd_3AS_DC17S_Dual_F: 3AS_DC17S_Dual_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS DC-17S Dual";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_3AS_DC17S_Dual_F";
};
class 42nd_3AS_FusionCutter_F: 3AS_FusionCutter_F
{
	author = "HoundaCivic";
	displayName = "[42nd] 3AS Fusion Cutter";
	magazines[] = {"IDA_Blaster_Cell_Power5_5Rnd_Blue"};
	magazineWell[] = {};
	baseWeapon = "42nd_3AS_FusionCutter_F";
};
 
