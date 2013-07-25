#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
namespace UnrealScript
{
	class TrGame_TRTDM : public TrGame
	{
	public:
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTDM.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRTDM.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
