#pragma once
#include "Engine.RB_ConstraintSetup.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.PhysicsAssetInstance.h"
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
	class RB_ConstraintInstance : public Object
	{
	public:
		ADD_BOOL(bTerminated, 76, 0x1000)
		ADD_STRUCT(int, ConstraintIndex, 68)
		ADD_STRUCT(Object::Pointer, DummyKinActor, 168)
		ADD_STRUCT(float, AngularDriveForceLimit, 164)
		ADD_STRUCT(float, AngularDriveDamping, 160)
		ADD_STRUCT(float, AngularDriveSpring, 156)
		ADD_STRUCT(Object::Vector, AngularVelocityTarget, 144)
		ADD_STRUCT(Object::Quat, AngularPositionTarget, 128)
		ADD_STRUCT(float, LinearDriveForceLimit, 116)
		ADD_STRUCT(float, LinearDriveDamping, 112)
		ADD_STRUCT(float, LinearDriveSpring, 108)
		ADD_STRUCT(Object::Vector, LinearVelocityTarget, 96)
		ADD_STRUCT(Object::Vector, LinearPositionTarget, 84)
		ADD_STRUCT(Object::Pointer, ConstraintData, 80)
		ADD_BOOL(bAngularSlerpDrive, 76, 0x800)
		ADD_BOOL(bTwistVelocityDrive, 76, 0x400)
		ADD_BOOL(bTwistPositionDrive, 76, 0x200)
		ADD_BOOL(bSwingVelocityDrive, 76, 0x100)
		ADD_BOOL(bSwingPositionDrive, 76, 0x80)
		ADD_BOOL(bLinearZVelocityDrive, 76, 0x40)
		ADD_BOOL(bLinearZPositionDrive, 76, 0x20)
		ADD_BOOL(bLinearYVelocityDrive, 76, 0x10)
		ADD_BOOL(bLinearYPositionDrive, 76, 0x8)
		ADD_BOOL(bLinearXVelocityDrive, 76, 0x4)
		ADD_BOOL(bLinearXPositionDrive, 76, 0x2)
		ADD_BOOL(bInHardware, 76, 0x1)
		ADD_STRUCT(int, SceneIndex, 72)
		ADD_OBJECT(Actor, Owner, 60)
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
			byte params[28] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = PrimComp1;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = PrimComp2;
			*(class RB_ConstraintSetup**)&params[8] = Setup;
			*(float*)&params[12] = Scale;
			*(class Actor**)&params[16] = InOwner;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[20] = InPrimComp;
			*(bool*)&params[24] = bMakeKinForBody1;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PhysicsAssetInstance* GetPhysicsAssetInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.GetPhysicsAssetInstance");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicsAssetInstance**)&params[0];
		}
		Object::Vector GetConstraintLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.GetConstraintLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void SetLinearPositionDrive(bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearPositionDrive");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bEnableXDrive;
			*(bool*)&params[4] = bEnableYDrive;
			*(bool*)&params[8] = bEnableZDrive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLinearVelocityDrive(bool bEnableXDrive, bool bEnableYDrive, bool bEnableZDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearVelocityDrive");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bEnableXDrive;
			*(bool*)&params[4] = bEnableYDrive;
			*(bool*)&params[8] = bEnableZDrive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularPositionDrive");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularVelocityDrive");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLinearPositionTarget(Object::Vector InPosTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearPositionTarget");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = InPosTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLinearVelocityTarget(Object::Vector InVelTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearVelocityTarget");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = InVelTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLinearDriveParams(float InSpring, float InDamping, float InForceLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearDriveParams");
			byte params[12] = { NULL };
			*(float*)&params[0] = InSpring;
			*(float*)&params[4] = InDamping;
			*(float*)&params[8] = InForceLimit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularPositionTarget(Object::Quat& InPosTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularPositionTarget");
			byte params[16] = { NULL };
			*(Object::Quat*)&params[0] = InPosTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InPosTarget = *(Object::Quat*)&params[0];
		}
		void SetAngularVelocityTarget(Object::Vector InVelTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularVelocityTarget");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = InVelTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularDriveParams(float InSpring, float InDamping, float InForceLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularDriveParams");
			byte params[12] = { NULL };
			*(float*)&params[0] = InSpring;
			*(float*)&params[4] = InDamping;
			*(float*)&params[8] = InForceLimit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularDOFLimitScale(float InSwing1LimitScale, float InSwing2LimitScale, float InTwistLimitScale, class RB_ConstraintSetup* InSetup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetAngularDOFLimitScale");
			byte params[16] = { NULL };
			*(float*)&params[0] = InSwing1LimitScale;
			*(float*)&params[4] = InSwing2LimitScale;
			*(float*)&params[8] = InTwistLimitScale;
			*(class RB_ConstraintSetup**)&params[12] = InSetup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLinearLimitSize(float NewLimitSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.SetLinearLimitSize");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewLimitSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveKinActorTransform(Object::Matrix& NewTM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_ConstraintInstance.MoveKinActorTransform");
			byte params[64] = { NULL };
			*(Object::Matrix*)&params[0] = NewTM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewTM = *(Object::Matrix*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
