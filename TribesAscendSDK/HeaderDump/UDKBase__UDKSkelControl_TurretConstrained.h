#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_TurretConstrained." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_TurretConstrained." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_TurretConstrained : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(::RotatorProperty, ConstrainedBoneRotation, 0xFFFFFFFF
		ADD_VAR(::IntProperty, AssociatedSeatIndex, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, DesiredBoneRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, PitchSpeedScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LagDegreesPerSecond, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKSkelControl_TurretConstrained.TurretConstraintData' for the property named 'MinAngle'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKSkelControl_TurretConstrained.TurretConstraintData' for the property named 'MaxAngle'!
		ADD_VAR(::BoolProperty, bIsInMotion, 0x100)
		ADD_VAR(::BoolProperty, bResetWhenUnattended, 0x80)
		ADD_VAR(::BoolProperty, bFixedWhenFiring, 0x40)
		ADD_VAR(::BoolProperty, bInvertRoll, 0x20)
		ADD_VAR(::BoolProperty, bInvertYaw, 0x10)
		ADD_VAR(::BoolProperty, bInvertPitch, 0x8)
		ADD_VAR(::BoolProperty, bConstrainRoll, 0x4)
		ADD_VAR(::BoolProperty, bConstrainYaw, 0x2)
		ADD_VAR(::BoolProperty, bConstrainPitch, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
