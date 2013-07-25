#pragma once
#include "UTGame.UTGame.h"
#include "UTGame.UTBot.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTDeathmatch : public UTGame
	{
	public:
		bool WantsPickups(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDeathmatch.WantsPickups");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDeathmatch.GetHandicapNeed");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
