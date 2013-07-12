#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ModelComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ModelComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ModelComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ModelComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::IntProperty, ComponentIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ZoneIndex, 0xFFFFFFFF )
			ADD_OBJECT( Object, Model )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
