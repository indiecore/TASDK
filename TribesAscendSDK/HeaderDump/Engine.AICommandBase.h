#pragma once
#include "Core.Object.h"
#include "Engine.AIController.h"
namespace UnrealScript
{
	class AICommandBase : public Object
	{
	public:
		int GetUtility(class AIController* InAI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9681);
			byte params[8] = { NULL };
			*(class AIController**)params = InAI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
