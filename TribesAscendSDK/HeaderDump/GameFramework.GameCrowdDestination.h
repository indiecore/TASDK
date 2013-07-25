#pragma once
#include "GameFramework.GameCrowdDestinationQueuePoint.h"
#include "GameFramework.GameCrowdPopulationManager.h"
#include "GameFramework.GameCrowdInteractionPoint.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdDestination." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameCrowdDestination." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdDestination." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdDestination : public GameCrowdInteractionPoint
	{
	public:
		ADD_OBJECT(GameCrowdPopulationManager, MyPopMgr)
		ADD_VAR(::FloatProperty, LastSpawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgent, AgentEnRoute)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteractionDelay, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InteractionTag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExactReachTolerance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomerCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Capacity, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueueHead)
		ADD_VAR(::BoolProperty, bHasNavigationMesh, 0x20000)
		ADD_VAR(::BoolProperty, bAdjacentToVisibleNode, 0x10000)
		ADD_VAR(::BoolProperty, bIsBeyondSpawnDistance, 0x8000)
		ADD_VAR(::BoolProperty, bCanSpawnHereNow, 0x4000)
		ADD_VAR(::BoolProperty, bWillBeVisible, 0x2000)
		ADD_VAR(::BoolProperty, bIsVisible, 0x1000)
		ADD_VAR(::BoolProperty, bSoftPerimeter, 0x800)
		ADD_VAR(::BoolProperty, bSpawnAtEdge, 0x400)
		ADD_VAR(::BoolProperty, bLineSpawner, 0x200)
		ADD_VAR(::BoolProperty, bAllowsSpawning, 0x100)
		ADD_VAR(::BoolProperty, bHasRestrictions, 0x80)
		ADD_VAR(::BoolProperty, bMustReachExactly, 0x40)
		ADD_VAR(::BoolProperty, bFleeDestination, 0x20)
		ADD_VAR(::BoolProperty, bSkipBehaviorIfPanicked, 0x10)
		ADD_VAR(::BoolProperty, bAvoidWhenPanicked, 0x8)
		ADD_VAR(::BoolProperty, bLastAllowableResult, 0x4)
		ADD_VAR(::BoolProperty, bAllowAsPreviousDestination, 0x2)
		ADD_VAR(::BoolProperty, bKillWhenReached, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IEditorLinkSelectionInterface'!
		bool ReachedByAgent(class GameCrowdAgent* Agent, Vector TestPosition, bool bTestExactly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.ReachedByAgent");
			byte* params = (byte*)malloc(24);
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)(params + 4) = TestPosition;
			*(bool*)(params + 16) = bTestExactly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReachedDestination(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.ReachedDestination");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PickNewDestinationFor(class GameCrowdAgent* Agent, bool bIgnoreRestrictions)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.PickNewDestinationFor");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdAgent**)params = Agent;
			*(bool*)(params + 4) = bIgnoreRestrictions;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowableDestinationFor(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.AllowableDestinationFor");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DecrementCustomerCount(class GameCrowdAgent* DepartingAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.DecrementCustomerCount");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = DepartingAgent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementCustomerCount(class GameCrowdAgent* ArrivingAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.IncrementCustomerCount");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = ArrivingAgent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AtCapacity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.AtCapacity");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void GetSpawnPosition(class SeqAct_GameCrowdSpawner* Spawner, Vector& SpawnPos, Rotator& SpawnRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestination.GetSpawnPosition");
			byte* params = (byte*)malloc(28);
			*(class SeqAct_GameCrowdSpawner**)params = Spawner;
			*(Vector*)(params + 4) = SpawnPos;
			*(Rotator*)(params + 16) = SpawnRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			SpawnPos = *(Vector*)(params + 4);
			SpawnRot = *(Rotator*)(params + 16);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
