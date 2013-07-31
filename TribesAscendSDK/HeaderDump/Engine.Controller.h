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
		struct VisiblePortalInfo
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
		ADD_STRUCT(Vector, NavMeshPath_SearchExtent_Modifier, 888)
		ADD_STRUCT(Rotator, OldBasedRotation, 876)
		ADD_STRUCT(float, LaneOffset, 872)
		ADD_OBJECT(Pawn, Enemy, 856)
		ADD_STRUCT(float, MaxMoveTowardPawnTargetTime, 852)
		ADD_STRUCT(int, HighJumpNodeCostModifier, 848)
		ADD_STRUCT(float, InUseNodeCostMultiplier, 844)
		ADD_STRUCT(float, SightCounterInterval, 840)
		ADD_STRUCT(float, SightCounter, 836)
		ADD_STRUCT(Vector, FailedReachLocation, 824)
		ADD_STRUCT(float, FailedReachTime, 820)
		ADD_OBJECT(Actor, LastFailedReach, 816)
		ADD_OBJECT(Pawn, ShotTarget, 812)
		ADD_STRUCT(Vector, ViewZ, 800)
		ADD_STRUCT(Vector, ViewY, 788)
		ADD_STRUCT(Vector, ViewX, 776)
		ADD_STRUCT(float, GroundPitchTime, 772)
		ADD_STRUCT(int, MoveFailureCount, 768)
		ADD_OBJECT(Actor, FailedMoveTarget, 764)
		ADD_OBJECT(InterpActor, PendingMover, 760)
		ADD_STRUCT(float, LastRouteFind, 756)
		ADD_STRUCT(float, RouteDist, 752)
		ADD_OBJECT(Actor, RouteGoal, 748)
		ADD_STRUCT(Vector, CurrentPathDir, 736)
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
		ADD_STRUCT(Vector, OverrideSearchStart, 516)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5932);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RouteCache_Empty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5934);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RouteCache_AddItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5935);
			byte params[4] = { NULL };
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_InsertItem(class NavigationPoint* Nav, int Idx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5937);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = Nav;
			*(int*)&params[4] = Idx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_RemoveItem(class NavigationPoint* Nav)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5940);
			byte params[4] = { NULL };
			*(class NavigationPoint**)params = Nav;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RouteCache_RemoveIndex(int InIndex, int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5942);
			byte params[8] = { NULL };
			*(int*)params = InIndex;
			*(int*)&params[4] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFocalPoint(Vector FP, bool bOffsetFromBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5945);
			byte params[16] = { NULL };
			*(Vector*)params = FP;
			*(bool*)&params[12] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetFocalPoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5948);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void SetDestinationPosition(Vector Dest, bool bOffsetFromBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5950);
			byte params[16] = { NULL };
			*(Vector*)params = Dest;
			*(bool*)&params[12] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetDestinationPosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5953);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void SetAdjustLocation(Vector NewLoc, bool bAdjust, bool bOffsetFromBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5955);
			byte params[20] = { NULL };
			*(Vector*)params = NewLoc;
			*(bool*)&params[12] = bAdjust;
			*(bool*)&params[16] = bOffsetFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetAdjustLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5959);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void NotifyPathChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5961);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5962);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5964);
			byte params[36] = { NULL };
			*(ScriptName*)params = SlotName;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5972);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5974);
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5982);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5983);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5986);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5989);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5990);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetLocation(Vector NewLocation, Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5991);
			byte params[24] = { NULL };
			*(Vector*)params = NewLocation;
			*(Rotator*)&params[12] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetRotation(Rotator NewRotation, bool bResetCamera)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5995);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			*(bool*)&params[12] = bResetCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5998);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPossess(class SeqAct_Possess* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6000);
			byte params[4] = { NULL };
			*(class SeqAct_Possess**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6011);
			byte params[8] = { NULL };
			*(class Pawn**)params = inPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossess()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6015);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* inPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6016);
			byte params[4] = { NULL };
			*(class Pawn**)params = inPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GamePlayEndedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6020);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void NotifyPostLanded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6023);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupPRI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6026);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6027);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BeyondFogDistance(Vector ViewPoint, Vector OtherPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6030);
			byte params[28] = { NULL };
			*(Vector*)params = ViewPoint;
			*(Vector*)&params[12] = OtherPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6034);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6035);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitPlayerReplicationInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6041);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6044);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void ServerRestartPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6046);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerGivePawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6047);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCharacter(ScriptString* inCharacter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6048);
			byte params[12] = { NULL };
			*(ScriptString**)params = inCharacter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6050);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* damageTyp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6053);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = damageTyp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyProjLanded(class Projectile* Proj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6058);
			byte params[4] = { NULL };
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WarnProjExplode(class Projectile* Proj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6060);
			byte params[4] = { NULL };
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* inPickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6062);
			byte params[12] = { NULL };
			*(class Actor**)params = PickupHolder;
			*(ScriptClass**)&params[4] = inPickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool FireWeaponAt(class Actor* inActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6066);
			byte params[8] = { NULL };
			*(class Actor**)params = inActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6069);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6072);
			byte params[4] = { NULL };
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6074);
			byte params[4] = { NULL };
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6076);
			byte params[28] = { NULL };
			*(class Weapon**)params = W;
			*(Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		void InstantWarnTarget(class Actor* InTarget, class Weapon* FiredWeapon, Vector FireDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6082);
			byte params[20] = { NULL };
			*(class Actor**)params = InTarget;
			*(class Weapon**)&params[4] = FiredWeapon;
			*(Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6087);
			byte params[20] = { NULL };
			*(class Pawn**)params = shooter;
			*(float*)&params[4] = projSpeed;
			*(Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6091);
			byte params[4] = { NULL };
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6093);
			byte params[4] = { NULL };
			*(bool*)params = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSwitchToBestWeapon(bool bForceNewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6095);
			byte params[4] = { NULL };
			*(bool*)params = bForceNewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyChangedWeapon(class Weapon* PrevWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6097);
			byte params[8] = { NULL };
			*(class Weapon**)params = PrevWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool LineOfSightTo(class Actor* Other, Vector chkLocation, bool bTryAlternateTargetLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6100);
			byte params[24] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = chkLocation;
			*(bool*)&params[16] = bTryAlternateTargetLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool CanSee(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6105);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanSeeByPoints(Vector ViewLocation, Vector TestLocation, Rotator ViewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6108);
			byte params[40] = { NULL };
			*(Vector*)params = ViewLocation;
			*(Vector*)&params[12] = TestLocation;
			*(Rotator*)&params[24] = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		class Pawn* PickTarget(ScriptClass* TargetClass, float& bestAim, float& bestDist, Vector FireDir, Vector projStart, float MaxRange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6113);
			byte params[44] = { NULL };
			*(ScriptClass**)params = TargetClass;
			*(float*)&params[4] = bestAim;
			*(float*)&params[8] = bestDist;
			*(Vector*)&params[12] = FireDir;
			*(Vector*)&params[24] = projStart;
			*(float*)&params[36] = MaxRange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bestAim = *(float*)&params[4];
			bestDist = *(float*)&params[8];
			return *(class Pawn**)&params[40];
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6121);
			byte params[16] = { NULL };
			*(float*)params = Loudness;
			*(class Actor**)&params[4] = NoiseMaker;
			*(ScriptName*)&params[8] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeePlayer(class Pawn* Seen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6125);
			byte params[4] = { NULL };
			*(class Pawn**)params = Seen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeeMonster(class Pawn* Seen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6127);
			byte params[4] = { NULL };
			*(class Pawn**)params = Seen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnemyNotVisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6129);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveTo(Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6130);
			byte params[24] = { NULL };
			*(Vector*)params = NewDestination;
			*(class Actor**)&params[12] = ViewFocus;
			*(float*)&params[16] = DestinationOffset;
			*(bool*)&params[20] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToDirectNonPathPos(Vector NewDestination, class Actor* ViewFocus, float DestinationOffset, bool bShouldWalk)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6136);
			byte params[24] = { NULL };
			*(Vector*)params = NewDestination;
			*(class Actor**)&params[12] = ViewFocus;
			*(float*)&params[16] = DestinationOffset;
			*(bool*)&params[20] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToward(class Actor* NewTarget, class Actor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6141);
			byte params[20] = { NULL };
			*(class Actor**)params = NewTarget;
			*(class Actor**)&params[4] = ViewFocus;
			*(float*)&params[8] = DestinationOffset;
			*(bool*)&params[12] = bUseStrafing;
			*(bool*)&params[16] = bShouldWalk;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetupSpecialPathAbilities()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6147);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6148);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* FindPathTo(Vector aPoint, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6149);
			byte params[24] = { NULL };
			*(Vector*)params = aPoint;
			*(int*)&params[12] = MaxPathLength;
			*(bool*)&params[16] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[20];
		}
		class Actor* FindPathToward(class Actor* anActor, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6154);
			byte params[20] = { NULL };
			*(class Actor**)params = anActor;
			*(bool*)&params[4] = bWeightDetours;
			*(int*)&params[8] = MaxPathLength;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[16];
		}
		class Actor* FindPathTowardNearest(ScriptClass* GoalClass, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6160);
			byte params[20] = { NULL };
			*(ScriptClass**)params = GoalClass;
			*(bool*)&params[4] = bWeightDetours;
			*(int*)&params[8] = MaxPathLength;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[16];
		}
		class NavigationPoint* FindRandomDest()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6166);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)params;
		}
		class Actor* FindPathToIntercept(class Pawn* P, class Actor* InRouteGoal, bool bWeightDetours, int MaxPathLength, bool bReturnPartial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6168);
			byte params[24] = { NULL };
			*(class Pawn**)params = P;
			*(class Actor**)&params[4] = InRouteGoal;
			*(bool*)&params[8] = bWeightDetours;
			*(int*)&params[12] = MaxPathLength;
			*(bool*)&params[16] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[20];
		}
		bool PointReachable(Vector aPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6175);
			byte params[16] = { NULL };
			*(Vector*)params = aPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ActorReachable(class Actor* anActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6178);
			byte params[8] = { NULL };
			*(class Actor**)params = anActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void MoveUnreachable(Vector AttemptedDest, class Actor* AttemptedTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6181);
			byte params[16] = { NULL };
			*(Vector*)params = AttemptedDest;
			*(class Actor**)&params[12] = AttemptedTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PickWallAdjust(Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6184);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void WaitForLanding(float waitDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6187);
			byte params[4] = { NULL };
			*(float*)params = waitDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LongFall()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6189);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndClimbLadder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6190);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MayFall(bool bFloor, Vector FloorNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6191);
			byte params[16] = { NULL };
			*(bool*)params = bFloor;
			*(Vector*)&params[4] = FloorNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6194);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void WaitForMover(class InterpActor* M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6197);
			byte params[4] = { NULL };
			*(class InterpActor**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MoverFinished()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6200);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void UnderLift(class LiftCenter* Lift)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6205);
			byte params[4] = { NULL };
			*(class LiftCenter**)params = Lift;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6207);
			byte params[8] = { NULL };
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6210);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		void GetActorEyesViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6213);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		bool IsAimingAt(class Actor* ATarget, float Epsilon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6216);
			byte params[12] = { NULL };
			*(class Actor**)params = ATarget;
			*(float*)&params[4] = Epsilon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LandingShake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6222);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6224);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyHeadVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6226);
			byte params[8] = { NULL };
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6229);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6233);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6237);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyBump(class Actor* Other, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6240);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyJumpApex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6244);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMissedJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6245);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReachedPreciseDestination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6246);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InLatentExecution(int LatentActionNumber)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6247);
			byte params[8] = { NULL };
			*(int*)params = LatentActionNumber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopLatentExecution()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6250);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6251);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6258);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool IsDead()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6260);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6315);
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleGodMode(class SeqAct_ToggleGodMode* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6317);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleGodMode**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetPhysics(class SeqAct_SetPhysics* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6320);
			byte params[4] = { NULL };
			*(class SeqAct_SetPhysics**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6322);
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyCoverDisabled(class CoverLink* Link, int SlotIdx, bool bAdjacentIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6324);
			byte params[12] = { NULL };
			*(class CoverLink**)params = Link;
			*(int*)&params[4] = SlotIdx;
			*(bool*)&params[8] = bAdjacentIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyCoverAdjusted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6328);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyCoverClaimViolation(class Controller* NewClaim, class CoverLink* Link, int SlotIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6329);
			byte params[16] = { NULL };
			*(class Controller**)params = NewClaim;
			*(class CoverLink**)&params[4] = Link;
			*(int*)&params[8] = SlotIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6334);
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6336);
			byte params[4] = { NULL };
			*(class Inventory**)params = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6338);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6340);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsInCombat(bool bForceCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6342);
			byte params[8] = { NULL };
			*(bool*)params = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CurrentLevelUnloaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6345);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6346);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadyForLift()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6351);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitNavigationHandle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6352);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6353);
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6356);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GeneratePathToActor(class Actor* Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6358);
			byte params[16] = { NULL };
			*(class Actor**)params = Goal;
			*(float*)&params[4] = WithinDistance;
			*(bool*)&params[8] = bAllowPartialPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GeneratePathToLocation(Vector Goal, float WithinDistance, bool bAllowPartialPath)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6363);
			byte params[24] = { NULL };
			*(Vector*)params = Goal;
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
