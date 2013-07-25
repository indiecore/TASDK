#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrEffect_Shield : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Shield.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Shield.Remove");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
