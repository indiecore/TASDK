#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.NavMeshGoal_Filter.h"
#include "Engine.NavigationHandle.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshGoal_GenericFilterContainer : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(ScriptArray<class NavMeshGoal_Filter*>, GoalFilters, 80)
		ADD_OBJECT(NavigationHandle, MyNavigationHandle, 96)
		ADD_STRUCT(Object::Pointer, SuccessfulGoal, 92)
		class NavMeshGoal_GenericFilterContainer* CreateAndAddFilterToNavHandle(class NavigationHandle* NavHandle, int InMaxPathVisits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20963);
			byte params[12] = { NULL };
			*(class NavigationHandle**)params = NavHandle;
			*(int*)&params[4] = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshGoal_GenericFilterContainer**)&params[8];
		}
		class NavMeshGoal_Filter* GetFilterOfType(ScriptClass* Filter_Class)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20968);
			byte params[8] = { NULL };
			*(ScriptClass**)params = Filter_Class;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshGoal_Filter**)&params[4];
		}
		Vector GetGoalPoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20971);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20973);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
