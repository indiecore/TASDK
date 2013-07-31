#pragma once
#include "UTGame.UTGib_Vehicle.h"
namespace UnrealScript
{
	class UTVehicleDeathPiece : public UTGib_Vehicle
	{
	public:
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49677);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
