#pragma once
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "GameFramework.GameCrowdAgent.h"
namespace UnrealScript
{
	class GameCrowdBehavior_WaitForGroup : public GameCrowdAgentBehavior
	{
	public:
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.InitBehavior");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.GetBehaviorString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.ShouldEndIdle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
