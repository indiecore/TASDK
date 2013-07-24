#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundMode : public Object
	{
	public:
		ADD_VAR(::FloatProperty, FadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialDelay, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.SoundMode.AudioEQEffect' for the property named 'EQSettings'!
		ADD_VAR(::BoolProperty, bApplyEQ, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
