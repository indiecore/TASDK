#pragma once
#include "GameFramework__MobileHUD.h"
#include "Engine__Font.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKHUD : public MobileHUD
	{
	public:
		ADD_OBJECT(Font, BindTextFont)
		ADD_OBJECT(Font, ConsoleIconFont)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo' for the property named 'TextRenderInfo'!
		ADD_VAR(::FloatProperty, PulseMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PulseSplit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PulseDuration, 0xFFFFFFFF)
		ADD_OBJECT(Font, GlowFonts)
		void DrawGlowText(ScriptArray<wchar_t> Text, float X, float Y, float MaxHeightInPixels, float PulseTime, bool bRightJustified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKHUD.DrawGlowText");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Text;
			*(float*)(params + 12) = X;
			*(float*)(params + 16) = Y;
			*(float*)(params + 20) = MaxHeightInPixels;
			*(float*)(params + 24) = PulseTime;
			*(bool*)(params + 28) = bRightJustified;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TranslateBindToFont(ScriptArray<wchar_t> InBindStr, class Font*& DrawFont, ScriptArray<wchar_t>& OutBindStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKHUD.TranslateBindToFont");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = InBindStr;
			*(class Font**)(params + 12) = DrawFont;
			*(ScriptArray<wchar_t>*)(params + 16) = OutBindStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DrawFont = *(class Font**)(params + 12);
			OutBindStr = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
