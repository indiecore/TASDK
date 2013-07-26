#pragma once
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrMapMusicInfo.TrMapStingers." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMapStingers
	{
	public:
		ADD_OBJECT(SoundCue, TeamRabbitFriendlyPickedUpFlag)
		ADD_OBJECT(SoundCue, TeamRabbitEnemyPickedUpFlag)
		ADD_OBJECT(SoundCue, EnemyFlagDropped)
		ADD_OBJECT(SoundCue, EnemyFlagReturned)
		ADD_OBJECT(SoundCue, EnemyFlagCaptured)
		ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromDropped)
		ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromBase)
		ADD_OBJECT(SoundCue, FriendlyFlagDropped)
		ADD_OBJECT(SoundCue, FriendlyFlagReturned)
		ADD_OBJECT(SoundCue, FriendlyFlagCaptured)
		ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromDropped)
		ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromBase)
		ADD_OBJECT(SoundCue, PlayerLost)
		ADD_OBJECT(SoundCue, PlayerWon)
	};
}
#undef ADD_OBJECT
