/// Magazines macros definition ///
#define mag_2(a) a, a
#define mag_3(a) a, a, a
#define mag_4(a) a, a, a, a
#define mag_5(a) a, a, a, a, a
#define mag_6(a) a, a, a, a, a, a
#define mag_7(a) a, a, a, a, a, a, a
#define mag_8(a) a, a, a, a, a, a, a, a
#define mag_9(a) a, a, a, a, a, a, a, a, a
#define mag_10(a) a, a, a, a, a, a, a, a, a, a
#define mag_11(a) a, a, a, a, a, a, a, a, a, a, a
#define mag_12(a) a, a, a, a, a, a, a, a, a, a, a, a

#define mag_xx(a,b) class _xx_##a {magazine = a; count = b;}
#define weap_xx(a,b) class _xx_##a {weapon = a; count = b;}
#define item_xx(a,b) class _xx_##a {name = a; count = b;}

class IDA_Clone_DC15S;
class ls_clone_phase2_pilot;

class 42nd_Pilot_base: ls_clone_phase2_pilot
{
    author = "Hound";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Pilot";
    faction = "Fac42nd_INF";
    editorSubcategory = "Sub42ndAirCrew";
    uniformClass = "42nd_Pilot_Trooper_Uniform";
    identityTypes[] = {"42nd_Clone_Face"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Lower_Co.paa"};
    backpack = "42nd_MiniLR_Backpack";
    linkedItems[] = {"42nd_Holster","42nd_WO1_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_WO1_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
}
class 42nd_Trainee_Pilot: 42nd_Pilot_base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Pilot Trainee";
    backpack = "42nd_MiniLR_Backpack";
    linkedItems[] = {"42nd_Holster","42nd_Trainee_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Trainee_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_WO1_Pilot: 42nd_Pilot_base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Pilot WO1";
    backpack = "42nd_MiniLR_Backpack";
    linkedItems[] = {"42nd_Holster","42nd_WO1_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_WO1_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_WO2_Pilot: 42nd_Pilot_base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Pilot WO2";
    backpack = "42nd_MiniLR_Backpack";
    linkedItems[] = {"42nd_Holster","42nd_WO2_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_WO2_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_WO3_Pilot: 42nd_Pilot_base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Pilot WO3";
    backpack = "42nd_MiniLR_Backpack";
    linkedItems[] = {"42nd_Holster","42nd_WO3_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_WO3_Pilot_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_Clone_Base: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 1;
    scopeCurator = 0;
    faction = "Fac42nd_INF";
    vehicleClass = "Men";
    identityTypes[] = {"42nd_Clone_Face"};
    linkedItems[] = {"42nd_Holster","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
}
};

class 42nd_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Clone Trooper";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Lower_Co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Standard_Backpack";
};

class 42nd_CPLTL_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Platoon Lead";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_CPLTL_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CPLTL\42nd_Platoon_Lead_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CPLTL\42nd_Platoon_Lead_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CPLTL_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CPLTL_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Standard_Backpack";
};

class 42nd_CSGT_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Squad Lead";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_CSGT_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CSGT\42nd_Squad_Lead_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CSGT\42nd_Squad_Lead_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CSGT_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CSGT_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Standard_Backpack";
};

class 42nd_CST_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Senior Trooper";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_CST_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CST\42nd_CST_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CST\42nd_CST_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CST_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CST_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Standard_Backpack";
};

class 42nd_medic_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Medic";
    editorSubcategory = "Sub42ndMedics";
    uniformClass = "42nd_medic_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_CT_Medic_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_CT_Medic_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Medic_Backpack";
};

class 42nd_CVT_Medic_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Veteran Medic";
    editorSubcategory = "Sub42ndMedics";
    uniformClass = "42nd_CVT_Medic_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_CVT_Medic_Upper.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_CVT_Medic_lower.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CVT_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CVT_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Medic_Backpack";
};

class 42nd_Squad_Medic_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Squad Medic";
    editorSubcategory = "Sub42ndMedics";
    uniformClass = "42nd_Squad_Medic_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_Squad_Medic_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Medic\42nd_Squad_Medic_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Squad_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Squad_Medic_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Medic_Backpack";
};

class 42nd_Rose_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Rose";
    editorSubcategory = "Sub42ndCustom";
    uniformClass = "42nd_Rose_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Rose_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Rose_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Rose_P2_Helmet","42nd_Rose_Kama_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Rose_P2_Helmet","42nd_Rose_Kama_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    backpack = "42nd_Medic_Backpack";
};

