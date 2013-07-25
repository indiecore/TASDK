#pragma once
#include "TribesGame__TrProjectile.h"
#include "TribesGame__TrCollisionProxy.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#include "Engine__PhysicsVolume.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Grenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Grenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Grenade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Grenade : public TrProjectile
	{
	public:
		ADD_VAR(::BoolProperty, m_bStuckOnPlayer, 0x1)
		ADD_VAR(::FloatProperty, m_fProxyDetonationHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProxyDetonationRadius, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_CollisionProxyClass)
		ADD_OBJECT(TrCollisionProxy, m_CollisionProxy)
		ADD_VAR(::FloatProperty, m_fStuckMomentumMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStuckDamageMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_OverloadHitNormal, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, m_StuckOnPawnLoopingSound)
		ADD_OBJECT(ParticleSystem, m_StuckOnTargetTemplate)
		ADD_VAR(::FloatProperty, m_fExplosionTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSpawnProxyOnInit, 0x80)
		ADD_VAR(::BoolProperty, m_bScanProxyOnInit, 0x40)
		ADD_VAR(::BoolProperty, m_bFullyInheritVelocity, 0x20)
		ADD_VAR(::BoolProperty, m_bDoRandSpin, 0x10)
		ADD_VAR(::BoolProperty, m_bBounceRequiredForExplode, 0x8)
		ADD_VAR(::BoolProperty, m_bExplodeOnTouchEvent, 0x4)
		ADD_VAR(::BoolProperty, m_bTimedExplosion, 0x2)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'SpawnCollisionProxy'
		// Here lies the not-yet-implemented method 'DestroyCollisionProxy'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'ApplyInheritance'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'PhysicsVolumeChange'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'StickToTarget'
		// Here lies the not-yet-implemented method 'PlayStuckOnEffects'
		// Here lies the not-yet-implemented method 'MyOnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'PawnEnteredDetonationArea'
		// Here lies the not-yet-implemented method 'PawnLeftDetonationArea'
		// Here lies the not-yet-implemented method 'NativeExplode'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
