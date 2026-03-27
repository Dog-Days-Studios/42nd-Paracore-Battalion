class 3AS_ARC_170_Republic;

class 42nd_ARC170: 3AS_ARC_170_Republic
{
    author = "HoundaCivic";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] ARC-170";
    faction = "Fac42nd";
    editorSubcategory = "SUB42ndAir";
    crew = "42nd_WO1_Pilot";
    typicalCargo[] = {"42nd_WO1_Pilot"};
    hiddenselections[] = {"\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa","\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa","3as\3AS_ARC170\Data\Guns_CO.paa"};
    class TextureSources
    {
        class Base42ndARC170
        {
            displayName = "[42nd] Base";
            scope = 2;
            author = "HoundaCivic";
            textures[] =
            {
                "\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa",
                "\3AS\3AS_ARC170\Data\Guns_CO.paa"
            };
            factions[] = {"Fac42nd"};
        };
    };
    textureList[] = {"Base42ndARC170",1};
};
