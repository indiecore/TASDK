#pragma once
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKMapMusicInfo.MusicSegment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKMapMusicInfo.MusicSegment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MusicSegment
	{
	public:
		ADD_OBJECT(SoundCue, TheCue)
		ADD_VAR(::IntProperty, CrossfadeToMeNumMeasuresDuration, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CrossfadeRule, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TempoOverride, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
