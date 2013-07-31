#pragma once
#include "Core.Object.h"
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
	class UDKMapMusicInfo : public Object
	{
	public:
		enum ECrossfadeType : byte
		{
			CFT_BeginningOfMeasure = 0,
			CFT_EndOfMeasure = 1,
			CFT_MAX = 2,
		};
		struct StingersForAMap
		{
		public:
			ADD_OBJECT(SoundCue, ScoreWinning, 56)
			ADD_OBJECT(SoundCue, ScoreTie, 52)
			ADD_OBJECT(SoundCue, ScoreLosing, 48)
			ADD_OBJECT(SoundCue, ReturnFlag, 44)
			ADD_OBJECT(SoundCue, MultiKill, 40)
			ADD_OBJECT(SoundCue, MonsterKill, 36)
			ADD_OBJECT(SoundCue, MajorKill, 32)
			ADD_OBJECT(SoundCue, LongKillingSpree, 28)
			ADD_OBJECT(SoundCue, Kill, 24)
			ADD_OBJECT(SoundCue, GrabFlag, 20)
			ADD_OBJECT(SoundCue, FlagReturned, 16)
			ADD_OBJECT(SoundCue, FirstKillingSpree, 12)
			ADD_OBJECT(SoundCue, EnemyGrabFlag, 8)
			ADD_OBJECT(SoundCue, DoubleKill, 4)
			ADD_OBJECT(SoundCue, Died, 0)
		};
		struct MusicSegment
		{
		public:
			ADD_OBJECT(SoundCue, TheCue, 12)
			ADD_STRUCT(int, CrossfadeToMeNumMeasuresDuration, 8)
			ADD_STRUCT(UDKMapMusicInfo::ECrossfadeType, CrossfadeRule, 4)
			ADD_STRUCT(float, TempoOverride, 0)
		};
		struct MusicForAMap
		{
		public:
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Victory, 84)
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Tension, 68)
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Suspense, 52)
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Intro, 36)
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Ambient, 20)
			ADD_STRUCT(UDKMapMusicInfo::MusicSegment, Action, 4)
			ADD_STRUCT(float, Tempo, 0)
		};
		ADD_STRUCT(UDKMapMusicInfo::StingersForAMap, MapStingers, 160)
		ADD_STRUCT(UDKMapMusicInfo::MusicForAMap, MapMusic, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
