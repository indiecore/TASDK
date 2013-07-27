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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25357);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
