#pragma once
#include "TribesGame.GFxTrScene.h"
#include "TribesGame.TrSummaryHelper.h"
#include "GFxUI.GFxObject.h"
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
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.ClearSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearEarnedBadgeValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.ClearEarnedBadgeValue");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.SummaryReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadXPData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.LoadXPData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadPlayerStatsData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerStatsData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadPlayerAccoladeData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerAccoladeData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadPlayerMiscData(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.LoadPlayerMiscData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAward(int AwardId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.AddAward");
			byte* params = (byte*)malloc(8);
			*(int*)params = AwardId;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddBadge(
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.BadgeStruct'!
void* Badge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.AddBadge");
			byte* params = (byte*)malloc(52);
			*(
// WARNING: Unknown structure type 'ScriptStruct PlatformCommon.TgPlayerProfile.BadgeStruct'!
void**)params = Badge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAccolade(int AccoladeId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.AddAccolade");
			byte* params = (byte*)malloc(8);
			*(int*)params = AccoladeId;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMiscData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.AddMiscData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetFlagGrabCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.GetFlagGrabCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetFlagReturnCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrScene_PlayerSummary.GetFlagReturnCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
