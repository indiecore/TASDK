#pragma once
#include "Engine.Texture2D.h"
#include "Engine.PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpriteComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SpriteComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpriteComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, VL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, V, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, U, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScreenSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsScreenSizeScaled, 0x1)
		ADD_OBJECT(Texture2D, Sprite)
		void SetSprite(class Texture2D* NewSprite)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetSprite");
			byte* params = (byte*)malloc(4);
			*(class Texture2D**)params = NewSprite;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetUV(int NewU, int NewUL, int NewV, int NewVL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetUV");
			byte* params = (byte*)malloc(16);
			*(int*)params = NewU;
			*(int*)(params + 4) = NewUL;
			*(int*)(params + 8) = NewV;
			*(int*)(params + 12) = NewVL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpriteAndUV(class Texture2D* NewSprite, int NewU, int NewUL, int NewV, int NewVL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpriteComponent.SetSpriteAndUV");
			byte* params = (byte*)malloc(20);
			*(class Texture2D**)params = NewSprite;
			*(int*)(params + 4) = NewU;
			*(int*)(params + 8) = NewUL;
			*(int*)(params + 12) = NewV;
			*(int*)(params + 16) = NewVL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
