#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrBrowserManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrBrowserManager : public Object
	{
	public:
		ADD_VAR(::StrProperty, URLCreateSteamAccount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRecoverUsername, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRecoverPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLCreateAccount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLActivateKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLClassVideo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLRedirect, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLProfile, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLSupport, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLBooster, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLStore, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLAlert, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, URLGold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
