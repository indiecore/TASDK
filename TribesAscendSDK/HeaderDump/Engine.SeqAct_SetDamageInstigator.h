#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetDamageInstigator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetDamageInstigator : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, DamageInstigator)
	};
}
#undef ADD_OBJECT
