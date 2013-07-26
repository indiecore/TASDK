#pragma once
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrPawn.FootstepParticleInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrPawn.FootstepParticleInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FootstepParticleInfo
	{
	public:
		ADD_OBJECT(ParticleSystem, FootParticle)
		ADD_VAR(::NameProperty, MaterialType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
