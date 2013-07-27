#pragma once
#include "Core.Interface.h"
#include "GameFramework.GameCrowdAgent.h"
namespace UnrealScript
{
	class GameCrowdSpawnerInterface : public Interface
	{
	public:
		bool AddToAgentPool(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30973);
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetMaxSpawnDist()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31010);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void AgentDestroyed(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31514);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
