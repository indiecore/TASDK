#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.OnlineEventsInterfaceMcp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.OnlineEventsInterfaceMcp." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.OnlineEventsInterfaceMcp." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineEventsInterfaceMcp : public MCPBase
	{
	public:
			ADD_VAR( ::BoolProperty, bBinaryStats, 0x1 )
			bool UploadPlayerData( void* UniqueId, ScriptArray< wchar_t > PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineEventsInterfaceMcp.UploadPlayerData" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = UniqueId;
				*( ScriptArray< wchar_t >* )( params + 8 ) = PlayerNick;
				*( class OnlineProfileSettings** )( params + 20 ) = ProfileSettings;
				*( class OnlinePlayerStorage** )( params + 24 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UploadGameplayEventsData( void* UniqueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineEventsInterfaceMcp.UploadGameplayEventsData" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )params = UniqueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UpdatePlaylistPopulation( int PlaylistId, int NumPlayers )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineEventsInterfaceMcp.UpdatePlaylistPopulation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = PlaylistId;
				*( int* )( params + 4 ) = NumPlayers;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UploadMatchmakingStats( void* UniqueId, class OnlineMatchmakingStats* MMStats )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineEventsInterfaceMcp.UploadMatchmakingStats" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )params = UniqueId;
				*( class OnlineMatchmakingStats** )( params + 8 ) = MMStats;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
