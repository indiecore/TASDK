#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_MinPathDistance : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(int, MinDistancePathShouldBe, 72)
		bool MustBeLongerPathThan(class NavMeshGoal_GenericFilterContainer* FilterContainer, int InMinDistancePathShouldBe)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20990);
			byte params[12] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(int*)&params[4] = InMinDistancePathShouldBe;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
