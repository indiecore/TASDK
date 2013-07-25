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
			byte* params = (byte*)malloc(8);
			*(class AIController**)params = InAI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
