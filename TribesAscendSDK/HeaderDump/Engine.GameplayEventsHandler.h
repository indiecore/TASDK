#pragma once
#include "Engine.GameplayEventsReader.h"
#include "Core.Object.h"
#include "Engine.GameplayEvents.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsHandler : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<int>, EventIDFilter, 60)
		ADD_STRUCT(ScriptArray<GameplayEvents::GameStatGroup>, GroupFilter, 72)
		ADD_OBJECT(GameplayEventsReader, Reader, 84)
		void SetReader(class GameplayEventsReader* NewReader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.SetReader");
			byte params[4] = { NULL };
			*(class GameplayEventsReader**)&params[0] = NewReader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.PreProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostProcessStream()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.PostProcessStream");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResolveGroupFilters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.ResolveGroupFilters");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFilter(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.AddFilter");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFilter(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.RemoveFilter");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsEventFiltered(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.IsEventFiltered");
			byte params[8] = { NULL };
			*(int*)&params[0] = EventID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
