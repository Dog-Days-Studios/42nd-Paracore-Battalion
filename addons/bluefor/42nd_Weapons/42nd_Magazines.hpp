	class 100Rnd_65x39_caseless_mag;
	class 3Rnd_Smoke_Grenade_shell;
	class 1Rnd_HE_Grenade_shell;
	class CA_LauncherMagazine;
	class CA_Magazine;
	class RPG32_F;
	class IDA_blaster_cell;
	class IDA_blaster_cell_High;
	class IDA_blaster_cell_low;
	class IDA_blaster_cell_Amp;
	class IDA_blaster_cell_Overcharged;
	class IDA_blaster_scatter_cell;
	class IDA_blaster_battery;
	class IDA_blaster_battery_high;
	class Titan_AT;
	class IDA_HE_LauncherGrenade;
	class SWLW_mag_40mm_6rnd;
	class Vorona_HEAT;
	class magazine_Cannon_Phalanx_x1550;
	class IDA_Stun_cell;
	class IDA_thermal_coil_LP;
	class IDA_thermal_coil_HP;
	class 42nd_Stun_mag: IDA_Stun_cell
	{
		displayName = "30Rnd Stun Magazine";
		author = "Hound";
		count = 30;
		mass = 10;
	};
	class 42nd_CIWIS_Magazine: magazine_Cannon_Phalanx_x1550
	{
		displayName = "6000rnd Anti-Air Rounds";
		author = "Hound";
		ammo = "3AS_GAT_redPlasma_AT";
		count = 6000;
		mass = 10;
	};
	class 42nd_GL_Ext_Cell: IDA_HE_LauncherGrenade
	{
		displayName = "150rnd High Explosive Cell";
		descriptionShort = "Energy cell<br/>Rounds: 150<br/>";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "IDA_HE_LauncherGrenade";
		count = 150;
		mass = 300;
	};
	class 42nd_Imploder_Cell: IDA_HE_LauncherGrenade
	{
		displayName = "150rnd Imploder Cell";
		descriptionShort = "Energy cell<br/>Rounds: 150<br/>";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "IDA_grenade_Imploder_ammo";
		count = 150;
		mass = 1000;
	};
	class 42nd_BlasterCell_High_Cap: IDA_blaster_cell_Overcharged
	{
		displayName = "300rnd Energy Cell";
		descriptionShort = "Energy cell<br/>Rounds: 60<br/>";
		displayNameShort = "Med-capacity energy";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "42nd_blasterbolt_OC";
		count = 300;
		mass = 20;
	};
	class 42nd_BlasterCell_308: IDA_blaster_cell_Overcharged
	{
		displayName = "60rnd Energy Cell";
		descriptionShort = "Energy cell<br/>Rounds: 60<br/>";
		displayNameShort = "Med-capacity energy";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "42nd_blasterbolt_OC";
		count = 60;
		mass = 10;
	};
	class 42nd_BlasterCell_308_EXT: IDA_blaster_cell_Overcharged
	{
		displayName = "120rnd Energy Cell";
		descriptionShort = "Energy cell<br/>Rounds: 60<br/>";
		displayNameShort = "Med-capacity energy";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "42nd_blasterbolt_OC";
		count = 120;
		mass = 25;
	};
	class 42nd_IDA_HEGL_Shell: IDA_HE_LauncherGrenade
	{
		author = "Hound";
		count = 3;
		displayName = "3Rnd Impact grenade";
		descriptionShort = "Impact grenade";
		ammo = "IDA_HE_LauncherGrenade";
		mass = 8;
	};
	class 42nd_40mm_Blue : SWLW_mag_40mm_6rnd
	{
		displayName = "3rd 40mm GL (Blue)";
		descriptionShort = "Energy cell<br/>Rounds: 6<br/>";
		displayNameShort = "Hi-capacity energy";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "SWLW_ammo_40mm_blue";
		count = 3;
		mass = 20;
	};
	class 42nd_40mm_red_smoke : SWLW_mag_40mm_6rnd
	{
		displayName = "3rd 40mm Smoke (Red)";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "M319_Smoke_Red";
		count = 3;
		mass = 20;
	};
	class 42nd_40mm_orange_smoke : SWLW_mag_40mm_6rnd
	{
		displayName = "3rd 40mm Smoke (Orange)";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "M319_Smoke_Orange";
		count = 3;
		mass = 20;
	};
	class 42nd_40mm_green_smoke : SWLW_mag_40mm_6rnd
	{
		displayName = "3rd 40mm Smoke (Green)";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "M319_Smoke_Green";
		count = 3;
		mass = 20;
	};
	class 42nd_40mm_red : SWLW_mag_40mm_6rnd
	{
		displayName = "3rd 40mm GL (red)";
		descriptionShort = "Energy cell<br/>Rounds: 6<br/>";
		displayNameShort = "Hi-capacity energy";
		JLTS_hasEMPProtection = 1;
		author = "Hound";
		ammo = "ls_ammo_40mm_red";
		count = 3;
		mass = 20;
	};
	class 42nd_RPS_Extended_Mag: Vorona_HEAT
	{
		scope = 2;
		displayname = "[42nd] 3rd RPS Magazine";
		picture = "\ls_weapons\_ui\RPS6_mag_ca.paa";
		count = 3;
		initSpeed = 300;
		maxLeadSpeed = 80;
	};
	class 42nd_Manta_Tow_Mag: Vorona_HEAT
	{
		scope = 2;
		displayname = "[42nd] 8rd Tow Missle";
		picture = "\ls_weapons\_ui\RPS6_mag_ca.paa";
		count = 8;
		initSpeed = 300;
		maxLeadSpeed = 80;
	};
	class 42nd_blaster_cell: IDA_blaster_cell
	{
		author= "HoundaCivic + IDA Dev Team";
		scope= 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 75;
		displayName = "Standard Energy Cell";
		displayNameShort = "Energy Cell";
		descriptionShort = "75 round capacity.";
		ammo = "42nd_blasterbolt";
		tracersEvery = 1;
		initSpeed = 300;
		mass = 5;
	};
	class 42nd_blaster_cell_High: IDA_blaster_cell_High
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 60;
		displayName = "High-Power Energy Cell";
		displayNameShort = "HP Energy Cell";
		descriptionShort = "60 round capacity.";
		ammo = "42nd_blasterbolt_High";
		tracersEvery = 1;
		initSpeed = 500;
		mass = 5;
	};
	class 42nd_blaster_cell_Vintage: IDA_blaster_cell_High
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 45;
		displayName = "Vintage HP Energy Cell";
		displayNameShort = "HP Energy Cell";
		descriptionShort = "45 round capacity.";
		ammo = "42nd_blasterbolt_High";
		tracersEvery = 1;
		initSpeed = 450;
		mass = 5;
	};
	class 42nd_blaster_cell_low: IDA_blaster_cell_low
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 500;
		displayName = "Low-Power Energy Cell";
		displayNameShort = "LP Energy Cell";
		descriptionShort = "Near-infinte ammo, but lower power";
		ammo = "IDA_blasterbolt_low";
		tracersEvery = 1;
		initSpeed = 250;
		mass = 2;
	};	
	class 42nd_blaster_cell_Amp: IDA_blaster_cell_Amp
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 45;
		displayName = "Amplified Energy Cell";
		displayNameShort = "Amp Energy Cell";
		descriptionShort = "30 round capacity.";
		ammo = "IDA_blasterbolt_Amp";
		tracersEvery = 1;
		initSpeed = 700;
		mass = 5;
	};
	class 42nd_blaster_cell_OC: IDA_blaster_cell_Overcharged
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 15;
		displayName = "Overcharged High-Power Energy Cell";
		displayNameShort = "O/HP Energy Cell";
		descriptionShort = "15 round capacity.";
		ammo = "42nd_blasterbolt_OC";
		tracersEvery = 1;
		initSpeed = 750;
		mass = 10;
	};
	class 42nd_blaster_cell_HOC: IDA_blaster_cell_Overcharged
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 15;
		displayName = "Heavy HP Energy Cell";
		displayNameShort = "O/HP Energy Cell";
		descriptionShort = "15 round capacity.";
		ammo = "42nd_Heavy_blasterbolt";
		tracersEvery = 1;
		initSpeed = 850;
		mass = 20;
	};
	class 42nd_blaster_cell_APEX: IDA_blaster_cell_Overcharged
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 10;
		displayName = "Apex Energy Cell";
		displayNameShort = "APEX Energy Cell";
		descriptionShort = "10 round capacity.";
		ammo = "42nd_Apex_Blasterbolt";
		tracersEvery = 1;
		initSpeed = 700;
		mass = 30;
	};
	class 42nd_blaster_scatter_cell: IDA_blaster_scatter_cell
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 10;
		displayName = "High-Power Scatter Cell";
		displayNameShort = "HP Scatter Cell";
		descriptionShort = "10 round capacity";
		ammo = "IDA_blasterbolt_scatter";
		tracersEvery = 1;
		initSpeed = 250;
		mass = 8;
	};
	class 42nd_LP_blaster_battery: IDA_blaster_battery
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		count = 1000;
		displayName = "Low-Power Energy Battery";
		displayNameShort = "LP Energy Battery";
		descriptionShort = "1000 round capacity.";
		ammo = "IDA_blasterbolt_low";
		tracersEvery = 1;
		initSpeed = 600;
		mass = 30;
	};
	class 42nd_HP_blaster_battery: IDA_blaster_battery_high
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\z6\data\ui\z6_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\z6\z6_mag.p3d";
		count = 500;
		displayName = "High-Power Energy Battery";
		displayNameShort = "HP Energy Battery";
		descriptionShort = "500 round capacity.";
		ammo = "42nd_blasterbolt_High";
		tracersEvery = 1;
		initSpeed = 650;
		mass = 45;
	};
	class 42nd_thermal_coil_AMP: IDA_thermal_coil_LP
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 50;
		displayName = "Amplified Thermal coil";
		displayNameShort = "Amped Thermal coil";
		descriptionShort = "25 round capacity.";
		ammo = "IDA_thermal_shell_LP";
		tracersEvery = 1;
		initSpeed = 700;
		mass = 25;
	};
	class 42nd_thermal_coil_HP: IDA_thermal_coil_HP
	{
		author = "Hound";
		scope = 2;
		modelSpecial = "";
		modelSpecialIsProxy = 0;
		picture = "\MRC\JLTS\weapons\DC15A\data\ui\DC15A_mag_ui_ca.paa";
		model = "\MRC\JLTS\weapons\DC15A\DC15A_mag.p3d";
		count = 10;
		displayName = "High-Power Thermal coil";
		displayNameShort = "HP Thermal coil";
		descriptionShort = "10 round capacity.";
		ammo = "IDA_thermal_shell_HP";
		tracersEvery = 1;
		initSpeed = 500;
		mass = 40;
	};
