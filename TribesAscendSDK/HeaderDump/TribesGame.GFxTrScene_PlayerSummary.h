#pragma once
#include "TribesGame.GFxTrScene.h"
#include "GFxUI.GFxObject.h"
#include "PlatformCommon.TgPlayerProfile.h"
#include "TribesGame.TrSummaryHelper.h"
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
	class GFxTrScene_PlayerSummary : public GFxTrScene
	{
	public:
		ADD_BOOL(bSummaryReady, 228, 0x4)
		ADD_BOOL(bSummaryTweened, 228, 0x8)
		ADD_BOOL(bSummaryXPTweened, 228, 0x10)
		ADD_BOOL(bFirstWin, 228, 0x2)
		ADD_BOOL(bUseSNS, 228, 0x1)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, AwardData, 232)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, accoladeData, 244)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::BadgeStruct>, EarnedBadges, 256)
		ADD_OBJECT(TrSummaryHelper, SummaryHelper, 268)
		ADD_STRUCT(int, EarnedBadgeValue, 224)
		ADD_STRUCT(int, XPBoost, 220)
		ADD_STRUCT(int, XPVIP, 216)
		ADD_STRUCT(int, XPPerf, 212)
		ADD_STRUCT(int, XPBase, 208)
		ADD_STRUCT(ScriptString*, PlayerName, 196)
		ADD_STRUCT(int, RankGained, 192)
		ADD_STRUCT(int, RankBase, 188)
		ADD_STRUCT(int, TopPlayedClass, 184)
		ADD_STRUCT(int, Credits, 180)
		ADD_STRUCT(int, Assists, 176)
		ADD_STRUCT(int, Deaths, 172)
		ADD_STRUCT(int, Kills, 168)
		ADD_STRUCT(int, PlayerID, 164)
		ADD_OBJECT(GFxObject, AccoladeDataList, 160)
		ADD_OBJECT(GFxObject, AwardDataList, 156)
		ADD_OBJECT(GFxObject, MiscDataList, 152)
		ADD_STRUCT(int, AccoladeDataCount, 148)
		ADD_STRUCT(int, AwardDataCount, 144)
		ADD_STRUCT(int, MiscDataCount, 140)
		ADD_STRUCT(int, SkillClassId, 136)
		ADD_STRUCT(int, AWARD_TIER_SIZE, 132)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63709);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63710);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearEarnedBadgeValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63712);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63714);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadXPData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63716);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadPlayerStatsData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63718);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadPlayerAccoladeData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63723);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadPlayerMiscData(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63726);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAward(int AwardId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63728);
			byte params[8] = { NULL };
			*(int*)params = AwardId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddBadge(TgPlayerProfile::BadgeStruct Badge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63734);
			byte params[52] = { NULL };
			*(TgPlayerProfile::BadgeStruct*)params = Badge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAccolade(int AccoladeId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63737);
			byte params[8] = { NULL };
			*(int*)params = AccoladeId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMiscData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63742);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetFlagGrabCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63756);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetFlagReturnCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(63760);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
