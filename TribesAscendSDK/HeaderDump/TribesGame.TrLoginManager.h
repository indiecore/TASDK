#pragma once
#include "GFxUI.GFxObject.h"
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrLoginManager : public Object
	{
	public:
		ADD_BOOL(bRemember, 60, 0x1)
		ADD_STRUCT(ScriptString*, LoginName, 64)
		ADD_STRUCT(ScriptString*, LoginPassword, 76)
		ADD_BOOL(bWaitingForLoginWaitPopup, 60, 0x2)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98659);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Login(ScriptString* UserName, ScriptString* Password, bool bShouldRemember)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98660);
			byte params[32] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			*(bool*)&params[24] = bShouldRemember;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void OnUserLoginFailed(byte LocalUserNum, OnlineSubsystem::EOnlineServerConnectionStatus ErrorCode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98665);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[1] = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RetryLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98669);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logout()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98670);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SubmitPlayerName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98671);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoginWaitPopup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98673);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98674);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
