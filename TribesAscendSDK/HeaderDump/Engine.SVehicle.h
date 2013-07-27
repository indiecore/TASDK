#pragma once
#include "Engine.Vehicle.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "Engine.Pawn.h"
#include "Engine.RB_StayUprightSetup.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.PlayerController.h"
#include "Engine.Teleporter.h"
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
	class SVehicle : public Vehicle
	{
	public:
		struct VehicleState
		{
		public:
			ADD_STRUCT(int, ServerView, 72)
			ADD_BOOL(bServerHandbrake, 68, 0x1)
			ADD_STRUCT(byte, ServerRise, 67)
			ADD_STRUCT(byte, ServerSteering, 66)
			ADD_STRUCT(byte, ServerGas, 65)
			ADD_STRUCT(byte, ServerBrake, 64)
			ADD_STRUCT(Actor::RigidBodyState, RBState, 0)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, Wheels, 1264)
		ADD_STRUCT(float, RadialImpulseScaling, 1540)
		ADD_STRUCT(float, AngErrorAccumulator, 1536)
		ADD_STRUCT(SVehicle::VehicleState, VState, 1456)
		ADD_STRUCT(int, DriverViewYaw, 1452)
		ADD_STRUCT(int, DriverViewPitch, 1448)
		ADD_STRUCT(float, CamDist, 1444)
		ADD_STRUCT(Vector, BaseOffset, 1432)
		ADD_STRUCT(int, NumPoweredWheels, 1428)
		ADD_STRUCT(float, ForwardVel, 1424)
		ADD_STRUCT(float, OutputRise, 1420)
		ADD_STRUCT(float, OutputSteering, 1416)
		ADD_STRUCT(float, OutputGas, 1412)
		ADD_STRUCT(float, OutputBrake, 1408)
		ADD_STRUCT(float, LastCollisionSoundTime, 1404)
		ADD_STRUCT(float, EngineStopOffsetSecs, 1400)
		ADD_STRUCT(float, EngineStartOffsetSecs, 1396)
		ADD_STRUCT(float, LatAngleVolumeMult, 1392)
		ADD_STRUCT(float, SquealLatThreshold, 1388)
		ADD_STRUCT(float, SquealThreshold, 1384)
		ADD_STRUCT(float, CollisionIntervalSecs, 1380)
		ADD_OBJECT(SoundCue, ExitVehicleSound, 1376)
		ADD_OBJECT(SoundCue, EnterVehicleSound, 1372)
		ADD_OBJECT(SoundCue, CollisionSound, 1368)
		ADD_STRUCT(float, UprightStartTime, 1356)
		ADD_STRUCT(float, UprightTime, 1352)
		ADD_STRUCT(float, UprightTorqueStrength, 1348)
		ADD_STRUCT(float, UprightLiftStrength, 1344)
		ADD_STRUCT(float, TimeOffGround, 1340)
		ADD_STRUCT(float, MaxAngularVelocity, 1336)
		ADD_STRUCT(float, MaxSpeed, 1332)
		ADD_STRUCT(float, HeavySuspensionShiftPercent, 1328)
		ADD_OBJECT(RB_ConstraintInstance, StayUprightConstraintInstance, 1324)
		ADD_OBJECT(RB_StayUprightSetup, StayUprightConstraintSetup, 1320)
		ADD_STRUCT(float, StayUprightDamping, 1316)
		ADD_STRUCT(float, StayUprightStiffness, 1312)
		ADD_STRUCT(float, StayUprightPitchResistAngle, 1308)
		ADD_STRUCT(float, StayUprightRollResistAngle, 1304)
		ADD_BOOL(bHoldingDownHandbrake, 1300, 0x1000)
		ADD_BOOL(bOutputHandbrake, 1300, 0x800)
		ADD_BOOL(bIsUprighting, 1300, 0x400)
		ADD_BOOL(bFlipRight, 1300, 0x200)
		ADD_BOOL(bCanFlip, 1300, 0x100)
		ADD_BOOL(bWasChassisTouchingGroundLastTick, 1300, 0x80)
		ADD_BOOL(bChassisTouchingGround, 1300, 0x40)
		ADD_BOOL(bIsInverted, 1300, 0x20)
		ADD_BOOL(bVehicleOnWater, 1300, 0x10)
		ADD_BOOL(bVehicleOnGround, 1300, 0x8)
		ADD_BOOL(bUpdateWheelShapes, 1300, 0x4)
		ADD_BOOL(bUseSuspensionAxis, 1300, 0x2)
		ADD_BOOL(bStayUpright, 1300, 0x1)
		ADD_STRUCT(Vector, InertiaTensorMultiplier, 1288)
		ADD_STRUCT(Vector, COMOffset, 1276)
		void AddForce(Vector Force)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27501);
			byte params[12] = { NULL };
			*(Vector*)params = Force;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddImpulse(Vector Impulse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27503);
			byte params[12] = { NULL };
			*(Vector*)params = Impulse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddTorque(Vector Torque)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27505);
			byte params[12] = { NULL };
			*(Vector*)params = Torque;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSleeping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27507);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetWheelCollision(int WheelNum, bool bCollision)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27509);
			byte params[8] = { NULL };
			*(int*)params = WheelNum;
			*(bool*)&params[4] = bCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27512);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27513);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27519);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27520);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27521);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27522);
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
		void InitVehicleRagdoll(class SkeletalMesh* RagdollMesh, class PhysicsAsset* RagdollPhysAsset, Vector ActorMove, bool bClearAnimTree)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27538);
			byte params[24] = { NULL };
			*(class SkeletalMesh**)params = RagdollMesh;
			*(class PhysicsAsset**)&params[4] = RagdollPhysAsset;
			*(Vector*)&params[8] = ActorMove;
			*(bool*)&params[20] = bClearAnimTree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27543);
			byte params[56] = { NULL };
			*(Vector*)params = NewVelocity;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27548);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27553);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27562);
			byte params[12] = { NULL };
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27565);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasWheelsOnGround()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27568);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StartEngineSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27570);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartEngineSoundTimed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27571);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopEngineSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27572);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopEngineSoundTimed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27573);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehiclePlayEnterSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehiclePlayExitSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27575);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27576);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27577);
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComponent;
			*(Actor::CollisionImpactData*)&params[8] = RigidCollisionData;
			*(int*)&params[44] = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RigidCollisionData = *(Actor::CollisionImpactData*)&params[8];
		}
		void SuspensionHeavyShift(float Delta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27582);
			byte params[4] = { NULL };
			*(float*)params = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27584);
			byte params[4] = { NULL };
			*(class Teleporter**)params = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27586);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void DisplayWheelsDebug(class HUD* HUD, float YL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27593);
			byte params[8] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float HermiteEval(float Slip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27622);
			byte params[8] = { NULL };
			*(float*)params = Slip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27637);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
