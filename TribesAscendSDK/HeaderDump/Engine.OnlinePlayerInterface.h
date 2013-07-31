#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
#include "Engine.Settings.h"
namespace UnrealScript
{
	class OnlinePlayerInterface : public Interface
	{
	public:
		bool GetUniquePlayerId(byte LocalUserNum, OnlineSubsystem::UniqueNetId& PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7777);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerID = *(OnlineSubsystem::UniqueNetId*)&params[4];
			return *(bool*)&params[12];
		}
		OnlineSubsystem::ELoginStatus GetLoginStatus(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8383);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ELoginStatus*)&params[1];
		}
		ScriptString* GetPlayerNickname(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8385);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanPlayOnline(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9266);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanDownloadUserContent(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9381);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		bool AutoLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17368);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21949);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadAchievementsComplete(int TitleId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21952);
			byte params[4] = { NULL };
			*(int*)params = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnlockAchievementComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21954);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21956);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinFriendGameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21958);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReceivedGameInvite(byte LocalUserNum, ScriptString* InviterName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21960);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21962);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAddFriendByNameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21964);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnKeyboardInputComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21966);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadFriendsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21968);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnWritePlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21970);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadPlayerStorageForNetIdComplete(OnlineSubsystem::UniqueNetId NetId, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21972);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = NetId;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadPlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21974);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnWriteProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21976);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21978);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginStatusChange(OnlineSubsystem::ELoginStatus NewStatus, OnlineSubsystem::UniqueNetId NewId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21980);
			byte params[9] = { NULL };
			*(OnlineSubsystem::ELoginStatus*)params = NewStatus;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NewId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLogoutCompleted(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21982);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginFailed(byte LocalUserNum, OnlineSubsystem::EOnlineServerConnectionStatus ErrorCode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21984);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[1] = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendsChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21986);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMutingChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21988);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginCancelled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21990);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShowLoginUI(bool bShowOnlineOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21992);
			byte params[8] = { NULL };
			*(bool*)params = bShowOnlineOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool Login(byte LocalUserNum, ScriptString* LoginName, ScriptString* Password, bool bWantsLocalOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21995);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = LoginName;
			*(ScriptString**)&params[16] = Password;
			*(bool*)&params[28] = bWantsLocalOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void AddLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22003);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22006);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Logout(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22009);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22013);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22016);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsGuestLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22023);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLocalLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22026);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanCommunicate(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22030);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanPurchaseContent(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22034);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanViewPlayerProfiles(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22037);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanShowPresenceInformation(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22040);
			byte params[2] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		bool IsFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22043);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AreAnyFriends(byte LocalUserNum, ScriptArray<OnlineSubsystem::FriendsQuery>& Query)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22047);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::FriendsQuery>*)&params[4] = Query;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Query = *(ScriptArray<OnlineSubsystem::FriendsQuery>*)&params[4];
			return *(bool*)&params[16];
		}
		bool IsMuted(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22052);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowFriendsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22056);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22059);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22061);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22065);
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginStatusDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22068);
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginStatusDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22071);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22073);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22075);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22077);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22079);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22082);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22085);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)&params[4] = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22091);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22094);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class OnlineProfileSettings* GetProfileSettings(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22097);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineProfileSettings**)&params[4];
		}
		bool WriteProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22100);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)&params[4] = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22106);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22109);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22112);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[4] = PlayerStorage;
			*(int*)&params[8] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22119);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22122);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlayerStorageForNetId(byte LocalUserNum, OnlineSubsystem::UniqueNetId NetId, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22125);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NetId;
			*(class OnlinePlayerStorage**)&params[12] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddReadPlayerStorageForNetIdCompleteDelegate(OnlineSubsystem::UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22132);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[8] = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadPlayerStorageForNetIdCompleteDelegate(OnlineSubsystem::UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22135);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[8] = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class OnlinePlayerStorage* GetPlayerStorage(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22138);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlinePlayerStorage**)&params[4];
		}
		bool WritePlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22141);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[4] = PlayerStorage;
			*(int*)&params[8] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22148);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22151);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadFriendsList(byte LocalUserNum, int Count, int StartingAt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22154);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = Count;
			*(int*)&params[8] = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22160);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22163);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetFriendsList(byte LocalUserNum, ScriptArray<OnlineSubsystem::OnlineFriend>& Friends, int Count, int StartingAt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22166);
			byte params[22] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4] = Friends;
			*(int*)&params[16] = Count;
			*(int*)&params[20] = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Friends = *(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[24];
		}
		void SetOnlineStatus(byte LocalUserNum, int StatusId, ScriptArray<Settings::LocalizedStringSetting>& LocalizedStringSettings, ScriptArray<Settings::SettingsProperty>& Properties)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22173);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = StatusId;
			*(ScriptArray<Settings::LocalizedStringSetting>*)&params[8] = LocalizedStringSettings;
			*(ScriptArray<Settings::SettingsProperty>*)&params[20] = Properties;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LocalizedStringSettings = *(ScriptArray<Settings::LocalizedStringSetting>*)&params[8];
			Properties = *(ScriptArray<Settings::SettingsProperty>*)&params[20];
		}
		bool ShowKeyboardUI(byte LocalUserNum, ScriptString* TitleText, ScriptString* DescriptionText, bool bIsPassword, bool bShouldValidate, ScriptString* DefaultText, int MaxResultLength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22180);
			byte params[53] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = TitleText;
			*(ScriptString**)&params[16] = DescriptionText;
			*(bool*)&params[28] = bIsPassword;
			*(bool*)&params[32] = bShouldValidate;
			*(ScriptString**)&params[36] = DefaultText;
			*(int*)&params[48] = MaxResultLength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[52];
		}
		void AddKeyboardInputDoneDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InputDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22190);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearKeyboardInputDoneDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InputDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22192);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetKeyboardInputResults(byte& bWasCanceled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22194);
			byte params[13] = { NULL };
			*params = bWasCanceled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bWasCanceled = *params;
			return *(ScriptString**)&params[4];
		}
		bool AddFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId NewFriend, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22197);
			byte params[25] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NewFriend;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool AddFriendByName(byte LocalUserNum, ScriptString* FriendName, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22202);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = FriendName;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void AddAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22208);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22211);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AcceptFriendInvite(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22214);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool DenyFriendInvite(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22218);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RemoveFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId FormerFriend)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22222);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = FormerFriend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22230);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22233);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SendMessageToFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22236);
			byte params[25] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool SendGameInviteToFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend, ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22241);
			byte params[25] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			*(ScriptString**)&params[12] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool SendGameInviteToFriends(byte LocalUserNum, ScriptArray<OnlineSubsystem::UniqueNetId> Friends, ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22246);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4] = Friends;
			*(ScriptString**)&params[16] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void AddReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22254);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22257);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool JoinFriendGame(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22260);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22265);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22267);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetFriendMessages(byte LocalUserNum, ScriptArray<OnlineSubsystem::OnlineFriendMessage>& FriendMessages)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22269);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::OnlineFriendMessage>*)&params[4] = FriendMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FriendMessages = *(ScriptArray<OnlineSubsystem::OnlineFriendMessage>*)&params[4];
		}
		void AddFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22277);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22280);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DeleteMessage(byte LocalUserNum, int MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22283);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnlockAchievement(byte LocalUserNum, int AchievementId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22287);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = AchievementId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22292);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22295);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadAchievements(byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22298);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = TitleId;
			*(bool*)&params[8] = bShouldReadText;
			*(bool*)&params[12] = bShouldReadImages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22305);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22308);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetAchievements(byte LocalUserNum, ScriptArray<OnlineSubsystem::AchievementDetails>& Achievements, int TitleId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22311);
			byte params[18] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::AchievementDetails>*)&params[4] = Achievements;
			*(int*)&params[16] = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Achievements = *(ScriptArray<OnlineSubsystem::AchievementDetails>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[20];
		}
	};
}
