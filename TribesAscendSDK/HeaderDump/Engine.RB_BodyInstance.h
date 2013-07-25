#pragma once
#include "Core.Object.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.RB_BodySetup.h"
#include "Engine.PhysicsAssetInstance.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_BodyInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.RB_BodyInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RB_BodyInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RB_BodyInstance : public Object
	{
	public:
		ADD_VAR(::FloatProperty, InstanceDampingScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InstanceMassScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ContactReportForceThreshold, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, PhysMaterialOverride)
		ADD_VAR(::FloatProperty, LastEffectPlayedTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CustomGravityFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OverextensionThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoneAngularDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoneAngularSpring, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoneLinearDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoneLinearSpring, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInstanceAlwaysFullAnimWeight, 0x800)
		ADD_VAR(::BoolProperty, bForceUnfixed, 0x400)
		ADD_VAR(::BoolProperty, bPushBody, 0x200)
		ADD_VAR(::BoolProperty, bEnableCollisionResponse, 0x100)
		ADD_VAR(::BoolProperty, bOnlyCollideWithPawns, 0x80)
		ADD_VAR(::BoolProperty, bMakeSpringToBaseCollisionComponent, 0x40)
		ADD_VAR(::BoolProperty, bUseKinActorForBoneSpring, 0x20)
		ADD_VAR(::BoolProperty, bTeleportOnOverextension, 0x10)
		ADD_VAR(::BoolProperty, bNotifyOwnerOnOverextension, 0x8)
		ADD_VAR(::BoolProperty, bDisableOnOverextension, 0x4)
		ADD_VAR(::BoolProperty, bEnableBoneSpringAngular, 0x2)
		ADD_VAR(::BoolProperty, bEnableBoneSpringLinear, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BoneSpringKinActor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BoneSpring'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BodyData'!
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PreviousVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BodyIndex, 0xFFFFFFFF)
		bool IsFixed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.IsFixed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetFixed(bool bNewFixed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetFixed");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewFixed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetBodyMass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetBodyMass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool IsValidBodyInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.IsValidBodyInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class PhysicsAssetInstance* GetPhysicsAssetInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetPhysicsAssetInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicsAssetInstance**)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetUnrealWorldTM()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetUnrealWorldTM");
			byte* params = (byte*)malloc(64);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
			return returnVal;
		}
		Vector GetUnrealWorldVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetUnrealWorldVelocity");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector GetUnrealWorldAngularVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetUnrealWorldAngularVelocity");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector GetUnrealWorldVelocityAtPoint(Vector Point)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.GetUnrealWorldVelocityAtPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Point;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void EnableBoneSpring(bool bInEnableLinear, bool bInEnableAngular, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void*& InBoneTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.EnableBoneSpring");
			byte* params = (byte*)malloc(72);
			*(bool*)params = bInEnableLinear;
			*(bool*)(params + 4) = bInEnableAngular;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16) = InBoneTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InBoneTarget = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16);
			free(params);
		}
		void SetBoneSpringParams(float InLinearSpring, float InLinearDamping, float InAngularSpring, float InAngularDamping)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetBoneSpringParams");
			byte* params = (byte*)malloc(16);
			*(float*)params = InLinearSpring;
			*(float*)(params + 4) = InLinearDamping;
			*(float*)(params + 8) = InAngularSpring;
			*(float*)(params + 12) = InAngularDamping;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBoneSpringTarget(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void*& InBoneTarget, bool bTeleport)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetBoneSpringTarget");
			byte* params = (byte*)malloc(68);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = InBoneTarget;
			*(bool*)(params + 64) = bTeleport;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InBoneTarget = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
		}
		void SetBlockRigidBody(bool bNewBlockRigidBody)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetBlockRigidBody");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBlockRigidBody;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPhysMaterialOverride(class PhysicalMaterial* NewPhysMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetPhysMaterialOverride");
			byte* params = (byte*)malloc(4);
			*(class PhysicalMaterial**)params = NewPhysMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableCollisionResponse(bool bEnableResponse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.EnableCollisionResponse");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnableResponse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetContactReportForceThreshold(float Threshold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.SetContactReportForceThreshold");
			byte* params = (byte*)malloc(4);
			*(float*)params = Threshold;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateMassProperties(class RB_BodySetup* Setup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.UpdateMassProperties");
			byte* params = (byte*)malloc(4);
			*(class RB_BodySetup**)params = Setup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDampingProperties()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_BodyInstance.UpdateDampingProperties");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
