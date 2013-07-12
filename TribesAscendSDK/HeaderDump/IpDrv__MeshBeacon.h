#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.MeshBeacon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.MeshBeacon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.MeshBeacon." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MeshBeacon : public Object
	{
	public:
			ADD_VAR( ::IntProperty, MaxBandwidthHistoryEntries, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxBandwidthTestReceiveTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxBandwidthTestSendTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinBandwidthTestBufferSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxBandwidthTestBufferSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SocketReceiveBufferSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SocketSendBufferSize, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BeaconName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeartbeatTimeout, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldTick, 0x4 )
			ADD_VAR( ::BoolProperty, bWantsDeferredDestroy, 0x2 )
			ADD_VAR( ::BoolProperty, bIsInTick, 0x1 )
			ADD_VAR( ::IntProperty, MeshBeaconPort, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
