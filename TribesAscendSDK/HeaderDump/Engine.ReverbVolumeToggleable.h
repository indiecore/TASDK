#pragma once
#include "Engine.ReverbVolume.h"
#include "Engine.SeqAct_Toggle.h"
namespace UnrealScript
{
	class ReverbVolumeToggleable : public ReverbVolume
	{
	public:
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ReverbVolumeToggleable.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
