#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_Eagle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Eagle.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
