#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerController : public Controller
	{
	public:
			ADD_VAR( ::FloatProperty, LODDistanceFactor, 0xFFFFFFFF )
			float GetFOVAngle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetFOVAngle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Player, Player )
			ScriptArray< wchar_t > GetPlayerNetworkAddress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPlayerNetworkAddress" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Actor, ViewTarget )
			class Actor* GetViewTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetViewTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Camera, PlayerCamera )
			bool IsPrimaryPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsPrimaryPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetNetSpeed( int NewSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetNetSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetServerNetworkAddress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetServerNetworkAddress" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > ConsoleCommand( ScriptArray< wchar_t > Command, bool bWriteToLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ConsoleCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Command;
				*( bool* )( params + 12 ) = bWriteToLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ClientTravel( ScriptArray< wchar_t > URL, byte TravelType, bool bSeamless, void* MapPackageGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientTravel" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				*( byte* )( params + 12 ) = TravelType;
				*( bool* )( params + 16 ) = bSeamless;
				*( void** )( params + 20 ) = MapPackageGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateURL( ScriptArray< wchar_t > NewOption, ScriptArray< wchar_t > NewValue, bool bSave1Default )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UpdateURL" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = NewOption;
				*( ScriptArray< wchar_t >* )( params + 12 ) = NewValue;
				*( bool* )( params + 24 ) = bSave1Default;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDefaultURL( ScriptArray< wchar_t > Option )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetDefaultURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Option;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void CopyToClipboard( ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CopyToClipboard" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > PasteFromClipboard(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PasteFromClipboard" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetAllowMatureLanguage( bool bAllowMatureLanguge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetAllowMatureLanguage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bAllowMatureLanguge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAudioGroupVolume( ScriptName GroupName, float Volume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetAudioGroupVolume" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = GroupName;
				*( float* )( params + 8 ) = Volume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientConvolve( ScriptArray< wchar_t > C, int H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientConvolve" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = C;
				*( int* )( params + 12 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerProcessConvolve( ScriptArray< wchar_t > C, int H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerProcessConvolve" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = C;
				*( int* )( params + 12 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckSpeedHack( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CheckSpeedHack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindStairRotation( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FindStairRotation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void CleanUpAudioComponents(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CleanUpAudioComponents" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceClearUnpauseDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ForceClearUnpauseDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnExternalUIChanged( bool bIsOpening )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnExternalUIChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIsOpening;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bIsExternalUIOpen, 0x400000 )
			bool CanUnpauseExternalUI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanUnpauseExternalUI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bPendingDestroy, 0x200 )
			void OnControllerChanged( int ControllerId, bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnControllerChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ControllerId;
				*( bool* )( params + 4 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bIsControllerConnected, 0x800000 )
			bool CanUnpauseControllerConnected(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanUnpauseControllerConnected" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class CoverReplicator* SpawnCoverReplicator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SpawnCoverReplicator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class CoverReplicator** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( CoverReplicator, MyCoverReplicator )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MaxTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxResponseTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastActiveTime, 0xFFFFFFFF )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			void ReceivedPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ReceivedPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RegisterPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindConnectedPeerIndex( void* PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FindConnectedPeerIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void AddPeer( void* PeerNetId, byte NatType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AddPeer" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )params = PeerNetId;
				*( byte* )( params + 8 ) = NatType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemovePeer( void* PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RemovePeer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAddPeer( void* PeerNetId, byte NatType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerAddPeer" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )params = PeerNetId;
				*( byte* )( params + 8 ) = NatType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRemovePeer( void* PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerRemovePeer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUpdateBestNextHosts( void* SortedNextHosts, byte NumEntries )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientUpdateBestNextHosts" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )params = SortedNextHosts;
				*( byte* )( params + 80 ) = NumEntries;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyPeerDisconnectHost( void* PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyPeerDisconnectHost" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsBestHostPeer( void* PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsBestHostPeer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MigrateNewHost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.MigrateNewHost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnEndGameForHostMigrate( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnEndGameForHostMigrate" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetRegisteredPlayersInSession( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetRegisteredPlayersInSession" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMissingPeersFromSession( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RemoveMissingPeersFromSession" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregisterPlayerCompleteForMigrate( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnUnregisterPlayerCompleteForMigrate" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnHostMigratedOnlineGame( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnHostMigratedOnlineGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetCurrentSearchClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetCurrentSearchClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void PeerDesignatedAsHost( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PeerDesignatedAsHost" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PeerTravelAsHost( float TravelCountdownTimer, ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PeerTravelAsHost" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = TravelCountdownTimer;
				*( ScriptArray< wchar_t >* )( params + 4 ) = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellPeerToTravel( void* ToPeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TellPeerToTravel" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = ToPeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellPeerToTravelToSession( void* ToPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo, int PlatformSpecificInfoSize )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TellPeerToTravelToSession" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( void** )params = ToPeerNetId;
				*( ScriptName* )( params + 8 ) = SessionName;
				*( ScriptClass** )( params + 16 ) = SearchClass;
				*( byte* )( params + 20 ) = PlatformSpecificInfo;
				*( int* )( params + 100 ) = PlatformSpecificInfoSize;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PeerReceivedMigratedSession( void* FromPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PeerReceivedMigratedSession" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( void** )params = FromPeerNetId;
				*( ScriptName* )( params + 8 ) = SessionName;
				*( ScriptClass** )( params + 16 ) = SearchClass;
				*( byte* )( params + 20 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( OnlineGameSearch, MigratedSearchToJoin )
			void OnEndGameForJoinMigrate( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnEndGameForJoinMigrate" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinMigratedGame( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnJoinMigratedGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreRender( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PreRender" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )params = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetTimeMargin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ResetTimeMargin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, TimeMargin, 0xFFFFFFFF )
			void ServerShortTimeout(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerShortTimeout" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bShortConnectTimeOut, 0x100 )
			void ServerGivePawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerGivePawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickWarning(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.KickWarning" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCheats( bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AddCheats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableCheats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.EnableCheats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnDefaultHUD(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SpawnDefaultHUD" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( HUD, myHUD )
			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, WaitDelay, 0xFFFFFFFF )
			void ClientReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanOutSavedMoves(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CleanOutSavedMoves" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SavedMove, SavedMoves )
			ADD_OBJECT( SavedMove, PendingMove )
			void PreControllerIdChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PreControllerIdChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostControllerIdChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PostControllerIdChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlineSubsystem* GetOnlineSubsystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetOnlineSubsystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineSubsystem** )( params + function->return_val_offset() );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( PlayerInput, PlayerInput )
			ADD_OBJECT( ScriptClass, InputClass )
			ADD_VAR( ::StrProperty, ForceFeedbackManagerClassName, 0xFFFFFFFF )
			ADD_OBJECT( ForceFeedbackManager, ForceFeedbackManager )
			void ClientInitializeDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientInitializeDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterCustomPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RegisterCustomPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( UIDataStore_OnlinePlayerData, OnlinePlayerData )
			void RegisterStandardPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RegisterStandardPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UnregisterPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnregisterStandardPlayerDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UnregisterStandardPlayerDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReloadProfileSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ReloadProfileSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRumbleScale( float ScaleBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetRumbleScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = ScaleBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsControllerTiltActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsControllerTiltActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetControllerTiltDesiredIfAvailable( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetControllerTiltDesiredIfAvailable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetControllerTiltActive( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetControllerTiltActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOnlyUseControllerTiltInput( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetOnlyUseControllerTiltInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetUseTiltForwardAndBack( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetUseTiltForwardAndBack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsKeyboardAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsKeyboardAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsMouseAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsMouseAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClientGotoState( ScriptName NewState, ScriptName NewLabel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientGotoState" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = NewState;
				*( ScriptName* )( params + 8 ) = NewLabel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AskForPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AskForPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bFrozen, 0x1 )
			void GivePawn( class Pawn* NewPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GivePawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = NewPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Possess( class Pawn* aPawn, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Possess" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = aPawn;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AcknowledgePossession( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AcknowledgePossession" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( Pawn, AcknowledgedPawn )
			void ServerAcknowledgePossession( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerAcknowledgePossession" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UnPossess(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UnPossess" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnDied( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PawnDied" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetHUD( ScriptClass* newHUDType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = newHUDType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandlePickup( class Inventory* Inv )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.HandlePickup" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Inventory** )params = Inv;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanupPRI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CleanupPRI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceiveLocalizedMessage( ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ReceiveLocalizedMessage" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptClass** )params = Message;
				*( int* )( params + 4 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 8 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI_;
				*( class Object** )( params + 16 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlaySound( class SoundCue* ASound )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPlaySound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SoundCue** )params = ASound;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HearSoundFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.HearSoundFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetPooledAudioComponent( class SoundCue* ASound, class Actor* SourceActor, bool bStopWhenOwnerDestroyed, bool bUseLocation, Vector SourceLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPooledAudioComponent" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( bool* )( params + 8 ) = bStopWhenOwnerDestroyed;
				*( bool* )( params + 12 ) = bUseLocation;
				*( Vector* )( params + 16 ) = SourceLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void ClientHearSound( class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientHearSound" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( Vector* )( params + 8 ) = SourceLocation;
				*( bool* )( params + 20 ) = bStopWhenOwnerDestroyed;
				*( bool* )( params + 24 ) = bIsOccluded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsClosestLocalPlayerToActor( class Actor* TheActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsClosestLocalPlayerToActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = TheActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Kismet_ClientPlaySound( class SoundCue* ASound, class Actor* SourceActor, float VolumeMultiplier, float PitchMultiplier, float FadeInTime, bool bSuppressSubtitles, bool bSuppressSpatialization )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Kismet_ClientPlaySound" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( float* )( params + 8 ) = VolumeMultiplier;
				*( float* )( params + 12 ) = PitchMultiplier;
				*( float* )( params + 16 ) = FadeInTime;
				*( bool* )( params + 20 ) = bSuppressSubtitles;
				*( bool* )( params + 24 ) = bSuppressSpatialization;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Kismet_ClientStopSound( class SoundCue* ASound, class Actor* SourceActor, float FadeOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Kismet_ClientStopSound" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SoundCue** )params = ASound;
				*( class Actor** )( params + 4 ) = SourceActor;
				*( float* )( params + 8 ) = FadeOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayActorFaceFXAnim( class Actor* SourceActor, class FaceFXAnimSet* AnimSet, ScriptArray< wchar_t > GroupName, ScriptArray< wchar_t > SeqName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPlayActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Actor** )params = SourceActor;
				*( class FaceFXAnimSet** )( params + 4 ) = AnimSet;
				*( ScriptArray< wchar_t >* )( params + 8 ) = GroupName;
				*( ScriptArray< wchar_t >* )( params + 20 ) = SeqName;
				*( class SoundCue** )( params + 32 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientMessage( ScriptArray< wchar_t > S, ScriptName Type, float MsgLifeTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = S;
				*( ScriptName* )( params + 12 ) = Type;
				*( float* )( params + 20 ) = MsgLifeTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanCommunicate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanCommunicate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowTTSMessageFrom( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AllowTTSMessageFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class SoundCue* CreateTTSSoundCue( ScriptArray< wchar_t > StrToSpeak, class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CreateTTSSoundCue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = StrToSpeak;
				*( class PlayerReplicationInfo** )( params + 12 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundCue** )( params + function->return_val_offset() );
			}

			void Talk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Talk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamTalk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TeamTalk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpeakTTS( ScriptArray< wchar_t > S, class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SpeakTTS" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = S;
				*( class PlayerReplicationInfo** )( params + 12 ) = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamMessage( class PlayerReplicationInfo* PRI, ScriptArray< wchar_t > S, ScriptName Type, float MsgLifeTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TeamMessage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				*( ScriptArray< wchar_t >* )( params + 4 ) = S;
				*( ScriptName* )( params + 16 ) = Type;
				*( float* )( params + 24 ) = MsgLifeTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayBeepSound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PlayBeepSound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterOnlineDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RegisterOnlineDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPartyMemberListChanged( bool bJoinedOrLeft, ScriptArray< wchar_t > PlayerName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnPartyMemberListChanged" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( bool* )params = bJoinedOrLeft;
				*( ScriptArray< wchar_t >* )( params + 4 ) = PlayerName;
				*( void** )( params + 16 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPartyMembersInfoChanged( ScriptArray< wchar_t > PlayerName, void* PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnPartyMembersInfoChanged" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = PlayerName;
				*( void** )( params + 12 ) = PlayerID;
				*( int* )( params + 20 ) = CustomData1;
				*( int* )( params + 24 ) = CustomData2;
				*( int* )( params + 28 ) = CustomData3;
				*( int* )( params + 32 ) = CustomData4;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearOnlineDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClearOnlineDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CleanupPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CleanupPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FixFOV(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FixFOV" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredFOV, 0xFFFFFFFF )
			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetFOV(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ResetFOV" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FOV( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowTextMessage( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AllowTextMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, LastBroadcastTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LastBroadcastString, 0xFFFFFFFF )
			void Say( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Say" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientAdminMessage( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientAdminMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TeamSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerTeamSay( ScriptArray< wchar_t > msg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerTeamSay" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = msg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreClientTravel( ScriptArray< wchar_t > PendingURL, byte TravelType, bool bIsSeamlessTravel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PreClientTravel" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( ScriptArray< wchar_t >* )params = PendingURL;
				*( byte* )( params + 12 ) = TravelType;
				*( bool* )( params + 16 ) = bIsSeamlessTravel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UIInteraction* GetUIController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetUIController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UIInteraction** )( params + function->return_val_offset() );
			}

			void Camera( ScriptName NewMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Camera" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerCamera( ScriptName NewMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerCamera" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetCameraMode( ScriptName NewCamMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetCameraMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewCamMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCameraMode( ScriptName NewCamMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetCameraMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewCamMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetCameraMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ResetCameraMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetCameraFade( bool bEnableFading, void* FadeColor, void* FadeAlpha, float FadeTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetCameraFade" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( bool* )params = bEnableFading;
				*( void** )( params + 4 ) = FadeColor;
				*( void** )( params + 8 ) = FadeAlpha;
				*( float* )( params + 16 ) = FadeTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UsingFirstPersonCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UsingFirstPersonCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ForceDeathUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ForceDeathUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			void DualServerMove( float TimeStamp0, Vector InAccel0, byte PendingFlags, int View0, float TimeStamp, Vector InAccel, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DualServerMove" );
				byte *params = ( byte* )( malloc( 55 ) );
				*( float* )params = TimeStamp0;
				*( Vector* )( params + 4 ) = InAccel0;
				*( byte* )( params + 16 ) = PendingFlags;
				*( int* )( params + 20 ) = View0;
				*( float* )( params + 24 ) = TimeStamp;
				*( Vector* )( params + 28 ) = InAccel;
				*( Vector* )( params + 40 ) = ClientLoc;
				*( byte* )( params + 52 ) = NewFlags;
				*( byte* )( params + 53 ) = ClientRoll;
				*( int* )( params + 56 ) = View;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OldServerMove( float OldTimeStamp, byte OldAccelX, byte OldAccelY, byte OldAccelZ, byte OldMoveFlags )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OldServerMove" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = OldTimeStamp;
				*( byte* )( params + 4 ) = OldAccelX;
				*( byte* )( params + 5 ) = OldAccelY;
				*( byte* )( params + 6 ) = OldAccelZ;
				*( byte* )( params + 7 ) = OldMoveFlags;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, CurrentTimeStamp, 0xFFFFFFFF )
			float GetServerMoveDeltaTime( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetServerMoveDeltaTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bWasSpeedHack, 0x400 )
			ADD_VAR( ::FloatProperty, LastSpeedHackLog, 0xFFFFFFFF )
			void ServerMoveHandleClientError( float TimeStamp, Vector Accel, Vector ClientLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerMoveHandleClientError" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = TimeStamp;
				*( Vector* )( params + 4 ) = Accel;
				*( Vector* )( params + 16 ) = ClientLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerMove( float TimeStamp, Vector InAccel, Vector ClientLoc, byte MoveFlags, byte ClientRoll, int View )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerMove" );
				byte *params = ( byte* )( malloc( 34 ) );
				*( float* )params = TimeStamp;
				*( Vector* )( params + 4 ) = InAccel;
				*( Vector* )( params + 16 ) = ClientLoc;
				*( byte* )( params + 28 ) = MoveFlags;
				*( byte* )( params + 29 ) = ClientRoll;
				*( int* )( params + 32 ) = View;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, ServerTimeStamp, 0xFFFFFFFF )
			void SendClientAdjustment(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SendClientAdjustment" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerDrive( float InForward, float InStrafe, float aUp, bool InJump, int View )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerDrive" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = InForward;
				*( float* )( params + 4 ) = InStrafe;
				*( float* )( params + 8 ) = aUp;
				*( bool* )( params + 12 ) = InJump;
				*( int* )( params + 16 ) = View;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessDrive( float InForward, float InStrafe, float InUp, bool InJump )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ProcessDrive" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = InForward;
				*( float* )( params + 4 ) = InStrafe;
				*( float* )( params + 8 ) = InUp;
				*( bool* )( params + 12 ) = InJump;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessMove( float DeltaTime, Vector newAccel, byte DoubleClickMove, Rotator DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ProcessMove" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( float* )params = DeltaTime;
				*( Vector* )( params + 4 ) = newAccel;
				*( byte* )( params + 16 ) = DoubleClickMove;
				*( Rotator* )( params + 20 ) = DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveAutonomous( float DeltaTime, byte CompressedFlags, Vector newAccel, Rotator DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.MoveAutonomous" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( float* )params = DeltaTime;
				*( byte* )( params + 4 ) = CompressedFlags;
				*( Vector* )( params + 8 ) = newAccel;
				*( Rotator* )( params + 20 ) = DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, SavedMoveClass )
			ADD_VAR( ::BoolProperty, bDoubleJump, 0x4 )
			void VeryShortClientAdjustPosition( float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.VeryShortClientAdjustPosition" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = TimeStamp;
				*( float* )( params + 4 ) = NewLocX;
				*( float* )( params + 8 ) = NewLocY;
				*( float* )( params + 12 ) = NewLocZ;
				*( class Actor** )( params + 16 ) = NewBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShortClientAdjustPosition( float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ShortClientAdjustPosition" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( float* )params = TimeStamp;
				*( ScriptName* )( params + 4 ) = NewState;
				*( byte* )( params + 12 ) = newPhysics;
				*( float* )( params + 16 ) = NewLocX;
				*( float* )( params + 20 ) = NewLocY;
				*( float* )( params + 24 ) = NewLocZ;
				*( class Actor** )( params + 28 ) = NewBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientCapBandwidth( int Cap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientCapBandwidth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Cap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, ClientCap, 0xFFFFFFFF )
			void ClientAckGoodMove( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientAckGoodMove" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePing( float TimeStamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UpdatePing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = TimeStamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientAdjustPosition( float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientAdjustPosition" );
				byte *params = ( byte* )( malloc( 41 ) );
				*( float* )params = TimeStamp;
				*( ScriptName* )( params + 4 ) = NewState;
				*( byte* )( params + 12 ) = newPhysics;
				*( float* )( params + 16 ) = NewLocX;
				*( float* )( params + 20 ) = NewLocY;
				*( float* )( params + 24 ) = NewLocZ;
				*( float* )( params + 28 ) = NewVelX;
				*( float* )( params + 32 ) = NewVelY;
				*( float* )( params + 36 ) = NewVelZ;
				*( class Actor** )( params + 40 ) = NewBase;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastPingUpdate, 0xFFFFFFFF )
			void LongClientAdjustPosition( float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LongClientAdjustPosition" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( float* )params = TimeStamp;
				*( ScriptName* )( params + 4 ) = NewState;
				*( byte* )( params + 12 ) = newPhysics;
				*( float* )( params + 16 ) = NewLocX;
				*( float* )( params + 20 ) = NewLocY;
				*( float* )( params + 24 ) = NewLocZ;
				*( float* )( params + 28 ) = NewVelX;
				*( float* )( params + 32 ) = NewVelY;
				*( float* )( params + 36 ) = NewVelZ;
				*( class Actor** )( params + 40 ) = NewBase;
				*( float* )( params + 44 ) = NewFloorX;
				*( float* )( params + 48 ) = NewFloorY;
				*( float* )( params + 52 ) = NewFloorZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( SavedMove, FreeMoves )
			ADD_STRUCT( ::VectorProperty, LastAckedAccel, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUpdatePosition, 0x8 )
			void UpdateStateFromAdjustment( ScriptName NewState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UpdateStateFromAdjustment" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = NewState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerUpdatePing( int NewPing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerUpdatePing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewPing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAckedMoves(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClearAckedMoves" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUpdatePosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientUpdatePosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, bRun, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bDuck, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPressedJump, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdating, 0x10 )
			class SavedMove* GetFreeMove(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetFreeMove" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SavedMove** )( params + function->return_val_offset() );
			}

			int CompressAccel( int C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CompressAccel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ReplicateMove( float DeltaTime, Vector newAccel, byte DoubleClickMove, Rotator DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ReplicateMove" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( float* )params = DeltaTime;
				*( Vector* )( params + 4 ) = newAccel;
				*( byte* )( params + 16 ) = DoubleClickMove;
				*( Rotator* )( params + 20 ) = DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, ClientUpdateTime, 0xFFFFFFFF )
			void CallServerMove( class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CallServerMove" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( class SavedMove** )params = NewMove;
				*( Vector* )( params + 4 ) = ClientLoc;
				*( byte* )( params + 16 ) = ClientRoll;
				*( int* )( params + 20 ) = View;
				*( class SavedMove** )( params + 24 ) = OldMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleWalking(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.HandleWalking" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRestartGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerRestartGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestartLevel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RestartLevel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PauseRumbleForAllPlayers( bool bShouldPauseRumble )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PauseRumbleForAllPlayers" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShouldPauseRumble;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanUnpause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanUnpause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetPause( bool bPause )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetPause" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bPause;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPaused(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsPaused" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Pause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Pause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConditionalPause( bool bDesiredPauseState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ConditionalPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDesiredPauseState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThrowWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ThrowWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerThrowWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerThrowWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrevWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PrevWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NextWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NextWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bCinematicMode, 0x10000 )
			void StopFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.StopFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartAltFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.StartAltFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopAltFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.StopAltFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetTriggerUseList( float interactDistanceToCheck, float crosshairDist, float minDot, bool bUsuableOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetTriggerUseList" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = interactDistanceToCheck;
				*( float* )( params + 4 ) = crosshairDist;
				*( float* )( params + 8 ) = minDot;
				*( bool* )( params + 12 ) = bUsuableOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Use(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Use" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ServerUse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerUse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PerformedUseAction(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PerformedUseAction" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindVehicleToDrive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.FindVehicleToDrive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TriggerInteracted(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.TriggerInteracted" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, InteractDistance, 0xFFFFFFFF )
			void Suicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Suicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerSuicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerSuicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetName( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerChangeName( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerChangeName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SwitchTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeTeam( ScriptArray< wchar_t > TeamName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ChangeTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = TeamName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerChangeTeam( int N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerChangeTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetProgressMessage( byte MessageType, ScriptArray< wchar_t > Message, ScriptArray< wchar_t > Title, bool bIgnoreFutureNetworkMessages )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetProgressMessage" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )params = MessageType;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Title;
				*( bool* )( params + 28 ) = bIgnoreFutureNetworkMessages;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Restart( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Restart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerNotifyLoadedWorld( ScriptName WorldPackageName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerNotifyLoadedWorld" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = WorldPackageName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyLoadedWorld( ScriptName WorldPackageName, bool bFinalDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyLoadedWorld" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = WorldPackageName;
				*( bool* )( params + 8 ) = bFinalDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HasClientLoadedCurrentWorld(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.HasClientLoadedCurrentWorld" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ForceSingleNetUpdateFor( class Actor* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ForceSingleNetUpdateFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnterStartState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.EnterStartState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRestart( class Pawn* NewPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientRestart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = NewPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameHasEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GameHasEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientGameEnded( class Actor* EndGameFocus, bool bIsWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientGameEnded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = EndGameFocus;
				*( bool* )( params + 4 ) = bIsWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyChangedWeapon( class Weapon* PreviousWeapon, class Weapon* NewWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyChangedWeapon" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )params = PreviousWeapon;
				*( class Weapon** )( params + 4 ) = NewWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayerTick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PlayerTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayerMove( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PlayerMove" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AimingHelp( bool bInstantHit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AimingHelp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInstantHit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bAimingHelp, 0x1000 )
			void CameraLookAtFinished( class SeqAct_CameraLookAt* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CameraLookAtFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_CameraLookAt** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator GetAdjustedAimFor( class Weapon* W, Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetAdjustedAimFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Weapon** )params = W;
				*( Vector* )( params + 4 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			float AimHelpDot( bool bInstantHit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AimHelpDot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInstantHit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool NotifyLanded( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyLanded" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AdjustFOV( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AdjustFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsLocalPlayerController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsLocalPlayerController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetViewTarget( class Actor* NewViewTarget, void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetViewTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = NewViewTarget;
				*( void** )( params + 4 ) = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetViewTargetWithBlend( class Actor* NewViewTarget, float BlendTime, byte BlendFunc, float BlendExp, bool bLockOutgoing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetViewTargetWithBlend" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Actor** )params = NewViewTarget;
				*( float* )( params + 4 ) = BlendTime;
				*( byte* )( params + 8 ) = BlendFunc;
				*( float* )( params + 12 ) = BlendExp;
				*( bool* )( params + 16 ) = bLockOutgoing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetViewTarget( class Actor* A, void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetViewTarget" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Actor** )params = A;
				*( void** )( params + 4 ) = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bClientSimulatingViewTarget, 0x2000 )
			void ServerVerifyViewTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerVerifyViewTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnPlayerCamera(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SpawnPlayerCamera" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, CameraClass )
			void GetPlayerViewPoint( Vector &out_Location, Rotator &out_Rotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPlayerViewPoint" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = out_Location;
				*( Rotator* )( params + 12 ) = out_Rotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Location = *( Vector* )params;
				out_Rotation = *( Rotator* )( params + 12 );
			}

			void ViewShake( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ViewShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateRotation( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.UpdateRotation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
			}

			Rotator LimitViewRotation( Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LimitViewRotation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Rotator* )params = ViewRotation;
				*( float* )( params + 12 ) = ViewPitchMin;
				*( float* )( params + 16 ) = ViewPitchMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void CheckJumpOrDuck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CheckJumpOrDuck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, DoubleClickDir, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GroundPitch, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCheatFlying, 0x40 )
			bool IsSpectating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsSpectating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerSetSpectatorLocation( Vector NewLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerSetSpectatorLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastSpectatorStateSynchTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpectatorCameraSpeed, 0xFFFFFFFF )
			void ServerViewNextPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerViewNextPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerViewPrevPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerViewPrevPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewAPlayer( int Dir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ViewAPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Dir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( PlayerReplicationInfo, RealViewTarget )
			void ServerViewSelf( void* TransitionParams )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerViewSelf" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )params = TransitionParams;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsWaiting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsWaiting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MinRespawnDelay, 0xFFFFFFFF )
			bool CanRestartPlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanRestartPlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( NetConnection, PendingSwapConnection )
			void DrawHUD( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DrawHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleInput( class SeqAct_ToggleInput* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnToggleInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleInput** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientIgnoreMoveInput( bool bIgnore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientIgnoreMoveInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIgnore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientIgnoreLookInput( bool bIgnore )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientIgnoreLookInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIgnore;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ADD_VAR( ::ByteProperty, bIgnoreMoveInput, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bIgnoreLookInput, 0xFFFFFFFF )
			void OnDrawText( class SeqAct_DrawText* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnDrawText" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_DrawText** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientDrawKismetText( void* DrawTextInfo, float DisplayTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientDrawKismetText" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )params = DrawTextInfo;
				*( float* )( params + 52 ) = DisplayTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientClearKismetText( void* MessageOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientClearKismetText" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = MessageOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetCameraTarget( class SeqAct_SetCameraTarget* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnSetCameraTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetCameraTarget** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleHUD( class SeqAct_ToggleHUD* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnToggleHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleHUD** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnForceFeedback( class SeqAct_ForceFeedback* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnForceFeedback" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ForceFeedback** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopForceFeedbackWaveform( class ForceFeedbackWaveform* FFWaveform )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStopForceFeedbackWaveform" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class ForceFeedbackWaveform** )params = FFWaveform;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRumble( class AnimNotify_Rumble* TheAnimNotify )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.PlayRumble" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_Rumble** )params = TheAnimNotify;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayForceFeedbackWaveform( class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPlayForceFeedbackWaveform" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ForceFeedbackWaveform** )params = FFWaveform;
				*( class Actor** )( params + 4 ) = FFWaveformInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsForceFeedbackAllowed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsForceFeedbackAllowed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnToggleCinematicMode( class SeqAct_ToggleCinematicMode* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnToggleCinematicMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleCinematicMode** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCinematicMode( bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsButtons )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetCinematicMode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( bool* )params = bInCinematicMode;
				*( bool* )( params + 4 ) = bHidePlayer;
				*( bool* )( params + 8 ) = bAffectsHUD;
				*( bool* )( params + 12 ) = bAffectsMovement;
				*( bool* )( params + 16 ) = bAffectsTurning;
				*( bool* )( params + 20 ) = bAffectsButtons;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bCinemaDisableInputMove, 0x20000 )
			ADD_VAR( ::BoolProperty, bCinemaDisableInputLook, 0x40000 )
			void ClientSetCinematicMode( bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetCinematicMode" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bInCinematicMode;
				*( bool* )( params + 4 ) = bAffectsMovement;
				*( bool* )( params + 8 ) = bAffectsTurning;
				*( bool* )( params + 12 ) = bAffectsHUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IgnoreMoveInput( bool bNewMoveInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IgnoreMoveInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewMoveInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsMoveInputIgnored(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsMoveInputIgnored" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void IgnoreLookInput( bool bNewLookInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IgnoreLookInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewLookInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsLookInputIgnored(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsLookInputIgnored" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ResetPlayerMovementInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ResetPlayerMovementInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnConsoleCommand( class SeqAct_ConsoleCommand* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnConsoleCommand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ConsoleCommand** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientForceGarbageCollection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientForceGarbageCollection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LevelStreamingStatusChanged( class LevelStreaming* LevelObject, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LevelStreamingStatusChanged" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class LevelStreaming** )params = LevelObject;
				*( bool* )( params + 4 ) = bNewShouldBeLoaded;
				*( bool* )( params + 8 ) = bNewShouldBeVisible;
				*( bool* )( params + 12 ) = bNewShouldBlockOnLoad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUpdateLevelStreamingStatus( ScriptName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientUpdateLevelStreamingStatus" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = PackageName;
				*( bool* )( params + 8 ) = bNewShouldBeLoaded;
				*( bool* )( params + 12 ) = bNewShouldBeVisible;
				*( bool* )( params + 16 ) = bNewShouldBlockOnLoad;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerUpdateLevelVisibility( ScriptName PackageName, bool bIsVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerUpdateLevelVisibility" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = PackageName;
				*( bool* )( params + 8 ) = bIsVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPrepareMapChange( ScriptName LevelName, bool bFirst, bool bLast )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPrepareMapChange" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = LevelName;
				*( bool* )( params + 8 ) = bFirst;
				*( bool* )( params + 12 ) = bLast;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DelayedPrepareMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DelayedPrepareMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientCommitMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientCommitMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientCancelPendingMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientCancelPendingMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientFlushLevelStreaming(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientFlushLevelStreaming" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetBlockOnAsyncLoading(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetBlockOnAsyncLoading" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPlayerMuted( void* &Sender )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsPlayerMuted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = Sender;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Sender = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeamlessTravelTo( class PlayerController* NewPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SeamlessTravelTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = NewPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeamlessTravelFrom( class PlayerController* OldPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SeamlessTravelFrom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = OldPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetOnlineStatus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetOnlineStatus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerController* GetPlayerControllerFromNetId( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPlayerControllerFromNetId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			void ClientVoiceHandshakeComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientVoiceHandshakeComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bHasVoiceHandshakeCompleted, 0x8000 )
			void ClientMutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientMutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientUnmutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientUnmutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameplayMutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GameplayMutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameplayUnmutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GameplayUnmutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerMutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerMutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerUnmutePlayer( void* PlayerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerUnmutePlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PlayerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyDirectorControl( bool bNowControlling )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyDirectorControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNowControlling;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShowSubtitles( bool bValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SetShowSubtitles" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsShowingSubtitles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsShowingSubtitles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClientWasKicked(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientWasKicked" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRegisterForArbitration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientRegisterForArbitration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnArbitrationRegisterComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnArbitrationRegisterComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRegisteredForArbitration( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerRegisteredForArbitration" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteAccepted( void* &InviteResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnGameInviteAccepted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = InviteResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InviteResult = *( void** )params;
			}

			bool InviteHasEnoughSpace( class OnlineGameSettings* InviteSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.InviteHasEnoughSpace" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineGameSettings** )params = InviteSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanAllPlayersPlayOnline(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanAllPlayersPlayOnline" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearInviteDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClearInviteDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnEndForInviteComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnEndForInviteComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroyForInviteComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnDestroyForInviteComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ModifyClientURL( ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ModifyClientURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void OnInviteJoinComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnInviteJoinComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyInviteFailed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyInviteFailed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNotAllPlayersCanJoinInvite(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyNotAllPlayersCanJoinInvite" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNotEnoughSpaceInInvite(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.NotifyNotEnoughSpaceInInvite" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientArbitratedMatchEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientArbitratedMatchEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWriteOnlinePlayerScores( int LeaderboardId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientWriteOnlinePlayerScores" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = LeaderboardId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientWriteLeaderboardStats( ScriptClass* OnlineStatsWriteClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientWriteLeaderboardStats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = OnlineStatsWriteClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetHostUniqueId( void* InHostId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetHostUniqueId" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = InHostId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopNetworkedVoice(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStopNetworkedVoice" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStartNetworkedVoice(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStartNetworkedVoice" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroy( class SeqAct_Destroy* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnDestroy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Destroy** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugTextList( class Canvas* Canvas, float RenderDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DrawDebugTextList" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Canvas** )params = Canvas;
				*( float* )( params + 4 ) = RenderDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDebugText( ScriptArray< wchar_t > DebugText, class Actor* SrcActor, float Duration, Vector Offset, Vector DesiredOffset, void* TextColor, bool bSkipOverwriteCheck, bool bAbsoluteLocation, bool bKeepAttachedToActor, class Font* InFont )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.AddDebugText" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( ScriptArray< wchar_t >* )params = DebugText;
				*( class Actor** )( params + 12 ) = SrcActor;
				*( float* )( params + 16 ) = Duration;
				*( Vector* )( params + 20 ) = Offset;
				*( Vector* )( params + 32 ) = DesiredOffset;
				*( void** )( params + 44 ) = TextColor;
				*( bool* )( params + 48 ) = bSkipOverwriteCheck;
				*( bool* )( params + 52 ) = bAbsoluteLocation;
				*( bool* )( params + 56 ) = bKeepAttachedToActor;
				*( class Font** )( params + 60 ) = InFont;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveDebugText( class Actor* SrcActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RemoveDebugText" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = SrcActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveAllDebugStrings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.RemoveAllDebugStrings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientRegisterHostStatGuid( ScriptArray< wchar_t > StatGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientRegisterHostStatGuid" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = StatGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegisterHostStatGuidComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnRegisterHostStatGuidComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerRegisterClientStatGuid( ScriptArray< wchar_t > StatGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ServerRegisterClientStatGuid" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = StatGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStartOnlineGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStartOnlineGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientEndOnlineGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientEndOnlineGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanViewUserCreatedContent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.CanViewUserCreatedContent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void IncrementNumberOfMatchesPlayed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IncrementNumberOfMatchesPlayed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SoakPause( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.SoakPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientTravelToSession( ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientTravelToSession" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )params = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinTravelToSessionComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnJoinTravelToSessionComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReturnToParty( void* RequestingPlayerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientReturnToParty" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = RequestingPlayerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsSplitscreenPlayer( int &out_SplitscreenPlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsSplitscreenPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = out_SplitscreenPlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_SplitscreenPlayerIndex = *( int* )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, NetPlayerIndex, 0xFFFFFFFF )
			class PlayerReplicationInfo* GetSplitscreenPlayerByIndex( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetSplitscreenPlayerByIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			int GetSplitscreenPlayerCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetSplitscreenPlayerCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ClientControlMovieTexture( class TextureMovie* MovieTexture, byte Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientControlMovieTexture" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TextureMovie** )params = MovieTexture;
				*( byte* )( params + 4 ) = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSetForceMipLevelsToBeResident( class MaterialInterface* Material, float ForceDuration, int CinematicTextureGroups )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSetForceMipLevelsToBeResident" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class MaterialInterface** )params = Material;
				*( float* )( params + 4 ) = ForceDuration;
				*( int* )( params + 8 ) = CinematicTextureGroups;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPrestreamTextures( class Actor* ForcedActor, float ForceDuration, bool bEnableStreaming, int CinematicTextureGroups )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPrestreamTextures" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = ForcedActor;
				*( float* )( params + 4 ) = ForceDuration;
				*( bool* )( params + 8 ) = bEnableStreaming;
				*( int* )( params + 12 ) = CinematicTextureGroups;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPartyLeader(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.IsPartyLeader" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPartyMapName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPartyMapName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPartyGameTypeName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetPartyGameTypeName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool GetAchievementProgression( int AchievementId, float &CurrentValue, float &MaxValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.GetAchievementProgression" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = AchievementId;
				*( float* )( params + 4 ) = CurrentValue;
				*( float* )( params + 8 ) = MaxValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CurrentValue = *( float* )( params + 4 );
				MaxValue = *( float* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnFlyThroughHasEnded( class SeqAct_FlyThroughHasEnded* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnFlyThroughHasEnded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_FlyThroughHasEnded** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Sentinel_SetupForGamebasedTravelTheWorld(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Sentinel_SetupForGamebasedTravelTheWorld" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Sentinel_PreAcquireTravelTheWorldPoints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Sentinel_PreAcquireTravelTheWorldPoints" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Sentinel_PostAcquireTravelTheWorldPoints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.Sentinel_PostAcquireTravelTheWorldPoints" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InputMatchDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.InputMatchDelegate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoForceFeedbackForScreenShake( class CameraShake* ShakeData, float ShakeScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DoForceFeedbackForScreenShake" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class CameraShake** )params = ShakeData;
				*( float* )( params + 4 ) = ShakeScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayCameraShake( class CameraShake* Shake, float Scale, bool bTryForceFeedback, byte PlaySpace, Rotator UserPlaySpaceRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPlayCameraShake" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( class CameraShake** )params = Shake;
				*( float* )( params + 4 ) = Scale;
				*( bool* )( params + 8 ) = bTryForceFeedback;
				*( byte* )( params + 12 ) = PlaySpace;
				*( Rotator* )( params + 16 ) = UserPlaySpaceRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopCameraShake( class CameraShake* Shake )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStopCameraShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CameraShake** )params = Shake;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCameraShake( class SeqAct_CameraShake* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnCameraShake" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_CameraShake** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayCameraAnim( class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, byte Space, Rotator CustomPlaySpace )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientPlayCameraAnim" );
				byte *params = ( byte* )( malloc( 41 ) );
				*( class CameraAnim** )params = AnimToPlay;
				*( float* )( params + 4 ) = Scale;
				*( float* )( params + 8 ) = Rate;
				*( float* )( params + 12 ) = BlendInTime;
				*( float* )( params + 16 ) = BlendOutTime;
				*( bool* )( params + 20 ) = bLoop;
				*( bool* )( params + 24 ) = bRandomStartTime;
				*( byte* )( params + 28 ) = Space;
				*( Rotator* )( params + 32 ) = CustomPlaySpace;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopCameraAnim( class CameraAnim* AnimToStop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientStopCameraAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class CameraAnim** )params = AnimToStop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSpawnCameraLensEffect( ScriptClass* LensEffectEmitterClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ClientSpawnCameraLensEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = LensEffectEmitterClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetSoundMode( class SeqAct_SetSoundMode* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnSetSoundMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetSoundMode** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HasPeerConnection( void* &PeerNetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.HasPeerConnection" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = PeerNetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PeerNetId = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			void BugItGo( float X, float Y, float Z, int Pitch, int Yaw, int Roll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugItGo" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( float* )params = X;
				*( float* )( params + 4 ) = Y;
				*( float* )( params + 8 ) = Z;
				*( int* )( params + 12 ) = Pitch;
				*( int* )( params + 16 ) = Yaw;
				*( int* )( params + 20 ) = Roll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BugItGoString( ScriptArray< wchar_t > TheLocation, ScriptArray< wchar_t > TheRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugItGoString" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = TheLocation;
				*( ScriptArray< wchar_t >* )( params + 12 ) = TheRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BugItWorker( Vector TheLocation, Rotator TheRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugItWorker" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = TheLocation;
				*( Rotator* )( params + 12 ) = TheRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( CheatManager, CheatManager )
			void BugIt( ScriptArray< wchar_t > ScreenShotDescription )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugIt" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = ScreenShotDescription;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogOutBugItGoToLogFile( ScriptArray< wchar_t > InScreenShotDesc, ScriptArray< wchar_t > InGoString, ScriptArray< wchar_t > InLocString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LogOutBugItGoToLogFile" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = InScreenShotDesc;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InGoString;
				*( ScriptArray< wchar_t >* )( params + 24 ) = InLocString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogLoc(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LogLoc" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BugItAI( ScriptArray< wchar_t > ScreenShotDescription )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugItAI" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = ScreenShotDescription;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LogOutBugItAIGoToLogFile( ScriptArray< wchar_t > InScreenShotDesc, ScriptArray< wchar_t > InGoString, ScriptArray< wchar_t > InLocString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.LogOutBugItAIGoToLogFile" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = InScreenShotDesc;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InGoString;
				*( ScriptArray< wchar_t >* )( params + 24 ) = InLocString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BugItStringCreator( Vector &ViewLocation, Rotator &ViewRotation, ScriptArray< wchar_t > &GoString, ScriptArray< wchar_t > &LocString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.BugItStringCreator" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )params = ViewLocation;
				*( Rotator* )( params + 12 ) = ViewRotation;
				*( ScriptArray< wchar_t >* )( params + 24 ) = GoString;
				*( ScriptArray< wchar_t >* )( params + 36 ) = LocString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ViewLocation = *( Vector* )params;
				ViewRotation = *( Rotator* )( params + 12 );
				GoString = *( ScriptArray< wchar_t >* )( params + 24 );
				LocString = *( ScriptArray< wchar_t >* )( params + 36 );
			}

			void OnEngineInitialTick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.OnEngineInitialTick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableDebugAI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.DisableDebugAI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedGameClass( ScriptClass* GameClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerController.ReceivedGameClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = GameClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bNeverSwitchOnPickup, 0x20 )
			ADD_VAR( ::BoolProperty, bCameraPositionLocked, 0x80 )
			ADD_VAR( ::BoolProperty, bWasSaturated, 0x800 )
			ADD_VAR( ::BoolProperty, bPreventRespawn, 0x4000 )
			ADD_VAR( ::BoolProperty, bIgnoreNetworkMessages, 0x80000 )
			ADD_VAR( ::BoolProperty, bReplicateAllPawns, 0x100000 )
			ADD_VAR( ::BoolProperty, bIsUsingStreamingVolumes, 0x200000 )
			ADD_VAR( ::BoolProperty, bCheckSoundOcclusion, 0x1000000 )
			ADD_VAR( ::BoolProperty, bDebugCameraAnims, 0x2000000 )
			ADD_VAR( ::BoolProperty, bBlockCameraAnimsFromOverridingPostProcess, 0x4000000 )
			ADD_VAR( ::BoolProperty, bLogHearSoundOverflow, 0x8000000 )
			ADD_VAR( ::BoolProperty, bCheckRelevancyThroughPortals, 0x10000000 )
			ADD_VAR( ::BoolProperty, bDebugClientAdjustPosition, 0x20000000 )
			ADD_OBJECT( InterpTrackInstDirector, ControllingDirTrackInst )
			ADD_STRUCT( ::RotatorProperty, TargetViewRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetEyeHeight, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, BlendedTargetViewRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DynamicPingThreshold, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, CheatClass )
			ADD_STRUCT( ::VectorProperty, FailedPathStart, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DelayedJoinSessionName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxConcurrentHearSounds, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
