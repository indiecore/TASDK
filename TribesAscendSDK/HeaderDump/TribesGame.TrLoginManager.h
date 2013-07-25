#pragma once
#include "GFxUI.GFxObject.h"
#include "Core.Object.h"
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
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Login(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password, bool bShouldRemember)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.Login");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			*(bool*)(params + 24) = bShouldRemember;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void OnUserLoginFailed(byte LocalUserNum, byte ErrorCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.OnUserLoginFailed");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			*(params + 1) = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RetryLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.RetryLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.Logout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SubmitPlayerName(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.SubmitPlayerName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoginWaitPopup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.LoginWaitPopup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrLoginManager.PopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
