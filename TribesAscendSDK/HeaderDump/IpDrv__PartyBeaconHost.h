#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.PartyBeaconHost." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.PartyBeaconHost." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.PartyBeaconHost." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PartyBeaconHost : public PartyBeacon
	{
	public:
			void OnClientCancellationReceived( void* PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.OnClientCancellationReceived" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReservationsFull(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.OnReservationsFull" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReservationChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.OnReservationChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, BeaconState, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBestFitTeamAssignment, 0x1 )
			ADD_VAR( ::IntProperty, ReservedHostTeamNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ForceTeamNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConnectionBacklog, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, OnlineSessionName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumConsumedReservations, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumReservations, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumPlayersPerTeam, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumTeams, 0xFFFFFFFF )
			void PauseReservationRequests( bool bPause )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.PauseReservationRequests" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPause;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InitHostBeacon( int InNumTeams, int InNumPlayersPerTeam, int InNumReservations, ScriptName InSessionName, int InForceTeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.InitHostBeacon" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( int* )( params + 0 ) = InNumTeams;
				*( int* )( params + 4 ) = InNumPlayersPerTeam;
				*( int* )( params + 8 ) = InNumReservations;
				*( ScriptName* )( params + 12 ) = InSessionName;
				*( int* )( params + 20 ) = InForceTeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte AddPartyReservationEntry( void* PartyLeader, int TeamNum, bool bIsHost )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.AddPartyReservationEntry" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = PartyLeader;
				*( int* )( params + 20 ) = TeamNum;
				*( bool* )( params + 24 ) = bIsHost;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte UpdatePartyReservationEntry( void* PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.UpdatePartyReservationEntry" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			int GetExistingReservation( void* &PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.GetExistingReservation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PartyLeader = *( void** )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			void HandlePlayerLogout( void* PlayerID, bool bMaintainParty )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.HandlePlayerLogout" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = PlayerID;
				*( bool* )( params + 8 ) = bMaintainParty;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyBeacon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.DestroyBeacon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellClientsToTravel( ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.TellClientsToTravel" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellClientsHostIsReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.TellClientsHostIsReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellClientsHostHasCancelled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.TellClientsHostHasCancelled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AreReservationsFull(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.AreReservationsFull" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RegisterPartyMembers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.RegisterPartyMembers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterPartyMembers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.UnregisterPartyMembers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterParty( void* PartyLeader )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.UnregisterParty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = PartyLeader;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AppendReservationSkillsToSearch( class OnlineGameSearch* Search )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.AppendReservationSkillsToSearch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineGameSearch** )( params + 0 ) = Search;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.GetPlayers" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetPartyLeaders(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.GetPartyLeaders" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetMaxAvailableTeamSize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.PartyBeaconHost.GetMaxAvailableTeamSize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
