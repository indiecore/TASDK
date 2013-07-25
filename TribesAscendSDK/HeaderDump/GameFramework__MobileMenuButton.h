#pragma once
#include "GameFramework__MobileMenuObject.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "GameFramework__MobileMenuScene.h"
#include "GameFramework__MobilePlayerInput.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'CaptionColor'!
		ADD_VAR(::StrProperty, Caption, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'ImageColor'!
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileMenuObject.UVCoords' for the property named 'ImagesUVs'!
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
