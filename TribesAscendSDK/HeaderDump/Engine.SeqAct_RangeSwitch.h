#pragma once
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_RangeSwitch : public SequenceAction
	{
	public:
		struct SwitchRange
		{
		public:
			ADD_STRUCT(int, Max, 4)
			ADD_STRUCT(int, Min, 0)
		};
		ADD_STRUCT(ScriptArray<SeqAct_RangeSwitch::SwitchRange>, Ranges, 232)
	};
}
#undef ADD_STRUCT
