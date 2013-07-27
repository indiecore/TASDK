#pragma once
#include "TribesGame.TrProj_CallInBase.h"
namespace UnrealScript
{
	class TrProj_OrbitalStrike : public TrProj_CallInBase
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108824);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
