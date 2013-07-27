#pragma once
#include "Core.Object.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.RB_BodySetup.h"
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
	class RB_BodyInstance : public Object
	{
	public:
		ADD_STRUCT(float, InstanceDampingScale, 152)
		ADD_STRUCT(float, InstanceMassScale, 148)
		ADD_STRUCT(float, ContactReportForceThreshold, 144)
		ADD_OBJECT(PhysicalMaterial, PhysMaterialOverride, 140)
		ADD_STRUCT(float, LastEffectPlayedTime, 136)
		ADD_STRUCT(float, CustomGravityFactor, 132)
		ADD_STRUCT(float, OverextensionThreshold, 128)
		ADD_STRUCT(float, BoneAngularDamping, 124)
		ADD_STRUCT(float, BoneAngularSpring, 120)
		ADD_STRUCT(float, BoneLinearDamping, 116)
		ADD_STRUCT(float, BoneLinearSpring, 112)
		ADD_BOOL(bInstanceAlwaysFullAnimWeight, 108, 0x800)
		ADD_BOOL(bForceUnfixed, 108, 0x400)
		ADD_BOOL(bPushBody, 108, 0x200)
		ADD_BOOL(bEnableCollisionResponse, 108, 0x100)
		ADD_BOOL(bOnlyCollideWithPawns, 108, 0x80)
		ADD_BOOL(bMakeSpringToBaseCollisionComponent, 108, 0x40)
		ADD_BOOL(bUseKinActorForBoneSpring, 108, 0x20)
		ADD_BOOL(bTeleportOnOverextension, 108, 0x10)
		ADD_BOOL(bNotifyOwnerOnOverextension, 108, 0x8)
		ADD_BOOL(bDisableOnOverextension, 108, 0x4)
		ADD_BOOL(bEnableBoneSpringAngular, 108, 0x2)
		ADD_BOOL(bEnableBoneSpringLinear, 108, 0x1)
		ADD_STRUCT(Object::Pointer, BoneSpringKinActor, 104)
		ADD_STRUCT(Object::Pointer, BoneSpring, 100)
		ADD_STRUCT(Object::Pointer, BodyData, 96)
		ADD_STRUCT(int, SceneIndex, 92)
		ADD_STRUCT(Vector, PreviousVelocity, 80)
		ADD_STRUCT(Vector, Velocity, 68)
		ADD_STRUCT(int, BodyIndex, 64)
		bool IsFixed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7324);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetFixed(bool bNewFixed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7326);
			byte params[4] = { NULL };
			*(bool*)params = bNewFixed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetBodyMass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19049);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool IsValidBodyInstance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24992);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class PhysicsAssetInstance* GetPhysicsAssetInstance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24994);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicsAssetInstance**)params;
		}
		Object::Matrix GetUnrealWorldTM()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24996);
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)params;
		}
		Vector GetUnrealWorldVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24998);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector GetUnrealWorldAngularVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25000);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector GetUnrealWorldVelocityAtPoint(Vector Point)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25002);
			byte params[24] = { NULL };
			*(Vector*)params = Point;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void EnableBoneSpring(bool bInEnableLinear, bool bInEnableAngular, Object::Matrix& InBoneTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25005);
			byte params[72] = { NULL };
			*(bool*)params = bInEnableLinear;
			*(bool*)&params[4] = bInEnableAngular;
			*(Object::Matrix*)&params[16] = InBoneTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InBoneTarget = *(Object::Matrix*)&params[16];
		}
		void SetBoneSpringParams(float InLinearSpring, float InLinearDamping, float InAngularSpring, float InAngularDamping)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25009);
			byte params[16] = { NULL };
			*(float*)params = InLinearSpring;
			*(float*)&params[4] = InLinearDamping;
			*(float*)&params[8] = InAngularSpring;
			*(float*)&params[12] = InAngularDamping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBoneSpringTarget(Object::Matrix& InBoneTarget, bool bTeleport)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25014);
			byte params[68] = { NULL };
			*(Object::Matrix*)params = InBoneTarget;
			*(bool*)&params[64] = bTeleport;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InBoneTarget = *(Object::Matrix*)params;
		}
		void SetBlockRigidBody(bool bNewBlockRigidBody)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25017);
			byte params[4] = { NULL };
			*(bool*)params = bNewBlockRigidBody;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPhysMaterialOverride(class PhysicalMaterial* NewPhysMaterial)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25019);
			byte params[4] = { NULL };
			*(class PhysicalMaterial**)params = NewPhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableCollisionResponse(bool bEnableResponse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25021);
			byte params[4] = { NULL };
			*(bool*)params = bEnableResponse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetContactReportForceThreshold(float Threshold)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25023);
			byte params[4] = { NULL };
			*(float*)params = Threshold;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateMassProperties(class RB_BodySetup* Setup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25025);
			byte params[4] = { NULL };
			*(class RB_BodySetup**)params = Setup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDampingProperties()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25027);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
