#pragma once
#include "TribesGame.TrStationCollision.h"
#include "TribesGame.TrPawn.h"
namespace UnrealScript
{
	class TrInventoryStationCollision : public TrStationCollision
	{
	public:
		bool CheckCanPawnUseStationNow(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryStationCollision.CheckCanPawnUseStationNow");
			byte params[8] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
