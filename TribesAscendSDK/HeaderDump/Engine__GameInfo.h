#pragma once
#include "Core__Object.h"
#include "Engine__GameReplicationInfo.h"
#include "Engine__Info.h"
#include "Engine__OnlineSubsystem.h"
#include "Engine__NavigationPoint.h"
#include "Engine__CoverReplicator.h"
#include "Engine__BroadcastHandler.h"
#include "Engine__Mutator.h"
#include "Engine__AccessControl.h"
#include "Engine__AutoTestManager.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Pawn.h"
#include "Engine__HUD.h"
#include "Engine__PickupFactory.h"
#include "Engine__PlayerStart.h"
#include "Engine__Vehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameInfo : public Info
	{
	public:
		ADD_VAR(::IntProperty, NumPlayers, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, GameMessageClass)
		ADD_OBJECT(ScriptClass, PlayerReplicationInfoClass)
		ADD_VAR(::StrProperty, DefaultPlayerName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTimeMargin, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRequiresPushToTalk, 0x400000)
		ADD_VAR(::BoolProperty, bTeamGame, 0x4)
		ADD_VAR(::BoolProperty, bWaitingToStartMatch, 0x40)
		ADD_VAR(::IntProperty, ArbitratedLeaderboardId, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GameDifficulty, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TimeLimit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CauseEventCommand, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasNetworkError, 0x200000)
		ADD_VAR(::BoolProperty, bRestartLevel, 0x1)
		ADD_VAR(::IntProperty, AdjustedNetSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxDynamicBandwidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GameSpeed, 0xFFFFFFFF)
		ADD_OBJECT(GameReplicationInfo, GameReplicationInfo)
		ADD_OBJECT(ScriptClass, GameReplicationInfoClass)
		ADD_OBJECT(CoverReplicator, CoverReplicatorBase)
		ADD_VAR(::StrProperty, GameName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGameEnded, 0x8)
		ADD_VAR(::BoolProperty, bOverTime, 0x10)
		ADD_OBJECT(BroadcastHandler, BroadcastHandler)
		ADD_VAR(::BoolProperty, bDoFearCostFallOff, 0x80000)
		ADD_OBJECT(AccessControl, AccessControl)
		ADD_VAR(::IntProperty, NumTravellingPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPlayersAllowed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSpectators, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSpectatorsAllowed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, BroadcastHandlerClass)
		ADD_OBJECT(ScriptClass, AccessControlClass)
		ADD_VAR(::BoolProperty, bFixedPlayerStart, 0x40000)
		ADD_OBJECT(AutoTestManager, MyAutoTestManager)
		ADD_OBJECT(ScriptClass, AutoTestManagerClass)
		ADD_VAR(::StrProperty, BugLocString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BugRotString, 0xFFFFFFFF)
		ADD_OBJECT(Mutator, BaseMutator)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::BoolProperty, bUsingArbitration, 0x2000)
		ADD_VAR(::StrProperty, ServerOptions, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLevelChange, 0x800)
		ADD_VAR(::BoolProperty, bUseSeamlessTravel, 0x100000)
		ADD_VAR(::BoolProperty, bHasArbitratedHandshakeBegun, 0x4000)
		ADD_VAR(::IntProperty, NumSpectators, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, PlayerControllerClass)
		ADD_VAR(::BoolProperty, bDelayedStart, 0x20)
		ADD_OBJECT(ScriptClass, DefaultPawnClass)
		ADD_OBJECT(ScriptClass, HUDType)
		ADD_VAR(::FloatProperty, LastNetSpeedUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TotalNetBandwidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinDynamicBandwidth, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasEndGameHandshakeBegun, 0x20000)
		ADD_OBJECT(ScriptClass, DeathMessageClass)
		ADD_VAR(::BoolProperty, bIsEndGameHandshakeComplete, 0x10000)
		ADD_VAR(::BoolProperty, bGameRestarted, 0x400)
		ADD_VAR(::BoolProperty, bChangeLevels, 0x80)
		ADD_VAR(::BoolProperty, bAlreadyChanged, 0x100)
		ADD_OBJECT(ScriptClass, OnlineStatsWriteClass)
		ADD_VAR(::IntProperty, LeaderboardId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLives, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPauseable, 0x2)
		ADD_VAR(::BoolProperty, bAdminCanPause, 0x200)
		ADD_VAR(::IntProperty, NumBots, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ArbitrationHandshakeTimeout, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedsEndGameHandshake, 0x8000)
		ADD_OBJECT(ScriptClass, OnlineGameSettingsClass)
		ADD_VAR(::BoolProperty, bKickLiveIdlers, 0x1000)
		ADD_VAR(::BoolProperty, bIsStandbyCheckingEnabled, 0x800000)
		ADD_VAR(::BoolProperty, bIsStandbyCheckingOn, 0x1000000)
		ADD_VAR(::BoolProperty, bHasStandbyCheatTriggered, 0x2000000)
		ADD_VAR(::IntProperty, GoreLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentID, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FearCostFallOff, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoalScore, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxIdleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeMarginSlack, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinTimeMargin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StandbyRxCheatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StandbyTxCheatTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BadPingThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PercentMissingForRxStandby, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PercentMissingForTxStandby, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PercentForBadPing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, JoinInProgressStandbyWaitTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultGameType, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CheckRelevance'
		// Here lies the not-yet-implemented method 'ParseOption'
		// Here lies the not-yet-implemented method 'AtCapacity'
		// Here lies the not-yet-implemented method 'ForceClearUnpauseDelegates'
		// Here lies the not-yet-implemented method 'IsAutomatedPerfTesting'
		// Here lies the not-yet-implemented method 'SetPause'
		// Here lies the not-yet-implemented method 'ChangeTeam'
		// Here lies the not-yet-implemented method 'CanSpectate'
		// Here lies the not-yet-implemented method 'PlayerCanRestartGame'
		// Here lies the not-yet-implemented method 'PlayerCanRestart'
		// Here lies the not-yet-implemented method 'IsDoingASentinelRun'
		// Here lies the not-yet-implemented method 'GetCoverReplicator'
		// Here lies the not-yet-implemented method 'PickupQuery'
		// Here lies the not-yet-implemented method 'GetSupportedGameTypes'
		// Here lies the not-yet-implemented method 'GetMapCommonPackageName'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ShouldReset'
		// Here lies the not-yet-implemented method 'ResetLevel'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'DoNavFearCostFallOff'
		// Here lies the not-yet-implemented method 'NotifyNavigationChanged'
		// Here lies the not-yet-implemented method 'GameEnding'
		// Here lies the not-yet-implemented method 'KickIdler'
		// Here lies the not-yet-implemented method 'ForceKickPlayer'
		// Here lies the not-yet-implemented method 'InitGameReplicationInfo'
		// Here lies the not-yet-implemented method 'GetNetworkNumber'
		// Here lies the not-yet-implemented method 'GetNumPlayers'
		// Here lies the not-yet-implemented method 'CanUnpause'
		// Here lies the not-yet-implemented method 'ClearPause'
		// Here lies the not-yet-implemented method 'DebugPause'
		// Here lies the not-yet-implemented method 'SetGameSpeed'
		// Here lies the not-yet-implemented method 'GrabOption'
		// Here lies the not-yet-implemented method 'GetKeyValue'
		// Here lies the not-yet-implemented method 'HasOption'
		// Here lies the not-yet-implemented method 'GetIntOption'
		// Here lies the not-yet-implemented method 'GetDefaultGameClassPath'
		// Here lies the not-yet-implemented method 'SetGameType'
		// Here lies the not-yet-implemented method 'InitGame'
		// Here lies the not-yet-implemented method 'NotifyPendingConnectionLost'
		// Here lies the not-yet-implemented method 'AddMutator'
		// Here lies the not-yet-implemented method 'RemoveMutator'
		// Here lies the not-yet-implemented method 'ProcessServerTravel'
		// Here lies the not-yet-implemented method 'ProcessClientTravel'
		// Here lies the not-yet-implemented method 'RequiresPassword'
		// Here lies the not-yet-implemented method 'PreLogin'
		// Here lies the not-yet-implemented method 'GetNextPlayerID'
		// Here lies the not-yet-implemented method 'SpawnPlayerController'
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'StartMatch'
		// Here lies the not-yet-implemented method 'StartOnlineGame'
		// Here lies the not-yet-implemented method 'OnStartOnlineGameComplete'
		// Here lies the not-yet-implemented method 'StartHumans'
		// Here lies the not-yet-implemented method 'StartBots'
		// Here lies the not-yet-implemented method 'RestartPlayer'
		// Here lies the not-yet-implemented method 'SpawnDefaultPawnFor'
		// Here lies the not-yet-implemented method 'GetDefaultPlayerClass'
		// Here lies the not-yet-implemented method 'ReplicateStreamingStatus'
		// Here lies the not-yet-implemented method 'GenericPlayerInitialization'
		// Here lies the not-yet-implemented method 'BestNextHostSort'
		// Here lies the not-yet-implemented method 'UpdateBestNextHosts'
		// Here lies the not-yet-implemented method 'PostLogin'
		// Here lies the not-yet-implemented method 'UpdateNetSpeeds'
		// Here lies the not-yet-implemented method 'CalculatedNetSpeed'
		// Here lies the not-yet-implemented method 'PreExit'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'UnregisterPlayer'
		// Here lies the not-yet-implemented method 'AcceptInventory'
		// Here lies the not-yet-implemented method 'AddDefaultInventory'
		// Here lies the not-yet-implemented method 'Mutate'
		// Here lies the not-yet-implemented method 'SetPlayerDefaults'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'Killed'
		// Here lies the not-yet-implemented method 'PreventDeath'
		// Here lies the not-yet-implemented method 'BroadcastDeathMessage'
		// Here lies the not-yet-implemented method 'Kick'
		// Here lies the not-yet-implemented method 'KickBan'
		// Here lies the not-yet-implemented method 'ReduceDamage'
		// Here lies the not-yet-implemented method 'ShouldRespawn'
		// Here lies the not-yet-implemented method 'DiscardInventory'
		// Here lies the not-yet-implemented method 'ChangeName'
		// Here lies the not-yet-implemented method 'PickTeam'
		// Here lies the not-yet-implemented method 'SendPlayer'
		// Here lies the not-yet-implemented method 'GetNextMap'
		// Here lies the not-yet-implemented method 'GetTravelType'
		// Here lies the not-yet-implemented method 'RestartGame'
		// Here lies the not-yet-implemented method 'Broadcast'
		// Here lies the not-yet-implemented method 'BroadcastTeam'
		// Here lies the not-yet-implemented method 'BroadcastLocalized'
		// Here lies the not-yet-implemented method 'BroadcastLocalizedTeam'
		// Here lies the not-yet-implemented method 'CheckModifiedEndGame'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'WriteOnlineStats'
		// Here lies the not-yet-implemented method 'WriteOnlinePlayerScores'
		// Here lies the not-yet-implemented method 'ForceRoundStart'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'PerformEndGameHandling'
		// Here lies the not-yet-implemented method 'EndOnlineGame'
		// Here lies the not-yet-implemented method 'GameEventsPoll'
		// Here lies the not-yet-implemented method 'EndLogging'
		// Here lies the not-yet-implemented method 'ShouldSpawnAtStartSpot'
		// Here lies the not-yet-implemented method 'FindPlayerStart'
		// Here lies the not-yet-implemented method 'ChoosePlayerStart'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'AddObjectiveScore'
		// Here lies the not-yet-implemented method 'ScoreObjective'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'ModifyScoreKill'
		// Here lies the not-yet-implemented method 'DriverEnteredVehicle'
		// Here lies the not-yet-implemented method 'CanLeaveVehicle'
		// Here lies the not-yet-implemented method 'DriverLeftVehicle'
		// Here lies the not-yet-implemented method 'AllowMutator'
		// Here lies the not-yet-implemented method 'AllowCheats'
		// Here lies the not-yet-implemented method 'AllowPausing'
		// Here lies the not-yet-implemented method 'PreCommitMapChange'
		// Here lies the not-yet-implemented method 'PostCommitMapChange'
		// Here lies the not-yet-implemented method 'AddInactivePRI'
		// Here lies the not-yet-implemented method 'FindInactivePRI'
		// Here lies the not-yet-implemented method 'SetPRI'
		// Here lies the not-yet-implemented method 'OverridePRI'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'SwapPlayerControllers'
		// Here lies the not-yet-implemented method 'PostSeamlessTravel'
		// Here lies the not-yet-implemented method 'UpdateGameSettings'
		// Here lies the not-yet-implemented method 'HandleSeamlessTravelPlayer'
		// Here lies the not-yet-implemented method 'SetSeamlessTravelViewTarget'
		// Here lies the not-yet-implemented method 'UpdateGameSettingsCounts'
		// Here lies the not-yet-implemented method 'ProcessClientRegistrationCompletion'
		// Here lies the not-yet-implemented method 'StartArbitrationRegistration'
		// Here lies the not-yet-implemented method 'StartArbitratedMatch'
		// Here lies the not-yet-implemented method 'RegisterServerForArbitration'
		// Here lies the not-yet-implemented method 'ArbitrationRegistrationComplete'
		// Here lies the not-yet-implemented method 'MatchIsInProgress'
		// Here lies the not-yet-implemented method 'NotifyArbitratedMatchEnd'
		// Here lies the not-yet-implemented method 'UpdateGameplayMuteList'
		// Here lies the not-yet-implemented method 'RecalculateSkillRating'
		// Here lies the not-yet-implemented method 'MatineeCancelled'
		// Here lies the not-yet-implemented method 'ProcessServerLogin'
		// Here lies the not-yet-implemented method 'ClearAutoLoginDelegates'
		// Here lies the not-yet-implemented method 'OnLoginFailed'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'RegisterServer'
		// Here lies the not-yet-implemented method 'OnServerCreateComplete'
		// Here lies the not-yet-implemented method 'TellClientsToReturnToPartyHost'
		// Here lies the not-yet-implemented method 'TellClientsToTravelToSession'
		// Here lies the not-yet-implemented method 'DoTravelTheWorld'
		// Here lies the not-yet-implemented method 'IsCheckingForFragmentation'
		// Here lies the not-yet-implemented method 'IsCheckingForMemLeaks'
		// Here lies the not-yet-implemented method 'ShouldAutoContinueToNextRound'
		// Here lies the not-yet-implemented method 'CheckForSentinelRun'
		// Here lies the not-yet-implemented method 'BeginBVT'
		// Here lies the not-yet-implemented method 'EnableStandbyCheatDetection'
		// Here lies the not-yet-implemented method 'StandbyCheatDetected'
		// Here lies the not-yet-implemented method 'OnEngineHasLoaded'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
