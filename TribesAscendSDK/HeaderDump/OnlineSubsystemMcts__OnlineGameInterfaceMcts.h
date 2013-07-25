#pragma once
#include "IpDrv__OnlineGameInterfaceImpl.h"
#include "Engine__OnlineGameSearch.h"
#include "OnlineSubsystemMcts__OnlineVoiceInterfaceMcts.h"
#include "OnlineSubsystemMcts__MctsOnlineSettings.h"
#include "Engine__OnlineGameSettings.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
		ADD_OBJECT(OnlineGameSearch, InviteGameSearch)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(MctsOnlineSettings, MctsSettings)
		void OnGameInviteAccepted(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void*& InviteResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnGameInviteAccepted");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InviteResult = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params;
			free(params);
		}
		void OnRegisterPlayerComplete(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnRegisterPlayerComplete");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = PlayerID;
			*(bool*)(params + 16) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregisterPlayerComplete(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnUnregisterPlayerComplete");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = PlayerID;
			*(bool*)(params + 16) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SealMatch(bool bSeal, bool bLateSeal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.SealMatch");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bSeal;
			*(bool*)(params + 4) = bLateSeal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HoldInvites(bool bHold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.HoldInvites");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bHold;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndGame(int nWaitSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.EndGame");
			byte* params = (byte*)malloc(4);
			*(int*)params = nWaitSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MatchQueueJoin(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueJoin");
			byte* params = (byte*)malloc(8);
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool MatchQueueLeave(int nQueueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueLeave");
			byte* params = (byte*)malloc(8);
			*(int*)params = nQueueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool MatchChooseClass(int nClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = nClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool MatchChooseSkin(int nSkinId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseSkin");
			byte* params = (byte*)malloc(8);
			*(int*)params = nSkinId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool MatchAcceptInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchAcceptInvite");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool MatchLockIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLockIn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool MatchLobbyEquipItems(int eType, int nItem1, int nItem2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLobbyEquipItems");
			byte* params = (byte*)malloc(16);
			*(int*)params = eType;
			*(int*)(params + 4) = nItem1;
			*(int*)(params + 8) = nItem2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool UpdateOnlineGame(ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UpdateOnlineGame");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(class OnlineGameSettings**)(params + 8) = UpdatedGameSettings;
			*(bool*)(params + 12) = bShouldRefreshOnlineData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		class OnlineGameSettings* GetGameSettings(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.GetGameSettings");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineGameSettings**)(params + 8);
			free(params);
			return returnVal;
		}
		void AddGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddGameInviteAcceptedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearGameInviteAcceptedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* GameInviteAcceptedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearGameInviteAcceptedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = GameInviteAcceptedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AcceptGameInvite(byte LocalUserNum, ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AcceptGameInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptName*)(params + 4) = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RegisterPlayer(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bWasInvited)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.RegisterPlayer");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = PlayerID;
			*(bool*)(params + 16) = bWasInvited;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void AddRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddRegisterPlayerCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearRegisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearRegisterPlayerCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UnregisterPlayer(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UnregisterPlayer");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddUnregisterPlayerCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearUnregisterPlayerCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnregisterPlayerCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearUnregisterPlayerCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = UnregisterPlayerCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool QueryNonAdvertisedData(int StartAt, int NumberToQuery)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.QueryNonAdvertisedData");
			byte* params = (byte*)malloc(12);
			*(int*)params = StartAt;
			*(int*)(params + 4) = NumberToQuery;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
