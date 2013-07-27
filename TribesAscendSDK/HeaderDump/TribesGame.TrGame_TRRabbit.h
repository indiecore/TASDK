#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrFlagRabbit.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRRabbit : public TrGame
	{
	public:
		class ScoreStruct
		{
		public:
			ADD_STRUCT(float, Score, 4)
			ADD_OBJECT(TrPlayerController, C, 0)
		};
		ADD_OBJECT(PlayerReplicationInfo, m_HolderPRI, 1464)
		ADD_OBJECT(PlayerReplicationInfo, m_Leader, 1468)
		ADD_STRUCT(float, m_fScoreInterval, 1460)
		ADD_OBJECT(TrFlagRabbit, m_Flag, 1456)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterFlag(class TrFlagRabbit* F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.RegisterFlag");
			byte params[4] = { NULL };
			*(class TrFlagRabbit**)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpFlag(class Controller* Holder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickedUpFlag");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Holder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DroppedFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.DroppedFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.SetTeam");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreFlagTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreFlagTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreFlagHold(bool firstPass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreFlagHold");
			byte params[4] = { NULL };
			*(bool*)&params[0] = firstPass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreKill");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangePreviousRabbitTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ChangePreviousRabbitTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		TrGame_TRRabbit::ScoreStruct MakeScoreStruct(class TrPlayerController* C, float Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.MakeScoreStruct");
			byte params[16] = { NULL };
			*(class TrPlayerController**)&params[0] = C;
			*(float*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrGame_TRRabbit::ScoreStruct*)&params[8];
		}
		bool SortPlayerScores(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.SortPlayerScores");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.CheckScore");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.CheckEndGame");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickTeam");
			byte params[6] = { NULL };
			params[0] = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickTeamForMigration");
			byte params[5] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PlayEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.DiscardInventory");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			*(class Controller**)&params[4] = Killer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.RatePlayerStart");
			byte params[13] = { NULL };
			*(class PlayerStart**)&params[0] = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.GetGameTypeId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
