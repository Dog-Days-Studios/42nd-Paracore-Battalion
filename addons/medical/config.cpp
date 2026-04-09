class CfgPatches
{
    class Aux_42nd_Medical
    {
        name = "42nd Medical";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] =
        {
            "cba_main",
            "ace_common",
            "ace_medical_treatment",
            "kat_pharma",
            "kat_vitals",
            "3AS_Equipment"
        };
        units[] =
        {
            "42nd_BactaItem",
            "42nd_RedBactaItem",
            "42nd_MedKitItem",
            "42nd_PlasmaIV_1500Item",
            "42nd_PlasmaIV_2000Item"
        };
        weapons[] =
        {
            "42nd_Bacta",
            "42nd_Bacta_Red",
            "42nd_MedKit",
            "42nd_PlasmaIV_1500",
            "42nd_PlasmaIV_2000"
        };
        magazines[] =
        {
            "42nd_TXAGas_Grenade"
        };
        ammo[] =
        {
            "42nd_TXAGas_Ammo"
        };
    };
};

class CfgFunctions
{
    class Para42
    {
        class Medical
        {
            file = "\42nd_para\42nd\addons\medical\functions";
            class handleTxaGasGrenadeFired {};
            class trackTxaGasGrenade {};
            class applyTxaGasServer {};
        };
    };
};

class CfgAmmo
{
    class SmokeShell;

    class 42nd_TXAGas_Ammo: SmokeShell
    {
        author = "HoundaCivic";
        displayName = "[42nd] TXA Gas";
        hit = 0;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = 0;
        explosive = 0;
        cost = 0;
        model = "\3AS\3AS_Equipment\model\3AS_smokegrenade.p3d";
        explosionEffects = "";
        SoundSetExplosion[] = {};
        multiSoundHit[] = {};
        craterEffects = "";
        effectsSmoke = "SmokeShellPurpleEffect";
        smokeColor[] = {0.72, 0.82, 1, 1};
        timeToLive = 45;
        explosionTime = 2.2;
        ace_frag_enabled = 0;
        Para42_isTxaGas = 1;
        Para42_txaRadius = 10;
        Para42_txaCloudDuration = 12;
        Para42_txaTickInterval = 0.5;
        Para42_txaExposureTime = 4;
    };
};

class CfgMagazines
{
    class SmokeShell;

    class 42nd_TXAGas_Grenade: SmokeShell
    {
        author = "HoundaCivic";
        scope = 2;
        displayName = "[42nd] TXA Gas Grenade";
        displayNameShort = "TXA Gas";
        descriptionShort = "Gas grenade that applies TXA after sustained exposure.";
        ammo = "42nd_TXAGas_Ammo";
        model = "\3AS\3AS_Equipment\model\3AS_smokegrenade.p3d";
        picture = "\3AS\3AS_Equipment\UI\Nacht5_Smoke_UI_ca.paa";
        mass = 4;
        count = 1;
        initSpeed = 20;
        nameSound = "smokeshell";
        sound[] = {"", 0.000316228, 1};
        maxLeadSpeed = 7;
    };
};

class CfgWeapons
{
    class ACE_fieldDressing;
    class ACE_personalAidKit;
    class ACE_plasmaIV;
    class CBA_MiscItem_ItemInfo;
    class GrenadeLauncher;
    class Throw: GrenadeLauncher
    {
        class ThrowMuzzle;
        muzzles[] += {"42nd_TXAGas_Muzzle"};

        class 42nd_TXAGas_Muzzle: ThrowMuzzle
        {
            displayName = "[42nd] TXA Gas";
            model = "\3AS\3AS_Equipment\model\3AS_smokegrenade.p3d";
            magazines[] = {"42nd_TXAGas_Grenade"};

            class EventHandlers
            {
                class Para42_TXAGas
                {
                    Fired = "_this call Para42_fnc_handleTxaGasGrenadeFired;";
                };
            };
        };
    };

    class 42nd_MedKit: ACE_personalAidKit
    {
        scope = 2;
        author = "HoundaCivic";
        displayName = "[42nd] MedKit";
        picture = "\MRC\JLTS\contraband\Drugs\data\ui\medikit_ui_ca.paa";
        model = "\MRC\JLTS\contraband\Drugs\medikit.p3d";
        descriptionShort = "Compact treatment kit loaded with clone medical supplies.";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 20;
        };
    };

    class 42nd_Bacta: ACE_fieldDressing
    {
        scope = 2;
        author = "HoundaCivic";
        model = "\MRC\JLTS\contraband\Drugs\bacta.p3d";
        picture = "\MRC\JLTS\contraband\Drugs\data\ui\bacta_ui_ca.paa";
        displayName = "[42nd] Bacta Canister";
        descriptionShort = "Fast-acting bacta treatment that bandages wounds and administers TXA.";
        descriptionUse = "Injecting bacta...";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 2;
        };
    };

    class 42nd_Bacta_Red: ACE_fieldDressing
    {
        scope = 2;
        author = "HoundaCivic";
        model = "\MRC\JLTS\contraband\Drugs\bacta.p3d";
        picture = "\MRC\JLTS\contraband\Drugs\data\ui\bacta_red_ui_ca.paa";
        displayName = "[42nd] Red Bacta";
        descriptionShort = "Dense bacta treatment tuned for severe trauma care.";
        descriptionUse = "Applying red bacta...";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 2;
        };
    };

    class 42nd_PlasmaIV_1500: ACE_plasmaIV
    {
        scope = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Plasma IV (1500mL)";
        descriptionShort = "Expanded plasma IV bag for large-volume clone trauma response.";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 8;
        };
    };

    class 42nd_PlasmaIV_2000: ACE_plasmaIV
    {
        scope = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Plasma IV (2000mL)";
        descriptionShort = "Maximum-capacity plasma IV bag for extended stabilization.";
        class ItemInfo: CBA_MiscItem_ItemInfo
        {
            mass = 10;
        };
    };
};

