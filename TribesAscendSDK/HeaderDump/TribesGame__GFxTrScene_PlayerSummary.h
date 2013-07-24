#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrScene_PlayerSummary." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrScene_PlayerSummary." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrScene_PlayerSummary : public GFxTrScene
	{
	public:
		ADD_VAR(::BoolProperty, bSummaryReady, 0x4)
		ADD_VAR(::BoolProperty, bSummaryTweened, 0x8)
		ADD_VAR(::BoolProperty, bSummaryXPTweened, 0x10)
		ADD_VAR(::BoolProperty, bFirstWin, 0x2)
		ADD_VAR(::BoolProperty, bUseSNS, 0x1)
		ADD_OBJECT(TrSummaryHelper, SummaryHelper)
		ADD_VAR(::IntProperty, EarnedBadgeValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPBoost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPVIP, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPPerf, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RankGained, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RankBase, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TopPlayedClass, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Credits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Assists, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Deaths, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Kills, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, AccoladeDataList)
		ADD_OBJECT(GFxObject, AwardDataList)
		ADD_OBJECT(GFxObject, MiscDataList)
		ADD_VAR(::IntProperty, AccoladeDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AwardDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MiscDataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SkillClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AWARD_TIER_SIZE, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
