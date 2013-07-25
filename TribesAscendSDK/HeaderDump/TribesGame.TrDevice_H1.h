#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_H1 : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_H1.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
