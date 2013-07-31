#pragma once
#include "Engine.Projectile.h"
#include "Engine.Volume.h"
namespace UnrealScript
{
	class TriggerVolume : public Volume
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14906);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14907);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
