#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.NavMeshPathGoalEvaluatorCacheDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty WorldInfo.NavMeshPathGoalEvaluatorCacheDatum." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPathGoalEvaluatorCacheDatum
	{
	public:
		ADD_VAR(::IntProperty, ListIdx, 0xFFFFFFFF)
		ADD_OBJECT(NavMeshPathGoalEvaluator, List)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
