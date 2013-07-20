#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TranslatorTag." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TranslatorTag." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TranslatorTag." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TranslatorTag : public Object
	{
	public:
			ADD_VAR( ::NameProperty, Tag, 0xFFFFFFFF )
			ScriptArray< wchar_t > Translate( ScriptArray< wchar_t > InArgument )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TranslatorTag.Translate" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = InArgument;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
