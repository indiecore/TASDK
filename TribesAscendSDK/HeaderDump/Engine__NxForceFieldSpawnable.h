#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
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
