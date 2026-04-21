class 3as_gozanti_republic;

class 42nd_Gozanti_Republic: 3as_gozanti_republic
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Gozanti Cruiser";
    faction = "Fac42nd_AIR";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_WO1_Pilot";
    hiddenselections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6"};
    hiddenselectionstextures[] = {"\42nd_para\42nd\addons\vehicles\42nd_Gozanti\42nd_Gozanti_camo1_co.paa","3AS\3AS_Imperial_Air\Gozanti\data\Gozanti_Int_co.paa","\42nd_para\42nd\addons\vehicles\42nd_Gozanti\42nd_Gozanti_camo2_co.paa","3AS\3AS_Imperial_Air\Gozanti\data\Camo3_co.paa","3AS\3AS_Imperial_Air\Gozanti\data\Camo4_co.paa","3AS\3AS_Imperial_Air\Gozanti\data\Camo5_co.paa","3AS\3AS_Imperial_Air\Gozanti\data\Camo6_co.paa"};
    class VehicleTransport
    {
        class Carrier
        {
            cargoBayDimensions[] = {{-8, -20, -8}, {8, -2, 0}};
            disableHeightLimit = 1;
            maxLoadMass = 500000;
            cargoAlignment[] = {"center", "front"};
            cargoSpacing[] = {0.3, 0.3, 0};
        };
    };
};

