#pragma once
#include "Engine.Texture.h"
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
	class Texture2DDynamic : public Texture
	{
	public:
		ADD_BOOL(bIsResolveTarget, 252, 0x1)
		ADD_STRUCT(int, NumMips, 248)
		ADD_STRUCT(Texture::EPixelFormat, Format, 244)
		ADD_STRUCT(int, SizeY, 240)
		ADD_STRUCT(int, SizeX, 236)
		void Init(int InSizeX, int InSizeY, Texture::EPixelFormat InFormat, bool InIsResolveTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27953);
			byte params[13] = { NULL };
			*(int*)params = InSizeX;
			*(int*)&params[4] = InSizeY;
			*(Texture::EPixelFormat*)&params[8] = InFormat;
			*(bool*)&params[12] = InIsResolveTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2DDynamic* Create(int InSizeX, int InSizeY, Texture::EPixelFormat InFormat, bool InIsResolveTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27958);
			byte params[17] = { NULL };
			*(int*)params = InSizeX;
			*(int*)&params[4] = InSizeY;
			*(Texture::EPixelFormat*)&params[8] = InFormat;
			*(bool*)&params[12] = InIsResolveTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2DDynamic**)&params[16];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