class CfgVehicles
{
    class ACE_fieldDressingItem;
    class ACE_personalAidKitItem;
    class ACE_plasmaIVItem;

    class 42nd_BactaItem: ACE_fieldDressingItem
    {
        scope = 2;
        scopeCurator = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Bacta";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_42nd_Bacta
            {
                name = "42nd_Bacta";
                count = 1;
            };
        };
    };

    class 42nd_RedBactaItem: ACE_fieldDressingItem
    {
        scope = 2;
        scopeCurator = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Red Bacta";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_42nd_Bacta_Red
            {
                name = "42nd_Bacta_Red";
                count = 1;
            };
        };
    };

    class 42nd_MedKitItem: ACE_personalAidKitItem
    {
        scope = 2;
        scopeCurator = 2;
        author = "HoundaCivic";
        displayName = "[42nd] MedKit";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_42nd_MedKit
            {
                name = "42nd_MedKit";
                count = 1;
            };
        };
    };

    class 42nd_PlasmaIV_1500Item: ACE_plasmaIVItem
    {
        scope = 2;
        scopeCurator = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Plasma IV (1500mL)";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_42nd_PlasmaIV_1500
            {
                name = "42nd_PlasmaIV_1500";
                count = 1;
            };
        };
    };

    class 42nd_PlasmaIV_2000Item: ACE_plasmaIVItem
    {
        scope = 2;
        scopeCurator = 2;
        author = "HoundaCivic";
        displayName = "[42nd] Plasma IV (2000mL)";
        vehicleClass = "Items";
        class TransportItems
        {
            class _xx_42nd_PlasmaIV_2000
            {
                name = "42nd_PlasmaIV_2000";
                count = 1;
            };
        };
    };
};

class ACE_Medical_Treatment
{
    class Bandaging
    {
        class BasicBandage;

        class 42nd_Bacta: BasicBandage
        {
            effectiveness = 6;
            reopeningChance = 0;
            reopeningMinDelay = 0;
            reopeningMaxDelay = 0;
        };

        class 42nd_Bacta_Red: BasicBandage
        {
            effectiveness = 7;
            reopeningChance = 0;
            reopeningMinDelay = 0;
            reopeningMaxDelay = 0;
        };
    };

    class IV
    {
        class PlasmaIV;

        class 42nd_PlasmaIV_1500: PlasmaIV
        {
            volume = 1500;
            ratio[] = {"Blood", 1};
            type = "Plasma";
        };

        class 42nd_PlasmaIV_2000: 42nd_PlasmaIV_1500
        {
            volume = 2000;
        };
    };
};

class ACE_Medical_Treatment_Actions
{
    class BasicBandage;
    class PersonalAidKit;
    class PlasmaIV;

    class 42nd_Bacta: BasicBandage
    {
        displayName = "Inject [42nd] Bacta";
        displayNameProgress = "Injecting [42nd] Bacta...";
        treatmentTime = 4;
        items[] = {"42nd_Bacta"};
        callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_bandage; [_patient, _bodyPart, 'TXA'] call kat_pharma_fnc_medicationLocal;";
        animationCaller = "AinvPknlMstpSlayWrflDnon_medic1";
        icon = "\MRC\JLTS\contraband\Drugs\data\ui\bacta_ui_ca.paa";
        litter[] = {{}, {"ACE_MedicalLitter_clean"}};
    };

    class 42nd_Bacta_Red: BasicBandage
    {
        displayName = "Apply [42nd] Red Bacta";
        displayNameProgress = "Applying [42nd] Red Bacta...";
        treatmentTime = 5;
        items[] = {"42nd_Bacta_Red"};
        callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_bandage;";
        animationCaller = "AinvPknlMstpSlayWrflDnon_medic1";
        icon = "\MRC\JLTS\contraband\Drugs\data\ui\bacta_red_ui_ca.paa";
        litter[] = {{}, {"ACE_MedicalLitter_clean"}};
    };

    class 42nd_MedKit: PersonalAidKit
    {
        displayName = "Use [42nd] MedKit";
        displayNameProgress = "Using [42nd] MedKit...";
        items[] = {"42nd_MedKit"};
        icon = "\MRC\JLTS\contraband\Drugs\data\ui\medikit_ui_ca.paa";
    };

    class 42nd_PlasmaIV_1500: PlasmaIV
    {
        displayName = "Use [42nd] Plasma IV (1500mL)";
        displayNameProgress = "Infusing [42nd] Plasma IV (1500mL)...";
        items[] = {"42nd_PlasmaIV_1500"};
    };

    class 42nd_PlasmaIV_2000: PlasmaIV
    {
        displayName = "Use [42nd] Plasma IV (2000mL)";
        displayNameProgress = "Infusing [42nd] Plasma IV (2000mL)...";
        items[] = {"42nd_PlasmaIV_2000"};
    };
};

