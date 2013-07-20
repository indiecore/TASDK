#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.PartyBeaconClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.PartyBeaconClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.PartyBeaconClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PartyBeaconClient : public PartyBeacon
	{
	public:
			void OnHostHasCancelled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.OnHostHasCancelled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnHostIsReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.OnHostIsReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTravelRequestReceived( ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.OnTravelRequestReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )params = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReservationCountUpdated( int ReservationRemaining )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.OnReservationCountUpdated" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ReservationRemaining;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReservationRequestComplete( byte ReservationResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.OnReservationRequestComplete" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ReservationResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ClientBeaconAddressResolver, Resolver )
			ADD_OBJECT( ScriptClass, ResolverClass )
			ADD_VAR( ::StrProperty, ResolverClassName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReservationRequestElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReservationRequestTimeout, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconRequestType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconState, 0xFFFFFFFF )
			bool RequestReservation( void* &DesiredHost, void* RequestingPartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.RequestReservation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = DesiredHost;
				*( void** )( params + 8 ) = RequestingPartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredHost = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RequestReservationUpdate( void* &DesiredHost, void* RequestingPartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.RequestReservationUpdate" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = DesiredHost;
				*( void** )( params + 8 ) = RequestingPartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredHost = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CancelReservation( void* CancellingPartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.CancelReservation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = CancellingPartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DestroyBeacon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconClient.DestroyBeacon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
