#pragma once
#include "TribesGame__TrStationCollision.h"
#include "TribesGame__TrPawn.h"
namespace UnrealScript
{
	class TrInventoryStationCollision : public TrStationCollision
	{
	public:
		bool CheckCanPawnUseStationNow(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStationCollision.CheckCanPawnUseStationNow");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
