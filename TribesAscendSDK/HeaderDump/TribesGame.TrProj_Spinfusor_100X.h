#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_Spinfusor_100X : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_Spinfusor_100X.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
