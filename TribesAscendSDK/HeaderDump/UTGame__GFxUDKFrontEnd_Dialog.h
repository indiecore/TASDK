#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_Dialog." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_Dialog." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_Dialog." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Dialog : public GFxUDKFrontEnd_View
	{
	public:
			void AcceptDelegate( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.AcceptDelegate" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( GFxClikWidget, AcceptBtn )
			ADD_OBJECT( GFxClikWidget, BackBtn )
			ADD_OBJECT( GFxObject, InfoTxt )
			ADD_OBJECT( GFxObject, TitleTxt )
			ADD_OBJECT( GFxObject, DialogMC )
			void OnViewClosed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.OnViewClosed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableSubComponents( bool bDisableComponents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.DisableSubComponents" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDisableComponents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTopMostView( bool bPlayOpenAnimation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.OnTopMostView" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bPlayOpenAnimation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayOpenAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.PlayOpenAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCloseAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.PlayCloseAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBackButton( class GFxObject* InBackButton )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.SetBackButton" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = InBackButton;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBackButton_OnPress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.SetBackButton_OnPress" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Select_Back( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.Select_Back" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WidgetInitialized( ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Dialog.WidgetInitialized" );
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
