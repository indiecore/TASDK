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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110940);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void HandleDamage(class Actor* InOriginator, class Actor* InInstigator, ScriptClass* inDamageType, int inAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110942);
			byte params[16] = { NULL };
			*(class Actor**)params = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(ScriptClass**)&params[8] = inDamageType;
			*(int*)&params[12] = inAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
