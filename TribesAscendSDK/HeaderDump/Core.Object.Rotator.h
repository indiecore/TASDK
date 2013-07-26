#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Rotator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Rotator
	{
	public:
		ADD_VAR(::IntProperty, Pitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Yaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Roll, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
