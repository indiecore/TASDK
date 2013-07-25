#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ForceFeedbackWaveform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ForceFeedbackWaveform : public Object
	{
	public:
		ADD_VAR(::FloatProperty, MaxWaveformDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaveformFalloffStartDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLooping, 0x1)
	};
}
#undef ADD_VAR
