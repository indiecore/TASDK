#pragma once
#include "Engine.DroppedPickup.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ReachSpec.h"
#include "Engine.Pawn.h"
#include "Engine.SeqAct_Toggle.h"
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
	class NavigationPoint : public Actor
	{
	public:
		static const auto INFINITE_PATH_COST = 10000000;
		struct DebugNavCost
		{
		public:
			ADD_STRUCT(int, Cost, 12)
			ADD_STRUCT(ScriptString*, Desc, 0)
		};
		struct NavigationOctreeObject
		{
		public:
			ADD_STRUCT(byte, OwnerType, 48)
			ADD_OBJECT(Object, Owner, 44)
			ADD_STRUCT(Object::Pointer, OctreeNode, 40)
			ADD_STRUCT(Vector, BoxCenter, 28)
			ADD_STRUCT(Object::Box, BoundingBox, 0)
		};
		struct CheckpointRecord
		{
		public:
			ADD_BOOL(bBlocked, 0, 0x2)
			ADD_BOOL(bDisabled, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<class ReachSpec*>, PathList, 532)
		ADD_STRUCT(ScriptArray<Actor::ActorReference>, EditorProscribedPaths, 544)
		ADD_STRUCT(ScriptArray<Actor::ActorReference>, EditorForcedPaths, 556)
		ADD_STRUCT(ScriptArray<Actor::ActorReference>, Volumes, 568)
		ADD_STRUCT(ScriptArray<NavigationPoint::DebugNavCost>, CostArray, 620)
		ADD_STRUCT(float, LastAnchoredPawnTime, 688)
		ADD_OBJECT(Pawn, AnchoredPawn, 684)
		ADD_STRUCT(int, NetworkID, 680)
		ADD_STRUCT(Object::Guid, NavGuid, 656)
		ADD_STRUCT(Object::Cylinder, MaxPathSize, 648)
		ADD_STRUCT(float, LastDetourWeight, 640)
		ADD_STRUCT(float, InventoryDist, 636)
		ADD_OBJECT(DroppedPickup, InventoryCache, 632)
		ADD_STRUCT(int, FearCost, 616)
		ADD_STRUCT(int, TransientCost, 612)
		ADD_STRUCT(int, ExtraCost, 608)
		ADD_STRUCT(int, Cost, 604)
		ADD_OBJECT(NavigationPoint, previousPath, 600)
		ADD_OBJECT(NavigationPoint, prevOrdered, 596)
		ADD_OBJECT(NavigationPoint, nextOrdered, 592)
		ADD_OBJECT(NavigationPoint, nextNavigationPoint, 588)
		ADD_STRUCT(int, bestPathWeight, 584)
		ADD_STRUCT(int, visitedWeight, 580)
		ADD_STRUCT(NavigationPoint::NavigationOctreeObject, NavOctreeObject, 480)
		ADD_BOOL(bShouldSaveForCheckpoint, 476, 0x40000000)
		ADD_BOOL(bHasCrossLevelPaths, 476, 0x20000000)
		ADD_BOOL(bPreferredVehiclePath, 476, 0x10000000)
		ADD_BOOL(bBlockedForVehicles, 476, 0x8000000)
		ADD_BOOL(bBuildLongPaths, 476, 0x4000000)
		ADD_BOOL(bCanWalkOnToReach, 476, 0x2000000)
		ADD_BOOL(bMustTouchToReach, 476, 0x1000000)
		ADD_BOOL(bMakeSourceOnly, 476, 0x800000)
		ADD_BOOL(bVehicleDestination, 476, 0x400000)
		ADD_BOOL(bAlreadyVisited, 476, 0x200000)
		ADD_BOOL(bMayCausePain, 476, 0x100000)
		ADD_BOOL(bFlyingPreferred, 476, 0x80000)
		ADD_BOOL(bBlockable, 476, 0x40000)
		ADD_BOOL(bMustBeReachable, 476, 0x20000)
		ADD_BOOL(bSpecialForced, 476, 0x10000)
		ADD_BOOL(bSourceOnly, 476, 0x8000)
		ADD_BOOL(bDestinationOnly, 476, 0x4000)
		ADD_BOOL(bPathsChanged, 476, 0x2000)
		ADD_BOOL(bNotBased, 476, 0x1000)
		ADD_BOOL(bNoAutoConnect, 476, 0x800)
		ADD_BOOL(bSpecialMove, 476, 0x400)
		ADD_BOOL(bAutoBuilt, 476, 0x200)
		ADD_BOOL(bForceNoStrafing, 476, 0x100)
		ADD_BOOL(bAlwaysUseStrafing, 476, 0x80)
		ADD_BOOL(bNeverUseStrafing, 476, 0x40)
		ADD_BOOL(bOneWayPath, 476, 0x20)
		ADD_BOOL(bBlocked, 476, 0x10)
		ADD_BOOL(bCanReach, 476, 0x8)
		ADD_BOOL(bHideEditorPaths, 476, 0x4)
		ADD_BOOL(bTransientEndPoint, 476, 0x2)
		ADD_BOOL(bEndPoint, 476, 0x1)
		bool ProceedWithMove(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6203);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9839);
			byte params[8] = { NULL };
			*(float*)params = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)&params[4];
		}
		class ReachSpec* GetReachSpecTo(class NavigationPoint* Nav, ScriptClass* SpecClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9842);
			byte params[12] = { NULL };
			*(class NavigationPoint**)params = Nav;
			*(ScriptClass**)&params[4] = SpecClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ReachSpec**)&params[8];
		}
		bool IsUsableAnchorFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9846);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanTeleport(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9849);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int SpecialCost(class Pawn* Seeker, class ReachSpec* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9852);
			byte params[12] = { NULL };
			*(class Pawn**)params = Seeker;
			*(class ReachSpec**)&params[4] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool Accept(class Actor* Incoming, class Actor* Source)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9856);
			byte params[12] = { NULL };
			*(class Actor**)params = Incoming;
			*(class Actor**)&params[4] = Source;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9861);
			byte params[12] = { NULL };
			*(class Pawn**)params = Other;
			*(float*)&params[4] = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9865);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class NavigationPoint* GetNearestNavToActor(class Actor* ChkActor, ScriptClass* RequiredClass, ScriptArray<class NavigationPoint*> ExcludeList, float MinDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9872);
			byte params[28] = { NULL };
			*(class Actor**)params = ChkActor;
			*(ScriptClass**)&params[4] = RequiredClass;
			*(ScriptArray<class NavigationPoint*>*)&params[8] = ExcludeList;
			*(float*)&params[20] = MinDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[24];
		}
		class NavigationPoint* GetNearestNavToPoint(class Actor* ChkActor, Vector ChkPoint, ScriptClass* RequiredClass, ScriptArray<class NavigationPoint*> ExcludeList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9883);
			byte params[36] = { NULL };
			*(class Actor**)params = ChkActor;
			*(Vector*)&params[4] = ChkPoint;
			*(ScriptClass**)&params[16] = RequiredClass;
			*(ScriptArray<class NavigationPoint*>*)&params[20] = ExcludeList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[32];
		}
		bool GetAllNavInRadius(class Actor* ChkActor, Vector ChkPoint, float Radius, ScriptArray<class NavigationPoint*>& out_NavList, bool bSkipBlocked, int inNetworkID, Object::Cylinder MinSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9894);
			byte params[52] = { NULL };
			*(class Actor**)params = ChkActor;
			*(Vector*)&params[4] = ChkPoint;
			*(float*)&params[16] = Radius;
			*(ScriptArray<class NavigationPoint*>*)&params[20] = out_NavList;
			*(bool*)&params[32] = bSkipBlocked;
			*(int*)&params[36] = inNetworkID;
			*(Object::Cylinder*)&params[40] = MinSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_NavList = *(ScriptArray<class NavigationPoint*>*)&params[20];
			return *(bool*)&params[48];
		}
		bool IsOnDifferentNetwork(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9904);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9907);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9909);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9910);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(NavigationPoint::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9912);
			byte params[4] = { NULL };
			*(NavigationPoint::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(NavigationPoint::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9914);
			byte params[4] = { NULL };
			*(NavigationPoint::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(NavigationPoint::CheckpointRecord*)params;
		}
		ScriptString* GetDebugAbbrev()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9916);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
