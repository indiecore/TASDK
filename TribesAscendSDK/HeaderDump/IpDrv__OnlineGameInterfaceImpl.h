#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.OnlineGameInterfaceImpl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.OnlineGameInterfaceImpl." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.OnlineGameInterfaceImpl." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameInterfaceImpl : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, LanQueryTimeout, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LanQueryTimeLeft, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LanPacketPlatformMask, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LanGameUniqueId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LanAnnouncePort, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LanNonce, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LanBeaconState, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentGameState, 0xFFFFFFFF )
			ADD_OBJECT( OnlineGameSearch, GameSearch )
			ADD_OBJECT( OnlineGameSettings, GameSettings )
			ADD_OBJECT( OnlineSubsystemCommonImpl, OwningSubsystem )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
