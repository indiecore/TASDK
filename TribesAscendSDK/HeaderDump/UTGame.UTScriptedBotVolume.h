#pragma once
#include "Engine.PhysicsVolume.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTScriptedBotVolume : public PhysicsVolume
	{
	public:
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTScriptedBotVolume.PawnLeavingVolume");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
