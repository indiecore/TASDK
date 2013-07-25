#pragma once
#include "Engine__SequenceCondition.h"
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
	};
}
#undef ADD_OBJECT
