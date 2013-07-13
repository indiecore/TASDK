#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Core.Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Core.Object." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Core.Object." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Object
	{
	public:
			ADD_OBJECT( Object, Outer )
			ADD_VAR( ::NameProperty, Name, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ObjectInternalInteger, 0xFFFFFFFF )
			ADD_OBJECT( Object, Linker )
			ADD_VAR( ::IntProperty, NetIndex, 0xFFFFFFFF )
			ADD_OBJECT( Object, ObjectArchetype )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
