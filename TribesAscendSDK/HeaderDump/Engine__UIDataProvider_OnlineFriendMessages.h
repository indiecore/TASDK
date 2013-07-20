#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_OnlineFriendMessages." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_OnlineFriendMessages." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_OnlineFriendMessages." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
			ADD_VAR( ::StrProperty, LastInviteFrom, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MessageCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bWasDeniedCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bWasAcceptedCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, bIsFriendInviteCol, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SendingPlayerNameCol, 0xFFFFFFFF )
			void OnRegister( class LocalPlayer* InPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnRegister" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = InPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregister(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnUnregister" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadMessages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.ReadMessages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendInviteReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = RequestingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendMessageReceived( byte LocalUserNum, void* SendingPlayer, ScriptArray< wchar_t > SendingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendMessageReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = SendingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SendingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteReceived( byte LocalUserNum, ScriptArray< wchar_t > InviterName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_OnlineFriendMessages.OnGameInviteReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = InviterName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
