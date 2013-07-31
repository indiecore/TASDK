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
		struct ScoreStruct
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90778);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterFlag(class TrFlagRabbit* F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90780);
			byte params[4] = { NULL };
			*(class TrFlagRabbit**)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PickedUpFlag(class Controller* Holder)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90783);
			byte params[4] = { NULL };
			*(class Controller**)params = Holder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DroppedFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90786);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90789);
			byte params[12] = { NULL };
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreFlagTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreFlagHold(bool firstPass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90795);
			byte params[4] = { NULL };
			*(bool*)params = firstPass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90798);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangePreviousRabbitTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90801);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		TrGame_TRRabbit::ScoreStruct MakeScoreStruct(class TrPlayerController* C, float Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90802);
			byte params[16] = { NULL };
			*(class TrPlayerController**)params = C;
			*(float*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrGame_TRRabbit::ScoreStruct*)&params[8];
		}
		bool SortPlayerScores(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90807);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90820);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90824);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90831);
			byte params[6] = { NULL };
			*params = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90835);
			byte params[5] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90838);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90843);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			*(class Controller**)&params[4] = Killer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90848);
			byte params[13] = { NULL };
			*(class PlayerStart**)params = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90854);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
