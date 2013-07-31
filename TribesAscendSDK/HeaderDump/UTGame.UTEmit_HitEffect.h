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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47370);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(ScriptName*)&params[4] = NewBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnBaseDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47373);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
