#pragma once
#include "Core.Object.h"
#include "Engine.Surface.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Texture.h"
#include "Engine.EngineTypes.h"
#include "Engine.Material.h"
#include "Engine.Font.h"
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
	class MaterialInterface : public Surface
	{
	public:
		enum EMaterialUsage : byte
		{
			MATUSAGE_SkeletalMesh = 0,
			MATUSAGE_FracturedMeshes = 1,
			MATUSAGE_ParticleSprites = 2,
			MATUSAGE_BeamTrails = 3,
			MATUSAGE_ParticleSubUV = 4,
			MATUSAGE_SpeedTree = 5,
			MATUSAGE_StaticLighting = 6,
			MATUSAGE_GammaCorrection = 7,
			MATUSAGE_LensFlare = 8,
			MATUSAGE_InstancedMeshParticles = 9,
			MATUSAGE_FluidSurface = 10,
			MATUSAGE_Decals = 11,
			MATUSAGE_MaterialEffect = 12,
			MATUSAGE_MorphTargets = 13,
			MATUSAGE_FogVolumes = 14,
			MATUSAGE_RadialBlur = 15,
			MATUSAGE_InstancedMeshes = 16,
			MATUSAGE_SplineMesh = 17,
			MATUSAGE_ScreenDoorFade = 18,
			MATUSAGE_APEXMesh = 19,
			MATUSAGE_Terrain = 20,
			MATUSAGE_Landscape = 21,
			MATUSAGE_MAX = 22,
		};
		struct LightmassMaterialInterfaceSettings
		{
		public:
			ADD_BOOL(bOverrideDistanceFieldPenumbraScale, 24, 0x20)
			ADD_BOOL(bOverrideExportResolutionScale, 24, 0x10)
			ADD_BOOL(bOverrideSpecularBoost, 24, 0x8)
			ADD_BOOL(bOverrideDiffuseBoost, 24, 0x4)
			ADD_BOOL(bOverrideEmissiveBoost, 24, 0x2)
			ADD_BOOL(bOverrideCastShadowAsMasked, 24, 0x1)
			ADD_STRUCT(float, DistanceFieldPenumbraScale, 20)
			ADD_STRUCT(float, ExportResolutionScale, 16)
			ADD_STRUCT(float, SpecularBoost, 12)
			ADD_STRUCT(float, DiffuseBoost, 8)
			ADD_STRUCT(float, EmissiveBoost, 4)
			ADD_BOOL(bCastShadowAsMasked, 0, 0x1)
		};
		ADD_STRUCT(float, MobileSwayMaxAngle, 332)
		ADD_STRUCT(float, MobileSwayFrequencyMultiplier, 328)
		ADD_STRUCT(float, MobileMaxVertexMovementAmplitude, 324)
		ADD_STRUCT(float, MobileVerticalFrequencyMultiplier, 320)
		ADD_STRUCT(float, MobileTangentVertexFrequencyMultiplier, 316)
		ADD_STRUCT(float, SineScaleFrequencyMultipler, 312)
		ADD_STRUCT(float, SineScaleY, 308)
		ADD_STRUCT(float, SineScaleX, 304)
		ADD_STRUCT(float, FixedScaleY, 300)
		ADD_STRUCT(float, FixedScaleX, 296)
		ADD_STRUCT(float, RotateSpeed, 292)
		ADD_STRUCT(float, PannerSpeedY, 288)
		ADD_STRUCT(float, PannerSpeedX, 284)
		ADD_STRUCT(float, TransformCenterY, 280)
		ADD_STRUCT(float, TransformCenterX, 276)
		ADD_STRUCT(Object::LinearColor, DefaultUniformColor, 260)
		ADD_OBJECT(Texture, MobileDetailTexture, 256)
		ADD_OBJECT(Texture, MobileMaskTexture, 252)
		ADD_STRUCT(float, MobileBumpOffsetHeightRatio, 248)
		ADD_STRUCT(float, MobileBumpOffsetReferencePlane, 244)
		ADD_STRUCT(Object::LinearColor, MobileRimLightingColor, 228)
		ADD_STRUCT(float, MobileRimLightingExponent, 224)
		ADD_STRUCT(float, MobileRimLightingStrength, 220)
		ADD_STRUCT(float, MobileEnvironmentFresnelExponent, 216)
		ADD_STRUCT(float, MobileEnvironmentFresnelAmount, 212)
		ADD_STRUCT(Object::LinearColor, MobileEnvironmentColor, 196)
		ADD_STRUCT(float, MobileEnvironmentAmount, 192)
		ADD_OBJECT(Texture, MobileEnvironmentTexture, 188)
		ADD_STRUCT(Object::LinearColor, MobileEmissiveColor, 172)
		ADD_OBJECT(Texture, MobileEmissiveTexture, 168)
		ADD_STRUCT(float, MobileSpecularPower, 164)
		ADD_STRUCT(Object::LinearColor, MobileSpecularColor, 148)
		ADD_OBJECT(Texture, MobileNormalTexture, 144)
		ADD_STRUCT(EngineTypes::EMobileTextureTransformTarget, MobileTextureTransformTarget, 143)
		ADD_STRUCT(EngineTypes::EMobileTextureBlendFactorSource, MobileTextureBlendFactorSource, 142)
		ADD_STRUCT(EngineTypes::EMobileTexCoordsSource, MobileDetailTextureTexCoordsSource, 141)
		ADD_STRUCT(EngineTypes::EMobileTexCoordsSource, MobileMaskTextureTexCoordsSource, 140)
		ADD_STRUCT(EngineTypes::EMobileValueSource, MobileRimLightingMaskSource, 139)
		ADD_STRUCT(EngineTypes::EMobileEnvironmentBlendMode, MobileEnvironmentBlendMode, 138)
		ADD_STRUCT(EngineTypes::EMobileValueSource, MobileEnvironmentMaskSource, 137)
		ADD_STRUCT(EngineTypes::EMobileValueSource, MobileEmissiveMaskSource, 136)
		ADD_STRUCT(EngineTypes::EMobileEmissiveColorSource, MobileEmissiveColorSource, 135)
		ADD_STRUCT(EngineTypes::EMobileSpecularMask, MobileSpecularMask, 134)
		ADD_STRUCT(EngineTypes::EMobileAmbientOcclusionSource, MobileAmbientOcclusionSource, 133)
		ADD_STRUCT(EngineTypes::EMobileTexCoordsSource, MobileBaseTextureTexCoordsSource, 132)
		ADD_OBJECT(Texture, FlattenedTexture, 128)
		ADD_OBJECT(Texture, MobileBaseTexture, 124)
		ADD_BOOL(bUseMobileWaveVertexMovement, 120, 0x400)
		ADD_BOOL(bUseMobileTextureTransform, 120, 0x200)
		ADD_BOOL(bUseMobileVertexColorMultiply, 120, 0x100)
		ADD_BOOL(bUseMobileUniformColorMultiply, 120, 0x80)
		ADD_BOOL(bLockColorBlending, 120, 0x40)
		ADD_BOOL(bUseMobileBumpOffset, 120, 0x20)
		ADD_BOOL(bUseMobilePixelSpecular, 120, 0x10)
		ADD_BOOL(bUseMobileVertexSpecular, 120, 0x8)
		ADD_BOOL(bUseMobileSpecular, 120, 0x4)
		ADD_BOOL(bMobileAllowFog, 120, 0x2)
		ADD_BOOL(bAutoFlattenMobile, 120, 0x1)
		ADD_STRUCT(Object::Guid, LightingGuid, 104)
		ADD_STRUCT(ScriptString*, PreviewMesh, 92)
		ADD_STRUCT(MaterialInterface::LightmassMaterialInterfaceSettings, LightmassSettings, 64)
		ADD_STRUCT(Object::RenderCommandFence_Mirror, ParentRefFence, 60)
		class Material* GetMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14251);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Material**)params;
		}
		class PhysicalMaterial* GetPhysicalMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14253);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PhysicalMaterial**)params;
		}
		bool GetParameterDesc(ScriptName ParameterName, ScriptString*& OutDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14255);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(ScriptString**)&params[8] = OutDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDesc = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool GetFontParameterValue(ScriptName ParameterName, class Font*& OutFontValue, int& OutFontPage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14259);
			byte params[20] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Font**)&params[8] = OutFontValue;
			*(int*)&params[12] = OutFontPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFontValue = *(class Font**)&params[8];
			OutFontPage = *(int*)&params[12];
			return *(bool*)&params[16];
		}
		bool GetScalarParameterValue(ScriptName ParameterName, float& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14264);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(float*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetScalarCurveParameterValue(ScriptName ParameterName, Object::InterpCurveFloat& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14268);
			byte params[28] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::InterpCurveFloat*)&params[8] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(Object::InterpCurveFloat*)&params[8];
			return *(bool*)&params[24];
		}
		bool GetTextureParameterValue(ScriptName ParameterName, class Texture*& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14272);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Texture**)&params[8] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(class Texture**)&params[8];
			return *(bool*)&params[12];
		}
		bool GetVectorParameterValue(ScriptName ParameterName, Object::LinearColor& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14276);
			byte params[28] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::LinearColor*)&params[8] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(Object::LinearColor*)&params[8];
			return *(bool*)&params[24];
		}
		bool GetVectorCurveParameterValue(ScriptName ParameterName, Object::InterpCurveVector& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14280);
			byte params[28] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::InterpCurveVector*)&params[8] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(Object::InterpCurveVector*)&params[8];
			return *(bool*)&params[24];
		}
		void SetForceMipLevelsToBeResident(bool OverrideForceMiplevelsToBeResident, bool bForceMiplevelsToBeResidentValue, float ForceDuration, int CinematicTextureGroups)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14284);
			byte params[16] = { NULL };
			*(bool*)params = OverrideForceMiplevelsToBeResident;
			*(bool*)&params[4] = bForceMiplevelsToBeResidentValue;
			*(float*)&params[8] = ForceDuration;
			*(int*)&params[12] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
