#pragma once
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MusicTrackDataStructures : public Object
	{
	public:
		class MusicTrackStruct
		{
		public:
			ADD_STRUCT(ScriptString*, MP3Filename, 24)
			ADD_STRUCT(float, FadeOutVolumeLevel, 20)
			ADD_STRUCT(float, FadeOutTime, 16)
			ADD_STRUCT(float, FadeInVolumeLevel, 12)
			ADD_STRUCT(float, FadeInTime, 8)
			ADD_BOOL(bPersistentAcrossLevels, 4, 0x2)
			ADD_BOOL(bAutoPlay, 4, 0x1)
			ADD_OBJECT(SoundCue, TheSoundCue, 0)
		};
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
