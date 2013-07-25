#pragma once
#include "TribesGame__TrProjectile.h"
namespace UnrealScript
{
	class TrProj_LightSpinfusor : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_LightSpinfusor.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
