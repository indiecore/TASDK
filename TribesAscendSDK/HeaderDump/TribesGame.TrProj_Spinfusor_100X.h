#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_Spinfusor_100X : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109186);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
