#pragma once
#include "Core__Object.h"
#include "Engine__NavMeshPathGoalEvaluator.h"
#include "Engine__Actor.h"
#include "Engine__NavMeshPathConstraint.h"
#include "Engine__Pylon.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavigationHandle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavigationHandle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavigationHandle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavigationHandle : public Object
	{
	public:
		ADD_VAR(::FloatProperty, LastPathFailTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LastPathError, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationHandle.NavMeshPathParams' for the property named 'CachedPathParams'!
		ADD_OBJECT(NavMeshPathGoalEvaluator, PathGoalList)
		ADD_OBJECT(NavMeshPathConstraint, PathConstraintList)
		ADD_VAR(::BoolProperty, bUltraVerbosePathDebugging, 0x8)
		ADD_VAR(::BoolProperty, bDebugConstraintsAndGoalEvals, 0x4)
		ADD_VAR(::BoolProperty, bUseORforEvaluateGoal, 0x2)
		ADD_VAR(::BoolProperty, bSkipRouteCacheUpdates, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'FinalDestination'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SubGoal_DestPoly'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CurrentEdge'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BestUnfinishedPathPoint'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationHandle.PathStore' for the property named 'PathCache'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'AnchorPoly'!
		ADD_OBJECT(Pylon, AnchorPylon)
		// Here lies the not-yet-implemented method 'ClearConstraints'
		// Here lies the not-yet-implemented method 'AddPathConstraint'
		// Here lies the not-yet-implemented method 'AddGoalEvaluator'
		// Here lies the not-yet-implemented method 'CreatePathConstraint'
		// Here lies the not-yet-implemented method 'CreatePathGoalEvaluator'
		// Here lies the not-yet-implemented method 'GetPathCacheLength'
		// Here lies the not-yet-implemented method 'PathCache_Empty'
		// Here lies the not-yet-implemented method 'PathCache_GetGoalPoint'
		// Here lies the not-yet-implemented method 'PathCache_RemoveIndex'
		// Here lies the not-yet-implemented method 'GetBestUnfinishedPathPoint'
		// Here lies the not-yet-implemented method 'FindPylon'
		// Here lies the not-yet-implemented method 'GetPylonFromPos'
		// Here lies the not-yet-implemented method 'GetNextMoveLocation'
		// Here lies the not-yet-implemented method 'SetFinalDestination'
		// Here lies the not-yet-implemented method 'ComputeValidFinalDestination'
		// Here lies the not-yet-implemented method 'FindPath'
		// Here lies the not-yet-implemented method 'SuggestMovePreparation'
		// Here lies the not-yet-implemented method 'ObstacleLineCheck'
		// Here lies the not-yet-implemented method 'ObstaclePointCheck'
		// Here lies the not-yet-implemented method 'LineCheck'
		// Here lies the not-yet-implemented method 'PointCheck'
		// Here lies the not-yet-implemented method 'PointReachable'
		// Here lies the not-yet-implemented method 'ActorReachable'
		// Here lies the not-yet-implemented method 'DrawPathCache'
		// Here lies the not-yet-implemented method 'GetCurrentEdgeDebugText'
		// Here lies the not-yet-implemented method 'ClearCurrentEdge'
		// Here lies the not-yet-implemented method 'GetCurrentEdgeType'
		// Here lies the not-yet-implemented method 'GetAllPolyCentersWithinBounds'
		// Here lies the not-yet-implemented method 'GetValidPositionsForBox'
		// Here lies the not-yet-implemented method 'LimitPathCacheDistance'
		// Here lies the not-yet-implemented method 'IsAnchorInescapable'
		// Here lies the not-yet-implemented method 'GetFirstMoveLocation'
		// Here lies the not-yet-implemented method 'CalculatePathDistance'
		// Here lies the not-yet-implemented method 'MoveToDesiredHeightAboveMesh'
		// Here lies the not-yet-implemented method 'PopulatePathfindingParamCache'
		// Here lies the not-yet-implemented method 'GetAllCoverSlotsInRadius'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
