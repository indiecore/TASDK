#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlineFriends." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlineFriends." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriends : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::StrProperty, BusyText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AwayText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OnlineText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OfflineText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHasInvitedYouCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHaveInvitedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bHasVoiceSupportCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsJoinableCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsPlayingThisGameCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsPlayingCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsOnlineCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendStateCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PresenceInfoCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NickNameCol, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFriendsReadComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnFriendsReadComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshFriendsList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriends.RefreshFriendsList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
