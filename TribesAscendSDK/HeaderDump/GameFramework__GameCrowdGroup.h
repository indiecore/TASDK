#pragma once
#include "GameFramework__GameCrowdDestination.h"
#include "Core__Object.h"
#include "GameFramework__GameCrowdAgent.h"
namespace UnrealScript
{
	class GameCrowdGroup : public Object
	{
	public:
		void AddMember(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdGroup.AddMember");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveMember(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdGroup.RemoveMember");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDestinations(class GameCrowdDestination* NewDestination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdGroup.UpdateDestinations");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdDestination**)params = NewDestination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
