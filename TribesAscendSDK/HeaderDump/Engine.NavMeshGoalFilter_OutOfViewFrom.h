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
	class NavMeshGoalFilter_OutOfViewFrom : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(Object::Vector, OutOfViewLocation, 76)
		ADD_STRUCT(Object::Pointer, GoalPoly, 72)
		bool MustBeHiddenFromThisPoint(class NavMeshGoal_GenericFilterContainer* FilterContainer, Object::Vector InOutOfViewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_OutOfViewFrom.MustBeHiddenFromThisPoint");
			byte params[20] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)&params[0] = FilterContainer;
			*(Object::Vector*)&params[4] = InOutOfViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
