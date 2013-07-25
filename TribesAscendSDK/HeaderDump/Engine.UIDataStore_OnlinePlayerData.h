#pragma once
#include "Engine.UIDataProvider_OnlineFriends.h"
#include "Engine.UIDataStore_Remote.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.UIDataProvider_PlayerAchievements.h"
#include "Engine.UIDataProvider_OnlinePartyChatList.h"
#include "Engine.UIDataProvider_OnlineFriendMessages.h"
#include "Engine.UIDataProvider_OnlinePlayerStorage.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlinePlayerData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlinePlayerData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlinePlayerData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlinePlayerData : public UIDataStore_Remote
	{
	public:
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider)
		ADD_OBJECT(UIDataProvider_OnlinePartyChatList, PartyChatProvider)
		ADD_OBJECT(ScriptClass, PartyChatProviderClass)
		ADD_VAR(::StrProperty, PartyChatProviderClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, AchievementsProviderClass)
		ADD_VAR(::StrProperty, AchievementsProviderClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, FriendMessagesProviderClass)
		ADD_VAR(::StrProperty, FriendMessagesProviderClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, FriendsProviderClass)
		ADD_VAR(::StrProperty, FriendsProviderClassName, 0xFFFFFFFF)
		ADD_OBJECT(UIDataProvider_PlayerAchievements, AchievementsProvider)
		ADD_OBJECT(UIDataProvider_OnlineFriendMessages, FriendMessagesProvider)
		ADD_OBJECT(UIDataProvider_OnlinePlayerStorage, StorageProvider)
		ADD_OBJECT(ScriptClass, PlayerStorageClass)
		ADD_VAR(::StrProperty, PlayerStorageClassName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ProfileSettingsClass)
		ADD_VAR(::StrProperty, ProfileSettingsClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerNick, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerControllerId, 0xFFFFFFFF)
		ADD_OBJECT(UIDataProvider_OnlineFriends, FriendsProvider)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		void OnSettingProviderChanged(class UIDataProvider* SourceProvider, ScriptName SettingsName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.OnSettingProviderChanged");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayerDataChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.OnPlayerDataChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.RegisterDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.ClearDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineProfileSettings* GetCachedPlayerProfile(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.GetCachedPlayerProfile");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineProfileSettings**)(params + 4);
			free(params);
			return returnVal;
		}
		class OnlinePlayerStorage* GetCachedPlayerStorage(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlayerData.GetCachedPlayerStorage");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlinePlayerStorage**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
