#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Engine.ProcBuildingRuleset.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeRepeat : public PBRuleNodeBase
	{
	public:
		ADD_STRUCT(float, RepeatMaxSize, 108)
		ADD_STRUCT(ProcBuildingRuleset::EProcBuildingAxis, RepeatAxis, 104)
	};
}
#undef ADD_STRUCT
