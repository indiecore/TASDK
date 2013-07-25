#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_CustomEagle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_CustomEagle.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
