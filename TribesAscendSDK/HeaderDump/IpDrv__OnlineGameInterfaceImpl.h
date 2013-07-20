#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " IpDrv.OnlineGameInterfaceImpl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty IpDrv.OnlineGameInterfaceImpl." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty IpDrv.OnlineGameInterfaceImpl." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameInterfaceImpl : public Object
	{
	public:
			void OnCreateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnCreateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnUpdateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroyOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnDestroyOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnJoinOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMigrateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnMigrateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinMigratedOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnJoinMigratedOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRecalculateSkillRatingComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnRecalculateSkillRatingComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStartOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnStartOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnEndOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnEndOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFindOnlineGamesComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnFindOnlineGamesComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCancelFindOnlineGamesComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnCancelFindOnlineGamesComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnQosStatusChanged( int NumComplete, int NumTotal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnQosStatusChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = NumComplete;
				*( int* )( params + 4 ) = NumTotal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteAccepted( void* &InviteResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnGameInviteAccepted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )params = InviteResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InviteResult = *( void** )params;
			}

			void OnArbitrationRegistrationComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnArbitrationRegistrationComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnUnregisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.OnRegisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

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
			class OnlineGameSettings* GetGameSettings( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.GetGameSettings" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSettings** )( params + function->return_val_offset() );
			}

			class OnlineGameSearch* GetGameSearch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.GetGameSearch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSearch** )( params + function->return_val_offset() );
			}

			bool CreateOnlineGame( byte HostingPlayerNum, ScriptName SessionName, class OnlineGameSettings* NewGameSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.CreateOnlineGame" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = HostingPlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( class OnlineGameSettings** )( params + 12 ) = NewGameSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddCreateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddCreateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCreateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearCreateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UpdateOnlineGame( ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.UpdateOnlineGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = SessionName;
				*( class OnlineGameSettings** )( params + 8 ) = UpdatedGameSettings;
				*( bool* )( params + 12 ) = bShouldRefreshOnlineData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUpdateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddUpdateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUpdateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearUpdateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DestroyOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.DestroyOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddDestroyOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddDestroyOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDestroyOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearDestroyOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FindOnlineGames( byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.FindOnlineGames" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = SearchingPlayerNum;
				*( class OnlineGameSearch** )( params + 4 ) = SearchSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CancelFindOnlineGames(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.CancelFindOnlineGames" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddCancelFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddCancelFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCancelFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearCancelFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FreeSearchResults( class OnlineGameSearch* Search )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.FreeSearchResults" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineGameSearch** )params = Search;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool JoinOnlineGame( byte PlayerNum, ScriptName SessionName, void* &DesiredGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.JoinOnlineGame" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )params = PlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( void** )( params + 12 ) = DesiredGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddJoinOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddJoinOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearJoinOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetResolvedConnectString( ScriptName SessionName, ScriptArray< wchar_t > &ConnectInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.GetResolvedConnectString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ConnectInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ConnectInfo = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterPlayer( ScriptName SessionName, void* PlayerID, bool bWasInvited )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.RegisterPlayer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasInvited;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UnregisterPlayer( ScriptName SessionName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.UnregisterPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )params = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StartOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.StartOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddStartOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddStartOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearStartOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearStartOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool EndOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.EndOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddEndOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddEndOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearEndOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearEndOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RegisterForArbitration( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.RegisterForArbitration" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddArbitrationRegistrationCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddArbitrationRegistrationCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearArbitrationRegistrationCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearArbitrationRegistrationCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetArbitratedPlayers( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.GetArbitratedPlayers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void AddGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AcceptGameInvite( byte LocalUserNum, ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AcceptGameInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RecalculateSkillRating( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.RecalculateSkillRating" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddRecalculateSkillRatingCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddRecalculateSkillRatingCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRecalculateSkillRatingCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearRecalculateSkillRatingCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MigrateOnlineGame( byte HostingPlayerNum, ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.MigrateOnlineGame" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = HostingPlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddMigrateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddMigrateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMigrateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearMigrateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool JoinMigratedOnlineGame( byte PlayerNum, ScriptName SessionName, void* &DesiredGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.JoinMigratedOnlineGame" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )params = PlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( void** )( params + 12 ) = DesiredGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddJoinMigratedOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddJoinMigratedOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinMigratedOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearJoinMigratedOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool QueryNonAdvertisedData( int StartAt, int NumberToQuery )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.QueryNonAdvertisedData" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StartAt;
				*( int* )( params + 4 ) = NumberToQuery;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadPlatformSpecificSessionInfo( void* &DesiredGame, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfo" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )params = DesiredGame;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )params;
				PlatformSpecificInfo = *( byte* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadPlatformSpecificSessionInfoBySessionName( ScriptName SessionName, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfoBySessionName" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )params = SessionName;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BindPlatformSpecificSessionToSearch( byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.BindPlatformSpecificSessionToSearch" );
				byte *params = ( byte* )( malloc( 6 ) );
				*( byte* )params = SearchingPlayerNum;
				*( class OnlineGameSearch** )( params + 4 ) = SearchSettings;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddQosStatusChangedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.AddQosStatusChangedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearQosStatusChangedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function IpDrv.OnlineGameInterfaceImpl.ClearQosStatusChangedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
