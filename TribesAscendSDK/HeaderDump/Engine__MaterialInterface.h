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
		// Here lies the not-yet-implemented method 'GetMaterial'
		// Here lies the not-yet-implemented method 'GetPhysicalMaterial'
		// Here lies the not-yet-implemented method 'GetParameterDesc'
		// Here lies the not-yet-implemented method 'GetFontParameterValue'
		// Here lies the not-yet-implemented method 'GetScalarParameterValue'
		// Here lies the not-yet-implemented method 'GetScalarCurveParameterValue'
		// Here lies the not-yet-implemented method 'GetTextureParameterValue'
		// Here lies the not-yet-implemented method 'GetVectorParameterValue'
		// Here lies the not-yet-implemented method 'GetVectorCurveParameterValue'
		// Here lies the not-yet-implemented method 'SetForceMipLevelsToBeResident'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
