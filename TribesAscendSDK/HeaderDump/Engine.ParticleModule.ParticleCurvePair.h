#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModule.ParticleCurvePair." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty ParticleModule.ParticleCurvePair." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleCurvePair
	{
	public:
		ADD_OBJECT(Object, CurveObject)
		ADD_VAR(::StrProperty, CurveName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
