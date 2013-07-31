#pragma once
#include "Engine.PlayerController.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.Info.h"
#include "Engine.AutoTestManager.h"
#include "Engine.GameReplicationInfo.h"
#include "Engine.BroadcastHandler.h"
#include "Engine.Mutator.h"
#include "Engine.HUD.h"
#include "Engine.AccessControl.h"
#include "Engine.CoverReplicator.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.Pawn.h"
#include "Engine.NavigationPoint.h"
#include "Core.Object.h"
#include "Engine.PlayerStart.h"
#include "Engine.PickupFactory.h"
#include "Engine.Vehicle.h"
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
	class GameInfo : public Info
	{
	public:
		enum EStandbyType : byte
		{
			STDBY_Rx = 0,
			STDBY_Tx = 1,
			STDBY_BadPing = 2,
			STDBY_MAX = 3,
		};
		struct GameClassShortName
		{
		public:
			ADD_STRUCT(ScriptString*, GameClassName, 12)
			ADD_STRUCT(ScriptString*, ShortName, 0)
		};
		struct GameTypePrefix
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, AdditionalGameTypes, 28)
			ADD_STRUCT(ScriptArray<ScriptString*>, ForcedObjects, 40)
			ADD_STRUCT(ScriptString*, GameType, 16)
			ADD_BOOL(bUsesCommonPackage, 12, 0x1)
			ADD_STRUCT(ScriptString*, Prefix, 0)
		};
		ADD_STRUCT(int, NumPlayers, 584)
		ADD_OBJECT(ScriptClass, GameMessageClass, 644)
		ADD_OBJECT(ScriptClass, PlayerReplicationInfoClass, 680)
		ADD_STRUCT(ScriptString*, DefaultPlayerName, 600)
		ADD_STRUCT(float, MaxTimeMargin, 696)
		ADD_BOOL(bRequiresPushToTalk, 476, 0x400000)
		ADD_BOOL(bTeamGame, 476, 0x4)
		ADD_BOOL(bWaitingToStartMatch, 476, 0x40)
		ADD_STRUCT(int, ArbitratedLeaderboardId, 752)
		ADD_STRUCT(float, GameDifficulty, 544)
		ADD_STRUCT(int, TimeLimit, 636)
		ADD_STRUCT(ScriptString*, CauseEventCommand, 480)
		ADD_BOOL(bHasNetworkError, 476, 0x200000)
		ADD_BOOL(bRestartLevel, 476, 0x1)
		ADD_STRUCT(int, AdjustedNetSpeed, 776)
		ADD_STRUCT(int, MaxDynamicBandwidth, 792)
		ADD_STRUCT(float, GameSpeed, 552)
		ADD_OBJECT(GameReplicationInfo, GameReplicationInfo, 688)
		ADD_OBJECT(ScriptClass, GameReplicationInfoClass, 684)
		ADD_OBJECT(CoverReplicator, CoverReplicatorBase, 756)
		ADD_STRUCT(ScriptString*, GameName, 612)
		ADD_BOOL(bGameEnded, 476, 0x8)
		ADD_BOOL(bOverTime, 476, 0x10)
		ADD_OBJECT(BroadcastHandler, BroadcastHandler, 664)
		ADD_BOOL(bDoFearCostFallOff, 476, 0x80000)
		ADD_OBJECT(AccessControl, AccessControl, 656)
		ADD_STRUCT(int, NumTravellingPlayers, 592)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, Pausers, 720)
		ADD_STRUCT(int, MaxPlayers, 576)
		ADD_STRUCT(int, MaxPlayersAllowed, 580)
		ADD_STRUCT(int, MaxSpectators, 564)
		ADD_STRUCT(int, MaxSpectatorsAllowed, 568)
		ADD_OBJECT(ScriptClass, BroadcastHandlerClass, 660)
		ADD_OBJECT(ScriptClass, AccessControlClass, 652)
		ADD_BOOL(bFixedPlayerStart, 476, 0x40000)
		ADD_OBJECT(AutoTestManager, MyAutoTestManager, 672)
		ADD_OBJECT(ScriptClass, AutoTestManagerClass, 668)
		ADD_STRUCT(ScriptString*, BugLocString, 492)
		ADD_STRUCT(ScriptString*, BugRotString, 504)
		ADD_OBJECT(Mutator, BaseMutator, 648)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 732)
		ADD_BOOL(bUsingArbitration, 476, 0x2000)
		ADD_STRUCT(ScriptString*, ServerOptions, 764)
		ADD_BOOL(bLevelChange, 476, 0x800)
		ADD_BOOL(bUseSeamlessTravel, 476, 0x100000)
		ADD_BOOL(bHasArbitratedHandshakeBegun, 476, 0x4000)
		ADD_STRUCT(int, NumSpectators, 572)
		ADD_OBJECT(ScriptClass, PlayerControllerClass, 676)
		ADD_BOOL(bDelayedStart, 476, 0x20)
		ADD_OBJECT(ScriptClass, DefaultPawnClass, 556)
		ADD_OBJECT(ScriptClass, HUDType, 560)
		ADD_STRUCT(float, LastNetSpeedUpdateTime, 780)
		ADD_STRUCT(int, TotalNetBandwidth, 784)
		ADD_STRUCT(int, MinDynamicBandwidth, 788)
		ADD_BOOL(bHasEndGameHandshakeBegun, 476, 0x20000)
		ADD_STRUCT(ScriptArray<class PlayerController*>, ArbitrationPCs, 528)
		ADD_OBJECT(ScriptClass, DeathMessageClass, 640)
		ADD_BOOL(bIsEndGameHandshakeComplete, 476, 0x10000)
		ADD_BOOL(bGameRestarted, 476, 0x400)
		ADD_BOOL(bChangeLevels, 476, 0x80)
		ADD_BOOL(bAlreadyChanged, 476, 0x100)
		ADD_OBJECT(ScriptClass, OnlineStatsWriteClass, 744)
		ADD_STRUCT(int, LeaderboardId, 748)
		ADD_STRUCT(ScriptArray<class PlayerController*>, PendingArbitrationPCs, 516)
		ADD_STRUCT(int, MaxLives, 632)
		ADD_BOOL(bPauseable, 476, 0x2)
		ADD_BOOL(bAdminCanPause, 476, 0x200)
		ADD_STRUCT(ScriptArray<class PlayerReplicationInfo*>, InactivePRIArray, 708)
		ADD_STRUCT(int, NumBots, 588)
		ADD_STRUCT(float, ArbitrationHandshakeTimeout, 540)
		ADD_BOOL(bNeedsEndGameHandshake, 476, 0x8000)
		ADD_OBJECT(ScriptClass, OnlineGameSettingsClass, 760)
		ADD_BOOL(bKickLiveIdlers, 476, 0x1000)
		ADD_BOOL(bIsStandbyCheckingEnabled, 476, 0x800000)
		ADD_BOOL(bIsStandbyCheckingOn, 476, 0x1000000)
		ADD_BOOL(bHasStandbyCheatTriggered, 476, 0x2000000)
		ADD_STRUCT(int, GoreLevel, 548)
		ADD_STRUCT(int, CurrentID, 596)
		ADD_STRUCT(float, FearCostFallOff, 624)
		ADD_STRUCT(int, GoalScore, 628)
		ADD_STRUCT(float, MaxIdleTime, 692)
		ADD_STRUCT(float, TimeMarginSlack, 700)
		ADD_STRUCT(float, MinTimeMargin, 704)
		ADD_STRUCT(float, StandbyRxCheatTime, 796)
		ADD_STRUCT(float, StandbyTxCheatTime, 800)
		ADD_STRUCT(int, BadPingThreshold, 804)
		ADD_STRUCT(float, PercentMissingForRxStandby, 808)
		ADD_STRUCT(float, PercentMissingForTxStandby, 812)
		ADD_STRUCT(float, PercentForBadPing, 816)
		ADD_STRUCT(float, JoinInProgressStandbyWaitTime, 820)
		ADD_STRUCT(ScriptArray<GameInfo::GameClassShortName>, GameInfoClassAliases, 824)
		ADD_STRUCT(ScriptString*, DefaultGameType, 836)
		ADD_STRUCT(ScriptArray<GameInfo::GameTypePrefix>, DefaultMapPrefixes, 848)
		ADD_STRUCT(ScriptArray<GameInfo::GameTypePrefix>, CustomMapPrefixes, 860)
		bool CheckRelevance(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4029);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* ParseOption(ScriptString* Options, ScriptString* InKey)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5760);
			byte params[36] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = InKey;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		bool AtCapacity(bool bSpectator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5772);
			byte params[8] = { NULL };
			*(bool*)params = bSpectator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ForceClearUnpauseDelegates(class Actor* PauseActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7599);
			byte params[4] = { NULL };
			*(class Actor**)params = PauseActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsAutomatedPerfTesting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7611);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SetPause(class PlayerController* PC, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8306);
			byte params[20] = { NULL };
			*(class PlayerController**)params = PC;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ChangeTeam(class Controller* Other, int N, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8397);
			byte params[16] = { NULL };
			*(class Controller**)params = Other;
			*(int*)&params[4] = N;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8743);
			byte params[12] = { NULL };
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)&params[4] = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool PlayerCanRestartGame(class PlayerController* aPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8890);
			byte params[8] = { NULL };
			*(class PlayerController**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlayerCanRestart(class PlayerController* aPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8947);
			byte params[8] = { NULL };
			*(class PlayerController**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsDoingASentinelRun()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9459);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class CoverReplicator* GetCoverReplicator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13337);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CoverReplicator**)params;
		}
		bool PickupQuery(class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14811);
			byte params[16] = { NULL };
			*(class Pawn**)params = Other;
			*(ScriptClass**)&params[4] = ItemClass;
			*(class Actor**)&params[8] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetSupportedGameTypes(ScriptString*& InFilename, GameInfo::GameTypePrefix& OutGameType, bool bCheckExt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16748);
			byte params[72] = { NULL };
			*(ScriptString**)params = InFilename;
			*(GameInfo::GameTypePrefix*)&params[12] = OutGameType;
			*(bool*)&params[64] = bCheckExt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InFilename = *(ScriptString**)params;
			OutGameType = *(GameInfo::GameTypePrefix*)&params[12];
			return *(bool*)&params[68];
		}
		bool GetMapCommonPackageName(ScriptString*& InFilename, ScriptString*& OutCommonPackageName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16753);
			byte params[28] = { NULL };
			*(ScriptString**)params = InFilename;
			*(ScriptString**)&params[12] = OutCommonPackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InFilename = *(ScriptString**)params;
			OutCommonPackageName = *(ScriptString**)&params[12];
			return *(bool*)&params[24];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16757);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16764);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16765);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16771);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldReset(class Actor* ActorToReset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16774);
			byte params[8] = { NULL };
			*(class Actor**)params = ActorToReset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ResetLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16777);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16786);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoNavFearCostFallOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16789);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNavigationChanged(class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16790);
			byte params[4] = { NULL };
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameEnding()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16792);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickIdler(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16793);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceKickPlayer(class PlayerController* PC, ScriptString* KickReason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16796);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(ScriptString**)&params[4] = KickReason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitGameReplicationInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16799);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetNetworkNumber()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16800);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		int GetNumPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16802);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CanUnpause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16805);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16812);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16816);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetGameSpeed(float T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16819);
			byte params[4] = { NULL };
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GrabOption(ScriptString*& Options, ScriptString*& Result)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16821);
			byte params[28] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = Result;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Options = *(ScriptString**)params;
			Result = *(ScriptString**)&params[12];
			return *(bool*)&params[24];
		}
		void GetKeyValue(ScriptString* Pair, ScriptString*& Key, ScriptString*& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16825);
			byte params[36] = { NULL };
			*(ScriptString**)params = Pair;
			*(ScriptString**)&params[12] = Key;
			*(ScriptString**)&params[24] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Key = *(ScriptString**)&params[12];
			Value = *(ScriptString**)&params[24];
		}
		bool HasOption(ScriptString* Options, ScriptString* InKey)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16834);
			byte params[28] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = InKey;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		int GetIntOption(ScriptString* Options, ScriptString* ParseString, int CurrentValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16841);
			byte params[32] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ParseString;
			*(int*)&params[24] = CurrentValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[28];
		}
		ScriptString* GetDefaultGameClassPath(ScriptString* MapName, ScriptString* Options, ScriptString* Portal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16847);
			byte params[48] = { NULL };
			*(ScriptString**)params = MapName;
			*(ScriptString**)&params[12] = Options;
			*(ScriptString**)&params[24] = Portal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[36];
		}
		ScriptClass* SetGameType(ScriptString* MapName, ScriptString* Options, ScriptString* Portal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16852);
			byte params[40] = { NULL };
			*(ScriptString**)params = MapName;
			*(ScriptString**)&params[12] = Options;
			*(ScriptString**)&params[24] = Portal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[36];
		}
		void InitGame(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16857);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
		void NotifyPendingConnectionLost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16881);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddMutator(ScriptString* mutname, bool bUserAdded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16882);
			byte params[16] = { NULL };
			*(ScriptString**)params = mutname;
			*(bool*)&params[12] = bUserAdded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveMutator(class Mutator* MutatorToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16891);
			byte params[4] = { NULL };
			*(class Mutator**)params = MutatorToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessServerTravel(ScriptString* URL, bool bAbsolute)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16894);
			byte params[16] = { NULL };
			*(ScriptString**)params = URL;
			*(bool*)&params[12] = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PlayerController* ProcessClientTravel(ScriptString*& URL, Object::Guid NextMapGuid, bool bSeamless, bool bAbsolute)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16904);
			byte params[40] = { NULL };
			*(ScriptString**)params = URL;
			*(Object::Guid*)&params[12] = NextMapGuid;
			*(bool*)&params[28] = bSeamless;
			*(bool*)&params[32] = bAbsolute;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
			return *(class PlayerController**)&params[36];
		}
		bool RequiresPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16912);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PreLogin(ScriptString* Options, ScriptString* Address, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16914);
			byte params[36] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = Address;
			*(ScriptString**)&params[24] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[24];
		}
		int GetNextPlayerID()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16923);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		class PlayerController* SpawnPlayerController(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16925);
			byte params[28] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)&params[24];
		}
		class PlayerController* Login(ScriptString* Portal, ScriptString* Options, OnlineSubsystem::UniqueNetId UniqueId, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16930);
			byte params[48] = { NULL };
			*(ScriptString**)params = Portal;
			*(ScriptString**)&params[12] = Options;
			*(OnlineSubsystem::UniqueNetId*)&params[24] = UniqueId;
			*(ScriptString**)&params[32] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[32];
			return *(class PlayerController**)&params[44];
		}
		void StartMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16949);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartOnlineGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16953);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartHumans()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16960);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartBots()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16962);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16964);
			byte params[4] = { NULL };
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Pawn* SpawnDefaultPawnFor(class Controller* NewPlayer, class NavigationPoint* StartSpot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16974);
			byte params[12] = { NULL };
			*(class Controller**)params = NewPlayer;
			*(class NavigationPoint**)&params[4] = StartSpot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)&params[8];
		}
		ScriptClass* GetDefaultPlayerClass(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16981);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		void ReplicateStreamingStatus(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16985);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GenericPlayerInitialization(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16992);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int BestNextHostSort(class PlayerController* A, class PlayerController* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16996);
			byte params[12] = { NULL };
			*(class PlayerController**)params = A;
			*(class PlayerController**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void UpdateBestNextHosts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17002);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17010);
			byte params[4] = { NULL };
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateNetSpeeds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalculatedNetSpeed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17027);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void PreExit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17031);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17032);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnregisterPlayer(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17038);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AcceptInventory(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17040);
			byte params[4] = { NULL };
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDefaultInventory(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17042);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Mutate(ScriptString* MutateString, class PlayerController* Sender)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17044);
			byte params[16] = { NULL };
			*(ScriptString**)params = MutateString;
			*(class PlayerController**)&params[12] = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerDefaults(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17047);
			byte params[4] = { NULL };
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17049);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17055);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = KilledPlayer;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PreventDeath(class Pawn* KilledPawn, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17060);
			byte params[28] = { NULL };
			*(class Pawn**)params = KilledPawn;
			*(class Controller**)&params[4] = Killer;
			*(ScriptClass**)&params[8] = DamageType;
			*(Vector*)&params[12] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void BroadcastDeathMessage(class Controller* Killer, class Controller* Other, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17068);
			byte params[12] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Kick(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17073);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickBan(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17075);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReduceDamage(int& Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17079);
			byte params[44] = { NULL };
			*(int*)params = Damage;
			*(class Pawn**)&params[4] = injured;
			*(class Controller**)&params[8] = InstigatedBy;
			*(Vector*)&params[12] = HitLocation;
			*(Vector*)&params[24] = Momentum;
			*(ScriptClass**)&params[36] = DamageType;
			*(class Actor**)&params[40] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)&params[24];
		}
		bool ShouldRespawn(class PickupFactory* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17093);
			byte params[8] = { NULL };
			*(class PickupFactory**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17104);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			*(class Controller**)&params[4] = Killer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeName(class Controller* Other, ScriptString* S, bool bNameChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17107);
			byte params[20] = { NULL };
			*(class Controller**)params = Other;
			*(ScriptString**)&params[4] = S;
			*(bool*)&params[16] = bNameChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte PickTeam(byte Current, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17114);
			byte params[6] = { NULL };
			*params = Current;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		void SendPlayer(class PlayerController* aPlayer, ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17118);
			byte params[16] = { NULL };
			*(class PlayerController**)params = aPlayer;
			*(ScriptString**)&params[4] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetNextMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17121);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool GetTravelType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17123);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RestartGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17125);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Broadcast(class Actor* Sender, ScriptString* msg, ScriptName Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17137);
			byte params[24] = { NULL };
			*(class Actor**)params = Sender;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTeam(class Controller* Sender, ScriptString* msg, ScriptName Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17141);
			byte params[24] = { NULL };
			*(class Controller**)params = Sender;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastLocalized(class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17145);
			byte params[24] = { NULL };
			*(class Actor**)params = Sender;
			*(ScriptClass**)&params[4] = Message;
			*(int*)&params[8] = Switch;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_2;
			*(class Object**)&params[20] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastLocalizedTeam(int TeamIndex, class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17152);
			byte params[28] = { NULL };
			*(int*)params = TeamIndex;
			*(class Actor**)&params[4] = Sender;
			*(ScriptClass**)&params[8] = Message;
			*(int*)&params[12] = Switch;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[20] = RelatedPRI_2;
			*(class Object**)&params[24] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckModifiedEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17160);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17166);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void WriteOnlineStats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17171);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WriteOnlinePlayerScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17176);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceRoundStart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17179);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17180);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PerformEndGameHandling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17183);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndOnlineGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17185);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameEventsPoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17187);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndLogging(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17188);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSpawnAtStartSpot(class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17190);
			byte params[8] = { NULL };
			*(class Controller**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptString* IncomingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17194);
			byte params[21] = { NULL };
			*(class Controller**)params = Player;
			params[4] = InTeam;
			*(ScriptString**)&params[8] = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[20];
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17204);
			byte params[9] = { NULL };
			*(class Controller**)params = Player;
			params[4] = InTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerStart**)&params[8];
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17213);
			byte params[13] = { NULL };
			*(class PlayerStart**)params = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void AddObjectiveScore(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17222);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreObjective(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17225);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17228);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17231);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17236);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17239);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanLeaveVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17242);
			byte params[12] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17248);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowMutator(ScriptString* MutatorClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17253);
			byte params[16] = { NULL };
			*(ScriptString**)params = MutatorClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AllowCheats(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17256);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowPausing(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17259);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PreCommitMapChange(ScriptString* PreviousMapName, ScriptString* NextMapName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17264);
			byte params[24] = { NULL };
			*(ScriptString**)params = PreviousMapName;
			*(ScriptString**)&params[12] = NextMapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostCommitMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddInactivePRI(class PlayerReplicationInfo* PRI, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17268);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindInactivePRI(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17279);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetPRI(class PlayerController* PC, class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17289);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)&params[4] = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OverridePRI(class PlayerController* PC, class PlayerReplicationInfo* OldPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17292);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)&params[4] = OldPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17295);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void SwapPlayerControllers(class PlayerController* OldPC, class PlayerController* NewPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17300);
			byte params[8] = { NULL };
			*(class PlayerController**)params = OldPC;
			*(class PlayerController**)&params[4] = NewPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostSeamlessTravel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17303);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGameSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17306);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17307);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)params;
		}
		void SetSeamlessTravelViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17314);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameSettingsCounts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17316);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessClientRegistrationCompletion(class PlayerController* PC, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17319);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartArbitrationRegistration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17322);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartArbitratedMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17323);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterServerForArbitration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17324);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ArbitrationRegistrationComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17325);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MatchIsInProgress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17328);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void NotifyArbitratedMatchEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17354);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateGameplayMuteList(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17356);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RecalculateSkillRating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17358);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MatineeCancelled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessServerLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17366);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearAutoLoginDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17370);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginFailed(byte LocalUserNum, OnlineSubsystem::EOnlineServerConnectionStatus ErrorCode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17371);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[1] = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17374);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RegisterServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17376);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnServerCreateComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17381);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellClientsToReturnToPartyHost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17385);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsToTravelToSession(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17389);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoTravelTheWorld()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17394);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsCheckingForFragmentation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17396);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsCheckingForMemLeaks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17398);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldAutoContinueToNextRound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17400);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheckForSentinelRun()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17402);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void BeginBVT(ScriptString* TagDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17404);
			byte params[12] = { NULL };
			*(ScriptString**)params = TagDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableStandbyCheatDetection(bool bIsEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17406);
			byte params[4] = { NULL };
			*(bool*)params = bIsEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StandbyCheatDetected(GameInfo::EStandbyType StandbyType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17408);
			byte params[1] = { NULL };
			*(GameInfo::EStandbyType*)params = StandbyType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEngineHasLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17410);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
