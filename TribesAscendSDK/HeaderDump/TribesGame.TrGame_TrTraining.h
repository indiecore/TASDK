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
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.PickTeam");
			byte params[6] = { NULL };
			params[0] = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.PickTeamForMigration");
			byte params[5] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrTraining.EndGame");
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
