#pragma once
#include "Engine.Volume.h"
#include "Engine.SeqAct_Toggle.h"
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
	class PostProcessVolume : public Volume
	{
	public:
		class LUTBlender
		{
		public:
			ADD_STRUCT(ScriptArray<class Texture*>, LUTTextures, 0)
			ADD_STRUCT(ScriptArray<float>, LUTWeights, 12)
		};
		class PostProcessSettings
		{
		public:
			ADD_STRUCT(PostProcessVolume::LUTBlender, ColorGradingLUT, 196)
			ADD_OBJECT(Texture, ColorGrading_LookupTable, 192)
			ADD_STRUCT(float, RimShader_InterpolationDuration, 188)
			ADD_STRUCT(Object::LinearColor, RimShader_Color, 172)
			ADD_STRUCT(float, Scene_InterpolationDuration, 168)
			ADD_STRUCT(Object::Vector, Scene_Shadows, 156)
			ADD_STRUCT(Object::Vector, Scene_MidTones, 144)
			ADD_STRUCT(Object::Vector, Scene_HighLights, 132)
			ADD_STRUCT(float, Scene_ImageGrainScale, 128)
			ADD_STRUCT(float, Scene_TonemapperScale, 124)
			ADD_STRUCT(Object::Vector, Scene_Colorize, 112)
			ADD_STRUCT(float, Scene_Desaturation, 108)
			ADD_STRUCT(float, MotionBlur_InterpolationDuration, 104)
			ADD_STRUCT(float, MotionBlur_CameraTranslationThreshold, 100)
			ADD_STRUCT(float, MotionBlur_CameraRotationThreshold, 96)
			ADD_BOOL(MotionBlur_FullMotionBlur, 92, 0x1)
			ADD_STRUCT(float, MotionBlur_Amount, 88)
			ADD_STRUCT(float, MotionBlur_MaxVelocity, 84)
			ADD_STRUCT(float, DOF_InterpolationDuration, 80)
			ADD_STRUCT(Object::Vector, DOF_FocusPosition, 68)
			ADD_STRUCT(float, DOF_FocusDistance, 64)
			ADD_STRUCT(float, DOF_FocusInnerRadius, 60)
			ADD_STRUCT(DOFEffect::EFocusType, DOF_FocusType, 56)
			ADD_STRUCT(Object::Color, DOF_ModulateBlurColor, 52)
			ADD_STRUCT(float, DOF_MaxFarBlurAmount, 48)
			ADD_STRUCT(float, DOF_MinBlurAmount, 44)
			ADD_STRUCT(float, DOF_MaxNearBlurAmount, 40)
			ADD_STRUCT(float, DOF_BlurKernelSize, 36)
			ADD_STRUCT(float, DOF_FalloffExponent, 32)
			ADD_STRUCT(float, DOF_BlurBloomKernelSize, 28)
			ADD_STRUCT(float, Bloom_InterpolationDuration, 24)
			ADD_STRUCT(float, Bloom_ScreenBlendThreshold, 20)
			ADD_STRUCT(Object::Color, Bloom_Tint, 16)
			ADD_STRUCT(float, Bloom_Threshold, 12)
			ADD_STRUCT(float, Bloom_Scale, 8)
			ADD_BOOL(bOverrideRimShaderColor, 4, 0x2000)
			ADD_BOOL(bAllowAmbientOcclusion, 4, 0x1000)
			ADD_BOOL(bEnableSceneEffect, 4, 0x800)
			ADD_BOOL(bEnableMotionBlur, 4, 0x400)
			ADD_BOOL(bEnableDOF, 4, 0x200)
			ADD_BOOL(bEnableBloom, 4, 0x100)
			ADD_BOOL(bOverride_RimShader_InterpolationDuration, 4, 0x80)
			ADD_BOOL(bOverride_RimShader_Color, 4, 0x40)
			ADD_BOOL(bOverride_Scene_ColorGradingLUT, 4, 0x20)
			ADD_BOOL(bOverride_Scene_InterpolationDuration, 4, 0x10)
			ADD_BOOL(bOverride_Scene_Shadows, 4, 0x8)
			ADD_BOOL(bOverride_Scene_MidTones, 4, 0x4)
			ADD_BOOL(bOverride_Scene_HighLights, 4, 0x2)
			ADD_BOOL(bOverride_Scene_ImageGrainScale, 4, 0x1)
			ADD_BOOL(bOverride_Scene_TonemapperScale, 0, 0x80000000)
			ADD_BOOL(bOverride_Scene_Colorize, 0, 0x40000000)
			ADD_BOOL(bOverride_Scene_Desaturation, 0, 0x20000000)
			ADD_BOOL(bOverride_MotionBlur_InterpolationDuration, 0, 0x10000000)
			ADD_BOOL(bOverride_MotionBlur_CameraTranslationThreshold, 0, 0x8000000)
			ADD_BOOL(bOverride_MotionBlur_CameraRotationThreshold, 0, 0x4000000)
			ADD_BOOL(bOverride_MotionBlur_FullMotionBlur, 0, 0x2000000)
			ADD_BOOL(bOverride_MotionBlur_Amount, 0, 0x1000000)
			ADD_BOOL(bOverride_MotionBlur_MaxVelocity, 0, 0x800000)
			ADD_BOOL(bOverride_DOF_InterpolationDuration, 0, 0x400000)
			ADD_BOOL(bOverride_DOF_FocusPosition, 0, 0x200000)
			ADD_BOOL(bOverride_DOF_FocusDistance, 0, 0x100000)
			ADD_BOOL(bOverride_DOF_FocusInnerRadius, 0, 0x80000)
			ADD_BOOL(bOverride_DOF_FocusType, 0, 0x40000)
			ADD_BOOL(bOverride_DOF_ModulateBlurColor, 0, 0x20000)
			ADD_BOOL(bOverride_DOF_MaxFarBlurAmount, 0, 0x10000)
			ADD_BOOL(bOverride_DOF_MinBlurAmount, 0, 0x8000)
			ADD_BOOL(bOverride_DOF_MaxNearBlurAmount, 0, 0x4000)
			ADD_BOOL(bOverride_DOF_BlurBloomKernelSize, 0, 0x2000)
			ADD_BOOL(bOverride_DOF_BlurKernelSize, 0, 0x1000)
			ADD_BOOL(bOverride_DOF_FalloffExponent, 0, 0x800)
			ADD_BOOL(bOverride_Bloom_InterpolationDuration, 0, 0x400)
			ADD_BOOL(bOverride_Bloom_ScreenBlendThreshold, 0, 0x200)
			ADD_BOOL(bOverride_Bloom_Tint, 0, 0x100)
			ADD_BOOL(bOverride_Bloom_Threshold, 0, 0x80)
			ADD_BOOL(bOverride_Bloom_Scale, 0, 0x40)
			ADD_BOOL(bOverride_OverrideRimShaderColor, 0, 0x20)
			ADD_BOOL(bOverride_AllowAmbientOcclusion, 0, 0x10)
			ADD_BOOL(bOverride_EnableSceneEffect, 0, 0x8)
			ADD_BOOL(bOverride_EnableMotionBlur, 0, 0x4)
			ADD_BOOL(bOverride_EnableDOF, 0, 0x2)
			ADD_BOOL(bOverride_EnableBloom, 0, 0x1)
		};
		ADD_BOOL(bEnabled, 748, 0x1)
		ADD_OBJECT(PostProcessVolume, NextLowerPriorityVolume, 744)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, Settings, 524)
		ADD_STRUCT(float, Priority, 520)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PostProcessVolume.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
