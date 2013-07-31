#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_Buckler : public TrProjectile
	{
	public:
		void SpawnFlightEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108164);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
