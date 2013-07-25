#pragma once
#include "Engine__NavMeshGoal_Filter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoalFilter_OutSideOfDotProductWedge." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_OutSideOfDotProductWedge : public NavMeshGoal_Filter
	{
	public:
		ADD_VAR(::FloatProperty, Epsilon, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Rotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
