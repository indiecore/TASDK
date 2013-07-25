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
		// Here lies the not-yet-implemented method 'CreditsSort'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ClearSummary'
		// Here lies the not-yet-implemented method 'SummaryReady'
		// Here lies the not-yet-implemented method 'LoadTeamStatsData'
		// Here lies the not-yet-implemented method 'LoadTeamAccoladeData'
		// Here lies the not-yet-implemented method 'LoadTeamScoreboardData'
		// Here lies the not-yet-implemented method 'LoadTeamMiscData'
		// Here lies the not-yet-implemented method 'AddAward'
		// Here lies the not-yet-implemented method 'AddAccolade'
		// Here lies the not-yet-implemented method 'AddScoreSlot'
		// Here lies the not-yet-implemented method 'AddMiscData'
		// Here lies the not-yet-implemented method 'FormatResult'
		// Here lies the not-yet-implemented method 'FormatTime'
		// Here lies the not-yet-implemented method 'FindPlayerName'
		// Here lies the not-yet-implemented method 'PopulateScoreboardDataFromGRI'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
