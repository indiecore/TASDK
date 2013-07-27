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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.GetGameSettings");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		bool EndOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.EndOnlineGame");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnregisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.UnregisterPlayer");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool MigrateOnlineGame(byte HostingPlayerNum, ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.MigrateOnlineGame");
			byte params[13] = { NULL };
			params[0] = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ReadPlatformSpecificSessionInfoBySessionName(ScriptName SessionName, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ReadPlatformSpecificSessionInfoBySessionName");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		bool BindPlatformSpecificSessionToSearch(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.BindPlatformSpecificSessionToSearch");
			byte params[10] = { NULL };
			params[0] = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[88];
		}
		bool JoinMigratedOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.JoinMigratedOnlineGame");
			byte params[21] = { NULL };
			params[0] = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		bool GetResolvedConnectString(ScriptName SessionName, ScriptString*& ConnectInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.GetResolvedConnectString");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptString**)&params[8] = ConnectInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ConnectInfo = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool RegisterForArbitration(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.RegisterForArbitration");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AcceptGameInvite");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool DestroyOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.DestroyOnlineGame");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool StartOnlineGame(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.StartOnlineGame");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool JoinOnlineGame(byte PlayerNum, ScriptName SessionName, OnlineGameSearch::OnlineGameSearchResult& DesiredGame)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.JoinOnlineGame");
			byte params[21] = { NULL };
			params[0] = PlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[12] = DesiredGame;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[12];
			return *(bool*)&params[20];
		}
		bool RegisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.RegisterPlayer");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasInvited;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool RecalculateSkillRating(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.RecalculateSkillRating");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
			return *(bool*)&params[20];
		}
		bool CreateOnlineGame(byte HostingPlayerNum, ScriptName SessionName, class OnlineGameSettings* NewGameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.CreateOnlineGame");
			byte params[17] = { NULL };
			params[0] = HostingPlayerNum;
			*(ScriptName*)&params[4] = SessionName;
			*(class OnlineGameSettings**)&params[12] = NewGameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnCreateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnCreateOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinMigratedOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnJoinMigratedOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMigrateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnMigrateOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRecalculateSkillRatingComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnRecalculateSkillRatingComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnGameInviteAccepted");
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
		}
		void OnArbitrationRegistrationComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnArbitrationRegistrationComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnEndOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStartOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnStartOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnUnregisterPlayerComplete");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnRegisterPlayerComplete");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnJoinOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQosStatusChanged(int NumComplete, int NumTotal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnQosStatusChanged");
			byte params[8] = { NULL };
			*(int*)&params[0] = NumComplete;
			*(int*)&params[4] = NumTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCancelFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnCancelFindOnlineGamesComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnFindOnlineGamesComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnDestroyOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdateOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.OnUpdateOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CreateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddCreateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CreateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCreateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CreateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearCreateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CreateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.UpdateOnlineGame");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(class OnlineGameSettings**)&params[8] = UpdatedGameSettings;
			*(bool*)&params[12] = bShouldRefreshOnlineData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddUpdateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UpdateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddUpdateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UpdateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUpdateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UpdateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearUpdateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UpdateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDestroyOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DestroyOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddDestroyOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = DestroyOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDestroyOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DestroyOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearDestroyOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = DestroyOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindOnlineGames(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.FindOnlineGames");
			byte params[9] = { NULL };
			params[0] = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddFindOnlineGamesCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = FindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearFindOnlineGamesCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = FindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CancelFindOnlineGames()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.CancelFindOnlineGames");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AddCancelFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelFindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddCancelFindOnlineGamesCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CancelFindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCancelFindOnlineGamesCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelFindOnlineGamesCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearCancelFindOnlineGamesCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CancelFindOnlineGamesCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddQosStatusChangedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QosStatusChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddQosStatusChangedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = QosStatusChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQosStatusChangedDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* QosStatusChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearQosStatusChangedDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = QosStatusChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlatformSpecificSessionInfo(OnlineGameSearch::OnlineGameSearchResult& DesiredGame, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ReadPlatformSpecificSessionInfo");
			byte params[13] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = DesiredGame;
			params[8] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredGame = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
			PlatformSpecificInfo = params[8];
			return *(bool*)&params[88];
		}
		class OnlineGameSearch* GetGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.GetGameSearch");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSearch**)&params[0];
		}
		bool FreeSearchResults(class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.FreeSearchResults");
			byte params[8] = { NULL };
			*(class OnlineGameSearch**)&params[0] = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.QueryNonAdvertisedData");
			byte params[12] = { NULL };
			*(int*)&params[0] = StartAt;
			*(int*)&params[4] = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddJoinOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddJoinOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearJoinOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddRegisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearRegisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddUnregisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearUnregisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddStartOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StartOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddStartOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = StartOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStartOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StartOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearStartOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = StartOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddEndOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EndOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddEndOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = EndOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearEndOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EndOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearEndOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = EndOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddArbitrationRegistrationCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ArbitrationRegistrationCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddArbitrationRegistrationCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ArbitrationRegistrationCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearArbitrationRegistrationCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ArbitrationRegistrationCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearArbitrationRegistrationCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ArbitrationRegistrationCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant> GetArbitratedPlayers(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.GetArbitratedPlayers");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<OnlineSubsystem::OnlineArbitrationRegistrant>*)&params[8];
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddGameInviteAcceptedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearGameInviteAcceptedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRecalculateSkillRatingCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecalculateSkillRatingCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddRecalculateSkillRatingCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RecalculateSkillRatingCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecalculateSkillRatingCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RecalculateSkillRatingGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearRecalculateSkillRatingCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RecalculateSkillRatingGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMigrateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MigrateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddMigrateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = MigrateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMigrateOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MigrateOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearMigrateOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = MigrateOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddJoinMigratedOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinMigratedOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.AddJoinMigratedOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinMigratedOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinMigratedOnlineGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinMigratedOnlineGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineGameInterface.ClearJoinMigratedOnlineGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinMigratedOnlineGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
