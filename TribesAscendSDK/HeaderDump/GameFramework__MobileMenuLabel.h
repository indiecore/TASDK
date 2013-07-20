#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.MobileMenuLabel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.MobileMenuLabel." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.MobileMenuLabel." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobileMenuLabel : public MobileMenuObject
	{
	public:
			ADD_VAR( ::BoolProperty, bAutoSize, 0x1 )
			ADD_VAR( ::FloatProperty, TextYScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TextXScale, 0xFFFFFFFF )
			ADD_OBJECT( Font, TextFont )
			ADD_VAR( ::StrProperty, Caption, 0xFFFFFFFF )
			void RenderObject( class Canvas* Canvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileMenuLabel.RenderObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Canvas** )params = Canvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
