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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
