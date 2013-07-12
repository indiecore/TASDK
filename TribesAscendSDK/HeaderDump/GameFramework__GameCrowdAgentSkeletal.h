#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdAgentSkeletal." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdAgentSkeletal." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdAgentSkeletal." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdAgentSkeletal : public GameCrowdAgent
	{
	public:
			ADD_VAR( ::FloatProperty, MaxAnimationDistanceSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAnimationDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAnimateThisTick, 0x8 )
			ADD_VAR( ::BoolProperty, bIsPlayingDeathAnimation, 0x4 )
			ADD_VAR( ::BoolProperty, bIsPlayingIdleAnimation, 0x2 )
			ADD_VAR( ::BoolProperty, bUseRootMotionVelocity, 0x1 )
			ADD_VAR( ::FloatProperty, MaxTargetAcquireTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MoveSyncGroupName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpeedBlendChangeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimVelRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpeedBlendEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpeedBlendStart, 0xFFFFFFFF )
			ADD_OBJECT( AnimTree, AgentTree )
			ADD_OBJECT( AnimNodeSequence, RunSeqNode )
			ADD_OBJECT( AnimNodeSequence, WalkSeqNode )
			ADD_OBJECT( AnimNodeSequence, ActionSeqNode )
			ADD_OBJECT( AnimNodeSlot, FullBodySlot )
			ADD_OBJECT( AnimNodeBlend, SpeedBlendNode )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
