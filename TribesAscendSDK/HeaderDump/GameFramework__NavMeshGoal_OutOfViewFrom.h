#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.NavMeshGoal_OutOfViewFrom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.NavMeshGoal_OutOfViewFrom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_OutOfViewFrom : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_VAR(::BoolProperty, bShowDebug, 0x1)
		ADD_STRUCT(::VectorProperty, OutOfViewLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'GoalPoly'!
		// Here lies the not-yet-implemented method 'RecycleNative'
		// Here lies the not-yet-implemented method 'MustBeHiddenFromThisPoint'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
