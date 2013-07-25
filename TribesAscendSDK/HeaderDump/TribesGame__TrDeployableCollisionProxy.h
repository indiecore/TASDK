#pragma once
#include "TribesGame__TrCollisionProxy.h"
#include "Engine__Pawn.h"
namespace UnrealScript
{
	class TrDeployableCollisionProxy : public TrCollisionProxy
	{
	public:
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableCollisionProxy.OnPawnAdded");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployableCollisionProxy.OnPawnRemoved");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
