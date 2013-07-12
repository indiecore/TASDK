#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.NavigationHandle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.NavigationHandle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.NavigationHandle." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NavigationHandle : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, LastPathFailTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LastPathError, 0xFFFFFFFF )
			ADD_OBJECT( NavMeshPathGoalEvaluator, PathGoalList )
			ADD_OBJECT( NavMeshPathConstraint, PathConstraintList )
			ADD_VAR( ::BoolProperty, bUltraVerbosePathDebugging, 0x8 )
			ADD_VAR( ::BoolProperty, bDebugConstraintsAndGoalEvals, 0x4 )
			ADD_VAR( ::BoolProperty, bUseORforEvaluateGoal, 0x2 )
			ADD_VAR( ::BoolProperty, bSkipRouteCacheUpdates, 0x1 )
			ADD_OBJECT( Pylon, AnchorPylon )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
