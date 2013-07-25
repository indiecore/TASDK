#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
namespace UnrealScript
{
	class SceneCaptureActor : public Actor
	{
	public:
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCaptureActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
