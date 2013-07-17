#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_JoinGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_JoinGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_JoinGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_JoinGame : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( UDKDataStore_GameSearchBase, SearchDataStore )
			void OnViewLoaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewLoaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::NameProperty, SearchDSName, 0xFFFFFFFF )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
			ADD_OBJECT( UTUIDataStore_MenuItems, MenuItemDataStore )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			void OnViewActivated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewActivated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxClikWidget, FlagsHeaderBtn )
			ADD_OBJECT( GFxClikWidget, ServerHeaderBtn )
			ADD_OBJECT( GFxClikWidget, MapHeaderBtn )
			ADD_OBJECT( GFxClikWidget, PlayersHeaderBtn )
			ADD_OBJECT( GFxClikWidget, PingHeaderBtn )
			ADD_VAR( ::BoolProperty, bGametypeOutdated, 0x1 )
			ADD_VAR( ::BoolProperty, bIssuedInitialQuery, 0x4 )
			void ForceLANOption( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.ForceLANOption" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateFilterButton(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateFilterButton" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTopMostView( bool bPlayOpenAnimation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnTopMostView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPlayOpenAnimation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxClikWidget, RefreshBtn )
			void OnViewClosed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewClosed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableSubComponents( bool bDisableComponents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.DisableSubComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDisableComponents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxClikWidget, ServerListMC )
			void ValidateServerType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.ValidateServerType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Cleanup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.Cleanup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxObject, FilterMatchTypeTxt )
			ADD_OBJECT( GFxObject, FilterGameModeTxt )
			int GetGameTypeSearchProviderIndex( ScriptArray< wchar_t > GameClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.GetGameTypeSearchProviderIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = GameClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void OnGameTypeChanged( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnGameTypeChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConditionalRefreshServerList( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.ConditionalRefreshServerList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UseLANMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.UseLANMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateButtonStates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateButtonStates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PromptForServerPassword(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.PromptForServerPassword" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxUDKFrontEnd_PasswordDialog, PasswordDialog )
			ScriptArray< wchar_t > StripInvalidPasswordCharacters( ScriptArray< wchar_t > PasswordString, ScriptArray< wchar_t > InvalidChars )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.StripInvalidPasswordCharacters" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PasswordString;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InvalidChars;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void OnPasswordDialog_OK( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnPasswordDialog_OK" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, ServerPassword, 0xFFFFFFFF )
			void ProcessJoin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.ProcessJoin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateServerCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateServerCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxObject, StatusTxt )
			ADD_OBJECT( GFxObject, ServerCountTxt )
			ScriptArray< wchar_t > BuildJoinURL( ScriptArray< wchar_t > ResolvedConnectionURL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.BuildJoinURL" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ResolvedConnectionURL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bSpectate, 0x2 )
			void RefreshServerList( int InPlayerIndex, int MaxResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.RefreshServerList" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = InPlayerIndex;
				*( int* )( params + 4 ) = MaxResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SubmitServerListQuery( int PlayerIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.SubmitServerListQuery" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFindOnlineGamesCompleteDelegate( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnFindOnlineGamesCompleteDelegate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFindOnlineGamesComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnFindOnlineGamesComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, QueryCompletionAction, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bQueryDialogShowing, 0x8 )
			int GetDesiredMatchType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.GetDesiredMatchType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void OnRefreshButtonPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnRefreshButtonPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFilterButtonPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnFilterButtonPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerFilterChangedGameType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.ServerFilterChangedGameType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateListDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateListDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxObject, HeaderBarMC )
			void OnServerHeaderPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnServerHeaderPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMapHeaderPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnMapHeaderPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayersHeaderPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnPlayersHeaderPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPingHeaderPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnPingHeaderPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnServerListItemPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnServerListItemPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, SelectedIndex, 0xFFFFFFFF )
			ADD_OBJECT( GFxUDKFrontEnd_JoinDialog, JoinDialogMC )
			ADD_VAR( ::BoolProperty, bJoinDialogShowing, 0x10 )
			void SpectateServer( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.SpectateServer" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JoinServerClikListener( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.JoinServerClikListener" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JoinServer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.JoinServer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bProcessingJoin, 0x20 )
			void OnJoinGameComplete( ScriptName SessionName, bool bSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnJoinGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowJoinServer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.AllowJoinServer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CancelQuery( byte DesiredCancelAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.CancelQuery" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = DesiredCancelAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRefreshing( bool IsRefreshing )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.SetRefreshing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = IsRefreshing;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxObject, LoadingTickerMC )
			void OnCancelSearchComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.OnCancelSearchComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyGameTypeChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.NotifyGameTypeChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_JoinGame.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxClikWidget, FilterBtn )
			ADD_OBJECT( UTDataStore_GameSearchDM, SearchDMDataStore )
			ADD_VAR( ::IntProperty, LastServerAdded, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
