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
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
