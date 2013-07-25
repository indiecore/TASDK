#pragma once
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.NavigationHandle.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshGoal_ClosestActorInList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_ClosestActorInList : public NavMeshPathGoalEvaluator
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CachedAnchorPoly'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'PolyToGoalActorMap'!
		class NavMeshGoal_ClosestActorInList* ClosestActorInList(class NavigationHandle* NavHandle, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& InGoalList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_ClosestActorInList.ClosestActorInList");
			byte* params = (byte*)malloc(20);
			*(class NavigationHandle**)params = NavHandle;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = InGoalList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InGoalList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(class NavMeshGoal_ClosestActorInList**)(params + 16);
			free(params);
			return returnVal;
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
