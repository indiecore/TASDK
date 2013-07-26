#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.InputKeyAction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InputKeyAction
	{
	public:
		ADD_VAR(::ByteProperty, InputKeyState, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InputKeyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
