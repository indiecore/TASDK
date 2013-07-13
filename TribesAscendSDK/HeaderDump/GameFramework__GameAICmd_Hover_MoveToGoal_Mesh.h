#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameAICmd_Hover_MoveToGoal_Mesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameAICmd_Hover_MoveToGoal_Mesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameAICmd_Hover_MoveToGoal_Mesh." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameAICmd_Hover_MoveToGoal_Mesh : public GameAICommand
	{
	public:
			ADD_VAR( ::IntProperty, MaxMoveFails, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MoveFailCounter, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, InitialFinalDestination, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastMoveVectDest, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MoveVectDest, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GoalDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SubGoalReachDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentHoverHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredHoverHeight, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWasFiring, 0x1 )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Goal )
			ADD_OBJECT( Actor, Find )
			ADD_STRUCT( ::VectorProperty, Transient_FinalDest, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
