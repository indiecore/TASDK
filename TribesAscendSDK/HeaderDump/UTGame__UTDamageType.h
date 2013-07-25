#pragma once
#include "UTGame__UTGib.h"
#include "Engine__Pawn.h"
#include "Engine__DamageType.h"
#include "Engine__CameraAnim.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__ParticleSystem.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTPawn.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDamageType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTDamageType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDamageType." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDamageType : public DamageType
	{
	public:
		ADD_OBJECT(CameraAnim, DamageCameraAnim)
		ADD_VAR(::BoolProperty, bLocationalHit, 0x2)
		ADD_OBJECT(ScriptClass, DamageWeaponClass)
		ADD_VAR(::BoolProperty, bDirectDamage, 0x10)
		ADD_VAR(::BoolProperty, bHeadGibCamera, 0x40000)
		ADD_VAR(::FloatProperty, GibPerterbation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseDamageBasedDeathEffects, 0x2000)
		ADD_VAR(::NameProperty, DeathAnim, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimateHipsForDeathAnim, 0x8000)
		ADD_VAR(::FloatProperty, DeathAnimRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSeversHead, 0x20)
		ADD_VAR(::FloatProperty, MotorDecayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StopAnimAfterDamageInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageOverlayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XRayEffectTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DamageBodyMatColor'!
		ADD_VAR(::BoolProperty, bCausesBloodSplatterDecals, 0x80000)
		ADD_VAR(::BoolProperty, bCausesBlood, 0x1)
		ADD_VAR(::FloatProperty, PhysicsTakeHitMomentumThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSpecialDeathCamera, 0x4000)
		ADD_VAR(::BoolProperty, bThrowRagdoll, 0x100)
		ADD_VAR(::BoolProperty, bOverrideHitEffectColor, 0x20000)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'HitEffectColor'!
		ADD_VAR(::StrProperty, MaleSuicide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FemaleSuicide, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeathString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomTauntIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RewardEvent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RewardAnnouncementSwitch, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, RewardAnnouncementClass)
		ADD_VAR(::IntProperty, RewardCount, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SuicideStatsName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DeathStatsName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, KillStatsName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NodeDamageScaling, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DeathCameraEffectInstigator)
		ADD_OBJECT(ScriptClass, DeathCameraEffectVictim)
		ADD_OBJECT(ParticleSystem, GibTrail)
		ADD_VAR(::IntProperty, DamageWeaponFireMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AlwaysGibDamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinAccumulateDamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GibThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDontHurtInstigator, 0x100000)
		ADD_VAR(::BoolProperty, bComplainFriendlyFire, 0x10000)
		ADD_VAR(::BoolProperty, bSelfDestructDamage, 0x1000)
		ADD_VAR(::BoolProperty, bVehicleHit, 0x800)
		ADD_VAR(::BoolProperty, bBulletHit, 0x400)
		ADD_VAR(::BoolProperty, bLeaveBodyEffect, 0x200)
		ADD_VAR(::BoolProperty, bUseTearOffMomentum, 0x80)
		ADD_VAR(::BoolProperty, bCauseConvulsions, 0x40)
		ADD_VAR(::BoolProperty, bNeverGibs, 0x8)
		ADD_VAR(::BoolProperty, bAlwaysGibs, 0x4)
		ADD_VAR(::FloatProperty, DeathOverlayTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetDeathCameraEffectInstigator'
		// Here lies the not-yet-implemented method 'GetHitEffectDuration'
		// Here lies the not-yet-implemented method 'ShouldGib'
		// Here lies the not-yet-implemented method 'GetDeathCameraEffectVictim'
		// Here lies the not-yet-implemented method 'DeathMessage'
		// Here lies the not-yet-implemented method 'SuicideMessage'
		// Here lies the not-yet-implemented method 'SpawnHitEffect'
		// Here lies the not-yet-implemented method 'IncrementKills'
		// Here lies the not-yet-implemented method 'IncrementDeaths'
		// Here lies the not-yet-implemented method 'IncrementSuicides'
		// Here lies the not-yet-implemented method 'GetStatsName'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'PawnTornOff'
		// Here lies the not-yet-implemented method 'SpawnGibEffects'
		// Here lies the not-yet-implemented method 'DoCustomDamageEffects'
		// Here lies the not-yet-implemented method 'CreateDeathSkeleton'
		// Here lies the not-yet-implemented method 'BoneBreaker'
		// Here lies the not-yet-implemented method 'CreateDeathGoreChunks'
		// Here lies the not-yet-implemented method 'SpawnExtraGibEffects'
		// Here lies the not-yet-implemented method 'DrawKillIcon'
		// Here lies the not-yet-implemented method 'CalcDeathCamera'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
