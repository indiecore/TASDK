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
		// Here lies the not-yet-implemented method 'SetLinearDriveScale'
		// Here lies the not-yet-implemented method 'SetAngularDriveScale'
		// Here lies the not-yet-implemented method 'GetTotalMassBelowBone'
		// Here lies the not-yet-implemented method 'SetAllBodiesFixed'
		// Here lies the not-yet-implemented method 'SetNamedBodiesFixed'
		// Here lies the not-yet-implemented method 'ForceAllBodiesBelowUnfixed'
		// Here lies the not-yet-implemented method 'SetAllMotorsAngularPositionDrive'
		// Here lies the not-yet-implemented method 'SetAllMotorsAngularVelocityDrive'
		// Here lies the not-yet-implemented method 'SetAllMotorsAngularDriveParams'
		// Here lies the not-yet-implemented method 'SetNamedMotorsAngularPositionDrive'
		// Here lies the not-yet-implemented method 'SetNamedMotorsAngularVelocityDrive'
		// Here lies the not-yet-implemented method 'SetNamedRBBoneSprings'
		// Here lies the not-yet-implemented method 'SetNamedBodiesBlockRigidBody'
		// Here lies the not-yet-implemented method 'SetFullAnimWeightBlockRigidBody'
		// Here lies the not-yet-implemented method 'SetFullAnimWeightBonesFixed'
		// Here lies the not-yet-implemented method 'FindBodyInstance'
		// Here lies the not-yet-implemented method 'FindConstraintInstance'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
