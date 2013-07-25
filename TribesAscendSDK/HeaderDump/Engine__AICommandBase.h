#pragma once
#include "Core__Object.h"
#include "Engine__AIController.h"
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
