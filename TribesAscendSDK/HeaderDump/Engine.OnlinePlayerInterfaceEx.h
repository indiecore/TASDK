#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
namespace UnrealScript
{
	class OnlinePlayerInterfaceEx : public Interface
	{
	public:
		bool ShowFeedbackUI(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowFeedbackUI");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowGamerCardUI(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowGamerCardUI");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowMessagesUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowMessagesUI");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowAchievementsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowAchievementsUI");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowInviteUI(byte LocalUserNum, ScriptString* InviteText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowInviteUI");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = InviteText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ShowContentMarketplaceUI(byte LocalUserNum, int CategoryMask, int OfferId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowContentMarketplaceUI");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = CategoryMask;
			*(int*)&params[8] = OfferId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowMembershipMarketplaceUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowMembershipMarketplaceUI");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowDeviceSelectionUI(byte LocalUserNum, int SizeNeeded, bool bManageStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowDeviceSelectionUI");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = SizeNeeded;
			*(bool*)&params[8] = bManageStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnDeviceSelectionComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.OnDeviceSelectionComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDeviceSelectionDoneDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DeviceDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ClearDeviceSelectionDoneDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetDeviceSelectionResults(byte LocalUserNum, ScriptString*& DeviceName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.GetDeviceSelectionResults");
			byte params[17] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = DeviceName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DeviceName = *(ScriptString**)&params[4];
			return *(int*)&params[16];
		}
		bool IsDeviceValid(int DeviceID, int SizeNeeded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.IsDeviceValid");
			byte params[12] = { NULL };
			*(int*)&params[0] = DeviceID;
			*(int*)&params[4] = SizeNeeded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnlockGamerPicture(byte LocalUserNum, int PictureId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.UnlockGamerPicture");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = PictureId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.AddProfileDataChangedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ClearProfileDataChangedDelegate");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowFriendsInviteUI(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowFriendsInviteUI");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowPlayersUI(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowPlayersUI");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowCustomPlayersUI(byte LocalUserNum, ScriptArray<OnlineSubsystem::UniqueNetId>& Players, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.ShowCustomPlayersUI");
			byte params[41] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4] = Players;
			*(ScriptString**)&params[16] = Title;
			*(ScriptString**)&params[28] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4];
			return *(bool*)&params[40];
		}
		bool UnlockAvatarAward(byte LocalUserNum, int AvatarItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerInterfaceEx.UnlockAvatarAward");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(int*)&params[4] = AvatarItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
