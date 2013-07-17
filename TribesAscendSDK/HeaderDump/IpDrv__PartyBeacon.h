#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.PartyBeacon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.PartyBeacon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.PartyBeacon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PartyBeacon : public Object
	{
	public:
			void OnDestroyComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeacon.OnDestroyComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, BeaconName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeartbeatTimeout, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldTick, 0x4 )
			ADD_VAR( ::BoolProperty, bWantsDeferredDestroy, 0x2 )
			ADD_VAR( ::BoolProperty, bIsInTick, 0x1 )
			ADD_VAR( ::IntProperty, PartyBeaconPort, 0xFFFFFFFF )
			void DestroyBeacon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeacon.DestroyBeacon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
