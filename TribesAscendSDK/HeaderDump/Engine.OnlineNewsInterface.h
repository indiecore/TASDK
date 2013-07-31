#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlineNewsInterface : public Interface
	{
	public:
		bool ReadNews(byte LocalUserNum, OnlineSubsystem::EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21865);
			byte params[6] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnReadNewsCompleted(bool bWasSuccessful, OnlineSubsystem::EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21869);
			byte params[5] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(OnlineSubsystem::EOnlineNewsType*)&params[4] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21873);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21875);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetNews(byte LocalUserNum, OnlineSubsystem::EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21877);
			byte params[14] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
