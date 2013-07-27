#pragma once
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine.OnlineSubsystem.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriends : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlineFriend>, FriendsList, 96)
		ADD_STRUCT(ScriptString*, BusyText, 264)
		ADD_STRUCT(ScriptString*, AwayText, 252)
		ADD_STRUCT(ScriptString*, OnlineText, 240)
		ADD_STRUCT(ScriptString*, OfflineText, 228)
		ADD_STRUCT(ScriptString*, bHasInvitedYouCol, 216)
		ADD_STRUCT(ScriptString*, bHaveInvitedCol, 204)
		ADD_STRUCT(ScriptString*, bHasVoiceSupportCol, 192)
		ADD_STRUCT(ScriptString*, bIsJoinableCol, 180)
		ADD_STRUCT(ScriptString*, bIsPlayingThisGameCol, 168)
		ADD_STRUCT(ScriptString*, bIsPlayingCol, 156)
		ADD_STRUCT(ScriptString*, bIsOnlineCol, 144)
		ADD_STRUCT(ScriptString*, FriendStateCol, 132)
		ADD_STRUCT(ScriptString*, PresenceInfoCol, 120)
		ADD_STRUCT(ScriptString*, NickNameCol, 108)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnRegister");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFriendsReadComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnFriendsReadComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshFriendsList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.RefreshFriendsList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
