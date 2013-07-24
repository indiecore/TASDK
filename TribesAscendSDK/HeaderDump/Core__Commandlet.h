#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.Commandlet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Commandlet : public Object
	{
	public:
		ADD_VAR(::BoolProperty, ShowErrorCount, 0x10)
		ADD_VAR(::BoolProperty, LogToConsole, 0x8)
		ADD_VAR(::BoolProperty, IsEditor, 0x4)
		ADD_VAR(::BoolProperty, IsClient, 0x2)
		ADD_VAR(::BoolProperty, IsServer, 0x1)
		ADD_VAR(::StrProperty, HelpWebLink, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpUsage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpDescription, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
