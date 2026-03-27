class IDA_Holster_2;
class IDA_KnifeHolster;
class IDA_Holster_1;
class IDA_vest_base;
class VestItem;

class 42nd_Dual_Holsters: IDA_Holster_2
{
    author = "Hound";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[42nd] Dual DC-17 Holsters";
    model = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Holster_2.p3d";
    picture = "\Indecisive_Armoury_units\REPUBLIC\vests\Holster_UI.paa";
    hiddenSelectionsTextures[] = {"\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_Holster\IDA_Holster_co.paa"};
    class ItemInfo: VestItem
    {
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Holster_2.p3d";
        containerClass = "Supply200";
        hiddenSelections[] = {"camo"};
        mass = 15;
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.08975;
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.08975;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.08975;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.08975;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.08975;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.08975;
            };
        };
    };
};

class 42nd_Knife_Holster: IDA_KnifeHolster
{
    author = "Hound";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[42nd] Knife Holster";
    model = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_KnifeHolster.p3d";
    picture = "\Indecisive_Armoury_units\REPUBLIC\vests\KnifeHolster_UI.paa";
    hiddenSelections[] = {"holster", "knife"};
    hiddenSelectionsTextures[] =
    {
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_Holster\IDA_KnifeHolster_co.paa",
        "\Indecisive_Armoury_Melee\Data\Clone_Knife\Textures\Clone_Hunting_Knife_co.paa"
    };
    class ItemInfo: VestItem
    {
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_KnifeHolster.p3d";
        containerClass = "Supply200";
        hiddenSelections[] = {"holster", "knife"};
        mass = 15;
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.08975;
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.08975;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.08975;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.08975;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.08975;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.08975;
            };
        };
    };
};

class 42nd_Holster: IDA_Holster_1
{
    author = "Hound";
    scope = 2;
    scopeArsenal = 2;
    displayName = "[42nd] Holster";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_Holster\IDA_Holster_co.paa"};
    class ItemInfo: VestItem
    {
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Holster_1.p3d";
        containerClass = "Supply150";
        mass = 80;
        hiddenSelections[] = {"camo1"};
        class HitpointsProtectionInfo
        {
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Pelvis
            {
                hitpointName = "HitPelvis";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.2;
                explosiveShielding = 12;
            };
        };
    };
};

class 42nd_Hidden_Vest: IDA_vest_base
{
    author = "Hound";
    displayName = "[42nd] Standard Armor Plating";
    model = "";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    picture = "\Indecisive_Armoury_units\Plate_UI.paa";
    class ItemInfo: VestItem
    {
        uniformModel = "";
        containerClass = "Supply200";
        mass = 15;
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
        };
    };
};

class 42nd_Hidden_Medical_Vest: IDA_vest_base
{
    author = "Hound";
    displayName = "[42nd] Medical Armor Plating";
    model = "";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    picture = "\Indecisive_Armoury_units\Plate_UI.paa";
    class ItemInfo: VestItem
    {
        uniformModel = "";
        containerClass = "Supply250";
        mass = 15;
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
        };
    };
};

