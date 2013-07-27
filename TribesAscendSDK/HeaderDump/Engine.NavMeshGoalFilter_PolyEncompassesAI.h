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
	class NavMeshGoalFilter_PolyEncompassesAI : public NavMeshGoal_Filter
	{
	public:
		ADD_STRUCT(Object::Vector, OverrideExtentToCheck, 72)
		bool MakeSureAIFits(class NavMeshGoal_GenericFilterContainer* FilterContainer, Object::Vector InOverrideExtentToCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoalFilter_PolyEncompassesAI.MakeSureAIFits");
			byte params[20] = { NULL };
			*(class NavMeshGoal_GenericFilterContainer**)&params[0] = FilterContainer;
			*(Object::Vector*)&params[4] = InOverrideExtentToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_STRUCT
