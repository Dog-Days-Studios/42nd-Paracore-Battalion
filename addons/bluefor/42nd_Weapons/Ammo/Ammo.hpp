class IDA_HE_LauncherGrenade;

class 42nd_Grapple_40mm_Ammo_Base: IDA_HE_LauncherGrenade
{
    author = "HoundaCivic";
    cartridge = "";
    model = "Indecisive_Armoury_Ammos\Data\40mm_Grenade\IDA_40mm_Grenade.p3d";
    hit = 0;
    indirectHit = 0;
    indirectHitRange = 0;
    dangerRadiusHit = 0;
    suppressionRadiusHit = 0;
    explosive = 0;
    cost = 1;
    explosionEffects = "";
    craterEffects = "";
    CraterWaterEffects = "";
    effectsSmoke = "";
    effectFly = "";
    effectFlare = "";
    SoundSetExplosion[] = {};
    multiSoundHit[] = {};
    submunitionAmmo = "";
    submunitionDirectionType = "";
    submunitionInitialOffset[] = {0,0,0};
    submunitionParentSpeedCoef = 0;
    triggerOnImpact = 0;
    deleteParentWhenTriggered = 0;
    timeToLive = 8;
    fuseDistance = 0;
    ace_frag_enabled = 0;
    Para42_isGrapple = 1;
    Para42_grappleMaxLength = 250;
    Para42_grappleLifetime = 600;
    Para42_grappleTraceDistance = 120;
    Para42_grappleTraverseMinDistance = 5;
    Para42_grappleTraverseMaxDistance = 120;
    Para42_grappleMode = "vertical";
};

class 42nd_Grapple_40mm_Ammo: 42nd_Grapple_40mm_Ammo_Base
{
    displayName = "[42nd] Grapple Round";
    timeToLive = 30;
    Para42_grappleTraceDistance = 700;
    Para42_grappleTraverseMaxDistance = 700;
    Para42_grappleMode = "universal";
};

class 42nd_Traversal_Grapple_40mm_Ammo: 42nd_Grapple_40mm_Ammo_Base
{
    displayName = "[42nd] Grapple Round";
    timeToLive = 30;
    Para42_grappleTraceDistance = 700;
    Para42_grappleTraverseMaxDistance = 700;
    Para42_grappleMode = "universal";
};

// =============================================
// ARC-170 Gunship Ammo (AC-130 calibrated)
// =============================================

// 105mm Laser Cannon ammo - matches AC-130 M102 105mm Howitzer
class ls_120mm_he_blue;
class 42nd_ARC170_Ammo_105mm_HE: ls_120mm_he_blue
{
    hit = 1100;
    indirectHit = 150;
    indirectHitRange = 9;
    caliber = 10;
    explosive = 1.0;
    dangerRadiusHit = 200;
    suppressionRadiusHit = 30;
    typicalSpeed = 494;
    timeToLive = 20;
    whistleDist = 1000;
    class CamShakeExplode
    {
        power = 2;
        duration = 1.1;
        frequency = 20;
        distance = 500;
    };
    class CamShakeHit
    {
        power = 30;
        duration = 0.62;
        frequency = 20;
        distance = 1;
    };
};

// 105mm AP round - matches AC-130 105mm SABOT
class ls_120mm_apfsds_blue;
class 42nd_ARC170_Ammo_105mm_AP: ls_120mm_apfsds_blue
{
    hit = 1300;
    indirectHit = 100;
    indirectHitRange = 8;
    caliber = 18;
    explosive = 0.8;
    typicalSpeed = 494;
    timeToLive = 20;
    class CamShakeExplode
    {
        power = 2;
        duration = 1.1;
        frequency = 20;
        distance = 500;
    };
    class CamShakeHit
    {
        power = 30;
        duration = 0.62;
        frequency = 20;
        distance = 1;
    };
};

// 40mm Laser Bofors ammo - matches AC-130 L60 40mm HE
class ls_40mm_he_blue;
class 42nd_ARC170_Ammo_40mm_HE: ls_40mm_he_blue
{
    hit = 200;
    indirectHit = 75;
    indirectHitRange = 2.5;
    explosive = 1.0;
    deflecting = 1;
    typicalSpeed = 500;
    timeToLive = 20;
    caliber = 4;
    class CamShakeExplode
    {
        power = 0.5;
        duration = 1.1;
        frequency = 20;
        distance = 400;
    };
    class CamShakeHit
    {
        power = 20;
        duration = 0.4;
        frequency = 20;
        distance = 1;
    };
};

// 40mm AP round - matches AC-130 40mm SABOT
class 42nd_ARC170_Ammo_40mm_AP: ls_40mm_he_blue
{
    hit = 350;
    indirectHit = 50;
    indirectHitRange = 1.5;
    explosive = 0.5;
    deflecting = 1;
    typicalSpeed = 500;
    timeToLive = 20;
    caliber = 6;
    allowAgainstInfantry = 1;
    class CamShakeExplode
    {
        power = 0.5;
        duration = 1.1;
        frequency = 20;
        distance = 400;
    };
    class CamShakeHit
    {
        power = 20;
        duration = 0.4;
        frequency = 20;
        distance = 1;
    };
};

// 25mm Minigun ammo - matches AC-130 GAU-12 25mm HEI
class ls_127x99_blue;
class 42nd_ARC170_Ammo_25mm_HEI: ls_127x99_blue
{
    hit = 60;
    indirectHit = 30;
    indirectHitRange = 1.5;
    caliber = 3;
    explosive = 1.0;
    visibleFire = 32;
    audibleFire = 32;
    visibleFireTime = 4;
    typicalSpeed = 600;
    timeToLive = 20;
    airFriction = -0.0003;
    class CamShakeExplode
    {
        power = 0.5;
        duration = 0.4;
        frequency = 20;
        distance = 50;
    };
    class CamShakeFire
    {
        power = 10.35;
        duration = 1;
        frequency = 35;
        distance = 5;
    };
};
