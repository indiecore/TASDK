#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class OnlineNewsInterface : public Interface
	{
	public:
		bool ReadNews(byte LocalUserNum, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.ReadNews");
			byte* params = (byte*)malloc(6);
			*params = LocalUserNum;
			*(params + 1) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnReadNewsCompleted(bool bWasSuccessful, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.OnReadNewsCompleted");
			byte* params = (byte*)malloc(5);
			*(bool*)params = bWasSuccessful;
			*(params + 4) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.AddReadNewsCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadNewsCompletedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadNewsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.ClearReadNewsCompletedDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadNewsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetNews(byte LocalUserNum, byte NewsType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineNewsInterface.GetNews");
			byte* params = (byte*)malloc(14);
			*params = LocalUserNum;
			*(params + 1) = NewsType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
