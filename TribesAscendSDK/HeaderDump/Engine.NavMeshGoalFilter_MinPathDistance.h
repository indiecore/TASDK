#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoalFilter_MinPathDistance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_MinPathDistance : public NavMeshGoal_Filter
	{
	public:
		ADD_VAR(::IntProperty, MinDistancePathShouldBe, 0xFFFFFFFF)
		bool MustBeLongerPathThan(class NavMeshGoal_GenericFilterContainer* FilterContainer, int InMinDistancePathShouldBe)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_MinPathDistance.MustBeLongerPathThan");
			byte* params = (byte*)malloc(12);
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(int*)(params + 4) = InMinDistancePathShouldBe;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
