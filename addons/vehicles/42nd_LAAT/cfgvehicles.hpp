class ls_vehicle_laati;

    class 42nd_LAAT: ls_vehicle_laati
    {
        author = "HoundaCivic";
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] LAAT/I Gunship (Pylons)";
        faction = "Fac42nd";
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
                factions[] = {"Fac42nd"};
            };
        };
        textureList[] = {"Base42ndLAAT",1};
    };
