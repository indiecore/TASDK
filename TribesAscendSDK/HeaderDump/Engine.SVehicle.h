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
		class VehicleState
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
		ADD_STRUCT(Object::Vector, BaseOffset, 1432)
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
		ADD_STRUCT(Object::Vector, InertiaTensorMultiplier, 1288)
		ADD_STRUCT(Object::Vector, COMOffset, 1276)
		void AddForce(Object::Vector Force)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddForce");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Force;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddImpulse(Object::Vector Impulse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddImpulse");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Impulse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddTorque(Object::Vector Torque)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddTorque");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Torque;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSleeping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.IsSleeping");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetWheelCollision(int WheelNum, bool bCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.SetWheelCollision");
			byte params[8] = { NULL };
			*(int*)&params[0] = WheelNum;
			*(bool*)&params[4] = bCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.TurnOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopVehicleSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.StopVehicleSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.TakeRadiusDamage");
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
		void InitVehicleRagdoll(class SkeletalMesh* RagdollMesh, class PhysicsAsset* RagdollPhysAsset, Object::Vector ActorMove, bool bClearAnimTree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.InitVehicleRagdoll");
			byte params[24] = { NULL };
			*(class SkeletalMesh**)&params[0] = RagdollMesh;
			*(class PhysicsAsset**)&params[4] = RagdollPhysAsset;
			*(Object::Vector*)&params[8] = ActorMove;
			*(bool*)&params[20] = bClearAnimTree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVelocity(Object::Vector NewVelocity, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddVelocity");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = NewVelocity;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.GetDefaultCameraMode");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.TryToDrive");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasWheelsOnGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.HasWheelsOnGround");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void StartEngineSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.StartEngineSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartEngineSoundTimed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.StartEngineSoundTimed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopEngineSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.StopEngineSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopEngineSoundTimed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.StopEngineSoundTimed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehiclePlayEnterSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.VehiclePlayEnterSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VehiclePlayExitSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.VehiclePlayExitSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrivingStatusChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.DrivingStatusChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.RigidBodyCollision");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = HitComponent;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.SuspensionHeavyShift");
			byte params[4] = { NULL };
			*(float*)&params[0] = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.PostTeleport");
			byte params[4] = { NULL };
			*(class Teleporter**)&params[0] = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void DisplayWheelsDebug(class HUD* HUD, float YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.DisplayWheelsDebug");
			byte params[8] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float HermiteEval(float Slip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.HermiteEval");
			byte params[8] = { NULL };
			*(float*)&params[0] = Slip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void GetSVehicleDebug(ScriptArray<ScriptString*>& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.GetSVehicleDebug");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DebugInfo = *(ScriptArray<ScriptString*>*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
