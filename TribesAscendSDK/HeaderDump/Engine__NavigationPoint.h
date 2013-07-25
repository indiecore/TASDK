#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__DroppedPickup.h"
#include "Engine__Pawn.h"
#include "Engine__ReachSpec.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavigationPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavigationPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavigationPoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavigationPoint : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, LastAnchoredPawnTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, AnchoredPawn)
		ADD_VAR(::IntProperty, NetworkID, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'NavGuid'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Cylinder' for the property named 'MaxPathSize'!
		ADD_VAR(::FloatProperty, LastDetourWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InventoryDist, 0xFFFFFFFF)
		ADD_OBJECT(DroppedPickup, InventoryCache)
		ADD_VAR(::IntProperty, FearCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TransientCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ExtraCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Cost, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, previousPath)
		ADD_OBJECT(NavigationPoint, prevOrdered)
		ADD_OBJECT(NavigationPoint, nextOrdered)
		ADD_OBJECT(NavigationPoint, nextNavigationPoint)
		ADD_VAR(::IntProperty, bestPathWeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, visitedWeight, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.NavigationOctreeObject' for the property named 'NavOctreeObject'!
		ADD_VAR(::BoolProperty, bShouldSaveForCheckpoint, 0x40000000)
		ADD_VAR(::BoolProperty, bHasCrossLevelPaths, 0x20000000)
		ADD_VAR(::BoolProperty, bPreferredVehiclePath, 0x10000000)
		ADD_VAR(::BoolProperty, bBlockedForVehicles, 0x8000000)
		ADD_VAR(::BoolProperty, bBuildLongPaths, 0x4000000)
		ADD_VAR(::BoolProperty, bCanWalkOnToReach, 0x2000000)
		ADD_VAR(::BoolProperty, bMustTouchToReach, 0x1000000)
		ADD_VAR(::BoolProperty, bMakeSourceOnly, 0x800000)
		ADD_VAR(::BoolProperty, bVehicleDestination, 0x400000)
		ADD_VAR(::BoolProperty, bAlreadyVisited, 0x200000)
		ADD_VAR(::BoolProperty, bMayCausePain, 0x100000)
		ADD_VAR(::BoolProperty, bFlyingPreferred, 0x80000)
		ADD_VAR(::BoolProperty, bBlockable, 0x40000)
		ADD_VAR(::BoolProperty, bMustBeReachable, 0x20000)
		ADD_VAR(::BoolProperty, bSpecialForced, 0x10000)
		ADD_VAR(::BoolProperty, bSourceOnly, 0x8000)
		ADD_VAR(::BoolProperty, bDestinationOnly, 0x4000)
		ADD_VAR(::BoolProperty, bPathsChanged, 0x2000)
		ADD_VAR(::BoolProperty, bNotBased, 0x1000)
		ADD_VAR(::BoolProperty, bNoAutoConnect, 0x800)
		ADD_VAR(::BoolProperty, bSpecialMove, 0x400)
		ADD_VAR(::BoolProperty, bAutoBuilt, 0x200)
		ADD_VAR(::BoolProperty, bForceNoStrafing, 0x100)
		ADD_VAR(::BoolProperty, bAlwaysUseStrafing, 0x80)
		ADD_VAR(::BoolProperty, bNeverUseStrafing, 0x40)
		ADD_VAR(::BoolProperty, bOneWayPath, 0x20)
		ADD_VAR(::BoolProperty, bBlocked, 0x10)
		ADD_VAR(::BoolProperty, bCanReach, 0x8)
		ADD_VAR(::BoolProperty, bHideEditorPaths, 0x4)
		ADD_VAR(::BoolProperty, bTransientEndPoint, 0x2)
		ADD_VAR(::BoolProperty, bEndPoint, 0x1)
		bool ProceedWithMove(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.ProceedWithMove");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetBoundingCylinder");
			byte* params = (byte*)malloc(8);
			*(float*)params = CollisionRadius;
			*(float*)(params + 4) = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)(params + 4);
			free(params);
		}
		class ReachSpec* GetReachSpecTo(class NavigationPoint* Nav, ScriptClass* SpecClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetReachSpecTo");
			byte* params = (byte*)malloc(12);
			*(class NavigationPoint**)params = Nav;
			*(ScriptClass**)(params + 4) = SpecClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ReachSpec**)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsUsableAnchorFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.IsUsableAnchorFor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanTeleport(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.CanTeleport");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int SpecialCost(class Pawn* Seeker, class ReachSpec* Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.SpecialCost");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Seeker;
			*(class ReachSpec**)(params + 4) = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool Accept(class Actor* Incoming, class Actor* Source)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.Accept");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Incoming;
			*(class Actor**)(params + 4) = Source;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SuggestMovePreparation(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.SuggestMovePreparation");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class NavigationPoint* GetNearestNavToActor(class Actor* ChkActor, ScriptClass* RequiredClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ExcludeList, float MinDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetNearestNavToActor");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = ChkActor;
			*(ScriptClass**)(params + 4) = RequiredClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = ExcludeList;
			*(float*)(params + 20) = MinDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 24);
			free(params);
			return returnVal;
		}
		class NavigationPoint* GetNearestNavToPoint(class Actor* ChkActor, Vector ChkPoint, ScriptClass* RequiredClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ExcludeList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetNearestNavToPoint");
			byte* params = (byte*)malloc(36);
			*(class Actor**)params = ChkActor;
			*(Vector*)(params + 4) = ChkPoint;
			*(ScriptClass**)(params + 16) = RequiredClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = ExcludeList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 32);
			free(params);
			return returnVal;
		}
		bool GetAllNavInRadius(class Actor* ChkActor, Vector ChkPoint, float Radius, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_NavList, bool bSkipBlocked, int inNetworkID, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Cylinder'!
void* MinSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetAllNavInRadius");
			byte* params = (byte*)malloc(52);
			*(class Actor**)params = ChkActor;
			*(Vector*)(params + 4) = ChkPoint;
			*(float*)(params + 16) = Radius;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = out_NavList;
			*(bool*)(params + 32) = bSkipBlocked;
			*(int*)(params + 36) = inNetworkID;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Cylinder'!
void**)(params + 40) = MinSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_NavList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 48);
			free(params);
			return returnVal;
		}
		bool IsOnDifferentNetwork(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.IsOnDifferentNetwork");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationPoint.CheckpointRecord'!
void**)params;
			free(params);
		}
		ScriptArray<wchar_t> GetDebugAbbrev()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavigationPoint.GetDebugAbbrev");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
