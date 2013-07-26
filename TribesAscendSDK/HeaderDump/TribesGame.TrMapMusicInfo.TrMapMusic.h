#pragma once
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrMapMusicInfo.TrMapMusic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMapMusic
	{
	public:
		ADD_OBJECT(SoundCue, AmbientMusic)
		ADD_OBJECT(SoundCue, TeamLost)
		ADD_OBJECT(SoundCue, TeamWon)
		ADD_OBJECT(SoundCue, DeathDirge)
		ADD_OBJECT(SoundCue, FlagPossession)
		ADD_OBJECT(SoundCue, BattleMusicHigh)
		ADD_OBJECT(SoundCue, BattleMusicMed)
		ADD_OBJECT(SoundCue, BattleMusicLow)
	};
}
#undef ADD_OBJECT
