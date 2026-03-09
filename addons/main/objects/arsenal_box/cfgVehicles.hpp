class ls_carrybox_base;
class b_supplyCrate_F;
class 3as_Small_Box_9_Prop;

class 42nd_Arsenal_Box: ls_carrybox_base
{
    author = "Hound";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Full Arsenal Box";
    editorCategory = "42nd_Objects";
    editorSubcategory = "SUB42ndOBJ";
    class UserActions
    {
        class 42nd_Healstation_Heal
        {
            userActionID = 10;
            displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Receive Medical Attention</t>";
            radius = 15;
            priority = 100;
            onlyForPlayer = 1;
            position = "";
            condition = "isNull objectParent player";
            statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
        };
        class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 11;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", true];";
        };
        class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 12;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", false];";
        };
        class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 13;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", true];";
        };
        class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 14;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", false];";
        };
        class 42nd_GiveEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 15;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
            condition = "(isNull objectParent player) && (!(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", true]; player setUnitTrait [""explosiveSpecialist"", true];";
        };
        class 42nd_TakeEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 16;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
            condition = "(isNull objectParent player) && ((player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", false]; player setUnitTrait [""explosiveSpecialist"", false];";
        };
        class 42nd_Arsenal: 42nd_Healstation_Heal
        {
            userActionID = 17;
            displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>ACE Arsenal</t>";
            condition = "isNull objectParent player";
            statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
        };
    };
};

class 42nd_Arsenal_Supply: b_supplyCrate_F
{
    author = "Hound";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Full Arsenal Supply Crate";
    editorCategory = "42nd_Objects";
    editorSubcategory = "SUB42ndOBJ";
    class UserActions
    {
        class 42nd_Healstation_Heal
        {
            userActionID = 10;
            displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Receive Medical Attention</t>";
            radius = 15;
            priority = 100;
            onlyForPlayer = 1;
            position = "";
            condition = "isNull objectParent player";
            statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
        };
        class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 11;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", true];";
        };
        class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 12;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", false];";
        };
        class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 13;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", true];";
        };
        class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 14;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", false];";
        };
        class 42nd_GiveEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 15;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
            condition = "(isNull objectParent player) && (!(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", true]; player setUnitTrait [""explosiveSpecialist"", true];";
        };
        class 42nd_TakeEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 16;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
            condition = "(isNull objectParent player) && ((player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", false]; player setUnitTrait [""explosiveSpecialist"", false];";
        };
        class 42nd_Arsenal: 42nd_Healstation_Heal
        {
            userActionID = 17;
            displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>ACE Arsenal</t>";
            condition = "isNull objectParent player";
            statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
        };
    };
};

class 42nd_Arsenal_Weapon_Crate: 3as_Small_Box_9_Prop
{
    author = "Hound";
    scope = 2;
    scopeCurator = 2;
    displayName = "[42nd] Full Arsenal Weapons Crate";
    editorCategory = "42nd_Objects";
    editorSubcategory = "SUB42ndOBJ";
    class UserActions
    {
        class 42nd_Healstation_Heal
        {
            userActionID = 10;
            displayName = "<t size='1.25' font='PuristaSemibold' color='#ff5733'>Receive Medical Attention</t>";
            radius = 15;
            priority = 100;
            onlyForPlayer = 1;
            position = "";
            condition = "isNull objectParent player";
            statement = "[player] call ace_medical_treatment_fnc_fullHealLocal;";
        };
        class 42nd_GiveMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 11;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Med-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", true];";
        };
        class 42nd_TakeMedicPerms: 42nd_Healstation_Heal
        {
            userActionID = 12;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Med-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""medic"")";
            statement = "player setUnitTrait [""medic"", false];";
        };
        class 42nd_GiveEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 13;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get Engi-Perms</t>";
            condition = "(isNull objectParent player) && !(player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", true];";
        };
        class 42nd_TakeEngiPerms: 42nd_Healstation_Heal
        {
            userActionID = 14;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove Engi-Perms</t>";
            condition = "(isNull objectParent player) && (player getUnitTrait ""engineer"")";
            statement = "player setUnitTrait [""engineer"", false];";
        };
        class 42nd_GiveEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 15;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Get EOD-Perms</t>";
            condition = "(isNull objectParent player) && (!(player getUnitTrait ""engineer"") || !(player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", true]; player setUnitTrait [""explosiveSpecialist"", true];";
        };
        class 42nd_TakeEODPerms: 42nd_Healstation_Heal
        {
            userActionID = 16;
            displayName = "<t size='1.0' font='PuristaMedium' color='#ffd433'>Remove EOD-Perms</t>";
            condition = "(isNull objectParent player) && ((player getUnitTrait ""engineer"") || (player getUnitTrait ""explosiveSpecialist""))";
            statement = "player setUnitTrait [""engineer"", false]; player setUnitTrait [""explosiveSpecialist"", false];";
        };
        class 42nd_Arsenal: 42nd_Healstation_Heal
        {
            userActionID = 17;
            displayName = "<t size='1.0' font='PuristaMedium' color='#00FF00'>ACE Arsenal</t>";
            condition = "isNull objectParent player";
            statement = "[player, player, true] call ace_arsenal_fnc_openBox;";
        };
    };
};
