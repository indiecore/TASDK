#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SplineActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SplineActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SplineActor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SplineActor : public Actor
	{
	public:
			ADD_VAR( ::IntProperty, visitedWeight, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, bestPathWeight, 0xFFFFFFFF )
			ADD_OBJECT( SplineActor, previousPath )
			ADD_OBJECT( SplineActor, prevOrdered )
			ADD_OBJECT( SplineActor, nextOrdered )
			ADD_VAR( ::BoolProperty, bAlreadyVisited, 0x2 )
			ADD_VAR( ::BoolProperty, bDisableDestination, 0x1 )
			ADD_STRUCT( ::VectorProperty, SplineActorTangent, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
