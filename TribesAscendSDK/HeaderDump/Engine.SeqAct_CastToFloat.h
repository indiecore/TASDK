#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_CastToFloat : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(float, FloatResult, 236)
		ADD_STRUCT(int, Value, 232)
	};
}
#undef ADD_STRUCT
