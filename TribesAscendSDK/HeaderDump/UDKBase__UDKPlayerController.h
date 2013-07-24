#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKPlayerController : public GamePlayerController
	{
	public:
		ADD_VAR(::FloatProperty, PulseTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleCheckRadiusScaling, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'PostProcessModifier'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'CamOverridePostProcess'!
		ADD_STRUCT(::RotatorProperty, ShakeRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ShakeOffset, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bUsePhysicsRotation, 0x10)
		ADD_VAR(::BoolProperty, bPulseTeamColor, 0x8)
		ADD_VAR(::BoolProperty, bConsolePlayer, 0x4)
		ADD_VAR(::BoolProperty, bAcuteHearing, 0x2)
		ADD_VAR(::BoolProperty, bDedicatedServerSpectator, 0x1)
		ADD_OBJECT(UDKEmitCameraEffect, CameraEffect)
		ADD_OBJECT(CameraAnimInst, CameraAnimPlayer)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
