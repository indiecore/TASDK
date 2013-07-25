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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void HandleDamage(class Actor* InOriginator, class Actor* InInstigator, ScriptClass* inDamageType, int inAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqEvent_TakeDamage.HandleDamage");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = InOriginator;
			*(class Actor**)(params + 4) = InInstigator;
			*(ScriptClass**)(params + 8) = inDamageType;
			*(int*)(params + 12) = inAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
