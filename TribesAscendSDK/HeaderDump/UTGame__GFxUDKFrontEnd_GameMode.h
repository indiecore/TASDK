#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_GameMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_GameMode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_GameMode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( GFxClikWidget, ImgScrollerMC )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_VAR( ::StrProperty, MapName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameMode, 0xFFFFFFFF )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
			ADD_OBJECT( UIDataStore_OnlineGameSettings, SettingsDataStore )
			void OnViewLoaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnViewLoaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTopMostView( bool bPlayOpenAnimation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnTopMostView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPlayOpenAnimation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableSubComponents( bool bDisableComponents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.DisableSubComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDisableComponents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameModeSelected( ScriptArray< wchar_t > InGameMode, ScriptArray< wchar_t > InDefaultMap, ScriptArray< wchar_t > InGameSettingsClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeSelected" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = InGameMode;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InDefaultMap;
				*( ScriptArray< wchar_t >* )( params + 24 ) = InGameSettingsClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGameModeChange( int SelectedIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SelectedIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnListItemPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnListItemPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnListChange( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.OnListChange" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDescription(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.UpdateDescription" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateListDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.UpdateListDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetImgScroller( class GFxClikWidget* InImgScroller )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.SetImgScroller" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxClikWidget** )params = InImgScroller;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASSetList( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.ASSetList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_GameMode.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
