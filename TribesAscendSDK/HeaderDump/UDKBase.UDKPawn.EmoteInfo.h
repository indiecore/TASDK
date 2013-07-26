#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKPawn.EmoteInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EmoteInfo
	{
	public:
		ADD_VAR(::BoolProperty, bRequiresPlayer, 0x1)
		ADD_VAR(::NameProperty, Command, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTopHalfEmote, 0x2)
		ADD_VAR(::BoolProperty, bVictoryEmote, 0x1)
		ADD_VAR(::NameProperty, EmoteAnim, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EmoteName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EmoteTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CategoryName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
