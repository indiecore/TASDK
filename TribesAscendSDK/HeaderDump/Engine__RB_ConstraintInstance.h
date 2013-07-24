#pragma once
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
		ADD_STRUCT(::VectorProperty, AngularVelocityTarget, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat' for the property named 'AngularPositionTarget'!
		ADD_VAR(::FloatProperty, LinearDriveForceLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDriveDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LinearDriveSpring, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinearVelocityTarget, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LinearPositionTarget, 0xFFFFFFFF
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
