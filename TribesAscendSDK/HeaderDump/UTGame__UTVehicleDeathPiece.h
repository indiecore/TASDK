#pragma once
#include "UTGame__UTGib_Vehicle.h"
namespace UnrealScript
{
	class UTVehicleDeathPiece : public UTGib_Vehicle
	{
	public:
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTVehicleDeathPiece.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
