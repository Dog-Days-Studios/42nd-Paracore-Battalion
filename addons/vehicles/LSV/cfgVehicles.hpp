class LSV_01_armed_base_F;
class LSV_01_unarmed_base_F;

class B_LSV_01_armed_F: LSV_01_armed_base_F
{
    class Turrets
    {
        class MainTurret;
        class CodRiverTurret;
    };
};
class B_LSV_01_unarmed_F: LSV_01_unarmed_base_F {};

#define C42_LSV_HIDDEN_SELECTIONS "Camo_1", "Camo_2", "Camo_3", "Camo_4"
#define C42_LSV_TEXTURES \
    "\42nd_para\42nd\addons\Vehicles\LSV\42nd_LSV_01_BODY_CO.paa", \
    "\42nd_para\42nd\addons\Vehicles\LSV\42nd_LSV_02_BASE_CO.paa", \
    "\42nd_para\42nd\addons\Vehicles\LSV\42nd_LSV_03_Base_CO.paa", \
    "\42nd_para\42nd\addons\Vehicles\LSV\42nd_LSV_Adds_base_CO.paa"
#define C42_LSV_TEXTURE_SOURCE(CLASSNAME) \
    class CLASSNAME \
    { \
        displayName = "[42nd] Base"; \
        author = "HoundaCivic"; \
        scope = 2; \
        textures[] = {C42_LSV_TEXTURES}; \
        factions[] = {"Fac42nd_Ground"}; \
    };

class 42nd_LSV_Armed: B_LSV_01_armed_F
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LRATV (Z-6)";
    side = 1;
    faction = "Fac42nd_Ground";
    vehicleClass = "Car";
    editorSubcategory = "Sub42ndLightVic";
    crew = "42nd_Trooper";
    transportSoldier = 4;
    typicalCargo[] = {"42nd_Trooper"};
    hiddenSelections[] = {C42_LSV_HIDDEN_SELECTIONS};
    hiddenSelectionsTextures[] = {C42_LSV_TEXTURES};
    availableForSupportTypes[] = {"Drop", "Transport"};

    class Turrets: Turrets
    {
        class MainTurret: MainTurret
        {
            disableSoundAttenuation = 1;
            gunnerLeftHandAnimName = "otocHlaven";
            gunnerRightHandAnimName = "otocHlaven";
            body = "mainTurret";
            gun = "mainGun";
            animationSourceBody = "mainTurret";
            animationSourceGun = "mainGun";
            weapons[] = {"42nd_ls_weapon_z6"};
            magazines[] = {"42nd_LMG_Cell_1000Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
            minElev = -10;
            maxElev = 40;
            gunnerAction = "gunner_lsv_01";
            gunnerCompartments = "Compartment1";
            ejectDeadGunner = 0;
            castGunnerShadow = 1;
            stabilizedInAxes = 0;
            gunBeg = "muzzle_beg";
            gunEnd = "muzzle_end";
            memoryPointGunnerOptics = "gunnerView";
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
            commanding = -2;
            primaryGunner = 1;
            optics = 1;
            discreteDistance[] = {100, 200, 300, 400, 600, 800, 1000, 1200, 1500};
            discreteDistanceInitIndex = 2;
            turretInfoType = "RscOptics_crows";
            gunnerOpticsModel = "\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
        };

        class CodRiverTurret: CodRiverTurret
        {
            weapons[] = {"42nd_ls_weapon_z6"};
            magazines[] = {"42nd_LMG_Cell_1000Round_Blue", "42nd_LMG_Cell_1000Round_Blue"};
        };
    };

    class TextureSources
    {
        C42_LSV_TEXTURE_SOURCE(Base42ndLSV)
    };

    textureList[] = {"Base42ndLSV", 1};
};

class 42nd_LSV_Unarmed: B_LSV_01_unarmed_F
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LRATV";
    side = 1;
    faction = "Fac42nd_Ground";
    vehicleClass = "Car";
    editorSubcategory = "Sub42ndLightVic";
    crew = "42nd_Trooper";
    transportSoldier = 4;
    typicalCargo[] = {"42nd_Trooper", "42nd_Trooper"};
    hiddenSelections[] = {C42_LSV_HIDDEN_SELECTIONS};
    hiddenSelectionsTextures[] = {C42_LSV_TEXTURES};
    availableForSupportTypes[] = {"Drop", "Transport"};

    class TextureSources
    {
        C42_LSV_TEXTURE_SOURCE(Base42ndLSV)
    };

    textureList[] = {"Base42ndLSV", 1};
};

#undef C42_LSV_TEXTURE_SOURCE
#undef C42_LSV_TEXTURES
#undef C42_LSV_HIDDEN_SELECTIONS
