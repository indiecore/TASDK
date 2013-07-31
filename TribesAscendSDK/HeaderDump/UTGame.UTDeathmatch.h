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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42815);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45130);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
