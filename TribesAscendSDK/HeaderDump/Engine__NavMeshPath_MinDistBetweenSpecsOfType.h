#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavMeshPath_MinDistBetweenSpecsOfType : public NavMeshPathConstraint
	{
	public:
			ADD_VAR( ::ByteProperty, EdgeType, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinDistBetweenEdgeTypes, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
