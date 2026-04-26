class ls_cloneBackpack_jt12;
class IDA_Clone_GrenadeRig;
class IDA_Clone_ScoutPack;
class ls_cloneBackpack_rocket;
class ls_cloneBackpack_radio;
class ls_cloneBackpack_standard;
class ls_cloneBackpack_ammo;
class ls_cloneBackpack_heavy;
class ls_cloneBackpack_miniLR;
class ls_backpack_chestRig;
class ls_backpack_chestRigPouch;
class ls_gar_beltBag;
class ls_gar_beltBag_belt;
class ls_gar_beltBag_leg;
class JLTS_Clone_LR_attachment;
class JLTS_Clone_belt_bag;
class ls_cloneBackpack_medic;
class JLTS_portable_shield_gar_backpack;
class IDA_Clone_Rucksack;
class 42nd_Portable_Shield_Backpack: JLTS_portable_shield_gar_backpack
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Portable Shield Backpack";
};
class 42nd_JT12: ls_cloneBackpack_jt12
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] JT-12 Jetpack";
    hiddenSelections[] = {"camo1"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_JT12_CO.paa"};
};

class 42nd_Grenade_rig: IDA_Clone_GrenadeRig
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Grenade Rig";
    maximumload = 250;
};

class 42nd_Standard_Backpack: ls_cloneBackpack_standard
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Backpack";
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
    hiddenSelectionsTextures[] = {
        "\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa",
        "\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","","","","","","","","",""
    };
    maximumload = 250;
};
class 42nd_IDA_Backpack: IDA_Clone_Rucksack
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Rucksack";
    hiddenSelections[] = {"Rucksack","Grenade","Cloth"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_Rucksack_co.paa","\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_Backpack_cloth_CO.paa"};
    maximumload = 250;
};
class 42nd_Rocket_Backpack: ls_cloneBackpack_rocket
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Rocket Backpack";
    maximumload = 350;
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa",
    "",
    "",
    "\ls\core\addons\characters_clone\backpacks\standard\data\rockets_co.paa"};
};

class 42nd_Radio_Backpack: ls_cloneBackpack_radio
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Radio Backpack";
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa",
    "",
    "\ls\core\addons\characters_clone\backpacks\standard\data\radio_co.paa"};
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_west_radio_code";
		tf_hasLRradio = 1;
		tf_range = 50000;
		tf_subtype = "digital_lr";
};
class 42nd_Medic_Backpack: ls_cloneBackpack_medic
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    maximumload = 350;
    displayName = "[42nd] Medic Backpack";
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa",
    "\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","","",
    "\ls\core\addons\characters_clone\backpacks\standard\data\medic_CO.paa",
    "\ls\core\addons\characters_clone\backpacks\standard\data\bacta_CO.paa"};
};
class 42nd_Heavy_Backpack: ls_cloneBackpack_heavy
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Heavy Backpack";
    maximumload = 350;
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","
bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","","","","","","\ls\core\addons\characters_clone\backpacks\standard\data\heavy_CO.paa"};
};
class 42nd_Ammo_Backpack: ls_cloneBackpack_ammo
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Ammo Backpack";
    maximumload = 350;
    hiddenSelections[] = {"backpack","cloth","radio","rockets","medic","
bacta","ammo","heavy","supplies","lower_supplies","canister","grenade"};
hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_NewMod_Backpack_co_CO.paa","","","","","\ls\core\addons\characters_clone\backpacks\standard\data\ammo_co.paa"};
};
class 42nd_MiniLR_Backpack: ls_cloneBackpack_miniLR
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Mini LR Backpack";
    hiddenSelections[] = {"camo1"};
    maximumload = 250;
    hiddenSelectionsTextures[] = {"\42nd_para\42nd\addons\Bluefor\42nd_backpacks\42nd_MinirLR_Module_CO.paa"};
		tf_dialog = "JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode = "tf_west_radio_code";
		tf_hasLRradio = 1;
		tf_range = 50000;
		tf_subtype = "digital_lr";
};
class 42nd_Rucksack: IDA_Clone_ScoutPack
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    maximumload = 250;
    displayName = "[42nd] Rucksack";
};
class 42nd_ChestRig: ls_backpack_chestRig
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Chest Rig";
    maximumload = 250;
};
class 42nd_ChestRig_Pouch: ls_backpack_chestRigPouch
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Chest Rig Pouch";
    maximumload = 250;
};
class 42nd_BeltBag: ls_gar_beltBag
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Belt Bag";
    maximumload = 250;
};
class 42nd_BeltBag_Belt: ls_gar_beltBag_belt
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Belt Bag (Belt)";
    maximumload = 250;
};
class 42nd_BeltBag_Leg: ls_gar_beltBag_leg
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Belt Bag (Leg)";
    maximumload = 250;
};

class 42nd_LR_Attachment: JLTS_Clone_LR_attachment
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] LR Attachment";
    maximumload = 250;
    tf_dialog = "JLTS_clone_rto_radio_dialog";
    tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel;";
	tf_encryptionCode = "tf_west_radio_code";
	tf_hasLRradio = 1;
	tf_range = 50000;
	tf_subtype = "digital_lr";
};
class 42nd_BeltBag_Attachment: JLTS_Clone_belt_bag
{
    author = "Hound";
    scope = 2;
    scopecurator = 2;
    scopearsenal = 2;
    displayName = "[42nd] Belt Bag Attachment";
    maximumload = 250;
};
