#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AudioDevice.AudioClassInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AudioClassInfo
	{
	public:
		ADD_VAR(::IntProperty, SizeRealTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumRealTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeResident, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumResident, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
