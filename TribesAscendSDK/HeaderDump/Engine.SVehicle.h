#pragma once
#include "Engine.Vehicle.h"
#include "Engine.SVehicle.VehicleState.h"
#include "Engine.SoundCue.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Engine.Pawn.h"
#include "Engine.RB_StayUprightSetup.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "Core.Object.Rotator.h"
#include "Engine.PlayerController.h"
#include "Engine.Actor.CollisionImpactData.h"
#include "Engine.Teleporter.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SVehicle : public Vehicle
	{
	public:
		ADD_VAR(::FloatProperty, RadialImpulseScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngErrorAccumulator, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<VehicleState>, VState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DriverViewYaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DriverViewPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CamDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BaseOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumPoweredWheels, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForwardVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OutputRise, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OutputSteering, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OutputGas, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OutputBrake, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCollisionSoundTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EngineStopOffsetSecs, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EngineStartOffsetSecs, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LatAngleVolumeMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SquealLatThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SquealThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionIntervalSecs, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ExitVehicleSound)
		ADD_OBJECT(SoundCue, EnterVehicleSound)
		ADD_OBJECT(SoundCue, CollisionSound)
		ADD_VAR(::FloatProperty, UprightStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UprightTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UprightTorqueStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UprightLiftStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeOffGround, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAngularVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeavySuspensionShiftPercent, 0xFFFFFFFF)
		ADD_OBJECT(RB_ConstraintInstance, StayUprightConstraintInstance)
		ADD_OBJECT(RB_StayUprightSetup, StayUprightConstraintSetup)
		ADD_VAR(::FloatProperty, StayUprightDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightPitchResistAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightRollResistAngle, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHoldingDownHandbrake, 0x1000)
		ADD_VAR(::BoolProperty, bOutputHandbrake, 0x800)
		ADD_VAR(::BoolProperty, bIsUprighting, 0x400)
		ADD_VAR(::BoolProperty, bFlipRight, 0x200)
		ADD_VAR(::BoolProperty, bCanFlip, 0x100)
		ADD_VAR(::BoolProperty, bWasChassisTouchingGroundLastTick, 0x80)
		ADD_VAR(::BoolProperty, bChassisTouchingGround, 0x40)
		ADD_VAR(::BoolProperty, bIsInverted, 0x20)
		ADD_VAR(::BoolProperty, bVehicleOnWater, 0x10)
		ADD_VAR(::BoolProperty, bVehicleOnGround, 0x8)
		ADD_VAR(::BoolProperty, bUpdateWheelShapes, 0x4)
		ADD_VAR(::BoolProperty, bUseSuspensionAxis, 0x2)
		ADD_VAR(::BoolProperty, bStayUpright, 0x1)
		ADD_STRUCT(::VectorProperty, InertiaTensorMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, COMOffset, 0xFFFFFFFF)
		void AddForce(Vector Force)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddForce");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Force;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddImpulse(Vector Impulse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddImpulse");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Impulse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddTorque(Vector Torque)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddTorque");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Torque;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsSleeping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.IsSleeping");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetWheelCollision(int WheelNum, bool bCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.SetWheelCollision");
			byte* params = (byte*)malloc(8);
			*(int*)params = WheelNum;
			*(bool*)(params + 4) = bCollision;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.TakeRadiusDamage");
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
		void InitVehicleRagdoll(class SkeletalMesh* RagdollMesh, class PhysicsAsset* RagdollPhysAsset, Vector ActorMove, bool bClearAnimTree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.InitVehicleRagdoll");
			byte* params = (byte*)malloc(24);
			*(class SkeletalMesh**)params = RagdollMesh;
			*(class PhysicsAsset**)(params + 4) = RagdollPhysAsset;
			*(Vector*)(params + 8) = ActorMove;
			*(bool*)(params + 20) = bClearAnimTree;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.AddVelocity");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = NewVelocity;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.CalcCamera");
			byte* params = (byte*)malloc(36);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.GetDefaultCameraMode");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TryToDrive(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.TryToDrive");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasWheelsOnGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.HasWheelsOnGround");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
void* OtherComponent, CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.RigidBodyCollision");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComponent;
			*(CollisionImpactData*)(params + 8) = RigidCollisionData;
			*(int*)(params + 44) = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			RigidCollisionData = *(CollisionImpactData*)(params + 8);
			free(params);
		}
		void SuspensionHeavyShift(float Delta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.SuspensionHeavyShift");
			byte* params = (byte*)malloc(4);
			*(float*)params = Delta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.PostTeleport");
			byte* params = (byte*)malloc(4);
			*(class Teleporter**)params = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void DisplayWheelsDebug(class HUD* HUD, float YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.DisplayWheelsDebug");
			byte* params = (byte*)malloc(8);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = YL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float HermiteEval(float Slip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.HermiteEval");
			byte* params = (byte*)malloc(8);
			*(float*)params = Slip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetSVehicleDebug(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& DebugInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SVehicle.GetSVehicleDebug");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = DebugInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DebugInfo = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
