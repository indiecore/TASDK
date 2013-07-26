#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUDKFrontEnd_FilterDialog.Option." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Option
	{
	public:
		ADD_VAR(::StrProperty, OptionLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OptionName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
