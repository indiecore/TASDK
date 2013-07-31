#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.OnlineGameSettings.h"
#include "IpDrv.OnlineSubsystemCommonImpl.h"
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
	class OnlineGameInterfaceImpl : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, CreateOnlineGameCompleteDelegates, 84)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, UpdateOnlineGameCompleteDelegates, 96)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, DestroyOnlineGameCompleteDelegates, 108)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, JoinOnlineGameCompleteDelegates, 120)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, MigrateOnlineGameCompleteDelegates, 132)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, JoinMigratedOnlineGameCompleteDelegates, 144)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, RecalculateSkillRatingCompleteDelegates, 156)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, StartOnlineGameCompleteDelegates, 168)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, EndOnlineGameCompleteDelegates, 180)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, FindOnlineGamesCompleteDelegates, 192)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, CancelFindOnlineGamesCompleteDelegates, 204)
		ADD_STRUCT(Object::Pointer, SessionInfo, 240)
		ADD_STRUCT(Object::Pointer, LanBeacon, 236)
		ADD_STRUCT(float, LanQueryTimeout, 232)
		ADD_STRUCT(float, LanQueryTimeLeft, 228)
		ADD_STRUCT(int, LanPacketPlatformMask, 224)
		ADD_STRUCT(int, LanGameUniqueId, 220)
		ADD_STRUCT(int, LanAnnouncePort, 216)
		ADD_STRUCT(byte, LanNonce, 74)
		ADD_STRUCT(OnlineSubsystem::ELanBeaconState, LanBeaconState, 73)
		ADD_STRUCT(OnlineSubsystem::EOnlineGameState, CurrentGameState, 72)
		ADD_OBJECT(OnlineGameSearch, GameSearch, 68)
		ADD_OBJECT(OnlineGameSettings, GameSettings, 64)
		ADD_OBJECT(OnlineSubsystemCommonImpl, OwningSubsystem, 60)
		void OnCreateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33378);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33381);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33384);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33387);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMigrateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33390);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinMigratedOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33393);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRecalculateSkillRatingComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33396);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStartOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33399);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33402);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33405);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCancelFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33408);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQosStatusChanged(int NumComplete, int NumTotal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33410);
			byte params[8] = { NULL };
			*(int*)params = NumComplete;
			*(int*)&params[4] = NumTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33415);
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)params;
		}
		void OnArbitrationRegistrationComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33417);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33421);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33423);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class OnlineGameSettings* GetGameSettings(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33444);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		class OnlineGameSearch* GetGameSearch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33447);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSearch**)params;
		}
		bool CreateOnlineGame(byte HostingPlayerNum, ScriptName SessionName, class OnlineGameSettings* NewGameSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33449);
			byte params[17] = { NULL };
			*params = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(class OnlineGameSettings**)&params[12] = NewGameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddCreateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CreateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33456);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CreateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCreateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CreateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33458);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CreateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33461);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(class OnlineGameSettings**)&params[8] = UpdatedGameSettings;
			*(bool*)&params[12] = bShouldRefreshOnlineData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddUpdateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UpdateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33468);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UpdateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUpdateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UpdateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33470);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UpdateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DestroyOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33473);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddDestroyOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DestroyOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33478);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DestroyOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDestroyOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DestroyOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33480);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DestroyOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindOnlineGames(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33483);
			byte params[9] = { NULL };
			*params = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33487);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33489);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CancelFindOnlineGames()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33492);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void AddCancelFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelFindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33495);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelFindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCancelFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelFindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33497);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelFindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FreeSearchResults(class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33500);
			byte params[8] = { NULL };
			*(class OnlineGameSearch**)params = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool JoinOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33503);
			byte params[21] = { NULL };
			*params = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		void AddJoinOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33510);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33512);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetResolvedConnectString(ScriptName SessionName, ScriptString*& ConnectInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33515);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptString**)&params[8] = ConnectInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ConnectInfo = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool RegisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33519);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasInvited;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void AddRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33527);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33529);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UnregisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33531);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33538);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33540);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StartOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33542);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddStartOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StartOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33547);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StartOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStartOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StartOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33549);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StartOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EndOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33552);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddEndOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EndOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33557);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EndOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearEndOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EndOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33559);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EndOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterForArbitration(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33562);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddArbitrationRegistrationCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ArbitrationRegistrationCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33567);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ArbitrationRegistrationCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearArbitrationRegistrationCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ArbitrationRegistrationCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33569);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ArbitrationRegistrationCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant> GetArbitratedPlayers(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33571);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant>*)&params[8];
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33576);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33579);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33582);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RecalculateSkillRating(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33586);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
			return *(bool*)&params[20];
		}
		void AddRecalculateSkillRatingCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecalculateSkillRatingCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33593);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RecalculateSkillRatingCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecalculateSkillRatingCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecalculateSkillRatingGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33595);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RecalculateSkillRatingGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MigrateOnlineGame(byte HostingPlayerNum, ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33598);
			byte params[13] = { NULL };
			*params = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddMigrateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MigrateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33604);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MigrateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMigrateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MigrateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33606);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MigrateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool JoinMigratedOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33609);
			byte params[21] = { NULL };
			*params = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		void AddJoinMigratedOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinMigratedOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33616);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinMigratedOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinMigratedOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinMigratedOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33618);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinMigratedOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33621);
			byte params[12] = { NULL };
			*(int*)params = StartAt;
			*(int*)&params[4] = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ReadPlatformSpecificSessionInfo(OnlineGameSearch::OnlineGameSearchResult& DesiredGame, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33625);
			byte params[13] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = DesiredGame;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)params;
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		bool ReadPlatformSpecificSessionInfoBySessionName(ScriptName SessionName, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33629);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		bool BindPlatformSpecificSessionToSearch(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33633);
			byte params[10] = { NULL };
			*params = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[88];
		}
		void AddQosStatusChangedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QosStatusChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33640);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = QosStatusChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQosStatusChangedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QosStatusChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33642);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = QosStatusChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
