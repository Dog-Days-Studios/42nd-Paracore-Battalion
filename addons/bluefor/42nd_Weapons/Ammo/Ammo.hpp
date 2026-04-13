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
