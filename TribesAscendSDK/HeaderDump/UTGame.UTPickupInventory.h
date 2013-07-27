#pragma once
#include "UTGame.UTInventory.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTPickupInventory : public UTInventory
	{
	public:
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPickupInventory.BotDesireability");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = PickupHolder;
			*(class Pawn**)&params[4] = P;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
	};
}
