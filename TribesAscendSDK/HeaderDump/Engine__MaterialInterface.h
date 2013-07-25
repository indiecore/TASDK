#pragma once
#include "Engine__Surface.h"
#include "Engine__Font.h"
#include "Engine__Texture.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Material.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialInterface." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialInterface." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialInterface." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInterface : public Surface
	{
	public:
		ADD_VAR(::FloatProperty, MobileSwayMaxAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileSwayFrequencyMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileMaxVertexMovementAmplitude, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileVerticalFrequencyMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileTangentVertexFrequencyMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SineScaleFrequencyMultipler, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SineScaleY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SineScaleX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FixedScaleY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FixedScaleX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotateSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PannerSpeedY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PannerSpeedX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransformCenterY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransformCenterX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DefaultUniformColor'!
		ADD_OBJECT(Texture, MobileDetailTexture)
		ADD_OBJECT(Texture, MobileMaskTexture)
		ADD_VAR(::FloatProperty, MobileBumpOffsetHeightRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileBumpOffsetReferencePlane, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MobileRimLightingColor'!
		ADD_VAR(::FloatProperty, MobileRimLightingExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileRimLightingStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileEnvironmentFresnelExponent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileEnvironmentFresnelAmount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MobileEnvironmentColor'!
		ADD_VAR(::FloatProperty, MobileEnvironmentAmount, 0xFFFFFFFF)
		ADD_OBJECT(Texture, MobileEnvironmentTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MobileEmissiveColor'!
		ADD_OBJECT(Texture, MobileEmissiveTexture)
		ADD_VAR(::FloatProperty, MobileSpecularPower, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MobileSpecularColor'!
		ADD_OBJECT(Texture, MobileNormalTexture)
		ADD_VAR(::ByteProperty, MobileTextureTransformTarget, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileTextureBlendFactorSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileDetailTextureTexCoordsSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileMaskTextureTexCoordsSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileRimLightingMaskSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileEnvironmentBlendMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileEnvironmentMaskSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileEmissiveMaskSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileEmissiveColorSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileSpecularMask, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileAmbientOcclusionSource, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, MobileBaseTextureTexCoordsSource, 0xFFFFFFFF)
		ADD_OBJECT(Texture, FlattenedTexture)
		ADD_OBJECT(Texture, MobileBaseTexture)
		ADD_VAR(::BoolProperty, bUseMobileWaveVertexMovement, 0x400)
		ADD_VAR(::BoolProperty, bUseMobileTextureTransform, 0x200)
		ADD_VAR(::BoolProperty, bUseMobileVertexColorMultiply, 0x100)
		ADD_VAR(::BoolProperty, bUseMobileUniformColorMultiply, 0x80)
		ADD_VAR(::BoolProperty, bLockColorBlending, 0x40)
		ADD_VAR(::BoolProperty, bUseMobileBumpOffset, 0x20)
		ADD_VAR(::BoolProperty, bUseMobilePixelSpecular, 0x10)
		ADD_VAR(::BoolProperty, bUseMobileVertexSpecular, 0x8)
		ADD_VAR(::BoolProperty, bUseMobileSpecular, 0x4)
		ADD_VAR(::BoolProperty, bMobileAllowFog, 0x2)
		ADD_VAR(::BoolProperty, bAutoFlattenMobile, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightingGuid'!
		ADD_VAR(::StrProperty, PreviewMesh, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialInterface.LightmassMaterialInterfaceSettings' for the property named 'LightmassSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.RenderCommandFence_Mirror' for the property named 'ParentRefFence'!
		class Material* GetMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Material**)params;
			free(params);
			return returnVal;
		}
		class PhysicalMaterial* GetPhysicalMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetPhysicalMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicalMaterial**)params;
			free(params);
			return returnVal;
		}
		bool GetParameterDesc(ScriptName ParameterName, ScriptArray<wchar_t>& OutDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetParameterDesc");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(ScriptArray<wchar_t>*)(params + 8) = OutDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutDesc = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetFontParameterValue(ScriptName ParameterName, class Font*& OutFontValue, int& OutFontPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetFontParameterValue");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ParameterName;
			*(class Font**)(params + 8) = OutFontValue;
			*(int*)(params + 12) = OutFontPage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutFontValue = *(class Font**)(params + 8);
			OutFontPage = *(int*)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetScalarParameterValue(ScriptName ParameterName, float& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetScalarParameterValue");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(float*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetScalarCurveParameterValue(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat'!
void*& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetScalarCurveParameterValue");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat'!
void**)(params + 8) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GetTextureParameterValue(ScriptName ParameterName, class Texture*& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetTextureParameterValue");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(class Texture**)(params + 8) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(class Texture**)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetVectorParameterValue(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void*& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetVectorParameterValue");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GetVectorCurveParameterValue(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector'!
void*& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.GetVectorCurveParameterValue");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector'!
void**)(params + 8) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void SetForceMipLevelsToBeResident(bool OverrideForceMiplevelsToBeResident, bool bForceMiplevelsToBeResidentValue, float ForceDuration, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInterface.SetForceMipLevelsToBeResident");
			byte* params = (byte*)malloc(16);
			*(bool*)params = OverrideForceMiplevelsToBeResident;
			*(bool*)(params + 4) = bForceMiplevelsToBeResidentValue;
			*(float*)(params + 8) = ForceDuration;
			*(int*)(params + 12) = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
