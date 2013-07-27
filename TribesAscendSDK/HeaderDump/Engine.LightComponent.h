#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.h"
#include "Engine.Brush.h"
#include "Engine.LightFunction.h"
#include "Engine.Texture2D.h"
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
	class LightComponent : public ActorComponent
	{
	public:
		enum EShadowFilterQuality : byte
		{
			SFQ_Low = 0,
			SFQ_Medium = 1,
			SFQ_High = 2,
			SFQ_MAX = 3,
		};
		enum EShadowProjectionTechnique : byte
		{
			ShadowProjTech_Default = 0,
			ShadowProjTech_PCF = 1,
			ShadowProjTech_VSM = 2,
			ShadowProjTech_BPCF_Low = 3,
			ShadowProjTech_BPCF_Medium = 4,
			ShadowProjTech_BPCF_High = 5,
			ShadowProjTech_MAX = 6,
		};
		enum ELightShadowMode : byte
		{
			LightShadow_Normal = 0,
			LightShadow_Modulate = 1,
			LightShadow_ModulateBetter = 2,
			LightShadow_MAX = 3,
		};
		enum ELightAffectsClassification : byte
		{
			LAC_USER_SELECTED = 0,
			LAC_DYNAMIC_AFFECTING = 1,
			LAC_STATIC_AFFECTING = 2,
			LAC_DYNAMIC_AND_STATIC_AFFECTING = 3,
			LAC_MAX = 4,
		};
		class LightingChannelContainer
		{
		public:
			ADD_BOOL(Crowd, 0, 0x4000000)
			ADD_BOOL(Gameplay_4, 0, 0x2000000)
			ADD_BOOL(Gameplay_3, 0, 0x1000000)
			ADD_BOOL(Gameplay_2, 0, 0x800000)
			ADD_BOOL(Gameplay_1, 0, 0x400000)
			ADD_BOOL(Cinematic_10, 0, 0x200000)
			ADD_BOOL(Cinematic_9, 0, 0x100000)
			ADD_BOOL(Cinematic_8, 0, 0x80000)
			ADD_BOOL(Cinematic_7, 0, 0x40000)
			ADD_BOOL(Cinematic_6, 0, 0x20000)
			ADD_BOOL(Cinematic_5, 0, 0x10000)
			ADD_BOOL(Cinematic_4, 0, 0x8000)
			ADD_BOOL(Cinematic_3, 0, 0x4000)
			ADD_BOOL(Cinematic_2, 0, 0x2000)
			ADD_BOOL(Cinematic_1, 0, 0x1000)
			ADD_BOOL(Unnamed_6, 0, 0x800)
			ADD_BOOL(Unnamed_5, 0, 0x400)
			ADD_BOOL(Unnamed_4, 0, 0x200)
			ADD_BOOL(Unnamed_3, 0, 0x100)
			ADD_BOOL(Unnamed_2, 0, 0x80)
			ADD_BOOL(Unnamed_1, 0, 0x40)
			ADD_BOOL(Skybox, 0, 0x20)
			ADD_BOOL(CompositeDynamic, 0, 0x10)
			ADD_BOOL(Dynamic, 0, 0x8)
			ADD_BOOL(Static, 0, 0x4)
			ADD_BOOL(BSP, 0, 0x2)
			ADD_BOOL(bInitialized, 0, 0x1)
		};
		ADD_STRUCT(float, Brightness, 256)
		ADD_STRUCT(Object::Color, LightColor, 260)
		ADD_OBJECT(LightFunction, Function, 264)
		ADD_STRUCT(Object::Pointer, SceneInfo, 88)
		ADD_STRUCT(Object::Matrix, WorldToLight, 96)
		ADD_STRUCT(Object::Matrix, LightToWorld, 160)
		ADD_STRUCT(Object::Guid, LightGuid, 224)
		ADD_STRUCT(Object::Guid, LightmapGuid, 240)
		ADD_STRUCT(float, LightEnv_BouncedLightBrightness, 268)
		ADD_STRUCT(Object::Color, LightEnv_BouncedModulationColor, 272)
		ADD_BOOL(bEnabled, 276, 0x1)
		ADD_BOOL(CastShadows, 276, 0x2)
		ADD_BOOL(CastStaticShadows, 276, 0x4)
		ADD_BOOL(CastDynamicShadows, 276, 0x8)
		ADD_BOOL(bCastCompositeShadow, 276, 0x10)
		ADD_BOOL(bAffectCompositeShadowDirection, 276, 0x20)
		ADD_BOOL(bNonModulatedSelfShadowing, 276, 0x40)
		ADD_BOOL(bSelfShadowOnly, 276, 0x80)
		ADD_BOOL(bAllowPreShadow, 276, 0x100)
		ADD_BOOL(bForceDynamicLight, 276, 0x200)
		ADD_BOOL(UseDirectLightMap, 276, 0x400)
		ADD_BOOL(bHasLightEverBeenBuiltIntoLightMap, 276, 0x800)
		ADD_BOOL(bOnlyAffectSameAndSpecifiedLevels, 276, 0x1000)
		ADD_BOOL(bCanAffectDynamicPrimitivesOutsideDynamicChannel, 276, 0x2000)
		ADD_BOOL(bUseVolumes, 276, 0x4000)
		ADD_BOOL(bRenderLightShafts, 276, 0x8000)
		ADD_BOOL(bUseImageReflectionSpecular, 276, 0x10000)
		ADD_BOOL(bPrecomputedLightingIsValid, 276, 0x20000)
		ADD_BOOL(bExplicitlyAssignedLight, 276, 0x40000)
		ADD_STRUCT(ScriptArray<ScriptName>, OtherLevelsToAffect, 284)
		ADD_STRUCT(LightComponent::LightingChannelContainer, LightingChannels, 296)
		ADD_STRUCT(ScriptArray<class Brush*>, InclusionVolumes, 300)
		ADD_STRUCT(ScriptArray<class Brush*>, ExclusionVolumes, 312)
		ADD_STRUCT(ScriptArray<Object::Pointer>, InclusionConvexVolumes, 324)
		ADD_STRUCT(ScriptArray<Object::Pointer>, ExclusionConvexVolumes, 336)
		ADD_STRUCT(LightComponent::ELightAffectsClassification, LightAffectsClassification, 348)
		ADD_STRUCT(LightComponent::ELightShadowMode, LightShadowMode, 349)
		ADD_STRUCT(Object::LinearColor, ModShadowColor, 352)
		ADD_STRUCT(float, ModShadowFadeoutTime, 368)
		ADD_STRUCT(float, ModShadowFadeoutExponent, 372)
		ADD_STRUCT(int, LightListIndex, 376)
		ADD_STRUCT(LightComponent::EShadowProjectionTechnique, ShadowProjectionTechnique, 380)
		ADD_STRUCT(LightComponent::EShadowFilterQuality, ShadowFilterQuality, 381)
		ADD_STRUCT(int, MinShadowResolution, 384)
		ADD_STRUCT(int, MaxShadowResolution, 388)
		ADD_STRUCT(int, ShadowFadeResolution, 392)
		ADD_STRUCT(float, OcclusionDepthRange, 396)
		ADD_STRUCT(float, BloomScale, 400)
		ADD_STRUCT(float, BloomThreshold, 404)
		ADD_STRUCT(float, BloomScreenBlendThreshold, 408)
		ADD_STRUCT(Object::Color, BloomTint, 412)
		ADD_STRUCT(float, RadialBlurPercent, 416)
		ADD_STRUCT(float, OcclusionMaskDarkness, 420)
		ADD_OBJECT(Texture2D, ReflectionTexture, 424)
		ADD_STRUCT(float, ReflectionScale, 428)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightProperties(float NewBrightness, Object::Color NewLightColor, class LightFunction* NewLightFunction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.SetLightProperties");
			byte params[12] = { NULL };
			*(float*)&params[0] = NewBrightness;
			*(Object::Color*)&params[4] = NewLightColor;
			*(class LightFunction**)&params[8] = NewLightFunction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetOrigin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.GetOrigin");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Vector GetDirection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.GetDirection");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void UpdateColorAndBrightness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.UpdateColorAndBrightness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLightShaftParameters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.UpdateLightShaftParameters");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBloomScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.OnUpdatePropertyBloomScale");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBloomTint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.OnUpdatePropertyBloomTint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyOcclusionMaskDarkness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.OnUpdatePropertyOcclusionMaskDarkness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.OnUpdatePropertyBrightness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.OnUpdatePropertyLightColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
