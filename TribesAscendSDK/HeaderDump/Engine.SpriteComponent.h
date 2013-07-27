#pragma once
#include "Engine.Texture2D.h"
#include "Engine.PrimitiveComponent.h"
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
	class SpriteComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(float, VL, 512)
		ADD_STRUCT(float, V, 508)
		ADD_STRUCT(float, UL, 504)
		ADD_STRUCT(float, U, 500)
		ADD_STRUCT(float, ScreenSize, 496)
		ADD_BOOL(bIsScreenSizeScaled, 492, 0x1)
		ADD_OBJECT(Texture2D, Sprite, 488)
		void SetSprite(class Texture2D* NewSprite)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetSprite");
			byte params[4] = { NULL };
			*(class Texture2D**)&params[0] = NewSprite;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUV(int NewU, int NewUL, int NewV, int NewVL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetUV");
			byte params[16] = { NULL };
			*(int*)&params[0] = NewU;
			*(int*)&params[4] = NewUL;
			*(int*)&params[8] = NewV;
			*(int*)&params[12] = NewVL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpriteAndUV(class Texture2D* NewSprite, int NewU, int NewUL, int NewV, int NewVL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetSpriteAndUV");
			byte params[20] = { NULL };
			*(class Texture2D**)&params[0] = NewSprite;
			*(int*)&params[4] = NewU;
			*(int*)&params[8] = NewUL;
			*(int*)&params[12] = NewV;
			*(int*)&params[16] = NewVL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
