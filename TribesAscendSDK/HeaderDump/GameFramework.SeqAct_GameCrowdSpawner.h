#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowd_ListOfAgents.h"
#include "GameFramework.GameCrowdReplicationActor.h"
#include "GameFramework.GameCrowdGroup.h"
#include "Engine.LightComponent.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_GameCrowdSpawner : public SeqAct_Latent
	{
	public:
		struct AgentArchetypeInfo
		{
		public:
			ADD_STRUCT(ScriptArray<class Object*>, GroupMembers, 16)
			ADD_STRUCT(int, CurrSpawned, 12)
			ADD_STRUCT(int, MaxAllowed, 8)
			ADD_STRUCT(float, FrequencyModifier, 4)
			ADD_OBJECT(Object, AgentArchetype, 0)
		};
		ADD_STRUCT(ScriptArray<class Actor*>, SpawnLocs, 256)
		ADD_STRUCT(ScriptArray<SeqAct_GameCrowdSpawner::AgentArchetypeInfo>, AgentArchetypes, 300)
		ADD_STRUCT(ScriptArray<class GameCrowdAgent*>, SpawnedList, 312)
		ADD_STRUCT(float, AgentWarmupTime, 332)
		ADD_OBJECT(GameCrowdReplicationActor, RepActor, 328)
		ADD_STRUCT(LightComponent::LightingChannelContainer, AgentLightingChannel, 324)
		ADD_OBJECT(GameCrowd_ListOfAgents, CrowdAgentList, 296)
		ADD_STRUCT(float, AgentFrequencySum, 292)
		ADD_STRUCT(float, Remainder, 288)
		ADD_STRUCT(float, SplitScreenNumReduction, 284)
		ADD_STRUCT(float, SpawnRadius, 280)
		ADD_STRUCT(int, SpawnNum, 276)
		ADD_STRUCT(float, SpawnRate, 272)
		ADD_STRUCT(int, LastSpawnLocIndex, 268)
		ADD_STRUCT(int, NextDestinationIndex, 252)
		ADD_BOOL(bCastShadows, 248, 0x200)
		ADD_BOOL(bWarmupPosition, 248, 0x100)
		ADD_BOOL(bOnlySpawnHidden, 248, 0x80)
		ADD_BOOL(bForceNavMeshPathing, 248, 0x40)
		ADD_BOOL(bForceObstacleChecking, 248, 0x20)
		ADD_BOOL(bEnableCrowdLightEnvironment, 248, 0x10)
		ADD_BOOL(bHasReducedNumberDueToSplitScreen, 248, 0x8)
		ADD_BOOL(bRespawnDeadAgents, 248, 0x4)
		ADD_BOOL(bCycleSpawnLocs, 248, 0x2)
		ADD_BOOL(bSpawningActive, 248, 0x1)
		void SpawnedAgent(class GameCrowdAgent* NewAgent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32913);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = NewAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CacheSpawnerVars()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32915);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAgents()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32916);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpawning(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32917);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GameCrowdAgent* SpawnAgent(class Actor* SpawnLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32919);
			byte params[8] = { NULL };
			*(class Actor**)params = SpawnLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCrowdAgent**)&params[4];
		}
		class GameCrowdAgent* CreateNewAgent(class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32929);
			byte params[16] = { NULL };
			*(class Actor**)params = SpawnLoc;
			*(class GameCrowdAgent**)&params[4] = AgentTemplate;
			*(class GameCrowdGroup**)&params[8] = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCrowdAgent**)&params[12];
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32937);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
