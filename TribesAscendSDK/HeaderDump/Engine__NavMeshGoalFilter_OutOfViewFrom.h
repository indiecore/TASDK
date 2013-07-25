#pragma once
#include "Engine__NavMeshGoal_Filter.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoalFilter_OutOfViewFrom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_OutOfViewFrom : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(::VectorProperty, OutOfViewLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'GoalPoly'!
	};
}
#undef ADD_STRUCT
