#pragma once
#include "TribesGame.GFxTrScene.h"
#include "TribesGame.TrSummaryHelper.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class GFxTrScene_MatchSummary : public GFxTrScene
	{
	public:
		struct ScoreSlot
		{
		public:
			ADD_STRUCT(ScriptString*, PlayerName, 20)
			ADD_STRUCT(int, PlayerID, 16)
			ADD_STRUCT(int, Credits, 12)
			ADD_STRUCT(int, Assists, 8)
			ADD_STRUCT(int, Rank, 4)
			ADD_STRUCT(int, Kills, 0)
		};
		ADD_BOOL(bUseSNS, 200, 0x1)
		ADD_STRUCT(ScriptArray<TrSummaryHelper::MVPAward>, MVPAwards, 1228)
		ADD_STRUCT(ScriptArray<TrSummaryHelper::MVPAward>, MVPAccolades, 1240)
		ADD_OBJECT(TrSummaryHelper, SummaryHelper, 1252)
		ADD_STRUCT(GFxTrScene_MatchSummary::ScoreSlot, Scoreboard, 204)
		ADD_STRUCT(int, Team2Score, 196)
		ADD_STRUCT(int, Team1Score, 192)
		ADD_STRUCT(int, MatchDate, 188)
		ADD_STRUCT(int, MatchDuration, 184)
		ADD_STRUCT(int, MatchGameType, 180)
		ADD_STRUCT(int, MatchMapId, 176)
		ADD_STRUCT(int, MatchId, 172)
		ADD_STRUCT(int, WinningTeam, 168)
		ADD_OBJECT(GFxObject, ScoreboardDataList, 164)
		ADD_OBJECT(GFxObject, AccoladeDataList, 160)
		ADD_OBJECT(GFxObject, AwardDataList, 156)
		ADD_OBJECT(GFxObject, MiscDataList, 152)
		ADD_STRUCT(int, ScoreboardDataCount, 148)
		ADD_STRUCT(int, AccoladeDataCount, 144)
		ADD_STRUCT(int, AwardDataCount, 140)
		ADD_STRUCT(int, MiscDataCount, 136)
		ADD_STRUCT(int, SCOREBOARD_SIZE, 132)
		int CreditsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63292);
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63312);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63313);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63315);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadTeamStatsData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63604);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamAccoladeData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63609);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamScoreboardData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63612);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamMiscData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63615);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAward(int PlayerID, int AwardId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63617);
			byte params[12] = { NULL };
			*(int*)params = PlayerID;
			*(int*)&params[4] = AwardId;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAccolade(int PlayerID, int AccoladeId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63630);
			byte params[12] = { NULL };
			*(int*)params = PlayerID;
			*(int*)&params[4] = AccoladeId;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddScoreSlot(ScriptString* PlayerName, int Kills, int Assists, int Credits, int Rank)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63638);
			byte params[28] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(int*)&params[12] = Kills;
			*(int*)&params[16] = Assists;
			*(int*)&params[20] = Credits;
			*(int*)&params[24] = Rank;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMiscData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63645);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* FormatResult(int aWinningTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63647);
			byte params[16] = { NULL };
			*(int*)params = aWinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63652);
			byte params[16] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* FindPlayerName(int PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63658);
			byte params[16] = { NULL };
			*(int*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PopulateScoreboardDataFromGRI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63662);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
