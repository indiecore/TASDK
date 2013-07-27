#pragma once
#include "Engine.SeqAct_Latent.h"
#include "Engine.SoundCue.h"
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
	class SeqAct_PlaySound : public SeqAct_Latent
	{
	public:
		ADD_BOOL(bStopped, 276, 0x2)
		ADD_BOOL(bSuppressSubtitles, 276, 0x1)
		ADD_STRUCT(float, PitchMultiplier, 272)
		ADD_STRUCT(float, VolumeMultiplier, 268)
		ADD_STRUCT(float, FadeOutTime, 264)
		ADD_STRUCT(float, FadeInTime, 260)
		ADD_STRUCT(float, SoundDuration, 256)
		ADD_STRUCT(float, ExtraDelay, 252)
		ADD_OBJECT(SoundCue, PlaySound, 248)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_PlaySound.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
