#pragma once
#include "Engine__LightFunction.h"
#include "Engine__ActorComponent.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LightComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LightComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LightComponent : public ActorComponent
	{
	public:
		ADD_VAR(::FloatProperty, Brightness, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightColor'!
		ADD_OBJECT(LightFunction, Function)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SceneInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'WorldToLight'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LightToWorld'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightGuid'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightmapGuid'!
		ADD_VAR(::FloatProperty, LightEnv_BouncedLightBrightness, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightEnv_BouncedModulationColor'!
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::BoolProperty, CastShadows, 0x2)
		ADD_VAR(::BoolProperty, CastStaticShadows, 0x4)
		ADD_VAR(::BoolProperty, CastDynamicShadows, 0x8)
		ADD_VAR(::BoolProperty, bCastCompositeShadow, 0x10)
		ADD_VAR(::BoolProperty, bAffectCompositeShadowDirection, 0x20)
		ADD_VAR(::BoolProperty, bNonModulatedSelfShadowing, 0x40)
		ADD_VAR(::BoolProperty, bSelfShadowOnly, 0x80)
		ADD_VAR(::BoolProperty, bAllowPreShadow, 0x100)
		ADD_VAR(::BoolProperty, bForceDynamicLight, 0x200)
		ADD_VAR(::BoolProperty, UseDirectLightMap, 0x400)
		ADD_VAR(::BoolProperty, bHasLightEverBeenBuiltIntoLightMap, 0x800)
		ADD_VAR(::BoolProperty, bOnlyAffectSameAndSpecifiedLevels, 0x1000)
		ADD_VAR(::BoolProperty, bCanAffectDynamicPrimitivesOutsideDynamicChannel, 0x2000)
		ADD_VAR(::BoolProperty, bUseVolumes, 0x4000)
		ADD_VAR(::BoolProperty, bRenderLightShafts, 0x8000)
		ADD_VAR(::BoolProperty, bUseImageReflectionSpecular, 0x10000)
		ADD_VAR(::BoolProperty, bPrecomputedLightingIsValid, 0x20000)
		ADD_VAR(::BoolProperty, bExplicitlyAssignedLight, 0x40000)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer' for the property named 'LightingChannels'!
		ADD_VAR(::ByteProperty, LightAffectsClassification, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LightShadowMode, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ModShadowColor'!
		ADD_VAR(::FloatProperty, ModShadowFadeoutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ModShadowFadeoutExponent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LightListIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ShadowProjectionTechnique, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ShadowFilterQuality, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinShadowResolution, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxShadowResolution, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ShadowFadeResolution, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OcclusionDepthRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BloomScreenBlendThreshold, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BloomTint'!
		ADD_VAR(::FloatProperty, RadialBlurPercent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OcclusionMaskDarkness, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, ReflectionTexture)
		ADD_VAR(::FloatProperty, ReflectionScale, 0xFFFFFFFF)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLightProperties(float NewBrightness, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* NewLightColor, class LightFunction* NewLightFunction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.SetLightProperties");
			byte* params = (byte*)malloc(12);
			*(float*)params = NewBrightness;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 4) = NewLightColor;
			*(class LightFunction**)(params + 8) = NewLightFunction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetOrigin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.GetOrigin");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector GetDirection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LightComponent.GetDirection");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
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
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
