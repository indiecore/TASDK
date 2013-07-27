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
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = EventType;
			*(class Controller**)&params[8] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqEvent_FlagEvent.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
