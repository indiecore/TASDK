#pragma once
#include "TribesGame__TrDevice.h"
namespace UnrealScript
{
	class TrDevice_S22Rifle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_S22Rifle.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
