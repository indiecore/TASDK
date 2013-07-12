#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.MeshBeaconClient." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.MeshBeaconClient." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.MeshBeaconClient." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MeshBeaconClient : public MeshBeacon
	{
	public:
			ADD_VAR( ::BoolProperty, bUsingRegisteredAddr, 0x1 )
			ADD_OBJECT( ClientBeaconAddressResolver, Resolver )
			ADD_VAR( ::StrProperty, ResolverClassName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConnectionRequestElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConnectionRequestTimeout, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconRequestType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconState, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
