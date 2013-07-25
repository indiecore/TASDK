#pragma once
#include "Engine.GameplayEvents.h"
#include "Engine.GameplayEventsHandler.h"
namespace UnrealScript
{
	class GameplayEventsReader : public GameplayEvents
	{
	public:
		bool OpenStatsFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.OpenStatsFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SerializeHeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.SerializeHeader");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RegisterHandler(class GameplayEventsHandler* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.RegisterHandler");
			byte* params = (byte*)malloc(4);
			*(class GameplayEventsHandler**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnregisterHandler(class GameplayEventsHandler* ExistingHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.UnregisterHandler");
			byte* params = (byte*)malloc(4);
			*(class GameplayEventsHandler**)params = ExistingHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessStreamStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.ProcessStreamStart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.ProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessStreamEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.ProcessStreamEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetSessionID()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionID");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		int GetTitleID()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetTitleID");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetPlatform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetPlatform");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSessionTimestamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionTimestamp");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		float GetSessionStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionStart");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetSessionEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionEnd");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetSessionDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionDuration");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
