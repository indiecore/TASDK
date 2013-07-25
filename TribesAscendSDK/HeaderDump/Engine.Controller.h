#pragma once
#include "Engine.Actor.h"
#include "Engine.InterpGroup.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.InterpActor.h"
#include "Engine.ReachSpec.h"
#include "Engine.NavigationPoint.h"
#include "Engine.SeqAct_ModifyHealth.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.NavigationHandle.h"
#include "Engine.SeqAct_SetPhysics.h"
#include "Engine.SoundCue.h"
#include "Engine.SeqAct_Possess.h"
#include "Engine.Projectile.h"
#include "Engine.Inventory.h"
#include "Engine.LiftCenter.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.HUD.h"
#include "Engine.SeqAct_Teleport.h"
#include "Engine.SeqAct_ToggleGodMode.h"
#include "Engine.SeqAct_SetVelocity.h"
#include "Engine.CoverLink.h"
#include "Engine.SeqAct_ToggleHidden.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.InterpGroupInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Controller." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Controller." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Controller." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Controller : public Actor
	{
	public:
		ADD_OBJECT(Pawn, Pawn)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo)
		ADD_VAR(::BoolProperty, bGodMode, 0x2)
		ADD_STRUCT(::VectorProperty, NavMeshPath_SearchExtent_Modifier, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, OldBasedRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LaneOffset, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Enemy)
		ADD_VAR(::FloatProperty, MaxMoveTowardPawnTargetTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HighJumpNodeCostModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InUseNodeCostMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SightCounterInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SightCounter, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FailedReachLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FailedReachTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastFailedReach)
		ADD_OBJECT(Pawn, ShotTarget)
		ADD_STRUCT(::VectorProperty, ViewZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ViewY, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ViewX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroundPitchTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MoveFailureCount, 0xFFFFFFFF)
		ADD_OBJECT(Actor, FailedMoveTarget)
		ADD_OBJECT(InterpActor, PendingMover)
		ADD_VAR(::FloatProperty, LastRouteFind, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RouteDist, 0xFFFFFFFF)
		ADD_OBJECT(Actor, RouteGoal)
		ADD_STRUCT(::VectorProperty, CurrentPathDir, 0xFFFFFFFF)
		ADD_OBJECT(ReachSpec, NextRoutePath)
		ADD_OBJECT(ReachSpec, CurrentPath)
		ADD_OBJECT(NavigationPoint, StartSpot)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'AdjustPosition'!
		ADD_OBJECT(Actor, GoalList)
		ADD_OBJECT(Actor, Focus)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'FocalPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'DestinationPosition'!
		ADD_OBJECT(Actor, MoveTarget)
		ADD_VAR(::FloatProperty, MoveTimer, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OverrideSearchStart, 0xFFFFFFFF)
		ADD_OBJECT(NavigationHandle, NavigationHandle)
		ADD_OBJECT(ScriptClass, NavigationHandleClass)
		ADD_VAR(::FloatProperty, MinHitWall, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bAltFire, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bFire, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsingPathLanes, 0x20000)
		ADD_VAR(::BoolProperty, bSeeFriendly, 0x10000)
		ADD_VAR(::BoolProperty, bPreciseDestination, 0x8000)
		ADD_VAR(::BoolProperty, bNotifyFallingHitWall, 0x4000)
		ADD_VAR(::BoolProperty, bSkipExtraLOSChecks, 0x2000)
		ADD_VAR(::BoolProperty, bLOSflag, 0x1000)
		ADD_VAR(::BoolProperty, bForceStrafe, 0x800)
		ADD_VAR(::BoolProperty, bPreparingMove, 0x400)
		ADD_VAR(::BoolProperty, bAdjusting, 0x200)
		ADD_VAR(::BoolProperty, bCanDoSpecial, 0x100)
		ADD_VAR(::BoolProperty, bAdvancedTactics, 0x80)
		ADD_VAR(::BoolProperty, bOverrideSearchStart, 0x40)
		ADD_VAR(::BoolProperty, bNotifyApex, 0x20)
		ADD_VAR(::BoolProperty, bNotifyPostLanded, 0x10)
		ADD_VAR(::BoolProperty, bSlowerZAcquire, 0x8)
		ADD_VAR(::BoolProperty, bSoaking, 0x4)
		ADD_VAR(::BoolProperty, bIsPlayer, 0x1)
		ADD_OBJECT(Controller, NextController)
		ADD_VAR(::IntProperty, PlayerNum, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavigationHandle'!
		bool IsLocalPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsLocalPlayerController");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RouteCache_Empty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_Empty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RouteCache_AddItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_AddItem");
			byte* params = (byte*)malloc(4);
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RouteCache_InsertItem(class NavigationPoint* Nav, int Idx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_InsertItem");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = Nav;
			*(int*)(params + 4) = Idx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RouteCache_RemoveItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_RemoveItem");
			byte* params = (byte*)malloc(4);
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RouteCache_RemoveIndex(int InIndex, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_RemoveIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = InIndex;
			*(int*)(params + 4) = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFocalPoint(Vector FP, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetFocalPoint");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = FP;
			*(bool*)(params + 12) = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetFocalPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetFocalPoint");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void SetDestinationPosition(Vector Dest, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetDestinationPosition");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = Dest;
			*(bool*)(params + 12) = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetDestinationPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetDestinationPosition");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void SetAdjustLocation(Vector NewLoc, bool bAdjust, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetAdjustLocation");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = NewLoc;
			*(bool*)(params + 12) = bAdjust;
			*(bool*)(params + 16) = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetAdjustLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetAdjustLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void NotifyPathChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyPathChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.BeginAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptArray<wchar_t> GroupName, ScriptArray<wchar_t> SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PlayActorFaceFXAnim");
			byte* params = (byte*)malloc(36);
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptArray<wchar_t>*)(params + 4) = GroupName;
			*(ScriptArray<wchar_t>*)(params + 16) = SeqName;
			*(class SoundCue**)(params + 28) = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopActorFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetMorphWeight");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphNodeName;
			*(float*)(params + 8) = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetSkelControlScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SkelControlName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetLocation(Vector NewLocation, Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSetLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = NewLocation;
			*(Rotator*)(params + 12) = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetRotation(Rotator NewRotation, bool bResetCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSetRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(bool*)(params + 12) = bResetCamera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPossess(class SeqAct_Possess* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnPossess");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Possess**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.Possess");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = inPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.UnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* inPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PawnDied");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = inPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GamePlayEndedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GamePlayEndedState");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void NotifyPostLanded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyPostLanded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupPRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CleanupPRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.Restart");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool BeyondFogDistance(Vector ViewPoint, Vector OtherPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.BeyondFogDistance");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = ViewPoint;
			*(Vector*)(params + 12) = OtherPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.EnemyJustTeleported");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InitPlayerReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void ServerRestartPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ServerRestartPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerGivePawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ServerGivePawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCharacter(ScriptArray<wchar_t> inCharacter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetCharacter");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = inCharacter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GameHasEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* damageTyp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyKilled");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = damageTyp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyProjLanded(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyProjLanded");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WarnProjExplode(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WarnProjExplode");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* inPickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RatePickup");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = PickupHolder;
			*(ScriptClass**)(params + 4) = inPickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool FireWeaponAt(class Actor* inActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FireWeaponAt");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = inActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopFiring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RoundHasEnded");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HandlePickup");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = W;
			*(Vector*)(params + 4) = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		void InstantWarnTarget(class Actor* InTarget, class Weapon* FiredWeapon, Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InstantWarnTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = InTarget;
			*(class Weapon**)(params + 4) = FiredWeapon;
			*(Vector*)(params + 8) = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReceiveWarning");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = shooter;
			*(float*)(params + 4) = projSpeed;
			*(Vector*)(params + 8) = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReceiveProjectileWarning");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SwitchToBestWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSwitchToBestWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyChangedWeapon(class Weapon* PrevWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyChangedWeapon");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = PrevWeapon;
			*(class Weapon**)(params + 4) = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool LineOfSightTo(class Actor* Other, Vector chkLocation, bool bTryAlternateTargetLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.LineOfSightTo");
			byte* params = (byte*)malloc(24);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = chkLocation;
			*(bool*)(params + 16) = bTryAlternateTargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool CanSee(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CanSee");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanSeeByPoints(Vector ViewLocation, Vector TestLocation, Rotator ViewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CanSeeByPoints");
			byte* params = (byte*)malloc(40);
			*(Vector*)params = ViewLocation;
			*(Vector*)(params + 12) = TestLocation;
			*(Rotator*)(params + 24) = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		class Pawn* PickTarget(ScriptClass* TargetClass, float& bestAim, float& bestDist, Vector FireDir, Vector projStart, float MaxRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PickTarget");
			byte* params = (byte*)malloc(44);
			*(ScriptClass**)params = TargetClass;
			*(float*)(params + 4) = bestAim;
			*(float*)(params + 8) = bestDist;
			*(Vector*)(params + 12) = FireDir;
			*(Vector*)(params + 24) = projStart;
			*(float*)(params + 36) = MaxRange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			bestAim = *(float*)(params + 4);
			bestDist = *(float*)(params + 8);
			auto returnVal = *(class Pawn**)(params + 40);
			free(params);
			return returnVal;
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HearNoise");
			byte* params = (byte*)malloc(16);
			*(float*)params = Loudness;
			*(class Actor**)(params + 4) = NoiseMaker;
			*(ScriptName*)(params + 8) = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeePlayer(class Pawn* Seen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SeePlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Seen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeeMonster(class Pawn* Seen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SeeMonster");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Seen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnemyNotVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.EnemyNotVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveTo(Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveTo");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = NewDestination;
			*(class Actor**)(params + 12) = ViewFocus;
			*(float*)(params + 16) = DestinationOffset;
			*(bool*)(params + 20) = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveToDirectNonPathPos(Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveToDirectNonPathPos");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = NewDestination;
			*(class Actor**)(params + 12) = ViewFocus;
			*(float*)(params + 16) = DestinationOffset;
			*(bool*)(params + 20) = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveToward(class Actor* NewTarget, class Actor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveToward");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = NewTarget;
			*(class Actor**)(params + 4) = ViewFocus;
			*(float*)(params + 8) = DestinationOffset;
			*(bool*)(params + 12) = bUseStrafing;
			*(bool*)(params + 16) = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetupSpecialPathAbilities()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetupSpecialPathAbilities");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FinishRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* FindPathTo(Vector aPoint, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathTo");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = aPoint;
			*(int*)(params + 12) = MaxPathLength;
			*(bool*)(params + 16) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 20);
			free(params);
			return returnVal;
		}
		class Actor* FindPathToward(class Actor* anActor, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathToward");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = anActor;
			*(bool*)(params + 4) = bWeightDetours;
			*(int*)(params + 8) = MaxPathLength;
			*(bool*)(params + 12) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 16);
			free(params);
			return returnVal;
		}
		class Actor* FindPathTowardNearest(ScriptClass* GoalClass, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathTowardNearest");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = GoalClass;
			*(bool*)(params + 4) = bWeightDetours;
			*(int*)(params + 8) = MaxPathLength;
			*(bool*)(params + 12) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 16);
			free(params);
			return returnVal;
		}
		class NavigationPoint* FindRandomDest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindRandomDest");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)params;
			free(params);
			return returnVal;
		}
		class Actor* FindPathToIntercept(class Pawn* P, class Actor* InRouteGoal, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathToIntercept");
			byte* params = (byte*)malloc(24);
			*(class Pawn**)params = P;
			*(class Actor**)(params + 4) = InRouteGoal;
			*(bool*)(params + 8) = bWeightDetours;
			*(int*)(params + 12) = MaxPathLength;
			*(bool*)(params + 16) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 20);
			free(params);
			return returnVal;
		}
		bool PointReachable(Vector aPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PointReachable");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = aPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ActorReachable(class Actor* anActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ActorReachable");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = anActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void MoveUnreachable(Vector AttemptedDest, class Actor* AttemptedTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveUnreachable");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = AttemptedDest;
			*(class Actor**)(params + 12) = AttemptedTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PickWallAdjust(Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PickWallAdjust");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void WaitForLanding(float waitDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WaitForLanding");
			byte* params = (byte*)malloc(4);
			*(float*)params = waitDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LongFall()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.LongFall");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndClimbLadder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.EndClimbLadder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MayFall(bool bFloor, Vector FloorNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MayFall");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bFloor;
			*(Vector*)(params + 4) = FloorNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.AllowDetourTo");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void WaitForMover(class InterpActor* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WaitForMover");
			byte* params = (byte*)malloc(4);
			*(class InterpActor**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MoverFinished()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoverFinished");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void UnderLift(class LiftCenter* Lift)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.UnderLift");
			byte* params = (byte*)malloc(4);
			*(class LiftCenter**)params = Lift;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HandlePathObstruction");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = out_Location;
			*(Rotator*)(params + 12) = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)(params + 12);
			free(params);
		}
		void GetActorEyesViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetActorEyesViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = out_Location;
			*(Rotator*)(params + 12) = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)(params + 12);
			free(params);
		}
		bool IsAimingAt(class Actor* ATarget, float Epsilon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsAimingAt");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = ATarget;
			*(float*)(params + 4) = Epsilon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool LandingShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.LandingShake");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyPhysicsVolumeChange");
			byte* params = (byte*)malloc(4);
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NotifyHeadVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyHeadVolumeChange");
			byte* params = (byte*)malloc(8);
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyLanded");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyHitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyFallingHitWall");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NotifyBump(class Actor* Other, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyBump");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NotifyJumpApex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyJumpApex");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMissedJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyMissedJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReachedPreciseDestination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReachedPreciseDestination");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InLatentExecution(int LatentActionNumber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InLatentExecution");
			byte* params = (byte*)malloc(8);
			*(int*)params = LatentActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StopLatentExecution()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopLatentExecution");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool IsDead()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsDead");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnTeleport");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Teleport**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleGodMode(class SeqAct_ToggleGodMode* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnToggleGodMode");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleGodMode**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetPhysics(class SeqAct_SetPhysics* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnSetPhysics");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetPhysics**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnSetVelocity");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetVelocity**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyCoverDisabled(class CoverLink* Link, int SlotIdx, bool bAdjacentIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverDisabled");
			byte* params = (byte*)malloc(12);
			*(class CoverLink**)params = Link;
			*(int*)(params + 4) = SlotIdx;
			*(bool*)(params + 8) = bAdjacentIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyCoverAdjusted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverAdjusted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyCoverClaimViolation(class Controller* NewClaim, class CoverLink* Link, int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverClaimViolation");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = NewClaim;
			*(class CoverLink**)(params + 4) = Link;
			*(int*)(params + 8) = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnModifyHealth");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ModifyHealth**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyAddInventory");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnToggleHidden");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleHidden**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsSpectating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsInCombat(bool bForceCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsInCombat");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void CurrentLevelUnloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CurrentLevelUnloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SendMessage");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)(params + 4) = MessageType;
			*(float*)(params + 12) = Wait;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReadyForLift()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReadyForLift");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitNavigationHandle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InitNavigationHandle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InterpolationStarted");
			byte* params = (byte*)malloc(8);
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)(params + 4) = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InterpolationFinished");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GeneratePathToActor(class Actor* Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GeneratePathToActor");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = Goal;
			*(float*)(params + 4) = WithinDistance;
			*(bool*)(params + 8) = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GeneratePathToLocation(Vector Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GeneratePathToLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Goal;
			*(float*)(params + 12) = WithinDistance;
			*(bool*)(params + 16) = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
