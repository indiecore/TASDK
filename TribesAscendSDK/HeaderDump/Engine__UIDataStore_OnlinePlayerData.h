#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_OnlinePlayerData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_OnlinePlayerData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_OnlinePlayerData." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlinePlayerData : public UIDataStore_Remote
	{
	public:
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
			ADD_OBJECT( UIDataProvider_OnlinePartyChatList, PartyChatProvider )
			ADD_OBJECT( ScriptClass, PartyChatProviderClass )
			ADD_VAR( ::StrProperty, PartyChatProviderClassName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, AchievementsProviderClass )
			ADD_VAR( ::StrProperty, AchievementsProviderClassName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, FriendMessagesProviderClass )
			ADD_VAR( ::StrProperty, FriendMessagesProviderClassName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, FriendsProviderClass )
			ADD_VAR( ::StrProperty, FriendsProviderClassName, 0xFFFFFFFF )
			ADD_OBJECT( UIDataProvider_PlayerAchievements, AchievementsProvider )
			ADD_OBJECT( UIDataProvider_OnlineFriendMessages, FriendMessagesProvider )
			ADD_OBJECT( UIDataProvider_OnlinePlayerStorage, StorageProvider )
			ADD_OBJECT( ScriptClass, PlayerStorageClass )
			ADD_VAR( ::StrProperty, PlayerStorageClassName, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, ProfileSettingsClass )
			ADD_VAR( ::StrProperty, ProfileSettingsClassName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerNick, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerControllerId, 0xFFFFFFFF )
			ADD_OBJECT( UIDataProvider_OnlineFriends, FriendsProvider )
			void OnSettingProviderChanged( class UIDataProvider* SourceProvider, ScriptName SettingsName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.OnSettingProviderChanged" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UIDataProvider** )params = SourceProvider;
				*( ScriptName* )( params + 4 ) = SettingsName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegister( class LocalPlayer* InPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.OnRegister" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = InPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregister(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.OnUnregister" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayerDataChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.OnPlayerDataChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.RegisterDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.ClearDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlineProfileSettings* GetCachedPlayerProfile( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.GetCachedPlayerProfile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineProfileSettings** )( params + function->return_val_offset() );
			}

			class OnlinePlayerStorage* GetCachedPlayerStorage( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlayerData.GetCachedPlayerStorage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlinePlayerStorage** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
