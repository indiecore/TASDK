#pragma once
#include "Engine.SequenceCondition.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqCond_Increment : public SequenceCondition
	{
	public:
		ADD_STRUCT(int, ValueB, 216)
		ADD_STRUCT(int, ValueA, 212)
		ADD_STRUCT(int, IncrementAmount, 208)
	};
}
#undef ADD_STRUCT
