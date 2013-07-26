#pragma once
#include "Core.Object.Color.h"
#include "Engine.PostProcessVolume.LUTBlender.h"
#include "Engine.Texture.h"
#include "Core.Object.LinearColor.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PostProcessVolume.PostProcessSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PostProcessVolume.PostProcessSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PostProcessVolume.PostProcessSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PostProcessSettings
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LUTBlender>, ColorGradingLUT, 0xFFFFFFFF)
		ADD_OBJECT(Texture, ColorGrading_LookupTable)
		ADD_VAR(::FloatProperty, RimShader_InterpolationDuration, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, RimShader_Color, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scene_InterpolationDuration, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scene_Shadows, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scene_MidTones, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scene_HighLights, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scene_ImageGrainScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scene_TonemapperScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Scene_Colorize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Scene_Desaturation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlur_InterpolationDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlur_CameraTranslationThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlur_CameraRotationThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, MotionBlur_FullMotionBlur, 0x1)
		ADD_VAR(::FloatProperty, MotionBlur_Amount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MotionBlur_MaxVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_InterpolationDuration, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DOF_FocusPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_FocusDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_FocusInnerRadius, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DOF_FocusType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, DOF_ModulateBlurColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_MaxFarBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_MinBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_MaxNearBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_BlurKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_FalloffExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DOF_BlurBloomKernelSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bloom_InterpolationDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bloom_ScreenBlendThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, Bloom_Tint, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bloom_Threshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Bloom_Scale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverrideRimShaderColor, 0x2000)
		ADD_VAR(::BoolProperty, bAllowAmbientOcclusion, 0x1000)
		ADD_VAR(::BoolProperty, bEnableSceneEffect, 0x800)
		ADD_VAR(::BoolProperty, bEnableMotionBlur, 0x400)
		ADD_VAR(::BoolProperty, bEnableDOF, 0x200)
		ADD_VAR(::BoolProperty, bEnableBloom, 0x100)
		ADD_VAR(::BoolProperty, bOverride_RimShader_InterpolationDuration, 0x80)
		ADD_VAR(::BoolProperty, bOverride_RimShader_Color, 0x40)
		ADD_VAR(::BoolProperty, bOverride_Scene_ColorGradingLUT, 0x20)
		ADD_VAR(::BoolProperty, bOverride_Scene_InterpolationDuration, 0x10)
		ADD_VAR(::BoolProperty, bOverride_Scene_Shadows, 0x8)
		ADD_VAR(::BoolProperty, bOverride_Scene_MidTones, 0x4)
		ADD_VAR(::BoolProperty, bOverride_Scene_HighLights, 0x2)
		ADD_VAR(::BoolProperty, bOverride_Scene_ImageGrainScale, 0x1)
		ADD_VAR(::BoolProperty, bOverride_Scene_TonemapperScale, 0x80000000)
		ADD_VAR(::BoolProperty, bOverride_Scene_Colorize, 0x40000000)
		ADD_VAR(::BoolProperty, bOverride_Scene_Desaturation, 0x20000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_InterpolationDuration, 0x10000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_CameraTranslationThreshold, 0x8000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_CameraRotationThreshold, 0x4000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_FullMotionBlur, 0x2000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_Amount, 0x1000000)
		ADD_VAR(::BoolProperty, bOverride_MotionBlur_MaxVelocity, 0x800000)
		ADD_VAR(::BoolProperty, bOverride_DOF_InterpolationDuration, 0x400000)
		ADD_VAR(::BoolProperty, bOverride_DOF_FocusPosition, 0x200000)
		ADD_VAR(::BoolProperty, bOverride_DOF_FocusDistance, 0x100000)
		ADD_VAR(::BoolProperty, bOverride_DOF_FocusInnerRadius, 0x80000)
		ADD_VAR(::BoolProperty, bOverride_DOF_FocusType, 0x40000)
		ADD_VAR(::BoolProperty, bOverride_DOF_ModulateBlurColor, 0x20000)
		ADD_VAR(::BoolProperty, bOverride_DOF_MaxFarBlurAmount, 0x10000)
		ADD_VAR(::BoolProperty, bOverride_DOF_MinBlurAmount, 0x8000)
		ADD_VAR(::BoolProperty, bOverride_DOF_MaxNearBlurAmount, 0x4000)
		ADD_VAR(::BoolProperty, bOverride_DOF_BlurBloomKernelSize, 0x2000)
		ADD_VAR(::BoolProperty, bOverride_DOF_BlurKernelSize, 0x1000)
		ADD_VAR(::BoolProperty, bOverride_DOF_FalloffExponent, 0x800)
		ADD_VAR(::BoolProperty, bOverride_Bloom_InterpolationDuration, 0x400)
		ADD_VAR(::BoolProperty, bOverride_Bloom_ScreenBlendThreshold, 0x200)
		ADD_VAR(::BoolProperty, bOverride_Bloom_Tint, 0x100)
		ADD_VAR(::BoolProperty, bOverride_Bloom_Threshold, 0x80)
		ADD_VAR(::BoolProperty, bOverride_Bloom_Scale, 0x40)
		ADD_VAR(::BoolProperty, bOverride_OverrideRimShaderColor, 0x20)
		ADD_VAR(::BoolProperty, bOverride_AllowAmbientOcclusion, 0x10)
		ADD_VAR(::BoolProperty, bOverride_EnableSceneEffect, 0x8)
		ADD_VAR(::BoolProperty, bOverride_EnableMotionBlur, 0x4)
		ADD_VAR(::BoolProperty, bOverride_EnableDOF, 0x2)
		ADD_VAR(::BoolProperty, bOverride_EnableBloom, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
