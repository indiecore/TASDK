#pragma once
#include "Engine__SequenceCondition.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqCond_IsCarryingFlag." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqCond_IsCarryingFlag : public SequenceCondition
	{
	public:
		ADD_OBJECT(UTGameObjective, FlagBase)
		ADD_OBJECT(Actor, Target)
		// Here lies the not-yet-implemented method 'Activated'
	};
}
#undef ADD_OBJECT
