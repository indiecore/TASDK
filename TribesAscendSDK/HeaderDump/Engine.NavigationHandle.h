#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.NavMeshPathConstraint.h"
#include "Core.Object.h"
#include "Engine.EngineTypes.h"
#include "Engine.NavMeshPathGoalEvaluator.h"
#include "Engine.Pylon.h"
#include "Engine.CoverLink.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class NavigationHandle : public Object
	{
	public:
		static const float LINECHECK_GRANULARITY;
		static const auto NUM_PATHFINDING_PARAMS = 9;
		class PolySegmentSpan
		{
		public:
			ADD_STRUCT(Object::Vector, P2, 16)
			ADD_STRUCT(Object::Vector, P1, 4)
			ADD_STRUCT(Object::Pointer, Poly, 0)
		};
		class NavMeshPathParams
		{
		public:
			ADD_STRUCT(float, MaxHoverDistance, 44)
			ADD_STRUCT(float, MinWalkableZ, 40)
			ADD_STRUCT(float, MaxDropHeight, 36)
			ADD_STRUCT(Object::Vector, SearchStart, 24)
			ADD_STRUCT(float, SearchLaneMultiplier, 20)
			ADD_STRUCT(Object::Vector, SearchExtent, 8)
			ADD_BOOL(bAbleToSearch, 4, 0x4)
			ADD_BOOL(bNeedsMantleValidityTest, 4, 0x2)
			ADD_BOOL(bCanMantle, 4, 0x1)
			ADD_STRUCT(Object::Pointer, Interface, 0)
		};
		class EdgePointer
		{
		public:
			ADD_STRUCT(Object::Pointer, Dummy, 0)
		};
		class PathStore
		{
		public:
			ADD_STRUCT(ScriptArray<NavigationHandle::EdgePointer>, EdgeList, 0)
		};
		ADD_STRUCT(float, LastPathFailTime, 208)
		ADD_STRUCT(EngineTypes::EPathFindingError, LastPathError, 204)
		ADD_STRUCT(NavigationHandle::NavMeshPathParams, CachedPathParams, 156)
		ADD_OBJECT(NavMeshPathGoalEvaluator, PathGoalList, 152)
		ADD_OBJECT(NavMeshPathConstraint, PathConstraintList, 148)
		ADD_BOOL(bUltraVerbosePathDebugging, 144, 0x8)
		ADD_BOOL(bDebugConstraintsAndGoalEvals, 144, 0x4)
		ADD_BOOL(bUseORforEvaluateGoal, 144, 0x2)
		ADD_BOOL(bSkipRouteCacheUpdates, 144, 0x1)
		ADD_STRUCT(Actor::BasedPosition, FinalDestination, 92)
		ADD_STRUCT(Object::Pointer, SubGoal_DestPoly, 88)
		ADD_STRUCT(Object::Pointer, CurrentEdge, 84)
		ADD_STRUCT(Object::Pointer, BestUnfinishedPathPoint, 80)
		ADD_STRUCT(NavigationHandle::PathStore, PathCache, 68)
		ADD_STRUCT(Object::Pointer, AnchorPoly, 64)
		ADD_OBJECT(Pylon, AnchorPylon, 60)
		void ClearConstraints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ClearConstraints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPathConstraint(class NavMeshPathConstraint* Constraint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.AddPathConstraint");
			byte params[4] = { NULL };
			*(class NavMeshPathConstraint**)&params[0] = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddGoalEvaluator(class NavMeshPathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.AddGoalEvaluator");
			byte params[4] = { NULL };
			*(class NavMeshPathGoalEvaluator**)&params[0] = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class NavMeshPathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CreatePathConstraint");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathConstraint**)&params[4];
		}
		class NavMeshPathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CreatePathGoalEvaluator");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavMeshPathGoalEvaluator**)&params[4];
		}
		int GetPathCacheLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetPathCacheLength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void PathCache_Empty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_Empty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector PathCache_GetGoalPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_GetGoalPoint");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void PathCache_RemoveIndex(int InIdx, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PathCache_RemoveIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = InIdx;
			*(int*)&params[4] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetBestUnfinishedPathPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetBestUnfinishedPathPoint");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		bool FindPylon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.FindPylon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class Pylon* GetPylonFromPos(Object::Vector Position)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetPylonFromPos");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Position;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pylon**)&params[12];
		}
		bool GetNextMoveLocation(Object::Vector& out_MoveDest, float ArrivalDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetNextMoveLocation");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = out_MoveDest;
			*(float*)&params[12] = ArrivalDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_MoveDest = *(Object::Vector*)&params[0];
			return *(bool*)&params[16];
		}
		bool SetFinalDestination(Object::Vector FinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.SetFinalDestination");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ComputeValidFinalDestination(Object::Vector& out_ComputedPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ComputeValidFinalDestination");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = out_ComputedPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ComputedPosition = *(Object::Vector*)&params[0];
			return *(bool*)&params[12];
		}
		bool FindPath(class Actor*& out_DestActor, int& out_DestItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.FindPath");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = out_DestActor;
			*(int*)&params[4] = out_DestItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DestActor = *(class Actor**)&params[0];
			out_DestItem = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool SuggestMovePreparation(Object::Vector& MovePt, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.SuggestMovePreparation");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = MovePt;
			*(class Controller**)&params[12] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MovePt = *(Object::Vector*)&params[0];
			return *(bool*)&params[16];
		}
		bool ObstacleLineCheck(Object::Vector Start, Object::Vector End, Object::Vector Extent, Object::Vector& out_HitLoc, Object::Vector& out_HitNorm)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ObstacleLineCheck");
			byte params[64] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			*(Object::Vector*)&params[24] = Extent;
			*(Object::Vector*)&params[36] = out_HitLoc;
			*(Object::Vector*)&params[48] = out_HitNorm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_HitLoc = *(Object::Vector*)&params[36];
			out_HitNorm = *(Object::Vector*)&params[48];
			return *(bool*)&params[60];
		}
		bool ObstaclePointCheck(Object::Vector Pt, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ObstaclePointCheck");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Pt;
			*(Object::Vector*)&params[12] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool LineCheck(Object::Vector Start, Object::Vector End, Object::Vector Extent, Object::Vector& out_HitLocation, Object::Vector& out_HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.LineCheck");
			byte params[64] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			*(Object::Vector*)&params[24] = Extent;
			*(Object::Vector*)&params[36] = out_HitLocation;
			*(Object::Vector*)&params[48] = out_HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_HitLocation = *(Object::Vector*)&params[36];
			out_HitNormal = *(Object::Vector*)&params[48];
			return *(bool*)&params[60];
		}
		bool PointCheck(Object::Vector Pt, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PointCheck");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Pt;
			*(Object::Vector*)&params[12] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool PointReachable(Object::Vector Point, Object::Vector OverrideStartPoint, bool bAllowHitsInEndCollisionBox)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PointReachable");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(Object::Vector*)&params[12] = OverrideStartPoint;
			*(bool*)&params[24] = bAllowHitsInEndCollisionBox;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ActorReachable(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ActorReachable");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DrawPathCache(Object::Vector DrawOffset, bool bPersistent, Object::Color DrawColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.DrawPathCache");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = DrawOffset;
			*(bool*)&params[12] = bPersistent;
			*(Object::Color*)&params[16] = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetCurrentEdgeDebugText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetCurrentEdgeDebugText");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ClearCurrentEdge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.ClearCurrentEdge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Pylon::ENavMeshEdgeType GetCurrentEdgeType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetCurrentEdgeType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Pylon::ENavMeshEdgeType*)&params[0];
		}
		void GetAllPolyCentersWithinBounds(Object::Vector pos, Object::Vector Extent, ScriptArray<Object::Vector>& out_PolyCtrs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetAllPolyCentersWithinBounds");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = pos;
			*(Object::Vector*)&params[12] = Extent;
			*(ScriptArray<Object::Vector>*)&params[24] = out_PolyCtrs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_PolyCtrs = *(ScriptArray<Object::Vector>*)&params[24];
		}
		void GetValidPositionsForBox(Object::Vector pos, float Radius, Object::Vector Extent, bool bMustBeReachableFromStartPos, ScriptArray<Object::Vector>& out_ValidPositions, int MaxPositions, float MinRadius, Object::Vector ValidBoxAroundStartPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetValidPositionsForBox");
			byte params[64] = { NULL };
			*(Object::Vector*)&params[0] = pos;
			*(float*)&params[12] = Radius;
			*(Object::Vector*)&params[16] = Extent;
			*(bool*)&params[28] = bMustBeReachableFromStartPos;
			*(ScriptArray<Object::Vector>*)&params[32] = out_ValidPositions;
			*(int*)&params[44] = MaxPositions;
			*(float*)&params[48] = MinRadius;
			*(Object::Vector*)&params[52] = ValidBoxAroundStartPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ValidPositions = *(ScriptArray<Object::Vector>*)&params[32];
		}
		void LimitPathCacheDistance(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.LimitPathCacheDistance");
			byte params[4] = { NULL };
			*(float*)&params[0] = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsAnchorInescapable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.IsAnchorInescapable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Vector GetFirstMoveLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetFirstMoveLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		float CalculatePathDistance(Object::Vector FinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.CalculatePathDistance");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = FinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		Object::Vector MoveToDesiredHeightAboveMesh(Object::Vector Point, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.MoveToDesiredHeightAboveMesh");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(float*)&params[12] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		bool PopulatePathfindingParamCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.PopulatePathfindingParamCache");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool GetAllCoverSlotsInRadius(Object::Vector FromLoc, float Radius, ScriptArray<CoverLink::CoverInfo>& out_CoverList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationHandle.GetAllCoverSlotsInRadius");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = FromLoc;
			*(float*)&params[12] = Radius;
			*(ScriptArray<CoverLink::CoverInfo>*)&params[16] = out_CoverList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CoverList = *(ScriptArray<CoverLink::CoverInfo>*)&params[16];
			return *(bool*)&params[28];
		}
	};
	const float NavigationHandle::LINECHECK_GRANULARITY = 768.f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
