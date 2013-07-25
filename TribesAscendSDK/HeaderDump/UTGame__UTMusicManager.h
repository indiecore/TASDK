#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMusicManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTMusicManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTMusicManager : public Info
	{
	public:
		ADD_VAR(::FloatProperty, MusicStartTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastBeat, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MusicVolume, 0xFFFFFFFF)
		ADD_OBJECT(UTPlayerController, PlayerOwner)
		ADD_VAR(::FloatProperty, CurrTempo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrFadeFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PendingEvent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingEventPlayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingEventDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPendingAction, 0x1)
		ADD_VAR(::FloatProperty, LastActionEventTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StingerVolumeMultiplier, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
