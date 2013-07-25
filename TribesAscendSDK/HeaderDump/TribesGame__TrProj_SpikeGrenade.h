#pragma once
#include "Engine__ParticleSystem.h"
#include "TribesGame__TrProj_Grenade.h"
#include "Engine__SoundCue.h"
#include "Engine__SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_SpikeGrenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProj_SpikeGrenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_SpikeGrenade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_SpikeGrenade : public TrProj_Grenade
	{
	public:
		ADD_OBJECT(SoundCue, m_FractalExplosionSound)
		ADD_OBJECT(ParticleSystem, m_FractalBeamTemplate)
		ADD_OBJECT(ParticleSystem, m_FractalExplosionTemplate)
		ADD_VAR(::FloatProperty, m_fFractalDamageRadius, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nFractalDamage, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vFlashExplosionLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vAscentLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fZFractalShotDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalShotDistance, 0xFFFFFFFF)
		ADD_OBJECT(SkelControlSingleBone, m_AscendControl)
		ADD_STRUCT(::VectorProperty, m_CachedHitNormal, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fAscentHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAscentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFractalTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingFractalTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bStartedFractal, 0x1)
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'InitProjectile'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'ClientReceivedExplosionLocation'
		// Here lies the not-yet-implemented method 'IsFractalActive'
		// Here lies the not-yet-implemented method 'StartFractalShots'
		// Here lies the not-yet-implemented method 'ShootFractalShot'
		// Here lies the not-yet-implemented method 'SpawnFractalExplosionEffects'
		// Here lies the not-yet-implemented method 'EndFractal'
		// Here lies the not-yet-implemented method 'SpawnExplosionEffects'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
