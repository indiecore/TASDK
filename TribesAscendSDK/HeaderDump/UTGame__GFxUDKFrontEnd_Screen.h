#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Screen : public GFxUDKFrontEnd_View
	{
	public:
			ADD_VAR( ::StrProperty, CancelButtonImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AcceptButtonImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CancelButtonHelpText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AcceptButtonHelpText, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, InfoTxt )
			ADD_OBJECT( GFxObject, HelpTxt )
			ADD_OBJECT( GFxObject, LogoMC )
			ADD_OBJECT( GFxObject, FooterMC )
			ADD_OBJECT( GFxObject, TitleMC )
			ADD_OBJECT( GFxClikWidget, BackBtn )
			ADD_VAR( ::StrProperty, ViewTitle, 0xFFFFFFFF )
			void FocusIn_BackButton( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Screen.FocusIn_BackButton" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )( params + 0 ) = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateHelpButtonImages(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Screen.UpdateHelpButtonImages" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Screen.WidgetInitialized" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = WidgetName;
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
