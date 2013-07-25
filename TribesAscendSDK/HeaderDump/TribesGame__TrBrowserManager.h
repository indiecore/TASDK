#pragma once
#include "Core__Object.h"
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
		// Here lies the not-yet-implemented method 'OpenURL'
		// Here lies the not-yet-implemented method 'OpenVideo'
		// Here lies the not-yet-implemented method 'GetLanguageString'
		// Here lies the not-yet-implemented method 'Alert'
		// Here lies the not-yet-implemented method 'Gold'
		// Here lies the not-yet-implemented method 'Store'
		// Here lies the not-yet-implemented method 'Booster'
		// Here lies the not-yet-implemented method 'Support'
		// Here lies the not-yet-implemented method 'Profile'
		// Here lies the not-yet-implemented method 'ActivateKey'
		// Here lies the not-yet-implemented method 'RecoverPassword'
		// Here lies the not-yet-implemented method 'RecoverUsername'
		// Here lies the not-yet-implemented method 'ClassVideo'
		// Here lies the not-yet-implemented method 'CreateAccount'
		// Here lies the not-yet-implemented method 'GetLangParam'
	};
}
#undef ADD_VAR
