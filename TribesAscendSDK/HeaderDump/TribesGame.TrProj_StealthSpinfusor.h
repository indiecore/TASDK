#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_StealthSpinfusor : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(109204);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
