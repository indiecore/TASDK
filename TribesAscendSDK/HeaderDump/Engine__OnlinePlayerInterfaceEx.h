#pragma once
#include "Core__Interface.h"
namespace UnrealScript
{
	class OnlinePlayerInterfaceEx : public Interface
	{
	public:
		bool ShowFeedbackUI(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowFeedbackUI");
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
		bool ShowGamerCardUI(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowGamerCardUI");
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
		bool ShowMessagesUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowMessagesUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowAchievementsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowAchievementsUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowInviteUI(byte LocalUserNum, ScriptArray<wchar_t> InviteText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowInviteUI");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = InviteText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool ShowContentMarketplaceUI(byte LocalUserNum, int CategoryMask, int OfferId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowContentMarketplaceUI");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(int*)(params + 4) = CategoryMask;
			*(int*)(params + 8) = OfferId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShowMembershipMarketplaceUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowMembershipMarketplaceUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowDeviceSelectionUI(byte LocalUserNum, int SizeNeeded, bool bManageStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowDeviceSelectionUI");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(int*)(params + 4) = SizeNeeded;
			*(bool*)(params + 8) = bManageStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnDeviceSelectionComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.OnDeviceSelectionComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnProfileDataChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.OnProfileDataChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDeviceSelectionDoneDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DeviceDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.AddDeviceSelectionDoneDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearDeviceSelectionDoneDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DeviceDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ClearDeviceSelectionDoneDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetDeviceSelectionResults(byte LocalUserNum, ScriptArray<wchar_t>& DeviceName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.GetDeviceSelectionResults");
			byte* params = (byte*)malloc(17);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = DeviceName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DeviceName = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsDeviceValid(int DeviceID, int SizeNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.IsDeviceValid");
			byte* params = (byte*)malloc(12);
			*(int*)params = DeviceID;
			*(int*)(params + 4) = SizeNeeded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UnlockGamerPicture(byte LocalUserNum, int PictureId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.UnlockGamerPicture");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = PictureId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.AddProfileDataChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ClearProfileDataChangedDelegate");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShowFriendsInviteUI(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowFriendsInviteUI");
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
		bool ShowPlayersUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowPlayersUI");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShowCustomPlayersUI(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowCustomPlayersUI");
			byte* params = (byte*)malloc(41);
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Players;
			*(ScriptArray<wchar_t>*)(params + 16) = Title;
			*(ScriptArray<wchar_t>*)(params + 28) = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		bool UnlockAvatarAward(byte LocalUserNum, int AvatarItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.UnlockAvatarAward");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(int*)(params + 4) = AvatarItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
