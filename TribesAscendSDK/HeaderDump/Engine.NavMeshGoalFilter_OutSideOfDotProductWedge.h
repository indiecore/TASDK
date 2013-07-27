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
		ADD_STRUCT(Object::Vector, Rotation, 84)
		ADD_STRUCT(Object::Vector, Location, 72)
		bool OutsideOfDotProductWedge(class NavMeshGoal_GenericFilterContainer* FilterContainer, Object::Vector InLocation, Object::Rotator InRotation, float InEpsilon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_OutSideOfDotProductWedge.OutsideOfDotProductWedge");
			byte params[36] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)&params[0] = FilterContainer;
			*(Object::Vector*)&params[4] = InLocation;
			*(Object::Rotator*)&params[16] = InRotation;
			*(float*)&params[28] = InEpsilon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
	};
}
#undef ADD_STRUCT
