#pragma once
#include "Engine.Interface_NavMeshPathObject.h"
#include "Engine.AIController.h"
namespace UnrealScript
{
	class Interface_NavMeshPathSwitch : public Interface_NavMeshPathObject
	{
	public:
		bool AIActivateSwitch(class AIController* AI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18351);
			byte params[8] = { NULL };
			*(class AIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
