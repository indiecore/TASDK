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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22318);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowGamerCardUI(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22322);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowMessagesUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22326);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowAchievementsUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22329);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowInviteUI(byte LocalUserNum, ScriptString* InviteText)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22332);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = InviteText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ShowContentMarketplaceUI(byte LocalUserNum, int CategoryMask, int OfferId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22336);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = CategoryMask;
			*(int*)&params[8] = OfferId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowMembershipMarketplaceUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22341);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowDeviceSelectionUI(byte LocalUserNum, int SizeNeeded, bool bManageStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22344);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = SizeNeeded;
			*(bool*)&params[8] = bManageStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnDeviceSelectionComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22349);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnProfileDataChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22352);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDeviceSelectionDoneDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DeviceDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22354);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearDeviceSelectionDoneDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DeviceDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22357);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = DeviceDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetDeviceSelectionResults(byte LocalUserNum, ScriptString*& DeviceName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22360);
			byte params[17] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = DeviceName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DeviceName = *(ScriptString**)&params[4];
			return *(int*)&params[16];
		}
		bool IsDeviceValid(int DeviceID, int SizeNeeded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22364);
			byte params[12] = { NULL };
			*(int*)params = DeviceID;
			*(int*)&params[4] = SizeNeeded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UnlockGamerPicture(byte LocalUserNum, int PictureId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22368);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = PictureId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22372);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearProfileDataChangedDelegate(byte LocalUserNum, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ProfileDataChangedDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22375);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = ProfileDataChangedDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowFriendsInviteUI(byte LocalUserNum, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22378);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ShowPlayersUI(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22382);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShowCustomPlayersUI(byte LocalUserNum, ScriptArray<OnlineSubsystem::UniqueNetId>& Players, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22385);
			byte params[41] = { NULL };
			*params = LocalUserNum;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4] = Players;
			*(ScriptString**)&params[16] = Title;
			*(ScriptString**)&params[28] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[4];
			return *(bool*)&params[40];
		}
		bool UnlockAvatarAward(byte LocalUserNum, int AvatarItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22392);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(int*)&params[4] = AvatarItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
