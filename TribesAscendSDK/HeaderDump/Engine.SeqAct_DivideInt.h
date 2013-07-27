#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_DivideInt : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(int, IntResult, 244)
		ADD_STRUCT(float, FloatResult, 240)
		ADD_STRUCT(int, ValueB, 236)
		ADD_STRUCT(int, ValueA, 232)
	};
}
#undef ADD_STRUCT
