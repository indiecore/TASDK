#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetVectorComponents : public SequenceAction
	{
	public:
		ADD_STRUCT(float, Z, 252)
		ADD_STRUCT(float, Y, 248)
		ADD_STRUCT(float, X, 244)
		ADD_STRUCT(Vector, OutVector, 232)
	};
}
#undef ADD_STRUCT
