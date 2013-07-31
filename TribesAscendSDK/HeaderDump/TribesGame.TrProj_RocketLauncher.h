#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_RocketLauncher : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109023);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
