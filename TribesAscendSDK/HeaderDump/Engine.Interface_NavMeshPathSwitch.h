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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Interface_NavMeshPathSwitch.AIActivateSwitch");
			byte params[8] = { NULL };
			*(class AIController**)&params[0] = AI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
