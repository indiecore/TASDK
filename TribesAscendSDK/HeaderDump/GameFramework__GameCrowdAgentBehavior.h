#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdAgentBehavior." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdAgentBehavior." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdAgentBehavior." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdAgentBehavior : public Object
	{
	public:
			ADD_OBJECT( Actor, ActionTarget )
			ADD_VAR( ::FloatProperty, MaxPlayerDistance, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdAgent, MyAgent )
			ADD_VAR( ::FloatProperty, TimeToStopPropagatingViralBehavior, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DurationOfViralBehaviorPropagation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsPanicked, 0x10 )
			ADD_VAR( ::BoolProperty, bPassOnIsViralBehaviorFlag, 0x8 )
			ADD_VAR( ::BoolProperty, bIsViralBehavior, 0x4 )
			ADD_VAR( ::BoolProperty, bFaceActionTargetFirst, 0x2 )
			ADD_VAR( ::BoolProperty, bIdleBehavior, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
