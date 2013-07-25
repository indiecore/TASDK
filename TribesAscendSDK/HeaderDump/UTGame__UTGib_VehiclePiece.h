#pragma once
#include "UTGame__UTGib_Vehicle.h"
namespace UnrealScript
{
	class UTGib_VehiclePiece : public UTGib_Vehicle
	{
	public:
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGib_VehiclePiece.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
