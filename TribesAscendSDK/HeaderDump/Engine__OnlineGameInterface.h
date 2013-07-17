#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineGameInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineGameInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineGameInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameInterface : public Interface
	{
	public:
			class OnlineGameSettings* GetGameSettings( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.GetGameSettings" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSettings** )( params + function->return_val_offset() );
			}

			bool EndOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.EndOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnregisterPlayer( ScriptName SessionName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.UnregisterPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MigrateOnlineGame( byte HostingPlayerNum, ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.MigrateOnlineGame" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = HostingPlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadPlatformSpecificSessionInfoBySessionName( ScriptName SessionName, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ReadPlatformSpecificSessionInfoBySessionName" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlatformSpecificInfo = *( byte* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool BindPlatformSpecificSessionToSearch( byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.BindPlatformSpecificSessionToSearch" );
				byte *params = ( byte* )( malloc( 6 ) );
				*( byte* )( params + 0 ) = SearchingPlayerNum;
				*( class OnlineGameSearch** )( params + 4 ) = SearchSettings;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool JoinMigratedOnlineGame( byte PlayerNum, ScriptName SessionName, void* &DesiredGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.JoinMigratedOnlineGame" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 0 ) = PlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( void** )( params + 12 ) = DesiredGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetResolvedConnectString( ScriptName SessionName, ScriptArray< wchar_t > &ConnectInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.GetResolvedConnectString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ConnectInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ConnectInfo = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterForArbitration( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.RegisterForArbitration" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AcceptGameInvite( byte LocalUserNum, ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AcceptGameInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DestroyOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.DestroyOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StartOnlineGame( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.StartOnlineGame" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool JoinOnlineGame( byte PlayerNum, ScriptName SessionName, void* &DesiredGame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.JoinOnlineGame" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 0 ) = PlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( void** )( params + 12 ) = DesiredGame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterPlayer( ScriptName SessionName, void* PlayerID, bool bWasInvited )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.RegisterPlayer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasInvited;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RecalculateSkillRating( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.RecalculateSkillRating" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CreateOnlineGame( byte HostingPlayerNum, ScriptName SessionName, class OnlineGameSettings* NewGameSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.CreateOnlineGame" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = HostingPlayerNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				*( class OnlineGameSettings** )( params + 12 ) = NewGameSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnCreateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnCreateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinMigratedOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnJoinMigratedOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMigrateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnMigrateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRecalculateSkillRatingComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnRecalculateSkillRatingComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameInviteAccepted( void* &InviteResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnGameInviteAccepted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = InviteResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InviteResult = *( void** )( params + 0 );
			}

			void OnArbitrationRegistrationComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnArbitrationRegistrationComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnEndOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnEndOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStartOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnStartOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnUnregisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnRegisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnRegisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnJoinOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnQosStatusChanged( int NumComplete, int NumTotal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnQosStatusChanged" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = NumComplete;
				*( int* )( params + 4 ) = NumTotal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCancelFindOnlineGamesComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnCancelFindOnlineGamesComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFindOnlineGamesComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnFindOnlineGamesComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroyOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnDestroyOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdateOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.OnUpdateOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCreateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddCreateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCreateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearCreateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UpdateOnlineGame( ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.UpdateOnlineGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( class OnlineGameSettings** )( params + 8 ) = UpdatedGameSettings;
				*( bool* )( params + 12 ) = bShouldRefreshOnlineData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUpdateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddUpdateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUpdateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearUpdateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDestroyOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddDestroyOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDestroyOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearDestroyOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FindOnlineGames( byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.FindOnlineGames" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = SearchingPlayerNum;
				*( class OnlineGameSearch** )( params + 4 ) = SearchSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CancelFindOnlineGames(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.CancelFindOnlineGames" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddCancelFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddCancelFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCancelFindOnlineGamesCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearCancelFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddQosStatusChangedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddQosStatusChangedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearQosStatusChangedDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearQosStatusChangedDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadPlatformSpecificSessionInfo( void* &DesiredGame, byte &PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ReadPlatformSpecificSessionInfo" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )( params + 0 ) = DesiredGame;
				*( byte* )( params + 8 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DesiredGame = *( void** )( params + 0 );
				PlatformSpecificInfo = *( byte* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			class OnlineGameSearch* GetGameSearch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.GetGameSearch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSearch** )( params + function->return_val_offset() );
			}

			bool FreeSearchResults( class OnlineGameSearch* Search )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.FreeSearchResults" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class OnlineGameSearch** )( params + 0 ) = Search;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool QueryNonAdvertisedData( int StartAt, int NumberToQuery )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.QueryNonAdvertisedData" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = StartAt;
				*( int* )( params + 4 ) = NumberToQuery;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddJoinOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddJoinOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearJoinOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddStartOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddStartOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearStartOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearStartOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddEndOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddEndOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearEndOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearEndOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddArbitrationRegistrationCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddArbitrationRegistrationCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearArbitrationRegistrationCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearArbitrationRegistrationCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetArbitratedPlayers( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.GetArbitratedPlayers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void AddGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddRecalculateSkillRatingCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddRecalculateSkillRatingCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRecalculateSkillRatingCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearRecalculateSkillRatingCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMigrateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddMigrateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMigrateOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearMigrateOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddJoinMigratedOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.AddJoinMigratedOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinMigratedOnlineGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameInterface.ClearJoinMigratedOnlineGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
