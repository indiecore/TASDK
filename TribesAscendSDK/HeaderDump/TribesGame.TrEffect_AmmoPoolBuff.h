#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrEffect_AmmoPoolBuff : public TrEffect_Managed
	{
	public:
		void Apply(class Actor* Target, Actor::ImpactInfo Impact)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87101);
			byte params[84] = { NULL };
			*(class Actor**)params = Target;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87104);
			byte params[4] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
