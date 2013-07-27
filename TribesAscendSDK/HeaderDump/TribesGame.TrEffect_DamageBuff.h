#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrEffect_DamageBuff : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, Actor::ImpactInfo Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_DamageBuff.Apply");
			byte params[84] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_DamageBuff.Remove");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
