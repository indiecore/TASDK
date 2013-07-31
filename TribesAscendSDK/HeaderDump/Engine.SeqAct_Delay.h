#pragma once
#include "Engine.SeqAct_Latent.h"
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
	class SeqAct_Delay : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(float, RemainingTime, 264)
		ADD_STRUCT(float, LastUpdateTime, 260)
		ADD_STRUCT(float, Duration, 256)
		ADD_STRUCT(float, DefaultDuration, 252)
		ADD_BOOL(bStartWillRestart, 248, 0x2)
		ADD_BOOL(bDelayActive, 248, 0x1)
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25662);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDelayActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25663);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
