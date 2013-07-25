#pragma once
#include "Engine__PhysicsVolume.h"
namespace UnrealScript
{
	class DefaultPhysicsVolume : public PhysicsVolume
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DefaultPhysicsVolume.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
