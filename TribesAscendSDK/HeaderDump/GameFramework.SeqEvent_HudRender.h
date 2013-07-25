#pragma once
#include "Engine.Canvas.h"
#include "Engine.SequenceEvent.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_HudRender." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_HudRender : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bIsActive, 0x1)
		ADD_VAR(::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF)
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRender.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRender.Render");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = TargetCanvas;
			*(class HUD**)(params + 4) = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
