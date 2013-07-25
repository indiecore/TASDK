#pragma once
#include "UTGame__UTProjectile.h"
#include "Engine__Controller.h"
#include "TribesGame__TrDevice.h"
#include "Engine__Actor.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProjectile : public UTProjectile
	{
	public:
		ADD_VAR(::BoolProperty, m_bTether, 0x40)
		ADD_VAR(::BoolProperty, m_bSimulateAutonomousProjectiles, 0x80)
		ADD_VAR(::ByteProperty, m_SpawnedEquipPoint, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nTetherId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsBullet, 0x100)
		ADD_STRUCT(::VectorProperty, r_vSpawnLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fInstigatorExtraZMomentum, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, SpawnedFromDevice)
		ADD_VAR(::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinLifespan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxLifespan, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vAccelDirection, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fClientSimulatedSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTweenSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentTetherTweenAmount, 0xFFFFFFFF)
		ADD_OBJECT(TrProjectile, c_ChildTetheredProjectile)
		ADD_OBJECT(TrProjectile, c_ParentTetheredProjectile)
		ADD_VAR(::FloatProperty, m_fInstigatorMomentumTransferMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAmbientSoundFadeOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAmbientSoundFadeIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDirectHitMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxProjInheritPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProjInheritVelocityPctZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProjInheritVelocityPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fXYDamageRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAuthoritativeExploding, 0x20)
		ADD_VAR(::BoolProperty, m_bOrientToWall, 0x10)
		ADD_VAR(::BoolProperty, m_bHasBounced, 0x8)
		ADD_VAR(::BoolProperty, m_bFastProjectile, 0x4)
		ADD_VAR(::BoolProperty, m_bDebugProjectileRadius, 0x2)
		ADD_VAR(::BoolProperty, m_bLimitXYDamageCheck, 0x1)
		ADD_OBJECT(ScriptClass, m_SpawnedDeployableClass)
		// Here lies the not-yet-implemented method 'IsBlockedByBlocker'
		// Here lies the not-yet-implemented method 'OrientToSlope'
		// Here lies the not-yet-implemented method 'CalculateHitLocation'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'ExplodeFromTimeLimit'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ClientReceivedProjectileToTether'
		// Here lies the not-yet-implemented method 'CreateProjectileLight'
		// Here lies the not-yet-implemented method 'DetonateObsolete'
		// Here lies the not-yet-implemented method 'DestroyOldestOverLimit'
		// Here lies the not-yet-implemented method 'GetMaxDeployedLimit'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'ApplyInheritance'
		// Here lies the not-yet-implemented method 'ClientCheckFastSpawnExplode'
		// Here lies the not-yet-implemented method 'SpawnExplosionEffects'
		// Here lies the not-yet-implemented method 'GetExplosionSound'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'Bounce'
		// Here lies the not-yet-implemented method 'ProjectileHurtRadius'
		// Here lies the not-yet-implemented method 'HurtRadius_Internal'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'ProcessTouch'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
