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
#include "Engine.OnlineSubsystem.h"
#include "Engine.PlayerStart.h"
#include "Engine.PickupFactory.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTPawn.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTCharInfo.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTMutator.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UTGame : public UDKGame
	{
	public:
		enum EVoiceChannel : byte
		{
			VC_Spectators = 0,
			VC_Team1 = 1,
			VC_Team2 = 2,
			VC_MAX = 3,
		};
		struct GameMapCycle
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, Maps, 8)
			ADD_STRUCT(ScriptName, GameClassName, 0)
		};
		struct ActiveBotInfo
		{
		public:
			ADD_BOOL(bInUse, 12, 0x1)
			ADD_STRUCT(ScriptString*, BotName, 0)
		};
		ADD_OBJECT(UTVehicle, VehicleList, 1080)
		ADD_STRUCT(int, ResetTimeDelay, 1076)
		ADD_BOOL(bWarmupRound, 896, 0x1000)
		ADD_STRUCT(int, WarmupTime, 956)
		ADD_STRUCT(ScriptArray<ScriptClass*>, DefaultInventory, 1100)
		ADD_STRUCT(ScriptArray<ScriptString*>, MapPrefixes, 1116)
		ADD_STRUCT(ScriptArray<UTGame::GameMapCycle>, GameSpecificMapCycles, 1148)
		ADD_STRUCT(ScriptArray<UTGame::ActiveBotInfo>, ActiveBots, 1164)
		ADD_OBJECT(GameplayEventsWriter, GameplayEventsWriter, 1252)
		ADD_STRUCT(ScriptString*, GameplayEventsWriterClassName, 1240)
		ADD_STRUCT(ScriptName, MidgameScorePanelTag, 1232)
		ADD_OBJECT(Pawn, Sniper, 1228)
		ADD_STRUCT(float, LastManDownTime, 1224)
		ADD_STRUCT(float, LastEncouragementTime, 1220)
		ADD_OBJECT(SpeechRecognition, SpeechRecognitionData, 1216)
		ADD_STRUCT(ScriptString*, EndOfMatchRulesTemplateStr_Time, 1204)
		ADD_STRUCT(ScriptString*, EndOfMatchRulesTemplateStr_ScoringSingle, 1192)
		ADD_STRUCT(ScriptString*, EndOfMatchRulesTemplateStr_Scoring, 1180)
		ADD_OBJECT(NavigationPoint, ScriptedStartSpot, 1176)
		ADD_STRUCT(int, MapCycleIndex, 1160)
		ADD_OBJECT(ScriptClass, BotClass, 1144)
		ADD_STRUCT(ScriptString*, DemoPrefix, 1132)
		ADD_OBJECT(ScriptClass, ConsolePlayerControllerClass, 1128)
		ADD_OBJECT(ScriptClass, VictoryMessageClass, 1112)
		ADD_STRUCT(ScriptString*, EnemyRosterName, 1088)
		ADD_OBJECT(UTTeamInfo, EnemyRoster, 1084)
		ADD_STRUCT(int, ResetCountDown, 1072)
		ADD_OBJECT(Actor, EndGameFocus, 1068)
		ADD_STRUCT(ScriptString*, GameUMenuType, 1056)
		ADD_STRUCT(ScriptString*, RulesMenuType, 1044)
		ADD_STRUCT(int, EndMessageCounter, 1040)
		ADD_STRUCT(int, EndMessageWait, 1036)
		ADD_STRUCT(float, EndTime, 1032)
		ADD_OBJECT(NavigationPoint, LastStartSpot, 1028)
		ADD_OBJECT(NavigationPoint, LastPlayerStartSpot, 1024)
		ADD_STRUCT(int, PlayerDeaths, 1020)
		ADD_STRUCT(int, PlayerKills, 1016)
		ADD_STRUCT(float, AdjustedDifficulty, 1012)
		ADD_STRUCT(int, CountDown, 1008)
		ADD_STRUCT(int, PendingMatchElapsedTime, 1004)
		ADD_STRUCT(int, LateEntryLives, 1000)
		ADD_STRUCT(int, DefaultMaxLives, 996)
		ADD_STRUCT(float, SpawnProtectionTime, 992)
		ADD_STRUCT(int, DesiredPlayerCount, 988)
		ADD_STRUCT(byte, WeaponTauntUsed, 965)
		ADD_STRUCT(byte, StartupStage, 964)
		ADD_STRUCT(int, WarmupRemaining, 960)
		ADD_STRUCT(int, RestartWait, 952)
		ADD_STRUCT(int, MinNetPlayers, 948)
		ADD_STRUCT(int, ClientProcessingTimeout, 944)
		ADD_STRUCT(int, NetWait, 940)
		ADD_STRUCT(float, BotRatio, 936)
		ADD_STRUCT(float, EndTimeDelay, 932)
		ADD_STRUCT(int, ServerSkillLevel, 928)
		ADD_STRUCT(ScriptString*, Description, 916)
		ADD_STRUCT(ScriptString*, Acronym, 904)
		ADD_BOOL(bGivePhysicsGun, 900, 0x40)
		ADD_BOOL(bLogGameplayEvents, 900, 0x20)
		ADD_BOOL(bUseClassicHUD, 900, 0x10)
		ADD_BOOL(bIgnoreTeamForVoiceChat, 900, 0x8)
		ADD_BOOL(bNecrisLocked, 900, 0x4)
		ADD_BOOL(bForceMidGameMenuAtStart, 900, 0x2)
		ADD_BOOL(bMidGameHasMap, 900, 0x1)
		ADD_BOOL(bPlayedOneKill, 896, 0x80000000)
		ADD_BOOL(bPlayedFiveKills, 896, 0x40000000)
		ADD_BOOL(bPlayedTenKills, 896, 0x20000000)
		ADD_BOOL(bScoreDeaths, 896, 0x10000000)
		ADD_BOOL(bAllowKeyboardAndMouse, 896, 0x8000000)
		ADD_BOOL(bConsoleServer, 896, 0x4000000)
		ADD_BOOL(bAllowHoverboard, 896, 0x2000000)
		ADD_BOOL(bStartWithLockerWeaps, 896, 0x1000000)
		ADD_BOOL(bUndrivenVehicleDamage, 896, 0x800000)
		ADD_BOOL(bDemoMode, 896, 0x400000)
		ADD_BOOL(bMustJoinBeforeStart, 896, 0x200000)
		ADD_BOOL(bPlayerBecameActive, 896, 0x100000)
		ADD_BOOL(bMustHaveMultiplePlayers, 896, 0x80000)
		ADD_BOOL(bOverTimeBroadcast, 896, 0x40000)
		ADD_BOOL(bFinalStartup, 896, 0x20000)
		ADD_BOOL(bStartedCountDown, 896, 0x10000)
		ADD_BOOL(bSkipPlaySound, 896, 0x8000)
		ADD_BOOL(bQuickStart, 896, 0x4000)
		ADD_BOOL(bFirstBlood, 896, 0x2000)
		ADD_BOOL(bShouldWaitForNetPlayers, 896, 0x800)
		ADD_BOOL(bWaitForNetPlayers, 896, 0x400)
		ADD_BOOL(bTempForceRespawn, 896, 0x200)
		ADD_BOOL(bForceRespawn, 896, 0x100)
		ADD_BOOL(bPlayersMustBeReady, 896, 0x80)
		ADD_BOOL(bAutoNumBots, 896, 0x40)
		ADD_BOOL(bCustomBots, 896, 0x20)
		ADD_BOOL(bPlayersVsBots, 896, 0x10)
		ADD_BOOL(bSoaking, 896, 0x8)
		ADD_BOOL(bTeamScoreRounds, 896, 0x4)
		ADD_BOOL(bWeaponStay, 896, 0x2)
		ADD_BOOL(bExportMenuData, 896, 0x1)
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36535);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		bool ForceRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36762);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool JustStarted(float MaxElapsedTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39767);
			byte params[8] = { NULL };
			*(float*)params = MaxElapsedTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class UTTeamInfo* GetBotTeam(int TeamBots, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41546);
			byte params[16] = { NULL };
			*(int*)params = TeamBots;
			*(bool*)&params[4] = bUseTeamIndex;
			*(int*)&params[8] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTTeamInfo**)&params[12];
		}
		bool UseLowGore(class WorldInfo* WI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41762);
			byte params[8] = { NULL };
			*(class WorldInfo**)params = WI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TooManyBots(class Controller* botToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42769);
			byte params[8] = { NULL };
			*(class Controller**)params = botToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44615);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AllowMutator(ScriptString* MutatorClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44618);
			byte params[16] = { NULL };
			*(ScriptString**)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		ScriptClass* SetGameType(ScriptString* MapName, ScriptString* Options, ScriptString* Portal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44621);
			byte params[40] = { NULL };
			*(ScriptString**)params = MapName;
			*(ScriptString**)&params[12] = Options;
			*(ScriptString**)&params[24] = Portal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[36];
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44631);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44636);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowBecomeActivePlayer(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44640);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44643);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44646);
			byte params[4] = { NULL };
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyNavigationChanged(class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44648);
			byte params[4] = { NULL };
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ParseKillMessage(ScriptString* KillerName, ScriptString* VictimName, ScriptString* DeathMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44651);
			byte params[48] = { NULL };
			*(ScriptString**)params = KillerName;
			*(ScriptString**)&params[12] = VictimName;
			*(ScriptString**)&params[24] = DeathMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[36];
		}
		bool SkipPlaySound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44656);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetGameSpeed(float T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44658);
			byte params[4] = { NULL };
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastDeathMessage(class Controller* Killer, class Controller* Other, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44661);
			byte params[12] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44665);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustSkill(class AIController* B, class PlayerController* P, bool bWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44671);
			byte params[12] = { NULL };
			*(class AIController**)params = B;
			*(class PlayerController**)&params[4] = P;
			*(bool*)&params[8] = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44676);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = KilledPlayer;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitGame(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44695);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
		void GenericPlayerInitialization(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44700);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPause(class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44702);
			byte params[20] = { NULL };
			*(class PlayerController**)params = PC;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		int LevelRecommendedPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44706);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		class PlayerController* Login(ScriptString* Portal, ScriptString* Options, OnlineSubsystem::UniqueNetId UniqueId, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44711);
			byte params[48] = { NULL };
			*(ScriptString**)params = Portal;
			*(ScriptString**)&params[12] = Options;
			*(OnlineSubsystem::UniqueNetId*)&params[24] = UniqueId;
			*(ScriptString**)&params[32] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[32];
			return *(class PlayerController**)&params[44];
		}
		bool ShouldRespawn(class PickupFactory* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44721);
			byte params[8] = { NULL };
			*(class PickupFactory**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44724);
			byte params[8] = { NULL };
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float SpawnWait(class AIController* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44727);
			byte params[8] = { NULL };
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void RestartGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44731);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44732);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44738);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AtCapacity(bool bSpectator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44742);
			byte params[8] = { NULL };
			*(bool*)params = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44747);
			byte params[4] = { NULL };
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameSettingsCounts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44751);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AssignHoverboard(class UTPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44755);
			byte params[4] = { NULL };
			*(class UTPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44757);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void RestartPlayer(class Controller* aPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44760);
			byte params[4] = { NULL };
			*(class Controller**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CampaignSkillAdjust(class UTBot* aBot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44768);
			byte params[4] = { NULL };
			*(class UTBot**)params = aBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDefaultInventory(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44770);
			byte params[4] = { NULL };
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44777);
			byte params[12] = { NULL };
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)&params[4] = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ChangeName(class Controller* Other, ScriptString* S, bool bNameChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44781);
			byte params[20] = { NULL };
			*(class Controller**)params = Other;
			*(ScriptString**)&params[4] = S;
			*(bool*)&params[16] = bNameChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44786);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			*(class Controller**)&params[4] = Killer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44790);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KillBots()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44795);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillOthers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44797);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillThis()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44801);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillBot(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44804);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44806);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class UTBot* AddBot(ScriptString* BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44808);
			byte params[24] = { NULL };
			*(ScriptString**)params = BotName;
			*(bool*)&params[12] = bUseTeamIndex;
			*(int*)&params[16] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTBot**)&params[20];
		}
		class UTBot* SpawnBot(ScriptString* BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44815);
			byte params[24] = { NULL };
			*(ScriptString**)params = BotName;
			*(bool*)&params[12] = bUseTeamIndex;
			*(int*)&params[16] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTBot**)&params[20];
		}
		void InitializeBot(class UTBot* NewBot, class UTTeamInfo* BotTeam, UTCharInfo::CharacterInfo& BotInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44825);
			byte params[120] = { NULL };
			*(class UTBot**)params = NewBot;
			*(class UTTeamInfo**)&params[4] = BotTeam;
			*(UTCharInfo::CharacterInfo*)&params[8] = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BotInfo = *(UTCharInfo::CharacterInfo*)&params[8];
		}
		void InitGameReplicationInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44834);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetMapTypeRule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44844);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetEndGameConditionRule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44846);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void NotifySpree(class UTPlayerReplicationInfo* Other, int Num)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44848);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = Other;
			*(int*)&params[4] = Num;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndSpree(class UTPlayerReplicationInfo* Killer, class UTPlayerReplicationInfo* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44853);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = Killer;
			*(class UTPlayerReplicationInfo**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameplayMuteList(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44857);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetupPlayerMuteList(class UTPlayerController* PC, bool bForceSpectatorChannel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44860);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bForceSpectatorChannel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePlayerFromMuteLists(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44869);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetAllPlayerMuteListsToSpectatorChannel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44872);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44874);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44877);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndLogging(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44885);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptString* IncomingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44887);
			byte params[21] = { NULL };
			*(class Controller**)params = Player;
			params[4] = InTeam;
			*(ScriptString**)&params[8] = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[20];
		}
		bool DominatingVictory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44893);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsAWinner(class PlayerController* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44895);
			byte params[8] = { NULL };
			*(class PlayerController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44898);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRegularEndOfMatchMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44900);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44902);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndRound(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44905);
			byte params[4] = { NULL };
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MatchIsInProgress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44908);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void AddInitialBots()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44910);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalculatedNetSpeed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44912);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool IsConsoleDedicatedServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44915);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45001);
			byte params[9] = { NULL };
			*(class Controller**)params = Player;
			params[4] = InTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerStart**)&params[8];
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45014);
			byte params[13] = { NULL };
			*(class PlayerStart**)params = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool CheckMaxLives(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45023);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45029);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RegisterVehicle(class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45034);
			byte params[4] = { NULL };
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivateVehicleFactory(class UTVehicleFactory* VF)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45036);
			byte params[4] = { NULL };
			*(class UTVehicleFactory**)params = VF;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45043);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMutator(ScriptString* mutname, bool bUserAdded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45049);
			byte params[16] = { NULL };
			*(ScriptString**)params = mutname;
			*(bool*)&params[12] = bUserAdded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowClientToTeleport(class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45052);
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)params = ClientPRI;
			*(class Actor**)&params[4] = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ShowPathTo(class PlayerController* P, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45056);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45059);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void PostSeamlessTravel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45064);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45067);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)params;
		}
		class UTMutator* GetBaseUTMutator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45074);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTMutator**)params;
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45078);
			byte params[16] = { NULL };
			*(class UTPlayerController**)params = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
		}
		void WriteOnlinePlayerScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45083);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetCurrentMapCycleIndex(ScriptArray<ScriptString*>& MapList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45090);
			byte params[16] = { NULL };
			*(ScriptArray<ScriptString*>*)params = MapList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MapList = *(ScriptArray<ScriptString*>*)params;
			return *(int*)&params[12];
		}
		ScriptString* GetNextMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45094);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ProcessServerTravel(ScriptString* URL, bool bAbsolute)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45099);
			byte params[16] = { NULL };
			*(ScriptString**)params = URL;
			*(bool*)&params[12] = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ContinueSeamlessTravel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetEndOfMatchRules(int InGoalScore, int InTimeLimit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45104);
			byte params[20] = { NULL };
			*(int*)params = InGoalScore;
			*(int*)&params[4] = InTimeLimit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45109);
			byte params[20] = { NULL };
			*(class Pawn**)params = StatusPawn;
			*(class Actor**)&params[4] = LocationObject;
			*(int*)&params[8] = MessageIndex;
			*(int*)&params[12] = LocationSpeechOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LocationObject = *(class Actor**)&params[4];
			MessageIndex = *(int*)&params[8];
			return *(bool*)&params[16];
		}
		bool AllowCheats(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45121);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UpdateGameSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45124);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
