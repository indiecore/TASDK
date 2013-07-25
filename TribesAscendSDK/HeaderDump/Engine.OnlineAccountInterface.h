#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class OnlineAccountInterface : public Interface
	{
	public:
		bool CreateOnlineAccount(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password, ScriptArray<wchar_t> EmailAddress, ScriptArray<wchar_t> ProductKey)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.CreateOnlineAccount");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			*(ScriptArray<wchar_t>*)(params + 24) = EmailAddress;
			*(ScriptArray<wchar_t>*)(params + 36) = ProductKey;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 48);
			free(params);
			return returnVal;
		}
		void OnCreateOnlineAccountCompleted(byte ErrorStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.OnCreateOnlineAccountCompleted");
			byte* params = (byte*)malloc(1);
			*params = ErrorStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.AddCreateOnlineAccountCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.ClearCreateOnlineAccountCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CreateLocalAccount(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.CreateLocalAccount");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool RenameLocalAccount(ScriptArray<wchar_t> NewUserName, ScriptArray<wchar_t> OldUserName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.RenameLocalAccount");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = NewUserName;
			*(ScriptArray<wchar_t>*)(params + 12) = OldUserName;
			*(ScriptArray<wchar_t>*)(params + 24) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		bool DeleteLocalAccount(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.DeleteLocalAccount");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GetLocalAccountNames(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Accounts)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.GetLocalAccountNames");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Accounts;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Accounts = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
