#pragma once
#include "Core__Object.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrLoginManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrLoginManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bRemember, 0x1)
		ADD_VAR(::StrProperty, LoginName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoginPassword, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForLoginWaitPopup, 0x2)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'OnUserLoginFailed'
		// Here lies the not-yet-implemented method 'RetryLogin'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'SubmitPlayerName'
		// Here lies the not-yet-implemented method 'LoginWaitPopup'
		// Here lies the not-yet-implemented method 'PopupData'
	};
}
#undef ADD_VAR
