#pragma once
#include "UTGame__UTMutator.h"
#include "Engine__Pawn.h"
#include "Engine__Actor.h"
namespace UnrealScript
{
	class UTMutator_SuperBerserk : public UTMutator
	{
	public:
		void ModifyPlayer(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_SuperBerserk.ModifyPlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMutator_SuperBerserk.CheckReplacement");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
