#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Pawn.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class UTMutator_SuperBerserk : public UTMutator
	{
	public:
		void ModifyPlayer(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48637);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48640);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
