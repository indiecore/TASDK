#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_Sparrow : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Sparrow.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
