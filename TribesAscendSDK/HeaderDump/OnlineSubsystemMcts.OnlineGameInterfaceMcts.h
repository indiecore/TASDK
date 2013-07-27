#pragma once
#include "IpDrv.OnlineGameInterfaceImpl.h"
#include "OnlineSubsystemMcts.MctsOnlineSettings.h"
#include "OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineGameSettings.h"
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
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
		enum EMctsMatchmakingType : byte
		{
			SMT_Invalid = 0,
			SMT_LAN = 1,
			SMT_Internet = 2,
			SMT_MAX = 3,
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, GameInviteAcceptedDelegates, 444)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, RegisterPlayerCompleteDelegates, 460)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, UnregisterPlayerCompleteDelegates, 472)
		ADD_OBJECT(OnlineGameSearch, InviteGameSearch, 456)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt, 440)
		ADD_OBJECT(MctsOnlineSettings, MctsSettings, 436)
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnGameInviteAccepted");
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnRegisterPlayerComplete");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnUnregisterPlayerComplete");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SealMatch(bool bSeal, bool bLateSeal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.SealMatch");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bSeal;
			*(bool*)&params[4] = bLateSeal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldInvites(bool bHold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.HoldInvites");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bHold;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndGame(int nWaitSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.EndGame");
			byte params[4] = { NULL };
			*(int*)&params[0] = nWaitSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MatchQueueJoin(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueJoin");
			byte params[8] = { NULL };
			*(int*)&params[0] = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchQueueLeave(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueLeave");
			byte params[8] = { NULL };
			*(int*)&params[0] = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchChooseClass(int nClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseClass");
			byte params[8] = { NULL };
			*(int*)&params[0] = nClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchChooseSkin(int nSkinId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseSkin");
			byte params[8] = { NULL };
			*(int*)&params[0] = nSkinId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchAcceptInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchAcceptInvite");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool MatchLockIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLockIn");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool MatchLobbyEquipItems(int eType, int nItem1, int nItem2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLobbyEquipItems");
			byte params[16] = { NULL };
			*(int*)&params[0] = eType;
			*(int*)&params[4] = nItem1;
			*(int*)&params[8] = nItem2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UpdateOnlineGame");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(class OnlineGameSettings**)&params[8] = UpdatedGameSettings;
			*(bool*)&params[12] = bShouldRefreshOnlineData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class OnlineGameSettings* GetGameSettings(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.GetGameSettings");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddGameInviteAcceptedDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearGameInviteAcceptedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AcceptGameInvite");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RegisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.RegisterPlayer");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasInvited;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void AddRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddRegisterPlayerCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearRegisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UnregisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UnregisterPlayer");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddUnregisterPlayerCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearUnregisterPlayerCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.QueryNonAdvertisedData");
			byte params[12] = { NULL };
			*(int*)&params[0] = StartAt;
			*(int*)&params[4] = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
