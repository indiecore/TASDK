#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Font." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Font." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Font." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Font : public Object
	{
	public:
			ADD_VAR( ::IntProperty, NumCharacters, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Kerning, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Leading, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Descent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Ascent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IsRemapped, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
