#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlineFriends." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlineFriends." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlineFriends." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlineFriends : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::StrProperty, BusyText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AwayText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OnlineText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OfflineText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bHasInvitedYouCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bHaveInvitedCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bHasVoiceSupportCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsJoinableCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsPlayingThisGameCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsPlayingCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsOnlineCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FriendStateCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PresenceInfoCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NickNameCol, 0xFFFFFFFF )
			void OnRegister( class LocalPlayer* InPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriends.OnRegister" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = InPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregister(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriends.OnUnregister" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendsReadComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriends.OnFriendsReadComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriends.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshFriendsList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriends.RefreshFriendsList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
