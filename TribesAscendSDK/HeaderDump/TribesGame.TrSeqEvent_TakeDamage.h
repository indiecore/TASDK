#pragma once
#include "Engine.SeqEvent_TakeDamage.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrSeqEvent_TakeDamage : public SeqEvent_TakeDamage
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqEvent_TakeDamage.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void HandleDamage(class Actor* InOriginator, class Actor* InInstigator, ScriptClass* inDamageType, int inAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqEvent_TakeDamage.HandleDamage");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(ScriptClass**)&params[8] = inDamageType;
			*(int*)&params[12] = inAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
