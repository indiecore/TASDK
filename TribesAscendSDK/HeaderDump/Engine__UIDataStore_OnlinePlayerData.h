#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIDataStore_OnlinePlayerData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIDataStore_OnlinePlayerData." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIDataStore_OnlinePlayerData." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlinePlayerData : public UIDataStore_Remote
	{
	public:
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
			ADD_OBJECT( UIDataProvider_OnlinePartyChatList, PartyChatProvider )
			ADD_VAR( ::StrProperty, PartyChatProviderClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AchievementsProviderClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendMessagesProviderClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendsProviderClassName, 0xFFFFFFFF )
			ADD_OBJECT( UIDataProvider_PlayerAchievements, AchievementsProvider )
			ADD_OBJECT( UIDataProvider_OnlineFriendMessages, FriendMessagesProvider )
			ADD_OBJECT( UIDataProvider_OnlinePlayerStorage, StorageProvider )
			ADD_VAR( ::StrProperty, PlayerStorageClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProfileSettingsClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerNick, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerControllerId, 0xFFFFFFFF )
			ADD_OBJECT( UIDataProvider_OnlineFriends, FriendsProvider )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
