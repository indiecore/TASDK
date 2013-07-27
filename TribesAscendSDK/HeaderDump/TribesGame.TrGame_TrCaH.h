#pragma once
#include "TribesGame.TrGame.h"
#include "TribesGame.TrCaHCapturePoint.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrPawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
		ADD_STRUCT(int, m_nPostCapturePointTime, 1476)
		ADD_STRUCT(int, m_nTicketCountTime, 1472)
		ADD_STRUCT(ScriptArray<class TrCaHCapturePoint*>, m_CapturePoints, 1456)
		ADD_STRUCT(int, m_5PointGoalScore, 1488)
		ADD_STRUCT(int, m_4PointGoalScore, 1484)
		ADD_STRUCT(int, m_3PointGoalScore, 1480)
		ADD_STRUCT(int, m_nRemainingTicketTime, 1468)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.SetTeam");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.Logout");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ScoreKill");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.CheckScore");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.GotoPendingRoundStartTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.CheckEndGame");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AwardPoint(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.AwardPoint");
			byte params[1] = { NULL };
			params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.RestartPlayer");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.GetGameTypeId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void OnCapturePointHeld(class TrCaHCapturePoint* HeldPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.OnCapturePointHeld");
			byte params[4] = { NULL };
			*(class TrCaHCapturePoint**)&params[0] = HeldPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCapturePointOwnershipChanged(class TrCaHCapturePoint* PointThatChanged, class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.OnCapturePointOwnershipChanged");
			byte params[8] = { NULL };
			*(class TrCaHCapturePoint**)&params[0] = PointThatChanged;
			*(class TrPawn**)&params[4] = TRP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.RatePlayerStart");
			byte params[13] = { NULL };
			*(class PlayerStart**)&params[0] = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ChoosePlayerStart");
			byte params[9] = { NULL };
			*(class Controller**)&params[0] = Player;
			params[4] = InTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerStart**)&params[8];
		}
	};
}
#undef ADD_STRUCT
