#pragma once
#include "Engine.CrowdPopulationManagerBase.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.HUD.h"
#include "Engine.NavigationHandle.h"
#include "GameFramework.GameCrowdGroup.h"
#include "GameFramework.GameCrowdDestination.h"
#include "GameFramework.SeqAct_GameCrowdPopulationManagerToggle.h"
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
		ADD_OBJECT(ScriptClass, NavigationHandleClass)
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void AddSpawnPoint(class GameCrowdDestination* GCD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdDestination**)params = GCD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveSpawnPoint(class GameCrowdDestination* GCD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdDestination**)params = GCD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameCrowdPopulationManagerToggle(class SeqAct_GameCrowdPopulationManagerToggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_GameCrowdPopulationManagerToggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlushAgents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.FlushAgents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AgentDestroyed(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AgentDestroyed");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AddToAgentPool(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddToAgentPool");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		bool IsSpawningActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.IsSpawningActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GameCrowdDestination* PickSpawnPoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCrowdDestination**)params;
			free(params);
			return returnVal;
		}
		void PrioritizeSpawnPoints(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AnalyzeSpawnPoints(int StartIndex, int StopIndex, Vector ViewLocation, Vector PredictionLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints");
			byte* params = (byte*)malloc(32);
			*(int*)params = StartIndex;
			*(int*)(params + 4) = StopIndex;
			*(Vector*)(params + 8) = ViewLocation;
			*(Vector*)(params + 20) = PredictionLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddPrioritizedSpawnPoint(class GameCrowdDestination* GCD, Vector ViewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint");
			byte* params = (byte*)malloc(16);
			*(class GameCrowdDestination**)params = GCD;
			*(Vector*)(params + 4) = ViewLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ValidateSpawnAt(class GameCrowdDestination* Candidate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = Candidate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class GameCrowdAgent* SpawnAgent(class GameCrowdDestination* SpawnLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.SpawnAgent");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = SpawnLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCrowdAgent**)(params + 4);
			free(params);
			return returnVal;
		}
		class GameCrowdAgent* CreateNewAgent(class GameCrowdDestination* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdPopulationManager.CreateNewAgent");
			byte* params = (byte*)malloc(16);
			*(class GameCrowdDestination**)params = SpawnLoc;
			*(class GameCrowdAgent**)(params + 4) = AgentTemplate;
			*(class GameCrowdGroup**)(params + 8) = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCrowdAgent**)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
