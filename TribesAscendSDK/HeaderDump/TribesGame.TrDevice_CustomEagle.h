#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_CustomEagle : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81235);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