class 42nd_KamaCW_Vest: IDA_vest_base
{
    author = "Hound";
    scope = 2;
    scopeArsenal = 2;
    scopeCurator = 2;
    displayName = "[42nd] Kama CW Vest";
    model = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Vests.p3d";
    picture = "\Indecisive_Armoury_units\REPUBLIC\vests\KamaCW_UI.paa";
    hiddenSelections[] =
    {
        "Recon_Harness",
        "GrenadeBag",
        "KamaCW",
        "KamaEp3",
        "PauldronCW_L",
        "PauldronCW_R",
        "PauldronEp3_L",
        "PauldronEp3_R",
        "PauldronAccessory",
        "ArmPouches_L",
        "ArmPouches_R",
        "SuspenderL",
        "SuspenderR",
        "ChestPadR",
        "ShoulderPadR",
        "PauldronARC"
    };
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_kama.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
    class ItemInfo: VestItem
    {
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Vests.p3d";
        containerClass = "Supply220";
        mass = 25;
        hiddenSelections[] =
        {
            "Recon_Harness",
            "GrenadeBag",
            "KamaCW",
            "KamaEp3",
            "PauldronCW_L",
            "PauldronCW_R",
            "PauldronEp3_L",
            "PauldronEp3_R",
            "PauldronAccessory",
            "ArmPouches_L",
            "ArmPouches_R",
            "SuspenderL",
            "SuspenderR",
            "ChestPadR",
            "ShoulderPadR",
            "PauldronARC"
        };
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest
            {
                hitpointName = "HitChest";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Body
            {
                hitpointName = "HitBody";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Arms
            {
                hitpointName = "HitArms";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
            class Legs
            {
                hitpointName = "HitLegs";
                armor = 15;
                passThrough = 0.1;
                explosiveShielding = 6;
            };
        };
    };
};

class 42nd_Basic_KamaCW_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] Basic Kama CW Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_Basic_Kama_CW.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_EOD_KamaCW_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] EOD Kama CW Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_EOD_Kama_CW_Co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_EOD_Kama_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] EOD Kama Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_EOD_Kama_ep3.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Marksman_Kama_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] Marksman Kama Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_Marksman_Kama.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Medic_Kama_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] Medic Kama Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_Medic_Kama.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Medic_KamaCW_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] Medic Kama CW Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_Medic_Kama_CW.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Rose_Kama_Vest: 42nd_KamaCW_Vest
{
    displayName = "[42nd] Rose Kama Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\addons\bluefor\42nd_Vests\42nd_Rose_Kama_co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Officer_Pauldron_Vest_Base: IDA_vest_base
{
    author = "Hound";
    scope = 0;
    scopeArsenal = 0;
    scopeCurator = 0;
    displayName = "[42nd] Officer Pauldron";
    model = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Vests.p3d";
    picture = "\Indecisive_Armoury_Units\REPUBLIC\Vests\pauldronCW_ui.paa";
    hiddenSelections[] =
    {
        "Recon_Harness",
        "GrenadeBag",
        "KamaCW",
        "KamaEp3",
        "PauldronCW_L",
        "PauldronCW_R",
        "PauldronEp3_L",
        "PauldronEp3_R",
        "PauldronAccessory",
        "ArmPouches_L",
        "ArmPouches_R",
        "SuspenderL",
        "SuspenderR",
        "ChestPadR",
        "ShoulderPadR",
        "PauldronARC"
    };
    class ItemInfo: VestItem
    {
        uniformModel = "\Indecisive_Armoury_units\REPUBLIC\Vests\IDA_Vests.p3d";
        containerClass = "Supply220";
        mass = 25;
        hiddenSelections[] =
        {
            "Recon_Harness",
            "GrenadeBag",
            "KamaCW",
            "KamaEp3",
            "PauldronCW_L",
            "PauldronCW_R",
            "PauldronEp3_L",
            "PauldronEp3_R",
            "PauldronAccessory",
            "ArmPouches_L",
            "ArmPouches_R",
            "SuspenderL",
            "SuspenderR",
            "ChestPadR",
            "ShoulderPadR",
            "PauldronARC"
        };
        vestType = "Rebreather";
        class HitpointsProtectionInfo
        {
            class Chest { hitpointName = "HitChest"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
            class Diaphragm { hitpointName = "HitDiaphragm"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
            class Abdomen { hitpointName = "HitAbdomen"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
            class Body { hitpointName = "HitBody"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
            class Arms { hitpointName = "HitArms"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
            class Legs { hitpointName = "HitLegs"; armor = 15; passThrough = 0.1; explosiveShielding = 6; };
        };
    };
};

class 42nd_Officer_PauldronCW_L_Vest: 42nd_Officer_Pauldron_Vest_Base
{
    scope = 2;
    scopeArsenal = 2;
    scopeCurator = 2;
    displayName = "[42nd] Officer Pauldron CW (L) Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_KamaCW\IDA_KamaCW_co.paa",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_PauldronCW\IDA_PauldronCW_co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Officer_PauldronCW_R_Vest: 42nd_Officer_Pauldron_Vest_Base
{
    scope = 2;
    scopeArsenal = 2;
    scopeCurator = 2;
    displayName = "[42nd] Officer Pauldron CW (R) Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_KamaCW\IDA_KamaCW_co.paa",
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_PauldronCW\IDA_PauldronCW_co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Officer_PauldronEp3_L_Vest: 42nd_Officer_Pauldron_Vest_Base
{
    scope = 2;
    scopeArsenal = 2;
    scopeCurator = 2;
    displayName = "[42nd] Officer Pauldron Ep3 (L) Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_KamaCW\IDA_KamaCW_co.paa",
        "",
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_PauldronEp3\IDA_PauldronEp3_co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Officer_PauldronEp3_R_Vest: 42nd_Officer_Pauldron_Vest_Base
{
    scope = 2;
    scopeArsenal = 2;
    scopeCurator = 2;
    displayName = "[42nd] Officer Pauldron Ep3 (R) Vest";
    hiddenSelectionsTextures[] =
    {
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_KamaCW\IDA_KamaCW_co.paa",
        "",
        "",
        "",
        "",
        "\Indecisive_Armoury_Units\REPUBLIC\Vests\IDA_PauldronEp3\IDA_PauldronEp3_co.paa",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };
};

class 42nd_Officer_Pauldron_Vest: 42nd_Officer_PauldronEp3_L_Vest
{
    displayName = "[42nd] Officer Pauldron Vest";
};
