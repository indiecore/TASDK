#pragma once
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__GameCrowdAgent.h"
namespace UnrealScript
{
	class GameCrowdBehavior_WaitForGroup : public GameCrowdAgentBehavior
	{
	public:
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.InitBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.GetBehaviorString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.ShouldEndIdle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_WaitForGroup.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
