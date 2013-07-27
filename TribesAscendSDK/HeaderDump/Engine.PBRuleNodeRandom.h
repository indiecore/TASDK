#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeRandom : public PBRuleNodeBase
	{
	public:
		ADD_STRUCT(int, MaxNumExecuted, 112)
		ADD_STRUCT(int, MinNumExecuted, 108)
		ADD_STRUCT(int, NumOutputs, 104)
	};
}
#undef ADD_STRUCT
