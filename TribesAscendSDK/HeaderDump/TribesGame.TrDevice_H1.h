#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_H1 : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81374);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
