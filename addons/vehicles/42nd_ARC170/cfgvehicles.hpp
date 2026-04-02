class NewTurret;
class Optics_Commander_02
{
    class Wide;
    class Medium;
    class Narrow;
};
class Optics_Gunner_MBT_03
{
    class Wide;
    class Medium;
    class Narrow;
};
class 3AS_ARC_170_base;

#define C42_ARC170_TEXTURES \
    "\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa", \
    "\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa", \
    "\3AS\3AS_ARC170\Data\Guns_CO.paa"

class 42nd_ARC170: 3AS_ARC_170_base
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] ARC-170";
    side = 1;
    faction = "Fac42nd";
    editorSubcategory = "SUB42ndAir";
    vehicleClass = "Air";
    crew = "42nd_WO1_Pilot";
    typicalCargo[] = {"42nd_WO1_Pilot"};
    hiddenSelectionsTextures[] = {C42_ARC170_TEXTURES};

    class Turrets
    {
        class Reargun: NewTurret
        {
            isCopilot = 0;
            canEject = 1;
            startEngine = 0;

            class OpticsIn
            {
                class Wide
                {
                    opticsDisplayName = "W";
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.5;
                    minFov = 0.5;
                    maxFov = 0.5;
                    directionStabilized = 1;
                    visionMode[] = {"Normal", "NVG", "Ti"};
                    thermalMode[] = {0, 1};
                    gunnerOpticsModel = "A3\\drones_f\\Weapons_F_Gamma\\Reticle\\UAV_Optics_Gunner_wide_F.p3d";
                    opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
                };

                class Medium: Wide
                {
                    opticsDisplayName = "M";
                    initFov = 0.1;
                    minFov = 0.1;
                    maxFov = 0.1;
                    gunnerOpticsModel = "A3\\drones_f\\Weapons_F_Gamma\\Reticle\\UAV_Optics_Gunner_medium_F.p3d";
                };

                class Narrow: Wide
                {
                    opticsDisplayName = "N";
                    initFov = 0.0286;
                    minFov = 0.0286;
                    maxFov = 0.0286;
                    gunnerOpticsModel = "A3\\drones_f\\Weapons_F_Gamma\\Reticle\\UAV_Optics_Gunner_narrow_F.p3d";
                };

                showMiniMapInOptics = 1;
                showUAVViewInOptics = 0;
                showSlingLoadManagerInOptics = 0;
            };

            soundServo[] = {"", 0.01, 1};
            outGunnerMayFire = 1;
            commanding = -1;
            primaryGunner = 0;
            gunnerGetInAction = "GetInLow";
            gunnerGetOutAction = "GetOutLow";
            gunnerInAction = "Plane_Fighter_03_pilot";
            gunnerOpticsEffect[] = {"TankCommanderOptics1", "BWTV"};
            memoryPointGunnerOptics = "gunnerview";
            memoryPointsGetInGunner = "pos gunner";
            memoryPointsGetInGunnerDir = "pos gunner dir";
            stabilizedInAxes = 3;
            gunnerAction = "Plane_Fighter_03_pilot";
            gunnerForceOptics = 0;
            gunnerOpticsModel = "A3\\drones_f\\Weapons_F_Gamma\\Reticle\\UGV_01_Optics_Gunner_F.p3d";
            gunnerName = "Rear Gunner";
            proxyIndex = 3;
            proxyType = "CPGunner";
            gunnerLeftHandAnimName = "lever_copilot";
            gunnerRightHandAnimName = "stick_copilot";
            gunnerLeftLegAnimName = "";
            gunnerRightLegAnimName = "";
            animationSourceBody = "MainTurret";
            animationSourceGun = "Maingun";
            animationSourceHatch = "";
            body = "MainTurret";
            gun = "Maingun";
            memoryPointGun = "konec hlavne b";
            gunBeg = "usti hlavne b";
            gunEnd = "konec hlavne b";
            selectionFireAnim = "zasleh3";
            castGunnerShadow = 1;
            viewGunnerShadow = 1;
            preciseGetInOut = 0;
            turretInfoType = "RscOptics_Heli_Attack_01_gunner";
            discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 1000, 1200, 1500, 1800, 2100};
            discreteDistanceInitIndex = 5;
            weapons[] = {"3AS_ARC_Light_Canon_Rear", "CMFlareLauncher"};
            magazines[] = {"3AS_ARC_500Rnd_Light_Shells", "240Rnd_CMFlare_Chaff_Magazine"};
            minElev = -5;
            maxTurn = 270;
            minTurn = 90;
            maxElev = 60;
            initTurn = 180;
            initElev = 0;
            enableManualFire = 0;
            usePip = 2;
            LODTurnedOut = 1000;
            LODTurnedIn = 1000;
            elevationMode = 0;
            turretFollowFreeLook = 2;

            class HitPoints {};
        };

        class LaserPilot: Reargun
        {
            commanding = -1;
            memoryPointGunnerOptics = "gunnerview2";
            gunnerForceOptics = 0;
            enableManualFire = 1;
            primaryGunner = 0;
            body = "Mainturret2";
            gun = "maingun2";
            animationSourceBody = "mainturret2";
            animationSourceGun = "maingun2";
            weapons[] = {"3AS_ARC_Heavy_Canon"};
            magazines[] = {"3AS_PylonWeapon_ARC_240Rnd_Heavy_Shells", "3AS_PylonWeapon_ARC_240Rnd_Heavy_Shells"};
            gunnerName = "Co-pilot";
            gunBeg = "usti hlavne b2";
            gunEnd = "konec hlavne b2";
            memoryPointGun = "konec hlavne b2";
            selectionFireAnim = "zasleh4";
            usePip = 2;

            class OpticsIn: Optics_Gunner_MBT_03
            {
                class Wide: Wide {};
                class Medium: Medium {};
                class Narrow: Narrow {};
            };

            proxyIndex = 2;
            minElev = -90;
            maxTurn = 240;
            minTurn = 120;
            maxElev = 0;
            initTurn = 180;
            initElev = -10;
            maxHorizontalRotSpeed = 3;
            maxVerticalRotSpeed = 3;

            class HitPoints {};
        };
    };

    class TextureSources
    {
        class Base42ndARC170
        {
            displayName = "[42nd] Base";
            author = "HoundaCivic";
            scope = 2;
            textures[] = {C42_ARC170_TEXTURES};
            factions[] = {"Fac42nd"};
        };
    };

    textureList[] = {"Base42ndARC170", 1};
};

class 42nd_ARC170_Gunship: 42nd_ARC170
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] ARC-170 Gunship";
    side = 1;
    faction = "Fac42nd";
    editorSubcategory = "SUB42ndAir";
    vehicleClass = "Air";

    class Turrets: Turrets
    {
        class Reargun: Reargun
        {
            weapons[] =
            {
                "42nd_ARC170_105mm_Laser_Cannon",
                "42nd_ARC170_40mm_Laser_Bofors",
                "42nd_ARC170_Laser_Minigun"
            };
            magazines[] =
            {
                "ls_magazine_120mm_30Rnd_HE_blue",
                "ls_magazine_40mm_50Rnd_G_blue",
                "ls_magazine_40mm_50Rnd_G_blue",
                "ls_magazine_127x99_500Rnd_blue",
                "ls_magazine_127x99_500Rnd_blue",
                "ls_magazine_127x99_500Rnd_blue",
                "ls_magazine_127x99_500Rnd_blue"
            };
        };
    };
};

#undef C42_ARC170_TEXTURES
