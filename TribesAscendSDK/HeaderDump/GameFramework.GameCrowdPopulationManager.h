#pragma once
#include "Engine.CrowdPopulationManagerBase.h"
#include "GameFramework.SeqAct_GameCrowdPopulationManagerToggle.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.LightComponent.h"
#include "GameFramework.GameCrowdDestination.h"
#include "Engine.HUD.h"
#include "Engine.NavigationHandle.h"
#include "Core.Object.h"
#include "GameFramework.GameCrowdGroup.h"
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
	class GameCrowdPopulationManager : public CrowdPopulationManagerBase
	{
	public:
		ADD_STRUCT(ScriptArray<SeqAct_GameCrowdSpawner::AgentArchetypeInfo>, AgentArchetypes, 504)
		ADD_STRUCT(ScriptArray<class GameCrowdAgent*>, AgentPool, 516)
		ADD_STRUCT(ScriptArray<class GameCrowdDestination*>, PrioritizedSpawnPoints, 556)
		ADD_STRUCT(ScriptArray<class GameCrowdDestination*>, PotentialSpawnPoints, 572)
		ADD_OBJECT(GameCrowdAgent, QueryingAgent, 624)
		ADD_OBJECT(NavigationHandle, NavigationHandle, 620)
		ADD_OBJECT(ScriptClass, NavigationHandleClass, 616)
		ADD_STRUCT(float, InitialPopulationPct, 612)
		ADD_STRUCT(float, HeadVisibilityOffset, 608)
		ADD_STRUCT(int, KilledCount, 604)
		ADD_STRUCT(int, PoolCount, 600)
		ADD_STRUCT(int, SpawnedCount, 596)
		ADD_STRUCT(float, MinBehindSpawnDistSq, 592)
		ADD_STRUCT(float, MaxSpawnDistSq, 588)
		ADD_STRUCT(float, MaxSpawnDist, 584)
		ADD_STRUCT(float, PlayerPositionPredictionTime, 568)
		ADD_STRUCT(int, PrioritizationUpdateIndex, 552)
		ADD_STRUCT(int, PrioritizationIndex, 548)
		ADD_STRUCT(float, SpawnPrioritizationInterval, 544)
		ADD_STRUCT(float, AgentWarmupTime, 540)
		ADD_STRUCT(LightComponent::LightingChannelContainer, AgentLightingChannel, 536)
		ADD_STRUCT(int, AgentCount, 532)
		ADD_STRUCT(int, MaxAgentPoolSize, 528)
		ADD_STRUCT(float, AgentFrequencySum, 500)
		ADD_STRUCT(float, Remainder, 496)
		ADD_STRUCT(float, SplitScreenNumReduction, 492)
		ADD_STRUCT(int, SpawnNum, 488)
		ADD_STRUCT(float, SpawnRate, 484)
		ADD_BOOL(bWarmupPosition, 480, 0x40)
		ADD_BOOL(bHaveInitialPopulation, 480, 0x20)
		ADD_BOOL(bForceNavMeshPathing, 480, 0x10)
		ADD_BOOL(bForceObstacleChecking, 480, 0x8)
		ADD_BOOL(bCastShadows, 480, 0x4)
		ADD_BOOL(bEnableCrowdLightEnvironment, 480, 0x2)
		ADD_BOOL(bSpawningActive, 480, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_NavigationHandle, 476)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyPathChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.NotifyPathChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxSpawnDist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.GetMaxSpawnDist");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void AddSpawnPoint(class GameCrowdDestination* GCD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint");
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)&params[0] = GCD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveSpawnPoint(class GameCrowdDestination* GCD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint");
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)&params[0] = GCD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameCrowdPopulationManagerToggle(class SeqAct_GameCrowdPopulationManagerToggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle");
			byte params[4] = { NULL };
			*(class SeqAct_GameCrowdPopulationManagerToggle**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlushAgents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.FlushAgents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AgentDestroyed(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AgentDestroyed");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AddToAgentPool(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddToAgentPool");
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		bool IsSpawningActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.IsSpawningActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Tick(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GameCrowdDestination* PickSpawnPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCrowdDestination**)&params[0];
		}
		void PrioritizeSpawnPoints(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AnalyzeSpawnPoints(int StartIndex, int StopIndex, Object::Vector ViewLocation, Object::Vector PredictionLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints");
			byte params[32] = { NULL };
			*(int*)&params[0] = StartIndex;
			*(int*)&params[4] = StopIndex;
			*(Object::Vector*)&params[8] = ViewLocation;
			*(Object::Vector*)&params[20] = PredictionLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddPrioritizedSpawnPoint(class GameCrowdDestination* GCD, Object::Vector ViewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint");
			byte params[16] = { NULL };
			*(class GameCrowdDestination**)&params[0] = GCD;
			*(Object::Vector*)&params[4] = ViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ValidateSpawnAt(class GameCrowdDestination* Candidate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = Candidate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GameCrowdAgent* SpawnAgent(class GameCrowdDestination* SpawnLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.SpawnAgent");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = SpawnLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCrowdAgent**)&params[4];
		}
		class GameCrowdAgent* CreateNewAgent(class GameCrowdDestination* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.CreateNewAgent");
			byte params[16] = { NULL };
			*(class GameCrowdDestination**)&params[0] = SpawnLoc;
			*(class GameCrowdAgent**)&params[4] = AgentTemplate;
			*(class GameCrowdGroup**)&params[8] = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCrowdAgent**)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
