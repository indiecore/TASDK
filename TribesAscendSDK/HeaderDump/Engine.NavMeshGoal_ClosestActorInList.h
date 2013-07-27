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
	class NavMeshGoal_ClosestActorInList : public NavMeshPathGoalEvaluator
	{
	public:
		ADD_STRUCT(ScriptArray<NavMeshPathGoalEvaluator::BiasedGoalActor>, GoalList, 80)
		ADD_STRUCT(Object::Pointer, CachedAnchorPoly, 152)
		ADD_STRUCT(Object::MultiMap_Mirror, PolyToGoalActorMap, 92)
		class NavMeshGoal_ClosestActorInList* ClosestActorInList(class NavigationHandle* NavHandle, ScriptArray<NavMeshPathGoalEvaluator::BiasedGoalActor>& InGoalList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_ClosestActorInList.ClosestActorInList");
			byte params[20] = { NULL };
			*(class NavigationHandle**)&params[0] = NavHandle;
			*(ScriptArray<NavMeshPathGoalEvaluator::BiasedGoalActor>*)&params[4] = InGoalList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InGoalList = *(ScriptArray<NavMeshPathGoalEvaluator::BiasedGoalActor>*)&params[4];
			return *(class NavMeshGoal_ClosestActorInList**)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_ClosestActorInList.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RecycleInternal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_ClosestActorInList.RecycleInternal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
