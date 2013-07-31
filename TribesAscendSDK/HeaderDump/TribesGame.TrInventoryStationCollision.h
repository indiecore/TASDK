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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98341);
			byte params[8] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
