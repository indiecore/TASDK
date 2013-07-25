#pragma once
#include "Core__Interface.h"
#include "Engine__OnlinePlayerStorage.h"
#include "Engine__OnlineProfileSettings.h"
namespace UnrealScript
{
	class OnlinePlayerInterface : public Interface
	{
	public:
		bool GetUniquePlayerId(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void*& PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetUniquePlayerId");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerID = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		byte GetLoginStatus(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetLoginStatus");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerNickname(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetPlayerNickname");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		byte CanPlayOnline(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanPlayOnline");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanDownloadUserContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanDownloadUserContent");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		bool AutoLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AutoLogin");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadAchievementsComplete(int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReadAchievementsComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = TitleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnlockAchievementComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnUnlockAchievementComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendMessageReceived(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* SendingPlayer, ScriptArray<wchar_t> SendingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnFriendMessageReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = SendingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = SendingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnJoinFriendGameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnJoinFriendGameComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReceivedGameInvite(byte LocalUserNum, ScriptArray<wchar_t> InviterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReceivedGameInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendInviteReceived(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPlayer, ScriptArray<wchar_t> RequestingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnFriendInviteReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = RequestingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = RequestingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAddFriendByNameComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnAddFriendByNameComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnKeyboardInputComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnKeyboardInputComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadFriendsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReadFriendsComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnWritePlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnWritePlayerStorageComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadPlayerStorageForNetIdComplete(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NetId, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReadPlayerStorageForNetIdComplete");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = NetId;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadPlayerStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReadPlayerStorageComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnWriteProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnWriteProfileSettingsComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnReadProfileSettingsComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginStatusChange(byte NewStatus, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NewId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnLoginStatusChange");
			byte* params = (byte*)malloc(9);
			*params = NewStatus;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = NewId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLogoutCompleted(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnLogoutCompleted");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginFailed(byte LocalUserNum, byte ErrorCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnLoginFailed");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			*(params + 1) = ErrorCode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendsChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnFriendsChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMutingChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnMutingChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginCancelled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.OnLoginCancelled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShowLoginUI(bool bShowOnlineOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ShowLoginUI");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bShowOnlineOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool Login(byte LocalUserNum, ScriptArray<wchar_t> LoginName, ScriptArray<wchar_t> Password, bool bWantsLocalOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.Login");
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
		void AddLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddLoginFailedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLoginFailedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearLoginFailedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Logout(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.Logout");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddLogoutCompletedDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearLogoutCompletedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = LogoutDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsGuestLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.IsGuestLogin");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsLocalLogin(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.IsLocalLogin");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		byte CanCommunicate(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanCommunicate");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanPurchaseContent(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanPurchaseContent");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanViewPlayerProfiles(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanViewPlayerProfiles");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		byte CanShowPresenceInformation(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.CanShowPresenceInformation");
			byte* params = (byte*)malloc(2);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 1);
			free(params);
			return returnVal;
		}
		bool IsFriend(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.IsFriend");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AreAnyFriends(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Query)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AreAnyFriends");
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
		bool IsMuted(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.IsMuted");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShowFriendsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ShowFriendsUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddLoginChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddLoginChangeDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearLoginChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LoginDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddLoginStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LoginStatusDelegate, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddLoginStatusChangeDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearLoginStatusChangeDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddLoginCancelledDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearLoginCancelledDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = CancelledDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMutingChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MutingDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddMutingChangeDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearMutingChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MutingDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFriendsChangeDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FriendsDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddFriendsChangeDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearFriendsChangeDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendsDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ReadProfileSettings");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)(params + 4) = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddReadProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReadProfileSettingsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReadProfileSettingsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadProfileSettingsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class OnlineProfileSettings* GetProfileSettings(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetProfileSettings");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineProfileSettings**)(params + 4);
			free(params);
			return returnVal;
		}
		bool WriteProfileSettings(byte LocalUserNum, class OnlineProfileSettings* ProfileSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.WriteProfileSettings");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class OnlineProfileSettings**)(params + 4) = ProfileSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddWriteProfileSettingsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* WriteProfileSettingsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddWriteProfileSettingsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearWriteProfileSettingsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ReadPlayerStorage");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReadPlayerStorageCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReadPlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadPlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadPlayerStorageForNetId(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NetId, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ReadPlayerStorageForNetId");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = NetId;
			*(class OnlinePlayerStorage**)(params + 12) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddReadPlayerStorageForNetIdCompleteDelegate(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReadPlayerStorageForNetIdCompleteDelegate");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 8) = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadPlayerStorageForNetIdCompleteDelegate(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NetId, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadPlayerStorageForNetIdCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReadPlayerStorageForNetIdCompleteDelegate");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = NetId;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 8) = ReadPlayerStorageForNetIdCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class OnlinePlayerStorage* GetPlayerStorage(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetPlayerStorage");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlinePlayerStorage**)(params + 4);
			free(params);
			return returnVal;
		}
		bool WritePlayerStorage(byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.WritePlayerStorage");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddWritePlayerStorageCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearWritePlayerStorageCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = WritePlayerStorageCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadFriendsList(byte LocalUserNum, int Count, int StartingAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ReadFriendsList");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReadFriendsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReadFriendsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetFriendsList");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.SetOnlineStatus");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ShowKeyboardUI");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddKeyboardInputDoneDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearKeyboardInputDoneDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InputDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetKeyboardInputResults(byte& bWasCanceled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetKeyboardInputResults");
			byte* params = (byte*)malloc(13);
			*params = bWasCanceled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			bWasCanceled = *params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AddFriend(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NewFriend, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = NewFriend;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool AddFriendByName(byte LocalUserNum, ScriptArray<wchar_t> FriendName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddFriendByName");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddAddFriendByNameCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearAddFriendByNameCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = FriendDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AcceptFriendInvite(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AcceptFriendInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool DenyFriendInvite(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.DenyFriendInvite");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = RequestingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RemoveFriend(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* FormerFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.RemoveFriend");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = FormerFriend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddFriendInviteReceivedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InviteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddFriendInviteReceivedDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearFriendInviteReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = InviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SendMessageToFriend(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Friend, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.SendMessageToFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = Friend;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool SendGameInviteToFriend(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Friend, ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.SendGameInviteToFriend");
			byte* params = (byte*)malloc(25);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = Friend;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.SendGameInviteToFriends");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReceivedGameInviteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReceivedGameInviteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReceivedGameInviteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool JoinFriendGame(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Friend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.JoinFriendGame");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = Friend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddJoinFriendGameCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinFriendGameCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddJoinFriendGameCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearJoinFriendGameCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetFriendMessages");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddFriendMessageReceivedDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearFriendMessageReceivedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = MessageDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DeleteMessage(byte LocalUserNum, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.DeleteMessage");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UnlockAchievement(byte LocalUserNum, int AchievementId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.UnlockAchievement");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = AchievementId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddUnlockAchievementCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* UnlockAchievementCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddUnlockAchievementCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearUnlockAchievementCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = UnlockAchievementCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadAchievements(byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ReadAchievements");
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
		void AddReadAchievementsCompleteDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadAchievementsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.AddReadAchievementsCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.ClearReadAchievementsCompleteDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ReadAchievementsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetAchievements(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Achievements, int TitleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterface.GetAchievements");
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
	};
}
