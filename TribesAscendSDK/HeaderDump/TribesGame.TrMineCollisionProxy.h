#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class TrMineCollisionProxy : public TrCollisionProxy
	{
	public:
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMineCollisionProxy.OnPawnAdded");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMineCollisionProxy.OnPawnRemoved");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
