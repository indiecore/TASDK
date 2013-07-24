#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdPopulationManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameCrowdPopulationManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdPopulationManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdPopulationManager : public CrowdPopulationManagerBase
	{
	public:
		ADD_OBJECT(GameCrowdAgent, QueryingAgent)
		ADD_OBJECT(NavigationHandle, NavigationHandle)
		ADD_VAR(::FloatProperty, InitialPopulationPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeadVisibilityOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KilledCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PoolCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SpawnedCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinBehindSpawnDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpawnDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpawnDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayerPositionPredictionTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrioritizationUpdateIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrioritizationIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnPrioritizationInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AgentWarmupTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer' for the property named 'AgentLightingChannel'!
		ADD_VAR(::IntProperty, AgentCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxAgentPoolSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AgentFrequencySum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Remainder, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SpawnNum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWarmupPosition, 0x40)
		ADD_VAR(::BoolProperty, bHaveInitialPopulation, 0x20)
		ADD_VAR(::BoolProperty, bForceNavMeshPathing, 0x10)
		ADD_VAR(::BoolProperty, bForceObstacleChecking, 0x8)
		ADD_VAR(::BoolProperty, bCastShadows, 0x4)
		ADD_VAR(::BoolProperty, bEnableCrowdLightEnvironment, 0x2)
		ADD_VAR(::BoolProperty, bSpawningActive, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavigationHandle'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
