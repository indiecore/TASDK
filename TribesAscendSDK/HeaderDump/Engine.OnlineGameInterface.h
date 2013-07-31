#pragma once
#include "Engine.OnlineGameSettings.h"
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineGameSearch.h"
namespace UnrealScript
{
	class OnlineGameInterface : public Interface
	{
	public:
		class OnlineGameSettings* GetGameSettings(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7674);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		bool EndOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7677);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7693);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool MigrateOnlineGame(byte HostingPlayerNum, ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7695);
			byte params[13] = { NULL };
			*params = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ReadPlatformSpecificSessionInfoBySessionName(ScriptName SessionName, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7711);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		bool BindPlatformSpecificSessionToSearch(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7735);
			byte params[10] = { NULL };
			*params = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[88];
		}
		bool JoinMigratedOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7741);
			byte params[21] = { NULL };
			*params = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		bool GetResolvedConnectString(ScriptName SessionName, ScriptString*& ConnectInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7747);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptString**)&params[8] = ConnectInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ConnectInfo = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool RegisterForArbitration(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9241);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9253);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool DestroyOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9272);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool StartOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9374);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool JoinOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9396);
			byte params[21] = { NULL };
			*params = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		bool RegisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16946);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasInvited;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool RecalculateSkillRating(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17363);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
			return *(bool*)&params[20];
		}
		bool CreateOnlineGame(byte HostingPlayerNum, ScriptName SessionName, class OnlineGameSettings* NewGameSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17379);
			byte params[17] = { NULL };
			*params = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(class OnlineGameSettings**)&params[12] = NewGameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnCreateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21627);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinMigratedOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21631);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMigrateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21633);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRecalculateSkillRatingComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21635);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21637);
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)params;
		}
		void OnArbitrationRegistrationComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21639);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21641);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStartOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21643);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21645);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21647);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21649);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQosStatusChanged(int NumComplete, int NumTotal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21651);
			byte params[8] = { NULL };
			*(int*)params = NumComplete;
			*(int*)&params[4] = NumTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCancelFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21653);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21655);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21657);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21659);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CreateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21661);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21663);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CreateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21665);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21672);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21674);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UpdateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDestroyOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DestroyOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21680);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21682);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DestroyOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindOnlineGames(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21684);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21689);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21691);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CancelFindOnlineGames()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21693);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void AddCancelFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelFindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21696);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21698);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelFindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddQosStatusChangedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QosStatusChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21702);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21704);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = QosStatusChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlatformSpecificSessionInfo(OnlineGameSearch::OnlineGameSearchResult& DesiredGame, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21706);
			byte params[13] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = DesiredGame;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)params;
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		class OnlineGameSearch* GetGameSearch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21715);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSearch**)params;
		}
		bool FreeSearchResults(class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21717);
			byte params[8] = { NULL };
			*(class OnlineGameSearch**)params = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21720);
			byte params[12] = { NULL };
			*(int*)params = StartAt;
			*(int*)&params[4] = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddJoinOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21729);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21731);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21741);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21743);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21750);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21752);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddStartOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StartOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21757);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21759);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StartOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddEndOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EndOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21764);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21766);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EndOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddArbitrationRegistrationCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ArbitrationRegistrationCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21771);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21773);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ArbitrationRegistrationCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant> GetArbitratedPlayers(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21775);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant>*)&params[8];
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21780);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21783);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRecalculateSkillRatingCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecalculateSkillRatingCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21793);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21795);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RecalculateSkillRatingGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMigrateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MigrateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21801);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21803);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MigrateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddJoinMigratedOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinMigratedOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21810);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21812);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinMigratedOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
