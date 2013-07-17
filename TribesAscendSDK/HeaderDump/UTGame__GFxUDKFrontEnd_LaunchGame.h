#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_LaunchGame : public GFxUDKFrontEnd_Screen
	{
	public:
			ScriptArray< wchar_t > GetGameModeFriendlyString( ScriptArray< wchar_t > InGameMode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.GetGameModeFriendlyString" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = InGameMode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( GFxObject, MutatorsLabelTxt )
			ADD_OBJECT( GFxObject, RespawnLabelTxt )
			ADD_OBJECT( GFxObject, TimeLabelTxt )
			ADD_OBJECT( GFxObject, ScoreLabelTxt )
			ADD_OBJECT( GFxObject, OpponentsLabelTxt )
			ADD_OBJECT( GFxObject, BotLvlLabelTxt )
			ADD_OBJECT( GFxObject, MapLabelTxt )
			ADD_OBJECT( GFxObject, MutatorsTxt )
			ADD_OBJECT( GFxObject, RespawnTxt )
			ADD_OBJECT( GFxObject, MapTxt )
			ADD_OBJECT( GFxObject, TimeTxt )
			ADD_OBJECT( GFxObject, ScoreTxt )
			ADD_OBJECT( GFxObject, OpponentsTxt )
			ADD_OBJECT( GFxObject, BotLvlTxt )
			ADD_OBJECT( GFxObject, GameTitleTxt )
			ADD_OBJECT( GFxObject, MapNameTxt )
			ADD_OBJECT( GFxObject, MapImageMC )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_VAR( ::StrProperty, DefaultGameModePrefixes, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultMapImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameModeSettings, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameMode, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultMapName, 0xFFFFFFFF )
			ADD_OBJECT( UTUIDataStore_MenuItems, MenuDataStore )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
			ADD_OBJECT( UIDataStore_OnlineGameSettings, SettingsDataStore )
			void OnViewLoaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnViewLoaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnViewActivated(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnViewActivated" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableSubComponents( bool bDisableComponents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.DisableSubComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDisableComponents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTopMostView( bool bPlayOpenAnimation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnTopMostView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPlayOpenAnimation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameSettingsPanel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateGameSettingsPanel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayOpenAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.PlayOpenAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCloseAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.PlayCloseAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStartGame_Confirm(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnStartGame_Confirm" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnListItemPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnListItemPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnListChange( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.OnListChange" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDescription(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateDescription" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateListDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateListDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = WidgetName;
				*( ScriptName* )( params + 8 ) = WidgetPath;
				*( class GFxObject** )( params + 16 ) = Widget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetStringFromMarkup( ScriptArray< wchar_t > MarkupString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_LaunchGame.GetStringFromMarkup" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MarkupString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
