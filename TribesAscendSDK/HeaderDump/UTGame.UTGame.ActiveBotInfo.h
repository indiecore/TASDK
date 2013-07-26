#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.ActiveBotInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ActiveBotInfo
	{
	public:
		ADD_VAR(::BoolProperty, bInUse, 0x1)
		ADD_VAR(::StrProperty, BotName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
