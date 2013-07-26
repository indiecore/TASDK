#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerController.InputEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InputEntry
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeDelta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Action, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
