#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineEventsInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineEventsInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineEventsInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineEventsInterface : public Interface
	{
	public:
			bool UploadPlayerData( void* UniqueId, ScriptArray< wchar_t > PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineEventsInterface.UploadPlayerData" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = UniqueId;
				*( ScriptArray< wchar_t >* )( params + 8 ) = PlayerNick;
				*( class OnlineProfileSettings** )( params + 20 ) = ProfileSettings;
				*( class OnlinePlayerStorage** )( params + 24 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UploadGameplayEventsData( void* UniqueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineEventsInterface.UploadGameplayEventsData" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = UniqueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UpdatePlaylistPopulation( int PlaylistId, int NumPlayers )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineEventsInterface.UpdatePlaylistPopulation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = PlaylistId;
				*( int* )( params + 4 ) = NumPlayers;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
