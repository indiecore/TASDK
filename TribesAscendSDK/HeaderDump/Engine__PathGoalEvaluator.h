#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PathGoalEvaluator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PathGoalEvaluator." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PathGoalEvaluator." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PathGoalEvaluator : public Object
	{
	public:
			ADD_VAR( ::IntProperty, CacheIdx, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPathVisits, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, GeneratedGoal )
			ADD_OBJECT( PathGoalEvaluator, NextEvaluator )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
