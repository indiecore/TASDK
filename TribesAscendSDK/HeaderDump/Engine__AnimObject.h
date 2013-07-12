#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.AnimObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.AnimObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.AnimObject." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimObject : public Object
	{
	public:
			ADD_VAR( ::StrProperty, CategoryDesc, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OutDrawY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NodePosY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NodePosX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DrawHeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DrawWidth, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
