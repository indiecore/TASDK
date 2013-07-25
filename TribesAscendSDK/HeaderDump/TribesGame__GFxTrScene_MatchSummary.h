#pragma once
#include "TribesGame__TrPlayerReplicationInfo.h"
#include "TribesGame__GFxTrScene.h"
#include "TribesGame__TrSummaryHelper.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrScene_MatchSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.GFxTrScene_MatchSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrScene_MatchSummary." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrScene_MatchSummary : public GFxTrScene
	{
	public:
		ADD_VAR(::BoolProperty, bUseSNS, 0x1)
		ADD_OBJECT(TrSummaryHelper, SummaryHelper)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GFxTrScene_MatchSummary.ScoreSlot' for the property named 'Scoreboard'!
		ADD_VAR(::IntProperty, Team2Score, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Team1Score, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchDate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchDuration, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchGameType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchMapId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MatchId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, WinningTeam, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, ScoreboardDataList)
		ADD_OBJECT(GFxObject, AccoladeDataList)
		ADD_OBJECT(GFxObject, AwardDataList)
		ADD_OBJECT(GFxObject, MiscDataList)
		ADD_VAR(::IntProperty, ScoreboardDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AccoladeDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AwardDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MiscDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SCOREBOARD_SIZE, 0xFFFFFFFF)
		int CreditsSort(class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.CreditsSort");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerReplicationInfo**)params = A;
			*(class TrPlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadTeamAccoladeData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamAccoladeData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadTeamScoreboardData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamScoreboardData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadTeamMiscData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.LoadTeamMiscData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAward(int PlayerID, int AwardId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddAward");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlayerID;
			*(int*)(params + 4) = AwardId;
			*(int*)(params + 8) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAccolade(int PlayerID, int AccoladeId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddAccolade");
			byte* params = (byte*)malloc(12);
			*(int*)params = PlayerID;
			*(int*)(params + 4) = AccoladeId;
			*(int*)(params + 8) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddScoreSlot(ScriptArray<wchar_t> PlayerName, int Kills, int Assists, int Credits, int Rank)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddScoreSlot");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(int*)(params + 12) = Kills;
			*(int*)(params + 16) = Assists;
			*(int*)(params + 20) = Credits;
			*(int*)(params + 24) = Rank;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMiscData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.AddMiscData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> FormatResult(int aWinningTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FormatResult");
			byte* params = (byte*)malloc(16);
			*(int*)params = aWinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> FormatTime(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FormatTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> FindPlayerName(int PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.FindPlayerName");
			byte* params = (byte*)malloc(16);
			*(int*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void PopulateScoreboardDataFromGRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_MatchSummary.PopulateScoreboardDataFromGRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
