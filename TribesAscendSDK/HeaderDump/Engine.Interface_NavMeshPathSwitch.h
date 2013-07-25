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
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = AI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
