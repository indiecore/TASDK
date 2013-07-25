#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class UTMutator_NoPowerups : public UTMutator
	{
	public:
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_NoPowerups.CheckReplacement");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
