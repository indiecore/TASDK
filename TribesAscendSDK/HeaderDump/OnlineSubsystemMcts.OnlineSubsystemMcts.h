#pragma once
#include "OnlineSubsystemMcts.OnlineGameInterfaceMcts.h"
#include "IpDrv.OnlineSubsystemCommonImpl.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.Settings.h"
#include "OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.h"
#include "Engine.OnlineProfileSettings.h"
#include "Engine.OnlinePlayerStorage.h"
#include "PlatformCommon.TgPlayerProfile.h"
#include "Core.Object.h"
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
	class OnlineSubsystemMcts : public OnlineSubsystemCommonImpl
	{
	public:
		class ControllerConnectionState
		{
		public:
			ADD_STRUCT(int, bLastIsControllerConnected, 4)
			ADD_STRUCT(int, bIsControllerConnected, 0)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ConnectionStatusChangeDelegates, 316)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, LoginChangeDelegates, 328)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, LoginFailedDelegates, 340)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, LogoutCompletedDelegates, 352)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, LinkStatusDelegates, 364)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, ChatMessageDelegates, 376)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, KeyboardInputDelegates, 404)
		ADD_STRUCT(float, ConnectionPresenceElapsedTime, 452)
		ADD_STRUCT(float, ConnectionPresenceTimeInterval, 448)
		ADD_STRUCT(OnlineSubsystemMcts::ControllerConnectionState, ControllerStates, 416)
		ADD_BOOL(bShouldUseMcp, 400, 0x4)
		ADD_BOOL(bLastHasConnection, 400, 0x2)
		ADD_BOOL(bNeedsKeyboardTicking, 400, 0x1)
		ADD_STRUCT(ScriptString*, KeyboardResultsString, 388)
		ADD_STRUCT(ScriptString*, ProfileDataExtension, 304)
		ADD_STRUCT(ScriptString*, ProfileDataDirectory, 292)
		ADD_STRUCT(OnlineSubsystem::ENetworkNotificationPosition, CurrentNotificationPosition, 290)
		ADD_STRUCT(byte, bWasKeyboardInputCanceled, 289)
		ADD_STRUCT(OnlineSubsystem::ELoginStatus, LoggedInStatus, 288)
		ADD_STRUCT(int, LoggedInPlayerNum, 284)
		ADD_STRUCT(OnlineSubsystem::UniqueNetId, LoggedInPlayerId, 276)
		ADD_STRUCT(ScriptString*, LoggedInPlayerName, 264)
		ADD_STRUCT(ScriptString*, LocalProfileName, 252)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt, 248)
		ADD_OBJECT(OnlineGameInterfaceMcts, MctsGameInt, 244)
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnConnectionStatusChange");
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[0] = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginFailed(byte LocalUserNum, OnlineSubsystem::EOnlineServerConnectionStatus ErrorCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginFailed");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[1] = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLogoutCompleted(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLogoutCompleted");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChange(bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLinkStatusChange");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnChatMessage(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnChatMessage");
			byte params[28] = { NULL };
			*(int*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnKeyboardInputComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnKeyboardInputComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadAchievementsComplete(int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadAchievementsComplete");
			byte params[4] = { NULL };
			*(int*)&params[0] = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnlockAchievementComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnUnlockAchievementComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendMessageReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinFriendGameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnJoinFriendGameComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReceivedGameInvite(byte LocalUserNum, ScriptString* InviterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReceivedGameInvite");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendInviteReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAddFriendByNameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnAddFriendByNameComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadFriendsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadFriendsComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendsChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendsChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWritePlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWritePlayerStorageComplete");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadPlayerStorageForNetIdComplete(OnlineSubsystem::UniqueNetId NetId, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageForNetIdComplete");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = NetId;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadPlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageComplete");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnWriteProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWriteProfileSettingsComplete");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadProfileSettingsComplete");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMutingChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnMutingChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginCancelled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginCancelled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginStatusChange(OnlineSubsystem::ELoginStatus NewStatus, OnlineSubsystem::UniqueNetId NewId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginStatusChange");
			byte params[9] = { NULL };
			*(OnlineSubsystem::ELoginStatus*)&params[0] = NewStatus;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NewId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnStorageDeviceChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChange(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnControllerChange");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnExternalUIChange(bool bIsOpening)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnExternalUIChange");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Init");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Login(byte LocalUserNum, ScriptString* LoginName, ScriptString* Password, bool bWantsLocalOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Login");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = LoginName;
			*(ScriptString**)&params[16] = Password;
			*(bool*)&params[28] = bWantsLocalOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool RequestNewPlayer(byte LocalUserNum, ScriptString* LoginName, ScriptString* Password, ScriptString* DesiredPlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.RequestNewPlayer");
			byte params[41] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = LoginName;
			*(ScriptString**)&params[16] = Password;
			*(ScriptString**)&params[28] = DesiredPlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		bool AutoLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AutoLogin");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AddLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginFailedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginFailedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LoginFailedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginFailedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginFailedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LoginFailedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Logout(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Logout");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLogoutCompletedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLogoutCompletedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::ELoginStatus GetLoginStatus(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLoginStatus");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ELoginStatus*)&params[1];
		}
		bool IsGuestLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsGuestLogin");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLocalLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsLocalLogin");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetUniquePlayerId(byte LocalUserNum, OnlineSubsystem::UniqueNetId& PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetUniquePlayerId");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerID = *(OnlineSubsystem::UniqueNetId*)&params[4];
			return *(bool*)&params[12];
		}
		ScriptString* GetPlayerNickname(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNickname");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanPlayOnline(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPlayOnline");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanDownloadUserContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanDownloadUserContent");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanPurchaseContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPurchaseContent");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanViewPlayerProfiles(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanViewPlayerProfiles");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanShowPresenceInformation(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanShowPresenceInformation");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		bool IsFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsFriend");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AreAnyFriends(byte LocalUserNum, ScriptArray<OnlineSubsystem::FriendsQuery>& Query)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AreAnyFriends");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::FriendsQuery>*)&params[4] = Query;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Query = *(ScriptArray<OnlineSubsystem::FriendsQuery>*)&params[4];
			return *(bool*)&params[16];
		}
		ScriptString* GetPlayerMctsName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerMctsName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void AddLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NeedEULA()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.NeedEULA");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptString* GetPlayerNicknameFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNicknameFromIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		OnlineSubsystem::UniqueNetId GetPlayerUniqueNetIdFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerUniqueNetIdFromIndex");
			byte params[12] = { NULL };
			*(int*)&params[0] = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::UniqueNetId*)&params[4];
		}
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.HasLinkConnection");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AddLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLinkStatusChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLinkStatusChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddExternalUIChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearExternalUIChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::ENetworkNotificationPosition GetNetworkNotificationPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNetworkNotificationPosition");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ENetworkNotificationPosition*)&params[0];
		}
		void AddControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddControllerChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearControllerChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsControllerConnected(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsControllerConnected");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddConnectionStatusChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearConnectionStatusChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::ENATType GetNATType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNATType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ENATType*)&params[0];
		}
		void AddStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddStorageDeviceChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearStorageDeviceChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddChatMessageDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearChatMessageDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendChatMessage(int Channel, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendChatMessage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendPrivateChatMessage(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendPrivateChatMessage");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WriteActiveCharacterClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteActiveCharacterClass");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadCharacterClasses(ScriptArray<int>& CharList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadCharacterClasses");
			byte params[12] = { NULL };
			*(ScriptArray<int>*)&params[0] = CharList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CharList = *(ScriptArray<int>*)&params[0];
		}
		int ReadActiveCharacterClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadActiveCharacterClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool WritePlayerProfileData(Object::QWord UniqueId, class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerProfileData");
			byte params[16] = { NULL };
			*(Object::QWord*)&params[0] = UniqueId;
			*(class TgPlayerProfile**)&params[8] = Profile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ReadPlayerProfileData(Object::QWord UniqueId, class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerProfileData");
			byte params[16] = { NULL };
			*(Object::QWord*)&params[0] = UniqueId;
			*(class TgPlayerProfile**)&params[8] = Profile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void NotifyTeamChange(Object::QWord PlayerUid, byte TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.NotifyTeamChange");
			byte params[9] = { NULL };
			*(Object::QWord*)&params[0] = PlayerUid;
			params[8] = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCharacterIdFromClassId(Object::QWord UniqueId, int nClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetCharacterIdFromClassId");
			byte params[16] = { NULL };
			*(Object::QWord*)&params[0] = UniqueId;
			*(int*)&params[8] = nClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool IsMuted(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsMuted");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		OnlineSubsystem::EFeaturePrivilegeLevel CanCommunicate(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanCommunicate");
			byte params[2] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::EFeaturePrivilegeLevel*)&params[1];
		}
		void AddLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginStatusChangeDelegate");
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LoginStatusDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginStatusChangeDelegate");
			byte params[13] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = LoginStatusDelegate;
			params[12] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginCancelledDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginCancelledDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadProfileSettings");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlineProfileSettings**)&params[4] = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool WriteProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteProfileSettings");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlineProfileSettings**)&params[4] = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class OnlineProfileSettings* GetProfileSettings(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetProfileSettings");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineProfileSettings**)&params[4];
		}
		void AddMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddMutingChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearMutingChangeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadProfileSettingsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadProfileSettingsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWriteProfileSettingsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWriteProfileSettingsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorage");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[4] = PlayerStorage;
			*(int*)&params[8] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlayerStorageForNetId(byte LocalUserNum, OnlineSubsystem::UniqueNetId NetId, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorageForNetId");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NetId;
			*(class OnlinePlayerStorage**)&params[12] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddReadPlayerStorageForNetIdCompleteDelegate(OnlineSubsystem::UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageForNetIdCompleteDelegate");
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[8] = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadPlayerStorageForNetIdCompleteDelegate(OnlineSubsystem::UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageForNetIdCompleteDelegate");
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[8] = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class OnlinePlayerStorage* GetPlayerStorage(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerStorage");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlinePlayerStorage**)&params[4];
		}
		bool WritePlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerStorage");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[4] = PlayerStorage;
			*(int*)&params[8] = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWritePlayerStorageCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWritePlayerStorageCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendsChangeDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendsChangeDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadFriendsList(byte LocalUserNum, int Count, int StartingAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadFriendsList");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = Count;
			*(int*)&params[8] = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadFriendsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadFriendsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetFriendsList(byte LocalUserNum, ScriptArray<OnlineSubsystem::OnlineFriend>& Friends, int Count, int StartingAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendsList");
			byte params[22] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4] = Friends;
			*(int*)&params[16] = Count;
			*(int*)&params[20] = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Friends = *(ScriptArray<OnlineSubsystem::OnlineFriend>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[24];
		}
		void SetOnlineStatus(byte LocalUserNum, int StatusId, ScriptArray<Settings::LocalizedStringSetting>& LocalizedStringSettings, ScriptArray<Settings::SettingsProperty>& Properties)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetOnlineStatus");
			byte params[29] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = StatusId;
			*(ScriptArray<Settings::LocalizedStringSetting>*)&params[8] = LocalizedStringSettings;
			*(ScriptArray<Settings::SettingsProperty>*)&params[20] = Properties;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LocalizedStringSettings = *(ScriptArray<Settings::LocalizedStringSetting>*)&params[8];
			Properties = *(ScriptArray<Settings::SettingsProperty>*)&params[20];
		}
		bool ShowKeyboardUI(byte LocalUserNum, ScriptString* TitleText, ScriptString* DescriptionText, bool bIsPassword, bool bShouldValidate, ScriptString* DefaultText, int MaxResultLength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowKeyboardUI");
			byte params[53] = { NULL };
			params[0] = LocalUserNum;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddKeyboardInputDoneDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearKeyboardInputDoneDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InputDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearKeyboardInputDoneDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetKeyboardInputResults(byte& bWasCanceled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetKeyboardInputResults");
			byte params[13] = { NULL };
			params[0] = bWasCanceled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bWasCanceled = params[0];
			return *(ScriptString**)&params[4];
		}
		bool AddFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId NewFriend, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriend");
			byte params[25] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = NewFriend;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool AddFriendByName(byte LocalUserNum, ScriptString* FriendName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendByName");
			byte params[29] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = FriendName;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void AddAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddAddFriendByNameCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearAddFriendByNameCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AcceptFriendInvite(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AcceptFriendInvite");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool DenyFriendInvite(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.DenyFriendInvite");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RemoveFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId FormerFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.RemoveFriend");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = FormerFriend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendInviteReceivedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendInviteReceivedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SendMessageToFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendMessageToFriend");
			byte params[25] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool SendGameInviteToFriend(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend, ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriend");
			byte params[25] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			*(ScriptString**)&params[12] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool SendGameInviteToFriends(byte LocalUserNum, ScriptArray<OnlineSubsystem::UniqueNetId> Friends, ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriends");
			byte params[29] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4] = Friends;
			*(ScriptString**)&params[16] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void AddReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReceivedGameInviteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReceivedGameInviteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool JoinFriendGame(byte LocalUserNum, OnlineSubsystem::UniqueNetId Friend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.JoinFriendGame");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = Friend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AddJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddJoinFriendGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearJoinFriendGameCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetFriendMessages(byte LocalUserNum, ScriptArray<OnlineSubsystem::OnlineFriendMessage>& FriendMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendMessages");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::OnlineFriendMessage>*)&params[4] = FriendMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FriendMessages = *(ScriptArray<OnlineSubsystem::OnlineFriendMessage>*)&params[4];
		}
		void AddFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendMessageReceivedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendMessageReceivedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UnlockAchievement(byte LocalUserNum, int AchievementId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.UnlockAchievement");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = AchievementId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ReadAchievements(byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadAchievements");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = TitleId;
			*(bool*)&params[8] = bShouldReadText;
			*(bool*)&params[12] = bShouldReadImages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		OnlineSubsystem::EOnlineEnumerationReadState GetAchievements(byte LocalUserNum, ScriptArray<OnlineSubsystem::AchievementDetails>& Achievements, int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetAchievements");
			byte params[18] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::AchievementDetails>*)&params[4] = Achievements;
			*(int*)&params[16] = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Achievements = *(ScriptArray<OnlineSubsystem::AchievementDetails>*)&params[4];
			return *(OnlineSubsystem::EOnlineEnumerationReadState*)&params[20];
		}
		void AddUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddUnlockAchievementCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearUnlockAchievementCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadAchievementsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadAchievementsCompleteDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DeleteMessage(byte LocalUserNum, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.DeleteMessage");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ShowFriendsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowFriendsUI");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowLoginUI(bool bShowOnlineOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowLoginUI");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bShowOnlineOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetNetworkNotificationPosition(OnlineSubsystem::ENetworkNotificationPosition NewPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetNetworkNotificationPosition");
			byte params[1] = { NULL };
			*(OnlineSubsystem::ENetworkNotificationPosition*)&params[0] = NewPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetLocale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLocale");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
