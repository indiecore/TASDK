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
		class ScoreSlot
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.CreditsSort");
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)&params[0] = A;
			*(class TrPlayerReplicationInfo**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.ClearSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.SummaryReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadTeamStatsData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamStatsData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamAccoladeData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamAccoladeData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamScoreboardData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamScoreboardData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadTeamMiscData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamMiscData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAward(int PlayerID, int AwardId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddAward");
			byte params[12] = { NULL };
			*(int*)&params[0] = PlayerID;
			*(int*)&params[4] = AwardId;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAccolade(int PlayerID, int AccoladeId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddAccolade");
			byte params[12] = { NULL };
			*(int*)&params[0] = PlayerID;
			*(int*)&params[4] = AccoladeId;
			*(int*)&params[8] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddScoreSlot(ScriptString* PlayerName, int Kills, int Assists, int Credits, int Rank)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddScoreSlot");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(int*)&params[12] = Kills;
			*(int*)&params[16] = Assists;
			*(int*)&params[20] = Credits;
			*(int*)&params[24] = Rank;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMiscData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddMiscData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* FormatResult(int aWinningTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FormatResult");
			byte params[16] = { NULL };
			*(int*)&params[0] = aWinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FormatTime");
			byte params[16] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* FindPlayerName(int PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FindPlayerName");
			byte params[16] = { NULL };
			*(int*)&params[0] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PopulateScoreboardDataFromGRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.PopulateScoreboardDataFromGRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
