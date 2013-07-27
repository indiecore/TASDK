#pragma once
#include "Engine.Canvas.h"
#include "Engine.SequenceEvent.h"
#include "Core.Object.h"
#include "Engine.HUD.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_HudRender : public SequenceEvent
	{
	public:
		ADD_BOOL(bIsActive, 268, 0x1)
		ADD_STRUCT(ScriptArray<class Object*>, Targets, 256)
		ADD_STRUCT(float, AuthoredGlobalScale, 272)
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRender.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Render(class Canvas* TargetCanvas, class HUD* TargetHud)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_HudRender.Render");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = TargetCanvas;
			*(class HUD**)&params[4] = TargetHud;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
