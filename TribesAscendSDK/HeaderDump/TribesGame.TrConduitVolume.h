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
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeavingVolume(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrConduitVolume.PawnLeavingVolume");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
