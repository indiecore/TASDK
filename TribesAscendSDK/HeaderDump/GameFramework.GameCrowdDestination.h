#pragma once
#include "GameFramework.GameCrowdDestinationQueuePoint.h"
#include "GameFramework.GameCrowdPopulationManager.h"
#include "GameFramework.GameCrowdInteractionPoint.h"
#include "Core.Object.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
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
	class GameCrowdDestination : public GameCrowdInteractionPoint
	{
	public:
		ADD_STRUCT(ScriptArray<class GameCrowdDestination*>, NextDestinations, 492)
		ADD_STRUCT(ScriptArray<ScriptClass*>, SupportedAgentClasses, 520)
		ADD_STRUCT(ScriptArray<class Object*>, SupportedArchetypes, 532)
		ADD_STRUCT(ScriptArray<ScriptClass*>, RestrictedAgentClasses, 544)
		ADD_STRUCT(ScriptArray<class Object*>, RestrictedArchetypes, 556)
		ADD_STRUCT(ScriptArray<GameCrowdAgent::BehaviorEntry>, ReachedBehaviors, 588)
		ADD_OBJECT(GameCrowdPopulationManager, MyPopMgr, 612)
		ADD_STRUCT(float, LastSpawnTime, 608)
		ADD_STRUCT(float, Priority, 604)
		ADD_OBJECT(GameCrowdAgent, AgentEnRoute, 600)
		ADD_STRUCT(float, SpawnRadius, 584)
		ADD_STRUCT(float, InteractionDelay, 580)
		ADD_STRUCT(ScriptName, InteractionTag, 572)
		ADD_STRUCT(float, ExactReachTolerance, 568)
		ADD_STRUCT(int, CustomerCount, 516)
		ADD_STRUCT(float, Frequency, 512)
		ADD_STRUCT(int, Capacity, 508)
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueueHead, 504)
		ADD_BOOL(bHasNavigationMesh, 488, 0x20000)
		ADD_BOOL(bAdjacentToVisibleNode, 488, 0x10000)
		ADD_BOOL(bIsBeyondSpawnDistance, 488, 0x8000)
		ADD_BOOL(bCanSpawnHereNow, 488, 0x4000)
		ADD_BOOL(bWillBeVisible, 488, 0x2000)
		ADD_BOOL(bIsVisible, 488, 0x1000)
		ADD_BOOL(bSoftPerimeter, 488, 0x800)
		ADD_BOOL(bSpawnAtEdge, 488, 0x400)
		ADD_BOOL(bLineSpawner, 488, 0x200)
		ADD_BOOL(bAllowsSpawning, 488, 0x100)
		ADD_BOOL(bHasRestrictions, 488, 0x80)
		ADD_BOOL(bMustReachExactly, 488, 0x40)
		ADD_BOOL(bFleeDestination, 488, 0x20)
		ADD_BOOL(bSkipBehaviorIfPanicked, 488, 0x10)
		ADD_BOOL(bAvoidWhenPanicked, 488, 0x8)
		ADD_BOOL(bLastAllowableResult, 488, 0x4)
		ADD_BOOL(bAllowAsPreviousDestination, 488, 0x2)
		ADD_BOOL(bKillWhenReached, 488, 0x1)
		ADD_STRUCT(Object::Pointer, VfTable_IEditorLinkSelectionInterface, 484)
		bool ReachedByAgent(class GameCrowdAgent* Agent, Vector TestPosition, bool bTestExactly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30478);
			byte params[24] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)&params[4] = TestPosition;
			*(bool*)&params[16] = bTestExactly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30483);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30486);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReachedDestination(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30487);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickNewDestinationFor(class GameCrowdAgent* Agent, bool bIgnoreRestrictions)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30497);
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			*(bool*)&params[4] = bIgnoreRestrictions;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowableDestinationFor(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30503);
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DecrementCustomerCount(class GameCrowdAgent* DepartingAgent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30505);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = DepartingAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementCustomerCount(class GameCrowdAgent* ArrivingAgent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30513);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = ArrivingAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AtCapacity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30518);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void GetSpawnPosition(class SeqAct_GameCrowdSpawner* Spawner, Vector& SpawnPos, Rotator& SpawnRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30526);
			byte params[28] = { NULL };
			*(class SeqAct_GameCrowdSpawner**)params = Spawner;
			*(Vector*)&params[4] = SpawnPos;
			*(Rotator*)&params[16] = SpawnRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SpawnPos = *(Vector*)&params[4];
			SpawnRot = *(Rotator*)&params[16];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
