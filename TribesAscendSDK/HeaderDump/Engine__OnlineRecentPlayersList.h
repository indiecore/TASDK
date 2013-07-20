#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineRecentPlayersList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineRecentPlayersList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineRecentPlayersList." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
			ADD_VAR( ::IntProperty, RecentPartiesAddIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecentPlayersAddIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxRecentParties, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxRecentPlayers, 0xFFFFFFFF )
			void AddPlayerToRecentPlayers( void* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.AddPlayerToRecentPlayers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRecentPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ClearRecentPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPartyToRecentParties( void* PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.AddPartyToRecentParties" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRecentParties(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ClearRecentParties" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayersFromRecentParties(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.GetPlayersFromRecentParties" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayersFromCurrentPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.GetPlayersFromCurrentPlayers" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetSkillForCurrentPlayer( void* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.GetSkillForCurrentPlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetTeamForCurrentPlayer( void* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.GetTeamForCurrentPlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetLastParty( void* PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.SetLastParty" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowRecentPlayerList( byte LocalUserNum, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Description )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ShowRecentPlayerList" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Description;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowRecentPartiesPlayerList( byte LocalUserNum, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Description )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ShowRecentPartiesPlayerList" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Description;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowLastPartyPlayerList( byte LocalUserNum, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Description )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ShowLastPartyPlayerList" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Description;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowCurrentPlayersList( byte LocalUserNum, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Description )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.ShowCurrentPlayersList" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Description;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetCurrentPlayersList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.SetCurrentPlayersList" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCurrentPlayersListCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineRecentPlayersList.GetCurrentPlayersListCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
