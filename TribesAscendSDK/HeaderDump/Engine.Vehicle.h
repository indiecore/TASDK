#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.HUD.h"
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
	class Vehicle : public Pawn
	{
	public:
		ADD_OBJECT(Pawn, Driver, 1144)
		ADD_STRUCT(ScriptArray<Object::Vector>, ExitPositions, 1152)
		ADD_STRUCT(float, TurnTime, 1256)
		ADD_STRUCT(float, VehicleMovingTime, 1252)
		ADD_STRUCT(float, AIMoveCheckTime, 1248)
		ADD_STRUCT(float, OldThrottle, 1244)
		ADD_STRUCT(float, OnlySteeringStartTime, 1240)
		ADD_STRUCT(float, OldSteering, 1236)
		ADD_STRUCT(float, StuckTime, 1232)
		ADD_STRUCT(float, ThrottleTime, 1228)
		ADD_STRUCT(byte, StuckCount, 1224)
		ADD_STRUCT(float, ForceCrushPenetration, 1220)
		ADD_STRUCT(float, MinCrushSpeed, 1216)
		ADD_OBJECT(ScriptClass, CrushedDamageType, 1212)
		ADD_STRUCT(float, MomentumMult, 1208)
		ADD_STRUCT(float, DriverDamageMult, 1204)
		ADD_STRUCT(Object::Vector, TargetLocationAdjustment, 1192)
		ADD_STRUCT(float, Rise, 1188)
		ADD_STRUCT(float, Throttle, 1184)
		ADD_STRUCT(float, Steering, 1180)
		ADD_STRUCT(Object::Vector, ExitOffset, 1168)
		ADD_STRUCT(float, ExitRadius, 1164)
		ADD_BOOL(bDoExtraNetRelevancyTraces, 1148, 0x1000)
		ADD_BOOL(bIgnoreStallZ, 1148, 0x800)
		ADD_BOOL(bRetryPathfindingWithDriver, 1148, 0x400)
		ADD_BOOL(bAvoidReversing, 1148, 0x200)
		ADD_BOOL(bDuckObstacles, 1148, 0x100)
		ADD_BOOL(bScriptedRise, 1148, 0x80)
		ADD_BOOL(bHasHandbrake, 1148, 0x40)
		ADD_BOOL(bFollowLookDir, 1148, 0x20)
		ADD_BOOL(bSeparateTurretFocus, 1148, 0x10)
		ADD_BOOL(bTurnInPlace, 1148, 0x8)
		ADD_BOOL(bAttachDriver, 1148, 0x4)
		ADD_BOOL(bDriverIsVisible, 1148, 0x2)
		ADD_BOOL(bDriving, 1148, 0x1)
		bool DriverLeave(bool bForceLeave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverLeave");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TryToDrive");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxRiseForce()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetMaxRiseForce");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetTargetLocation");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Object::Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverRadiusDamage");
			byte params[40] = { NULL };
			*(float*)&params[0] = DamageAmount;
			*(float*)&params[4] = DamageRadius;
			*(class Controller**)&params[8] = EventInstigator;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HitLocation;
			*(class Actor**)&params[32] = DamageCauser;
			*(float*)&params[36] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CheatGhost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CheatFly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CheatFly");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AnySeatAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverEnter");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PossessedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EntryAnnouncement");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AttachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DetachDriver");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ContinueOnFoot");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetExitRotation(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetExitRotation");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[4];
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetInputs");
			byte params[12] = { NULL };
			*(float*)&params[0] = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverLeft");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PlaceExitingDriver");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.FindAutoExit");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryExitPos(class Pawn* ExitingDriver, Object::Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TryExitPos");
			byte params[24] = { NULL };
			*(class Pawn**)&params[0] = ExitingDriver;
			*(Object::Vector*)&params[4] = ExitPos;
			*(bool*)&params[16] = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void UnPossessed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.UnPossessed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetKillInstigator");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[8];
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustDriverDamage(int& Damage, class Controller* InstigatedBy, Object::Vector HitLocation, Object::Vector& Momentum, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.AdjustDriverDamage");
			byte params[36] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)&params[0];
			Momentum = *(Object::Vector*)&params[20];
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ThrowActiveWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void DriverDied(ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DriverDied");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Object::Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PlayDying");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = DamageType;
			*(Object::Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetDefaultCameraMode");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		void FaceRotation(Object::Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.FaceRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetCollisionDamageInstigator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[0];
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.EncroachingOn");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.PancakeOther");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.CrushedBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetEntryLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.GetEntryLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void SetDriving(bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.SetDriving");
			byte params[4] = { NULL };
			*(bool*)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.DrivingStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDriverTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.NotifyDriverTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ZeroMovementVariables()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Vehicle.ZeroMovementVariables");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
