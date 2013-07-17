#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.MeshBeaconHost." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.MeshBeaconHost." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.MeshBeaconHost." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MeshBeaconHost : public MeshBeacon
	{
	public:
			void OnReceivedClientCreateNewSessionResult( bool bSucceeded, ScriptName SessionName, ScriptClass* SearchClass, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( bool* )( params + 0 ) = bSucceeded;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( ScriptClass** )( params + 12 ) = SearchClass;
				*( byte* )( params + 16 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 16 );
			}

			void OnAllPendingPlayersConnected(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFinishedBandwidthTest( void* PlayerNetId, byte TestType, byte TestResult, void* &BandwidthStats )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.OnFinishedBandwidthTest" );
				byte *params = ( byte* )( malloc( 22 ) );
				*( void** )( params + 0 ) = PlayerNetId;
				*( byte* )( params + 8 ) = TestType;
				*( byte* )( params + 9 ) = TestResult;
				*( void** )( params + 12 ) = BandwidthStats;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BandwidthStats = *( void** )( params + 12 );
			}

			void OnStartedBandwidthTest( void* PlayerNetId, byte TestType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.OnStartedBandwidthTest" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )( params + 0 ) = PlayerNetId;
				*( byte* )( params + 8 ) = TestType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReceivedClientConnectionRequest( void* &NewClientConnection )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest" );
				byte *params = ( byte* )( malloc( 88 ) );
				*( void** )( params + 0 ) = NewClientConnection;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewClientConnection = *( void** )( params + 0 );
			}

			ADD_VAR( ::IntProperty, ConnectionBacklog, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAllowBandwidthTesting, 0x1 )
			bool InitHostBeacon( void* InOwningPlayerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.InitHostBeacon" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = InOwningPlayerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DestroyBeacon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.DestroyBeacon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RequestClientBandwidthTest( void* PlayerNetId, byte TestType, int TestBufferSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.RequestClientBandwidthTest" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( void** )( params + 0 ) = PlayerNetId;
				*( byte* )( params + 8 ) = TestType;
				*( int* )( params + 12 ) = TestBufferSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HasInProgressBandwidthTest(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.HasInProgressBandwidthTest" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CancelInProgressBandwidthTests(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HasPendingBandwidthTest(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.HasPendingBandwidthTest" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CancelPendingBandwidthTests(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.CancelPendingBandwidthTests" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllowBandwidthTesting( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.AllowBandwidthTesting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPendingPlayerConnections(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.SetPendingPlayerConnections" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetConnectionIndexForPlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool AllPlayersConnected(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.AllPlayersConnected" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TellClientsToTravel( ScriptName SessionName, ScriptClass* SearchClass, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.TellClientsToTravel" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 12 );
			}

			bool RequestClientCreateNewSession( void* PlayerNetId, ScriptName SessionName, ScriptClass* SearchClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.MeshBeaconHost.RequestClientCreateNewSession" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = PlayerNetId;
				*( ScriptName* )( params + 8 ) = SessionName;
				*( ScriptClass** )( params + 16 ) = SearchClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
