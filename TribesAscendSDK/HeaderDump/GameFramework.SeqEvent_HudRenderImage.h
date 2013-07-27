#pragma once
#include "Engine.HUD.h"
#include "GameFramework.SeqEvent_HudRender.h"
#include "Engine.Texture2D.h"
#include "Core.Object.h"
#include "Engine.Canvas.h"
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
	class SeqEvent_HudRenderImage : public SeqEvent_HudRender
	{
	public:
		ADD_STRUCT(float, VL, 328)
		ADD_STRUCT(float, UL, 324)
		ADD_STRUCT(float, V, 320)
		ADD_STRUCT(float, U, 316)
		ADD_STRUCT(float, YL, 312)
		ADD_STRUCT(float, XL, 308)
		ADD_OBJECT(Texture2D, DisplayTexture, 304)
		ADD_STRUCT(Vector, DisplayLocation, 292)
		ADD_STRUCT(Object::LinearColor, DisplayColor, 276)
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32987);
			byte params[8] = { NULL };
			*(class Canvas**)params = TargetCanvas;
			*(class HUD**)&params[4] = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
