#pragma once
#include "UTGame.UTGib_Vehicle.h"
namespace UnrealScript
{
	class UTGib_VehiclePiece : public UTGib_Vehicle
	{
	public:
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47952);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
