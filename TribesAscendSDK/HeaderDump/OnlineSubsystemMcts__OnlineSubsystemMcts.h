#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " OnlineSubsystemMcts.OnlineSubsystemMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty OnlineSubsystemMcts.OnlineSubsystemMcts." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSubsystemMcts : public OnlineSubsystemCommonImpl
	{
	public:
			void OnConnectionStatusChange( byte ConnectionStatus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnConnectionStatusChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = ConnectionStatus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginFailed( byte LocalUserNum, byte ErrorCode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginFailed" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ErrorCode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLogoutCompleted( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLogoutCompleted" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLinkStatusChange( bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLinkStatusChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnChatMessage( int Channel, ScriptArray< wchar_t > Sender, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnChatMessage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )( params + 0 ) = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Sender;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnKeyboardInputComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnKeyboardInputComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadAchievementsComplete( int TitleId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadAchievementsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TitleId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnlockAchievementComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnUnlockAchievementComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendMessageReceived( byte LocalUserNum, void* SendingPlayer, ScriptArray< wchar_t > SendingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendMessageReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = SendingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = SendingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnJoinFriendGameComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnJoinFriendGameComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReceivedGameInvite( byte LocalUserNum, ScriptArray< wchar_t > InviterName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReceivedGameInvite" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = InviterName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendInviteReceived" );
				byte *params = ( byte* )( malloc( 33 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				*( ScriptArray< wchar_t >* )( params + 12 ) = RequestingNick;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAddFriendByNameComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnAddFriendByNameComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadFriendsComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadFriendsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendsChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnFriendsChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWritePlayerStorageComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWritePlayerStorageComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlayerStorageForNetIdComplete( void* NetId, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageForNetIdComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = NetId;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlayerStorageComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadPlayerStorageComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWriteProfileSettingsComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnWriteProfileSettingsComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadProfileSettingsComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnReadProfileSettingsComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMutingChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnMutingChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginCancelled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginCancelled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginStatusChange( byte NewStatus, void* NewId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnLoginStatusChange" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = NewStatus;
				*( void** )( params + 4 ) = NewId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStorageDeviceChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnStorageDeviceChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnControllerChange( int ControllerId, bool bIsConnected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnControllerChange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( bool* )( params + 4 ) = bIsConnected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnExternalUIChange( bool bIsOpening )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.OnExternalUIChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsOpening;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, ConnectionPresenceElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConnectionPresenceTimeInterval, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldUseMcp, 0x4 )
			ADD_VAR( ::BoolProperty, bLastHasConnection, 0x2 )
			ADD_VAR( ::BoolProperty, bNeedsKeyboardTicking, 0x1 )
			ADD_VAR( ::StrProperty, KeyboardResultsString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProfileDataExtension, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ProfileDataDirectory, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentNotificationPosition, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bWasKeyboardInputCanceled, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LoggedInStatus, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LoggedInPlayerNum, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LoggedInPlayerName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, LocalProfileName, 0xFFFFFFFF )
			ADD_OBJECT( OnlineVoiceInterfaceMcts, MctsVoiceInt )
			ADD_OBJECT( OnlineGameInterfaceMcts, MctsGameInt )
			bool Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Login( byte LocalUserNum, ScriptArray< wchar_t > LoginName, ScriptArray< wchar_t > Password, bool bWantsLocalOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.Login" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = LoginName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Password;
				*( bool* )( params + 28 ) = bWantsLocalOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RequestNewPlayer( byte LocalUserNum, ScriptArray< wchar_t > LoginName, ScriptArray< wchar_t > Password, ScriptArray< wchar_t > DesiredPlayerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.RequestNewPlayer" );
				byte *params = ( byte* )( malloc( 37 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = LoginName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Password;
				*( ScriptArray< wchar_t >* )( params + 28 ) = DesiredPlayerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AutoLogin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AutoLogin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLoginFailedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginFailedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginFailedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginFailedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Logout( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.Logout" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLogoutCompletedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLogoutCompletedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLogoutCompletedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLogoutCompletedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetLoginStatus( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLoginStatus" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsGuestLogin( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsGuestLogin" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLocalLogin( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsLocalLogin" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetUniquePlayerId( byte LocalUserNum, void* &PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetUniquePlayerId" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlayerID = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPlayerNickname( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNickname" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			byte CanPlayOnline( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPlayOnline" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanDownloadUserContent( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanDownloadUserContent" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanPurchaseContent( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanPurchaseContent" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanViewPlayerProfiles( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanViewPlayerProfiles" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanShowPresenceInformation( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanShowPresenceInformation" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsFriend( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsFriend" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AreAnyFriends( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AreAnyFriends" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPlayerMctsName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerMctsName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void AddLoginChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NeedEULA(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.NeedEULA" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPlayerNicknameFromIndex( int UserIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerNicknameFromIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = UserIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetPlayerUniqueNetIdFromIndex( int UserIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerUniqueNetIdFromIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = UserIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool HasLinkConnection(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.HasLinkConnection" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLinkStatusChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLinkStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLinkStatusChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLinkStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddExternalUIChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddExternalUIChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearExternalUIChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearExternalUIChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetNetworkNotificationPosition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNetworkNotificationPosition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void AddControllerChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddControllerChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearControllerChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearControllerChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsControllerConnected( int ControllerId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsControllerConnected" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ControllerId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddConnectionStatusChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddConnectionStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearConnectionStatusChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearConnectionStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetNATType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetNATType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void AddStorageDeviceChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddStorageDeviceChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearStorageDeviceChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearStorageDeviceChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddChatMessageDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddChatMessageDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearChatMessageDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearChatMessageDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendChatMessage( int Channel, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendChatMessage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = Channel;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendPrivateChatMessage( ScriptArray< wchar_t > PlayerName, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendPrivateChatMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PlayerName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WriteActiveCharacterClass( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteActiveCharacterClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReadCharacterClasses(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadCharacterClasses" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int ReadActiveCharacterClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadActiveCharacterClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool WritePlayerProfileData( void* UniqueId, class TgPlayerProfile* Profile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerProfileData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = UniqueId;
				*( class TgPlayerProfile** )( params + 8 ) = Profile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadPlayerProfileData( void* UniqueId, class TgPlayerProfile* Profile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerProfileData" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = UniqueId;
				*( class TgPlayerProfile** )( params + 8 ) = Profile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyTeamChange( void* PlayerUid, byte TeamID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.NotifyTeamChange" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( void** )( params + 0 ) = PlayerUid;
				*( byte* )( params + 8 ) = TeamID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCharacterIdFromClassId( void* UniqueId, int nClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetCharacterIdFromClassId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = UniqueId;
				*( int* )( params + 8 ) = nClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsMuted( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.IsMuted" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte CanCommunicate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.CanCommunicate" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void AddLoginStatusChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginStatusChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddLoginCancelledDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddLoginCancelledDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginCancelledDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearLoginCancelledDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadProfileSettings( byte LocalUserNum, class OnlineProfileSettings* ProfileSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadProfileSettings" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlineProfileSettings** )( params + 4 ) = ProfileSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WriteProfileSettings( byte LocalUserNum, class OnlineProfileSettings* ProfileSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.WriteProfileSettings" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlineProfileSettings** )( params + 4 ) = ProfileSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class OnlineProfileSettings* GetProfileSettings( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetProfileSettings" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineProfileSettings** )( params + function->return_val_offset() );
			}

			void AddMutingChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddMutingChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMutingChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearMutingChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddWriteProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWriteProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWriteProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWriteProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadPlayerStorage( byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorage" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlinePlayerStorage** )( params + 4 ) = PlayerStorage;
				*( int* )( params + 8 ) = DeviceID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadPlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadPlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadPlayerStorageForNetId( byte LocalUserNum, void* NetId, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadPlayerStorageForNetId" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = NetId;
				*( class OnlinePlayerStorage** )( params + 12 ) = PlayerStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadPlayerStorageForNetIdCompleteDelegate( void* NetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadPlayerStorageForNetIdCompleteDelegate" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = NetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadPlayerStorageForNetIdCompleteDelegate( void* NetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadPlayerStorageForNetIdCompleteDelegate" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = NetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlinePlayerStorage* GetPlayerStorage( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetPlayerStorage" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlinePlayerStorage** )( params + function->return_val_offset() );
			}

			bool WritePlayerStorage( byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.WritePlayerStorage" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlinePlayerStorage** )( params + 4 ) = PlayerStorage;
				*( int* )( params + 8 ) = DeviceID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddWritePlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddWritePlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWritePlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearWritePlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFriendsChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendsChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendsChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendsChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadFriendsList( byte LocalUserNum, int Count, int StartingAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadFriendsList" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = Count;
				*( int* )( params + 8 ) = StartingAt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadFriendsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadFriendsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadFriendsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadFriendsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetFriendsList( byte LocalUserNum, int Count, int StartingAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendsList" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 16 ) = Count;
				*( int* )( params + 20 ) = StartingAt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void SetOnlineStatus( byte LocalUserNum, int StatusId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetOnlineStatus" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = StatusId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowKeyboardUI( byte LocalUserNum, ScriptArray< wchar_t > TitleText, ScriptArray< wchar_t > DescriptionText, bool bIsPassword, bool bShouldValidate, ScriptArray< wchar_t > DefaultText, int MaxResultLength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowKeyboardUI" );
				byte *params = ( byte* )( malloc( 49 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = TitleText;
				*( ScriptArray< wchar_t >* )( params + 16 ) = DescriptionText;
				*( bool* )( params + 28 ) = bIsPassword;
				*( bool* )( params + 32 ) = bShouldValidate;
				*( ScriptArray< wchar_t >* )( params + 36 ) = DefaultText;
				*( int* )( params + 48 ) = MaxResultLength;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddKeyboardInputDoneDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddKeyboardInputDoneDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearKeyboardInputDoneDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearKeyboardInputDoneDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetKeyboardInputResults( byte &bWasCanceled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetKeyboardInputResults" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = bWasCanceled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				bWasCanceled = *( byte* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool AddFriend( byte LocalUserNum, void* NewFriend, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriend" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = NewFriend;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AddFriendByName( byte LocalUserNum, ScriptArray< wchar_t > FriendName, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendByName" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = FriendName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddAddFriendByNameCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddAddFriendByNameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAddFriendByNameCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearAddFriendByNameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AcceptFriendInvite( byte LocalUserNum, void* RequestingPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AcceptFriendInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DenyFriendInvite( byte LocalUserNum, void* RequestingPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.DenyFriendInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveFriend( byte LocalUserNum, void* FormerFriend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.RemoveFriend" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = FormerFriend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddFriendInviteReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendInviteReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendInviteReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendInviteReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SendMessageToFriend( byte LocalUserNum, void* Friend, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendMessageToFriend" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = Friend;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SendGameInviteToFriend( byte LocalUserNum, void* Friend, ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriend" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = Friend;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SendGameInviteToFriends( byte LocalUserNum, ScriptArray< wchar_t > Text )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SendGameInviteToFriends" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReceivedGameInviteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReceivedGameInviteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReceivedGameInviteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReceivedGameInviteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool JoinFriendGame( byte LocalUserNum, void* Friend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.JoinFriendGame" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = Friend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddJoinFriendGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddJoinFriendGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinFriendGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearJoinFriendGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetFriendMessages( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetFriendMessages" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFriendMessageReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddFriendMessageReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendMessageReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearFriendMessageReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool UnlockAchievement( byte LocalUserNum, int AchievementId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.UnlockAchievement" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = AchievementId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadAchievements( byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ReadAchievements" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = TitleId;
				*( bool* )( params + 8 ) = bShouldReadText;
				*( bool* )( params + 12 ) = bShouldReadImages;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte GetAchievements( byte LocalUserNum, int TitleId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetAchievements" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 16 ) = TitleId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void AddUnlockAchievementCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddUnlockAchievementCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUnlockAchievementCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearUnlockAchievementCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadAchievementsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.AddReadAchievementsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadAchievementsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ClearReadAchievementsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DeleteMessage( byte LocalUserNum, int MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.DeleteMessage" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowFriendsUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowFriendsUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowLoginUI( bool bShowOnlineOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.ShowLoginUI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bShowOnlineOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetNetworkNotificationPosition( byte NewPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.SetNetworkNotificationPosition" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = NewPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLocale(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function OnlineSubsystemMcts.OnlineSubsystemMcts.GetLocale" );
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
