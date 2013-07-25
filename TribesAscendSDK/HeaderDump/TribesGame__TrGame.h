#pragma once
#include "UTGame__UTTeamGame.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame : public UTTeamGame
	{
	public:
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::BoolProperty, bFirstBloodAchieved, 0x8)
		ADD_VAR(::FloatProperty, m_fFriendlyFireDamageScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRoamingMap, 0x200)
		ADD_VAR(::FloatProperty, m_fForcedRespawnTime, 0xFFFFFFFF)
		ADD_OBJECT(TrSeekingMissileManager, m_SeekingMissileManager)
		ADD_VAR(::IntProperty, m_nMinNetPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRoundCountdownRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRoundCountdownTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAutoBalanceTeamDifference, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAutoBalanceTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerTrackingInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerTrackingCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CountdownWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SummaryWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EndGameWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_CREDITS_FOR_EXPERIENCE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_OvertimeTimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNextEffectInstanceId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nEndMatchCounter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nWinningTeam, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWinnerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bShouldAutoBalance, 0x100)
		ADD_VAR(::BoolProperty, PlayedEndOfGame, 0x80)
		ADD_VAR(::BoolProperty, bPlayedDSWinning, 0x40)
		ADD_VAR(::BoolProperty, bPlayedBEWinning, 0x20)
		ADD_VAR(::BoolProperty, bPlayTeamAudio, 0x10)
		ADD_VAR(::BoolProperty, bForceRoundStart, 0x4)
		ADD_VAR(::BoolProperty, bForceEndGame, 0x2)
		ADD_VAR(::BoolProperty, m_bPostedStats, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
