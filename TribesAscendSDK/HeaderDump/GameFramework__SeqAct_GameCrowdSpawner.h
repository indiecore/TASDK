#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.SeqAct_GameCrowdSpawner." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.SeqAct_GameCrowdSpawner." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.SeqAct_GameCrowdSpawner." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_GameCrowdSpawner : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::FloatProperty, AgentWarmupTime, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdReplicationActor, RepActor )
			ADD_OBJECT( GameCrowd_ListOfAgents, CrowdAgentList )
			ADD_VAR( ::FloatProperty, AgentFrequencySum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Remainder, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRadius, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastSpawnLocIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NextDestinationIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x200 )
			ADD_VAR( ::BoolProperty, bWarmupPosition, 0x100 )
			ADD_VAR( ::BoolProperty, bOnlySpawnHidden, 0x80 )
			ADD_VAR( ::BoolProperty, bForceNavMeshPathing, 0x40 )
			ADD_VAR( ::BoolProperty, bForceObstacleChecking, 0x20 )
			ADD_VAR( ::BoolProperty, bEnableCrowdLightEnvironment, 0x10 )
			ADD_VAR( ::BoolProperty, bHasReducedNumberDueToSplitScreen, 0x8 )
			ADD_VAR( ::BoolProperty, bRespawnDeadAgents, 0x4 )
			ADD_VAR( ::BoolProperty, bCycleSpawnLocs, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawningActive, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
