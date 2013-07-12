#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.WebServer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.WebServer." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.WebServer." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WebServer : public TcpLink
	{
	public:
			ADD_VAR( ::IntProperty, ConnID, 0xFFFFFFFF )
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
