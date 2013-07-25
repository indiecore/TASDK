#pragma once
#include "Engine__PBRuleNodeBase.h"
#include "Engine__ProcBuildingRuleset.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PBRuleNodeSubRuleset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PBRuleNodeSubRuleset : public PBRuleNodeBase
	{
	public:
		ADD_OBJECT(ProcBuildingRuleset, SubRuleset)
	};
}
#undef ADD_OBJECT
