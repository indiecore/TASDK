#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SVehicleSimCar." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SVehicleSimCar." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SVehicleSimCar : public SVehicleSimBase
	{
	public:
		ADD_VAR(::FloatProperty, TimeSinceThrottle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActualSteering, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsDriving, 0x1)
		ADD_VAR(::FloatProperty, StopThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxBrakeTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EngineBrakeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReverseThrottle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SteerSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'MaxSteerAngleCurve'!
		ADD_VAR(::FloatProperty, ChassisTorqueScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
