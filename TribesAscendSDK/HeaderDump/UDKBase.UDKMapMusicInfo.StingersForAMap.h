#pragma once
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKMapMusicInfo.StingersForAMap." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class StingersForAMap
	{
	public:
		ADD_OBJECT(SoundCue, ScoreWinning)
		ADD_OBJECT(SoundCue, ScoreTie)
		ADD_OBJECT(SoundCue, ScoreLosing)
		ADD_OBJECT(SoundCue, ReturnFlag)
		ADD_OBJECT(SoundCue, MultiKill)
		ADD_OBJECT(SoundCue, MonsterKill)
		ADD_OBJECT(SoundCue, MajorKill)
		ADD_OBJECT(SoundCue, LongKillingSpree)
		ADD_OBJECT(SoundCue, Kill)
		ADD_OBJECT(SoundCue, GrabFlag)
		ADD_OBJECT(SoundCue, FlagReturned)
		ADD_OBJECT(SoundCue, FirstKillingSpree)
		ADD_OBJECT(SoundCue, EnemyGrabFlag)
		ADD_OBJECT(SoundCue, DoubleKill)
		ADD_OBJECT(SoundCue, Died)
	};
}
#undef ADD_OBJECT
