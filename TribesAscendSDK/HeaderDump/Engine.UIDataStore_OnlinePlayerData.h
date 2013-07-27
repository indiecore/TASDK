#pragma once
#include "Engine.UIDataProvider_OnlineFriends.h"
#include "Engine.UIDataStore_Remote.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.UIDataProvider_PlayerAchievements.h"
#include "Engine.UIDataProvider_OnlinePartyChatList.h"
#include "Core.Object.h"
#include "Engine.UIDataProvider_OnlineFriendMessages.h"
#include "Engine.UIDataProvider_OnlinePlayerStorage.h"
#include "Engine.UIDataProvider.h"
#include "Engine.LocalPlayer.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
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
	class UIDataStore_OnlinePlayerData : public UIDataStore_Remote
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider, 160)
		ADD_OBJECT(UIDataProvider_OnlinePartyChatList, PartyChatProvider, 256)
		ADD_OBJECT(ScriptClass, PartyChatProviderClass, 252)
		ADD_STRUCT(ScriptString*, PartyChatProviderClassName, 240)
		ADD_OBJECT(ScriptClass, AchievementsProviderClass, 236)
		ADD_STRUCT(ScriptString*, AchievementsProviderClassName, 224)
		ADD_OBJECT(ScriptClass, FriendMessagesProviderClass, 220)
		ADD_STRUCT(ScriptString*, FriendMessagesProviderClassName, 208)
		ADD_OBJECT(ScriptClass, FriendsProviderClass, 204)
		ADD_STRUCT(ScriptString*, FriendsProviderClassName, 192)
		ADD_OBJECT(UIDataProvider_PlayerAchievements, AchievementsProvider, 188)
		ADD_OBJECT(UIDataProvider_OnlineFriendMessages, FriendMessagesProvider, 184)
		ADD_OBJECT(UIDataProvider_OnlinePlayerStorage, StorageProvider, 180)
		ADD_OBJECT(ScriptClass, PlayerStorageClass, 176)
		ADD_STRUCT(ScriptString*, PlayerStorageClassName, 164)
		ADD_OBJECT(ScriptClass, ProfileSettingsClass, 156)
		ADD_STRUCT(ScriptString*, ProfileSettingsClassName, 144)
		ADD_STRUCT(ScriptString*, PlayerNick, 132)
		ADD_STRUCT(int, PlayerControllerId, 128)
		ADD_OBJECT(UIDataProvider_OnlineFriends, FriendsProvider, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
		void OnSettingProviderChanged(class UIDataProvider* SourceProvider, ScriptName SettingsName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28750);
			byte params[12] = { NULL };
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)&params[4] = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28753);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28757);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28760);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayerDataChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28764);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28766);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28767);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineProfileSettings* GetCachedPlayerProfile(int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28768);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineProfileSettings**)&params[4];
		}
		class OnlinePlayerStorage* GetCachedPlayerStorage(int ControllerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28774);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlinePlayerStorage**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
