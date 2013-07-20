#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTEntryPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTEntryPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTEntryPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTEntryPlayerController : public UTPlayerController
	{
	public:
			ADD_OBJECT( LocalPlayer, OldPlayer )
			ADD_OBJECT( PostProcessChain, EntryPostProcessChain )
			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestorePostProcessing(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.RestorePostProcessing" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnControllerChanged( int ControllerId, bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnControllerChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ControllerId;
				*( bool* )( params + 4 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteReceived( byte LocalUserNum, ScriptArray< wchar_t > RequestingNick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnGameInviteReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = RequestingNick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnFriendInviteReceived" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnFriendMessageReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = SendingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SendingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnConnectionStatusChange( byte ConnectionStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnConnectionStatusChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ConnectionStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLinkStatusChanged( bool bConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.OnLinkStatusChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void QuitToMainMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.QuitToMainMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPawnConstructionScene( bool bShow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.SetPawnConstructionScene" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMidGameMenu( ScriptName TabTag, bool bEnableInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.ShowMidGameMenu" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TabTag;
				*( bool* )( params + 8 ) = bEnableInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowScoreboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTEntryPlayerController.ShowScoreboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
