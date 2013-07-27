#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_PlasmaCannon : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108840);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
