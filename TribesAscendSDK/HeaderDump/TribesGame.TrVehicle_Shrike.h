#pragma once
#include "TribesGame.TrVehicle_BaseFlying.h"
#include "UTGame.UTPawn.h"
namespace UnrealScript
{
	class TrVehicle_Shrike : public TrVehicle_BaseFlying
	{
	public:
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114912);
			byte params[8] = { NULL };
			*(class UTPawn**)params = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
