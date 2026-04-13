class ls_vehicle_laati;

    class 42nd_LAAT: ls_vehicle_laati
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] LAAT/I Gunship (Pylons)";
        faction = "Fac42nd_AIR";
        editorSubcategory = "SUB42ndAir";
        crew = "42nd_Trooper";
        ls_hasImpulse = 1;
        ls_impulsor_fuelDrain_1 = 0.000015;
        ls_impulsor_fuelDrain_2 = 0.000025;
        ls_impulsor_boostSpeed_1 = 600;
        ls_impulsor_boostSpeed_2 = 1200;
        availableForSupportTypes[] = {"Drop","Transport"};
        magazines[] = {
            "ls_magazine_50mm_200Rnd_HE_green",
            "ls_magazine_50mm_200Rnd_HE_green",
            "ls_magazine_50mm_200Rnd_APFSDS_green",
            "ls_magazine_50mm_200Rnd_APFSDS_green",
            "12rnd_missiles",
            "12rnd_missiles",
            "12rnd_missiles",
            "ls_mag_300Rnd_CMFlareChaff_purple",
            "ls_mag_300Rnd_CMFlareChaff_purple",
            "ls_mag_300Rnd_CMFlareChaff_purple"
        };
        hiddenSelectionsTextures[] = {
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_body1_co.paa",
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_body2_co.paa",
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_door1_co.paa",
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_door2_co.paa",
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_door3_co.paa",
            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_wings_co.paa",
            "\ls\core\addons\vehicles_laati\data\missiles_co.paa",
            "\ls\core\addons\vehicles_laati\data\cockpits_co.paa",
            "\ls\core\addons\vehicles_laati\data\glass_ca.paa"
        };
        class TextureSources
        {
            class Base42ndLAAT
            {
                displayName = "[42nd] Base";
                scope = 2;
                author = "HoundaCivic";
                textures[] = {
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_body1_co.paa",
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_body2_co.paa",
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_LAAT_door1_co.paa",
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_door2_co.paa",
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_door3_co.paa",
                            "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_Laat_wings_co.paa",
                            "\ls\core\addons\vehicles_laati\data\missiles_co.paa",
                            "\ls\core\addons\vehicles_laati\data\cockpits_co.paa",
                            "\ls\core\addons\vehicles_laati\data\glass_ca.paa"
                        };
                factions[] = {"Fac42nd_AIR"};
            };
        };
        textureList[] = {"Base42ndLAAT",1};
    };

class 3AS_LAAT_Mk1;
class 3AS_LAAT_Mk1Lights;
class 3AS_LAAT_Mk2;
class 3AS_LAAT_Mk2Lights;
class 42nd_3as_LAAT_Mk1: 3AS_LAAT_Mk1
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK1";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_Trooper";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
    };
    class TextureSources
    {
        class Base42nd3asLAAT
        {
            displayName = "[42nd] Base";
            scope = 2;
            author = "HoundaCivic";
            textures[] = {
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
            };
            factions[] = {"Fac42nd_AIR"};
        };
    };
    textureList[] = {"Base42nd3asLAAT",1};
};

class 42nd_3as_LAAT_Mk1Lights: 3AS_LAAT_Mk1Lights
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK1 (Lamps)";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_Trooper";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
    };
    class TextureSources
    {
        class Base42nd3asLAAT
        {
            displayName = "[42nd] Base";
            scope = 2;
            author = "HoundaCivic";
            textures[] = {
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
            };
            factions[] = {"Fac42nd_AIR"};
        };
    };
    textureList[] = {"Base42nd3asLAAT",1};
};

class 42nd_3as_LAAT: 3AS_LAAT_Mk2
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK2";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_Trooper";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
    };
    class AnimationSources;
    class Turrets
    {
        class Copilot;
    };
    class TextureSources
    {
        class Base42nd3asLAAT
        {
            displayName = "[42nd] Base";
            scope = 2;
            author = "HoundaCivic";
            textures[] = {
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
            };
            factions[] = {"Fac42nd_AIR"};
        };
    };
    textureList[] = {"Base42nd3asLAAT",1};
};

class 42nd_3as_LAAT_Mk2Lights: 3AS_LAAT_Mk2Lights
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK2 (Lamps)";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_Trooper";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
        "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
        "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
    };
    class TextureSources
    {
        class Base42nd3asLAAT
        {
            displayName = "[42nd] Base";
            scope = 2;
            author = "HoundaCivic";
            textures[] = {
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_LAAT_Hull_co.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_LAAT\42nd_3as_Laat_Wings.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapons_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Weapon_Details_CO.paa",
                "\3AS\3AS_Laat\LAATI\data\Interior_CO.paa"
            };
            factions[] = {"Fac42nd_AIR"};
        };
    };
    textureList[] = {"Base42nd3asLAAT",1};
};

class 42nd_3as_LAAT_Mk1_Fast: 42nd_3as_LAAT_Mk1
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK1 (Fast)";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    side = 1;
    crew = "42nd_Trooper";
    typicalCargo[] = {"42nd_Trooper"};
    maxSpeed = 850;
    acceleration = 650;
    liftForceCoef = 3.35;
    bodyFrictionCoef = 1.7;
    cyclicForwardForceCoef = 2.5;
    tas_max_impulse = 1000;
};

class 42nd_3as_LAAT_Mk2_NoTurrets: 42nd_3as_LAAT
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK2 (No Turrets)";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    side = 1;
    crew = "42nd_Trooper";
    typicalCargo[] = {"42nd_Trooper"};
    class Turrets {};
    class AnimationSources: AnimationSources
    {
        class Turrets
        {
            source = "user";
            initPhase = 0;
            animPeriod = 0.001;
        };
    };
};

class 42nd_3as_LAAT_Mk3_HeavyTurrets: 42nd_3as_LAAT
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] LAAT/I MK3 (Heavy)";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    side = 1;
    crew = "42nd_Trooper";
    typicalCargo[] = {"42nd_Trooper"};
    maxSpeed = 500;
    acceleration = 350;
    armor = 300;
    armorStructural = 1.2;
    class Turrets: Turrets
    {
        class Copilot: Copilot
        {
            weapons[] = {"ParticleBeamCannon","SmokeLauncher"};
            magazines[] = {"Laser_Battery_F","Laser_Battery_F"};
        };
    };
};
