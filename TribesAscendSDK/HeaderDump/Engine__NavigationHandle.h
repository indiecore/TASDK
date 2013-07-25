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
		void ClearConstraints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ClearConstraints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPathConstraint(class NavMeshPathConstraint* Constraint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.AddPathConstraint");
			byte* params = (byte*)malloc(4);
			*(class NavMeshPathConstraint**)params = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddGoalEvaluator(class NavMeshPathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.AddGoalEvaluator");
			byte* params = (byte*)malloc(4);
			*(class NavMeshPathGoalEvaluator**)params = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class NavMeshPathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CreatePathConstraint");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshPathConstraint**)(params + 4);
			free(params);
			return returnVal;
		}
		class NavMeshPathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CreatePathGoalEvaluator");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavMeshPathGoalEvaluator**)(params + 4);
			free(params);
			return returnVal;
		}
		int GetPathCacheLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetPathCacheLength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void PathCache_Empty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_Empty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector PathCache_GetGoalPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_GetGoalPoint");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void PathCache_RemoveIndex(int InIdx, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_RemoveIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = InIdx;
			*(int*)(params + 4) = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetBestUnfinishedPathPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetBestUnfinishedPathPoint");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		bool FindPylon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.FindPylon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Pylon* GetPylonFromPos(Vector Position)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetPylonFromPos");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Position;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pylon**)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetNextMoveLocation(Vector& out_MoveDest, float ArrivalDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetNextMoveLocation");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = out_MoveDest;
			*(float*)(params + 12) = ArrivalDistance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_MoveDest = *(Vector*)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool SetFinalDestination(Vector FinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.SetFinalDestination");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ComputeValidFinalDestination(Vector& out_ComputedPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ComputeValidFinalDestination");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = out_ComputedPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ComputedPosition = *(Vector*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool FindPath(class Actor*& out_DestActor, int& out_DestItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.FindPath");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = out_DestActor;
			*(int*)(params + 4) = out_DestItem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_DestActor = *(class Actor**)params;
			out_DestItem = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SuggestMovePreparation(Vector& MovePt, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.SuggestMovePreparation");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = MovePt;
			*(class Controller**)(params + 12) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MovePt = *(Vector*)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool ObstacleLineCheck(Vector Start, Vector End, Vector Extent, Vector& out_HitLoc, Vector& out_HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ObstacleLineCheck");
			byte* params = (byte*)malloc(64);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			*(Vector*)(params + 24) = Extent;
			*(Vector*)(params + 36) = out_HitLoc;
			*(Vector*)(params + 48) = out_HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_HitLoc = *(Vector*)(params + 36);
			out_HitNorm = *(Vector*)(params + 48);
			auto returnVal = *(bool*)(params + 60);
			free(params);
			return returnVal;
		}
		bool ObstaclePointCheck(Vector Pt, Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ObstaclePointCheck");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Pt;
			*(Vector*)(params + 12) = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool LineCheck(Vector Start, Vector End, Vector Extent, Vector& out_HitLocation, Vector& out_HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.LineCheck");
			byte* params = (byte*)malloc(64);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			*(Vector*)(params + 24) = Extent;
			*(Vector*)(params + 36) = out_HitLocation;
			*(Vector*)(params + 48) = out_HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_HitLocation = *(Vector*)(params + 36);
			out_HitNormal = *(Vector*)(params + 48);
			auto returnVal = *(bool*)(params + 60);
			free(params);
			return returnVal;
		}
		bool PointCheck(Vector Pt, Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PointCheck");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Pt;
			*(Vector*)(params + 12) = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool PointReachable(Vector Point, Vector OverrideStartPoint, bool bAllowHitsInEndCollisionBox)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PointReachable");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = Point;
			*(Vector*)(params + 12) = OverrideStartPoint;
			*(bool*)(params + 24) = bAllowHitsInEndCollisionBox;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool ActorReachable(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ActorReachable");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DrawPathCache(Vector DrawOffset, bool bPersistent, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* DrawColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.DrawPathCache");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = DrawOffset;
			*(bool*)(params + 12) = bPersistent;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 16) = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetCurrentEdgeDebugText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetCurrentEdgeDebugText");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ClearCurrentEdge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ClearCurrentEdge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetCurrentEdgeType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetCurrentEdgeType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void GetAllPolyCentersWithinBounds(Vector pos, Vector Extent, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_PolyCtrs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetAllPolyCentersWithinBounds");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = pos;
			*(Vector*)(params + 12) = Extent;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24) = out_PolyCtrs;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_PolyCtrs = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24);
			free(params);
		}
		void GetValidPositionsForBox(Vector pos, float Radius, Vector Extent, bool bMustBeReachableFromStartPos, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_ValidPositions, int MaxPositions, float MinRadius, Vector ValidBoxAroundStartPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetValidPositionsForBox");
			byte* params = (byte*)malloc(64);
			*(Vector*)params = pos;
			*(float*)(params + 12) = Radius;
			*(Vector*)(params + 16) = Extent;
			*(bool*)(params + 28) = bMustBeReachableFromStartPos;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 32) = out_ValidPositions;
			*(int*)(params + 44) = MaxPositions;
			*(float*)(params + 48) = MinRadius;
			*(Vector*)(params + 52) = ValidBoxAroundStartPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ValidPositions = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 32);
			free(params);
		}
		void LimitPathCacheDistance(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.LimitPathCacheDistance");
			byte* params = (byte*)malloc(4);
			*(float*)params = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsAnchorInescapable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.IsAnchorInescapable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector GetFirstMoveLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetFirstMoveLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		float CalculatePathDistance(Vector FinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CalculatePathDistance");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		Vector MoveToDesiredHeightAboveMesh(Vector Point, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.MoveToDesiredHeightAboveMesh");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Point;
			*(float*)(params + 12) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		bool PopulatePathfindingParamCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PopulatePathfindingParamCache");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool GetAllCoverSlotsInRadius(Vector FromLoc, float Radius, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_CoverList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetAllCoverSlotsInRadius");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = FromLoc;
			*(float*)(params + 12) = Radius;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = out_CoverList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CoverList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
