#pragma once
#include "Engine.HUD.h"
#include "GameFramework.SeqEvent_HudRender.h"
#include "Core.Object.h"
#include "Engine.Font.h"
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
	class SeqEvent_HudRenderText : public SeqEvent_HudRender
	{
	public:
		enum ETextDrawMethod : byte
		{
			DRAW_CenterText = 0,
			DRAW_WrapText = 1,
			DRAW_MAX = 2,
		};
		ADD_STRUCT(SeqEvent_HudRenderText::ETextDrawMethod, TextDrawMethod, 308)
		ADD_STRUCT(ScriptString*, DisplayText, 296)
		ADD_STRUCT(Object::Vector, DisplayLocation, 284)
		ADD_STRUCT(Object::Color, DisplayColor, 280)
		ADD_OBJECT(Font, DisplayFont, 276)
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRenderText.Render");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = TargetCanvas;
			*(class HUD**)&params[4] = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRenderText.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
