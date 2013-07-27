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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17575);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17578);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SerializeHeader()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17579);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RegisterHandler(class GameplayEventsHandler* NewHandler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17581);
			byte params[4] = { NULL };
			*(class GameplayEventsHandler**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnregisterHandler(class GameplayEventsHandler* ExistingHandler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17584);
			byte params[4] = { NULL };
			*(class GameplayEventsHandler**)params = ExistingHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessStreamStart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17587);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17588);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessStreamEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17589);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetSessionID()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17590);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		int GetTitleID()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17592);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetPlatform()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17594);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* GetSessionTimestamp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17596);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		float GetSessionStart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17598);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetSessionEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17600);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetSessionDuration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17602);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_STRUCT
