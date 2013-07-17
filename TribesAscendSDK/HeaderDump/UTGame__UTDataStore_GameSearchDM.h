#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDataStore_GameSearchDM." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDataStore_GameSearchDM." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDataStore_GameSearchDM." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDataStore_GameSearchDM : public UDKDataStore_GameSearchBase
	{
	public:
			ADD_OBJECT( UTDataStore_GameSearchHistory, HistoryGameSearchDataStore )
			ADD_OBJECT( ScriptClass, HistoryGameSearchDataStoreClass )
			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SubmitGameSearch( byte ControllerIndex, bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.SubmitGameSearch" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = ControllerIndex;
				*( bool* )( params + 4 ) = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasOutstandingQueries( bool bRestrictCheckToSelf )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.HasOutstandingQueries" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bRestrictCheckToSelf;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindStoredSearchIndex( ScriptName GameSearchName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.FindStoredSearchIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = GameSearchName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int FindStoredSettingValueIndex( int StoredGameSearchIndex, int LocalizedSettingId, bool bAddIfNecessary )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.FindStoredSettingValueIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = StoredGameSearchIndex;
				*( int* )( params + 4 ) = LocalizedSettingId;
				*( bool* )( params + 8 ) = bAddIfNecessary;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void LoadGameSearchParameters(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.LoadGameSearchParameters" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveGameSearchParameters(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDataStore_GameSearchDM.SaveGameSearchParameters" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
