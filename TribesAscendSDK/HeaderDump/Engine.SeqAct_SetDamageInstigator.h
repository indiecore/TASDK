#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetDamageInstigator : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, DamageInstigator, 232)
	};
}
#undef ADD_OBJECT
