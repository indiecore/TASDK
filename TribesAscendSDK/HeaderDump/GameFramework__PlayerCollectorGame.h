#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.PlayerCollectorGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.PlayerCollectorGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.PlayerCollectorGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerCollectorGame : public GameInfo
	{
	public:
			ADD_VAR( ::StrProperty, URLToLoad, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumberOfClientsToWaitFor, 0xFFFFFFFF )
			class PlayerController* Login( ScriptArray< wchar_t > Portal, ScriptArray< wchar_t > Options, void* UniqueId, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.PlayerCollectorGame.Login" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( ScriptArray< wchar_t >* )params = Portal;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( void** )( params + 24 ) = UniqueId;
				*( ScriptArray< wchar_t >* )( params + 32 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 32 );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.PlayerCollectorGame.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
