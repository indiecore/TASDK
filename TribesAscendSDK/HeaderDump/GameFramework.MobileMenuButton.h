#pragma once
#include "Core.Object.h"
#include "GameFramework.MobileMenuObject.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobilePlayerInput.h"
#include "Engine.Canvas.h"
#include "GameFramework.MobileMenuScene.h"
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
	class MobileMenuButton : public MobileMenuObject
	{
	public:
		ADD_STRUCT(Object::LinearColor, CaptionColor, 208)
		ADD_STRUCT(ScriptString*, Caption, 196)
		ADD_STRUCT(Object::LinearColor, ImageColor, 180)
		ADD_STRUCT(MobileMenuObject::UVCoords, ImagesUVs, 140)
		ADD_OBJECT(Texture2D, Images, 132)
		void InitMenuObject(class MobilePlayerInput* PlayerInput, class MobileMenuScene* Scene, int ScreenWidth, int ScreenHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32612);
			byte params[16] = { NULL };
			*(class MobilePlayerInput**)params = PlayerInput;
			*(class MobileMenuScene**)&params[4] = Scene;
			*(int*)&params[8] = ScreenWidth;
			*(int*)&params[12] = ScreenHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderObject(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32618);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderCaption(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32625);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
