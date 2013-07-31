#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ModifyObjectList : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(int, ListEntriesCount, 232)
	};
}
#undef ADD_STRUCT
