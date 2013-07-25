#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTTeamGame.h"
#include "TribesGame__TrSeekingMissileManager.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Actor.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTTeamInfo.h"
#include "Engine__NavigationPoint.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "TribesGame__TrPowerGenerator.h"
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
		// Here lies the not-yet-implemented method 'RequestTeam'
		// Here lies the not-yet-implemented method 'AutoAssignTeam'
		// Here lies the not-yet-implemented method 'AllowRespawn'
		// Here lies the not-yet-implemented method 'CanEnterSpectate'
		// Here lies the not-yet-implemented method 'CreditsSortViaPC'
		// Here lies the not-yet-implemented method 'CreditSort'
		// Here lies the not-yet-implemented method 'ScoreSort'
		// Here lies the not-yet-implemented method 'GetNextEffectInstanceId'
		// Here lies the not-yet-implemented method 'LocalLeaveGame'
		// Here lies the not-yet-implemented method 'OnServerInitialized'
		// Here lies the not-yet-implemented method 'SetOnlinePlayerName'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'ReduceDamage'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'AddInitialBots'
		// Here lies the not-yet-implemented method 'AddBot'
		// Here lies the not-yet-implemented method 'AddBots'
		// Here lies the not-yet-implemented method 'SpawnBot'
		// Here lies the not-yet-implemented method 'InitializeBot'
		// Here lies the not-yet-implemented method 'StartBots'
		// Here lies the not-yet-implemented method 'KickIdler'
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'SpawnDefaultPawnFor'
		// Here lies the not-yet-implemented method 'DetermineWinningTeam'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'EndOnlineGame'
		// Here lies the not-yet-implemented method 'SetEndGameFocus'
		// Here lies the not-yet-implemented method 'TrackPlayerMovement'
		// Here lies the not-yet-implemented method 'RespawnPlayers'
		// Here lies the not-yet-implemented method 'ResetScores'
		// Here lies the not-yet-implemented method 'ResetRound'
		// Here lies the not-yet-implemented method 'ForceRoundStart'
		// Here lies the not-yet-implemented method 'NotifySpree'
		// Here lies the not-yet-implemented method 'EndSpree'
		// Here lies the not-yet-implemented method 'GenericPlayerInitialization'
		// Here lies the not-yet-implemented method 'SetGameType'
		// Here lies the not-yet-implemented method 'PlayEndOfMatchMessage'
		// Here lies the not-yet-implemented method 'SendMatchOver'
		// Here lies the not-yet-implemented method 'SendShowSummary'
		// Here lies the not-yet-implemented method 'SendNextMatchCountdown'
		// Here lies the not-yet-implemented method 'SendMatchCountdown'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'ForceRespawn'
		// Here lies the not-yet-implemented method 'RestartPlayer'
		// Here lies the not-yet-implemented method 'ChangeTeam'
		// Here lies the not-yet-implemented method 'PickTeam'
		// Here lies the not-yet-implemented method 'PickTeamForMigration'
		// Here lies the not-yet-implemented method 'HandleSeamlessTravelPlayer'
		// Here lies the not-yet-implemented method 'SetPlayerDefaults'
		// Here lies the not-yet-implemented method 'Killed'
		// Here lies the not-yet-implemented method 'AllowCheats'
		// Here lies the not-yet-implemented method 'AreTeamsUnbalanced'
		// Here lies the not-yet-implemented method 'CheckForAutoBalance'
		// Here lies the not-yet-implemented method 'AutoBalanceInTwenty'
		// Here lies the not-yet-implemented method 'AutoBalanceInFive'
		// Here lies the not-yet-implemented method 'AutoBalanceTeams'
		// Here lies the not-yet-implemented method 'MoveRandomPlayerFromTeam'
		// Here lies the not-yet-implemented method 'InitGame'
		// Here lies the not-yet-implemented method 'SetPRI'
		// Here lies the not-yet-implemented method 'GetRankFromXP'
		// Here lies the not-yet-implemented method 'CanSpectate'
		// Here lies the not-yet-implemented method 'BroadcastAccolade'
		// Here lies the not-yet-implemented method 'SendMessageToAll'
		// Here lies the not-yet-implemented method 'OnServerSpawnedPlayer'
		// Here lies the not-yet-implemented method 'FindGameTypeId'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
		// Here lies the not-yet-implemented method 'OnGeneratorPowerChange'
		// Here lies the not-yet-implemented method 'TgStartGame'
		// Here lies the not-yet-implemented method 'TgEndGame'
		// Here lies the not-yet-implemented method 'TgChangeScore'
		// Here lies the not-yet-implemented method 'TgChangeTime'
		// Here lies the not-yet-implemented method 'TgGetSpectators'
		// Here lies the not-yet-implemented method 'FindPlayerStart'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
