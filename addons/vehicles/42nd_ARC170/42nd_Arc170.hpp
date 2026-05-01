	class Air;
	class NewTurret;
	class Plane: Air
	{
		class HitPoints;
		class NewTurret;
	};
	class Plane_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class Components;
		class Eventhandlers;
		class ViewPilot;
	};
	class Plane_Fighter_03_base_F: Plane_Base_F
	{
		class Turrets{};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull{};
			class HitEngine: HitHull{};
			class HitAvionics: HitHull{};
			class HitFuel: HitHull{};
			class HitLAileron: HitHull{};
			class HitRAileron: HitLAileron{};
			class HitLCRudder: HitHull{};
			class HitLCElevator: HitHull{};
			class HitRElevator: HitHull{};
		};
		class AnimationSources: AnimationSources{};
		class Components: Components{};
		class UserActions;
	};
	class Plane_Fighter_03_dynamicLoadout_base_F: Plane_Fighter_03_base_F
	{
		class Components: Components
		{
			class TransportPylonsComponent;
		};
	}; //I have been fighting trying to make variants of this plane for a week, and I have no idea how to make it work.
    //So here we are, with the base class being the ARC-170 itself. I will be adding variants of this plane as I make them, but for now, this is the only one.
	class 3AS_ARC_170_base: Plane_Fighter_03_dynamicLoadout_base_F
	{
		class Components: Components
		{
			class TransportPylonsComponent;
		};
	};
	class 42nd_ARC_170_Base: Plane_Fighter_03_dynamicLoadout_base_F
	{
		author = "HoundaCivic";
		class MFD
		{
			class AirplaneHUD
			{
				topLeft = "HUD_top_left";
				topRight = "HUD_top_right";
				bottomLeft = "HUD_bottom_left";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0.082,0.408,0.039,1};
				helmetMountedDisplay = 1;
				helmetPosition[] = {-0.0375,0.0375,0.1};
				helmetRight[] = {0.075,0,0};
				helmetDown[] = {0,-0.075,0};
				font = "";
				turret[] = {-2};
				class Bones
				{
					class HUDCenter
					{
						type = "fixed";
						pos[] = {0.5,0.5};
					};
					class HorizonBankSource
					{
						type = "rotational";
						source = "HorizonBank";
						center[] = {0.5,0.5};
						min = -6.2831;
						max = 6.2831;
						minAngle = -360;
						maxAngle = 360;
					};
					class HorizonDiveSource
					{
						source = "horizonDive";
						type = "linear";
						min = -1;
						max = 1;
						minPos[] = {0.5,2.5};
						maxPos[] = {0.5,-1.5};
					};
					class VelocityVector
					{
						type = "vector";
						source = "velocityToView";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class ForwardVector
					{
						type = "vector";
						source = "forward";
						pos0[] = {0,0};
						pos10[] = {0.234,0.23};
					};
					class WeaponAim
					{
						type = "vector";
						source = "weaponToView";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class TargetingPodDir
					{
						source = "pilotcameratoview";
						type = "vector";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class TargetingPodTarget
					{
						source = "pilotcameratargettoview";
						type = "vector";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class SliderDiveSource
					{
						type = "linear";
						source = "horizonDive";
						min = "RAD(-10)";
						max = "RAD(10)";
						minPos[] = {0.105,0.38};
						maxPos[] = {0.105,0.54};
					};
					class SliderDiveSource30: SliderDiveSource
					{
						min = "RAD(10)";
						max = "RAD(30)";
						minPos[] = {0,-0.04};
						maxPos[] = {0,"0)"};
					};
					class SliderDiveSource90: SliderDiveSource30
					{
						min = "RAD(30)";
						max = "RAD(90)";
						minPos[] = {0,-0.04};
					};
					class SliderDiveSource30m: SliderDiveSource
					{
						min = "RAD(-30)";
						max = "RAD(-10)";
						minPos[] = {0,0};
						maxPos[] = {0,0.04};
					};
					class SliderDiveSource90m: SliderDiveSource30m
					{
						min = "RAD(-90)";
						max = "RAD(-30)";
						maxPos[] = {0,0.04};
					};
					class SliderAltitudeSource
					{
						type = "linear";
						source = "altitudeAGL";
						sourceOffset = -3;
						min = 0;
						max = 1000;
						minPos[] = {0.885,0.2};
						maxPos[] = {0.885,0.375};
					};
					class GForceSource
					{
						type = "linear";
						source = "gmeter";
						sourceScale = 0.15;
						min = -1;
						max = 3;
						minPos[] = {0.105,0.7};
						maxPos[] = {0.105,0.86};
					};
					class SliderVSpeedSource
					{
						type = "linear";
						source = "vspeed";
						min = -15;
						max = 15;
						minPos[] = {0.795,0.6};
						maxPos[] = {0.795,0.84};
					};
					class ImpactPoint
					{
						type = "vector";
						source = "ImpactPointToView";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class ImpactPointRockets
					{
						type = "vector";
						source = "ImpactPointToView";
						pos0[] = {0.5,0.565};
						pos10[] = {0.734,0.795};
					};
					class WPPoint
					{
						type = "vector";
						source = "WPPointToView";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class rtdRPM1
					{
						type = "linear";
						source = "rpm";
						min = 0.1;
						max = 1;
						minPos[] = {0,-0.075};
						maxPos[] = {0,0};
					};
					class rtdRPM2: rtdRPM1
					{
						source = "rpm";
					};
					class Limit0109
					{
						type = "limit";
						limits[] = {0.1,0.1,0.9,0.9};
					};
					class Target
					{
						source = "targettoview";
						type = "vector";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class ThrustVectoringRotation
					{
						type = "rotational";
						source = "vtolvectoring";
						sourceScale = 100;
						center[] = {0.06,0.145};
						min = 0;
						max = 100;
						minAngle = 0;
						maxAngle = -90;
						aspectRatio = 0.982906;
					};
					class MissileFlightTimeRot1
					{
						type = "rotational";
						source = "MissileFlightTime";
						sourceScale = 0.46;
						center[] = {0,0};
						min = 0;
						max = 0.5;
						minAngle = 0;
						maxAngle = 18;
						aspectRatio = 0.982906;
					};
					class MissileFlightTimeRot2: MissileFlightTimeRot1
					{
						maxAngle = 36;
						max = 1;
					};
					class MissileFlightTimeRot3: MissileFlightTimeRot1
					{
						maxAngle = 54;
						max = 1.5;
					};
					class MissileFlightTimeRot4: MissileFlightTimeRot1
					{
						maxAngle = 72;
						max = 2;
					};
					class MissileFlightTimeRot5: MissileFlightTimeRot1
					{
						maxAngle = 90;
						max = 2.5;
					};
					class MissileFlightTimeRot6: MissileFlightTimeRot1
					{
						maxAngle = 108;
						max = 3;
					};
					class MissileFlightTimeRot7: MissileFlightTimeRot1
					{
						maxAngle = 126;
						max = 3.5;
					};
					class MissileFlightTimeRot8: MissileFlightTimeRot1
					{
						maxAngle = 144;
						max = 4;
					};
					class MissileFlightTimeRot9: MissileFlightTimeRot1
					{
						maxAngle = 162;
						max = 4.5;
					};
					class MissileFlightTimeRot10: MissileFlightTimeRot1
					{
						maxAngle = 180;
						max = 5;
					};
					class MissileFlightTimeRot11: MissileFlightTimeRot1
					{
						maxAngle = 198;
						max = 5.5;
					};
					class MissileFlightTimeRot12: MissileFlightTimeRot1
					{
						maxAngle = 216;
						max = 6;
					};
					class MissileFlightTimeRot13: MissileFlightTimeRot1
					{
						maxAngle = 234;
						max = 6.5;
					};
					class MissileFlightTimeRot14: MissileFlightTimeRot1
					{
						maxAngle = 252;
						max = 7;
					};
					class MissileFlightTimeRot15: MissileFlightTimeRot1
					{
						maxAngle = 270;
						max = 7.5;
					};
					class MissileFlightTimeRot16: MissileFlightTimeRot1
					{
						maxAngle = 288;
						max = 8;
					};
					class MissileFlightTimeRot17: MissileFlightTimeRot1
					{
						maxAngle = 306;
						max = 8.5;
					};
					class MissileFlightTimeRot18: MissileFlightTimeRot1
					{
						maxAngle = 324;
						max = 9;
					};
					class MissileFlightTimeRot19: MissileFlightTimeRot1
					{
						maxAngle = 342;
						max = 9.5;
					};
					class MissileFlightTimeRot20: MissileFlightTimeRot1
					{
						maxAngle = 360;
						max = 10;
					};
					class HorizonBankRotFull
					{
						type = "rotational";
						source = "horizonBank";
						center[] = {0,0};
						min = -3.1416;
						max = 3.1416;
						minAngle = -180;
						maxAngle = 180;
						aspectRatio = 1;
					};
					class Airport1
					{
						type = "vector";
						source = "airportCorner1toview";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
					};
					class Airport2: Airport1
					{
						source = "airportCorner2toview";
					};
					class Airport3: Airport1
					{
						source = "airportCorner3toview";
					};
					class Airport4: Airport1
					{
						source = "airportCorner4toview";
					};
					class ILS_H
					{
						type = "ils";
						pos0[] = {0.5,0.5};
						pos3[] = {0.5702,0.5};
					};
					class ILS_W: ILS_H
					{
						pos3[] = {0.5,0.569};
					};
				};
				class Draw
				{
					alpha = "user3";
					color[] = {"user0","user1","user2"};
					condition = "(1 - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37))*on";
					class VelocityLine
					{
						type = "line";
						width = 2;
						points[] = {{"HUDCenter",1},{"VelocityVector",1},{},{"VelocityVector",{0,-0.00491453},1},{"VelocityVector",{0.0025,-0.00425598},1},{"VelocityVector",{0.00433,-0.00245726},1},{"VelocityVector",{0.005,0},1},{"VelocityVector",{0.00433,0.00245726},1},{"VelocityVector",{0.0025,0.00425598},1},{"VelocityVector",{0,0.00491453},1},{"VelocityVector",{-0.0025,0.00425598},1},{"VelocityVector",{-0.00433,0.00245726},1},{"VelocityVector",{-0.005,0},1},{"VelocityVector",{-0.00433,-0.00245726},1},{"VelocityVector",{-0.0025,-0.00425598},1},{"VelocityVector",{0,-0.00491453},1},{}};
					};
					class Static
					{
						type = "line";
						width = 3;
						points[] = {{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.015,0.01},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0,0},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.015,-0.01},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.015,0.01},1},{},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.03,0.015},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.088,0.015},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.088,-0.015},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.03,-0.015},1},{"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.03,0.015},1},{},{{0.1,0.3},1},{{0.1,0.62},1},{},{{0.1,0.3},1},{{0.08,0.3},1},{},{{0.1,0.34},1},{{0.08,0.34},1},{},{{0.1,0.38},1},{{0.08,0.38},1},{},{{0.1,0.46},1},{{0.08,0.46},1},{},{{0.1,0.54},1},{{0.08,0.54},1},{},{{0.1,0.58},1},{{0.08,0.58},1},{},{{0.1,0.62},1},{{0.08,0.62},1},{},{"GForceSource",{0.015,0.01},1},{"GForceSource",{0,0},1},{"GForceSource",{0.015,-0.01},1},{"GForceSource",{0.015,0.01},1},{},{{0.1,0.688},1},{{0.1,0.82},1},{},{{0.1,0.7},1},{{0.08,0.7},1},{},{{0.1,0.74},1},{{0.08,0.74},1},{},{{0.1,0.78},1},{{0.08,0.78},1},{},{{0.1,0.82},1},{{0.08,0.82},1},{},{{0.46,0.07},1},{{0.54,0.07},1},{{0.54,0.035},1},{{0.46,0.035},1},{{0.46,0.07},1},{},{{0.15,0.115},1},{{0.85,0.115},1},{},{{0,0.96},1},{{1.1,0.96},1},{},{{0.48,0.5},1},{{0.49,0.5},1},{},{{0.51,0.5},1},{{0.52,0.5},1},{},{{0.5,0.49},1},{{0.5,0.48},1},{},{{0.5,0.51},1},{{0.5,0.52},1},{},{"WeaponAim",1,{-0.02,0},1},{"WeaponAim",1,{-0.01,0},1},{},{"WeaponAim",1,{0.01,0},1},{"WeaponAim",1,{0.02,0},1},{},{"WeaponAim",1,{0,-0.01},1},{"WeaponAim",1,{0,-0.02},1},{},{"WeaponAim",1,{0,0.01},1},{"WeaponAim",1,{0,0.02},1},{},{"HUDCenter",{-0.165,7.08909e-09},1},{"HUDCenter",{-0.22,9.45212e-09},1},{},{"HUDCenter",{0.165,-1.93397e-09},1},{"HUDCenter",{0.22,-2.57863e-09},1},{},{"HUDCenter",{-0.0825,0.140452},1},{"HUDCenter",{-0.09625,0.16386},1},{},{"HUDCenter",{0.0825,0.140452},1},{"HUDCenter",{0.09625,0.16386},1},{},{"HUDCenter",{-0.142894,0.0810897},1},{"HUDCenter",{-0.16671,0.0946047},1},{},{"HUDCenter",{0.142894,0.0810897},1},{"HUDCenter",{0.16671,0.0946047},1},{},{"HUDCenter",{-0.116673,0.114678},1},{"HUDCenter",{-0.155564,0.152904},1},{},{"HUDCenter",{0.116673,0.114678},1},{"HUDCenter",{0.155563,0.152904},1},{},{{0.0333333,0.148667},1},{{0.054,0.162},1},{{0.135,0.162},1},{{0.135,0.148667},1},{{0.126333,0.139667},1},{{0.118,0.139667},1},{{0.0933333,0.129333},1},{{0.0333333,0.129333},1},{{0.0156667,0.111},1},{{0.00866667,0.115333},1},{{0.0116667,0.136},1},{}};
					};
					class DiveNumber
					{
						type = "text";
						source = "horizondive";
						sourceScale = 57.29578;
						sourceOffset = 0;
						align = "left";
						scale = 1;
						pos[] = {"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.085,-0.011},1};
						right[] = {"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.12,-0.011},1};
						down[] = {"SliderDiveSource90",1,"SliderDiveSource30",1,"SliderDiveSource",1,"SliderDiveSource30m",1,"SliderDiveSource90m",1,{0.085,0.019},1};
					};
					class VSpeedGroup
					{
						condition = "on";
						class VSpeedNumber
						{
							type = "text";
							source = "vspeed";
							sourceScale = 1;
							align = "center";
							scale = 1;
							pos[] = {{0.89,0.728},1};
							right[] = {{0.93,0.728},1};
							down[] = {{0.89,0.763},1};
						};
						class Static
						{
							type = "line";
							width = 3;
							points[] = {{{0.849,0.76},1},{{0.929,0.76},1},{{0.929,0.725},1},{{0.849,0.725},1},{{0.849,0.76},1},{}};
						};
					};
					class VSpeedGroupUp
					{
						condition = "vspeed";
						class Static
						{
							type = "line";
							width = 3;
							points[] = {{{0.869,0.715},1},{{0.909,0.715},1},{{0.889,0.695},1},{{0.869,0.715},1},{}};
						};
					};
					class VSpeedGroupDown
					{
						condition = "-vspeed";
						class Static
						{
							type = "line";
							width = 3;
							points[] = {{{0.869,0.77},1},{{0.909,0.77},1},{{0.889,0.79},1},{{0.869,0.77},1},{}};
						};
					};
					class AltGroup
					{
						condition = "1000 - altitudeAGL";
						class Static
						{
							type = "line";
							width = 3;
							points[] = {{"SliderAltitudeSource",{0.024,0.01},1},{"SliderAltitudeSource",{0.009,0},1},{"SliderAltitudeSource",{0.024,-0.01},1},{"SliderAltitudeSource",{0.024,0.01},1},{},{"SliderAltitudeSource",{0.035,0.015},1},{"SliderAltitudeSource",{0.093,0.015},1},{"SliderAltitudeSource",{0.093,-0.015},1},{"SliderAltitudeSource",{0.035,-0.015},1},{"SliderAltitudeSource",{0.035,0.015},1},{},{{0.889,0.2},1},{{0.889,0.375},1},{},{{0.879,0.2},1},{{0.899,0.2},1},{},{{0.879,0.375},1},{{0.899,0.375},1},{}};
						};
						class AltNumber
						{
							type = "text";
							source = "altitudeAGL";
							sourceScale = 1;
							sourceOffset = -3;
							align = "left";
							scale = 1;
							pos[] = {"SliderAltitudeSource",{0.085,-0.011},1};
							right[] = {"SliderAltitudeSource",{0.11,-0.011},1};
							down[] = {"SliderAltitudeSource",{0.085,0.019},1};
						};
						class AltStatic50
						{
							type = "text";
							source = "static";
							text = "1000";
							scale = 1;
							sourceScale = 1;
							align = "center";
							pos[] = {{0.885,0.171},1};
							right[] = {{0.925,0.171},1};
							down[] = {{0.885,0.201},1};
						};
					};
					class SpeedNumber
					{
						type = "text";
						source = "speed";
						sourceScale = 3.6;
						sourceLength = 3;
						align = "left";
						scale = 1;
						pos[] = {{0.13,0.22},1};
						down[] = {{0.13,0.26},1};
						right[] = {{0.2,0.22},1};
					};
					class Angle_90
					{
						type = "text";
						source = "static";
						text = "90";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.285},1};
						right[] = {{0.11,0.285},1};
						down[] = {{0.07,0.315},1};
					};
					class Angle_30
					{
						type = "text";
						source = "static";
						text = "30";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.325},1};
						right[] = {{0.11,0.325},1};
						down[] = {{0.07,0.355},1};
					};
					class Angle_10
					{
						type = "text";
						source = "static";
						text = "10";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.365},1};
						right[] = {{0.11,0.365},1};
						down[] = {{0.07,0.395},1};
					};
					class Angle_0
					{
						type = "text";
						source = "static";
						text = "0";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.445},1};
						right[] = {{0.11,0.445},1};
						down[] = {{0.07,0.475},1};
					};
					class Angle_10m
					{
						type = "text";
						source = "static";
						text = "-10";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.525},1};
						right[] = {{0.11,0.525},1};
						down[] = {{0.07,0.555},1};
					};
					class Angle_30m
					{
						type = "text";
						source = "static";
						text = "-30";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.565},1};
						right[] = {{0.11,0.565},1};
						down[] = {{0.07,0.595},1};
					};
					class Angle_90m
					{
						type = "text";
						source = "static";
						text = "-90";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.605},1};
						right[] = {{0.11,0.605},1};
						down[] = {{0.07,0.635},1};
					};
					class GMeterStatic3
					{
						type = "text";
						source = "static";
						text = "3";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.683},1};
						right[] = {{0.11,0.683},1};
						down[] = {{0.07,0.713},1};
					};
					class GMeterStatic2
					{
						type = "text";
						source = "static";
						text = "2";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.723},1};
						right[] = {{0.11,0.723},1};
						down[] = {{0.07,0.753},1};
					};
					class GMeterStatic1
					{
						type = "text";
						source = "static";
						text = "1";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.763},1};
						right[] = {{0.11,0.763},1};
						down[] = {{0.07,0.793},1};
					};
					class GMeterStatic0
					{
						type = "text";
						source = "static";
						text = "0";
						scale = 1;
						sourceScale = 1;
						align = "left";
						pos[] = {{0.07,0.803},1};
						right[] = {{0.11,0.803},1};
						down[] = {{0.07,0.833},1};
					};
					class CollectiveNumber
					{
						type = "text";
						source = "throttle";
						sourceScale = 100;
						align = "left";
						scale = 1;
						pos[] = {{0.889,0.46},1};
						right[] = {{0.939,0.46},1};
						down[] = {{0.889,0.495},1};
					};
					class CollectiveText
					{
						type = "text";
						source = "static";
						text = "%";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.899,0.46},1};
						right[] = {{0.949,0.46},1};
						down[] = {{0.899,0.495},1};
					};
					class ThrustVectoring
					{
						condition = "1+vtolvectoring";
						class VectorigNumber
						{
							type = "text";
							source = "vtolvectoring";
							sourceScale = 90;
							align = "left";
							scale = 1;
							pos[] = {{0.102,0.14},1};
							right[] = {{0.127,0.14},1};
							down[] = {{0.102,0.155},1};
						};
						class VectoringArrow
						{
							type = "line";
							width = 3;
							points[] = {{"ThrustVectoringRotation",{-0.034,-0.006},1},{"ThrustVectoringRotation",{-0.044,0},1},{"ThrustVectoringRotation",{-0.034,0.006},1},{"ThrustVectoringRotation",{-0.034,-0.006},1},{},{"ThrustVectoringRotation",{-0.044,0},1},{"ThrustVectoringRotation",{-0.004,0},1},{}};
						};
					};
					class ThrustVectoringAuto
					{
						condition = "-vtolvectoring";
						class VectorigNumber
						{
							type = "text";
							source = "static";
							sourceScale = 1;
							text = "AUTO";
							align = "left";
							scale = 1;
							pos[] = {{0.103,0.14},1};
							right[] = {{0.123,0.14},1};
							down[] = {{0.103,0.155},1};
						};
					};
					class EngineRPM
					{
						type = "line";
						width = 3;
						points[] = {{{0.89,0.5},1},{{0.89,0.66},1},{},{{0.92,0.5},1},{{0.86,0.5},1},{},{{0.92,0.66},1},{{0.86,0.66},1},{},{{0.91,0.54},1},{{0.87,0.54},1},{},{{0.91,0.58},1},{{0.87,0.58},1},{},{{0.91,0.62},1},{{0.87,0.62},1},{}};
					};
					class EngineRPMLines
					{
						type = "line";
						width = 5;
						points[] = {{{0.91,0.66},1},{"rtdrpm1",{0.91,0.66},1},{},{{0.87,0.66},1},{"rtdrpm2",{0.87,0.66},1},{},{}};
					};
					class RPM60Text
					{
						type = "text";
						source = "static";
						text = "60";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.925,0.645},1};
						right[] = {{0.955,0.645},1};
						down[] = {{0.925,0.67},1};
					};
					class RPM80Text
					{
						type = "text";
						source = "static";
						text = "80";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.925,0.605},1};
						right[] = {{0.955,0.605},1};
						down[] = {{0.925,0.63},1};
					};
					class RPM100Text
					{
						type = "text";
						source = "static";
						text = "100";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.925,0.565},1};
						right[] = {{0.955,0.565},1};
						down[] = {{0.925,0.59},1};
					};
					class RPM120Text
					{
						type = "text";
						source = "static";
						text = "120";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.925,0.525},1};
						right[] = {{0.955,0.525},1};
						down[] = {{0.925,0.55},1};
					};
					class HeadingNumber
					{
						type = "text";
						source = "heading";
						sourceScale = 1;
						align = "center";
						scale = 1;
						pos[] = {{0.498,0.039},1};
						right[] = {{0.538,0.039},1};
						down[] = {{0.498,0.074},1};
					};
					class HeadingRotationArrow
					{
						condition = "5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
						class HeadingArrow
						{
							type = "line";
							width = 3;
							points[] = {{{0.52,0.08},1},{{0.5,0.11},1},{{0.48,0.08},1},{{0.52,0.08},1},{}};
						};
					};
					class HeadingRotation
					{
						condition = "abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
						class HeadingHeadNumber
						{
							type = "text";
							source = "cameraDir";
							sourceScale = 1;
							align = "center";
							scale = 1;
							pos[] = {{0.498,0.083},1};
							right[] = {{0.528,0.083},1};
							down[] = {{0.498,0.114},1};
						};
						class HeadingArrow
						{
							type = "line";
							width = 3;
							points[] = {{{0.478,0.075},1},{{0.522,0.075},1},{{0.552,0.095},1},{{0.522,0.115},1},{{0.478,0.115},1},{{0.448,0.095},1},{{0.478,0.075},1},{}};
						};
					};
					class HeadingScale
					{
						type = "scale";
						horizontal = 1;
						source = "heading";
						sourceScale = 0.1;
						sourceoffset = 0;
						width = 3;
						NeverEatSeaWeed = 1;
						top = 0.15;
						center = 0.5;
						bottom = 0.85;
						lineXleft = 0.114;
						lineYright = 0.12;
						lineXleftMajor = 0.114;
						lineYrightMajor = 0.13;
						majorLineEach = 2;
						numberEach = 6;
						step = 0.5;
						stepSize = 0.0344828;
						align = "center";
						scale = 1;
						pos[] = {0.15,0.13};
						right[] = {0.21,0.13};
						down[] = {0.15,0.17};
					};
					class HorizonBanking
					{
						type = "line";
						width = 3;
						clipTL[] = {0,0.1};
						clipBR[] = {1,0.9};
						points[] = {{"HorizonBankSource",{0.16,0},1},{"HorizonBankSource",{0.1,0},1},{"HorizonBankSource",{0.085,-0.015},1},{"HorizonBankSource",{0.07,0},1},{"HorizonBankSource",{0.05,0},1},{},{"HorizonBankSource",{-0.16,0},1},{"HorizonBankSource",{-0.1,0},1},{"HorizonBankSource",{-0.085,-0.015},1},{"HorizonBankSource",{-0.07,0},1},{"HorizonBankSource",{-0.05,0},1},{}};
					};
					class CoordXNumber
					{
						type = "text";
						source = "coordinateX";
						sourceScale = 0.01;
						sourceLength = 3;
						sourceOffset = -0.5;
						align = "right";
						scale = 1;
						pos[] = {{0.809,0.961},1};
						right[] = {{0.859,0.961},1};
						down[] = {{0.809,0.996},1};
					};
					class CoordYNumber: CoordXNumber
					{
						source = "coordinateY";
						pos[] = {{0.899,0.961},1};
						right[] = {{0.949,0.961},1};
						down[] = {{0.899,0.996},1};
					};
					class Time: CoordXNumber
					{
						source = "time";
						text = "%X";
						align = "left";
						pos[] = {{0.605,0.961},1};
						right[] = {{0.655,0.961},1};
						down[] = {{0.605,0.996},1};
					};
					class CurrentWeapon
					{
						type = "text";
						source = "weapon";
						sourceScale = 1;
						align = "left";
						scale = 1;
						pos[] = {{0.979,0.889},1};
						right[] = {{1.029,0.889},1};
						down[] = {{0.979,0.924},1};
					};
					class CurrentAmmo: CurrentWeapon
					{
						source = "ammo";
						align = "left";
						pos[] = {{0.979,0.921},1};
						right[] = {{1.029,0.921},1};
						down[] = {{0.979,0.956},1};
					};
					class CoordXText
					{
						type = "text";
						source = "static";
						text = "GRID:";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.655,0.961},1};
						right[] = {{0.705,0.961},1};
						down[] = {{0.655,0.996},1};
					};
					class CoordYText
					{
						type = "text";
						source = "static";
						text = "";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{0.875,0.961},1};
						right[] = {{0.925,0.961},1};
						down[] = {{0.875,0.996},1};
					};
					class LightsGroup
					{
						condition = "lights";
						class LightsText
						{
							type = "text";
							source = "static";
							text = "LIGHT";
							align = "left";
							scale = 1;
							pos[] = {{0.149,0.961},1};
							right[] = {{0.199,0.961},1};
							down[] = {{0.149,0.996},1};
						};
					};
					class CollisionLights
					{
						condition = "collisionlights";
						class CollisionLightsText
						{
							type = "text";
							source = "static";
							text = "COLL";
							align = "left";
							scale = 1;
							pos[] = {{0.309,0.961},1};
							right[] = {{0.359,0.961},1};
							down[] = {{0.309,0.996},1};
						};
					};
					class WeaponsLocking
					{
						condition = "missilelocking";
						blinkingPattern[] = {0.2,0.2};
						blinkingStartsOn = 1;
						class Text
						{
							type = "text";
							source = "static";
							text = "LOCKING";
							align = "center";
							scale = 1;
							pos[] = {{0.215,0.879701},1};
							right[] = {{0.275,0.879701},1};
							down[] = {{0.215,0.928846},1};
						};
					};
					class TargetInfo
					{
						condition = "missilelocked";
						class TargetLockedText
						{
							type = "text";
							source = "static";
							text = "TARGET ACQUIRED";
							scale = 1;
							sourceScale = 1;
							align = "center";
							pos[] = {{0.195,0.859},1};
							right[] = {{0.235,0.859},1};
							down[] = {{0.195,0.89},1};
						};
						class TimeOfFlightText
						{
							type = "text";
							source = "static";
							text = "TOF:";
							scale = 1;
							sourceScale = 1;
							align = "left";
							pos[] = {{0.257,0.889},1};
							right[] = {{0.302,0.889},1};
							down[] = {{0.257,0.924},1};
						};
						class DistanceText
						{
							type = "text";
							source = "static";
							text = "DISTANCE:";
							scale = 1;
							sourceScale = 1;
							align = "left";
							pos[] = {{0.255,0.921},1};
							right[] = {{0.3,0.921},1};
							down[] = {{0.255,0.956},1};
						};
						class TOF_source: CurrentWeapon
						{
							source = "missileflighttime";
							align = "right";
							pos[] = {{0.269,0.889},1};
							right[] = {{0.319,0.889},1};
							down[] = {{0.269,0.924},1};
						};
						class TargetDistance: CurrentWeapon
						{
							source = "targetDist";
							sourceLength = 0;
							sourcePrecision = 1;
							sourceScale = 0.001;
							align = "right";
							pos[] = {{0.269,0.921},1};
							right[] = {{0.319,0.921},1};
							down[] = {{0.269,0.956},1};
						};
					};
					class IncomingMissile
					{
						condition = "incomingmissile";
						blinkingPattern[] = {0.3,0.3};
						blinkingStartsOn = 1;
						class Text
						{
							type = "text";
							source = "static";
							text = "!INCOMING MISSILE!";
							align = "center";
							scale = 1;
							pos[] = {{0.485,0.216239},1};
							right[] = {{0.545,0.216239},1};
							down[] = {{0.485,0.265385},1};
						};
					};
					class GearGroup
					{
						type = "group";
						condition = "ils";
						class GearText
						{
							type = "text";
							source = "static";
							text = "GEAR";
							align = "center";
							scale = 1;
							pos[] = {{0.5,0.889},1};
							right[] = {{0.54,0.889},1};
							down[] = {{0.5,0.924},1};
						};
					};
					class ILS
					{
						condition = "ils";
						class Glideslope
						{
							clipTL[] = {0,0};
							clipBR[] = {1,1};
							class ILS
							{
								type = "line";
								points[] = {{"ILS_W",{-0.24,0},1},{"ILS_W",{0.24,0},1},{},{"ILS_W",{-0.24,-0.0235897},1},{"ILS_W",{-0.24,0.0235897},1},{},{"ILS_W",{-0.12,-0.0176923},1},{"ILS_W",{-0.12,0.0176923},1},{},{"ILS_W",{0,-0.0235897},1},{"ILS_W",{0,0.0235897},1},{},{"ILS_W",{0.12,-0.0176923},1},{"ILS_W",{0.12,0.0176923},1},{},{"ILS_W",{0.24,-0.0235897},1},{"ILS_W",{0.24,0.0235897},1},{},{"ILS_H",{0,-0.235897},1},{"ILS_H",{0,0.235897},1},{},{"ILS_H",{-0.024,-0.235897},1},{"ILS_H",{0.024,-0.235897},1},{},{"ILS_H",{-0.018,-0.117949},1},{"ILS_H",{0.018,-0.117949},1},{},{"ILS_H",{-0.024,0},1},{"ILS_H",{0.024,0},1},{},{"ILS_H",{-0.018,0.117949},1},{"ILS_H",{0.018,0.117949},1},{},{"ILS_H",{-0.024,0.235897},1},{"ILS_H",{0.024,0.235897},1}};
							};
							class airport
							{
								type = "line";
								points[] = {{"airport1",1},{"airport2",1},{"airport4",1},{"airport3",1},{"airport1",1}};
							};
						};
					};
					class MGun
					{
						condition = "-2+mgun*ImpactDistance";
						class Cross
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0294872},1},{"ImpactPoint",{0,-0.0393162},1},{},{"ImpactPoint",{0.02,-0.024},1},{"ImpactPoint",{0.025,-0.031},1},{},{"ImpactPoint",{0,-0.002},1},{"ImpactPoint",{0,0.002},1},{},{"ImpactPoint",{-0.002,0},1},{"ImpactPoint",{0.002,0},1},{}};
						};
						class Circle
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0275214},1},{"ImpactPoint",{0,-0.0344017},1},{"MissileFlightTimeRot1",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot2",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot3",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot4",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot5",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot6",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot7",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot8",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot9",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot10",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot11",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot12",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot13",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot14",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot15",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot16",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot17",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot18",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot19",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.028},1,"ImpactPoint",1}};
						};
						class Circle_Min_Range
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0294872},1},{"ImpactPoint",{0.005208,-0.029039},1},{"ImpactPoint",{0.01026,-0.0277091},1},{"ImpactPoint",{0.015,-0.0255359},1},{"ImpactPoint",{0.019284,-0.0225872},1},{"ImpactPoint",{0.02298,-0.0189544},1},{"ImpactPoint",{0.02598,-0.0147436},1},{"ImpactPoint",{0.028191,-0.0100846},1},{"ImpactPoint",{0.029544,-0.00511897},1},{"ImpactPoint",{0.03,0},1},{"ImpactPoint",{0.029544,0.00511897},1},{"ImpactPoint",{0.028191,0.0100846},1},{"ImpactPoint",{0.02598,0.0147436},1},{"ImpactPoint",{0.02298,0.0189544},1},{"ImpactPoint",{0.019284,0.0225872},1},{"ImpactPoint",{0.015,0.0255359},1},{"ImpactPoint",{0.01026,0.0277091},1},{"ImpactPoint",{0.005208,0.029039},1},{"ImpactPoint",{0,0.0294872},1},{"ImpactPoint",{-0.005208,0.029039},1},{"ImpactPoint",{-0.01026,0.0277091},1},{"ImpactPoint",{-0.015,0.0255359},1},{"ImpactPoint",{-0.019284,0.0225872},1},{"ImpactPoint",{-0.02298,0.0189544},1},{"ImpactPoint",{-0.02598,0.0147436},1},{"ImpactPoint",{-0.028191,0.0100846},1},{"ImpactPoint",{-0.029544,0.00511897},1},{"ImpactPoint",{-0.03,0},1},{"ImpactPoint",{-0.029544,-0.00511897},1},{"ImpactPoint",{-0.028191,-0.0100846},1},{"ImpactPoint",{-0.02598,-0.0147436},1},{"ImpactPoint",{-0.02298,-0.0189544},1},{"ImpactPoint",{-0.019284,-0.0225872},1},{"ImpactPoint",{-0.015,-0.0255359},1},{"ImpactPoint",{-0.01026,-0.0277091},1},{"ImpactPoint",{-0.005208,-0.029039},1},{"ImpactPoint",{0,-0.0294872},1}};
						};
						class Distance
						{
							type = "text";
							source = "ImpactDistance";
							sourceScale = 0.001;
							sourcePrecision = 1;
							max = 15;
							align = "center";
							scale = 1;
							pos[] = {"ImpactPoint",{-0.002,-0.08},1};
							right[] = {"ImpactPoint",{0.045,-0.08},1};
							down[] = {"ImpactPoint",{-0.002,-0.04},1};
						};
					};
					class Rockets
					{
						condition = "-2+rocket*ImpactDistance";
						class Cross
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0294872},1},{"ImpactPoint",{0,-0.0393162},1},{},{"ImpactPoint",{0.02,-0.024},1},{"ImpactPoint",{0.025,-0.031},1},{},{"ImpactPoint",{0,-0.002},1},{"ImpactPoint",{0,0.002},1},{},{"ImpactPoint",{-0.002,0},1},{"ImpactPoint",{0.002,0},1},{}};
						};
						class Circle
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0275214},1},{"ImpactPoint",{0,-0.0344017},1},{"MissileFlightTimeRot1",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot2",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot3",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot4",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot5",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot6",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot7",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot8",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot9",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot10",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot11",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot12",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot13",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot14",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot15",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot16",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot17",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot18",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot19",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.035},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.028},1,"ImpactPoint",1}};
						};
						class Circle_Min_Range
						{
							type = "line";
							width = 3;
							points[] = {{"ImpactPoint",{0,-0.0294872},1},{"ImpactPoint",{0.005208,-0.029039},1},{"ImpactPoint",{0.01026,-0.0277091},1},{"ImpactPoint",{0.015,-0.0255359},1},{"ImpactPoint",{0.019284,-0.0225872},1},{"ImpactPoint",{0.02298,-0.0189544},1},{"ImpactPoint",{0.02598,-0.0147436},1},{"ImpactPoint",{0.028191,-0.0100846},1},{"ImpactPoint",{0.029544,-0.00511897},1},{"ImpactPoint",{0.03,0},1},{"ImpactPoint",{0.029544,0.00511897},1},{"ImpactPoint",{0.028191,0.0100846},1},{"ImpactPoint",{0.02598,0.0147436},1},{"ImpactPoint",{0.02298,0.0189544},1},{"ImpactPoint",{0.019284,0.0225872},1},{"ImpactPoint",{0.015,0.0255359},1},{"ImpactPoint",{0.01026,0.0277091},1},{"ImpactPoint",{0.005208,0.029039},1},{"ImpactPoint",{0,0.0294872},1},{"ImpactPoint",{-0.005208,0.029039},1},{"ImpactPoint",{-0.01026,0.0277091},1},{"ImpactPoint",{-0.015,0.0255359},1},{"ImpactPoint",{-0.019284,0.0225872},1},{"ImpactPoint",{-0.02298,0.0189544},1},{"ImpactPoint",{-0.02598,0.0147436},1},{"ImpactPoint",{-0.028191,0.0100846},1},{"ImpactPoint",{-0.029544,0.00511897},1},{"ImpactPoint",{-0.03,0},1},{"ImpactPoint",{-0.029544,-0.00511897},1},{"ImpactPoint",{-0.028191,-0.0100846},1},{"ImpactPoint",{-0.02598,-0.0147436},1},{"ImpactPoint",{-0.02298,-0.0189544},1},{"ImpactPoint",{-0.019284,-0.0225872},1},{"ImpactPoint",{-0.015,-0.0255359},1},{"ImpactPoint",{-0.01026,-0.0277091},1},{"ImpactPoint",{-0.005208,-0.029039},1},{"ImpactPoint",{0,-0.0294872},1}};
						};
						class Distance
						{
							type = "text";
							source = "ImpactDistance";
							sourceScale = 0.001;
							sourcePrecision = 1;
							max = 15;
							align = "center";
							scale = 1;
							pos[] = {"ImpactPoint",{-0.002,-0.08},1};
							right[] = {"ImpactPoint",{0.045,-0.08},1};
							down[] = {"ImpactPoint",{-0.002,-0.04},1};
						};
					};
					class BombCrosshairGroup
					{
						type = "group";
						condition = "bomb";
						class BombCrosshair
						{
							type = "line";
							width = 4;
							points[] = {{"ImpactPoint",{0,-0.0982906},1},{"ImpactPoint",{0.01736,-0.0967966},1},{"ImpactPoint",{0.0342,-0.0923637},1},{"ImpactPoint",{0.05,-0.0851197},1},{"ImpactPoint",{0.06428,-0.0752906},1},{"ImpactPoint",{0.0766,-0.0631812},1},{"ImpactPoint",{0.0866,-0.0491453},1},{"ImpactPoint",{0.09397,-0.0336154},1},{"ImpactPoint",{0.09848,-0.0170632},1},{"ImpactPoint",{0.1,0},1},{"ImpactPoint",{0.09848,0.0170632},1},{"ImpactPoint",{0.09397,0.0336154},1},{"ImpactPoint",{0.0866,0.0491453},1},{"ImpactPoint",{0.0766,0.0631812},1},{"ImpactPoint",{0.06428,0.0752906},1},{"ImpactPoint",{0.05,0.0851197},1},{"ImpactPoint",{0.0342,0.0923637},1},{"ImpactPoint",{0.01736,0.0967966},1},{"ImpactPoint",{0,0.0982906},1},{"ImpactPoint",{-0.01736,0.0967966},1},{"ImpactPoint",{-0.0342,0.0923637},1},{"ImpactPoint",{-0.05,0.0851197},1},{"ImpactPoint",{-0.06428,0.0752906},1},{"ImpactPoint",{-0.0766,0.0631812},1},{"ImpactPoint",{-0.0866,0.0491453},1},{"ImpactPoint",{-0.09397,0.0336154},1},{"ImpactPoint",{-0.09848,0.0170632},1},{"ImpactPoint",{-0.1,0},1},{"ImpactPoint",{-0.09848,-0.0170632},1},{"ImpactPoint",{-0.09397,-0.0336154},1},{"ImpactPoint",{-0.0866,-0.0491453},1},{"ImpactPoint",{-0.0766,-0.0631812},1},{"ImpactPoint",{-0.06428,-0.0752906},1},{"ImpactPoint",{-0.05,-0.0851197},1},{"ImpactPoint",{-0.0342,-0.0923637},1},{"ImpactPoint",{-0.01736,-0.0967966},1},{"ImpactPoint",{0,-0.0982906},1},{},{"ImpactPoint",1,"Limit0109",1,{0,-0.0196581},1},{"ImpactPoint",1,"Limit0109",1,{0.014,-0.0137607},1},{"ImpactPoint",1,"Limit0109",1,{0.02,0},1},{"ImpactPoint",1,"Limit0109",1,{0.014,0.0137607},1},{"ImpactPoint",1,"Limit0109",1,{0,0.0196581},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,0.0137607},1},{"ImpactPoint",1,"Limit0109",1,{-0.02,0},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,-0.0137607},1},{"ImpactPoint",1,"Limit0109",1,{0,-0.0196581},1},{},{"VelocityVector",0.001,"ImpactPoint",1,"Limit0109",1,{0,0},1},{"VelocityVector",1,"Limit0109",1,{0,0},1}};
						};
						class Distance
						{
							type = "text";
							source = "ImpactDistance";
							sourceScale = 0.001;
							sourcePrecision = 1;
							max = 15;
							align = "center";
							scale = 1;
							pos[] = {"ImpactPoint",{-0.002,0.11},1};
							right[] = {"ImpactPoint",{0.045,0.11},1};
							down[] = {"ImpactPoint",{-0.002,0.15},1};
						};
					};
					class WP
					{
						condition = "wpvalid";
						class WPdist
						{
							type = "text";
							source = "wpdist";
							sourceScale = 0.001;
							sourcePrecision = 1;
							align = "left";
							scale = 1;
							pos[] = {{0.935,0.797137},1};
							right[] = {{0.975,0.797137},1};
							down[] = {{0.935,0.834487},1};
						};
						class WPstatic
						{
							type = "text";
							source = "static";
							text = ">";
							align = "center";
							scale = 2;
							pos[] = {{0.95,0.797137},1};
							right[] = {{0.97,0.797137},1};
							down[] = {{0.95,0.834487},1};
						};
						class WPIndex
						{
							type = "text";
							source = "wpIndex";
							sourceScale = 1;
							align = "right";
							scale = 1;
							pos[] = {{0.96,0.797137},1};
							right[] = {{1,0.797137},1};
							down[] = {{0.96,0.834487},1};
						};
						class WP
						{
							width = 1;
							type = "line";
							points[] = {{"wppoint",1,{"HorizonBankRotFull",0.015,-0.035},1},{"wppoint",1,{"HorizonBankRotFull",0,0},1},{"wppoint",1,{"HorizonBankRotFull",-0.015,-0.035},1}};
						};
					};
					class RadarBoxes
					{
						type = "radartoview";
						pos0[] = {0.5,0.5};
						pos10[] = {0.734,0.73};
						width = 2;
						points[] = {{{-0.002,-0.00196581},1},{{0.002,-0.00196581},1},{{0.002,0.00196581},1},{{-0.002,0.00196581},1},{{-0.002,-0.00196581},1}};
					};
					class TargetDiamond
					{
						class shape
						{
							type = "line";
							width = 4;
							points[] = {{"Target",1,"Limit0109",1,{0.02,0.0196581},1},{"Target",1,"Limit0109",1,{-0.02,0.0196581},1},{"Target",1,"Limit0109",1,{-0.02,-0.0196581},1},{"Target",1,"Limit0109",1,{0.02,-0.0196581},1},{"Target",1,"Limit0109",1,{0.02,0.0196581},1}};
						};
					};
					class TargetLocked
					{
						condition = "missilelocked";
						class shape
						{
							type = "line";
							width = 4;
							points[] = {{"Target",1,"Limit0109",1,{0,-0.0294872},1},{"Target",1,"Limit0109",1,{0.03,0},1},{"Target",1,"Limit0109",1,{0,0.0294872},1},{"Target",1,"Limit0109",1,{-0.03,0},1},{"Target",1,"Limit0109",1,{0,-0.0294872},1}};
						};
					};
				};
			};
			class HMD_CMPilot: AirplaneHUD
			{
				turret[] = {-1};
				class Draw
				{
					alpha = "user3";
					color[] = {"user0","user1","user2"};
					condition = "on - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37)";
					class CMName
					{
						type = "text";
						source = "cmweapon";
						sourceScale = 1;
						align = "left";
						scale = 1;
						pos[] = {{0.869,0.849},1};
						right[] = {{0.919,0.849},1};
						down[] = {{0.869,0.884},1};
					};
					class CMCount
					{
						type = "text";
						source = "cmammo";
						sourceScale = 1;
						align = "left";
						scale = 1;
						pos[] = {{0.979,0.849},1};
						right[] = {{1.029,0.849},1};
						down[] = {{0.979,0.884},1};
					};
				};
			};
		};
		irTarget = 1;
		irTargetSize = 0.95;
		radarTarget = 1;
		radarTargetSize = 0.9;
		allowTabLock = 1;
		driverCanSee = 31;
		canUseScanners = 1;
		showAllTargets = 2;
		memoryPointGun[] = {"Usti hlavne L","Usti hlavne R"};
		simulation = "airplaneX";
		vtol = 4;
		scope = 1;
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		model = "3as\3AS_ARC170\model\ARC_170.p3d";
		displayName = "[3AS] ARC-170X";
		crew = "JLTS_Clone_P2_DC15S";
		icon = "3as\3AS_ARC170\Data\ui\ARC_top_ca.paa";
		picture = "3as\3AS_ARC170\Data\ui\ARC_side_ca.paa";
		selectionFireAnim = "zasleh";
		side = 1;
		driverCanEject = 1;
		cargoCanEject = 0;
		laserScanner = 1;
		faction = "BLU_F";
		weapons[] = {"3AS_ARC_Light_Canon","CMFlareLauncher","Laserdesignator_pilotCamera"};
		magazines[] = {"3AS_ARC_500Rnd_Light_Shells","3AS_ARC_500Rnd_Light_Shells","120Rnd_CMFlare_Chaff_Magazine","Laserbatteries","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine"};
		memoryPointDriverOptics = "PilotCamera_1";
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 4;
				explosionShielding = 3;
				name = "HitHull";
				passThrough = 1;
				visual = "Hit_Hull";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "0";
				material = -1;
			};
			class HitEngine: HitHull
			{
				armor = 3;
				explosionShielding = 4;
				name = "HitEngine";
				passThrough = 1;
				visual = "Hit_Engine";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "0";
			};
			class HitFuel: HitHull
			{
				armor = 4.5;
				explosionShielding = 4;
				name = "HitFuel";
				passThrough = 0.8;
				visual = "";
				radius = 0.3;
				minimalHit = 0.1;
				depends = "0";
			};
			class HitLAileron: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = "HitLAileron";
				passThrough = 0.3;
				visual = "Hit_AileronL";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "HitLAileron_Link";
			};
			class HitRAileron: HitLAileron
			{
				armor = 1.5;
				explosionShielding = 3;
				name = "HitRAileron";
				passThrough = 0.3;
				visual = "Hit_AileronR";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "HitRAileron_Link";
			};
			class HitLCRudder: HitHull
			{
				armor = 2;
				explosionShielding = 3;
				name = "HitLCRudder";
				passThrough = 0.3;
				visual = "Hit_RudderC";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "0";
			};
			class HitLCElevator: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = "HitLCElevator";
				passThrough = 0.3;
				visual = "Hit_ElevatorL";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "0";
			};
			class HitRElevator: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = "HitRElevator";
				passThrough = 0.3;
				visual = "Hit_ElevatorR";
				radius = 0.3;
				minimalHit = 0.05;
				depends = "0";
			};
		};
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
					renderVisionMode = 0;
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
					renderVisionMode = 0;
					fov = 0.203452;
				};
				BBoxes[] = {"PIP_GUN2_TL","PIP_GUN2_TR","PIP_GUN2_BL","PIP_GUN2_BR"};
			};
		};
		class Turrets
		{
			class Reargun: NewTurret
			{
				isCopilot = 0;
				canEject = 1;
				startEngine = 0;
				class OpticsIn: Optics_Commander_02
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				soundServo[] = {"",0.01,1};
				outGunnerMayFire = 1;
				commanding = -1;
				primaryGunner = 0;
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				gunnerinaction = "Plane_Fighter_03_pilot";
				gunneropticseffect[] = {"TankCommanderOptics1","BWTV"};
				memorypointgunneroptics = "gunnerview";
				memorypointsgetingunner = "pos gunner";
				memorypointsgetingunnerdir = "pos gunner dir";
				stabilizedInAxes = 3;
				gunneraction = "Plane_Fighter_03_pilot";
				gunnerforceoptics = 0;
				gunnerName = "Rear Gunner";
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
				discreteDistance[] = {100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discreteDistanceInitIndex = 5;
				weapons[] = {"3AS_ARC_Light_Canon_Rear","CMFlareLauncher"};
				magazines[] = {"3AS_ARC_500Rnd_Light_Shells","240Rnd_CMFlare_Chaff_Magazine"};
				minElev = -5;
				maxturn = 270;
				minturn = 90;
				maxElev = 60;
				initTurn = 180;
				initElev = 0;
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
				gunnerForceOptics = 0;
				enableManualFire = 1;
				primaryGunner = 0;
				body = "Mainturret2";
				gun = "maingun2";
				animationSourceBody = "mainturret2";
				animationSourceGun = "maingun2";
				weapons[] = {"3AS_ARC_Heavy_Canon"};
				magazines[] = {"3AS_PylonWeapon_ARC_240Rnd_Heavy_Shells","3AS_PylonWeapon_ARC_240Rnd_Heavy_Shells"};
				gunnerName = "Co-pilot";
				gunBeg = "usti hlavne b2";
				gunEnd = "konec hlavne b2";
				memoryPointGun = "konec hlavne b2";
				selectionFireAnim = "zasleh4";
				usepip = 2;
				class OpticsIn: Optics_Gunner_MBT_03
				{
					class Wide: Wide{};
					class Medium: Medium{};
					class Narrow: Narrow{};
				};
				proxyIndex = 2;
				minElev = -90;
				maxturn = 240;
				minturn = 120;
				maxElev = 0;
				initTurn = 180;
				initElev = -10;
				maxHorizontalRotSpeed = 3;
				maxVerticalRotSpeed = 3;
				class HitPoints{};
			};
		};
		class Eventhandlers: Eventhandlers
		{
			postInit = "if (local (_this select 0)) then { [(_this select 0), """", [], false] call BIS_fnc_initVehicle; };";
		};
		hiddenselections[] = {"camo1","camo2","guns"};
		hiddenselectionstextures[] = {"","","","a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"3as\3AS_ARC170\Data\Main_Frame.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_damage.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_destruct.rvmat","3as\3AS_ARC170\Data\Wings.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_damage.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_destruct.rvmat","3as\3AS_ARC170\Data\Guns.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_damage.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_destruct.rvmat","a3\air_f_jets\plane_fighter_01\data\fighter_01_glass.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_glass_damage.rvmat","A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_glass_destruct.rvmat"};
		};
		insideSoundCoef = 0.2;
		destrType = "DestructWreck";
		driveraction = "Plane_Fighter_03_pilot";
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
							maxRange = 5000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 50;
						angleRangeVertical = 37;
						maxTrackableSpeed = 100;
						componentType = "IRSensorComponent";
						typeRecognitionDistance = 2000;
						maxFogSeeThrough = 0.995;
						color[] = {1,0,0,1};
						allowsMarking = 1;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = "";
						aimDown = 0;
						minTrackableSpeed = -1e+10;
						minTrackableATL = -1e+10;
						maxTrackableATL = 1e+10;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 26;
						angleRangeVertical = 20;
						maxTrackableSpeed = 100;
						aimDown = 1;
						animDirection = "pilotCameraRotY";
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						componentType = "PassiveRadarSensorComponent";
						class AirTarget
						{
							minRange = 12000;
							maxRange = 12000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 8000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 8000;
						angleRangeHorizontal = 150;
						angleRangeVertical = 90;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						animDirection = "";
						aimDown = 0;
						color[] = {0.5,1,0.5,0.5};
						minTrackableSpeed = -1e+10;
						maxTrackableSpeed = 1e+10;
						minTrackableATL = -1e+10;
						maxTrackableATL = 1e+10;
						allowsMarking = 0;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 10000;
							maxRange = 10000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 8000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 4000;
						angleRangeHorizontal = 45;
						angleRangeVertical = 45;
						groundNoiseDistanceCoef = 0.2;
					};
					class AntiRadiationSensorComponent: SensorTemplateAntiRadiation
					{
						class AirTarget
						{
							minRange = 6000;
							maxRange = 6000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 6000;
							maxRange = 6000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableATL = 100;
						maxTrackableSpeed = 60;
						angleRangeHorizontal = 70;
						angleRangeVertical = 60;
					};
					class LaserSensorComponent: SensorTemplateLaser{};
					class NVSensorComponent: SensorTemplateNV{};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType = "EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType = "UAVFeedDisplayComponent";
					};
					class VehicleDriverDisplay
					{
						componentType = "TransportFeedDisplayComponent";
						source = "Driver";
					};
					class VehicleMissileDisplay
					{
						componentType = "TransportFeedDisplayComponent";
						source = "Missile";
					};
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay = "SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType = "EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType = "UAVFeedDisplayComponent";
					};
					class VehicleDriverDisplay
					{
						componentType = "TransportFeedDisplayComponent";
						source = "Driver";
					};
					class VehicleMissileDisplay
					{
						componentType = "TransportFeedDisplayComponent";
						source = "Missile";
					};
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture = "3as\3AS_ARC170\data\ui\pylon_arc.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[] = {"B_BIM9X_DUAL_RAIL","B_AGM65_RAIL","REP_AGM_RAIL"};
						attachment = "PylonRack_Missile_BIM9X_x2";
						priority = 10;
						maxweight = 300;
						UIposition[] = {0.5,0.25};
					};
					class pylons2: pylons1
					{
						UIposition[] = {0.15,0.25};
						mirroredMissilePos = 1;
					};
					class pylons3: pylons1
					{
						hardpoints[] = {"B_AMRAAM_D_RAIL","B_AMRAAM_D_DUAL_RAIL","B_AGM65_RAIL","B_AGM65_DUAL_RAIL","ARC_AGM_PYLON","B_BOMB_PYLON"};
						attachment = "PylonMissile_1Rnd_Bomb_04_F";
						priority = 9;
						maxweight = 2500;
						UIposition[] = {0.55,0.35};
					};
					class pylons4: pylons3
					{
						UIposition[] = {0.1,0.35};
						mirroredMissilePos = 3;
					};
					class pylons5: pylons1
					{
						hardpoints[] = {"B_AMRAAM_D_RAIL","B_AGM65_RAIL","B_AGM65_DUAL_RAIL","B_HARM_RAIL","ARC_AGM_PYLON"};
						attachment = "PylonRack_Missile_AMRAAM_D_x1";
						priority = 7;
						maxweight = 5000;
						UIposition[] = {0.6,0.45};
					};
					class pylons6: pylons5
					{
						UIposition[] = {0.05,0.45};
						mirroredMissilePos = 5;
					};
				};
				class presets
				{
					class empty
					{
						displayName = "$STR_empty";
						attachment[] = {};
					};
					class AA
					{
						displayName = "$STR_A3_cfgmagazines_titan_aa_dns";
						attachment[] = {"PylonRack_Missile_BIM9X_x1","PylonRack_Missile_BIM9X_x1","3AS_PylonRack_ARC_6Rnd_Missile_AGM","3AS_PylonRack_ARC_6Rnd_Missile_AGM","PylonRack_Missile_AMRAAM_D_x1","PylonRack_Missile_AMRAAM_D_x1"};
					};
					class CAS
					{
						displayName = "$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[] = {"PylonRack_Missile_BIM9X_x1","PylonRack_Missile_BIM9X_x1","PylonMissile_1Rnd_Bomb_04_F","PylonMissile_1Rnd_Bomb_04_F","3AS_PylonRack_ARC_6Rnd_Missile_AGM","3AS_PylonRack_ARC_6Rnd_Missile_AGM"};
					};
				};
			};
		};
		driveoncomponent[] = {};
		camouflage = 8;
		audible = 10;
		accuracy = 0.2;
		memoryPointCM[] = {"flare_launcher1","flare_launcher2"};
		memoryPointCMDir[] = {"flare_launcher1_dir","flare_launcher2_dir"};
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 0;
		tBody = 0;
		radartype = 4;
		lockdetectionsystem = 14;
		incommingmissliedetectionsystem = 16;
		acceleration = 200;
		maxSpeed = 615;
		landingAoa = 0.10471666;
		landingSpeed = 215;
		stallSpeed = 50;
		stallWarningTreshold = 0.1;
		armor = 175;
		armorStructured = 1;
		draconicTorqueYCoef[] = {0,1.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		draconicForceYCoef = 6;
		envelope[] = {0.1,0.19,0.29,1.6,1.9,2.59,4,5.3,6.91,8.75,9.8,9.5,9.4,8.6,8.2,8};
		draconicForceXCoef = 6;
		draconicForceZCoef = 6.5;
		draconicTorqueXCoef = 2.1;
		angleOfIndicence = 0.08;
		airFriction0[] = {75,50,12};
		airFriction1[] = {75,50,12};
		airFriction2[] = {75,50,12};
		altNoForce = 13000;
		altFullForce = 10000;
		elevatorCoef[] = {0.2,0.39,0.51,0.6,0.68,0.75,0.8,0.85,0.9,0.74,0.3};
		elevatorSensitivity = 0.9;
		elevatorControlsSensitivityCoef = 4.0;
		aileronCoef[] = {0.5,0.7,1,1,1.2,1.15,1.1};
		aileronSensitivity = 2;
		aileronControlsSensitivityCoef = 3;
		rudderCoef[] = {1.6,2,2,2.9,2.8,2,1};
		rudderInfluence = 0.9;
		rudderControlsSensitivityCoef = 6;
		thrustCoef[] = {1.8,1.9,1.95,2,2.5,3,3.5,2.5,2,1.7,1.5,1.1,1,1,1};
		irScanRangeMin = 10;
		irScanRangeMax = 10000;
		irScanToEyeFactor = 8;
		fuelCapacity = 2000;
		wheelSteeringSensitivity = 1.5;
		maxOmega = 2000;
		airBrake = 90;
		airBrakeFrictionCoef = 75;
		flaps = 1;
		flapsFrictionCoef = 0.32;
		gearsUpFrictionCoef = 0.6;
		airFrictionCoefs0[] = {0,0,0};
		airFrictionCoefs1[] = {0.1,0.5,0.0066};
		airFrictionCoefs2[] = {0.001,0.005,6.8e-05};
		memoryPointLRocket = "P Raketa";
		memoryPointRRocket = "L Raketa";
		type = "VAir";
		cost = 10000000;
		threat[] = {0.2,1.0,0.9};
		VTOLPitchInfluence = 1;
		VTOLRollInfluence = 10;
		VTOLYawInfluence = 12;
		explosionShielding = 5.25;
		class camShakeGForce
		{
			power = 1;
			frequency = 20;
			distance = 0;
			minSpeed = 1;
		};
		minGForce = 0.3;
		maxGForce = 10;
		gForceShakeAttenuation = 0.5;
		class AnimationSources: AnimationSources
		{
			class SFoil
			{
				source = "user";
				animPeriod = 1;
				initPhase = 1;
			};
			class Muzzle_Flash
			{
				source = "ammorandom";
				weapon = "3AS_ARC_Light_Canon";
			};
			class Muzzle_Flash2
			{
				source = "ammorandom";
				weapon = "3AS_ARC_Light_Canon_Rear";
			};
			class Muzzle_Flash3
			{
				source = "ammorandom";
				weapon = "3AS_ARC_Heavy_Canon";
			};
			class recoil_source
			{
				source = "reload";
				weapon = "3AS_ARC_Heavy_Canon";
			};
		};
		class UserActions: UserActions
		{
			class deploySfoils
			{
				displayName = "Fold S-Foils";
				position = "action";
				radius = 10;
				onlyForPlayer = 0;
				condition = "(this animationSourcePhase ""SFoil"" == 0) AND (currentPilot this isEqualTo player) AND (alive this)";
				statement = "this animateSource [""SFoil"",1]";
			};
			class undeploySfoils: deploySfoils
			{
				displayName = "Deploy S-Foils";
				condition = "(this animationSourcePhase ""SFoil"" == 1) AND (currentPilot this isEqualTo player) AND (alive this)";
				statement = "this animateSource [""SFoil"",0]";
			};
		};
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";
				position = "body_vapour_L_E";
			};
			class WingTipRight
			{
				effectName = "WingVortices";
				position = "body_vapour_R_E";
			};
		};
		class Exhausts
		{
			class Exhaust_main
			{
				position = "exhaust1";
				direction = "Exhaust1_dir";
				effect = "ExhaustsEffectPlane";
			};
			class Exhaust_main2
			{
				position = "exhaust2";
				direction = "Exhaust2_dir";
				effect = "ExhaustsEffectPlane";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {7000,7500,10000,1};
				ambient[] = {100,100,100};
				position = "Light_L";
				direction = "Light_L_end";
				hitpoint = "Light";
				selection = "";
				innerAngle = 20;
				outerAngle = 60;
				coneFadeCoef = 10;
				intensity = 50;
				useFlare = 1;
				dayLight = 0;
				FlareSize = 4;
				size = 1;
				class Attenuation
				{
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 4;
					hardLimitStart = 150;
					hardLimitEnd = 300;
				};
			};
			class Right: Left
			{
				position = "Light_R";
				direction = "Light_R_end";
				hitpoint = "Light_R";
			};
		};
		class MarkerLights
		{
			class PositionRed
			{
				color[] = {0.8,0,0};
				ambient[] = {0.08,0,0};
				intensity = 75;
				name = "PositionLight_red_1_pos";
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 25;
					quadratic = 50;
					hardLimitStart = 0.75;
					hardLimitEnd = 1;
				};
			};
			class PositionGreen: PositionRed
			{
				color[] = {0,0.8,0};
				ambient[] = {0,0.08,0};
				name = "PositionLight_green_1_pos";
			};
			class PositionWhite: PositionRed
			{
				color[] = {1,1,1};
				ambient[] = {0.1,0.1,0.1};
				name = "PositionLight_white_1_pos";
				drawLightSize = 0.2;
			};
			class CollisionRed: PositionRed
			{
				color[] = {0.9,0.15,0.1};
				ambient[] = {0.09,0.015,0.01};
				name = "CollisionLight_red_1_pos";
				blinking = 1;
				blinkingPattern[] = {0.2,1.3};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.08;
			};
			class CollisionWhite: PositionRed
			{
				color[] = {1,1,1};
				ambient[] = {0.1,0.1,0.1};
				name = "CollisionLight_white_1_pos";
				blinking = 1;
				blinkingPattern[] = {0.1,0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
		};
		attenuationEffectType = "HeliAttenuation";
		soundGetIn[] = {"A3\Sounds_F\air\Plane_Fighter_03\buzzard_getin.wss","db0",1,40};
		soundGetOut[] = {"A3\Sounds_F\air\Plane_Fighter_03\getout.wss","db0",1,40};
		soundDammage[] = {"","db-5",1};
		soundEngineOnInt[] = {"3AS\3as_arc170\Sounds\ARCStart.ogg","db-0",1.0};
		soundEngineOnExt[] = {"3AS\3as_arc170\Sounds\ARCStart.ogg","db5",1.0,500};
		soundEngineOffInt[] = {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-stop_int.wss","db-0",1.0};
		soundEngineOffExt[] = {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-stop_ext.wss","db5",1.0,500};
		soundLocked[] = {"\A3\Sounds_F\weapons\Rockets\locked_1.wss","db-20",1};
		soundIncommingMissile[] = {"\A3\Sounds_F\weapons\Rockets\locked_3.wss","db-20",1.5};
		soundGearUp[] = {"A3\Sounds_F_EPC\CAS_02\gear_up.wss","db-2",1.0,150};
		soundGearDown[] = {"A3\Sounds_F_EPC\CAS_02\gear_down.wss","db-2",1.0,150};
		soundFlapsUp[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Up.wss","db-4",1.0,100};
		soundFlapsDown[] = {"A3\Sounds_F_EPC\CAS_02\Flaps_Down.wss","db-4",1.0,100};
		class scrubLandInt
		{
			sound[] = {"A3\Sounds_F\vehicles\air\noises\wheelsInt.wss","db0",1.0,100};
			frequency = 1;
			volume = "(scrubLand factor[0.01, 0.20])";
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[] = {"3AS\3as_arc170\Sounds\ARCLow.ogg",1.2,1.0,4000};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "camPos*2*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineHighOut
			{
				sound[] = {"3AS\3as_arc170\Sounds\ARC170.ogg",1.2,1.2,5000};
				frequency = "1";
				volume = "camPos*4*(rpm factor[0.5, 1.1])*(rpm factor[1.1, 0.5])";
			};
			class ForsageOut
			{
				sound[] = {"3AS\3as_arc170\Sounds\ARC170.ogg","db5",0.99,4200};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
				cone[] = {3.14,3.92,2.0,0.5};
			};
			class WindNoiseOut
			{
				sound[] = {"3AS\3as_arc170\Sounds\ARC170.ogg","db-5",1.0,800};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[] = {"3AS\3as_arc170\Sounds\FighterInt.ogg",0.8,1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*((rpm factor[0.7, 0.1])*(rpm factor[0.1, 0.7]))";
			};
			class EngineHighIn
			{
				sound[] = {"3AS\3as_arc170\Sounds\FighterInt.ogg",0.8,1.2};
				frequency = "1";
				volume = "(1-camPos)*(rpm factor[0.85, 1.0])";
			};
			class ForsageIn
			{
				sound[] = {"A3\Sounds_F\air\Plane_Fighter_03\Plane_Fighter_03-fors_int.wss","db0",1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.6, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[] = {"A3\Sounds_F\air\Plane_Fighter_03\noise.wss","db-6",1.0};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
		};
		class TextureSources
		{
			class Republic
			{
				displayName = "Republic";
				author = "$STR_3AS_Studio";
				textures[] = {"3as\3AS_ARC170\Data\Main_Frame_CO.paa","3as\3AS_ARC170\Data\Wings_Engines_CO.paa","3as\3AS_ARC170\Data\Guns_CO.paa"};
				factions[] = {"3AS_Rep"};
			};
			class Blue
			{
				displayName = "Blue";
				author = "$STR_3AS_Studio";
				textures[] = {"3as\3AS_ARC170\Data\units\501st_Main_Frame_CO.paa","3as\3AS_ARC170\Data\units\501st_Wings_Engines_CO.paa","3as\3AS_ARC170\Data\units\501st_Guns_CO.paa"};
				factions[] = {"3AS_Rep"};
			};
			class Green: Blue
			{
				displayName = "Green";
				textures[] = {"3as\3AS_ARC170\Data\units\101st_Main_Frame_CO.paa","3as\3AS_ARC170\Data\units\101st_Wings_Engines_CO.paa","3as\3AS_ARC170\Data\units\101st_Guns_CO.paa"};
			};
			class Orange: Blue
			{
				displayName = "Orange";
				textures[] = {"3as\3AS_ARC170\Data\units\212th_Main_Frame_CO.paa","3as\3AS_ARC170\Data\units\212th_Wings_Engines_CO.paa","3as\3AS_ARC170\Data\units\212th_Guns_CO.paa"};
			};
			class Yellow: Blue
			{
				displayName = "Yellow";
				textures[] = {"3as\3AS_ARC170\Data\units\327th_Main_Frame_CO.paa","3as\3AS_ARC170\Data\units\327th_Wings_Engines_CO.paa","3as\3AS_ARC170\Data\units\327th_Guns_CO.paa"};
			};
		};
		textureList[] = {"Republic",1,"Blue",0,"Green",0,"Orange",0,"Yellow",0};
	};
	class 42nd_Arc170: 3AS_ARC_170_base
	{
		author = "Houndacivic";
		displayName = "[42nd] ARC-170 "; 
		editorPreview = "";
		scope = 2;
		scopeCurator = 2;
		crew = "42nd_WO1_Pilot";
		side = 1;
		faction = "Fac42nd_AIR";
		editorSubcategory = "SUB42ndAir";
		hiddenselectionstextures[] = {"\42nd_para\42nd\addons\vehicles\42nd_ARC170\42nd_Main_Frame_CO.paa",
                "\42nd_para\42nd\addons\vehicles\42nd_ARC170\42nd_Wings_Engines_CO.paa",
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
	};
