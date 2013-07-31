#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_HeavySpinfusor : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108488);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
