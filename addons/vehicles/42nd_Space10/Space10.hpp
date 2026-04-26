
	class lsd_heli_laati;
	class OPTRE_M412_IFV_UNSC;
	class 3as_BTLB_Bomber_Redleader;
	class OPTRE_Pelican_unarmed;
	class SensorTemplateActiveRadar;
    class SensorTemplateIR;
    class SensorTemplateVisual;
    class SensorTemplateActive;
    class SensorTemplatePassiveRadar;
    class SensorTemplateLaser;
    class SensorTemplateNV;
	class DefaultVehicleSystemsDisplayManagerLeft
	{
		class Components;
	};
	class DefaultVehicleSystemsDisplayManagerRight
	{
		class Components;
	};

	class Plane_CAS_01_base_F;
	class Plane_CAS_01_dynamicLoadout_base_F: Plane_CAS_01_base_F
	{};
	class B_Plane_CAS_01_dynamicLoadout_F: Plane_CAS_01_dynamicLoadout_base_F
	{};

	class 42nd_A10 :B_Plane_CAS_01_dynamicLoadout_F
	{
		displayName="[42nd] A-10 Vtol";
		editorPreview="-";
		scope=2;
		armor=160;
		maxSpeed = 1200;
		enginePower = 140000;
		vtol = 4;
		VTOLPitchInfluence = 6.0;
		VTOLRollInfluence = 15.0;
		VTOLYawInfluence = 12.0;
		airFrictionCoefs0[]={0,0,0};
        airFrictionCoefs1[]={0.1,0.5,0.0066};
        airFrictionCoefs2[]={0.001,0.0049999999,6.8000001e-005};
		fuelCapacity=16000;
		maxOmega=18000;
		altFullForce = 15000;
		irScanRangeMin=3;
        irScanRangeMax=100000;
        irScanToEyeFactor=8;
		peakTorque = 8000;
		altNoForce = 90000;
		accuracy=10000;
		lockDetectionSystem="2+4+8+16";
        incomingMissileDetectionSystem="2+4+8+16";
        allowTabLock = 1;
        driverCanSee=31;
		draconicForceYCoef = 2;
		hiddenSelections[] = {"Camo_1","Camo_2"};
		hiddenSelectionsTextures[] = {"A3\Air_F_EPC\Plane_CAS_01\Data\plane_cas_01_ext01_co.paa","A3\Air_F_EPC\Plane_CAS_01\Data\plane_cas_01_ext02_co.paa"};
		weapons[] = {"Gatling_30mm_Plane_CAS_01_F","Laserdesignator_pilotCamera","CMFlareLauncher"};
		magazines[] = {"1000Rnd_Gatling_30mm_Plane_CAS_01_F","Laserbatteries","120Rnd_CMFlare_Chaff_Magazine"};
		thrustCoef[] = {1.8,1.9,1.95,2,2.5,3,3.5,2.5,2,1.7,1.5,1.1,1,1,1};
		availableForSupportTypes[] = {"CAS_Bombing"};
		faction="Fac42nd";
		editorSubcategory = "Sub42ndAir";
		crew = "42nd_P1_Pilot_Unit";
		class Components: Components
		{
			class TransportPylonsComponent
            {
                UIPicture="3as\3as_arc170\data\plane_arc_pylon_ca.paa";
                class pylons
                {
                    class pylons1
                    {
                        hardpoints[]=
                        {
                            "B_BIM9X_DUAL_RAIL"
                        };
                        attachment="PylonRack_Missile_BIM9X_x2";
                        priority=10;
                        maxweight=300;
                        UIposition[]={0.5,0.25};
                    };
                    class pylons2: pylons1
                    {
                        UIposition[]={0.15000001,0.25};
                        mirroredMissilePos=1;
                    };
                    class pylons3: pylons1
                    {
                        hardpoints[]=
                        {
                            "B_AMRAAM_D_RAIL",
                            "B_AMRAAM_D_DUAL_RAIL",
                            "B_AGM65_RAIL",
                            "B_AGM65_DUAL_RAIL",
                            "ARC_AGM_PYLON",
                            "B_BOMB_PYLON"
                        };
                        attachment="PylonMissile_1Rnd_Bomb_04_F";
                        priority=9;
                        maxweight=2500;
                        UIposition[]={0.55000001,0.34999999};
                    };
                    class pylons4: pylons3
                    {
                        UIposition[]={0.1,0.34999999};
                        mirroredMissilePos=3;
                    };
                    class pylons5: pylons1
                    {
                        hardpoints[]=
                        {
                            "B_AMRAAM_D_RAIL",
                            "B_AGM65_RAIL",
                            "B_AGM65_DUAL_RAIL",
                            "B_HARM_RAIL",
                            "ARC_AGM_PYLON"
                        };
                        attachment="PylonRack_Missile_AMRAAM_D_x1";
                        priority=7;
                        maxweight=5000;
                        UIposition[]={0.60000002,0.44999999};
                    };
                    class pylons6: pylons5
                    {
                        UIposition[]={0.050000001,0.44999999};
                        mirroredMissilePos=5;
                    };
                };
                class presets
                {
                    class empty
                    {
                        displayName="$STR_empty";
                        attachment[]={};
                    };
                    class AA
                    {
                        displayName="$STR_A3_cfgmagazines_titan_aa_dns";
                        attachment[]=
                        {
                            "PylonRack_Missile_BIM9X_x1",
                            "PylonRack_Missile_BIM9X_x1",
                            "3as_PylonRack_ARC_6Rnd_Missile_AGM",
                            "3as_PylonRack_ARC_6Rnd_Missile_AGM",
                            "PylonRack_Missile_AMRAAM_D_x1",
                            "PylonRack_Missile_AMRAAM_D_x1"
                        };
                    };
                    class CAS
                    {
                        displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
                        attachment[]=
                        {
                            "PylonRack_Missile_BIM9X_x1",
                            "PylonRack_Missile_BIM9X_x1",
                            "PylonMissile_1Rnd_Bomb_04_F",
                            "PylonMissile_1Rnd_Bomb_04_F",
                            "3as_PylonRack_ARC_6Rnd_Missile_AGM",
                            "3as_PylonRack_ARC_6Rnd_Missile_AGM"
                        };
                    };
					class AT
					{
						displayName = "$STR_A3_cfgmagazines_titan_at_dns";
						attachment[] = {"PylonRack_1Rnd_Missile_AA_04_F","PylonRack_1Rnd_Missile_AGM_02_F","PylonRack_3Rnd_Missile_AGM_02_F","PylonRack_7Rnd_Rocket_04_HE_F","PylonMissile_1Rnd_Bomb_04_F","PylonMissile_1Rnd_Bomb_04_F","PylonRack_7Rnd_Rocket_04_HE_F","PylonRack_3Rnd_Missile_AGM_02_F","PylonRack_1Rnd_Missile_AGM_02_F","PylonRack_1Rnd_Missile_AA_04_F"};
					};
                };
            };
			class SensorsManagerComponent
			{
				class Components
				{
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=100;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=100;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableSpeed=900;
						angleRangeHorizontal=200;
						angleRangeVertical=90;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						aimDown=15;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
					};
					class NVSensorComponent: SensorTemplateNV
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				componentType = "VehicleSystemsDisplayManager";
				left=1;
				x = "safezoneX + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
				y = "safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				defaultDisplay="CrewDisplay";
				class Components: Components
				{
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						showTargetTypes = 1+2+4+8+16+32+64+128+256+1024;
						range[]={8000,4000,16000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				componentType = "VehicleSystemsDisplayManager";
				right=1;
				x = "(46 * (((safezoneW / safezoneH) min 1.2) / 40)) + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
				y = "safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				defaultDisplay="SensorDisplay";
				class Components: Components
				{
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						showTargetTypes = 1+2+4+8+16+32+64+128+256+1024;
						range[]={8000,4000,16000};
						resource="RscCustomInfoSensors";
					};
				};
			};
						class Reflectors
		{
			class Gear_1_light_1
			{
				color[] = {0,0.8,0,1};
				ambient[] = {0.009,0.01,0.008};
				intensity = 25000;
				size = 1;
				innerAngle = 0;
				outerAngle = 90;
				coneFadeCoef = 12;
				position = "Gear_1_light_1_pos";
				direction = "Gear_1_light_1_dir";
				hitpoint = "Gear_1_light_1_hit";
				selection = "Gear_1_light_1_hide";
				useFlare = 1;
				flareSize = 0.5;
				flareMaxDistance = 30;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 15;
					quadratic = 7;
					hardLimitStart = 75;
					hardLimitEnd = 100;
				};
			};
			class Gear_1_light_2
			{
				color[] = {0,0.8,0,1};
				ambient[] = {0.0085,0.0095,0.01};
				intensity = 500000;
				size = 1;
				innerAngle = 15;
				outerAngle = 40;
				coneFadeCoef = 5;
				position = "Gear_1_light_2_pos";
				direction = "Gear_1_light_2_dir";
				hitpoint = "Gear_1_light_2_hit";
				selection = "Gear_1_light_2_hide";
				useFlare = 1;
				flareSize = 1.5;
				flareMaxDistance = 500;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 5;
					quadratic = 2;
					hardLimitStart = 400;
					hardLimitEnd = 500;
				};
			};
		};
		};
	};


	