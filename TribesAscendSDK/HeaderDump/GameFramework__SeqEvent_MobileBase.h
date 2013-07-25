#pragma once
#include "Engine__SequenceEvent.h"
#include "GameFramework__MobilePlayerInput.h"
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
			byte* params = (byte*)malloc(4);
			*(class MobilePlayerInput**)params = MPI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
