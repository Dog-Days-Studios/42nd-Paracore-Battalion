class CfgPatches
{
    class Aux_42nd_ScionIntegration
    {
        name = "42nd Scion Integration";
        author = "HoundaCivic";
        requiredVersion = 2.10;
        requiredAddons[] = {"Aux_42nd", "sc_uniforms"};
        units[] = {"42nd_Warbot_Trooper"};
        weapons[] = {"42nd_Warbot_Uniform"};
        skipWhenMissingDependencies = 1;
    };
};

class CfgWeapons
{
    class ItemInfo;
    class SC_Warbot_Uniform;

    class 42nd_Warbot_Uniform: SC_Warbot_Uniform
    {
        author = "HoundaCivic";
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;
        displayName = "[42nd] Warbot Chassis";
        hiddenSelectionsTextures[] =
        {
            "\42nd_para\42nd\addons\scion_integration\data\warbot\Torso\DefaultMaterial_CO.paa",
            "\42nd_para\42nd\addons\scion_integration\data\warbot\Legs\DefaultMaterial_CO.paa"
        };
        class ItemInfo: ItemInfo
        {
            uniformClass = "42nd_Warbot_Trooper";
        };
    };
};

class CfgVehicles
{
    class WarbotUniform_dummy;

    class 42nd_Warbot_Trooper: WarbotUniform_dummy
    {
        author = "HoundaCivic";
        side = 1;
        scope = 2;
        scopeCurator = 2;
        displayName = "[42nd] Warbot";
        faction = "Fac42nd";
        editorSubcategory = "Sub42ndCustom";
        uniformClass = "42nd_Warbot_Uniform";
        hiddenSelectionsTextures[] =
        {
            "\42nd_para\42nd\addons\scion_integration\data\warbot\Torso\DefaultMaterial_CO.paa",
            "\42nd_para\42nd\addons\scion_integration\data\warbot\Legs\DefaultMaterial_CO.paa"
        };
        linkedItems[] = {"", "", "SWLB_clone_commander_binocular", "ItemMap", "ItemGPS", "ls_comlink_aur", "ItemCompass"};
        respawnLinkedItems[] = {"", "", "SWLB_clone_commander_binocular", "ItemMap", "ItemGPS", "ls_comlink_aur", "ItemCompass"};
        identityTypes[] = {"LanguageENG_F", "42nd_Clone_Face", "NoGlasses"};
    };
};
