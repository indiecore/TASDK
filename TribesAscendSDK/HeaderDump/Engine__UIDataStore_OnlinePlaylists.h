#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_OnlinePlaylists." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_OnlinePlaylists." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_OnlinePlaylists." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlinePlaylists : public UIDataStore
	{
	public:
			ADD_OBJECT( ScriptClass, ProviderClass )
			ADD_VAR( ::StrProperty, ProviderClassName, 0xFFFFFFFF )
			int GetProviderCount( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetProviderCount" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetResourceProviders( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviders" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetResourceProviderFields( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviderFields" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProviderFieldValue( ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, void* &out_FieldValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetProviderFieldValue" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( ScriptName* )params = ProviderTag;
				*( ScriptName* )( params + 8 ) = SearchField;
				*( int* )( params + 16 ) = ProviderIndex;
				*( void** )( params + 20 ) = out_FieldValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_FieldValue = *( void** )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindProviderIndexByFieldValue( ScriptName ProviderTag, ScriptName SearchField, void* &ValueToSearchFor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.FindProviderIndexByFieldValue" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptName* )params = ProviderTag;
				*( ScriptName* )( params + 8 ) = SearchField;
				*( void** )( params + 16 ) = ValueToSearchFor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueToSearchFor = *( void** )( params + 16 );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetPlaylistProvider( ScriptName ProviderTag, int ProviderIndex, class UIResourceDataProvider* &out_Provider )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetPlaylistProvider" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = ProviderTag;
				*( int* )( params + 8 ) = ProviderIndex;
				*( class UIResourceDataProvider** )( params + 12 ) = out_Provider;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Provider = *( class UIResourceDataProvider** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			class OnlinePlaylistProvider* GetOnlinePlaylistProvider( ScriptName ProviderTag, int PlaylistId, int &ProviderIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlinePlaylists.GetOnlinePlaylistProvider" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = ProviderTag;
				*( int* )( params + 8 ) = PlaylistId;
				*( int* )( params + 12 ) = ProviderIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ProviderIndex = *( int* )( params + 12 );
				return *( class OnlinePlaylistProvider** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
