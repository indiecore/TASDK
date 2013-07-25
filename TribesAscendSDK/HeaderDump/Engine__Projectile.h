#pragma once
#include "Engine__Actor.h"
#include "Engine__Controller.h"
#include "Engine__SoundCue.h"
#include "Engine__FluidSurfaceActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Projectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Projectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Projectile : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, NetCullDistanceSquared, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ImpactedActor)
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(SoundCue, ImpactSound)
		ADD_OBJECT(SoundCue, SpawnSound)
		ADD_OBJECT(ScriptClass, MyDamageType)
		ADD_VAR(::FloatProperty, MomentumTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Damage, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ZeroCollider)
		ADD_VAR(::BoolProperty, bRotationFollowsVelocity, 0x8)
		ADD_VAR(::BoolProperty, bBegunPlay, 0x4)
		ADD_VAR(::BoolProperty, bBlockedByInstigator, 0x2)
		ADD_VAR(::BoolProperty, bSwitchToZeroCollision, 0x1)
		ADD_VAR(::FloatProperty, MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Speed, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'EncroachingOn'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'GetTeamNum'
		// Here lies the not-yet-implemented method 'CanSplash'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ProjectileHurtRadius'
		// Here lies the not-yet-implemented method 'HurtRadius'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'RandSpin'
		// Here lies the not-yet-implemented method 'IsStationary'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'GetTimeToLocation'
		// Here lies the not-yet-implemented method 'StaticGetTimeToLocation'
		// Here lies the not-yet-implemented method 'GetRange'
		// Here lies the not-yet-implemented method 'ApplyFluidSurfaceImpact'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
