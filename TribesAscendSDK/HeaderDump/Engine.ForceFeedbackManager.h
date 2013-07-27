#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ForceFeedbackManager : public Object
	{
	public:
		ADD_STRUCT(float, ScaleAllWaveformsBy, 76)
		ADD_BOOL(bAllowsForceFeedback, 60, 0x1)
		ADD_OBJECT(Actor, WaveformInstigator, 80)
		ADD_STRUCT(float, ElapsedTime, 72)
		ADD_STRUCT(int, CurrentSample, 68)
		ADD_OBJECT(ForceFeedbackWaveform, FFWaveform, 64)
		ADD_BOOL(bIsPaused, 60, 0x2)
		void PlayForceFeedbackWaveform(class ForceFeedbackWaveform* WaveForm, class Actor* WaveInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15899);
			byte params[8] = { NULL };
			*(class ForceFeedbackWaveform**)params = WaveForm;
			*(class Actor**)&params[4] = WaveInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopForceFeedbackWaveform(class ForceFeedbackWaveform* WaveForm)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15903);
			byte params[4] = { NULL };
			*(class ForceFeedbackWaveform**)params = WaveForm;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PauseWaveform(bool bPause)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15905);
			byte params[4] = { NULL };
			*(bool*)params = bPause;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
