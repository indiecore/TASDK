#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TranslationContext." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TranslationContext." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TranslationContext." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TranslationContext : public Object
	{
	public:
			bool RegisterTranslatorTag( class TranslatorTag* InTagHandler )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TranslationContext.RegisterTranslatorTag" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TranslatorTag** )( params + 0 ) = InTagHandler;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
