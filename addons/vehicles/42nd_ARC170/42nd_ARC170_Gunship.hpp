	class 42nd_Arc170_Gunship: 3AS_ARC_170_base
	{
		author = "Houndacivic";
		displayName = "[42nd] ARC-130 Gunship";
		editorPreview = "";
		scope = 2;
		scopeCurator = 2;
		crew = "42nd_WO1_Pilot";
		side = 1;
		faction = "Fac42nd_AIR";
		editorSubcategory = "SUB42ndAir";
		hiddenselectionstextures[] = {"\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa",
                "\42nd_para\42nd\addons\Vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa",
                "\3AS\3AS_ARC170\Data\Guns_CO.paa"};
		class TextureSources
		{
			class base_42nd
			{
				displayName = "42nd Default";
				author = "Houndacivic";
				textures[] = {"\42nd_para\42nd\addons\vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa",
                "\42nd_para\42nd\addons\vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa",
                "\3AS\3AS_ARC170\Data\Guns_CO.paa"};
				factions[] = {"Fac42nd_AIR"};
			};

		};
		textureList[] = {"base_42nd",1};
		class RenderTargets
		{
			class PIPGunner
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "gunnerview2";
					pointDirection = "gunnerview2_dir";
					renderQuality = 2;
					renderVisionMode = 2;
					turret[] = {1};
					fov = 0.203452;
				};
				BBoxes[] = {"PIP_GUN_TL","PIP_GUN_TR","PIP_GUN_BL","PIP_GUN_BR"};
			};
			class PIPGunnerRear
			{
				renderTarget = "rendertarget1";
				class CameraView1
				{
					pointPosition = "gunnerview";
					pointDirection = "gunnerview_dir";
					renderQuality = 2;
					renderVisionMode = 2;
					fov = 0.203452;
				};
				BBoxes[] = {"PIP_GUN2_TL","PIP_GUN2_TR","PIP_GUN2_BL","PIP_GUN2_BR"};
			};
		};
		// Sensor suite matching AC-130 capabilities (inherits pylons from base)
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 6000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableSpeed = 175;
						angleRangeHorizontal = 45;
						angleRangeVertical = 35;
						aimDown = 0;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableSpeed = 175;
						angleRangeHorizontal = 45;
						angleRangeVertical = 36;
						aimDown = 1;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 6000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 6000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableSpeed = 250;
						angleRangeHorizontal = 360;
						angleRangeVertical = 110;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar{};
					class LaserSensorComponent: SensorTemplateLaser
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
						aimDown = 30;
					};
					class NVSensorComponent: SensorTemplateNV
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink{};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {4000,2000,16000,8000};
						resource = "RscCustomInfoSensors";
					};
					class MinimapDisplay
					{
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoMiniMap";
					};
					class CrewDisplay
					{
						componentType = "CrewDisplayComponent";
						resource = "RscCustomInfoCrew";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				class Components
				{
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {4000,2000,16000,8000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
		};
		class Turrets
		{
			class Reargun: NewTurret
			{
				isCopilot = 0;
				canEject = 1;
				startEngine = 0;
				// AC-130 style thermal optics: Wide/Medium/Narrow with FLIR
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -90;
						maxAngleX = 90;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.462;
						minFov = 0.462;
						maxFov = 0.462;
						directionStabilized = 1;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = 0.11;
						minFov = 0.11;
						maxFov = 0.11;
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						initFov = 0.0218;
						minFov = 0.0218;
						maxFov = 0.0218;
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.7;
						minFov = 0.25;
						maxFov = 0.85;
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
				soundServo[] = {"",0.000178,0.9};
				outGunnerMayFire = 1;
				commanding = -1;
				primaryGunner = 0;
				primaryObserver = 1;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				gunnerinaction = "Plane_Fighter_03_pilot";
				gunneropticseffect[] = {"TankCommanderOptics1","BWTV"};
				memorypointgunneroptics = "gunnerview";
				memorypointsgetingunner = "pos gunner";
				memorypointsgetingunnerdir = "pos gunner dir";
				stabilizedInAxes = 3;
				gunneraction = "Plane_Fighter_03_pilot";
				gunnerforceoptics = 1;
				// Top/rear turret - laser designator + sensors only
				gunnerName = "Sensor Operator";
				proxyIndex = 3;
				proxytype = "CPGunner";
				gunnerLeftHandAnimName = "lever_copilot";
				gunnerRightHandAnimName = "stick_copilot";
				gunnerLeftLegAnimName = "";
				gunnerRightLegAnimName = "";
				animationsourcebody = "MainTurret";
				animationsourcegun = "Maingun";
				animationsourcehatch = "";
				body = "MainTurret";
				gun = "Maingun";
				memoryPointGun = "konec hlavne b";
				gunBeg = "usti hlavne b";
				gunEnd = "konec hlavne b";
				selectionFireAnim = "zasleh3";
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				precisegetinout = 0;
				turretInfoType = "RscOptics_Heli_Attack_01_gunner";
				discreteDistance[] = {1000,1500,2000,2500,3000,3500,4000};
				discreteDistanceInitIndex = 2;
				weapons[] = {"Laserdesignator_mounted","CMFlareLauncher"};
				magazines[] = {
					"Laserbatteries",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine"
				};
				// Widened turret arcs for AC-130-style ground attack
				minElev = -60;
				maxElev = 60;
				maxturn = 330;
				minturn = 30;
				initTurn = 180;
				initElev = -10;
				maxHorizontalRotSpeed = 1.8;
				maxVerticalRotSpeed = 1.8;
				enableManualFire = 0;
				LODTurnedOut = 1000;
				LODTurnedIn = 1000;
				elevationMode = 0;
				turretFollowFreeLook = 2;
				class HitPoints{};
			};
			class LaserPilot: Reargun
			{
				commanding = -1;
				memorypointgunneroptics = "gunnerview2";
				gunnerForceOptics = 1;
				enableManualFire = 1;
				// Bottom/belly turret - primary gunner with side-firing weapons
				primaryGunner = 1;
				primaryObserver = 0;
				body = "Mainturret2";
				gun = "maingun2";
				animationSourceBody = "mainturret2";
				animationSourceGun = "maingun2";
				gunnerName = "Weapon Systems Officer";
				weapons[] = {"42nd_ARC170_105mm_Laser_Cannon","42nd_ARC170_40mm_Laser_Bofors","42nd_ARC170_Laser_Minigun","CMFlareLauncher"};
				magazines[] = {
					"42nd_ARC170_Mag_100Rnd_105mm_HE",
					"42nd_ARC170_Mag_5Rnd_105mm_AP",
					"42nd_ARC170_Mag_256Rnd_40mm_HE",
					"42nd_ARC170_Mag_256Rnd_40mm_AP",
					"42nd_ARC170_Mag_2000Rnd_25mm",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine",
					"240Rnd_CMFlare_Chaff_Magazine"
				};
				gunBeg = "usti hlavne b2";
				gunEnd = "konec hlavne b2";
				memoryPointGun = "konec hlavne b2";
				selectionFireAnim = "zasleh4";
				usepip = 2;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -90;
						maxAngleX = 90;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.462;
						minFov = 0.462;
						maxFov = 0.462;
						directionStabilized = 1;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = 0.11;
						minFov = 0.11;
						maxFov = 0.11;
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						initFov = 0.0218;
						minFov = 0.0218;
						maxFov = 0.0218;
						gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
					};
				};
				proxyIndex = 2;
				// Belly turret - primarily downward for ground attack
				minElev = -90;
				maxElev = 10;
				maxturn = 300;
				minturn = 60;
				initTurn = 180;
				initElev = -30;
				maxHorizontalRotSpeed = 3;
				maxVerticalRotSpeed = 3;
				class HitPoints{};
			};
		};
	};
