#pragma once
#include "Engine.AnimNotify_Scripted.h"
#include "Engine.SoundCue.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.Actor.h"
#include "Engine.AnimNodeSequence.h"
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
	class AnimNotify_PlayFaceFXAnim : public AnimNotify_Scripted
	{
	public:
		ADD_STRUCT(float, PlayFrequency, 100)
		ADD_BOOL(bOverridePlayingAnim, 96, 0x1)
		ADD_OBJECT(SoundCue, SoundCueToPlay, 92)
		ADD_STRUCT(ScriptString*, AnimName, 80)
		ADD_STRUCT(ScriptString*, GroupName, 68)
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef, 64)
		void Notify(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11407);
			byte params[8] = { NULL };
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)&params[4] = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
