#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_Eagle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81274);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
