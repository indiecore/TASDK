#pragma once
#include "UnrealEd.TextureFactory.h"
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
	class ReimportTextureFactory : public TextureFactory
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
		enum Blending : byte
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
		enum LightingModel : byte
		{
			MLM_Phong = 0,
			MLM_NonDirectional = 1,
			MLM_Unlit = 2,
			MLM_Custom = 3,
			MLM_Anisotropic = 4,
			MLM_MAX = 5,
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
		ADD_BOOL(NoCompression, 112, 0x1)
		ADD_BOOL(CompressionNoAlpha, 116, 0x1)
		ADD_STRUCT(ReimportTextureFactory::TextureCompressionSettings, CompressionSettings, 124)
		ADD_BOOL(DeferCompression, 120, 0x1)
		ADD_BOOL(Create Material?, 128, 0x1)
		ADD_BOOL(RGB To Diffuse, 132, 0x1)
		ADD_BOOL(RGB To Emissive, 136, 0x1)
		ADD_BOOL(Alpha To Specular, 140, 0x1)
		ADD_BOOL(Alpha To Emissive, 144, 0x1)
		ADD_BOOL(Alpha To Opacity, 148, 0x1)
		ADD_BOOL(Alpha To Opacity Mask, 152, 0x1)
		ADD_BOOL(Two Sided?, 156, 0x1)
		ADD_STRUCT(ReimportTextureFactory::Blending, Blending, 160)
		ADD_STRUCT(ReimportTextureFactory::LightingModel, Lighting Model, 161)
		ADD_BOOL(FlipBook, 164, 0x1)
		ADD_STRUCT(ReimportTextureFactory::TextureMipGenSettings, MipGenSettings, 192)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
