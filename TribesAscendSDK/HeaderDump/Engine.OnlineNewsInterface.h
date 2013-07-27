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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.ReadNews");
			byte params[6] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnReadNewsCompleted(bool bWasSuccessful, OnlineSubsystem::EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.OnReadNewsCompleted");
			byte params[5] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			*(OnlineSubsystem::EOnlineNewsType*)&params[4] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.AddReadNewsCompletedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.ClearReadNewsCompletedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetNews(byte LocalUserNum, OnlineSubsystem::EOnlineNewsType NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.GetNews");
			byte params[14] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineNewsType*)&params[1] = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
