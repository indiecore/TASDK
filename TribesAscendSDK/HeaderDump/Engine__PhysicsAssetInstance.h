#pragma once
#include "Core__Object.h"
#include "Engine__RB_BodyInstance.h"
#include "Engine__Actor.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__RB_ConstraintInstance.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PhysicsAssetInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PhysicsAssetInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PhysicsAssetInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PhysicsAssetInstance : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bInitBodies, 0x1)
		ADD_VAR(::FloatProperty, AngularForceLimitScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularDampingScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AngularSpringScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearForceLimitScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDampingScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearSpringScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'CollisionDisableTable'!
		ADD_VAR(::IntProperty, RootBodyIndex, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Owner)
		void SetLinearDriveScale(float InLinearSpringScale, float InLinearDampingScale, float InLinearForceLimitScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetLinearDriveScale");
			byte* params = (byte*)malloc(12);
			*(float*)params = InLinearSpringScale;
			*(float*)(params + 4) = InLinearDampingScale;
			*(float*)(params + 8) = InLinearForceLimitScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAngularDriveScale(float InAngularSpringScale, float InAngularDampingScale, float InAngularForceLimitScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetAngularDriveScale");
			byte* params = (byte*)malloc(12);
			*(float*)params = InAngularSpringScale;
			*(float*)(params + 4) = InAngularDampingScale;
			*(float*)(params + 8) = InAngularForceLimitScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetTotalMassBelowBone(ScriptName InBoneName, class PhysicsAsset* InAsset, class SkeletalMesh* InSkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.GetTotalMassBelowBone");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = InBoneName;
			*(class PhysicsAsset**)(params + 8) = InAsset;
			*(class SkeletalMesh**)(params + 12) = InSkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetAllBodiesFixed(bool bNewFixed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetAllBodiesFixed");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewFixed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNamedBodiesFixed(bool bNewFixed, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSetOtherBodiesToComplement, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetNamedBodiesFixed");
			byte* params = (byte*)malloc(28);
			*(bool*)params = bNewFixed;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = SkelMesh;
			*(bool*)(params + 20) = bSetOtherBodiesToComplement;
			*(bool*)(params + 24) = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceAllBodiesBelowUnfixed(ScriptName& InBoneName, class PhysicsAsset* InAsset, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InSkelMesh, bool InbInstanceAlwaysFullAnimWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.ForceAllBodiesBelowUnfixed");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = InBoneName;
			*(class PhysicsAsset**)(params + 8) = InAsset;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 12) = InSkelMesh;
			*(bool*)(params + 16) = InbInstanceAlwaysFullAnimWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InBoneName = *(ScriptName*)params;
			free(params);
		}
		void SetAllMotorsAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetAllMotorsAngularPositionDrive");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8) = SkelMesh;
			*(bool*)(params + 12) = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAllMotorsAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetAllMotorsAngularVelocityDrive");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8) = SkelMeshComp;
			*(bool*)(params + 12) = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAllMotorsAngularDriveParams(float InSpring, float InDamping, float InForceLimit, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetAllMotorsAngularDriveParams");
			byte* params = (byte*)malloc(20);
			*(float*)params = InSpring;
			*(float*)(params + 4) = InDamping;
			*(float*)(params + 8) = InForceLimit;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 12) = SkelMesh;
			*(bool*)(params + 16) = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNamedMotorsAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSetOtherBodiesToComplement)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetNamedMotorsAngularPositionDrive");
			byte* params = (byte*)malloc(28);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 20) = SkelMeshComp;
			*(bool*)(params + 24) = bSetOtherBodiesToComplement;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNamedMotorsAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSetOtherBodiesToComplement)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetNamedMotorsAngularVelocityDrive");
			byte* params = (byte*)malloc(28);
			*(bool*)params = bEnableSwingDrive;
			*(bool*)(params + 4) = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 20) = SkelMeshComp;
			*(bool*)(params + 24) = bSetOtherBodiesToComplement;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNamedRBBoneSprings(bool bEnable, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BoneNames, float InBoneLinearSpring, float InBoneAngularSpring, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetNamedRBBoneSprings");
			byte* params = (byte*)malloc(28);
			*(bool*)params = bEnable;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = BoneNames;
			*(float*)(params + 16) = InBoneLinearSpring;
			*(float*)(params + 20) = InBoneAngularSpring;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 24) = SkelMeshComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetNamedBodiesBlockRigidBody(bool bNewBlockRigidBody, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetNamedBodiesBlockRigidBody");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bNewBlockRigidBody;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 16) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFullAnimWeightBlockRigidBody(bool bNewBlockRigidBody, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetFullAnimWeightBlockRigidBody");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bNewBlockRigidBody;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFullAnimWeightBonesFixed(bool bNewFixed, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.SetFullAnimWeightBonesFixed");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bNewFixed;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class RB_BodyInstance* FindBodyInstance(ScriptName BodyName, class PhysicsAsset* InAsset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.FindBodyInstance");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = BodyName;
			*(class PhysicsAsset**)(params + 8) = InAsset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class RB_BodyInstance**)(params + 12);
			free(params);
			return returnVal;
		}
		class RB_ConstraintInstance* FindConstraintInstance(ScriptName ConName, class PhysicsAsset* InAsset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PhysicsAssetInstance.FindConstraintInstance");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ConName;
			*(class PhysicsAsset**)(params + 8) = InAsset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class RB_ConstraintInstance**)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
