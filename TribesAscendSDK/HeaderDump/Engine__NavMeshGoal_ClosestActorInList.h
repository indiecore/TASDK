#pragma once
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__NavigationHandle.h"
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
		// Here lies the not-yet-implemented method 'ClosestActorInList'
		// Here lies the not-yet-implemented method 'Recycle'
		// Here lies the not-yet-implemented method 'RecycleInternal'
	};
}
#undef ADD_STRUCT
