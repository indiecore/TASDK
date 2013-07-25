#pragma once
#include "Core__Object.h"
#include "Engine__Actor.h"
#include "Engine__RB_ConstraintSetup.h"
#include "Engine__PhysicsAssetInstance.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_ConstraintInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RB_ConstraintInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RB_ConstraintInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintInstance : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bTerminated, 0x1000)
		ADD_VAR(::IntProperty, ConstraintIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'DummyKinActor'!
		ADD_VAR(::FloatProperty, AngularDriveForceLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularDriveDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularDriveSpring, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, AngularVelocityTarget, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat' for the property named 'AngularPositionTarget'!
		ADD_VAR(::FloatProperty, LinearDriveForceLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDriveDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDriveSpring, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinearVelocityTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinearPositionTarget, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ConstraintData'!
		ADD_VAR(::BoolProperty, bAngularSlerpDrive, 0x800)
		ADD_VAR(::BoolProperty, bTwistVelocityDrive, 0x400)
		ADD_VAR(::BoolProperty, bTwistPositionDrive, 0x200)
		ADD_VAR(::BoolProperty, bSwingVelocityDrive, 0x100)
		ADD_VAR(::BoolProperty, bSwingPositionDrive, 0x80)
		ADD_VAR(::BoolProperty, bLinearZVelocityDrive, 0x40)
		ADD_VAR(::BoolProperty, bLinearZPositionDrive, 0x20)
		ADD_VAR(::BoolProperty, bLinearYVelocityDrive, 0x10)
		ADD_VAR(::BoolProperty, bLinearYPositionDrive, 0x8)
		ADD_VAR(::BoolProperty, bLinearXVelocityDrive, 0x4)
		ADD_VAR(::BoolProperty, bLinearXPositionDrive, 0x2)
		ADD_VAR(::BoolProperty, bInHardware, 0x1)
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Owner)
		void TermConstraint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.TermConstraint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitConstraint(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PrimComp1, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PrimComp2, class RB_ConstraintSetup* Setup, float Scale, class Actor* InOwner, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InPrimComp, bool bMakeKinForBody1)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.InitConstraint");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PrimComp1;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = PrimComp2;
			*(class RB_ConstraintSetup**)(params + 8) = Setup;
			*(float*)(params + 12) = Scale;
			*(class Actor**)(params + 16) = InOwner;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 20) = InPrimComp;
			*(bool*)(params + 24) = bMakeKinForBody1;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PhysicsAssetInstance* GetPhysicsAssetInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.GetPhysicsAssetInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicsAssetInstance**)params;
			free(params);
			return returnVal;
		}
		Vector GetConstraintLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.GetConstraintLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void SetLinearPositionDrive(bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearPositionDrive");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bEnableXDrive;
			*(bool*)(params + 4) = bEnableYDrive;
			*(bool*)(params + 8) = bEnableZDrive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLinearVelocityDrive(bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearVelocityDrive");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bEnableXDrive;
			*(bool*)(params + 4) = bEnableYDrive;
			*(bool*)(params + 8) = bEnableZDrive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularPositionDrive");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularVelocityDrive");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLinearPositionTarget(Vector InPosTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearPositionTarget");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = InPosTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLinearVelocityTarget(Vector InVelTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearVelocityTarget");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = InVelTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLinearDriveParams(float InSpring, float InDamping, float InForceLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearDriveParams");
			byte* params = (byte*)malloc(12);
			*(float*)params = InSpring;
			*(float*)(params + 4) = InDamping;
			*(float*)(params + 8) = InForceLimit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularPositionTarget(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void*& InPosTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularPositionTarget");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params = InPosTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InPosTarget = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)params;
			free(params);
		}
		void SetAngularVelocityTarget(Vector InVelTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularVelocityTarget");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = InVelTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularDriveParams(float InSpring, float InDamping, float InForceLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularDriveParams");
			byte* params = (byte*)malloc(12);
			*(float*)params = InSpring;
			*(float*)(params + 4) = InDamping;
			*(float*)(params + 8) = InForceLimit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularDOFLimitScale(float InSwing1LimitScale, float InSwing2LimitScale, float InTwistLimitScale, class RB_ConstraintSetup* InSetup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularDOFLimitScale");
			byte* params = (byte*)malloc(16);
			*(float*)params = InSwing1LimitScale;
			*(float*)(params + 4) = InSwing2LimitScale;
			*(float*)(params + 8) = InTwistLimitScale;
			*(class RB_ConstraintSetup**)(params + 12) = InSetup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLinearLimitSize(float NewLimitSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearLimitSize");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewLimitSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveKinActorTransform(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void*& NewTM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.MoveKinActorTransform");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = NewTM;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewTM = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
