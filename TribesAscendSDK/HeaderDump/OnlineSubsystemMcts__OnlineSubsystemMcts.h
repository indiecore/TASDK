#pragma once
#include "IpDrv__OnlineSubsystemCommonImpl.h"
#include "OnlineSubsystemMcts__OnlineVoiceInterfaceMcts.h"
#include "OnlineSubsystemMcts__OnlineGameInterfaceMcts.h"
#include "PlatformCommon__TgPlayerProfile.h"
#include "Engine__OnlinePlayerStorage.h"
#include "Engine__OnlineProfileSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystemMcts : public OnlineSubsystemCommonImpl
	{
	public:
		ADD_VAR(::FloatProperty, ConnectionPresenceElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConnectionPresenceTimeInterval, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct OnlineSubsystemMcts.OnlineSubsystemMcts.ControllerConnectionState' for the property named 'ControllerStates'!
		ADD_VAR(::BoolProperty, bShouldUseMcp, 0x4)
		ADD_VAR(::BoolProperty, bLastHasConnection, 0x2)
		ADD_VAR(::BoolProperty, bNeedsKeyboardTicking, 0x1)
		ADD_VAR(::StrProperty, KeyboardResultsString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileDataExtension, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProfileDataDirectory, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentNotificationPosition, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bWasKeyboardInputCanceled, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LoggedInStatus, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoggedInPlayerNum, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId' for the property named 'LoggedInPlayerId'!
		ADD_VAR(::StrProperty, LoggedInPlayerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LocalProfileName, 0xFFFFFFFF)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(OnlineGameInterfaceMcts, MctsGameInt)
		// Here lies the not-yet-implemented method 'OnConnectionStatusChange'
		// Here lies the not-yet-implemented method 'OnLoginChange'
		// Here lies the not-yet-implemented method 'OnLoginFailed'
		// Here lies the not-yet-implemented method 'OnLogoutCompleted'
		// Here lies the not-yet-implemented method 'OnLinkStatusChange'
		// Here lies the not-yet-implemented method 'OnChatMessage'
		// Here lies the not-yet-implemented method 'OnKeyboardInputComplete'
		// Here lies the not-yet-implemented method 'OnReadAchievementsComplete'
		// Here lies the not-yet-implemented method 'OnUnlockAchievementComplete'
		// Here lies the not-yet-implemented method 'OnFriendMessageReceived'
		// Here lies the not-yet-implemented method 'OnJoinFriendGameComplete'
		// Here lies the not-yet-implemented method 'OnReceivedGameInvite'
		// Here lies the not-yet-implemented method 'OnFriendInviteReceived'
		// Here lies the not-yet-implemented method 'OnAddFriendByNameComplete'
		// Here lies the not-yet-implemented method 'OnReadFriendsComplete'
		// Here lies the not-yet-implemented method 'OnFriendsChange'
		// Here lies the not-yet-implemented method 'OnWritePlayerStorageComplete'
		// Here lies the not-yet-implemented method 'OnReadPlayerStorageForNetIdComplete'
		// Here lies the not-yet-implemented method 'OnReadPlayerStorageComplete'
		// Here lies the not-yet-implemented method 'OnWriteProfileSettingsComplete'
		// Here lies the not-yet-implemented method 'OnReadProfileSettingsComplete'
		// Here lies the not-yet-implemented method 'OnMutingChange'
		// Here lies the not-yet-implemented method 'OnLoginCancelled'
		// Here lies the not-yet-implemented method 'OnLoginStatusChange'
		// Here lies the not-yet-implemented method 'OnStorageDeviceChange'
		// Here lies the not-yet-implemented method 'OnControllerChange'
		// Here lies the not-yet-implemented method 'OnExternalUIChange'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'Login'
		// Here lies the not-yet-implemented method 'RequestNewPlayer'
		// Here lies the not-yet-implemented method 'AutoLogin'
		// Here lies the not-yet-implemented method 'AddLoginFailedDelegate'
		// Here lies the not-yet-implemented method 'ClearLoginFailedDelegate'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'AddLogoutCompletedDelegate'
		// Here lies the not-yet-implemented method 'ClearLogoutCompletedDelegate'
		// Here lies the not-yet-implemented method 'GetLoginStatus'
		// Here lies the not-yet-implemented method 'IsGuestLogin'
		// Here lies the not-yet-implemented method 'IsLocalLogin'
		// Here lies the not-yet-implemented method 'GetUniquePlayerId'
		// Here lies the not-yet-implemented method 'GetPlayerNickname'
		// Here lies the not-yet-implemented method 'CanPlayOnline'
		// Here lies the not-yet-implemented method 'CanDownloadUserContent'
		// Here lies the not-yet-implemented method 'CanPurchaseContent'
		// Here lies the not-yet-implemented method 'CanViewPlayerProfiles'
		// Here lies the not-yet-implemented method 'CanShowPresenceInformation'
		// Here lies the not-yet-implemented method 'IsFriend'
		// Here lies the not-yet-implemented method 'AreAnyFriends'
		// Here lies the not-yet-implemented method 'GetPlayerMctsName'
		// Here lies the not-yet-implemented method 'AddLoginChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearLoginChangeDelegate'
		// Here lies the not-yet-implemented method 'NeedEULA'
		// Here lies the not-yet-implemented method 'GetPlayerNicknameFromIndex'
		// Here lies the not-yet-implemented method 'GetPlayerUniqueNetIdFromIndex'
		// Here lies the not-yet-implemented method 'HasLinkConnection'
		// Here lies the not-yet-implemented method 'AddLinkStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearLinkStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'AddExternalUIChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearExternalUIChangeDelegate'
		// Here lies the not-yet-implemented method 'GetNetworkNotificationPosition'
		// Here lies the not-yet-implemented method 'AddControllerChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearControllerChangeDelegate'
		// Here lies the not-yet-implemented method 'IsControllerConnected'
		// Here lies the not-yet-implemented method 'AddConnectionStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearConnectionStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'GetNATType'
		// Here lies the not-yet-implemented method 'AddStorageDeviceChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearStorageDeviceChangeDelegate'
		// Here lies the not-yet-implemented method 'AddChatMessageDelegate'
		// Here lies the not-yet-implemented method 'ClearChatMessageDelegate'
		// Here lies the not-yet-implemented method 'SendChatMessage'
		// Here lies the not-yet-implemented method 'SendPrivateChatMessage'
		// Here lies the not-yet-implemented method 'WriteActiveCharacterClass'
		// Here lies the not-yet-implemented method 'ReadCharacterClasses'
		// Here lies the not-yet-implemented method 'ReadActiveCharacterClass'
		// Here lies the not-yet-implemented method 'WritePlayerProfileData'
		// Here lies the not-yet-implemented method 'ReadPlayerProfileData'
		// Here lies the not-yet-implemented method 'NotifyTeamChange'
		// Here lies the not-yet-implemented method 'GetCharacterIdFromClassId'
		// Here lies the not-yet-implemented method 'IsMuted'
		// Here lies the not-yet-implemented method 'CanCommunicate'
		// Here lies the not-yet-implemented method 'AddLoginStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearLoginStatusChangeDelegate'
		// Here lies the not-yet-implemented method 'AddLoginCancelledDelegate'
		// Here lies the not-yet-implemented method 'ClearLoginCancelledDelegate'
		// Here lies the not-yet-implemented method 'ReadProfileSettings'
		// Here lies the not-yet-implemented method 'WriteProfileSettings'
		// Here lies the not-yet-implemented method 'GetProfileSettings'
		// Here lies the not-yet-implemented method 'AddMutingChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearMutingChangeDelegate'
		// Here lies the not-yet-implemented method 'AddReadProfileSettingsCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadProfileSettingsCompleteDelegate'
		// Here lies the not-yet-implemented method 'AddWriteProfileSettingsCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearWriteProfileSettingsCompleteDelegate'
		// Here lies the not-yet-implemented method 'ReadPlayerStorage'
		// Here lies the not-yet-implemented method 'AddReadPlayerStorageCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadPlayerStorageCompleteDelegate'
		// Here lies the not-yet-implemented method 'ReadPlayerStorageForNetId'
		// Here lies the not-yet-implemented method 'AddReadPlayerStorageForNetIdCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadPlayerStorageForNetIdCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetPlayerStorage'
		// Here lies the not-yet-implemented method 'WritePlayerStorage'
		// Here lies the not-yet-implemented method 'AddWritePlayerStorageCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearWritePlayerStorageCompleteDelegate'
		// Here lies the not-yet-implemented method 'AddFriendsChangeDelegate'
		// Here lies the not-yet-implemented method 'ClearFriendsChangeDelegate'
		// Here lies the not-yet-implemented method 'ReadFriendsList'
		// Here lies the not-yet-implemented method 'AddReadFriendsCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadFriendsCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetFriendsList'
		// Here lies the not-yet-implemented method 'SetOnlineStatus'
		// Here lies the not-yet-implemented method 'ShowKeyboardUI'
		// Here lies the not-yet-implemented method 'AddKeyboardInputDoneDelegate'
		// Here lies the not-yet-implemented method 'ClearKeyboardInputDoneDelegate'
		// Here lies the not-yet-implemented method 'GetKeyboardInputResults'
		// Here lies the not-yet-implemented method 'AddFriend'
		// Here lies the not-yet-implemented method 'AddFriendByName'
		// Here lies the not-yet-implemented method 'AddAddFriendByNameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearAddFriendByNameCompleteDelegate'
		// Here lies the not-yet-implemented method 'AcceptFriendInvite'
		// Here lies the not-yet-implemented method 'DenyFriendInvite'
		// Here lies the not-yet-implemented method 'RemoveFriend'
		// Here lies the not-yet-implemented method 'AddFriendInviteReceivedDelegate'
		// Here lies the not-yet-implemented method 'ClearFriendInviteReceivedDelegate'
		// Here lies the not-yet-implemented method 'SendMessageToFriend'
		// Here lies the not-yet-implemented method 'SendGameInviteToFriend'
		// Here lies the not-yet-implemented method 'SendGameInviteToFriends'
		// Here lies the not-yet-implemented method 'AddReceivedGameInviteDelegate'
		// Here lies the not-yet-implemented method 'ClearReceivedGameInviteDelegate'
		// Here lies the not-yet-implemented method 'JoinFriendGame'
		// Here lies the not-yet-implemented method 'AddJoinFriendGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearJoinFriendGameCompleteDelegate'
		// Here lies the not-yet-implemented method 'GetFriendMessages'
		// Here lies the not-yet-implemented method 'AddFriendMessageReceivedDelegate'
		// Here lies the not-yet-implemented method 'ClearFriendMessageReceivedDelegate'
		// Here lies the not-yet-implemented method 'UnlockAchievement'
		// Here lies the not-yet-implemented method 'ReadAchievements'
		// Here lies the not-yet-implemented method 'GetAchievements'
		// Here lies the not-yet-implemented method 'AddUnlockAchievementCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearUnlockAchievementCompleteDelegate'
		// Here lies the not-yet-implemented method 'AddReadAchievementsCompleteDelegate'
		// Here lies the not-yet-implemented method 'ClearReadAchievementsCompleteDelegate'
		// Here lies the not-yet-implemented method 'DeleteMessage'
		// Here lies the not-yet-implemented method 'ShowFriendsUI'
		// Here lies the not-yet-implemented method 'ShowLoginUI'
		// Here lies the not-yet-implemented method 'SetNetworkNotificationPosition'
		// Here lies the not-yet-implemented method 'GetLocale'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
