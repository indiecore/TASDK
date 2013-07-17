#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.WebServer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.WebServer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.WebServer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WebServer : public TcpLink
	{
	public:
			ADD_VAR( ::IntProperty, ConnID, 0xFFFFFFFF )
			class WebApplication* GetApplication( ScriptArray< wchar_t > URI, ScriptArray< wchar_t > &SubURI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebServer.GetApplication" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URI;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SubURI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SubURI = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( class WebApplication** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, DefaultApplication, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ApplicationPaths, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ExpirationSeconds, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConnectionCount, 0xFFFFFFFF )
			ADD_OBJECT( WebApplication, ApplicationObjects )
			ADD_VAR( ::StrProperty, ServerURL, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxConnections, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ListenPort, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_VAR( ::StrProperty, Applications, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ServerName, 0xFFFFFFFF )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebServer.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebServer.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GainedChild( class Actor* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebServer.GainedChild" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LostChild( class Actor* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.WebServer.LostChild" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
