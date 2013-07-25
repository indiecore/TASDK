#pragma once
#include "Engine__NavMeshGoal_Filter.h"
#include "Engine__NavMeshGoal_GenericFilterContainer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoalFilter_NotNearOtherAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_NotNearOtherAI : public NavMeshGoal_Filter
	{
	public:
		ADD_VAR(::FloatProperty, DistanceToCheck, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'NotNearOtherAI'
	};
}
#undef ADD_VAR
