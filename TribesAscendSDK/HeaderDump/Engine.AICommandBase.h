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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AICommandBase.GetUtility");
			byte params[8] = { NULL };
			*(class AIController**)&params[0] = InAI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
