#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AccessControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AccessControl : public Info
	{
	public:
		ADD_VAR(::BoolProperty, bDontAddDefaultAdmin, 0x1)
		ADD_VAR(::StrProperty, ACDescText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ACDisplayText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GamePassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AdminPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IdleKickReason, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultKickReason, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KickedMsg, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SessionBanned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NeedPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WrongPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IPBanned, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
