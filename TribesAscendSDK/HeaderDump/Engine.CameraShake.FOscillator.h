#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CameraShake.FOscillator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FOscillator
	{
	public:
		ADD_VAR(::FloatProperty, Amplitude, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InitialOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
