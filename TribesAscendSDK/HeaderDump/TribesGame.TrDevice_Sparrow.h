#pragma once
#include "TribesGame.TrDevice.h"
namespace UnrealScript
{
	class TrDevice_Sparrow : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86200);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
