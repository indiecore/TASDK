#pragma once
#include "UDKBase.UDKMapMusicInfo.h"
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
	class TrMapMusicInfo : public UDKMapMusicInfo
	{
	public:
		struct TrMapStingers
		{
		public:
			ADD_OBJECT(SoundCue, TeamRabbitFriendlyPickedUpFlag, 52)
			ADD_OBJECT(SoundCue, TeamRabbitEnemyPickedUpFlag, 48)
			ADD_OBJECT(SoundCue, EnemyFlagDropped, 44)
			ADD_OBJECT(SoundCue, EnemyFlagReturned, 40)
			ADD_OBJECT(SoundCue, EnemyFlagCaptured, 36)
			ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromDropped, 32)
			ADD_OBJECT(SoundCue, EnemyFlagPickedUpFromBase, 28)
			ADD_OBJECT(SoundCue, FriendlyFlagDropped, 24)
			ADD_OBJECT(SoundCue, FriendlyFlagReturned, 20)
			ADD_OBJECT(SoundCue, FriendlyFlagCaptured, 16)
			ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromDropped, 12)
			ADD_OBJECT(SoundCue, FriendlyFlagPickedUpFromBase, 8)
			ADD_OBJECT(SoundCue, PlayerLost, 4)
			ADD_OBJECT(SoundCue, PlayerWon, 0)
		};
		struct TrMapMusic
		{
		public:
			ADD_OBJECT(SoundCue, AmbientMusic, 28)
			ADD_OBJECT(SoundCue, TeamLost, 24)
			ADD_OBJECT(SoundCue, TeamWon, 20)
			ADD_OBJECT(SoundCue, DeathDirge, 16)
			ADD_OBJECT(SoundCue, FlagPossession, 12)
			ADD_OBJECT(SoundCue, BattleMusicHigh, 8)
			ADD_OBJECT(SoundCue, BattleMusicMed, 4)
			ADD_OBJECT(SoundCue, BattleMusicLow, 0)
		};
		ADD_STRUCT(TrMapMusicInfo::TrMapStingers, m_MapStingers, 252)
		ADD_STRUCT(TrMapMusicInfo::TrMapMusic, m_MapMusic, 220)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
