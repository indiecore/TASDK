#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Controller.h"
namespace UnrealScript
{
	class TrGame_TrTraining : public TrGame
	{
	public:
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.PickTeam");
			byte* params = (byte*)malloc(6);
			*params = Num;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.PickTeamForMigration");
			byte* params = (byte*)malloc(5);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AutoEndGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.AutoEndGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.PlayEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
