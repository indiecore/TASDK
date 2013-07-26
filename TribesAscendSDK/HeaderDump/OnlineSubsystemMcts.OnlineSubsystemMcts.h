#pragma once
#include "OnlineSubsystemMcts.OnlineGameInterfaceMcts.h"
#include "IpDrv.OnlineSubsystemCommonImpl.h"
#include "OnlineSubsystemMcts.OnlineSubsystemMcts.ControllerConnectionState.h"
#include "Core.Object.QWord.h"
#include "OnlineSubsystemMcts.OnlineVoiceInterfaceMcts.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.OnlineProfileSettings.h"
#include "Engine.OnlinePlayerStorage.h"
#include "PlatformCommon.TgPlayerProfile.h"
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
		ADD_STRUCT(::NonArithmeticProperty<ControllerConnectionState>, ControllerStates, 0xFFFFFFFF)
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
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, LoggedInPlayerId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoggedInPlayerName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LocalProfileName, 0xFFFFFFFF)
		ADD_OBJECT(OnlineVoiceInterfaceMcts, MctsVoiceInt)
		ADD_OBJECT(OnlineGameInterfaceMcts, MctsGameInt)
		void OnConnectionStatusChange(byte ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnConnectionStatusChange");
			byte* params = (byte*)malloc(1);
			*params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginFailed(byte LocalUserNum, byte ErrorCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginFailed");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			*(params + 1) = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLogoutCompleted(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLogoutCompleted");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLinkStatusChange(bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLinkStatusChange");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnChatMessage(int Channel, ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnChatMessage");
			byte* params = (byte*)malloc(28);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Sender;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnKeyboardInputComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnKeyboardInputComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadAchievementsComplete(int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadAchievementsComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnlockAchievementComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnUnlockAchievementComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendMessageReceived(byte LocalUserNum, UniqueNetId SendingPlayer, ScriptArray<wchar_t> SendingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendMessageReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = SendingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = SendingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnJoinFriendGameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnJoinFriendGameComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReceivedGameInvite(byte LocalUserNum, ScriptArray<wchar_t> InviterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReceivedGameInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendInviteReceived(byte LocalUserNum, UniqueNetId RequestingPlayer, ScriptArray<wchar_t> RequestingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendInviteReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = RequestingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = RequestingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAddFriendByNameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnAddFriendByNameComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadFriendsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadFriendsComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendsChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendsChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWritePlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWritePlayerStorageComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadPlayerStorageForNetIdComplete(UniqueNetId NetId, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageForNetIdComplete");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = NetId;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadPlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnWriteProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWriteProfileSettingsComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadProfileSettingsComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void OnLoginStatusChange(byte NewStatus, UniqueNetId NewId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginStatusChange");
			byte* params = (byte*)malloc(9);
			*params = NewStatus;
			*(UniqueNetId*)(params + 4) = NewId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnStorageDeviceChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChange(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnControllerChange");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnExternalUIChange(bool bIsOpening)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnExternalUIChange");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Init");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Login(byte LocalUserNum, ScriptArray<wchar_t> LoginName, ScriptArray<wchar_t> Password, bool bWantsLocalOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Login");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = LoginName;
			*(ScriptArray<wchar_t>*)(params + 16) = Password;
			*(bool*)(params + 28) = bWantsLocalOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool RequestNewPlayer(byte LocalUserNum, ScriptArray<wchar_t> LoginName, ScriptArray<wchar_t> Password, ScriptArray<wchar_t> DesiredPlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.RequestNewPlayer");
			byte* params = (byte*)malloc(41);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = LoginName;
			*(ScriptArray<wchar_t>*)(params + 16) = Password;
			*(ScriptArray<wchar_t>*)(params + 28) = DesiredPlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		bool AutoLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AutoLogin");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AddLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginFailedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginFailedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LoginFailedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginFailedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginFailedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LoginFailedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Logout(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.Logout");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLogoutCompletedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLogoutCompletedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LogoutDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLogoutCompletedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetLoginStatus(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLoginStatus");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		bool IsGuestLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsGuestLogin");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsLocalLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsLocalLogin");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetUniquePlayerId(byte LocalUserNum, UniqueNetId& PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetUniquePlayerId");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerID = *(UniqueNetId*)(params + 4);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerNickname(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNickname");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		byte CanPlayOnline(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPlayOnline");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanDownloadUserContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanDownloadUserContent");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanPurchaseContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPurchaseContent");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanViewPlayerProfiles(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanViewPlayerProfiles");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanShowPresenceInformation(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanShowPresenceInformation");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		bool IsFriend(byte LocalUserNum, UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsFriend");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AreAnyFriends(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Query)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AreAnyFriends");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Query;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Query = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerMctsName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerMctsName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void AddLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NeedEULA()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.NeedEULA");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerNicknameFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNicknameFromIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		UniqueNetId GetPlayerUniqueNetIdFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerUniqueNetIdFromIndex");
			byte* params = (byte*)malloc(12);
			*(int*)params = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(UniqueNetId*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.HasLinkConnection");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AddLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLinkStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLinkStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddExternalUIChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearExternalUIChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetNetworkNotificationPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNetworkNotificationPosition");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void AddControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddControllerChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearControllerChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsControllerConnected(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsControllerConnected");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddConnectionStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearConnectionStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetNATType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNATType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void AddStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddStorageDeviceChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearStorageDeviceChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddChatMessageDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearChatMessageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ChatDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearChatMessageDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ChatDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendChatMessage(int Channel, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendChatMessage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendPrivateChatMessage(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendPrivateChatMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WriteActiveCharacterClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteActiveCharacterClass");
			byte* params = (byte*)malloc(4);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReadCharacterClasses(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& CharList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadCharacterClasses");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = CharList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CharList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		int ReadActiveCharacterClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadActiveCharacterClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool WritePlayerProfileData(QWord UniqueId, class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerProfileData");
			byte* params = (byte*)malloc(16);
			*(QWord*)params = UniqueId;
			*(class TgPlayerProfile**)(params + 8) = Profile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ReadPlayerProfileData(QWord UniqueId, class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerProfileData");
			byte* params = (byte*)malloc(16);
			*(QWord*)params = UniqueId;
			*(class TgPlayerProfile**)(params + 8) = Profile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void NotifyTeamChange(QWord PlayerUid, byte TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.NotifyTeamChange");
			byte* params = (byte*)malloc(9);
			*(QWord*)params = PlayerUid;
			*(params + 8) = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetCharacterIdFromClassId(QWord UniqueId, int nClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetCharacterIdFromClassId");
			byte* params = (byte*)malloc(16);
			*(QWord*)params = UniqueId;
			*(int*)(params + 8) = nClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsMuted(byte LocalUserNum, UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsMuted");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		byte CanCommunicate(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanCommunicate");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		void AddLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginStatusChangeDelegate");
			byte* params = (byte*)malloc(13);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginStatusDelegate;
			*(params + 12) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginStatusChangeDelegate");
			byte* params = (byte*)malloc(13);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginStatusDelegate;
			*(params + 12) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginCancelledDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLoginCancelledDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CancelledDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginCancelledDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadProfileSettings");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)(params + 4) = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool WriteProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteProfileSettings");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)(params + 4) = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class OnlineProfileSettings* GetProfileSettings(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetProfileSettings");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineProfileSettings**)(params + 4);
			free(params);
			return returnVal;
		}
		void AddMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddMutingChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearMutingChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadProfileSettingsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadProfileSettingsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWriteProfileSettingsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWriteProfileSettingsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WriteProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadPlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorage");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(class OnlinePlayerStorage**)(params + 4) = PlayerStorage;
			*(int*)(params + 8) = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadPlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadPlayerStorageForNetId(byte LocalUserNum, UniqueNetId NetId, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorageForNetId");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = NetId;
			*(class OnlinePlayerStorage**)(params + 12) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddReadPlayerStorageForNetIdCompleteDelegate(UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageForNetIdCompleteDelegate");
			byte* params = (byte*)malloc(20);
			*(UniqueNetId*)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 8) = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadPlayerStorageForNetIdCompleteDelegate(UniqueNetId NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageForNetIdCompleteDelegate");
			byte* params = (byte*)malloc(20);
			*(UniqueNetId*)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 8) = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class OnlinePlayerStorage* GetPlayerStorage(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerStorage");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlinePlayerStorage**)(params + 4);
			free(params);
			return returnVal;
		}
		bool WritePlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerStorage");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(class OnlinePlayerStorage**)(params + 4) = PlayerStorage;
			*(int*)(params + 8) = DeviceID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWritePlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearWritePlayerStorageCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WritePlayerStorageCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWritePlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendsChangeDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendsChangeDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadFriendsList(byte LocalUserNum, int Count, int StartingAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadFriendsList");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(int*)(params + 4) = Count;
			*(int*)(params + 8) = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadFriendsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadFriendsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadFriendsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadFriendsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadFriendsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetFriendsList(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Friends, int Count, int StartingAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendsList");
			byte* params = (byte*)malloc(22);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Friends;
			*(int*)(params + 16) = Count;
			*(int*)(params + 20) = StartingAt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Friends = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(params + 24);
			free(params);
			return returnVal;
		}
		void SetOnlineStatus(byte LocalUserNum, int StatusId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& LocalizedStringSettings, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Properties)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetOnlineStatus");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(int*)(params + 4) = StatusId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = LocalizedStringSettings;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = Properties;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			LocalizedStringSettings = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			Properties = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			free(params);
		}
		bool ShowKeyboardUI(byte LocalUserNum, ScriptArray<wchar_t> TitleText, ScriptArray<wchar_t> DescriptionText, bool bIsPassword, bool bShouldValidate, ScriptArray<wchar_t> DefaultText, int MaxResultLength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowKeyboardUI");
			byte* params = (byte*)malloc(53);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = TitleText;
			*(ScriptArray<wchar_t>*)(params + 16) = DescriptionText;
			*(bool*)(params + 28) = bIsPassword;
			*(bool*)(params + 32) = bShouldValidate;
			*(ScriptArray<wchar_t>*)(params + 36) = DefaultText;
			*(int*)(params + 48) = MaxResultLength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 52);
			free(params);
			return returnVal;
		}
		void AddKeyboardInputDoneDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InputDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddKeyboardInputDoneDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearKeyboardInputDoneDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InputDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearKeyboardInputDoneDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetKeyboardInputResults(byte& bWasCanceled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetKeyboardInputResults");
			byte* params = (byte*)malloc(13);
			*params = bWasCanceled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			bWasCanceled = *params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AddFriend(byte LocalUserNum, UniqueNetId NewFriend, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = NewFriend;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool AddFriendByName(byte LocalUserNum, ScriptArray<wchar_t> FriendName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendByName");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = FriendName;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void AddAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddAddFriendByNameCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearAddFriendByNameCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearAddFriendByNameCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AcceptFriendInvite(byte LocalUserNum, UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AcceptFriendInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool DenyFriendInvite(byte LocalUserNum, UniqueNetId RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.DenyFriendInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RemoveFriend(byte LocalUserNum, UniqueNetId FormerFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.RemoveFriend");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = FormerFriend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendInviteReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendInviteReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SendMessageToFriend(byte LocalUserNum, UniqueNetId Friend, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendMessageToFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = Friend;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool SendGameInviteToFriend(byte LocalUserNum, UniqueNetId Friend, ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = Friend;
			*(ScriptArray<wchar_t>*)(params + 12) = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool SendGameInviteToFriends(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Friends, ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriends");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Friends;
			*(ScriptArray<wchar_t>*)(params + 16) = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void AddReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReceivedGameInviteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReceivedGameInviteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReceivedGameInviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReceivedGameInviteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool JoinFriendGame(byte LocalUserNum, UniqueNetId Friend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.JoinFriendGame");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = Friend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddJoinFriendGameCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearJoinFriendGameCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinFriendGameCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetFriendMessages(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& FriendMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendMessages");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = FriendMessages;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FriendMessages = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void AddFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendMessageReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFriendMessageReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MessageDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendMessageReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UnlockAchievement(byte LocalUserNum, int AchievementId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.UnlockAchievement");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = AchievementId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ReadAchievements(byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadAchievements");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(int*)(params + 4) = TitleId;
			*(bool*)(params + 8) = bShouldReadText;
			*(bool*)(params + 12) = bShouldReadImages;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		byte GetAchievements(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Achievements, int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetAchievements");
			byte* params = (byte*)malloc(18);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Achievements;
			*(int*)(params + 16) = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Achievements = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(params + 20);
			free(params);
			return returnVal;
		}
		void AddUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddUnlockAchievementCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearUnlockAchievementCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadAchievementsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadAchievementsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DeleteMessage(byte LocalUserNum, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.DeleteMessage");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ShowFriendsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowFriendsUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowLoginUI(bool bShowOnlineOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowLoginUI");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bShowOnlineOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetNetworkNotificationPosition(byte NewPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetNetworkNotificationPosition");
			byte* params = (byte*)malloc(1);
			*params = NewPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetLocale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLocale");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
