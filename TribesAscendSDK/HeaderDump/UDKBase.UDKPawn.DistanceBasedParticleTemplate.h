#pragma once
#include "Engine.ParticleSystem.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.DistanceBasedParticleTemplate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKPawn.DistanceBasedParticleTemplate." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DistanceBasedParticleTemplate
	{
	public:
		ADD_VAR(::FloatProperty, MinDistance, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, Template)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
