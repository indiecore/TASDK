#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIPropertyDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIPropertyDataProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIPropertyDataProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIPropertyDataProvider : public UIDataProvider
	{
	public:
			bool CanSupportComplexPropertyType( class Property* UnsupportedProperty )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIPropertyDataProvider.CanSupportComplexPropertyType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Property** )params = UnsupportedProperty;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetCustomPropertyValue( void* &PropertyValue, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIPropertyDataProvider.GetCustomPropertyValue" );
				byte *params = ( byte* )( malloc( 88 ) );
				*( void** )params = PropertyValue;
				*( int* )( params + 84 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				PropertyValue = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
