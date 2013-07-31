#pragma once
#include "Engine.InterpTrackVectorBase.h"
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
	class InterpTrackSound : public InterpTrackVectorBase
	{
	public:
		struct SoundTrackKey
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 12)
			ADD_STRUCT(float, Pitch, 8)
			ADD_STRUCT(float, Volume, 4)
			ADD_STRUCT(float, Time, 0)
		};
		ADD_STRUCT(ScriptArray<InterpTrackSound::SoundTrackKey>, Sounds, 148)
		ADD_BOOL(bTreatAsDialogue, 160, 0x8)
		ADD_BOOL(bSuppressSubtitles, 160, 0x4)
		ADD_BOOL(bContinueSoundOnMatineeEnd, 160, 0x2)
		ADD_BOOL(bPlayOnReverse, 160, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
