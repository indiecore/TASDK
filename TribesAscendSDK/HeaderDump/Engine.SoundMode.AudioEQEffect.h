#pragma once
#include "Core.Object.Double.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SoundMode.AudioEQEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SoundMode.AudioEQEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AudioEQEffect
	{
	public:
		ADD_VAR(::FloatProperty, LFGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LFFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MFGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MFBandwidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MFCutoffFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HFGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HFFrequency, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, RootTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
