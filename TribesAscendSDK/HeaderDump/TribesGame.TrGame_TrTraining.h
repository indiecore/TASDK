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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91060);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91063);
			byte params[6] = { NULL };
			*params = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91067);
			byte params[5] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91070);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AutoEndGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91078);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(91079);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
