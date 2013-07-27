#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_NotNearOtherAI : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(float, DistanceToCheck, 72)
		bool NotNearOtherAI(class NavMeshGoal_GenericFilterContainer* FilterContainer, float InDistanceToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_NotNearOtherAI.NotNearOtherAI");
			byte params[12] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)&params[0] = FilterContainer;
			*(float*)&params[4] = InDistanceToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
