#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.RawInputKeyEventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RawInputKeyEventData
	{
	public:
		ADD_VAR(::ByteProperty, ModifierKeyFlags, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InputKeyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
