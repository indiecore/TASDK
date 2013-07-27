#pragma once
#include "Engine.GameplayEvents.h"
#include "Engine.GameplayEventsHandler.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameplayEventsReader : public GameplayEvents
	{
	public:
		ADD_STRUCT(ScriptArray<class GameplayEventsHandler*>, RegisteredHandlers, 336)
		bool OpenStatsFile(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.OpenStatsFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SerializeHeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.SerializeHeader");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RegisterHandler(class GameplayEventsHandler* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.RegisterHandler");
			byte params[4] = { NULL };
			*(class GameplayEventsHandler**)&params[0] = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnregisterHandler(class GameplayEventsHandler* ExistingHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.UnregisterHandler");
			byte params[4] = { NULL };
			*(class GameplayEventsHandler**)&params[0] = ExistingHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		ScriptString* GetSessionID()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionID");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		int GetTitleID()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetTitleID");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetPlatform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetPlatform");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptString* GetSessionTimestamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionTimestamp");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		float GetSessionStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionStart");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetSessionEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionEnd");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetSessionDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsReader.GetSessionDuration");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
	};
}
#undef ADD_STRUCT
