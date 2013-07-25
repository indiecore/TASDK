#pragma once
#include "TribesGame__TrProjectile.h"
namespace UnrealScript
{
	class TrProj_HeavyTwinfusor : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_HeavyTwinfusor.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
