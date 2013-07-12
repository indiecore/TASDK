#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdPopulationManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdPopulationManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdPopulationManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdPopulationManager : public CrowdPopulationManagerBase
	{
	public:
			ADD_OBJECT( GameCrowdAgent, QueryingAgent )
			ADD_OBJECT( NavigationHandle, NavigationHandle )
			ADD_VAR( ::FloatProperty, InitialPopulationPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadVisibilityOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, KilledCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PoolCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnedCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBehindSpawnDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpawnDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpawnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlayerPositionPredictionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrioritizationUpdateIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrioritizationIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnPrioritizationInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentWarmupTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AgentCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxAgentPoolSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentFrequencySum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Remainder, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SpawnNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWarmupPosition, 0x40 )
			ADD_VAR( ::BoolProperty, bHaveInitialPopulation, 0x20 )
			ADD_VAR( ::BoolProperty, bForceNavMeshPathing, 0x10 )
			ADD_VAR( ::BoolProperty, bForceObstacleChecking, 0x8 )
			ADD_VAR( ::BoolProperty, bCastShadows, 0x4 )
			ADD_VAR( ::BoolProperty, bEnableCrowdLightEnvironment, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawningActive, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
