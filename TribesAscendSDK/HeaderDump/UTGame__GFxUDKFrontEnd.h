#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd : public GFxMoviePlayer
	{
	public:
			void EscapeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.EscapeDelegate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxUDKFrontEnd_PasswordDialog, PasswordDialog )
			ADD_OBJECT( GFxUDKFrontEnd_ErrorDialog, ErrorDialog )
			ADD_OBJECT( GFxUDKFrontEnd_JoinDialog, JoinDialog )
			ADD_OBJECT( GFxUDKFrontEnd_FilterDialog, FilterDialog )
			ADD_OBJECT( GFxUDKFrontEnd_InfoDialog, InfoDialog )
			ADD_OBJECT( GFxUDKFrontEnd_JoinGame, JoinGameView )
			ADD_OBJECT( GFxUDKFrontEnd_ServerSettings, ServerSettingsView )
			ADD_OBJECT( GFxUDKFrontEnd_Settings, SettingsView )
			ADD_OBJECT( GFxUDKFrontEnd_Mutators, MutatorsView )
			ADD_OBJECT( GFxUDKFrontEnd_GameMode, GameModeView )
			ADD_OBJECT( GFxUDKFrontEnd_MapSelect, MapSelectView )
			ADD_OBJECT( GFxUDKFrontEnd_HostGame, HostGameView )
			ADD_OBJECT( GFxUDKFrontEnd_Multiplayer, MultiplayerView )
			ADD_OBJECT( GFxUDKFrontEnd_InstantAction, InstantActionView )
			ADD_OBJECT( GFxUDKFrontEnd_MainMenu, MainMenuView )
			ADD_VAR( ::BoolProperty, bInitialized, 0x1 )
			ADD_OBJECT( GFxObject, ManagerMC )
			ADD_OBJECT( GFxObject, RootMC )
			bool Start( bool StartPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.Start" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = StartPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConfigFrontEnd(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ConfigFrontEnd" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASShowCursor( bool bShowCursor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ASShowCursor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bShowCursor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadViews(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.LoadViews" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadView( void* InViewInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.LoadView" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )params = InViewInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadViewByName( ScriptName InViewName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.LoadViewByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InViewName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsViewLoaded( ScriptName InViewName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.IsViewLoaded" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InViewName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetEscapeDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.SetEscapeDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PushViewByName( ScriptName TargetViewName, class GFxUDKFrontEnd_Screen* ParentView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PushViewByName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TargetViewName;
				*( class GFxUDKFrontEnd_Screen** )( params + 8 ) = ParentView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxUDKFrontEnd_Dialog* SpawnDialog( ScriptName TargetDialogName, class GFxUDKFrontEnd_Screen* ParentView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.SpawnDialog" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = TargetDialogName;
				*( class GFxUDKFrontEnd_Screen** )( params + 8 ) = ParentView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxUDKFrontEnd_Dialog** )( params + function->return_val_offset() );
			}

			void ConfigureTargetDialog( class GFxUDKFrontEnd_View* TargetDialog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ConfigureTargetDialog" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxUDKFrontEnd_View** )params = TargetDialog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConfigureTargetView( class GFxUDKFrontEnd_View* TargetView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ConfigureTargetView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxUDKFrontEnd_View** )params = TargetView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsViewAllowed( class GFxUDKFrontEnd_View* TargetView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.IsViewAllowed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxUDKFrontEnd_View** )params = TargetView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PushView( class GFxUDKFrontEnd_View* TargetView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PushView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxUDKFrontEnd_View** )params = TargetView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PushDialogView( class GFxUDKFrontEnd_View* dialogView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PushDialogView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxUDKFrontEnd_View** )params = dialogView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSelectionFocus( class GFxObject* MovieClip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.SetSelectionFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = MovieClip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASSetSelectionFocus( class GFxObject* MovieClip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ASSetSelectionFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = MovieClip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GFxObject* PopView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PopView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			class GFxObject* PopViewStub(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PopViewStub" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			void UpdateViewLayout(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.UpdateViewLayout" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConfigureView( class GFxUDKFrontEnd_View* InView, ScriptName WidgetName, ScriptName WidgetPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.ConfigureView" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class GFxUDKFrontEnd_View** )params = InView;
				*( ScriptName* )( params + 4 ) = WidgetName;
				*( ScriptName* )( params + 12 ) = WidgetPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostWidgetInit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.PostWidgetInit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckLinkConnectionAndError( ScriptArray< wchar_t > AlternateTitle, ScriptArray< wchar_t > AlternateMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.CheckLinkConnectionAndError" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = AlternateTitle;
				*( ScriptArray< wchar_t >* )( params + 12 ) = AlternateMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void LoadDependantViews( ScriptName InViewName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.LoadDependantViews" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InViewName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyDependantViews( ScriptName InViewName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd.DestroyDependantViews" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InViewName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
