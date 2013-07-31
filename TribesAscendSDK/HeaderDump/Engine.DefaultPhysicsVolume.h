#pragma once
#include "Engine.PhysicsVolume.h"
namespace UnrealScript
{
	class DefaultPhysicsVolume : public PhysicsVolume
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14476);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
