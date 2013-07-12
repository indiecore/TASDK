#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdDestinationQueuePoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdDestinationQueuePoint." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdDestinationQueuePoint." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdDestinationQueuePoint : public GameCrowdInteractionPoint
	{
	public:
			ADD_OBJECT( GameCrowdAgent, QueuedAgent )
			ADD_OBJECT( GameCrowdDestinationQueuePoint, NextQueuePosition )
			ADD_VAR( ::BoolProperty, bPendingAdvance, 0x2 )
			ADD_VAR( ::FloatProperty, AverageReactionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bClearingQueue, 0x1 )
			ADD_OBJECT( GameCrowdDestination, QueueDestination )
			ADD_OBJECT( GameCrowdInteractionPoint, PreviousQueuePosition )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
