#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_MapSelect : public GFxUDKFrontEnd_Screen
	{
	public:
			ScriptArray< wchar_t > GetImageMarkupByMapName( ScriptArray< wchar_t > InMapName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.GetImageMarkupByMapName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = InMapName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, LastSelectedItem, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxClikWidget, ImgScrollerMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
			void OnViewLoaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.OnViewLoaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTopMostView( bool bPlayOpenAnimation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.OnTopMostView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPlayOpenAnimation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableSubComponents( bool bDisableComponents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.DisableSubComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDisableComponents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMapList_ValueChanged( ScriptArray< wchar_t > InMapSelected, ScriptArray< wchar_t > InMapImageSelected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.OnMapList_ValueChanged" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = InMapSelected;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InMapImageSelected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetList( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.SetList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnListItemPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.OnListItemPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateListDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.UpdateListDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetMapFriendlyName( ScriptArray< wchar_t > Map )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.GetMapFriendlyName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Map;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetImgScroller( class GFxClikWidget* InImgScroller )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.SetImgScroller" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxClikWidget** )params = InImgScroller;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetCurrentGameMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.GetCurrentGameMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void SetupMapCycle( ScriptArray< wchar_t > SelectedMap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.SetupMapCycle" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = SelectedMap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetSelectedMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.GetSelectedMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_MapSelect.WidgetInitialized" );
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
