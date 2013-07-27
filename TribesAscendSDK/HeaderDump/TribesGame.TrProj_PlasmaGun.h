#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_PlasmaGun : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108852);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
