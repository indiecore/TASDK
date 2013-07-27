#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlineAccountInterface : public Interface
	{
	public:
		bool CreateOnlineAccount(ScriptString* UserName, ScriptString* Password, ScriptString* EmailAddress, ScriptString* ProductKey)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.CreateOnlineAccount");
			byte params[52] = { NULL };
			*(ScriptString**)&params[0] = UserName;
			*(ScriptString**)&params[12] = Password;
			*(ScriptString**)&params[24] = EmailAddress;
			*(ScriptString**)&params[36] = ProductKey;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[48];
		}
		void OnCreateOnlineAccountCompleted(OnlineSubsystem::EOnlineAccountCreateStatus ErrorStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.OnCreateOnlineAccountCompleted");
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineAccountCreateStatus*)&params[0] = ErrorStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.AddCreateOnlineAccountCompletedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.ClearCreateOnlineAccountCompletedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreateLocalAccount(ScriptString* UserName, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.CreateLocalAccount");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = UserName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool RenameLocalAccount(ScriptString* NewUserName, ScriptString* OldUserName, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.RenameLocalAccount");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = NewUserName;
			*(ScriptString**)&params[12] = OldUserName;
			*(ScriptString**)&params[24] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		bool DeleteLocalAccount(ScriptString* UserName, ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.DeleteLocalAccount");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = UserName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool GetLocalAccountNames(ScriptArray<ScriptString*>& Accounts)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineAccountInterface.GetLocalAccountNames");
			byte params[16] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = Accounts;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Accounts = *(ScriptArray<ScriptString*>*)&params[0];
			return *(bool*)&params[12];
		}
	};
}
