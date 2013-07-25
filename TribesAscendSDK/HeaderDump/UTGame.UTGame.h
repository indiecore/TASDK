#pragma once
#include "UDKBase.UDKGame.h"
#include "UTGame.UTVehicle.h"
#include "Engine.NavigationPoint.h"
#include "Engine.GameplayEventsWriter.h"
#include "Engine.SpeechRecognition.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.Actor.h"
#include "Engine.WorldInfo.h"
#include "Engine.Controller.h"
#include "Engine.Vehicle.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTVehicleFactory.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.AIController.h"
#include "Engine.PlayerStart.h"
#include "Engine.PickupFactory.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTMutator.h"
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
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetAutoObjectiveFor");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		bool ForceRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ForceRespawn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool JustStarted(float MaxElapsedTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.JustStarted");
			byte* params = (byte*)malloc(8);
			*(float*)params = MaxElapsedTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class UTTeamInfo* GetBotTeam(int TeamBots, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetBotTeam");
			byte* params = (byte*)malloc(16);
			*(int*)params = TeamBots;
			*(bool*)(params + 4) = bUseTeamIndex;
			*(int*)(params + 8) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTTeamInfo**)(params + 12);
			free(params);
			return returnVal;
		}
		bool UseLowGore(class WorldInfo* WI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.UseLowGore");
			byte* params = (byte*)malloc(8);
			*(class WorldInfo**)params = WI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TooManyBots(class Controller* botToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.TooManyBots");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = botToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AllowMutator(ScriptArray<wchar_t> MutatorClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AllowMutator");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptClass* SetGameType(ScriptArray<wchar_t> MapName, ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SetGameType");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = MapName;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(ScriptArray<wchar_t>*)(params + 24) = Portal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 36);
			free(params);
			return returnVal;
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.DriverEnteredVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.DriverLeftVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowBecomeActivePlayer(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AllowBecomeActivePlayer");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.FindNewObjectives");
			byte* params = (byte*)malloc(4);
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyNavigationChanged(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.NotifyNavigationChanged");
			byte* params = (byte*)malloc(4);
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> ParseKillMessage(ScriptArray<wchar_t> KillerName, ScriptArray<wchar_t> VictimName, ScriptArray<wchar_t> DeathMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ParseKillMessage");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = KillerName;
			*(ScriptArray<wchar_t>*)(params + 12) = VictimName;
			*(ScriptArray<wchar_t>*)(params + 24) = DeathMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 36);
			free(params);
			return returnVal;
		}
		bool SkipPlaySound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SkipPlaySound");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetGameSpeed(float T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SetGameSpeed");
			byte* params = (byte*)malloc(4);
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastDeathMessage(class Controller* Killer, class Controller* Other, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.BroadcastDeathMessage");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			*(ScriptClass**)(params + 8) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustSkill(class AIController* B, class PlayerController* P, bool bWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AdjustSkill");
			byte* params = (byte*)malloc(12);
			*(class AIController**)params = B;
			*(class PlayerController**)(params + 4) = P;
			*(bool*)(params + 8) = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.Killed");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = KilledPlayer;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitGame(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.InitGame");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		void GenericPlayerInitialization(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GenericPlayerInitialization");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetPause(class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SetPause");
			byte* params = (byte*)malloc(20);
			*(class PlayerController**)params = PC;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		int LevelRecommendedPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.LevelRecommendedPlayers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		class PlayerController* Login(ScriptArray<wchar_t> Portal, ScriptArray<wchar_t> Options, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.Login");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = Portal;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 24) = UniqueId;
			*(ScriptArray<wchar_t>*)(params + 32) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 32);
			auto returnVal = *(class PlayerController**)(params + 44);
			free(params);
			return returnVal;
		}
		bool ShouldRespawn(class PickupFactory* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ShouldRespawn");
			byte* params = (byte*)malloc(8);
			*(class PickupFactory**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.WantFastSpawnFor");
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float SpawnWait(class AIController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SpawnWait");
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void RestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.RestartGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SetEndGameFocus");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AtCapacity(bool bSpectator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AtCapacity");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PostLogin");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameSettingsCounts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.UpdateGameSettingsCounts");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AssignHoverboard(class UTPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AssignHoverboard");
			byte* params = (byte*)malloc(4);
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetHandicapNeed");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void RestartPlayer(class Controller* aPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CampaignSkillAdjust(class UTBot* aBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CampaignSkillAdjust");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = aBot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDefaultInventory(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AddDefaultInventory");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CanSpectate");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)(params + 4) = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ChangeName(class Controller* Other, ScriptArray<wchar_t> S, bool bNameChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ChangeName");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Other;
			*(ScriptArray<wchar_t>*)(params + 4) = S;
			*(bool*)(params + 16) = bNameChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.DiscardInventory");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			*(class Controller**)(params + 4) = Killer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KillBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.KillBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillOthers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.KillOthers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillThis()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.KillThis");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.KillBot");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NeedPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.NeedPlayers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class UTBot* AddBot(ScriptArray<wchar_t> BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AddBot");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = BotName;
			*(bool*)(params + 12) = bUseTeamIndex;
			*(int*)(params + 16) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTBot**)(params + 20);
			free(params);
			return returnVal;
		}
		class UTBot* SpawnBot(ScriptArray<wchar_t> BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SpawnBot");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = BotName;
			*(bool*)(params + 12) = bUseTeamIndex;
			*(int*)(params + 16) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTBot**)(params + 20);
			free(params);
			return returnVal;
		}
		void InitializeBot(class UTBot* NewBot, class UTTeamInfo* BotTeam, 
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void*& BotInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.InitializeBot");
			byte* params = (byte*)malloc(120);
			*(class UTBot**)params = NewBot;
			*(class UTTeamInfo**)(params + 4) = BotTeam;
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void**)(params + 8) = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BotInfo = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void**)(params + 8);
			free(params);
		}
		void InitGameReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.InitGameReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetMapTypeRule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetMapTypeRule");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetEndGameConditionRule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetEndGameConditionRule");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void NotifySpree(class UTPlayerReplicationInfo* Other, int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.NotifySpree");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = Other;
			*(int*)(params + 4) = Num;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndSpree(class UTPlayerReplicationInfo* Killer, class UTPlayerReplicationInfo* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.EndSpree");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = Killer;
			*(class UTPlayerReplicationInfo**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameplayMuteList(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.UpdateGameplayMuteList");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetupPlayerMuteList(class UTPlayerController* PC, bool bForceSpectatorChannel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.SetupPlayerMuteList");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerController**)params = PC;
			*(bool*)(params + 4) = bForceSpectatorChannel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemovePlayerFromMuteLists(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.RemovePlayerFromMuteLists");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetAllPlayerMuteListsToSpectatorChannel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ResetAllPlayerMuteListsToSpectatorChannel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndLogging(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.EndLogging");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptArray<wchar_t> IncomingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.FindPlayerStart");
			byte* params = (byte*)malloc(21);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			*(ScriptArray<wchar_t>*)(params + 8) = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 20);
			free(params);
			return returnVal;
		}
		bool DominatingVictory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.DominatingVictory");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsAWinner(class PlayerController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.IsAWinner");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PlayEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRegularEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PlayRegularEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PlayStartupMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndRound(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.EndRound");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MatchIsInProgress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.MatchIsInProgress");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AddInitialBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AddInitialBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalculatedNetSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CalculatedNetSpeed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool IsConsoleDedicatedServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.IsConsoleDedicatedServer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ChoosePlayerStart");
			byte* params = (byte*)malloc(9);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerStart**)(params + 8);
			free(params);
			return returnVal;
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CheckMaxLives(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CheckMaxLives");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RegisterVehicle(class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.RegisterVehicle");
			byte* params = (byte*)malloc(4);
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivateVehicleFactory(class UTVehicleFactory* VF)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ActivateVehicleFactory");
			byte* params = (byte*)malloc(4);
			*(class UTVehicleFactory**)params = VF;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ViewObjective");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMutator(ScriptArray<wchar_t> mutname, bool bUserAdded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AddMutator");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = mutname;
			*(bool*)(params + 12) = bUserAdded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowClientToTeleport(class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AllowClientToTeleport");
			byte* params = (byte*)malloc(12);
			*(class UTPlayerReplicationInfo**)params = ClientPRI;
			*(class Actor**)(params + 4) = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ShowPathTo(class PlayerController* P, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ShowPathTo");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void PostSeamlessTravel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.PostSeamlessTravel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.HandleSeamlessTravelPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			C = *(class Controller**)params;
			free(params);
		}
		class UTMutator* GetBaseUTMutator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetBaseUTMutator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTMutator**)params;
			free(params);
			return returnVal;
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ProcessSpeechRecognition");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerController**)params = Speaker;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void WriteOnlinePlayerScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.WriteOnlinePlayerScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetCurrentMapCycleIndex(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& MapList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetCurrentMapCycleIndex");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = MapList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MapList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetNextMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetNextMap");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ProcessServerTravel(ScriptArray<wchar_t> URL, bool bAbsolute)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ProcessServerTravel");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = URL;
			*(bool*)(params + 12) = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ContinueSeamlessTravel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.ContinueSeamlessTravel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetEndOfMatchRules(int InGoalScore, int InTimeLimit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetEndOfMatchRules");
			byte* params = (byte*)malloc(20);
			*(int*)params = InGoalScore;
			*(int*)(params + 4) = InTimeLimit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.GetLocationFor");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = StatusPawn;
			*(class Actor**)(params + 4) = LocationObject;
			*(int*)(params + 8) = MessageIndex;
			*(int*)(params + 12) = LocationSpeechOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LocationObject = *(class Actor**)(params + 4);
			MessageIndex = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool AllowCheats(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.AllowCheats");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGame.UpdateGameSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
