#pragma once
#include "Engine__SequenceEvent.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqEvent_GameEnded." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqEvent_GameEnded : public SequenceEvent
	{
	public:
		ADD_OBJECT(Actor, ActualWinner)
		ADD_OBJECT(Actor, Winner)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqEvent_GameEnded.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqEvent_GameEnded.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
