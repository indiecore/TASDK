#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_GameCrowdSpawner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqAct_GameCrowdSpawner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqAct_GameCrowdSpawner." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_GameCrowdSpawner : public SeqAct_Latent
	{
	public:
		ADD_VAR(::FloatProperty, AgentWarmupTime, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdReplicationActor, RepActor)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LightComponent.LightingChannelContainer' for the property named 'AgentLightingChannel'!
		ADD_OBJECT(GameCrowd_ListOfAgents, CrowdAgentList)
		ADD_VAR(::FloatProperty, AgentFrequencySum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Remainder, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplitScreenNumReduction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SpawnNum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastSpawnLocIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NextDestinationIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCastShadows, 0x200)
		ADD_VAR(::BoolProperty, bWarmupPosition, 0x100)
		ADD_VAR(::BoolProperty, bOnlySpawnHidden, 0x80)
		ADD_VAR(::BoolProperty, bForceNavMeshPathing, 0x40)
		ADD_VAR(::BoolProperty, bForceObstacleChecking, 0x20)
		ADD_VAR(::BoolProperty, bEnableCrowdLightEnvironment, 0x10)
		ADD_VAR(::BoolProperty, bHasReducedNumberDueToSplitScreen, 0x8)
		ADD_VAR(::BoolProperty, bRespawnDeadAgents, 0x4)
		ADD_VAR(::BoolProperty, bCycleSpawnLocs, 0x2)
		ADD_VAR(::BoolProperty, bSpawningActive, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
