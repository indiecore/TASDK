#pragma once
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.MaterialImpactEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKPawn.MaterialImpactEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialImpactEffect
	{
	public:
		ADD_OBJECT(ParticleSystem, ParticleTemplate)
		ADD_VAR(::FloatProperty, DecalHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalWidth, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DecalDissolveParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfDecal, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, Sound)
		ADD_VAR(::NameProperty, MaterialType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
