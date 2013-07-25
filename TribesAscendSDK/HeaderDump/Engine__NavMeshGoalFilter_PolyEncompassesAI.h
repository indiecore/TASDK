#pragma once
#include "Engine__NavMeshGoal_Filter.h"
#include "Engine__NavMeshGoal_GenericFilterContainer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoalFilter_PolyEncompassesAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_PolyEncompassesAI : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(::VectorProperty, OverrideExtentToCheck, 0xFFFFFFFF)
		bool MakeSureAIFits(class NavMeshGoal_GenericFilterContainer* FilterContainer, Vector InOverrideExtentToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_PolyEncompassesAI.MakeSureAIFits");
			byte* params = (byte*)malloc(20);
			*(class NavMeshGoal_GenericFilterContainer**)params = FilterContainer;
			*(Vector*)(params + 4) = InOverrideExtentToCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
