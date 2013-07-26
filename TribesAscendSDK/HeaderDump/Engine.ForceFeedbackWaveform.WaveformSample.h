#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ForceFeedbackWaveform.WaveformSample." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WaveformSample
	{
	public:
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RightFunction, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LeftFunction, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RightAmplitude, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LeftAmplitude, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
