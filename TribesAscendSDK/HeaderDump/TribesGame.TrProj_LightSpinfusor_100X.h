#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_LightSpinfusor_100X : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108608);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
