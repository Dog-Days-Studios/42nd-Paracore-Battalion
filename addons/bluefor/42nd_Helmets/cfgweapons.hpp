class IDA_P2_Helmet;
class SEA_Helmet_ARF_base;
class ls_gar_phase2Pilot_helmet;
class HeadgearItem;
class 42nd_Helmet_base: IDA_P2_Helmet
{
    scope = 1;
    scopeArsenal = 1;
    42nd_cloneHud = 1;
    ace_hearing_protection = 0.95;
    ace_hearing_lowervolume = 0.2;
    hiddenselections[] = {"Camo","visor"};
    class ItemInfo: HeadgearItem
    {
        mass = 10;
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Clone_P2_Helmet\IDA_Clone_P2_Helmet.p3d";
        hiddenselections[] = {"Camo","visor"};
        class HitpointsProtectionInfo
        {
            class Head
            {
                hitpointName = "HitHead";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Face
            {
                hitpointName = "HitFace";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Neck
            {
                hitpointName = "HitNeck";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
        };
    };
};
class 42nd_Pilot_Helmet_base: ls_gar_phase2Pilot_helmet
{
    scope = 1;
    scopeArsenal = 1;
    42nd_cloneHud = 1;
    ace_hearing_protection = 0.95;
    ace_hearing_lowervolume = 0.2;
    displayName = "[42nd] Pilot Helmet";
};
class 42nd_Arf_Helmet_base: SEA_Helmet_ARF_base
{
    scope = 1;
    scopeArsenal = 1;
    42nd_cloneHud = 1;
    ace_hearing_protection = 0.95;
    ace_hearing_lowervolume = 0.2;
    hiddenSelections[] = {"Camo1","Camo2","Visor"};
    class ItemInfo: HeadgearItem
    {
        mass = 10;
        uniformModel = "JLTS_AE\SEA_Helmet_ARF.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Visor"};
        class HitpointsProtectionInfo
        {
            class Head
            {
                hitpointName = "HitHead";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Face
            {
                hitpointName = "HitFace";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Neck
            {
                hitpointName = "HitNeck";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
        };
    };
};
class 42nd_CPLTL_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Platoon Lead P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CPLTL\42nd_Platoon_Lead_Helmet.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CPLTL\42nd_Platoon_Lead_Helmet.paa"
    };
};

class 42nd_CSGT_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Squad Lead P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CSGT\42nd_Squad_Lead_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CSGT\42nd_Squad_Lead_Helmet_co.paa"
    };
};

class 42nd_CST_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Senior Trooper P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CST\42nd_CST_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CST\42nd_CST_Helmet_co.paa"
    };
};

class 42nd_CT_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT\42nd_CT_Helmet.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT\42nd_CT_Helmet.paa"
    };
};

class 42nd_Trainee_Pilot_Helmet: 42nd_Pilot_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Pilot Trainee Helmet";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Pilot\42nd_Trainee_Pilot_Helmet.paa",
        "\ls\core\addons\characters_clone_legacy\helmets\phase2Pilot\data\visor_co.paa"
    };
};

class 42nd_WO1_Pilot_Helmet: 42nd_Pilot_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Pilot WO1 Helmet";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Pilot\42nd_Wo1_Pilot_Helmet_co.paa",
        "\ls\core\addons\characters_clone_legacy\helmets\phase2Pilot\data\visor_co.paa"
    };
};

class 42nd_WO2_Pilot_Helmet: 42nd_Pilot_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Pilot WO2 Helmet";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Pilot\42nd_wo2_Pilot_Helmet_co.paa",
        "\ls\core\addons\characters_clone_legacy\helmets\phase2Pilot\data\visor_co.paa"
    };
};

class 42nd_WO3_Pilot_Helmet: 42nd_Pilot_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Pilot WO3 Helmet";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Pilot\42nd_W03_Pilot_Helmet_co.paa",
        "\ls\core\addons\characters_clone_legacy\helmets\phase2Pilot\data\visor_co.paa"
    };
};

class 42nd_ARF_Helmet: 42nd_Arf_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] ARF Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CT_ARF\42nd_ARF_Helmet_co.paa",
        "\JLTS_AE\Data\BaseTextures\ARF\Plates_CO.paa",
		"\JLTS_AE\Data\BaseTextures\ARF\ARF_Visor_CO.paa"
	};
};

class 42nd_Medic_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] P2 Medic Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_CT_Medic_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_CT_Medic_Helmet_co.paa"
    };
};

class 42nd_CVT_Medic_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] CVT Medic Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_CVT_Medic_Helmet.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_CVT_Medic_Helmet.paa"
    };
};

class 42nd_Squad_Medic_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Squad Medic Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_Squad_Medic_helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Medic\42nd_Squad_Medic_helmet_co.paa"
    };
};

class 42nd_Rose_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Rose's' Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Rose_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Rose_Helmet_co.paa"
    };
};

class 42nd_Hound_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] Hound Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Hound_Helmet_CO.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Hound_Helmet_CO.paa"
    };
    hiddenSelectionsMaterials[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Hound_Helmet.rvmat",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\Customs\42nd_Hound_Helmet.rvmat"
    };
};

class 42nd_CVT_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] CVT P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CVT\42nd_CVT_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\CVT\42nd_CVT_Helmet_co.paa"
    };
};

class 42nd_NCO_P2_Helmet: 42nd_Helmet_base
{
    scope = 2;
    scopeArsenal = 2;
    author = "HoundaCivic";
    displayName = "[42nd] NCO P2 Helmet";
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\NCO\42nd_NCO_Helmet_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Helmets\NCO\42nd_NCO_Helmet_co.paa"
    };
};
