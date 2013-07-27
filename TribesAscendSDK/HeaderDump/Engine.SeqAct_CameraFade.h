#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.PlayerController.h"
#include "Core.Object.h"
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
	class SeqAct_CameraFade : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<class PlayerController*>, CachedPCs, 260)
		ADD_STRUCT(float, FadeTimeRemaining, 256)
		ADD_BOOL(bPersistFade, 252, 0x1)
		ADD_STRUCT(float, FadeTime, 248)
		ADD_STRUCT(float, FadeOpacity, 244)
		ADD_STRUCT(Object::Vector2D, FadeAlpha, 236)
		ADD_STRUCT(Object::Color, FadeColor, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_CameraFade.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
