#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUIFrontEnd_TitleScreen : public GFxMoviePlayer
	{
	public:
			ADD_VAR( ::ByteProperty, Selection, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CampaignMap, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, InstantActionMap, 0xFFFFFFFF )
			ADD_OBJECT( GFxClikWidget, MenuBtn6MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn5MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn4MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn3MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn2MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn1MC )
			ADD_OBJECT( GFxObject, BlackMC )
			ADD_OBJECT( GFxObject, MenuButtonsMC )
			ADD_OBJECT( GFxObject, MainMenuMC )
			ADD_OBJECT( GFxObject, TitleScreenMC )
			bool Start( bool StartPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.Start" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = StartPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FilterButtonInput( int ControllerId, ScriptName ButtonName, byte InputEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.FilterButtonInput" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( int* )( params + 0 ) = ControllerId;
				*( ScriptName* )( params + 4 ) = ButtonName;
				*( byte* )( params + 12 ) = InputEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnMenuButtonPress( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.OnMenuButtonPress" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCloseAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.PlayCloseAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCloseAnimationComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.OnCloseAnimationComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UT_ConsoleCommand( ScriptArray< wchar_t > Cmd, bool bWriteToLog )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUIFrontEnd_TitleScreen.UT_ConsoleCommand" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Cmd;
				*( bool* )( params + 12 ) = bWriteToLog;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
