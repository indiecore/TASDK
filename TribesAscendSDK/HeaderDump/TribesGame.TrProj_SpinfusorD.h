#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_SpinfusorD : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_SpinfusorD.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
