#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTMutator_BigHead : public UTMutator
	{
	public:
		void ModifyPlayer(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_BigHead.ModifyPlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
