#pragma once
#include "Core.Object.Map_Mirror.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemComponent.ParticleEmitterInstanceMotionBlurInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEmitterInstanceMotionBlurInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Map_Mirror>, ParticleMBInfoMap, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
