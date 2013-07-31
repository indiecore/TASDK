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
		ADD_STRUCT(ScriptArray<Vector>, ExitPositions, 1152)
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
		ADD_STRUCT(Vector, TargetLocationAdjustment, 1192)
		ADD_STRUCT(float, Rise, 1188)
		ADD_STRUCT(float, Throttle, 1184)
		ADD_STRUCT(float, Steering, 1180)
		ADD_STRUCT(Vector, ExitOffset, 1168)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6005);
			byte params[8] = { NULL };
			*(bool*)params = bForceLeave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6008);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27262);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27263);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Suicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27268);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxRiseForce()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27269);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27271);
			byte params[20] = { NULL };
			*(class Actor**)params = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27275);
			byte params[44] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverRadiusDamage(float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27285);
			byte params[40] = { NULL };
			*(float*)params = DamageAmount;
			*(float*)&params[4] = DamageRadius;
			*(class Controller**)&params[8] = EventInstigator;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HitLocation;
			*(class Actor**)&params[32] = DamageCauser;
			*(float*)&params[36] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerChangedTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27294);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27295);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27296);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheatWalk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27297);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27299);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheatFly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27301);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27303);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed_HandleDriver()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27304);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanEnterVehicle(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27306);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AnySeatAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27309);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool DriverEnter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27312);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27316);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EntryAnnouncement(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27319);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27321);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachDriver(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27323);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ContinueOnFoot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27325);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetExitRotation(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27327);
			byte params[16] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[4];
		}
		void SetInputs(float InForward, float InStrafe, float InUp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27335);
			byte params[12] = { NULL };
			*(float*)params = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27339);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool PlaceExitingDriver(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27340);
			byte params[8] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindAutoExit(class Pawn* ExitingDriver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27349);
			byte params[8] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TryExitPos(class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27355);
			byte params[24] = { NULL };
			*(class Pawn**)params = ExitingDriver;
			*(Vector*)&params[4] = ExitPos;
			*(bool*)&params[16] = bMustFindGround;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void UnPossessed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27366);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27367);
			byte params[12] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[8];
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27371);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustDriverDamage(int& Damage, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27379);
			byte params[36] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)&params[20];
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27385);
			byte params[4] = { NULL };
			*(bool*)params = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27387);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void DriverDied(ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27392);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27396);
			byte params[16] = { NULL };
			*(ScriptClass**)params = DamageType;
			*(Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27399);
			byte params[12] = { NULL };
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27402);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27405);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* GetCollisionDamageInstigator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27407);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)params;
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27409);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PancakeOther(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27417);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27419);
			byte params[4] = { NULL };
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetEntryLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27421);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void SetDriving(bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27423);
			byte params[4] = { NULL };
			*(bool*)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27425);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27426);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDriverTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27428);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ZeroMovementVariables()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
