#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.Path_AvoidInEscapableNodes." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.Path_AvoidInEscapableNodes." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.Path_AvoidInEscapableNodes." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Path_AvoidInEscapableNodes : public PathConstraint
	{
	public:
			ADD_VAR( ::IntProperty, MoveFlags, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxFallSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Height, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Radius, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
