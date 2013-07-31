#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_OutSideOfDotProductWedge : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(float, Epsilon, 96)
		ADD_STRUCT(Vector, Rotation, 84)
		ADD_STRUCT(Vector, Location, 72)
		bool OutsideOfDotProductWedge(class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InLocation, Rotator InRotation, float InEpsilon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21011);
			byte params[36] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(Vector*)&params[4] = InLocation;
			*(Rotator*)&params[16] = InRotation;
			*(float*)&params[28] = InEpsilon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
	};
}
#undef ADD_STRUCT
