#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Controller.h"
namespace UnrealScript
{
	class UTSeqEvent_FlagEvent : public SequenceEvent
	{
	public:
		void Trigger(ScriptName EventType, class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqEvent_FlagEvent.Trigger");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = EventType;
			*(class Controller**)(params + 8) = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqEvent_FlagEvent.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
