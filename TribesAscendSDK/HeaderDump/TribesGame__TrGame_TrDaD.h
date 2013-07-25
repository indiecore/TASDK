#pragma once
#include "TribesGame__TrGame.h"
#include "Engine__Controller.h"
#include "UTGame__UTTeamInfo.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrPowerGenerator.h"
namespace UnrealScript
{
	class TrGame_TrDaD : public TrGame
	{
	public:
		void ResetScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.ResetScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.SetTeam");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)(params + 4) = NewTeam;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.RespawnPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetRound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.ResetRound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.DetermineWinningTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.GotoPendingRoundStartTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void OnCoreBlownUp(byte Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.OnCoreBlownUp");
			byte* params = (byte*)malloc(1);
			*params = Team;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.SendMatchCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void OnGeneratorPowerChange(class TrPowerGenerator* G)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrDaD.OnGeneratorPowerChange");
			byte* params = (byte*)malloc(4);
			*(class TrPowerGenerator**)params = G;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
