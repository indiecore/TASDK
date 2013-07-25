#pragma once
#include "TribesGame__TrProjectile.h"
namespace UnrealScript
{
	class TrProj_PlasmaGun : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_PlasmaGun.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
