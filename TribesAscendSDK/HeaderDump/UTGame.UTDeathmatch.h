#pragma once
#include "UTGame.UTGame.h"
#include "UTGame.UTBot.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTDeathmatch : public UTGame
	{
	public:
		bool WantsPickups(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDeathmatch.WantsPickups");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDeathmatch.GetHandicapNeed");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
