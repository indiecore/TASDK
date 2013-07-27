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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdSpawnerInterface.AddToAgentPool");
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetMaxSpawnDist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdSpawnerInterface.GetMaxSpawnDist");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void AgentDestroyed(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdSpawnerInterface.AgentDestroyed");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
