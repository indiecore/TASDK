#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_S22Rifle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85999);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
