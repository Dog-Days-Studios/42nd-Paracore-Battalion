class CfgPatches {
    class Aux_42nd_ARC170_Hotfix {
        requiredVersion = 2.1;
        requiredAddons[] = {"Aux_42nd", "3AS_ARC_170"};
        units[] = {};
        weapons[] = {};
    };
};
class CfgVehicles {
    class 3AS_ARC_170_base;
    class 3AS_ARC_170_Republic: 3AS_ARC_170_base {
        class Turrets {
            class Reargun;
            class LaserPilot;
        };
    };
    class 42nd_ARC170: 3AS_ARC_170_Republic {};
    class 42nd_ARC170_Gunship: 42nd_ARC170 {
        class Turrets: Turrets {
            class Reargun: Reargun {
                weapons[] = {"42nd_ARC170_105mm_Laser_Cannon", "42nd_ARC170_40mm_Laser_Bofors", "42nd_ARC170_Laser_Minigun"};
                magazines[] = {
                    "ls_magazine_120mm_30Rnd_HE_blue",
                    "ls_magazine_40mm_50Rnd_G_blue",
                    "ls_magazine_40mm_50Rnd_G_blue",
                    "ls_magazine_127x99_500Rnd_blue",
                    "ls_magazine_127x99_500Rnd_blue",
                    "ls_magazine_127x99_500Rnd_blue",
                    "ls_magazine_127x99_500Rnd_blue"
                };
            };
            class LaserPilot: LaserPilot {};
        };
    };
};
