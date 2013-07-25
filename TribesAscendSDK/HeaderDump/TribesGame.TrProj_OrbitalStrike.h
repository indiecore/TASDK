#pragma once
#include "TribesGame.TrProj_CallInBase.h"
namespace UnrealScript
{
	class TrProj_OrbitalStrike : public TrProj_CallInBase
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_OrbitalStrike.SpawnFlightEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
