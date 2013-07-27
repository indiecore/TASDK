#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrPowerGenerator.h"
namespace UnrealScript
{
	class TrGame_TrDaD : public TrGame
	{
	public:
		void ResetScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90706);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90707);
			byte params[12] = { NULL };
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90711);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90713);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90714);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90715);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetRound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90717);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90725);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90728);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90731);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90734);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90735);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnCoreBlownUp(byte Team)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90739);
			byte params[1] = { NULL };
			*params = Team;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90759);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90763);
			byte params[4] = { NULL };
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90765);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void OnGeneratorPowerChange(class TrPowerGenerator* G)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90767);
			byte params[4] = { NULL };
			*(class TrPowerGenerator**)params = G;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
