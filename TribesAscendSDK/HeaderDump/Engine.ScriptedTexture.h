#pragma once
#include "Engine.TextureRenderTarget2D.h"
#include "Engine.Canvas.h"
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
namespace UnrealScript
{
	class ScriptedTexture : public TextureRenderTarget2D
	{
	public:
		ADD_BOOL(bSkipNextClear, 276, 0x2)
		ADD_BOOL(bNeedsUpdate, 276, 0x1)
		void Render(class Canvas* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25527);
			byte params[4] = { NULL };
			*(class Canvas**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
