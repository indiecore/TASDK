#pragma once
#include "Engine.Actor.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Core.Object.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.SkeletalMesh.h"
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
	class PhysicsAssetInstance : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class RB_ConstraintInstance*>, Constraints, 80)
		ADD_STRUCT(ScriptArray<class RB_BodyInstance*>, Bodies, 68)
		ADD_BOOL(bInitBodies, 176, 0x1)
		ADD_STRUCT(float, AngularForceLimitScale, 172)
		ADD_STRUCT(float, AngularDampingScale, 168)
		ADD_STRUCT(float, AngularSpringScale, 164)
		ADD_STRUCT(float, LinearForceLimitScale, 160)
		ADD_STRUCT(float, LinearDampingScale, 156)
		ADD_STRUCT(float, LinearSpringScale, 152)
		ADD_STRUCT(Object::Map_Mirror, CollisionDisableTable, 92)
		ADD_STRUCT(int, RootBodyIndex, 64)
		ADD_OBJECT(Actor, Owner, 60)
		void SetLinearDriveScale(float InLinearSpringScale, float InLinearDampingScale, float InLinearForceLimitScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24353);
			byte params[12] = { NULL };
			*(float*)params = InLinearSpringScale;
			*(float*)&params[4] = InLinearDampingScale;
			*(float*)&params[8] = InLinearForceLimitScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAngularDriveScale(float InAngularSpringScale, float InAngularDampingScale, float InAngularForceLimitScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24357);
			byte params[12] = { NULL };
			*(float*)params = InAngularSpringScale;
			*(float*)&params[4] = InAngularDampingScale;
			*(float*)&params[8] = InAngularForceLimitScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetTotalMassBelowBone(ScriptName InBoneName, class PhysicsAsset* InAsset, class SkeletalMesh* InSkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24361);
			byte params[20] = { NULL };
			*(ScriptName*)params = InBoneName;
			*(class PhysicsAsset**)&params[8] = InAsset;
			*(class SkeletalMesh**)&params[12] = InSkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		void SetAllBodiesFixed(bool bNewFixed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24366);
			byte params[4] = { NULL };
			*(bool*)params = bNewFixed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNamedBodiesFixed(bool bNewFixed, ScriptArray<ScriptName> BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSetOtherBodiesToComplement, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24368);
			byte params[28] = { NULL };
			*(bool*)params = bNewFixed;
			*(ScriptArray<ScriptName>*)&params[4] = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelMesh;
			*(bool*)&params[20] = bSetOtherBodiesToComplement;
			*(bool*)&params[24] = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceAllBodiesBelowUnfixed(ScriptName& InBoneName, class PhysicsAsset* InAsset, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InSkelMesh, bool InbInstanceAlwaysFullAnimWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24375);
			byte params[20] = { NULL };
			*(ScriptName*)params = InBoneName;
			*(class PhysicsAsset**)&params[8] = InAsset;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[12] = InSkelMesh;
			*(bool*)&params[16] = InbInstanceAlwaysFullAnimWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InBoneName = *(ScriptName*)params;
		}
		void SetAllMotorsAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24380);
			byte params[16] = { NULL };
			*(bool*)params = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8] = SkelMesh;
			*(bool*)&params[12] = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAllMotorsAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24385);
			byte params[16] = { NULL };
			*(bool*)params = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8] = SkelMeshComp;
			*(bool*)&params[12] = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAllMotorsAngularDriveParams(float InSpring, float InDamping, float InForceLimit, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh, bool bSkipFullAnimWeightBodies)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24390);
			byte params[20] = { NULL };
			*(float*)params = InSpring;
			*(float*)&params[4] = InDamping;
			*(float*)&params[8] = InForceLimit;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[12] = SkelMesh;
			*(bool*)&params[16] = bSkipFullAnimWeightBodies;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNamedMotorsAngularPositionDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, ScriptArray<ScriptName> BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSetOtherBodiesToComplement)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24396);
			byte params[28] = { NULL };
			*(bool*)params = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			*(ScriptArray<ScriptName>*)&params[8] = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[20] = SkelMeshComp;
			*(bool*)&params[24] = bSetOtherBodiesToComplement;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNamedMotorsAngularVelocityDrive(bool bEnableSwingDrive, bool bEnableTwistDrive, ScriptArray<ScriptName> BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, bool bSetOtherBodiesToComplement)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24403);
			byte params[28] = { NULL };
			*(bool*)params = bEnableSwingDrive;
			*(bool*)&params[4] = bEnableTwistDrive;
			*(ScriptArray<ScriptName>*)&params[8] = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[20] = SkelMeshComp;
			*(bool*)&params[24] = bSetOtherBodiesToComplement;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNamedRBBoneSprings(bool bEnable, ScriptArray<ScriptName> BoneNames, float InBoneLinearSpring, float InBoneAngularSpring, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24410);
			byte params[28] = { NULL };
			*(bool*)params = bEnable;
			*(ScriptArray<ScriptName>*)&params[4] = BoneNames;
			*(float*)&params[16] = InBoneLinearSpring;
			*(float*)&params[20] = InBoneAngularSpring;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[24] = SkelMeshComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetNamedBodiesBlockRigidBody(bool bNewBlockRigidBody, ScriptArray<ScriptName> BoneNames, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24417);
			byte params[20] = { NULL };
			*(bool*)params = bNewBlockRigidBody;
			*(ScriptArray<ScriptName>*)&params[4] = BoneNames;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFullAnimWeightBlockRigidBody(bool bNewBlockRigidBody, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24422);
			byte params[8] = { NULL };
			*(bool*)params = bNewBlockRigidBody;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFullAnimWeightBonesFixed(bool bNewFixed, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24425);
			byte params[8] = { NULL };
			*(bool*)params = bNewFixed;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class RB_BodyInstance* FindBodyInstance(ScriptName BodyName, class PhysicsAsset* InAsset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24428);
			byte params[16] = { NULL };
			*(ScriptName*)params = BodyName;
			*(class PhysicsAsset**)&params[8] = InAsset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_BodyInstance**)&params[12];
		}
		class RB_ConstraintInstance* FindConstraintInstance(ScriptName ConName, class PhysicsAsset* InAsset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24432);
			byte params[16] = { NULL };
			*(ScriptName*)params = ConName;
			*(class PhysicsAsset**)&params[8] = InAsset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_ConstraintInstance**)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
