#pragma once
#include "Engine.SequenceCondition.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Actor.h"
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
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqCond_IsCarryingFlag.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
