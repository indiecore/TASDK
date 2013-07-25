#pragma once
#include "Engine__SequenceEvent.h"
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
	};
}
#undef ADD_OBJECT
