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
class 42nd_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] P2 Private (DC15S)";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT\42nd_CT_Lower_Co.paa"};
    linkedItems[] = {"","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_CT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_CPLTL_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] Platoon Lead";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_CPLTL_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CPLTL\42nd_Platoon_Lead_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CPLTL\42nd_Platoon_Lead_Lower_co.paa"};
    linkedItems[] = {"","42nd_CPLTL_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_CPLTL_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_CSGT_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] Squad Lead";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_CSGT_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CSGT\42nd_Squad_Lead_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CSGT\42nd_Squad_Lead_Lower_co.paa"};
    linkedItems[] = {"","42nd_CSGT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_CSGT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_CST_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] CST";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_CST_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CST\42nd_CST_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CST\42nd_CST_Lower_co.paa"};
    linkedItems[] = {"","42nd_CST_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_CST_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_medic_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] P2 Medic (DC15S)";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_medic_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT_Medic\42nd_CT_Medic_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CT_Medic\42nd_CT_Medic_Lower_co.paa"};
    linkedItems[] = {"","42nd_Medic_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_Medic_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_Rose_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] Rose";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndCustom";
    uniformclass = "42nd_Rose_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Rose_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\customs\42nd_Rose_Lower_co.paa"};
    linkedItems[] = {"","42nd_Customs_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_Customs_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_CVT_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] CVT";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_CVT_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CVT\42nd_CVT_Upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\CVT\42nd_CVT_Lower_co.paa"};
    linkedItems[] = {"","42nd_CVT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_CVT_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};

class 42nd_NCO_Trooper: IDA_Clone_DC15S
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    displayName = "[42nd] NCO";
    faction = "Fac42nd";
    editorSubcategory = "Sub42ndMen";
    uniformclass = "42nd_NCO_Trooper_Uniform";
    //backpack = "42nd_Rucksack";
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\NCO\42nd_NCO_upper_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_Uniforms\NCO\42nd_NCO_Lower_co.paa"};
    linkedItems[] = {"","42nd_NCO_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
    respawnLinkedItems[] = {"","42nd_NCO_P2_Helmet","SWLB_clone_commander_binocular","ItemMap","ItemGPS","ls_comlink_aur","ItemCompass"};
};
