#pragma once
#include "Engine.ProcBuilding.h"
#include "Engine.ProcBuildingRuleset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuilding.PBScopeProcessInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty ProcBuilding.PBScopeProcessInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PBScopeProcessInfo
	{
	public:
		ADD_OBJECT(ProcBuilding, OwningBuilding)
		ADD_OBJECT(ProcBuildingRuleset, Ruleset)
		ADD_VAR(::NameProperty, RulesetVariation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGenerateLODPoly, 0x1)
		ADD_VAR(::BoolProperty, bPartOfNonRect, 0x2)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
