#pragma once
#include "Engine.SequenceEvent.h"
#include "GameFramework.MobilePlayerInput.h"
namespace UnrealScript
{
	class SeqEvent_MobileBase : public SequenceEvent
	{
	public:
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileBase.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToMobileInput(class MobilePlayerInput* MPI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileBase.AddToMobileInput");
			byte params[4] = { NULL };
			*(class MobilePlayerInput**)&params[0] = MPI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
