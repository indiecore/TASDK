#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty OnlineSubsystemMcts.OnlineGameInterfaceMcts." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameInterfaceMcts : public OnlineGameInterfaceImpl
	{
	public:
			void OnGameInviteAccepted( void* &InviteResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnGameInviteAccepted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = InviteResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InviteResult = *( void** )( params + 0 );
			}

			void OnRegisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnRegisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnregisterPlayerComplete( ScriptName SessionName, void* PlayerID, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.OnUnregisterPlayerComplete" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( OnlineGameSearch, InviteGameSearch )
			ADD_OBJECT( OnlineVoiceInterfaceMcts, MctsVoiceInt )
			ADD_OBJECT( MctsOnlineSettings, MctsSettings )
			void SealMatch( bool bSeal, bool bLateSeal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.SealMatch" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bSeal;
				*( bool* )( params + 4 ) = bLateSeal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HoldInvites( bool bHold )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.HoldInvites" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bHold;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndGame( int nWaitSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.EndGame" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nWaitSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MatchQueueJoin( int nQueueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueJoin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nQueueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchQueueLeave( int nQueueId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchQueueLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nQueueId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchChooseClass( int nClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchChooseSkin( int nSkinId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchChooseSkin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = nSkinId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchAcceptInvite(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchAcceptInvite" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchLockIn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLockIn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool MatchLobbyEquipItems( int eType, int nItem1, int nItem2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.MatchLobbyEquipItems" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = eType;
				*( int* )( params + 4 ) = nItem1;
				*( int* )( params + 8 ) = nItem2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UpdateOnlineGame( ScriptName SessionName, class OnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UpdateOnlineGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( class OnlineGameSettings** )( params + 8 ) = UpdatedGameSettings;
				*( bool* )( params + 12 ) = bShouldRefreshOnlineData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class OnlineGameSettings* GetGameSettings( ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.GetGameSettings" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSettings** )( params + function->return_val_offset() );
			}

			void AddGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearGameInviteAcceptedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearGameInviteAcceptedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AcceptGameInvite( byte LocalUserNum, ScriptName SessionName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AcceptGameInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptName* )( params + 4 ) = SessionName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RegisterPlayer( ScriptName SessionName, void* PlayerID, bool bWasInvited )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.RegisterPlayer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				*( bool* )( params + 16 ) = bWasInvited;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearRegisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearRegisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UnregisterPlayer( ScriptName SessionName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.UnregisterPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( void** )( params + 8 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.AddUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUnregisterPlayerCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.ClearUnregisterPlayerCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool QueryNonAdvertisedData( int StartAt, int NumberToQuery )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineGameInterfaceMcts.QueryNonAdvertisedData" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = StartAt;
				*( int* )( params + 4 ) = NumberToQuery;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
