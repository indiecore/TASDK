#pragma once
#include "UTGame.UTEmitter.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTEmit_HitEffect : public UTEmitter
	{
	public:
		void AttachTo(class Pawn* P, ScriptName NewBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmit_HitEffect.AttachTo");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(ScriptName*)&params[4] = NewBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnBaseDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmit_HitEffect.PawnBaseDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
