#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDeathMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDeathMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::BoolProperty, bNoConsoleDeathMessages, 0x1)
		ADD_VAR(::StrProperty, SomeoneString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KilledString, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
