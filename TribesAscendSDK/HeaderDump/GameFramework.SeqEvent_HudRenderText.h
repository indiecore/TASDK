#pragma once
#include "Engine.HUD.h"
#include "GameFramework.SeqEvent_HudRender.h"
#include "Engine.Font.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_HudRenderText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqEvent_HudRenderText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqEvent_HudRenderText." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_HudRenderText : public SeqEvent_HudRender
	{
	public:
		ADD_VAR(::ByteProperty, TextDrawMethod, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DisplayText, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DisplayLocation, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DisplayColor'!
		ADD_OBJECT(Font, DisplayFont)
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRenderText.Render");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = TargetCanvas;
			*(class HUD**)(params + 4) = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRenderText.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
