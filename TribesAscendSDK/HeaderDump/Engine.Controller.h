#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.InterpGroup.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.NavigationPoint.h"
#include "Engine.InterpActor.h"
#include "Engine.ReachSpec.h"
#include "Engine.NavigationHandle.h"
#include "Engine.SeqAct_ModifyHealth.h"
#include "Engine.FaceFXAnimSet.h"
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
	class Controller : public Actor
	{
	public:
		static const auto LATENT_MOVETOWARD = 503;
		class VisiblePortalInfo
		{
		public:
			ADD_OBJECT(Actor, Destination, 4)
			ADD_OBJECT(Actor, Source, 0)
		};
		ADD_OBJECT(Pawn, Pawn, 480)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo, 484)
		ADD_BOOL(bGodMode, 496, 0x2)
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, RouteCache, 716)
		ADD_STRUCT(ScriptArray<Controller::VisiblePortalInfo>, VisiblePortals, 860)
		ADD_STRUCT(Object::Vector, NavMeshPath_SearchExtent_Modifier, 888)
		ADD_STRUCT(Object::Rotator, OldBasedRotation, 876)
		ADD_STRUCT(float, LaneOffset, 872)
		ADD_OBJECT(Pawn, Enemy, 856)
		ADD_STRUCT(float, MaxMoveTowardPawnTargetTime, 852)
		ADD_STRUCT(int, HighJumpNodeCostModifier, 848)
		ADD_STRUCT(float, InUseNodeCostMultiplier, 844)
		ADD_STRUCT(float, SightCounterInterval, 840)
		ADD_STRUCT(float, SightCounter, 836)
		ADD_STRUCT(Object::Vector, FailedReachLocation, 824)
		ADD_STRUCT(float, FailedReachTime, 820)
		ADD_OBJECT(Actor, LastFailedReach, 816)
		ADD_OBJECT(Pawn, ShotTarget, 812)
		ADD_STRUCT(Object::Vector, ViewZ, 800)
		ADD_STRUCT(Object::Vector, ViewY, 788)
		ADD_STRUCT(Object::Vector, ViewX, 776)
		ADD_STRUCT(float, GroundPitchTime, 772)
		ADD_STRUCT(int, MoveFailureCount, 768)
		ADD_OBJECT(Actor, FailedMoveTarget, 764)
		ADD_OBJECT(InterpActor, PendingMover, 760)
		ADD_STRUCT(float, LastRouteFind, 756)
		ADD_STRUCT(float, RouteDist, 752)
		ADD_OBJECT(Actor, RouteGoal, 748)
		ADD_STRUCT(Object::Vector, CurrentPathDir, 736)
		ADD_OBJECT(ReachSpec, NextRoutePath, 732)
		ADD_OBJECT(ReachSpec, CurrentPath, 728)
		ADD_OBJECT(NavigationPoint, StartSpot, 712)
		ADD_STRUCT(Actor::BasedPosition, AdjustPosition, 660)
		ADD_OBJECT(Actor, GoalList, 644)
		ADD_OBJECT(Actor, Focus, 640)
		ADD_STRUCT(Actor::BasedPosition, FocalPosition, 588)
		ADD_STRUCT(Actor::BasedPosition, DestinationPosition, 536)
		ADD_OBJECT(Actor, MoveTarget, 532)
		ADD_STRUCT(float, MoveTimer, 528)
		ADD_STRUCT(Object::Vector, OverrideSearchStart, 516)
		ADD_OBJECT(NavigationHandle, NavigationHandle, 512)
		ADD_OBJECT(ScriptClass, NavigationHandleClass, 508)
		ADD_STRUCT(float, MinHitWall, 504)
		ADD_STRUCT(byte, bAltFire, 501)
		ADD_STRUCT(byte, bFire, 500)
		ADD_BOOL(bUsingPathLanes, 496, 0x20000)
		ADD_BOOL(bSeeFriendly, 496, 0x10000)
		ADD_BOOL(bPreciseDestination, 496, 0x8000)
		ADD_BOOL(bNotifyFallingHitWall, 496, 0x4000)
		ADD_BOOL(bSkipExtraLOSChecks, 496, 0x2000)
		ADD_BOOL(bLOSflag, 496, 0x1000)
		ADD_BOOL(bForceStrafe, 496, 0x800)
		ADD_BOOL(bPreparingMove, 496, 0x400)
		ADD_BOOL(bAdjusting, 496, 0x200)
		ADD_BOOL(bCanDoSpecial, 496, 0x100)
		ADD_BOOL(bAdvancedTactics, 496, 0x80)
		ADD_BOOL(bOverrideSearchStart, 496, 0x40)
		ADD_BOOL(bNotifyApex, 496, 0x20)
		ADD_BOOL(bNotifyPostLanded, 496, 0x10)
		ADD_BOOL(bSlowerZAcquire, 496, 0x8)
		ADD_BOOL(bSoaking, 496, 0x4)
		ADD_BOOL(bIsPlayer, 496, 0x1)
		ADD_OBJECT(Controller, NextController, 492)
		ADD_STRUCT(int, PlayerNum, 488)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavigationHandle, 476)
		bool IsLocalPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsLocalPlayerController");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RouteCache_Empty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_Empty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RouteCache_AddItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_AddItem");
			byte params[4] = { NULL };
			*(class NavigationPoint**)&params[0] = Nav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_InsertItem(class NavigationPoint* Nav, int Idx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_InsertItem");
			byte params[8] = { NULL };
			*(class NavigationPoint**)&params[0] = Nav;
			*(int*)&params[4] = Idx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_RemoveItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_RemoveItem");
			byte params[4] = { NULL };
			*(class NavigationPoint**)&params[0] = Nav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_RemoveIndex(int InIndex, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RouteCache_RemoveIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = InIndex;
			*(int*)&params[4] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFocalPoint(Object::Vector FP, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetFocalPoint");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = FP;
			*(bool*)&params[12] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetFocalPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetFocalPoint");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void SetDestinationPosition(Object::Vector Dest, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetDestinationPosition");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Dest;
			*(bool*)&params[12] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetDestinationPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetDestinationPosition");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void SetAdjustLocation(Object::Vector NewLoc, bool bAdjust, bool bOffsetFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetAdjustLocation");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = NewLoc;
			*(bool*)&params[12] = bAdjust;
			*(bool*)&params[16] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetAdjustLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetAdjustLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void NotifyPathChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyPathChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetAnimPosition");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = SlotName;
			*(int*)&params[8] = ChannelIndex;
			*(ScriptName*)&params[12] = InAnimSeqName;
			*(float*)&params[20] = InPosition;
			*(bool*)&params[24] = bFireNotifies;
			*(bool*)&params[28] = bLooping;
			*(bool*)&params[32] = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PlayActorFaceFXAnim");
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopActorFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetMorphWeight");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetSkelControlScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void ClientSetLocation(Object::Vector NewLocation, Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSetLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			*(Object::Rotator*)&params[12] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetRotation(Object::Rotator NewRotation, bool bResetCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSetRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(bool*)&params[12] = bResetCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPossess(class SeqAct_Possess* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnPossess");
			byte params[4] = { NULL };
			*(class SeqAct_Possess**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.Possess");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = inPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.UnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* inPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PawnDied");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = inPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GamePlayEndedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GamePlayEndedState");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BeyondFogDistance(Object::Vector ViewPoint, Object::Vector OtherPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.BeyondFogDistance");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = ViewPoint;
			*(Object::Vector*)&params[12] = OtherPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.EnemyJustTeleported");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InitPlayerReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
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
		void SetCharacter(ScriptString* inCharacter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SetCharacter");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = inCharacter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GameHasEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* damageTyp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyKilled");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = damageTyp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyProjLanded(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyProjLanded");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WarnProjExplode(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WarnProjExplode");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* inPickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RatePickup");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = PickupHolder;
			*(ScriptClass**)&params[4] = inPickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool FireWeaponAt(class Actor* inActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FireWeaponAt");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = inActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopFiring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.RoundHasEnded");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HandlePickup");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* W, Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = W;
			*(Object::Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		void InstantWarnTarget(class Actor* InTarget, class Weapon* FiredWeapon, Object::Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InstantWarnTarget");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = InTarget;
			*(class Weapon**)&params[4] = FiredWeapon;
			*(Object::Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Object::Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReceiveWarning");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = shooter;
			*(float*)&params[4] = projSpeed;
			*(Object::Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ReceiveProjectileWarning");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SwitchToBestWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ClientSwitchToBestWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyChangedWeapon(class Weapon* PrevWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyChangedWeapon");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = PrevWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool LineOfSightTo(class Actor* Other, Object::Vector chkLocation, bool bTryAlternateTargetLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.LineOfSightTo");
			byte params[24] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = chkLocation;
			*(bool*)&params[16] = bTryAlternateTargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool CanSee(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CanSee");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanSeeByPoints(Object::Vector ViewLocation, Object::Vector TestLocation, Object::Rotator ViewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CanSeeByPoints");
			byte params[40] = { NULL };
			*(Object::Vector*)&params[0] = ViewLocation;
			*(Object::Vector*)&params[12] = TestLocation;
			*(Object::Rotator*)&params[24] = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		class Pawn* PickTarget(ScriptClass* TargetClass, float& bestAim, float& bestDist, Object::Vector FireDir, Object::Vector projStart, float MaxRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PickTarget");
			byte params[44] = { NULL };
			*(ScriptClass**)&params[0] = TargetClass;
			*(float*)&params[4] = bestAim;
			*(float*)&params[8] = bestDist;
			*(Object::Vector*)&params[12] = FireDir;
			*(Object::Vector*)&params[24] = projStart;
			*(float*)&params[36] = MaxRange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bestAim = *(float*)&params[4];
			bestDist = *(float*)&params[8];
			return *(class Pawn**)&params[40];
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HearNoise");
			byte params[16] = { NULL };
			*(float*)&params[0] = Loudness;
			*(class Actor**)&params[4] = NoiseMaker;
			*(ScriptName*)&params[8] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeePlayer(class Pawn* Seen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SeePlayer");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Seen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeeMonster(class Pawn* Seen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SeeMonster");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Seen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnemyNotVisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.EnemyNotVisible");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveTo(Object::Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveTo");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = NewDestination;
			*(class Actor**)&params[12] = ViewFocus;
			*(float*)&params[16] = DestinationOffset;
			*(bool*)&params[20] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToDirectNonPathPos(Object::Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveToDirectNonPathPos");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = NewDestination;
			*(class Actor**)&params[12] = ViewFocus;
			*(float*)&params[16] = DestinationOffset;
			*(bool*)&params[20] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToward(class Actor* NewTarget, class Actor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveToward");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = NewTarget;
			*(class Actor**)&params[4] = ViewFocus;
			*(float*)&params[8] = DestinationOffset;
			*(bool*)&params[12] = bUseStrafing;
			*(bool*)&params[16] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		class Actor* FindPathTo(Object::Vector aPoint, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathTo");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = aPoint;
			*(int*)&params[12] = MaxPathLength;
			*(bool*)&params[16] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[20];
		}
		class Actor* FindPathToward(class Actor* anActor, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathToward");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = anActor;
			*(bool*)&params[4] = bWeightDetours;
			*(int*)&params[8] = MaxPathLength;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[16];
		}
		class Actor* FindPathTowardNearest(ScriptClass* GoalClass, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathTowardNearest");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = GoalClass;
			*(bool*)&params[4] = bWeightDetours;
			*(int*)&params[8] = MaxPathLength;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[16];
		}
		class NavigationPoint* FindRandomDest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindRandomDest");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[0];
		}
		class Actor* FindPathToIntercept(class Pawn* P, class Actor* InRouteGoal, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.FindPathToIntercept");
			byte params[24] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class Actor**)&params[4] = InRouteGoal;
			*(bool*)&params[8] = bWeightDetours;
			*(int*)&params[12] = MaxPathLength;
			*(bool*)&params[16] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[20];
		}
		bool PointReachable(Object::Vector aPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PointReachable");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = aPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ActorReachable(class Actor* anActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.ActorReachable");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = anActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void MoveUnreachable(Object::Vector AttemptedDest, class Actor* AttemptedTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoveUnreachable");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = AttemptedDest;
			*(class Actor**)&params[12] = AttemptedTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PickWallAdjust(Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.PickWallAdjust");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void WaitForLanding(float waitDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WaitForLanding");
			byte params[4] = { NULL };
			*(float*)&params[0] = waitDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void MayFall(bool bFloor, Object::Vector FloorNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MayFall");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bFloor;
			*(Object::Vector*)&params[4] = FloorNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.AllowDetourTo");
			byte params[8] = { NULL };
			*(class NavigationPoint**)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void WaitForMover(class InterpActor* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.WaitForMover");
			byte params[4] = { NULL };
			*(class InterpActor**)&params[0] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MoverFinished()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.MoverFinished");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void UnderLift(class LiftCenter* Lift)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.UnderLift");
			byte params[4] = { NULL };
			*(class LiftCenter**)&params[0] = Lift;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.HandlePathObstruction");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetPlayerViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		void GetActorEyesViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetActorEyesViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		bool IsAimingAt(class Actor* ATarget, float Epsilon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsAimingAt");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = ATarget;
			*(float*)&params[4] = Epsilon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LandingShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.LandingShake");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyPhysicsVolumeChange");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyHeadVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyHeadVolumeChange");
			byte params[8] = { NULL };
			*(class PhysicsVolume**)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NotifyLanded(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyLanded");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool NotifyHitWall(Object::Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyHitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyFallingHitWall(Object::Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyFallingHitWall");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyBump(class Actor* Other, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyBump");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
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
			byte params[8] = { NULL };
			*(int*)&params[0] = LatentActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopLatentExecution()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.StopLatentExecution");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool IsDead()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsDead");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnTeleport");
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleGodMode(class SeqAct_ToggleGodMode* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnToggleGodMode");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleGodMode**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetPhysics(class SeqAct_SetPhysics* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnSetPhysics");
			byte params[4] = { NULL };
			*(class SeqAct_SetPhysics**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnSetVelocity");
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyCoverDisabled(class CoverLink* Link, int SlotIdx, bool bAdjacentIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverDisabled");
			byte params[12] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bAdjacentIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyCoverAdjusted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverAdjusted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyCoverClaimViolation(class Controller* NewClaim, class CoverLink* Link, int SlotIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyCoverClaimViolation");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = NewClaim;
			*(class CoverLink**)&params[4] = Link;
			*(int*)&params[8] = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnModifyHealth");
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.NotifyAddInventory");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.OnToggleHidden");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsSpectating");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsInCombat(bool bForceCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.IsInCombat");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CurrentLevelUnloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.CurrentLevelUnloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.SendMessage");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.InterpolationFinished");
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GeneratePathToActor(class Actor* Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GeneratePathToActor");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = Goal;
			*(float*)&params[4] = WithinDistance;
			*(bool*)&params[8] = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GeneratePathToLocation(Object::Vector Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Controller.GeneratePathToLocation");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Goal;
			*(float*)&params[12] = WithinDistance;
			*(bool*)&params[16] = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
