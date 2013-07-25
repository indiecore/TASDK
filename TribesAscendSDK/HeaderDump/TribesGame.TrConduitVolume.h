#pragma once
#include "TribesGame.TrPhysicsVolume.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrConduitVolume : public TrPhysicsVolume
	{
	public:
		void PawnEnteredVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrConduitVolume.PawnEnteredVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrConduitVolume.PawnLeavingVolume");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
