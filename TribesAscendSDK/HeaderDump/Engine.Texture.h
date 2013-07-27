#pragma once
#include "Core.Object.h"
#include "Engine.Surface.h"
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
namespace UnrealScript
{
	class Texture : public Surface
	{
	public:
		enum TextureCompressionSettings : byte
		{
			TC_Default = 0,
			TC_Normalmap = 1,
			TC_Displacementmap = 2,
			TC_NormalmapAlpha = 3,
			TC_Grayscale = 4,
			TC_HighDynamicRange = 5,
			TC_OneBitAlpha = 6,
			TC_NormalmapUncompressed = 7,
			TC_NormalmapBC5 = 8,
			TC_OneBitMonochrome = 9,
			TC_SimpleLightmapModification = 10,
			TC_VectorDisplacementmap = 11,
			TC_MAX = 12,
		};
		enum EPixelFormat : byte
		{
			PF_Unknown = 0,
			PF_A32B32G32R32F = 1,
			PF_A8R8G8B8 = 2,
			PF_G8 = 3,
			PF_G16 = 4,
			PF_DXT1 = 5,
			PF_DXT3 = 6,
			PF_DXT5 = 7,
			PF_UYVY = 8,
			PF_FloatRGB = 9,
			PF_FloatRGBA = 10,
			PF_DepthStencil = 11,
			PF_ShadowDepth = 12,
			PF_FilteredShadowDepth = 13,
			PF_R32F = 14,
			PF_G16R16 = 15,
			PF_G16R16F = 16,
			PF_G16R16F_FILTER = 17,
			PF_G32R32F = 18,
			PF_A2B10G10R10 = 19,
			PF_A16B16G16R16 = 20,
			PF_D24 = 21,
			PF_R16F = 22,
			PF_R16F_FILTER = 23,
			PF_BC5 = 24,
			PF_V8U8 = 25,
			PF_A1 = 26,
			PF_MAX = 27,
		};
		enum TextureFilter : byte
		{
			TF_Nearest = 0,
			TF_Linear = 1,
			TF_MAX = 2,
		};
		enum TextureAddress : byte
		{
			TA_Wrap = 0,
			TA_Clamp = 1,
			TA_Mirror = 2,
			TA_MAX = 3,
		};
		enum TextureGroup : byte
		{
			TEXTUREGROUP_World = 0,
			TEXTUREGROUP_WorldNormalMap = 1,
			TEXTUREGROUP_WorldSpecular = 2,
			TEXTUREGROUP_Character = 3,
			TEXTUREGROUP_CharacterNormalMap = 4,
			TEXTUREGROUP_CharacterSpecular = 5,
			TEXTUREGROUP_Weapon = 6,
			TEXTUREGROUP_WeaponNormalMap = 7,
			TEXTUREGROUP_WeaponSpecular = 8,
			TEXTUREGROUP_Vehicle = 9,
			TEXTUREGROUP_VehicleNormalMap = 10,
			TEXTUREGROUP_VehicleSpecular = 11,
			TEXTUREGROUP_Cinematic = 12,
			TEXTUREGROUP_Effects = 13,
			TEXTUREGROUP_EffectsNotFiltered = 14,
			TEXTUREGROUP_Skybox = 15,
			TEXTUREGROUP_UI = 16,
			TEXTUREGROUP_Lightmap = 17,
			TEXTUREGROUP_RenderTarget = 18,
			TEXTUREGROUP_MobileFlattened = 19,
			TEXTUREGROUP_ProcBuilding_Face = 20,
			TEXTUREGROUP_ProcBuilding_LightMap = 21,
			TEXTUREGROUP_Shadowmap = 22,
			TEXTUREGROUP_ColorLookupTable = 23,
			TEXTUREGROUP_Terrain_Heightmap = 24,
			TEXTUREGROUP_Terrain_Weightmap = 25,
			TEXTUREGROUP_ImageBasedReflection = 26,
			TEXTUREGROUP_MAX = 27,
		};
		enum TextureMipGenSettings : byte
		{
			TMGS_FromTextureGroup = 0,
			TMGS_SimpleAverage = 1,
			TMGS_Sharpen0 = 2,
			TMGS_Sharpen1 = 3,
			TMGS_Sharpen2 = 4,
			TMGS_Sharpen3 = 5,
			TMGS_Sharpen4 = 6,
			TMGS_Sharpen5 = 7,
			TMGS_Sharpen6 = 8,
			TMGS_Sharpen7 = 9,
			TMGS_Sharpen8 = 10,
			TMGS_Sharpen9 = 11,
			TMGS_Sharpen10 = 12,
			TMGS_NoMipmaps = 13,
			TMGS_LeaveExistingMips = 14,
			TMGS_Blur1 = 15,
			TMGS_Blur2 = 16,
			TMGS_Blur3 = 17,
			TMGS_Blur4 = 18,
			TMGS_Blur5 = 19,
			TMGS_MAX = 20,
		};
		struct TextureGroupContainer
		{
		public:
			ADD_BOOL(TEXTUREGROUP_ImageBasedReflection, 0, 0x4000000)
			ADD_BOOL(TEXTUREGROUP_Terrain_Weightmap, 0, 0x2000000)
			ADD_BOOL(TEXTUREGROUP_Terrain_Heightmap, 0, 0x1000000)
			ADD_BOOL(TEXTUREGROUP_ColorLookupTable, 0, 0x800000)
			ADD_BOOL(TEXTUREGROUP_Shadowmap, 0, 0x400000)
			ADD_BOOL(TEXTUREGROUP_ProcBuilding_LightMap, 0, 0x200000)
			ADD_BOOL(TEXTUREGROUP_ProcBuilding_Face, 0, 0x100000)
			ADD_BOOL(TEXTUREGROUP_MobileFlattened, 0, 0x80000)
			ADD_BOOL(TEXTUREGROUP_RenderTarget, 0, 0x40000)
			ADD_BOOL(TEXTUREGROUP_Lightmap, 0, 0x20000)
			ADD_BOOL(TEXTUREGROUP_UI, 0, 0x10000)
			ADD_BOOL(TEXTUREGROUP_Skybox, 0, 0x8000)
			ADD_BOOL(TEXTUREGROUP_EffectsNotFiltered, 0, 0x4000)
			ADD_BOOL(TEXTUREGROUP_Effects, 0, 0x2000)
			ADD_BOOL(TEXTUREGROUP_Cinematic, 0, 0x1000)
			ADD_BOOL(TEXTUREGROUP_VehicleSpecular, 0, 0x800)
			ADD_BOOL(TEXTUREGROUP_VehicleNormalMap, 0, 0x400)
			ADD_BOOL(TEXTUREGROUP_Vehicle, 0, 0x200)
			ADD_BOOL(TEXTUREGROUP_WeaponSpecular, 0, 0x100)
			ADD_BOOL(TEXTUREGROUP_WeaponNormalMap, 0, 0x80)
			ADD_BOOL(TEXTUREGROUP_Weapon, 0, 0x40)
			ADD_BOOL(TEXTUREGROUP_CharacterSpecular, 0, 0x20)
			ADD_BOOL(TEXTUREGROUP_CharacterNormalMap, 0, 0x10)
			ADD_BOOL(TEXTUREGROUP_Character, 0, 0x8)
			ADD_BOOL(TEXTUREGROUP_WorldSpecular, 0, 0x4)
			ADD_BOOL(TEXTUREGROUP_WorldNormalMap, 0, 0x2)
			ADD_BOOL(TEXTUREGROUP_World, 0, 0x1)
		};
		ADD_STRUCT(int, InternalFormatLODBias, 232)
		ADD_STRUCT(float, AdjustHue, 228)
		ADD_STRUCT(float, AdjustRGBCurve, 224)
		ADD_STRUCT(float, AdjustSaturation, 220)
		ADD_STRUCT(float, AdjustVibrance, 216)
		ADD_STRUCT(float, AdjustBrightnessCurve, 212)
		ADD_STRUCT(float, AdjustBrightness, 208)
		ADD_STRUCT(Object::Guid, LightingGuid, 192)
		ADD_STRUCT(Object::Pointer, Resource, 188)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 176)
		ADD_STRUCT(ScriptString*, SourceFilePath, 164)
		ADD_STRUCT(int, NumCinematicMipLevels, 160)
		ADD_STRUCT(int, CachedCombinedLODBias, 156)
		ADD_STRUCT(int, LODBias, 152)
		ADD_STRUCT(Texture::TextureMipGenSettings, MipGenSettings, 151)
		ADD_STRUCT(Texture::TextureGroup, LODGroup, 150)
		ADD_STRUCT(Texture::TextureFilter, Filter, 149)
		ADD_STRUCT(Texture::TextureCompressionSettings, CompressionSettings, 148)
		ADD_STRUCT(Object::UntypedBulkData_Mirror, SourceArt, 96)
		ADD_STRUCT(float, UnpackMax, 80)
		ADD_STRUCT(float, UnpackMin, 64)
		ADD_BOOL(bUseCinematicMipLevels, 60, 0x20000)
		ADD_BOOL(bAsyncResourceReleaseHasBeenStarted, 60, 0x10000)
		ADD_BOOL(bForcePVRTC4, 60, 0x8000)
		ADD_BOOL(bNoTiling, 60, 0x4000)
		ADD_BOOL(bPreserveBorderA, 60, 0x2000)
		ADD_BOOL(bPreserveBorderB, 60, 0x1000)
		ADD_BOOL(bPreserveBorderG, 60, 0x800)
		ADD_BOOL(bPreserveBorderR, 60, 0x400)
		ADD_BOOL(bDitherMipMapAlpha, 60, 0x200)
		ADD_BOOL(NeverStream, 60, 0x100)
		ADD_BOOL(DeferCompression, 60, 0x80)
		ADD_BOOL(CompressionFullDynamicRange, 60, 0x40)
		ADD_BOOL(CompressionNoMipmaps, 60, 0x20)
		ADD_BOOL(CompressionNone, 60, 0x10)
		ADD_BOOL(CompressionNoAlpha, 60, 0x8)
		ADD_BOOL(bIsSourceArtUncompressed, 60, 0x4)
		ADD_BOOL(RGBE, 60, 0x2)
		ADD_BOOL(SRGB, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
