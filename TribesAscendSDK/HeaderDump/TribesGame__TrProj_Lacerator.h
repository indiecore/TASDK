#pragma once
#include "Engine__CameraAnim.h"
#include "TribesGame__TrProjectile.h"
#include "Engine__SoundCue.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_Lacerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_Lacerator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_Lacerator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_Lacerator : public TrProjectile
	{
	public:
		ADD_OBJECT(CameraAnim, ShortRangeKillAnim)
		ADD_VAR(::BoolProperty, bShrinking, 0x2)
		ADD_VAR(::BoolProperty, bCheckShortRangeKill, 0x1)
		ADD_OBJECT(SoundCue, HitPawnSound)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialSoundEffect' for the property named 'DefaultHitSound'!
		ADD_OBJECT(ParticleSystem, RockSmokeTemplate)
		ADD_OBJECT(ParticleSystem, BounceTemplate)
		ADD_VAR(::FloatProperty, ShrinkTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageAttenuation, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Bounces, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'SpawnFlightEffects'
		// Here lies the not-yet-implemented method 'InternalSpawnFlightEffects'
		// Here lies the not-yet-implemented method 'GetDamage'
		// Here lies the not-yet-implemented method 'GetMomentumTransfer'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'SpawnImpactEffect'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'StartToShrink'
		// Here lies the not-yet-implemented method 'MyOnParticleSystemFinished'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
