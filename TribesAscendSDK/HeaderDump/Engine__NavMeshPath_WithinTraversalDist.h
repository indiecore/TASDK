#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_WithinTraversalDist." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_WithinTraversalDist : public NavMeshPathConstraint
	{
	public:
			ADD_VAR( ::FloatProperty, SoftStartPenalty, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSoft, 0x1 )
			ADD_VAR( ::FloatProperty, MaxTraversalDist, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
