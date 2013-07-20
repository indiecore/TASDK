#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxClikWidget." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxClikWidget." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxClikWidget." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxClikWidget : public GFxObject
	{
	public:
			void EventListener( void* Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.EventListener" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddEventListener( ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.AddEventListener" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetEventStringFromTypename( ScriptName Typename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.GetEventStringFromTypename" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = Typename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SetListener( class GFxObject* O, ScriptArray< wchar_t > Member )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.SetListener" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class GFxObject** )params = O;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Member;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASAddEventListener( ScriptArray< wchar_t > Type, class GFxObject* O, ScriptArray< wchar_t > func )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.ASAddEventListener" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = Type;
				*( class GFxObject** )( params + 12 ) = O;
				*( ScriptArray< wchar_t >* )( params + 16 ) = func;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveAllEventListeners( ScriptArray< wchar_t > Event )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.RemoveAllEventListeners" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Event;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASRemoveAllEventListeners( ScriptArray< wchar_t > Event )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxClikWidget.ASRemoveAllEventListeners" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Event;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
