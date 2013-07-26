#pragma once
#include "Engine.NavMeshGoal_GenericFilterContainer.h"
#include "Engine.NavMeshGoal_Filter.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
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
		ADD_STRUCT(::VectorProperty, OutOfViewLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, GoalPoly, 0xFFFFFFFF)
		bool MustBeHiddenFromThisPoint(class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InOutOfViewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_OutOfViewFrom.MustBeHiddenFromThisPoint");
			byte* params = (byte*)malloc(20);
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(Vector*)(params + 4) = InOutOfViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
