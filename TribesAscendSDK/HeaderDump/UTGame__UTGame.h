#pragma once
#include "UTGame__UTVehicle.h"
#include "UDKBase__UDKGame.h"
#include "Engine__GameplayEventsWriter.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Pawn.h"
#include "UTGame__UTTeamInfo.h"
#include "Engine__SpeechRecognition.h"
#include "UTGame__UTPlayerController.h"
#include "Engine__Actor.h"
#include "UTGame__UTBot.h"
#include "Engine__WorldInfo.h"
#include "Engine__Controller.h"
#include "Engine__Vehicle.h"
#include "Engine__PlayerController.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__AIController.h"
#include "Engine__PickupFactory.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTPawn.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__PlayerStart.h"
#include "UTGame__UTVehicleFactory.h"
#include "UTGame__UTMutator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGame : public UDKGame
	{
	public:
		ADD_OBJECT(UTVehicle, VehicleList)
		ADD_VAR(::IntProperty, ResetTimeDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWarmupRound, 0x1000)
		ADD_VAR(::IntProperty, WarmupTime, 0xFFFFFFFF)
		ADD_OBJECT(GameplayEventsWriter, GameplayEventsWriter)
		ADD_VAR(::StrProperty, GameplayEventsWriterClassName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, MidgameScorePanelTag, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Sniper)
		ADD_VAR(::FloatProperty, LastManDownTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastEncouragementTime, 0xFFFFFFFF)
		ADD_OBJECT(SpeechRecognition, SpeechRecognitionData)
		ADD_VAR(::StrProperty, EndOfMatchRulesTemplateStr_Time, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndOfMatchRulesTemplateStr_ScoringSingle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EndOfMatchRulesTemplateStr_Scoring, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, ScriptedStartSpot)
		ADD_VAR(::IntProperty, MapCycleIndex, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, BotClass)
		ADD_VAR(::StrProperty, DemoPrefix, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ConsolePlayerControllerClass)
		ADD_OBJECT(ScriptClass, VictoryMessageClass)
		ADD_VAR(::StrProperty, EnemyRosterName, 0xFFFFFFFF)
		ADD_OBJECT(UTTeamInfo, EnemyRoster)
		ADD_VAR(::IntProperty, ResetCountDown, 0xFFFFFFFF)
		ADD_OBJECT(Actor, EndGameFocus)
		ADD_VAR(::StrProperty, GameUMenuType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RulesMenuType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EndMessageCounter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EndMessageWait, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndTime, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, LastStartSpot)
		ADD_OBJECT(NavigationPoint, LastPlayerStartSpot)
		ADD_VAR(::IntProperty, PlayerDeaths, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerKills, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AdjustedDifficulty, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CountDown, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PendingMatchElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LateEntryLives, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DefaultMaxLives, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnProtectionTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DesiredPlayerCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponTauntUsed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, StartupStage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, WarmupRemaining, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RestartWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNetPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClientProcessingTimeout, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NetWait, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BotRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndTimeDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerSkillLevel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Acronym, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGivePhysicsGun, 0x40)
		ADD_VAR(::BoolProperty, bLogGameplayEvents, 0x20)
		ADD_VAR(::BoolProperty, bUseClassicHUD, 0x10)
		ADD_VAR(::BoolProperty, bIgnoreTeamForVoiceChat, 0x8)
		ADD_VAR(::BoolProperty, bNecrisLocked, 0x4)
		ADD_VAR(::BoolProperty, bForceMidGameMenuAtStart, 0x2)
		ADD_VAR(::BoolProperty, bMidGameHasMap, 0x1)
		ADD_VAR(::BoolProperty, bPlayedOneKill, 0x80000000)
		ADD_VAR(::BoolProperty, bPlayedFiveKills, 0x40000000)
		ADD_VAR(::BoolProperty, bPlayedTenKills, 0x20000000)
		ADD_VAR(::BoolProperty, bScoreDeaths, 0x10000000)
		ADD_VAR(::BoolProperty, bAllowKeyboardAndMouse, 0x8000000)
		ADD_VAR(::BoolProperty, bConsoleServer, 0x4000000)
		ADD_VAR(::BoolProperty, bAllowHoverboard, 0x2000000)
		ADD_VAR(::BoolProperty, bStartWithLockerWeaps, 0x1000000)
		ADD_VAR(::BoolProperty, bUndrivenVehicleDamage, 0x800000)
		ADD_VAR(::BoolProperty, bDemoMode, 0x400000)
		ADD_VAR(::BoolProperty, bMustJoinBeforeStart, 0x200000)
		ADD_VAR(::BoolProperty, bPlayerBecameActive, 0x100000)
		ADD_VAR(::BoolProperty, bMustHaveMultiplePlayers, 0x80000)
		ADD_VAR(::BoolProperty, bOverTimeBroadcast, 0x40000)
		ADD_VAR(::BoolProperty, bFinalStartup, 0x20000)
		ADD_VAR(::BoolProperty, bStartedCountDown, 0x10000)
		ADD_VAR(::BoolProperty, bSkipPlaySound, 0x8000)
		ADD_VAR(::BoolProperty, bQuickStart, 0x4000)
		ADD_VAR(::BoolProperty, bFirstBlood, 0x2000)
		ADD_VAR(::BoolProperty, bShouldWaitForNetPlayers, 0x800)
		ADD_VAR(::BoolProperty, bWaitForNetPlayers, 0x400)
		ADD_VAR(::BoolProperty, bTempForceRespawn, 0x200)
		ADD_VAR(::BoolProperty, bForceRespawn, 0x100)
		ADD_VAR(::BoolProperty, bPlayersMustBeReady, 0x80)
		ADD_VAR(::BoolProperty, bAutoNumBots, 0x40)
		ADD_VAR(::BoolProperty, bCustomBots, 0x20)
		ADD_VAR(::BoolProperty, bPlayersVsBots, 0x10)
		ADD_VAR(::BoolProperty, bSoaking, 0x8)
		ADD_VAR(::BoolProperty, bTeamScoreRounds, 0x4)
		ADD_VAR(::BoolProperty, bWeaponStay, 0x2)
		ADD_VAR(::BoolProperty, bExportMenuData, 0x1)
		// Here lies the not-yet-implemented method 'GetAutoObjectiveFor'
		// Here lies the not-yet-implemented method 'ForceRespawn'
		// Here lies the not-yet-implemented method 'JustStarted'
		// Here lies the not-yet-implemented method 'GetBotTeam'
		// Here lies the not-yet-implemented method 'UseLowGore'
		// Here lies the not-yet-implemented method 'TooManyBots'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'AllowMutator'
		// Here lies the not-yet-implemented method 'SetGameType'
		// Here lies the not-yet-implemented method 'DriverEnteredVehicle'
		// Here lies the not-yet-implemented method 'DriverLeftVehicle'
		// Here lies the not-yet-implemented method 'AllowBecomeActivePlayer'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'FindNewObjectives'
		// Here lies the not-yet-implemented method 'NotifyNavigationChanged'
		// Here lies the not-yet-implemented method 'ParseKillMessage'
		// Here lies the not-yet-implemented method 'SkipPlaySound'
		// Here lies the not-yet-implemented method 'SetGameSpeed'
		// Here lies the not-yet-implemented method 'BroadcastDeathMessage'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'AdjustSkill'
		// Here lies the not-yet-implemented method 'Killed'
		// Here lies the not-yet-implemented method 'InitGame'
		// Here lies the not-yet-implemented method 'GenericPlayerInitialization'
		// Here lies the not-yet-implemented method 'SetPause'
		// Here lies the not-yet-implemented method 'LevelRecommendedPlayers'
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'ShouldRespawn'
		// Here lies the not-yet-implemented method 'WantFastSpawnFor'
		// Here lies the not-yet-implemented method 'SpawnWait'
		// Here lies the not-yet-implemented method 'RestartGame'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'SetEndGameFocus'
		// Here lies the not-yet-implemented method 'AtCapacity'
		// Here lies the not-yet-implemented method 'PostLogin'
		// Here lies the not-yet-implemented method 'UpdateGameSettingsCounts'
		// Here lies the not-yet-implemented method 'AssignHoverboard'
		// Here lies the not-yet-implemented method 'GetHandicapNeed'
		// Here lies the not-yet-implemented method 'RestartPlayer'
		// Here lies the not-yet-implemented method 'CampaignSkillAdjust'
		// Here lies the not-yet-implemented method 'AddDefaultInventory'
		// Here lies the not-yet-implemented method 'CanSpectate'
		// Here lies the not-yet-implemented method 'ChangeName'
		// Here lies the not-yet-implemented method 'DiscardInventory'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'KillBots'
		// Here lies the not-yet-implemented method 'KillOthers'
		// Here lies the not-yet-implemented method 'KillThis'
		// Here lies the not-yet-implemented method 'KillBot'
		// Here lies the not-yet-implemented method 'NeedPlayers'
		// Here lies the not-yet-implemented method 'AddBot'
		// Here lies the not-yet-implemented method 'SpawnBot'
		// Here lies the not-yet-implemented method 'InitializeBot'
		// Here lies the not-yet-implemented method 'InitGameReplicationInfo'
		// Here lies the not-yet-implemented method 'GetMapTypeRule'
		// Here lies the not-yet-implemented method 'GetEndGameConditionRule'
		// Here lies the not-yet-implemented method 'NotifySpree'
		// Here lies the not-yet-implemented method 'EndSpree'
		// Here lies the not-yet-implemented method 'UpdateGameplayMuteList'
		// Here lies the not-yet-implemented method 'SetupPlayerMuteList'
		// Here lies the not-yet-implemented method 'RemovePlayerFromMuteLists'
		// Here lies the not-yet-implemented method 'ResetAllPlayerMuteListsToSpectatorChannel'
		// Here lies the not-yet-implemented method 'StartMatch'
		// Here lies the not-yet-implemented method 'EndGame'
		// Here lies the not-yet-implemented method 'EndLogging'
		// Here lies the not-yet-implemented method 'FindPlayerStart'
		// Here lies the not-yet-implemented method 'DominatingVictory'
		// Here lies the not-yet-implemented method 'IsAWinner'
		// Here lies the not-yet-implemented method 'PlayEndOfMatchMessage'
		// Here lies the not-yet-implemented method 'PlayRegularEndOfMatchMessage'
		// Here lies the not-yet-implemented method 'PlayStartupMessage'
		// Here lies the not-yet-implemented method 'EndRound'
		// Here lies the not-yet-implemented method 'MatchIsInProgress'
		// Here lies the not-yet-implemented method 'AddInitialBots'
		// Here lies the not-yet-implemented method 'CalculatedNetSpeed'
		// Here lies the not-yet-implemented method 'IsConsoleDedicatedServer'
		// Here lies the not-yet-implemented method 'ChoosePlayerStart'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'CheckMaxLives'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'RegisterVehicle'
		// Here lies the not-yet-implemented method 'ActivateVehicleFactory'
		// Here lies the not-yet-implemented method 'ViewObjective'
		// Here lies the not-yet-implemented method 'AddMutator'
		// Here lies the not-yet-implemented method 'AllowClientToTeleport'
		// Here lies the not-yet-implemented method 'ShowPathTo'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'PostSeamlessTravel'
		// Here lies the not-yet-implemented method 'HandleSeamlessTravelPlayer'
		// Here lies the not-yet-implemented method 'GetBaseUTMutator'
		// Here lies the not-yet-implemented method 'ProcessSpeechRecognition'
		// Here lies the not-yet-implemented method 'WriteOnlinePlayerScores'
		// Here lies the not-yet-implemented method 'GetCurrentMapCycleIndex'
		// Here lies the not-yet-implemented method 'GetNextMap'
		// Here lies the not-yet-implemented method 'ProcessServerTravel'
		// Here lies the not-yet-implemented method 'ContinueSeamlessTravel'
		// Here lies the not-yet-implemented method 'GetEndOfMatchRules'
		// Here lies the not-yet-implemented method 'GetLocationFor'
		// Here lies the not-yet-implemented method 'AllowCheats'
		// Here lies the not-yet-implemented method 'UpdateGameSettings'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
