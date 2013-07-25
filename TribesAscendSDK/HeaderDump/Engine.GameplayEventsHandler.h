#pragma once
#include "Engine.GameplayEventsReader.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameplayEventsHandler." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsHandler : public Object
	{
	public:
		ADD_OBJECT(GameplayEventsReader, Reader)
		void SetReader(class GameplayEventsReader* NewReader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.SetReader");
			byte* params = (byte*)malloc(4);
			*(class GameplayEventsReader**)params = NewReader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = EventID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveFilter(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.RemoveFilter");
			byte* params = (byte*)malloc(4);
			*(int*)params = EventID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsEventFiltered(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsHandler.IsEventFiltered");
			byte* params = (byte*)malloc(8);
			*(int*)params = EventID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