class 42nd_Hound_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Hound";
    editorSubcategory = "Sub42ndCustom";
    uniformClass = "42nd_Hound_Trooper_Uniform";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Hound_Upper_CO.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Hound_Lower_CO.paa"
    };
    hiddenSelectionsMaterials[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Hound_Upper.rvmat",
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Hound_Lower.rvmat"
    };
    linkedItems[] = {"42nd_Holster","42nd_Hound_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Hound_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_Walker_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Walker";
    editorSubcategory = "Sub42ndCustom";
    uniformClass = "42nd_Walker_Trooper_Uniform";
    hiddenSelectionsTextures[] =
    {
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Walker_Upper_co.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Walker_Lower_co.paa"
    };
    linkedItems[] = {"42nd_Holster","42nd_Walker_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Walker_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_CVT_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Veteran Trooper";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_CVT_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CVT\42nd_CVT_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CVT\42nd_CVT_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_CVT_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_CVT_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_NCO_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] NCO";
    editorSubcategory = "Sub42ndBasic_Squad";
    uniformClass = "42nd_NCO_Trooper_Uniform";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\NCO\42nd_NCO_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\NCO\42nd_NCO_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_NCO_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_NCO_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_EOD_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] EOD";
    editorSubcategory = "Sub42ndEOD";
    uniformClass = "42nd_EOD_Trooper_Uniform";
    backpack = "42nd_Grenade_rig";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_EOD_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_EOD_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_EOD_Vet_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Veteran EOD Trooper";
    editorSubcategory = "Sub42ndEOD";
    uniformClass = "42nd_EOD_Vet_Trooper_Uniform";
    backpack = "42nd_Grenade_rig";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Vet_Upper.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Vet_Lower.paa"};
    linkedItems[] = {"42nd_Holster","42nd_EOD_Vet_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_EOD_Vet_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_EOD_Squad_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Squad EOD Trooper";
    editorSubcategory = "Sub42ndEOD";
    uniformClass = "42nd_EOD_Squad_Trooper_Uniform";
    backpack = "42nd_Grenade_rig";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Squad_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Squad_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_EOD_Squad_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_EOD_Squad_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_EOD_Senior_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Senior EOD Trooper";
    editorSubcategory = "Sub42ndEOD";
    uniformClass = "42nd_EOD_Senior_Trooper_Uniform";
    backpack = "42nd_Grenade_rig";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Senior_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\EOD\42nd_EOD_Senior_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_EOD_Senior_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_EOD_Senior_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_Marksman_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Marksman";
    editorSubcategory = "Sub42ndMarksman";
    role = "Marksman";
    uniformClass = "42nd_Marksman_Trooper_Uniform";
    backpack = "42nd_Standard_Backpack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Marksman_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Marksman_P2_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    weapons[] = {"42nd_DC15X","Throw","Put"};
    respawnWeapons[] = {"42nd_DC15X","Throw","Put"};
    magazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
    respawnMagazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
};

class 42nd_Marksman_Vet_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Veteran Marksman ";
    editorSubcategory = "Sub42ndMarksman";
    role = "Marksman";
    uniformClass = "42nd_Marksman_Vet_Trooper_Uniform";
    backpack = "42nd_Standard_Backpack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_marksman_vet_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_vet_lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Marksman_Vet_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Marksman_Vet_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    weapons[] = {"42nd_DC15X","Throw","Put"};
    respawnWeapons[] = {"42nd_DC15X","Throw","Put"};
    magazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
    respawnMagazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
};

class 42nd_Marksman_Squad_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Squad Marksman ";
    editorSubcategory = "Sub42ndMarksman";
    role = "Marksman";
    uniformClass = "42nd_Marksman_Squad_Trooper_Uniform";
    backpack = "42nd_Standard_Backpack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_Squad_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_Squad_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Marksman_Squad_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Marksman_Squad_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    weapons[] = {"42nd_DC15X","Throw","Put"};
    respawnWeapons[] = {"42nd_DC15X","Throw","Put"};
    magazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
    respawnMagazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
};

class 42nd_Marksman_Senior_Trooper: 42nd_Clone_Base
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Marksman Senior";
    editorSubcategory = "Sub42ndMarksman";
    role = "Marksman";
    uniformClass = "42nd_Marksman_Senior_Trooper_Uniform";
    backpack = "42nd_Standard_Backpack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_Senior_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\Marksman\42nd_Marksman_Senior_Lower_co.paa"};
    linkedItems[] = {"42nd_Holster","42nd_Marksman_Senior_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"42nd_Holster","42nd_Marksman_Senior_Helmet","42nd_KamaCW_Glasses","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    weapons[] = {"42nd_DC15X","Throw","Put"};
    respawnWeapons[] = {"42nd_DC15X","Throw","Put"};
    magazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
    respawnMagazines[] = {mag_6("42nd_Sniper_Cell_10Round_Blue"),"IDA_grenade_Smoke_Green_mag","IDA_grenade_Smoke_Blue_mag","IDA_grenade_Smoke_Red_mag","IDA_grenade_Smoke_mag","IDA_grenade_Detonator_mag"};
};
