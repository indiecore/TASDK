#pragma once
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MusicTrackDataStructures.MusicTrackStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty MusicTrackDataStructures.MusicTrackStruct." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MusicTrackStruct
	{
	public:
		ADD_VAR(::StrProperty, MP3Filename, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInVolumeLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPersistentAcrossLevels, 0x2)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x1)
		ADD_OBJECT(SoundCue, TheSoundCue)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
