#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SVehicleSimBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SVehicleSimBase : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, WheelLatExtremumValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLatExtremumSlip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLatAsymptoteSlip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLatAsymptoteValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AutoDriveSteer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoDrive, 0x4)
		ADD_VAR(::BoolProperty, bClampedFrictionModel, 0x2)
		ADD_VAR(::BoolProperty, bWheelSpeedOverride, 0x1)
		ADD_VAR(::FloatProperty, WheelInertia, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLongAsymptoteValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLongAsymptoteSlip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLongExtremumValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelLongExtremumSlip, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelSuspensionBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelSuspensionDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WheelSuspensionStiffness, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
