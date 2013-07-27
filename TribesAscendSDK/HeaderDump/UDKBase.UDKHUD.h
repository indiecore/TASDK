#pragma once
#include "GameFramework.MobileHUD.h"
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
	class UDKHUD : public MobileHUD
	{
	public:
		ADD_OBJECT(Font, BindTextFont, 1424)
		ADD_OBJECT(Font, ConsoleIconFont, 1420)
		ADD_STRUCT(Canvas::FontRenderInfo, TextRenderInfo, 1380)
		ADD_STRUCT(float, PulseMultiplier, 1376)
		ADD_STRUCT(float, PulseSplit, 1372)
		ADD_STRUCT(float, PulseDuration, 1368)
		ADD_OBJECT(Font, GlowFonts, 1360)
		void DrawGlowText(ScriptString* Text, float X, float Y, float MaxHeightInPixels, float PulseTime, bool bRightJustified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKHUD.DrawGlowText");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(float*)&params[12] = X;
			*(float*)&params[16] = Y;
			*(float*)&params[20] = MaxHeightInPixels;
			*(float*)&params[24] = PulseTime;
			*(bool*)&params[28] = bRightJustified;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TranslateBindToFont(ScriptString* InBindStr, class Font*& DrawFont, ScriptString*& OutBindStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKHUD.TranslateBindToFont");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = InBindStr;
			*(class Font**)&params[12] = DrawFont;
			*(ScriptString**)&params[16] = OutBindStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DrawFont = *(class Font**)&params[12];
			OutBindStr = *(ScriptString**)&params[16];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
