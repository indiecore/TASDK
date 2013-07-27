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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31276);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31278);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31281);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StopBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31283);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
