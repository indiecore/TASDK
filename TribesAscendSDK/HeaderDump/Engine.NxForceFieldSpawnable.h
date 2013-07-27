#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
namespace UnrealScript
{
	class NxForceFieldSpawnable : public Actor
	{
	public:
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NxForceFieldSpawnable.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
