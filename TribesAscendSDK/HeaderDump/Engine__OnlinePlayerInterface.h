#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlinePlayerInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlinePlayerInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlinePlayerInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlayerInterface : public Interface
	{
	public:
			bool GetUniquePlayerId( byte LocalUserNum, void* &PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetUniquePlayerId" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PlayerID = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte GetLoginStatus( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetLoginStatus" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetPlayerNickname( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetPlayerNickname" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			byte CanPlayOnline( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanPlayOnline" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanDownloadUserContent( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanDownloadUserContent" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool AutoLogin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AutoLogin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadAchievementsComplete( int TitleId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReadAchievementsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TitleId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUnlockAchievementComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnUnlockAchievementComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendMessageReceived( byte LocalUserNum, void* SendingPlayer, ScriptArray< wchar_t > SendingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnFriendMessageReceived" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnJoinFriendGameComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReceivedGameInvite( byte LocalUserNum, ScriptArray< wchar_t > InviterName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReceivedGameInvite" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = InviterName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendInviteReceived( byte LocalUserNum, void* RequestingPlayer, ScriptArray< wchar_t > RequestingNick, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnFriendInviteReceived" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnAddFriendByNameComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnKeyboardInputComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnKeyboardInputComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadFriendsComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReadFriendsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWritePlayerStorageComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnWritePlayerStorageComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlayerStorageForNetIdComplete( void* NetId, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReadPlayerStorageForNetIdComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( void** )( params + 0 ) = NetId;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadPlayerStorageComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReadPlayerStorageComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWriteProfileSettingsComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnWriteProfileSettingsComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadProfileSettingsComplete( byte LocalUserNum, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnReadProfileSettingsComplete" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginStatusChange( byte NewStatus, void* NewId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnLoginStatusChange" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = NewStatus;
				*( void** )( params + 4 ) = NewId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLogoutCompleted( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnLogoutCompleted" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginFailed( byte LocalUserNum, byte ErrorCode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnLoginFailed" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ErrorCode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFriendsChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnFriendsChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMutingChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnMutingChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginCancelled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.OnLoginCancelled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowLoginUI( bool bShowOnlineOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ShowLoginUI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bShowOnlineOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Login( byte LocalUserNum, ScriptArray< wchar_t > LoginName, ScriptArray< wchar_t > Password, bool bWantsLocalOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.Login" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = LoginName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Password;
				*( bool* )( params + 28 ) = bWantsLocalOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLoginFailedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddLoginFailedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginFailedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearLoginFailedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Logout( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.Logout" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLogoutCompletedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddLogoutCompletedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLogoutCompletedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearLogoutCompletedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsGuestLogin( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.IsGuestLogin" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLocalLogin( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.IsLocalLogin" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte CanCommunicate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanCommunicate" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanPurchaseContent( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanPurchaseContent" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanViewPlayerProfiles( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanViewPlayerProfiles" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte CanShowPresenceInformation( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.CanShowPresenceInformation" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsFriend( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.IsFriend" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AreAnyFriends( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AreAnyFriends" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsMuted( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.IsMuted" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowFriendsUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ShowFriendsUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddLoginChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddLoginChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearLoginChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddLoginStatusChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddLoginStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginStatusChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearLoginStatusChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddLoginCancelledDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddLoginCancelledDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLoginCancelledDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearLoginCancelledDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMutingChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddMutingChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearMutingChangeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearMutingChangeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFriendsChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddFriendsChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendsChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearFriendsChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadProfileSettings( byte LocalUserNum, class OnlineProfileSettings* ProfileSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ReadProfileSettings" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlineProfileSettings** )( params + 4 ) = ProfileSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReadProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReadProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlineProfileSettings* GetProfileSettings( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetProfileSettings" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineProfileSettings** )( params + function->return_val_offset() );
			}

			bool WriteProfileSettings( byte LocalUserNum, class OnlineProfileSettings* ProfileSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.WriteProfileSettings" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( class OnlineProfileSettings** )( params + 4 ) = ProfileSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddWriteProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddWriteProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWriteProfileSettingsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearWriteProfileSettingsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadPlayerStorage( byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ReadPlayerStorage" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReadPlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadPlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReadPlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadPlayerStorageForNetId( byte LocalUserNum, void* NetId, class OnlinePlayerStorage* PlayerStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ReadPlayerStorageForNetId" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReadPlayerStorageForNetIdCompleteDelegate" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = NetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadPlayerStorageForNetIdCompleteDelegate( void* NetId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReadPlayerStorageForNetIdCompleteDelegate" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( void** )( params + 0 ) = NetId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlinePlayerStorage* GetPlayerStorage( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetPlayerStorage" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlinePlayerStorage** )( params + function->return_val_offset() );
			}

			bool WritePlayerStorage( byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage, int DeviceID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.WritePlayerStorage" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddWritePlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWritePlayerStorageCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearWritePlayerStorageCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadFriendsList( byte LocalUserNum, int Count, int StartingAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ReadFriendsList" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReadFriendsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadFriendsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReadFriendsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetFriendsList( byte LocalUserNum, int Count, int StartingAt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetFriendsList" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.SetOnlineStatus" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = StatusId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowKeyboardUI( byte LocalUserNum, ScriptArray< wchar_t > TitleText, ScriptArray< wchar_t > DescriptionText, bool bIsPassword, bool bShouldValidate, ScriptArray< wchar_t > DefaultText, int MaxResultLength )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ShowKeyboardUI" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddKeyboardInputDoneDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearKeyboardInputDoneDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearKeyboardInputDoneDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetKeyboardInputResults( byte &bWasCanceled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetKeyboardInputResults" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = bWasCanceled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				bWasCanceled = *( byte* )( params + 0 );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool AddFriend( byte LocalUserNum, void* NewFriend, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddFriend" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddFriendByName" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddAddFriendByNameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAddFriendByNameCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearAddFriendByNameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AcceptFriendInvite( byte LocalUserNum, void* RequestingPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AcceptFriendInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DenyFriendInvite( byte LocalUserNum, void* RequestingPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.DenyFriendInvite" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = RequestingPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveFriend( byte LocalUserNum, void* FormerFriend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.RemoveFriend" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = FormerFriend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddFriendInviteReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddFriendInviteReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendInviteReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearFriendInviteReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SendMessageToFriend( byte LocalUserNum, void* Friend, ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.SendMessageToFriend" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.SendGameInviteToFriend" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.SendGameInviteToFriends" );
				byte *params = ( byte* )( malloc( 25 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Text;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReceivedGameInviteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReceivedGameInviteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReceivedGameInviteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReceivedGameInviteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool JoinFriendGame( byte LocalUserNum, void* Friend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.JoinFriendGame" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( void** )( params + 4 ) = Friend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddJoinFriendGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddJoinFriendGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJoinFriendGameCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearJoinFriendGameCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetFriendMessages( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetFriendMessages" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFriendMessageReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddFriendMessageReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFriendMessageReceivedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearFriendMessageReceivedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DeleteMessage( byte LocalUserNum, int MessageIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.DeleteMessage" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = MessageIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnlockAchievement( byte LocalUserNum, int AchievementId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.UnlockAchievement" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = AchievementId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUnlockAchievementCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddUnlockAchievementCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUnlockAchievementCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearUnlockAchievementCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadAchievements( byte LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ReadAchievements" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = TitleId;
				*( bool* )( params + 8 ) = bShouldReadText;
				*( bool* )( params + 12 ) = bShouldReadImages;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadAchievementsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.AddReadAchievementsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadAchievementsCompleteDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.ClearReadAchievementsCompleteDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetAchievements( byte LocalUserNum, int TitleId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterface.GetAchievements" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 16 ) = TitleId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
