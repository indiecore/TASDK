#pragma once
#include "TribesGame__TrVehicle_BaseFlying.h"
#include "UTGame__UTPawn.h"
namespace UnrealScript
{
	class TrVehicle_Shrike : public TrVehicle_BaseFlying
	{
	public:
		void SitDriver(class UTPawn* UTP, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicle_Shrike.SitDriver");
			byte* params = (byte*)malloc(8);
			*(class UTPawn**)params = UTP;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
