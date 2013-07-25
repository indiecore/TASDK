#pragma once
#include "Engine__RB_ConstraintInstance.h"
#include "Engine__Vehicle.h"
#include "Engine__SoundCue.h"
#include "Engine__RB_StayUprightSetup.h"
#include "Engine__Controller.h"
#include "Engine__Actor.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__PlayerController.h"
#include "Engine__Teleporter.h"
#include "Engine__Pawn.h"
#include "Engine__HUD.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.SVehicle.VehicleState' for the property named 'VState'!
		ADD_VAR(::IntProperty, DriverViewYaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DriverViewPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CamDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BaseOffset, 0xFFFFFFFF
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
		ADD_STRUCT(::VectorProperty, InertiaTensorMultiplier, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, COMOffset, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'AddForce'
		// Here lies the not-yet-implemented method 'AddImpulse'
		// Here lies the not-yet-implemented method 'AddTorque'
		// Here lies the not-yet-implemented method 'IsSleeping'
		// Here lies the not-yet-implemented method 'SetWheelCollision'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'TurnOff'
		// Here lies the not-yet-implemented method 'StopVehicleSounds'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'InitVehicleRagdoll'
		// Here lies the not-yet-implemented method 'AddVelocity'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'GetDefaultCameraMode'
		// Here lies the not-yet-implemented method 'TryToDrive'
		// Here lies the not-yet-implemented method 'HasWheelsOnGround'
		// Here lies the not-yet-implemented method 'StartEngineSound'
		// Here lies the not-yet-implemented method 'StartEngineSoundTimed'
		// Here lies the not-yet-implemented method 'StopEngineSound'
		// Here lies the not-yet-implemented method 'StopEngineSoundTimed'
		// Here lies the not-yet-implemented method 'VehiclePlayEnterSound'
		// Here lies the not-yet-implemented method 'VehiclePlayExitSound'
		// Here lies the not-yet-implemented method 'DrivingStatusChanged'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'SuspensionHeavyShift'
		// Here lies the not-yet-implemented method 'PostTeleport'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'DisplayWheelsDebug'
		// Here lies the not-yet-implemented method 'HermiteEval'
		// Here lies the not-yet-implemented method 'GetSVehicleDebug'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
