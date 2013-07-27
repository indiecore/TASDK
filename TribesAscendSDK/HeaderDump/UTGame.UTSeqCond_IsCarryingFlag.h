#pragma once
#include "Engine.SequenceCondition.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqCond_IsCarryingFlag : public SequenceCondition
	{
	public:
		ADD_OBJECT(UTGameObjective, FlagBase, 212)
		ADD_OBJECT(Actor, Target, 208)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqCond_IsCarryingFlag.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
