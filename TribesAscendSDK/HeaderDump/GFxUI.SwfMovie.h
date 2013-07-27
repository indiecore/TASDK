#pragma once
#include "GFxUI.GFxRawData.h"
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
namespace UnrealScript
{
	class SwfMovie : public GFxRawData
	{
	public:
		enum FlashTextureRescale : byte
		{
			FlashTextureScale_High = 0,
			FlashTextureScale_Low = 1,
			FlashTextureScale_NextLow = 2,
			FlashTextureScale_Mult4 = 3,
			FlashTextureScale_MAX = 4,
		};
		ADD_STRUCT(Object::QWord, ImportTimeStamp, 164)
		ADD_STRUCT(int, RTVideoTextures, 160)
		ADD_STRUCT(int, RTTextures, 156)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 144)
		ADD_STRUCT(ScriptString*, TextureFormat, 132)
		ADD_STRUCT(SwfMovie::FlashTextureRescale, TextureRescale, 128)
		ADD_STRUCT(int, PackTextureSize, 124)
		ADD_STRUCT(ScriptString*, SourceFile, 112)
		ADD_BOOL(bPackTextures, 108, 0x4)
		ADD_BOOL(bSetSRGBOnImportedTextures, 108, 0x2)
		ADD_BOOL(bUsesFontlib, 108, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
