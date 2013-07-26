#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.ImpactInfo.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrEffect_HeavyShield : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, ImpactInfo Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_HeavyShield.Apply");
			byte* params = (byte*)malloc(84);
			*(class Actor**)params = Target;
			*(ImpactInfo*)(params + 4) = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_HeavyShield.Remove");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
