#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.WebConnection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.WebConnection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.WebConnection." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WebConnection : public TcpLink
	{
	public:
			ADD_VAR( ::IntProperty, ConnID, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLineLength, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxValueLength, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RawBytesExpecting, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDelayCleanup, 0x1 )
			ADD_OBJECT( WebApplication, Application )
			ADD_OBJECT( WebResponse, Response )
			ADD_OBJECT( WebRequest, Request )
			ADD_VAR( ::StrProperty, ReceivedData, 0xFFFFFFFF )
			ADD_OBJECT( WebServer, WebServer )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
