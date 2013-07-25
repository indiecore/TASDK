#pragma once
#include "UDKBase__UDKProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTProjectile : public UDKProjectile
	{
	public:
		ADD_VAR(::FloatProperty, GlobalCheckRadiusTweak, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TossZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DecalDissolveParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfDecal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalWidth, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ExplosionDecal)
		ADD_OBJECT(ParticleSystem, ProjExplosionTemplate)
		ADD_OBJECT(ParticleSystem, ProjFlightTemplate)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_OBJECT(SoundCue, AmbientSound)
		ADD_VAR(::BoolProperty, bAttachExplosionToVehicles, 0x40)
		ADD_VAR(::BoolProperty, bWaitForEffects, 0x20)
		ADD_VAR(::BoolProperty, bSuppressExplosionFX, 0x10)
		ADD_VAR(::BoolProperty, bAdvanceExplosionEffect, 0x8)
		ADD_VAR(::BoolProperty, m_bDestroyProjEffects, 0x4)
		ADD_VAR(::BoolProperty, bImportantAmbientSound, 0x2)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
