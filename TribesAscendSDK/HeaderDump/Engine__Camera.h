#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Camera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Camera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Camera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Camera : public Actor
	{
	public:
		ADD_OBJECT(CameraModifier_CameraShake, CameraShakeCamMod)
		ADD_OBJECT(CameraAnimInst, AnimInstPool)
		ADD_OBJECT(DynamicCameraActor, AnimCameraActor)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TCameraCache' for the property named 'CameraCache'!
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, PCOwner)
		ADD_VAR(::BoolProperty, bLockedFOV, 0x1)
		ADD_VAR(::FloatProperty, LockedFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableColorScaling, 0x8)
		ADD_STRUCT(::VectorProperty, ColorScale, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, OriginalColorScale, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DesiredColorScale, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ColorScaleInterpStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ColorScaleInterpDuration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableColorScaleInterp, 0x10)
		ADD_VAR(::BoolProperty, bConstrainAspectRatio, 0x2)
		ADD_VAR(::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget' for the property named 'PendingViewTarget'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams' for the property named 'BlendParams'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget' for the property named 'ViewTarget'!
		ADD_VAR(::FloatProperty, ConstrainedAspectRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableFading, 0x4)
		ADD_VAR(::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'FadeAlpha'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TCameraCache' for the property named 'LastFrameCameraCache'!
		ADD_STRUCT(::VectorProperty, FreeCamOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, FreeCamDistance, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'CamPostProcessSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FadeColor'!
		ADD_VAR(::FloatProperty, OffAxisPitchAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffAxisYawAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultAspectRatio, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CameraStyle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
