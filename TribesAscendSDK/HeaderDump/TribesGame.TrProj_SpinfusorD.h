#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_SpinfusorD : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
