#pragma once
#include "Engine.AIController.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#include "UDKBase.UDKSquadAI.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Projectile.h"
#include "Engine.Vehicle.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.PickupFactory.h"
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
	class UDKBot : public AIController
	{
	public:
		class EnemyPosition
		{
		public:
			ADD_STRUCT(float, Time, 24)
			ADD_STRUCT(Object::Vector, Velocity, 12)
			ADD_STRUCT(Object::Vector, Position, 0)
		};
		ADD_STRUCT(ScriptArray<UDKBot::EnemyPosition>, SavedPositions, 960)
		ADD_STRUCT(float, MultiJumpZ, 1120)
		ADD_STRUCT(float, DodgeToGoalPct, 1116)
		ADD_OBJECT(Actor, FearSpots, 1108)
		ADD_STRUCT(float, DodgeLandZ, 1104)
		ADD_STRUCT(float, CurrentAimError, 1100)
		ADD_STRUCT(float, LastErrorUpdateTime, 1096)
		ADD_STRUCT(float, ErrorUpdateFrequency, 1092)
		ADD_STRUCT(float, LastAimUpdateTime, 1088)
		ADD_STRUCT(float, AimUpdateFrequency, 1084)
		ADD_STRUCT(float, LastIterativeCheck, 1080)
		ADD_OBJECT(Pawn, BlockedAimTarget, 1076)
		ADD_OBJECT(NavigationPoint, SquadRouteGoal, 1072)
		ADD_STRUCT(Object::Vector, TrackedVelocity, 1060)
		ADD_STRUCT(float, BaseTrackingReactionTime, 1056)
		ADD_STRUCT(float, TrackingReactionTime, 1052)
		ADD_STRUCT(float, LastSeenTime, 1048)
		ADD_STRUCT(Object::Vector, LastSeeingPos, 1036)
		ADD_STRUCT(Object::Vector, LastSeenPos, 1024)
		ADD_STRUCT(float, MonitorMaxDistSq, 1020)
		ADD_OBJECT(Pawn, MonitoredPawn, 1016)
		ADD_STRUCT(Object::Vector, MonitorStartLoc, 1004)
		ADD_OBJECT(Projectile, WarningProjectile, 1000)
		ADD_STRUCT(float, WarningDelay, 996)
		ADD_STRUCT(float, RespawnPredictionTime, 992)
		ADD_STRUCT(float, HearingThreshold, 988)
		ADD_STRUCT(int, AcquisitionYawRate, 984)
		ADD_STRUCT(Object::Vector, ImpactVelocity, 972)
		ADD_OBJECT(Pawn, CurrentlyTrackedEnemy, 956)
		ADD_OBJECT(Vehicle, LastBlockingVehicle, 952)
		ADD_OBJECT(Pawn, VisibleEnemy, 948)
		ADD_STRUCT(float, EnemyVisibilityTime, 944)
		ADD_STRUCT(byte, ScriptedFireMode, 940)
		ADD_BOOL(bUsePreviousSquadRoute, 936, 0x4000)
		ADD_BOOL(bUsingSquadRoute, 936, 0x2000)
		ADD_BOOL(bAllowRouteReuse, 936, 0x1000)
		ADD_BOOL(bNeedDelayedLeaveVehicle, 936, 0x800)
		ADD_BOOL(bEnemyAcquired, 936, 0x400)
		ADD_BOOL(bInDodgeMove, 936, 0x200)
		ADD_BOOL(bPlannedJump, 936, 0x100)
		ADD_BOOL(bJumpOverWall, 936, 0x80)
		ADD_BOOL(bLeadTarget, 936, 0x40)
		ADD_BOOL(bEnemyIsVisible, 936, 0x20)
		ADD_BOOL(bEnemyInfoValid, 936, 0x10)
		ADD_BOOL(bTargetAlternateLoc, 936, 0x8)
		ADD_BOOL(bForceRefreshRoute, 936, 0x4)
		ADD_BOOL(bScriptSpecialJumpCost, 936, 0x2)
		ADD_BOOL(bExecutingWhatToDoNext, 936, 0x1)
		ADD_OBJECT(Actor, TemporaryFocus, 932)
		ADD_OBJECT(UDKSquadAI, Squad, 924)
		class Actor* FaceActor(float StrafingModifier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FaceActor");
			byte params[8] = { NULL };
			*(float*)&params[0] = StrafingModifier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void ExecuteWhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.ExecuteWhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveRunOverWarning(class UDKVehicle* V, float projSpeed, Object::Vector VehicleDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.ReceiveRunOverWarning");
			byte params[20] = { NULL };
			*(class UDKVehicle**)&params[0] = V;
			*(float*)&params[4] = projSpeed;
			*(Object::Vector*)&params[8] = VehicleDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WaitToSeeEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.WaitToSeeEnemy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LatentWhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.LatentWhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanMakePathTo(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.CanMakePathTo");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* FindBestInventoryPath(float& MinWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindBestInventoryPath");
			byte params[8] = { NULL };
			*(float*)&params[0] = MinWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MinWeight = *(float*)&params[0];
			return *(class Actor**)&params[4];
		}
		class Actor* FindPathToSquadRoute(bool bWeightDetours)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindPathToSquadRoute");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bWeightDetours;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void BuildSquadRoute()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.BuildSquadRoute");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* FindBestSuperPickup(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindBestSuperPickup");
			byte params[8] = { NULL };
			*(float*)&params[0] = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void WhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.WhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MonitoredPawnAlert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.MonitoredPawnAlert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimeDJReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.TimeDJReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MayDodgeToMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.MayDodgeToMoveTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SpecialJumpCost(float RequiredJumpZ, float& Cost)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.SpecialJumpCost");
			byte params[12] = { NULL };
			*(float*)&params[0] = RequiredJumpZ;
			*(float*)&params[4] = Cost;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Cost = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		float SuperDesireability(class PickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.SuperDesireability");
			byte params[8] = { NULL };
			*(class PickupFactory**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float AdjustAimError(float TargetDist, bool bInstantProj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.AdjustAimError");
			byte params[12] = { NULL };
			*(float*)&params[0] = TargetDist;
			*(bool*)&params[4] = bInstantProj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void MissedDodge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.MissedDodge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayedWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.DelayedWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayedLeaveVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.DelayedLeaveVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
