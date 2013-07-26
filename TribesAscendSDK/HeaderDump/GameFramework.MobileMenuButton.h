#pragma once
#include "GameFramework.MobileMenuObject.h"
#include "GameFramework.MobilePlayerInput.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobileMenuObject.UVCoords.h"
#include "Engine.Canvas.h"
#include "GameFramework.MobileMenuScene.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileMenuButton." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobileMenuButton." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuButton." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuButton : public MobileMenuObject
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, CaptionColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Caption, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ImageColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UVCoords>, ImagesUVs, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, Images)
		void InitMenuObject(class MobilePlayerInput* PlayerInput, class MobileMenuScene* Scene, int ScreenWidth, int ScreenHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuButton.InitMenuObject");
			byte* params = (byte*)malloc(16);
			*(class MobilePlayerInput**)params = PlayerInput;
			*(class MobileMenuScene**)(params + 4) = Scene;
			*(int*)(params + 8) = ScreenWidth;
			*(int*)(params + 12) = ScreenHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuButton.RenderObject");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderCaption(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileMenuButton.RenderCaption");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
