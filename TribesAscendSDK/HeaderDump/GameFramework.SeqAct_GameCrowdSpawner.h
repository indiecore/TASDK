#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "GameFramework.GameCrowd_ListOfAgents.h"
#include "GameFramework.GameCrowdReplicationActor.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdGroup.h"
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
		void SpawnedAgent(class GameCrowdAgent* NewAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.SpawnedAgent");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = NewAgent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CacheSpawnerVars()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.CacheSpawnerVars");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAgents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.KillAgents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpawning(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.UpdateSpawning");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GameCrowdAgent* SpawnAgent(class Actor* SpawnLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.SpawnAgent");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = SpawnLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCrowdAgent**)(params + 4);
			free(params);
			return returnVal;
		}
		class GameCrowdAgent* CreateNewAgent(class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.CreateNewAgent");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = SpawnLoc;
			*(class GameCrowdAgent**)(params + 4) = AgentTemplate;
			*(class GameCrowdGroup**)(params + 8) = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCrowdAgent**)(params + 12);
			free(params);
			return returnVal;
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdSpawner.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
