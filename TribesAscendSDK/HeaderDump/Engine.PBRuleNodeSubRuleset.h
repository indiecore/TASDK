#pragma once
#include "Engine.PBRuleNodeBase.h"
#include "Engine.ProcBuildingRuleset.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PBRuleNodeSubRuleset : public PBRuleNodeBase
	{
	public:
		ADD_OBJECT(ProcBuildingRuleset, SubRuleset, 104)
	};
}
#undef ADD_OBJECT
