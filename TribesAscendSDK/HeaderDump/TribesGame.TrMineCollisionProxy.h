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
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMineCollisionProxy.OnPawnRemoved");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
