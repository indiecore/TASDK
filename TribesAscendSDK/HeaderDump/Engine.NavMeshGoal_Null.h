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
	class NavMeshGoal_Null : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(Object::Pointer, PartialGoal, 80)
		bool GoUntilBust(class NavigationHandle* NavHandle, int InMaxPathVisits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20975);
			byte params[12] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(int*)&params[4] = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void RecycleNative()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20980);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20981);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
