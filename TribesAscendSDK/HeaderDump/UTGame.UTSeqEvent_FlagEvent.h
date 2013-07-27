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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49208);
			byte params[12] = { NULL };
			*(ScriptName*)params = EventType;
			*(class Controller**)&params[8] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49215);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
