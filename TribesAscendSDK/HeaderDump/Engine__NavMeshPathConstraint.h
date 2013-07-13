#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPathConstraint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPathConstraint." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPathConstraint." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPathConstraint : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, AddedHeuristicCost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AddedDirectCost, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumThrownOutNodes, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumNodesProcessed, 0xFFFFFFFF )
			ADD_OBJECT( NavMeshPathConstraint, NextConstraint )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
