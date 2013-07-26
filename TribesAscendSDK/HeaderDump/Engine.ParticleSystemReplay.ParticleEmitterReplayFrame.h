#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleSystemReplay.ParticleEmitterReplayFrame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ParticleSystemReplay.ParticleEmitterReplayFrame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEmitterReplayFrame
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FrameState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OriginalEmitterIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EmitterType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
