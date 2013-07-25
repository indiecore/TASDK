#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoal_At." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_At." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_At : public NavMeshPathGoalEvaluator
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'PartialGoal'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'GoalPoly'!
		ADD_VAR(::BoolProperty, bKeepPartial, 0x1)
		ADD_VAR(::FloatProperty, GoalDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Goal, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
