#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Input.KeyBind." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KeyBind
	{
	public:
		ADD_VAR(::BoolProperty, bIgnoreAlt, 0x20)
		ADD_VAR(::BoolProperty, bIgnoreShift, 0x10)
		ADD_VAR(::BoolProperty, bIgnoreCtrl, 0x8)
		ADD_VAR(::BoolProperty, Alt, 0x4)
		ADD_VAR(::BoolProperty, Shift, 0x2)
		ADD_VAR(::BoolProperty, Control, 0x1)
		ADD_VAR(::StrProperty, Command, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Name, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
