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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Shrike.SitDriver");
			byte params[8] = { NULL };
			*(class UTPawn**)&params[0] = UTP;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
