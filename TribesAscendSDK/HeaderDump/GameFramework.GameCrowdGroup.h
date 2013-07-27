#pragma once
#include "Core.Object.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdDestination.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameCrowdGroup : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class GameCrowdAgent*>, Members, 60)
		void AddMember(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31322);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveMember(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31324);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDestinations(class GameCrowdDestination* NewDestination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31326);
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)params = NewDestination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
