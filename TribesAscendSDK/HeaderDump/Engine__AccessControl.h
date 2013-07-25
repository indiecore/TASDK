#pragma once
#include "Engine__Info.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AccessControl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AccessControl." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
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
		ADD_OBJECT(ScriptClass, AdminClass)
		ADD_VAR(::StrProperty, IdleKickReason, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultKickReason, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KickedMsg, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SessionBanned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NeedPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, WrongPassword, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IPBanned, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsAdmin'
		// Here lies the not-yet-implemented method 'SetAdminPassword'
		// Here lies the not-yet-implemented method 'SetGamePassword'
		// Here lies the not-yet-implemented method 'RequiresPassword'
		// Here lies the not-yet-implemented method 'GetControllerFromString'
		// Here lies the not-yet-implemented method 'Kick'
		// Here lies the not-yet-implemented method 'KickBan'
		// Here lies the not-yet-implemented method 'ForceKickPlayer'
		// Here lies the not-yet-implemented method 'KickPlayer'
		// Here lies the not-yet-implemented method 'AdminLogin'
		// Here lies the not-yet-implemented method 'AdminLogout'
		// Here lies the not-yet-implemented method 'AdminEntered'
		// Here lies the not-yet-implemented method 'AdminExited'
		// Here lies the not-yet-implemented method 'ParseAdminOptions'
		// Here lies the not-yet-implemented method 'ValidLogin'
		// Here lies the not-yet-implemented method 'PreLogin'
		// Here lies the not-yet-implemented method 'CheckIPPolicy'
		// Here lies the not-yet-implemented method 'IsIDBanned'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
