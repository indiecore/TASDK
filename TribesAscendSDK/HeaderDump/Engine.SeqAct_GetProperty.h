#pragma once
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_GetProperty : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptName, PropertyName, 232)
	};
}
#undef ADD_STRUCT
