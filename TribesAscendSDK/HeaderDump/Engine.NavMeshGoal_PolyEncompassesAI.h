#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Core.Object.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_PolyEncompassesAI : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(Vector, OverrideExtentToCheck, 80)
		bool MakeSureAIFits(class NavigationHandle* NavHandle, Vector InOverrideExtentToCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20983);
			byte params[20] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(Vector*)&params[4] = InOverrideExtentToCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20988);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
