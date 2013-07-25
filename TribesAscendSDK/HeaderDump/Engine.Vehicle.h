#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.HUD.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Vehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Vehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Vehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Vehicle : public Pawn
	{
	public:
		ADD_OBJECT(Pawn, Driver)
		ADD_VAR(::FloatProperty, TurnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleMovingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AIMoveCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldThrottle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OnlySteeringStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldSteering, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StuckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ThrottleTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StuckCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceCrushPenetration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinCrushSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, CrushedDamageType)
		ADD_VAR(::FloatProperty, MomentumMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DriverDamageMult, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetLocationAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rise, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Throttle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Steering, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExitOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExitRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDoExtraNetRelevancyTraces, 0x1000)
		ADD_VAR(::BoolProperty, bIgnoreStallZ, 0x800)
		ADD_VAR(::BoolProperty, bRetryPathfindingWithDriver, 0x400)
		ADD_VAR(::BoolProperty, bAvoidReversing, 0x200)
		ADD_VAR(::BoolProperty, bDuckObstacles, 0x100)
		ADD_VAR(::BoolProperty, bScriptedRise, 0x80)
		ADD_VAR(::BoolProperty, bHasHandbrake, 0x40)
		ADD_VAR(::BoolProperty, bFollowLookDir, 0x20)
		ADD_VAR(::BoolProperty, bSeparateTurretFocus, 0x10)
		ADD_VAR(::BoolProperty, bTurnInPlace, 0x8)
		ADD_VAR(::BoolProperty, bAttachDriver, 0x4)
		ADD_VAR(::BoolProperty, bDriverIsVisible, 0x2)
		ADD_VAR(::BoolProperty, bDriving, 0x1)
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverLeave");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TryToDrive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxRiseForce()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetMaxRiseForce");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetTargetLocation");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = RequestedBy;
			*(bool*)(params + 4) = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = InstigatedBy;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverRadiusDamage");
			byte* params = (byte*)malloc(40);
			*(float*)params = DamageAmount;
			*(float*)(params + 4) = DamageRadius;
			*(class Controller**)(params + 8) = EventInstigator;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HitLocation;
			*(class Actor**)(params + 32) = DamageCauser;
			*(float*)(params + 36) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerChangedTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PlayerChangedTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetBaseEyeheight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheatWalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CheatWalk");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CheatGhost");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheatFly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CheatFly");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed_HandleDriver()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Destroyed_HandleDriver");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanEnterVehicle(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CanEnterVehicle");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AnySeatAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverEnter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PossessedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EntryAnnouncement");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AttachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DetachDriver");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ContinueOnFoot");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetExitRotation(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetExitRotation");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetInputs");
			byte* params = (byte*)malloc(12);
			*(float*)params = InForward;
			*(float*)(params + 4) = InStrafe;
			*(float*)(params + 8) = InUp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PlaceExitingDriver");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.FindAutoExit");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryExitPos(class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TryExitPos");
			byte* params = (byte*)malloc(24);
			*(class Pawn**)params = ExitingDriver;
			*(Vector*)(params + 4) = ExitPos;
			*(bool*)(params + 16) = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void UnPossessed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.UnPossessed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetKillInstigator");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = InstigatedBy;
			*(ScriptClass**)(params + 4) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 8);
			free(params);
			return returnVal;
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustDriverDamage(int& Damage, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AdjustDriverDamage");
			byte* params = (byte*)malloc(36);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = InstigatedBy;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)(params + 20);
			free(params);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ThrowActiveWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void DriverDied(ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverDied");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PlayDying");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = DamageType;
			*(Vector*)(params + 4) = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetDefaultCameraMode");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.FaceRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetCollisionDamageInstigator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)params;
			free(params);
			return returnVal;
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PancakeOther");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CrushedBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetEntryLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetEntryLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void SetDriving(bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetDriving");
			byte* params = (byte*)malloc(4);
			*(bool*)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DrivingStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyDriverTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.NotifyDriverTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ZeroMovementVariables()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ZeroMovementVariables");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
