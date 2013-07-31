#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.Projectile.h"
namespace UnrealScript
{
	class TrDevice_SN7 : public TrDevice
	{
	public:
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(86137);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
	};
}
