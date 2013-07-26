#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Info.h"
#include "Engine.Controller.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
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
		bool IsAdmin(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.IsAdmin");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetAdminPassword(ScriptArray<wchar_t> P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.SetAdminPassword");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetGamePassword(ScriptArray<wchar_t> P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.SetGamePassword");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RequiresPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.RequiresPassword");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Controller* GetControllerFromString(ScriptArray<wchar_t> Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.GetControllerFromString");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 12);
			free(params);
			return returnVal;
		}
		void Kick(ScriptArray<wchar_t> Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.Kick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KickBan(ScriptArray<wchar_t> Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.KickBan");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ForceKickPlayer(class PlayerController* C, ScriptArray<wchar_t> KickReason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.ForceKickPlayer");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = C;
			*(ScriptArray<wchar_t>*)(params + 4) = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool KickPlayer(class PlayerController* C, ScriptArray<wchar_t> KickReason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.KickPlayer");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = C;
			*(ScriptArray<wchar_t>*)(params + 4) = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool AdminLogin(class PlayerController* P, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.AdminLogin");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = P;
			*(ScriptArray<wchar_t>*)(params + 4) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool AdminLogout(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.AdminLogout");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AdminEntered(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.AdminEntered");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminExited(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.AdminExited");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ParseAdminOptions(ScriptArray<wchar_t> Options)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.ParseAdminOptions");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Options;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ValidLogin(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.ValidLogin");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void PreLogin(ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Address, ScriptArray<wchar_t>& OutError, bool bSpectator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.PreLogin");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = Address;
			*(ScriptArray<wchar_t>*)(params + 24) = OutError;
			*(bool*)(params + 36) = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
		}
		bool CheckIPPolicy(ScriptArray<wchar_t> Address)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.CheckIPPolicy");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Address;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsIDBanned(UniqueNetId& NetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AccessControl.IsIDBanned");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = NetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NetId = *(UniqueNetId*)params;
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
