#pragma once
#include "Engine__PhysicsVolume.h"
#include "Engine__Pawn.h"
namespace UnrealScript
{
	class UTScriptedBotVolume : public PhysicsVolume
	{
	public:
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTScriptedBotVolume.PawnLeavingVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
