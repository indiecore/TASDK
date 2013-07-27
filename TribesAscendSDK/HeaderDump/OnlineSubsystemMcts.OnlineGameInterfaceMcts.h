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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156413);
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)params;
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156416);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156419);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SealMatch(bool bSeal, bool bLateSeal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156427);
			byte params[8] = { NULL };
			*(bool*)params = bSeal;
			*(bool*)&params[4] = bLateSeal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HoldInvites(bool bHold)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156430);
			byte params[4] = { NULL };
			*(bool*)params = bHold;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndGame(int nWaitSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156432);
			byte params[4] = { NULL };
			*(int*)params = nWaitSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MatchQueueJoin(int nQueueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156434);
			byte params[8] = { NULL };
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchQueueLeave(int nQueueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156437);
			byte params[8] = { NULL };
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchChooseClass(int nClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156440);
			byte params[8] = { NULL };
			*(int*)params = nClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchChooseSkin(int nSkinId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156443);
			byte params[8] = { NULL };
			*(int*)params = nSkinId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MatchAcceptInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156446);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool MatchLockIn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156448);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool MatchLobbyEquipItems(int eType, int nItem1, int nItem2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156450);
			byte params[16] = { NULL };
			*(int*)params = eType;
			*(int*)&params[4] = nItem1;
			*(int*)&params[8] = nItem2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156455);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(class OnlineGameSettings**)&params[8] = UpdatedGameSettings;
			*(bool*)&params[12] = bShouldRefreshOnlineData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class OnlineGameSettings* GetGameSettings(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156460);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156464);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156467);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156472);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptName*)&params[4] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RegisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156476);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156484);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156486);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UnregisterPlayer(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156489);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156496);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156498);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(156501);
			byte params[12] = { NULL };
			*(int*)params = StartAt;
			*(int*)&params[4] = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
