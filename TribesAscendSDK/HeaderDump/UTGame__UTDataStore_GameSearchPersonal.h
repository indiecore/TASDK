#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDataStore_GameSearchPersonal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDataStore_GameSearchPersonal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDataStore_GameSearchPersonal." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDataStore_GameSearchPersonal : public UDKDataStore_GameSearchBase
	{
	public:
			ADD_OBJECT( UTDataStore_GameSearchDM, PrimaryGameSearchDataStore )
			bool HasOutstandingQueries( bool bRestrictCheckToSelf )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.HasOutstandingQueries" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bRestrictCheckToSelf;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, ServerUniqueId, 0xFFFFFFFF )
			bool OverrideQuerySubmission( byte ControllerId, class OnlineGameSearch* Search )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.OverrideQuerySubmission" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = ControllerId;
				*( class OnlineGameSearch** )( params + 4 ) = Search;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPlayerName( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool GetPlayerNetId( void* &out_PlayerId, int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.GetPlayerNetId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = out_PlayerId;
				*( int* )( params + 8 ) = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_PlayerId = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindServerIndexByString( int ControllerId, ScriptArray< wchar_t > IdToFind )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexByString" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = ControllerId;
				*( ScriptArray< wchar_t >* )( params + 4 ) = IdToFind;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FindServerIndexById( int ControllerId, void* &IdToFind )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.FindServerIndexById" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ControllerId;
				*( void** )( params + 4 ) = IdToFind;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				IdToFind = *( void** )( params + 4 );
				return *( int* )( params + function->return_val_offset() );
			}

			bool AddServer( int ControllerId, void* IdToAdd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.AddServer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ControllerId;
				*( void** )( params + 4 ) = IdToAdd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveServer( int ControllerId, void* IdToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.RemoveServer" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ControllerId;
				*( void** )( params + 4 ) = IdToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetServerIdList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.GetServerIdList" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetServerStringList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchPersonal.GetServerStringList" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
