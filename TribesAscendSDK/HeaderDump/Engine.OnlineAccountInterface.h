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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21358);
			byte params[52] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			*(ScriptString**)&params[24] = EmailAddress;
			*(ScriptString**)&params[36] = ProductKey;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[48];
		}
		void OnCreateOnlineAccountCompleted(OnlineSubsystem::EOnlineAccountCreateStatus ErrorStatus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21364);
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineAccountCreateStatus*)params = ErrorStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21367);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCreateOnlineAccountCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* AccountCreateDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21369);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = AccountCreateDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreateLocalAccount(ScriptString* UserName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21371);
			byte params[28] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool RenameLocalAccount(ScriptString* NewUserName, ScriptString* OldUserName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21375);
			byte params[40] = { NULL };
			*(ScriptString**)params = NewUserName;
			*(ScriptString**)&params[12] = OldUserName;
			*(ScriptString**)&params[24] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		bool DeleteLocalAccount(ScriptString* UserName, ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21380);
			byte params[28] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool GetLocalAccountNames(ScriptArray<ScriptString*>& Accounts)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21384);
			byte params[16] = { NULL };
			*(ScriptArray<ScriptString*>*)params = Accounts;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Accounts = *(ScriptArray<ScriptString*>*)params;
			return *(bool*)&params[12];
		}
	};
}
