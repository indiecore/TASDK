#pragma once
#include "TribesGame.TrProjectile.h"
namespace UnrealScript
{
	class TrProj_AntiAirTurret : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(107790);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
