#pragma once
#include "Engine__Actor.h"
#include "Engine__AIController.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Pawn.h"
#include "Engine__Projectile.h"
#include "Engine__Vehicle.h"
#include "UDKBase__UDKSquadAI.h"
#include "UDKBase__UDKVehicle.h"
#include "Engine__PickupFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKBot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKBot : public AIController
	{
	public:
		ADD_VAR(::FloatProperty, MultiJumpZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DodgeToGoalPct, 0xFFFFFFFF)
		ADD_OBJECT(Actor, FearSpots)
		ADD_VAR(::FloatProperty, DodgeLandZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentAimError, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastErrorUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ErrorUpdateFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastAimUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AimUpdateFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastIterativeCheck, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, BlockedAimTarget)
		ADD_OBJECT(NavigationPoint, SquadRouteGoal)
		ADD_STRUCT(::VectorProperty, TrackedVelocity, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, BaseTrackingReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TrackingReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSeenTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastSeeingPos, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastSeenPos, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MonitorMaxDistSq, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, MonitoredPawn)
		ADD_STRUCT(::VectorProperty, MonitorStartLoc, 0xFFFFFFFF
		ADD_OBJECT(Projectile, WarningProjectile)
		ADD_VAR(::FloatProperty, WarningDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnPredictionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HearingThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AcquisitionYawRate, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ImpactVelocity, 0xFFFFFFFF
		ADD_OBJECT(Pawn, CurrentlyTrackedEnemy)
		ADD_OBJECT(Vehicle, LastBlockingVehicle)
		ADD_OBJECT(Pawn, VisibleEnemy)
		ADD_VAR(::FloatProperty, EnemyVisibilityTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ScriptedFireMode, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsePreviousSquadRoute, 0x4000)
		ADD_VAR(::BoolProperty, bUsingSquadRoute, 0x2000)
		ADD_VAR(::BoolProperty, bAllowRouteReuse, 0x1000)
		ADD_VAR(::BoolProperty, bNeedDelayedLeaveVehicle, 0x800)
		ADD_VAR(::BoolProperty, bEnemyAcquired, 0x400)
		ADD_VAR(::BoolProperty, bInDodgeMove, 0x200)
		ADD_VAR(::BoolProperty, bPlannedJump, 0x100)
		ADD_VAR(::BoolProperty, bJumpOverWall, 0x80)
		ADD_VAR(::BoolProperty, bLeadTarget, 0x40)
		ADD_VAR(::BoolProperty, bEnemyIsVisible, 0x20)
		ADD_VAR(::BoolProperty, bEnemyInfoValid, 0x10)
		ADD_VAR(::BoolProperty, bTargetAlternateLoc, 0x8)
		ADD_VAR(::BoolProperty, bForceRefreshRoute, 0x4)
		ADD_VAR(::BoolProperty, bScriptSpecialJumpCost, 0x2)
		ADD_VAR(::BoolProperty, bExecutingWhatToDoNext, 0x1)
		ADD_OBJECT(Actor, TemporaryFocus)
		ADD_OBJECT(UDKSquadAI, Squad)
		class Actor* FaceActor(float StrafingModifier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FaceActor");
			byte* params = (byte*)malloc(8);
			*(float*)params = StrafingModifier;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		void ExecuteWhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.ExecuteWhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveRunOverWarning(class UDKVehicle* V, float projSpeed, Vector VehicleDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.ReceiveRunOverWarning");
			byte* params = (byte*)malloc(20);
			*(class UDKVehicle**)params = V;
			*(float*)(params + 4) = projSpeed;
			*(Vector*)(params + 8) = VehicleDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* FindBestInventoryPath(float& MinWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindBestInventoryPath");
			byte* params = (byte*)malloc(8);
			*(float*)params = MinWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MinWeight = *(float*)params;
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* FindPathToSquadRoute(bool bWeightDetours)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindPathToSquadRoute");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bWeightDetours;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		void BuildSquadRoute()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.BuildSquadRoute");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* FindBestSuperPickup(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.FindBestSuperPickup");
			byte* params = (byte*)malloc(8);
			*(float*)params = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(12);
			*(float*)params = RequiredJumpZ;
			*(float*)(params + 4) = Cost;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Cost = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float SuperDesireability(class PickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.SuperDesireability");
			byte* params = (byte*)malloc(8);
			*(class PickupFactory**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float AdjustAimError(float TargetDist, bool bInstantProj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKBot.AdjustAimError");
			byte* params = (byte*)malloc(12);
			*(float*)params = TargetDist;
			*(bool*)(params + 4) = bInstantProj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
