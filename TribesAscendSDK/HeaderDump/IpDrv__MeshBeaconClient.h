#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.MeshBeaconClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.MeshBeaconClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.MeshBeaconClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MeshBeaconClient : public MeshBeacon
	{
	public:
			void OnCreateNewSessionRequestReceived( ScriptName SessionName, ScriptClass* SearchClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.OnCreateNewSessionRequestReceived" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTravelRequestReceived( ScriptName SessionName, ScriptClass* SearchClass, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.OnTravelRequestReceived" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 12 );
			}

			void OnReceivedBandwidthTestResults( byte TestType, byte TestResult, void* &BandwidthStats )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestResults" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( byte* )( params + 0 ) = TestType;
				*( byte* )( params + 1 ) = TestResult;
				*( void** )( params + 4 ) = BandwidthStats;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BandwidthStats = *( void** )( params + 4 );
			}

			void OnReceivedBandwidthTestRequest( byte TestType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestRequest" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = TestType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnConnectionRequestResult( byte ConnectionResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.OnConnectionRequestResult" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = ConnectionResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bUsingRegisteredAddr, 0x1 )
			ADD_OBJECT( ClientBeaconAddressResolver, Resolver )
			ADD_OBJECT( ScriptClass, ResolverClass )
			ADD_VAR( ::StrProperty, ResolverClassName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConnectionRequestElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConnectionRequestTimeout, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconRequestType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ClientBeaconState, 0xFFFFFFFF )
			void DestroyBeacon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.DestroyBeacon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RequestConnection( void* &DesiredHost, void* &ClientRequest, bool bRegisterSecureAddress )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.RequestConnection" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 0 ) = DesiredHost;
				*( void** )( params + 8 ) = ClientRequest;
				*( bool* )( params + 44 ) = bRegisterSecureAddress;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredHost = *( void** )( params + 0 );
				ClientRequest = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BeginBandwidthTest( byte TestType, int TestBufferSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.BeginBandwidthTest" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = TestType;
				*( int* )( params + 4 ) = TestBufferSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SendHostNewGameSessionResponse( bool bSuccess, ScriptName SessionName, ScriptClass* SearchClass, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconClient.SendHostNewGameSessionResponse" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( bool* )( params + 0 ) = bSuccess;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( ScriptClass** )( params + 12 ) = SearchClass;
				*( byte* )( params + 16 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
