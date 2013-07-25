#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrEffect_Blink : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Blink.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
