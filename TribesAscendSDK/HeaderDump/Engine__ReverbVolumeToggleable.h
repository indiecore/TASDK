#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__ReverbVolume.h"
namespace UnrealScript
{
	class ReverbVolumeToggleable : public ReverbVolume
	{
	public:
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ReverbVolumeToggleable.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
