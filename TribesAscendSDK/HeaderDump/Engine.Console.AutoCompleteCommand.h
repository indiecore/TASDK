#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Console.AutoCompleteCommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AutoCompleteCommand
	{
	public:
		ADD_VAR(::StrProperty, Desc, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Command, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
