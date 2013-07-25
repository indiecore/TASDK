#pragma once
#include "Engine__RB_BodySetup.h"
#include "Core__Object.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__PhysicsAssetInstance.h"
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
		ADD_STRUCT(::VectorProperty, PreviousVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF
		ADD_VAR(::IntProperty, BodyIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsFixed'
		// Here lies the not-yet-implemented method 'SetFixed'
		// Here lies the not-yet-implemented method 'GetBodyMass'
		// Here lies the not-yet-implemented method 'IsValidBodyInstance'
		// Here lies the not-yet-implemented method 'GetPhysicsAssetInstance'
		// Here lies the not-yet-implemented method 'GetUnrealWorldTM'
		// Here lies the not-yet-implemented method 'GetUnrealWorldVelocity'
		// Here lies the not-yet-implemented method 'GetUnrealWorldAngularVelocity'
		// Here lies the not-yet-implemented method 'GetUnrealWorldVelocityAtPoint'
		// Here lies the not-yet-implemented method 'EnableBoneSpring'
		// Here lies the not-yet-implemented method 'SetBoneSpringParams'
		// Here lies the not-yet-implemented method 'SetBoneSpringTarget'
		// Here lies the not-yet-implemented method 'SetBlockRigidBody'
		// Here lies the not-yet-implemented method 'SetPhysMaterialOverride'
		// Here lies the not-yet-implemented method 'EnableCollisionResponse'
		// Here lies the not-yet-implemented method 'SetContactReportForceThreshold'
		// Here lies the not-yet-implemented method 'UpdateMassProperties'
		// Here lies the not-yet-implemented method 'UpdateDampingProperties'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
