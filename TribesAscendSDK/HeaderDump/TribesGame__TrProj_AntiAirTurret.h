#pragma once
#include "TribesGame__TrProjectile.h"
namespace UnrealScript
{
	class TrProj_AntiAirTurret : public TrProjectile
	{
	public:
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_AntiAirTurret.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
