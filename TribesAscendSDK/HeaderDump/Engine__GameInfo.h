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
		bool CheckRelevance(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CheckRelevance");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ParseOption(ScriptArray<wchar_t> Options, ScriptArray<wchar_t> InKey)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ParseOption");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = InKey;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		bool AtCapacity(bool bSpectator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AtCapacity");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceClearUnpauseDelegates(class Actor* PauseActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ForceClearUnpauseDelegates");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = PauseActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsAutomatedPerfTesting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.IsAutomatedPerfTesting");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SetPause(class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetPause");
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
		bool ChangeTeam(class Controller* Other, int N, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ChangeTeam");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Other;
			*(int*)(params + 4) = N;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CanSpectate");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)(params + 4) = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool PlayerCanRestartGame(class PlayerController* aPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PlayerCanRestartGame");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PlayerCanRestart(class PlayerController* aPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PlayerCanRestart");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsDoingASentinelRun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.IsDoingASentinelRun");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class CoverReplicator* GetCoverReplicator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetCoverReplicator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class CoverReplicator**)params;
			free(params);
			return returnVal;
		}
		bool PickupQuery(class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PickupQuery");
			byte* params = (byte*)malloc(16);
			*(class Pawn**)params = Other;
			*(ScriptClass**)(params + 4) = ItemClass;
			*(class Actor**)(params + 8) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetSupportedGameTypes(ScriptArray<wchar_t>& InFilename, 
// WARNING: Unknown structure type 'ScriptStruct Engine.GameInfo.GameTypePrefix'!
void*& OutGameType, bool bCheckExt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetSupportedGameTypes");
			byte* params = (byte*)malloc(72);
			*(ScriptArray<wchar_t>*)params = InFilename;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.GameInfo.GameTypePrefix'!
void**)(params + 12) = OutGameType;
			*(bool*)(params + 64) = bCheckExt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InFilename = *(ScriptArray<wchar_t>*)params;
			OutGameType = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.GameInfo.GameTypePrefix'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 68);
			free(params);
			return returnVal;
		}
		bool GetMapCommonPackageName(ScriptArray<wchar_t>& InFilename, ScriptArray<wchar_t>& OutCommonPackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetMapCommonPackageName");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = InFilename;
			*(ScriptArray<wchar_t>*)(params + 12) = OutCommonPackageName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InFilename = *(ScriptArray<wchar_t>*)params;
			OutCommonPackageName = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldReset(class Actor* ActorToReset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ShouldReset");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = ActorToReset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoNavFearCostFallOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DoNavFearCostFallOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNavigationChanged(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.NotifyNavigationChanged");
			byte* params = (byte*)malloc(4);
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GameEnding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GameEnding");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickIdler(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.KickIdler");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceKickPlayer(class PlayerController* PC, ScriptArray<wchar_t> KickReason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ForceKickPlayer");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = PC;
			*(ScriptArray<wchar_t>*)(params + 4) = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitGameReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.InitGameReplicationInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetNetworkNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetNetworkNumber");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		int GetNumPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetNumPlayers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CanUnpause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CanUnpause");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClearPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ClearPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DebugPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetGameSpeed(float T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetGameSpeed");
			byte* params = (byte*)malloc(4);
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GrabOption(ScriptArray<wchar_t>& Options, ScriptArray<wchar_t>& Result)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GrabOption");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = Result;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Options = *(ScriptArray<wchar_t>*)params;
			Result = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void GetKeyValue(ScriptArray<wchar_t> Pair, ScriptArray<wchar_t>& Key, ScriptArray<wchar_t>& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetKeyValue");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Pair;
			*(ScriptArray<wchar_t>*)(params + 12) = Key;
			*(ScriptArray<wchar_t>*)(params + 24) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Key = *(ScriptArray<wchar_t>*)(params + 12);
			Value = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
		}
		bool HasOption(ScriptArray<wchar_t> Options, ScriptArray<wchar_t> InKey)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.HasOption");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = InKey;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		int GetIntOption(ScriptArray<wchar_t> Options, ScriptArray<wchar_t> ParseString, int CurrentValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetIntOption");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ParseString;
			*(int*)(params + 24) = CurrentValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 28);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetDefaultGameClassPath(ScriptArray<wchar_t> MapName, ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetDefaultGameClassPath");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = MapName;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(ScriptArray<wchar_t>*)(params + 24) = Portal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 36);
			free(params);
			return returnVal;
		}
		ScriptClass* SetGameType(ScriptArray<wchar_t> MapName, ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetGameType");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = MapName;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(ScriptArray<wchar_t>*)(params + 24) = Portal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 36);
			free(params);
			return returnVal;
		}
		void InitGame(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.InitGame");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		void NotifyPendingConnectionLost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.NotifyPendingConnectionLost");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddMutator(ScriptArray<wchar_t> mutname, bool bUserAdded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AddMutator");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = mutname;
			*(bool*)(params + 12) = bUserAdded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveMutator(class Mutator* MutatorToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RemoveMutator");
			byte* params = (byte*)malloc(4);
			*(class Mutator**)params = MutatorToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessServerTravel(ScriptArray<wchar_t> URL, bool bAbsolute)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ProcessServerTravel");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = URL;
			*(bool*)(params + 12) = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PlayerController* ProcessClientTravel(ScriptArray<wchar_t>& URL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid'!
void* NextMapGuid, bool bSeamless, bool bAbsolute)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ProcessClientTravel");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = URL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid'!
void**)(params + 12) = NextMapGuid;
			*(bool*)(params + 28) = bSeamless;
			*(bool*)(params + 32) = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(class PlayerController**)(params + 36);
			free(params);
			return returnVal;
		}
		bool RequiresPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RequiresPassword");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PreLogin(ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Address, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PreLogin");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = Address;
			*(ScriptArray<wchar_t>*)(params + 24) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
		}
		int GetNextPlayerID()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetNextPlayerID");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		class PlayerController* SpawnPlayerController(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SpawnPlayerController");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = SpawnLocation;
			*(Rotator*)(params + 12) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerController**)(params + 24);
			free(params);
			return returnVal;
		}
		class PlayerController* Login(ScriptArray<wchar_t> Portal, ScriptArray<wchar_t> Options, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Login");
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
		void StartMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartOnlineGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartOnlineGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OnStartOnlineGameComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartHumans()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartHumans");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Pawn* SpawnDefaultPawnFor(class Controller* NewPlayer, class NavigationPoint* StartSpot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SpawnDefaultPawnFor");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = NewPlayer;
			*(class NavigationPoint**)(params + 4) = StartSpot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptClass* GetDefaultPlayerClass(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetDefaultPlayerClass");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		void ReplicateStreamingStatus(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ReplicateStreamingStatus");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GenericPlayerInitialization(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GenericPlayerInitialization");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int BestNextHostSort(class PlayerController* A, class PlayerController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BestNextHostSort");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = A;
			*(class PlayerController**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void UpdateBestNextHosts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UpdateBestNextHosts");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PostLogin");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateNetSpeeds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UpdateNetSpeeds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalculatedNetSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CalculatedNetSpeed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void PreExit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PreExit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnregisterPlayer(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UnregisterPlayer");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AcceptInventory(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AcceptInventory");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDefaultInventory(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AddDefaultInventory");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Mutate(ScriptArray<wchar_t> MutateString, class PlayerController* Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Mutate");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MutateString;
			*(class PlayerController**)(params + 12) = Sender;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerDefaults(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetPlayerDefaults");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.NotifyKilled");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Killed");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = KilledPlayer;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PreventDeath(class Pawn* KilledPawn, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PreventDeath");
			byte* params = (byte*)malloc(28);
			*(class Pawn**)params = KilledPawn;
			*(class Controller**)(params + 4) = Killer;
			*(ScriptClass**)(params + 8) = DamageType;
			*(Vector*)(params + 12) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void BroadcastDeathMessage(class Controller* Killer, class Controller* Other, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BroadcastDeathMessage");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			*(ScriptClass**)(params + 8) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Kick(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Kick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KickBan(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.KickBan");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReduceDamage(int& Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ReduceDamage");
			byte* params = (byte*)malloc(44);
			*(int*)params = Damage;
			*(class Pawn**)(params + 4) = injured;
			*(class Controller**)(params + 8) = InstigatedBy;
			*(Vector*)(params + 12) = HitLocation;
			*(Vector*)(params + 24) = Momentum;
			*(ScriptClass**)(params + 36) = DamageType;
			*(class Actor**)(params + 40) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)(params + 24);
			free(params);
		}
		bool ShouldRespawn(class PickupFactory* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ShouldRespawn");
			byte* params = (byte*)malloc(8);
			*(class PickupFactory**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DiscardInventory");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			*(class Controller**)(params + 4) = Killer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeName(class Controller* Other, ScriptArray<wchar_t> S, bool bNameChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ChangeName");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Other;
			*(ScriptArray<wchar_t>*)(params + 4) = S;
			*(bool*)(params + 16) = bNameChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte PickTeam(byte Current, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PickTeam");
			byte* params = (byte*)malloc(6);
			*params = Current;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		void SendPlayer(class PlayerController* aPlayer, ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SendPlayer");
			byte* params = (byte*)malloc(16);
			*(class PlayerController**)params = aPlayer;
			*(ScriptArray<wchar_t>*)(params + 4) = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetNextMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetNextMap");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool GetTravelType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetTravelType");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RestartGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Broadcast(class Actor* Sender, ScriptArray<wchar_t> msg, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.Broadcast");
			byte* params = (byte*)malloc(24);
			*(class Actor**)params = Sender;
			*(ScriptArray<wchar_t>*)(params + 4) = msg;
			*(ScriptName*)(params + 16) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastTeam(class Controller* Sender, ScriptArray<wchar_t> msg, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BroadcastTeam");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Sender;
			*(ScriptArray<wchar_t>*)(params + 4) = msg;
			*(ScriptName*)(params + 16) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastLocalized(class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BroadcastLocalized");
			byte* params = (byte*)malloc(24);
			*(class Actor**)params = Sender;
			*(ScriptClass**)(params + 4) = Message;
			*(int*)(params + 8) = Switch;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 16) = RelatedPRI;
			*(class Object**)(params + 20) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastLocalizedTeam(int TeamIndex, class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BroadcastLocalizedTeam");
			byte* params = (byte*)malloc(28);
			*(int*)params = TeamIndex;
			*(class Actor**)(params + 4) = Sender;
			*(ScriptClass**)(params + 8) = Message;
			*(int*)(params + 12) = Switch;
			*(class PlayerReplicationInfo**)(params + 16) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 20) = RelatedPRI;
			*(class Object**)(params + 24) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckModifiedEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CheckModifiedEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void WriteOnlineStats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.WriteOnlineStats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WriteOnlinePlayerScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.WriteOnlinePlayerScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceRoundStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ForceRoundStart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PerformEndGameHandling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PerformEndGameHandling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndOnlineGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.EndOnlineGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameEventsPoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GameEventsPoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndLogging(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.EndLogging");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldSpawnAtStartSpot(class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ShouldSpawnAtStartSpot");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptArray<wchar_t> IncomingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.FindPlayerStart");
			byte* params = (byte*)malloc(21);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			*(ScriptArray<wchar_t>*)(params + 8) = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 20);
			free(params);
			return returnVal;
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ChoosePlayerStart");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddObjectiveScore(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AddObjectiveScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreObjective(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ScoreObjective");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ModifyScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DriverEnteredVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanLeaveVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CanLeaveVehicle");
			byte* params = (byte*)malloc(12);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DriverLeftVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowMutator(ScriptArray<wchar_t> MutatorClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AllowMutator");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AllowCheats(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AllowCheats");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowPausing(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AllowPausing");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PreCommitMapChange(ScriptArray<wchar_t> PreviousMapName, ScriptArray<wchar_t> NextMapName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PreCommitMapChange");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PreviousMapName;
			*(ScriptArray<wchar_t>*)(params + 12) = NextMapName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostCommitMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PostCommitMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddInactivePRI(class PlayerReplicationInfo* PRI, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.AddInactivePRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = PRI;
			*(class PlayerController**)(params + 4) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FindInactivePRI(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.FindInactivePRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetPRI(class PlayerController* PC, class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetPRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)(params + 4) = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OverridePRI(class PlayerController* PC, class PlayerReplicationInfo* OldPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OverridePRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)(params + 4) = OldPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.GetSeamlessTravelActorList");
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
		void SwapPlayerControllers(class PlayerController* OldPC, class PlayerController* NewPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SwapPlayerControllers");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = OldPC;
			*(class PlayerController**)(params + 4) = NewPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostSeamlessTravel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.PostSeamlessTravel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UpdateGameSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.HandleSeamlessTravelPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			C = *(class Controller**)params;
			free(params);
		}
		void SetSeamlessTravelViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.SetSeamlessTravelViewTarget");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameSettingsCounts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UpdateGameSettingsCounts");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessClientRegistrationCompletion(class PlayerController* PC, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ProcessClientRegistrationCompletion");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartArbitrationRegistration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartArbitrationRegistration");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartArbitratedMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StartArbitratedMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterServerForArbitration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RegisterServerForArbitration");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ArbitrationRegistrationComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ArbitrationRegistrationComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MatchIsInProgress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.MatchIsInProgress");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void NotifyArbitratedMatchEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.NotifyArbitratedMatchEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGameplayMuteList(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.UpdateGameplayMuteList");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RecalculateSkillRating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RecalculateSkillRating");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MatineeCancelled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.MatineeCancelled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessServerLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ProcessServerLogin");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClearAutoLoginDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ClearAutoLoginDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginFailed(byte LocalUserNum, byte ErrorCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OnLoginFailed");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			*(params + 1) = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RegisterServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.RegisterServer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnServerCreateComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OnServerCreateComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TellClientsToReturnToPartyHost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.TellClientsToReturnToPartyHost");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsToTravelToSession(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.TellClientsToTravelToSession");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoTravelTheWorld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.DoTravelTheWorld");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsCheckingForFragmentation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.IsCheckingForFragmentation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsCheckingForMemLeaks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.IsCheckingForMemLeaks");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldAutoContinueToNextRound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.ShouldAutoContinueToNextRound");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheckForSentinelRun()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.CheckForSentinelRun");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void BeginBVT(ScriptArray<wchar_t> TagDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.BeginBVT");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TagDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableStandbyCheatDetection(bool bIsEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.EnableStandbyCheatDetection");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StandbyCheatDetected(byte StandbyType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.StandbyCheatDetected");
			byte* params = (byte*)malloc(1);
			*params = StandbyType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnEngineHasLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameInfo.OnEngineHasLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
