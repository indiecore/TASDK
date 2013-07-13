#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.WebApplication." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.WebApplication." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.WebApplication." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WebApplication : public Object
	{
	public:
			ADD_VAR( ::StrProperty, Path, 0xFFFFFFFF )
			ADD_OBJECT( WebServer, WebServer )
			ADD_OBJECT( WorldInfo, WorldInfo )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
