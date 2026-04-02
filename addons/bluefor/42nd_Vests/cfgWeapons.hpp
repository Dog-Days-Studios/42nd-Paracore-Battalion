class IDA_Holster_2;
class IDA_KnifeHolster;
class IDA_Holster_1;
class IDA_vest_base;
class VestItem;
class JLTS_CloneVestAirborne;
class JLTS_CloneVestRecon;
class JLTS_CloneVestSuspender;
class JLTS_CloneVestReconOfficer;
class JLTS_CloneVestReconNCO;
class JLTS_CloneVestOfficer2;
class JLTS_CloneVestOfficer;
class JLTS_CloneVestLieutenant;
class JLTS_CloneVestKama;
class JLTS_CloneVestHolster;
class JLTS_CloneVestCommander;
class JLTS_CloneVestAirborneNCO;
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
        hiddenSelections[] = {"camo"};
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
        "\42nd_para\42nd\addons\bluefor\42nd_Vests\42nd_kama.paa",
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

#define C42_JLTS_VEST_ITEMINFO \
    class ItemInfo: VestItem \
    { \
        containerClass = "Supply250"; \
        mass = 25; \
        vestType = "Rebreather"; \
        class HitpointsProtectionInfo \
        { \
            class Chest \
            { \
                hitpointName = "HitChest"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
            class Diaphragm \
            { \
                hitpointName = "HitDiaphragm"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
            class Abdomen \
            { \
                hitpointName = "HitAbdomen"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
            class Body \
            { \
                hitpointName = "HitBody"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
            class Arms \
            { \
                hitpointName = "HitArms"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
            class Legs \
            { \
                hitpointName = "HitLegs"; \
                armor = 15; \
                passThrough = 0.1; \
                explosiveShielding = 6; \
            }; \
        }; \
    };

#define C42_DEFINE_JLTS_VEST(CLASSNAME, BASECLASS, DISPLAYNAME) \
class CLASSNAME: BASECLASS \
{ \
    author = "Hound"; \
    scope = 2; \
    scopeArsenal = 2; \
    scopeCurator = 2; \
    displayName = DISPLAYNAME; \
    C42_JLTS_VEST_ITEMINFO \
};

C42_DEFINE_JLTS_VEST(42nd_Heavy_Vest,JLTS_CloneVestAirborne,"[42nd] Heavy Vest")
C42_DEFINE_JLTS_VEST(42nd_Recon_Vest,JLTS_CloneVestRecon,"[42nd] Recon Vest")
C42_DEFINE_JLTS_VEST(42nd_Suspender_Vest,JLTS_CloneVestSuspender,"[42nd] Suspender Vest")
C42_DEFINE_JLTS_VEST(42nd_Recon_Officer_Vest,JLTS_CloneVestReconOfficer,"[42nd] Recon Officer Vest")
C42_DEFINE_JLTS_VEST(42nd_Recon_NCO_Vest,JLTS_CloneVestReconNCO,"[42nd] Recon NCO Vest")
C42_DEFINE_JLTS_VEST(42nd_Officer2_Vest,JLTS_CloneVestOfficer2,"[42nd] Officer 2 Vest")
C42_DEFINE_JLTS_VEST(42nd_Officer_Vest,JLTS_CloneVestOfficer,"[42nd] Officer Vest")
C42_DEFINE_JLTS_VEST(42nd_Lieutenant_Vest,JLTS_CloneVestLieutenant,"[42nd] Lieutenant Vest")
C42_DEFINE_JLTS_VEST(42nd_Kama_Vest,JLTS_CloneVestKama,"[42nd] Kama Vest")
C42_DEFINE_JLTS_VEST(42nd_Holster_Vest,JLTS_CloneVestHolster,"[42nd] Holster Vest")
C42_DEFINE_JLTS_VEST(42nd_Commander_Vest,JLTS_CloneVestCommander,"[42nd] Commander Vest")
C42_DEFINE_JLTS_VEST(42nd_Airborne_NCO_Vest,JLTS_CloneVestAirborneNCO,"[42nd] Airborne NCO Vest")

#undef C42_DEFINE_JLTS_VEST
#undef C42_JLTS_VEST_ITEMINFO
