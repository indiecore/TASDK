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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33020);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToMobileInput(class MobilePlayerInput* MPI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33024);
			byte params[4] = { NULL };
			*(class MobilePlayerInput**)params = MPI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
