#pragma once
#include "Engine.Texture.h"
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
	class TextureCube : public Texture
	{
	public:
		ADD_OBJECT(Texture2D, FaceNegZ, 276)
		ADD_OBJECT(Texture2D, FacePosZ, 272)
		ADD_OBJECT(Texture2D, FaceNegY, 268)
		ADD_OBJECT(Texture2D, FacePosY, 264)
		ADD_OBJECT(Texture2D, FaceNegX, 260)
		ADD_OBJECT(Texture2D, FacePosX, 256)
		ADD_BOOL(bIsCubemapValid, 252, 0x1)
		ADD_STRUCT(int, NumMips, 248)
		ADD_STRUCT(Texture::EPixelFormat, Format, 244)
		ADD_STRUCT(int, SizeY, 240)
		ADD_STRUCT(int, SizeX, 236)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
