#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Login." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Login : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, CreateAccountLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpPasswordLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpUsernameLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CheckboxLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PasswordLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UsernameLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BetaKeyLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AccountLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SubmitLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpLabel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
