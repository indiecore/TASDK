#pragma once
#include "Core.Object.h"
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
	class EngineTypes : public Object
	{
	public:
		enum EPathFindingError : byte
		{
			PATHERROR_STARTPOLYNOTFOUND = 0,
			PATHERROR_GOALPOLYNOTFOUND = 1,
			PATHERROR_ANCHORPYLONNOTFOUND = 2,
			PATHERROR_NOPATHFOUND = 3,
			PATHERROR_MAX = 4,
		};
		enum EBlendMode : byte
		{
			BLEND_Opaque = 0,
			BLEND_Masked = 1,
			BLEND_Translucent = 2,
			BLEND_Additive = 3,
			BLEND_Modulate = 4,
			BLEND_SoftMasked = 5,
			BLEND_AlphaComposite = 6,
			BLEND_DitheredTranslucent = 7,
			BLEND_MAX = 8,
		};
		enum EMaterialLightingModel : byte
		{
			MLM_Phong = 0,
			MLM_NonDirectional = 1,
			MLM_Unlit = 2,
			MLM_SHPRT = 3,
			MLM_Custom = 4,
			MLM_Anisotropic = 5,
			MLM_MAX = 6,
		};
		enum EMaterialTessellationMode : byte
		{
			MTM_NoTessellation = 0,
			MTM_FlatTessellation = 1,
			MTM_PNTriangles = 2,
			MTM_MAX = 3,
		};
		enum EMobileTextureTransformTarget : byte
		{
			MTTT_BaseTexture = 0,
			MTTT_DetailTexture = 1,
			MTTT_MAX = 2,
		};
		enum EMobileValueSource : byte
		{
			MVS_Constant = 0,
			MVS_VertexColorRed = 1,
			MVS_VertexColorGreen = 2,
			MVS_VertexColorBlue = 3,
			MVS_VertexColorAlpha = 4,
			MVS_BaseTextureRed = 5,
			MVS_BaseTextureGreen = 6,
			MVS_BaseTextureBlue = 7,
			MVS_BaseTextureAlpha = 8,
			MVS_MaskTextureRed = 9,
			MVS_MaskTextureGreen = 10,
			MVS_MaskTextureBlue = 11,
			MVS_MaskTextureAlpha = 12,
			MVS_NormalTextureAlpha = 13,
			MVS_MAX = 14,
		};
		enum EMobileTextureBlendFactorSource : byte
		{
			MTBFS_VertexColor = 0,
			MTBFS_MaskTexture = 1,
			MTBFS_MAX = 2,
		};
		enum EMobileTexCoordsSource : byte
		{
			MTCS_TexCoords0 = 0,
			MTCS_TexCoords1 = 1,
			MTCS_TexCoords2 = 2,
			MTCS_TexCoords3 = 3,
			MTCS_MAX = 4,
		};
		enum EMobileEmissiveColorSource : byte
		{
			MECS_EmissiveTexture = 0,
			MECS_BaseTexture = 1,
			MECS_Constant = 2,
			MECS_MAX = 3,
		};
		enum EMobileEnvironmentBlendMode : byte
		{
			MEBM_Add = 0,
			MEBM_Lerp = 1,
			MEBM_MAX = 2,
		};
		enum EMobileSpecularMask : byte
		{
			MSM_Constant = 0,
			MSM_Luminance = 1,
			MSM_DiffuseRed = 2,
			MSM_DiffuseGreen = 3,
			MSM_DiffuseBlue = 4,
			MSM_DiffuseAlpha = 5,
			MSM_MaskTextureRGB = 6,
			MSM_MAX = 7,
		};
		enum EMobileAmbientOcclusionSource : byte
		{
			MAOS_Disabled = 0,
			MAOS_VertexColorRed = 1,
			MAOS_VertexColorGreen = 2,
			MAOS_VertexColorBlue = 3,
			MAOS_VertexColorAlpha = 4,
			MAOS_MAX = 5,
		};
		enum ELightingBuildQuality : byte
		{
			Quality_Preview = 0,
			Quality_Medium = 1,
			Quality_High = 2,
			Quality_Production = 3,
			Quality_NoGlobalIllumination = 4,
			Quality_MAX = 5,
		};
		struct SubtitleCue
		{
		public:
			ADD_STRUCT(float, Time, 12)
			ADD_STRUCT(ScriptString*, Text, 0)
		};
		struct LocalizedSubtitle
		{
		public:
			ADD_STRUCT(ScriptArray<EngineTypes::SubtitleCue>, Subtitles, 12)
			ADD_BOOL(bManualWordWrap, 24, 0x2)
			ADD_BOOL(bMature, 24, 0x1)
			ADD_STRUCT(ScriptString*, LanguageExt, 0)
		};
		struct LightMapRef
		{
		public:
			ADD_STRUCT(Object::Pointer, Reference, 0)
		};
		struct DominantShadowInfo
		{
		public:
			ADD_STRUCT(int, ShadowMapSizeY, 160)
			ADD_STRUCT(int, ShadowMapSizeX, 156)
			ADD_STRUCT(Object::Box, LightSpaceImportanceBounds, 128)
			ADD_STRUCT(Object::Matrix, LightToWorld, 64)
			ADD_STRUCT(Object::Matrix, WorldToLight, 0)
		};
		struct LightmassLightSettings
		{
		public:
			ADD_STRUCT(float, ShadowExponent, 8)
			ADD_STRUCT(float, IndirectLightingSaturation, 4)
			ADD_STRUCT(float, IndirectLightingScale, 0)
		};
		struct LightmassPointLightSettings : public LightmassLightSettings
		{
		public:
			ADD_STRUCT(float, LightSourceRadius, 12)
		};
		struct LightmassDirectionalLightSettings : public LightmassLightSettings
		{
		public:
			ADD_STRUCT(float, LightSourceAngle, 12)
		};
		struct LightmassPrimitiveSettings
		{
		public:
			ADD_STRUCT(float, FullyOccludedSamplesFraction, 24)
			ADD_STRUCT(float, SpecularBoost, 20)
			ADD_STRUCT(float, DiffuseBoost, 16)
			ADD_STRUCT(float, EmissiveBoost, 12)
			ADD_STRUCT(float, EmissiveLightExplicitInfluenceRadius, 8)
			ADD_STRUCT(float, EmissiveLightFalloffExponent, 4)
			ADD_BOOL(bUseEmissiveForStaticLighting, 0, 0x4)
			ADD_BOOL(bShadowIndirectOnly, 0, 0x2)
			ADD_BOOL(bUseTwoSidedLighting, 0, 0x1)
		};
		struct LightmassDebugOptions
		{
		public:
			ADD_BOOL(bInitialized, 16, 0x1)
			ADD_STRUCT(float, ExecutionTimeDivisor, 12)
			ADD_BOOL(bColorByExecutionTime, 8, 0x800)
			ADD_BOOL(bColorBordersGreen, 8, 0x400)
			ADD_BOOL(bUseRandomColors, 8, 0x200)
			ADD_BOOL(bOnlyCalcDebugTexelMappings, 8, 0x100)
			ADD_BOOL(bDebugPaddings, 8, 0x80)
			ADD_BOOL(bPadMappings, 8, 0x40)
			ADD_BOOL(bDebugMaterials, 8, 0x20)
			ADD_BOOL(bDumpBinaryFiles, 8, 0x10)
			ADD_BOOL(bSortMappings, 8, 0x8)
			ADD_BOOL(bImmediateProcessMappings, 8, 0x4)
			ADD_BOOL(bUseImmediateImport, 8, 0x2)
			ADD_BOOL(bUseDeterministicLighting, 8, 0x1)
			ADD_STRUCT(float, CoplanarTolerance, 4)
			ADD_BOOL(bGatherBSPSurfacesAcrossComponents, 0, 0x4)
			ADD_BOOL(bStatsEnabled, 0, 0x2)
			ADD_BOOL(bDebugMode, 0, 0x1)
		};
		struct SwarmDebugOptions
		{
		public:
			ADD_BOOL(bInitialized, 0, 0x4)
			ADD_BOOL(bForceContentExport, 0, 0x2)
			ADD_BOOL(bDistributionEnabled, 0, 0x1)
		};
		struct RootMotionCurve
		{
		public:
			ADD_STRUCT(float, MaxCurveTime, 24)
			ADD_STRUCT(Object::InterpCurveVector, Curve, 8)
			ADD_STRUCT(ScriptName, AnimName, 0)
		};
		struct PrimitiveMaterialRef
		{
		public:
			ADD_STRUCT(int, MaterialIndex, 4)
		};
		struct MaterialReferenceList
		{
		public:
			ADD_STRUCT(ScriptArray<EngineTypes::PrimitiveMaterialRef>, AffectedMaterialRefs, 4)
			ADD_OBJECT(MaterialInterface, TargetMaterial, 0)
		};
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
