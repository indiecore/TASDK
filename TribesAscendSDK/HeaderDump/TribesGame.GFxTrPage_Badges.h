#pragma once
#include "TribesGame.GFxTrPage.h"
#include "TribesGame.GFxTrAction.h"
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Badges : public GFxTrPage
	{
	public:
		static const auto STAT_GAME_MAP = 200001;
		static const auto STAT_GAME_TYPE = 200002;
		static const auto STAT_GAME_TIME = 200003;
		static const auto STAT_GAME_OVERTIME = 200004;
		static const auto STAT_GAME_WINNER = 200005;
		static const auto STAT_CLASS_TYPE = 201000;
		static const auto STAT_CLASS_SCORE = 201001;
		static const auto STAT_CLASS_KILLS = 201002;
		static const auto STAT_CLASS_DEATHS = 201003;
		static const auto STAT_CLASS_ASSISTS = 201004;
		static const auto STAT_CLASS_CREDITS_EARNED = 201005;
		static const auto STAT_CLASS_CREDITS_SPENT = 201006;
		static const auto STAT_WEAPON_TYPE = 202000;
		static const auto STAT_WEAPON_DAMAGE = 202001;
		static const auto STAT_WEAPON_KILLS = 202002;
		static const auto STAT_WEAPON_SHOTS = 202003;
		static const auto STAT_WEAPON_HITS = 202004;
		static const auto STAT_WEAPON_TIME = 202005;
		static const auto STAT_WEAPON_DISTANCE = 202006;
		static const auto STAT_ACO_KS_FIVE = 203001;
		static const auto STAT_ACO_KS_TEN = 203002;
		static const auto STAT_ACO_KS_FIFTEEN = 203003;
		static const auto STAT_ACO_KS_TWENTY = 203004;
		static const auto STAT_ACO_KS_TWENTYFIVE = 203005;
		static const auto STAT_ACO_KS_FIVE_SNIPING = 203006;
		static const auto STAT_ACO_KS_TEN_SNIPING = 203007;
		static const auto STAT_ACO_KS_FIFTEEN_SNIPING = 203008;
		static const auto STAT_ACO_KS_FIVE_EXPLOSIVE = 203009;
		static const auto STAT_ACO_KS_TEN_EXPLOSIVE = 203010;
		static const auto STAT_ACO_KS_FIFTEEN_EXPLOSIVE = 203011;
		static const auto STAT_ACO_KS_FIVE_SPINFUSOR = 203012;
		static const auto STAT_ACO_KS_TEN_SPINFUSOR = 203013;
		static const auto STAT_ACO_KS_FIFTEEN_SPINFUSOR = 203014;
		static const auto STAT_ACO_MK_DOUBLE = 203015;
		static const auto STAT_ACO_MK_TRIPLE = 203016;
		static const auto STAT_ACO_MK_QUATRA = 203017;
		static const auto STAT_ACO_MK_ULTRA = 203018;
		static const auto STAT_ACO_MK_TEAM = 203019;
		static const auto STAT_ACO_NOJOY = 203020;
		static const auto STAT_ACO_REVENGE = 203021;
		static const auto STAT_ACO_AFTERMATH = 203022;
		static const auto STAT_ACO_FIRSTBLOOD = 203023;
		static const auto STAT_ACO_BLUEPLATESPECIAL = 203024;
		static const auto STAT_ACO_STICKYKILL = 203025;
		static const auto STAT_ACO_HEADSHOT = 203026;
		static const auto STAT_ACO_ARTILLERYSTRIKE = 203027;
		static const auto STAT_ACO_MELEE = 203028;
		static const auto STAT_ACO_ROADKILL = 203029;
		static const auto STAT_ACO_FLAG_CAPTURE = 203030;
		static const auto STAT_ACO_FLAG_GRAB = 203031;
		static const auto STAT_ACO_BK_GEN = 203032;
		static const auto STAT_ACO_RABBITKILL = 203033;
		static const auto STAT_ACO_KILLASRABBIT = 203034;
		static const auto STAT_ACO_FINALBLOW = 203035;
		static const auto STAT_ACO_REPAIR = 203036;
		static const auto STAT_ACO_BK_TURRET = 203037;
		static const auto STAT_ACO_ASSIST = 203039;
		static const auto STAT_ACO_FLAG_RETURN = 203040;
		static const auto STAT_ACO_BK_RADAR = 203041;
		static const auto STAT_ACO_FLAG_ASSIST = 203042;
		static const auto STAT_ACO_AIRMAIL = 203043;
		static const auto STAT_ACO_GAME_COMPLETE = 203044;
		static const auto STAT_ACO_GAME_WINNER = 203045;
		static const auto STAT_ACO_FLAG_GRABDM = 203046;
		static const auto STAT_ACO_FLAG_HOLDER = 203047;
		static const auto STAT_ACO_FLAG_KILLER = 203048;
		static const auto STAT_ACO_FLAG_GRABFAST = 203049;
		static const auto STAT_ACO_DEFENSE_GEN = 203050;
		static const auto STAT_ACO_DEFENSE_FLAG = 203051;
		static const auto STAT_ACO_VD_BIKE = 203052;
		static const auto STAT_ACO_VD_TANK = 203053;
		static const auto STAT_ACO_VD_SHRIKE = 203054;
		static const auto STAT_ACO_FLAG_GRABE = 203055;
		static const auto STAT_ACO_FLAG_GRABLLAMA = 203056;
		static const auto STAT_ACO_ASSIST_VEHICLE = 203057;
		static const auto STAT_ACO_FLAG_GRABULTRA = 203058;
		static const auto STAT_ACO_BENCHEM = 203059;
		static const auto STAT_ACO_DOUBLEDOWN = 203060;
		static const auto STAT_ACO_LASTMANSTANDING = 203061;
		static const auto STAT_ACO_MIRACLE = 203062;
		static const auto STAT_ACO_NOTAMONGEQUALS = 203063;
		static const auto STAT_ACO_ONEMANARMY = 203064;
		static const auto STAT_ACO_TRIBALHONOR = 203065;
		static const auto STAT_ACO_UNITEDWESTAND = 203066;
		static const auto STAT_ACO_HOLDTHELINE = 203067;
		static const auto STAT_ACO_CAPTUREANDHOLD = 203068;
		static const auto STAT_ACO_BASEASSIST = 203069;
		static const auto STAT_ACO_TURRETASSIST = 203070;
		static const auto STAT_ACO_HOTAIR = 203071;
		static const auto ACT_ACO_KS_FIVE = 56;
		static const auto ACT_ACO_KS_TEN = 63;
		static const auto ACT_ACO_KS_FIFTEEN = 55;
		static const auto ACT_ACO_KS_TWENTY = 64;
		static const auto ACT_ACO_KS_TWENTYFIVE = 65;
		static const auto ACT_ACO_KS_FIVE_SNIPING = 58;
		static const auto ACT_ACO_KS_TEN_SNIPING = 59;
		static const auto ACT_ACO_KS_FIFTEEN_SNIPING = 57;
		static const auto ACT_ACO_KS_FIVE_EXPLOSIVE = 53;
		static const auto ACT_ACO_KS_TEN_EXPLOSIVE = 54;
		static const auto ACT_ACO_KS_FIFTEEN_EXPLOSIVE = 52;
		static const auto ACT_ACO_KS_FIVE_SPINFUSOR = 61;
		static const auto ACT_ACO_KS_TEN_SPINFUSOR = 62;
		static const auto ACT_ACO_KS_FIFTEEN_SPINFUSOR = 60;
		static const auto ACT_ACO_MK_DOUBLE = 66;
		static const auto ACT_ACO_MK_TRIPLE = 67;
		static const auto ACT_ACO_MK_QUATRA = 68;
		static const auto ACT_ACO_MK_ULTRA = 69;
		static const auto ACT_ACO_MK_TEAM = 70;
		static const auto ACT_ACO_NOJOY = 89;
		static const auto ACT_ACO_REVENGE = 90;
		static const auto ACT_ACO_AFTERMATH = 73;
		static const auto ACT_ACO_FIRSTBLOOD = 78;
		static const auto ACT_ACO_BLUEPLATESPECIAL = 29;
		static const auto ACT_ACO_STICKYKILL = 92;
		static const auto ACT_ACO_HEADSHOT = 84;
		static const auto ACT_ACO_ARTILLERYSTRIKE = 75;
		static const auto ACT_ACO_MELEE = 88;
		static const auto ACT_ACO_ROADKILL = 91;
		static const auto ACT_ACO_FLAG_CAPTURE = 42;
		static const auto ACT_ACO_FLAG_GRAB = 80;
		static const auto ACT_ACO_BK_GEN = 48;
		static const auto ACT_ACO_RABBITKILL = 72;
		static const auto ACT_ACO_KILLASRABBIT = 71;
		static const auto ACT_ACO_FINALBLOW = 49;
		static const auto ACT_ACO_REPAIR = 39;
		static const auto ACT_ACO_BK_TURRET = 40;
		static const auto ACT_ACO_ASSIST = 76;
		static const auto ACT_ACO_FLAG_RETURN = 46;
		static const auto ACT_ACO_BK_RADAR = 38;
		static const auto ACT_ACO_FLAG_ASSIST = 41;
		static const auto ACT_ACO_AIRMAIL = 74;
		static const auto ACT_ACO_GAME_COMPLETE = 82;
		static const auto ACT_ACO_GAME_WINNER = 83;
		static const auto ACT_ACO_FLAG_HOLDER = 51;
		static const auto ACT_ACO_FLAG_KILLER = 81;
		static const auto ACT_ACO_FLAG_GRABFAST = 77;
		static const auto ACT_ACO_DEFENSE_GEN = 47;
		static const auto ACT_ACO_DEFENSE_FLAG = 79;
		static const auto ACT_ACO_VD_BIKE = 87;
		static const auto ACT_ACO_VD_TANK = 85;
		static const auto ACT_ACO_VD_SHRIKE = 86;
		static const auto ACT_ACO_FLAG_GRABE = 44;
		static const auto ACT_ACO_FLAG_GRABLLAMA = 45;
		static const auto ACT_ACO_ASSIST_VEHICLE = 94;
		static const auto ACT_ACO_FLAG_GRABULTRA = 93;
		static const auto ACT_ACO_BENCHEM = 30;
		static const auto ACT_ACO_DOUBLEDOWN = 31;
		static const auto ACT_ACO_LASTMANSTANDING = 32;
		static const auto ACT_ACO_MIRACLE = 33;
		static const auto ACT_ACO_NOTAMONGEQUALS = 34;
		static const auto ACT_ACO_ONEMANARMY = 35;
		static const auto ACT_ACO_TRIBALHONOR = 36;
		static const auto ACT_ACO_UNITEDWESTAND = 37;
		static const auto ACT_ACO_HOLDTHELINE = 117;
		static const auto ACT_ACO_CAPTUREANDHOLD = 118;
		static const auto ACT_ACO_BASEASSIST = 121;
		static const auto ACT_ACO_TURRETASSIST = 122;
		static const auto ACT_ACO_HOTAIR = 123;
		static const auto ACO_TYPE_GENERAL = 0;
		static const auto ACO_TYPE_COMBAT = 1;
		static const auto ACO_TYPE_FLAG = 2;
		static const auto ACO_TYPE_OBJECTIVE = 3;
		static const auto ACO_TYPE_SPREES = 4;
		static const auto ACO_TYPE_MULTIKILL = 5;
		static const auto ACO_TYPE_ARENA = 6;
		static const auto STAT_ACOW_KS_FIVE = 5;
		static const auto STAT_ACOW_KS_TEN = 12;
		static const auto STAT_ACOW_KS_FIFTEEN = 20;
		static const auto STAT_ACOW_KS_TWENTY = 40;
		static const auto STAT_ACOW_KS_TWENTYFIVE = 100;
		static const auto STAT_ACOW_KS_FIVE_SNIPING = 5;
		static const auto STAT_ACOW_KS_TEN_SNIPING = 12;
		static const auto STAT_ACOW_KS_FIFTEEN_SNIPING = 20;
		static const auto STAT_ACOW_KS_FIVE_EXPLOSIVE = 5;
		static const auto STAT_ACOW_KS_TEN_EXPLOSIVE = 12;
		static const auto STAT_ACOW_KS_FIFTEEN_EXPLOSIVE = 20;
		static const auto STAT_ACOW_KS_FIVE_SPINFUSOR = 5;
		static const auto STAT_ACOW_KS_TEN_SPINFUSOR = 12;
		static const auto STAT_ACOW_KS_FIFTEEN_SPINFUSOR = 20;
		static const auto STAT_ACOW_MK_DOUBLE = 6;
		static const auto STAT_ACOW_MK_TRIPLE = 20;
		static const auto STAT_ACOW_MK_QUATRA = 50;
		static const auto STAT_ACOW_MK_ULTRA = 75;
		static const auto STAT_ACOW_MK_TEAM = 100;
		static const auto STAT_ACOW_NOJOY = 3;
		static const auto STAT_ACOW_REVENGE = 1;
		static const auto STAT_ACOW_AFTERMATH = 1;
		static const auto STAT_ACOW_FIRSTBLOOD = 1;
		static const auto STAT_ACOW_BLUEPLATESPECIAL = 6;
		static const auto STAT_ACOW_STICKYKILL = 1;
		static const auto STAT_ACOW_HEADSHOT = 1;
		static const auto STAT_ACOW_ARTILLERYSTRIKE = 3;
		static const auto STAT_ACOW_MELEE = 1;
		static const auto STAT_ACOW_ROADKILL = 1;
		static const auto STAT_ACOW_FLAG_CAPTURE = 30;
		static const auto STAT_ACOW_FLAG_GRAB = 1;
		static const auto STAT_ACOW_BK_GEN = 2;
		static const auto STAT_ACOW_RABBITKILL = 1;
		static const auto STAT_ACOW_KILLASRABBIT = 1;
		static const auto STAT_ACOW_FINALBLOW = 4;
		static const auto STAT_ACOW_REPAIR = 1;
		static const auto STAT_ACOW_BK_TURRET = 1;
		static const auto STAT_ACOW_ASSIST = 1;
		static const auto STAT_ACOW_FLAG_RETURN = 1;
		static const auto STAT_ACOW_BK_RADAR = 1;
		static const auto STAT_ACOW_FLAG_ASSIST = 1;
		static const auto STAT_ACOW_AIRMAIL = 6;
		static const auto STAT_ACOW_HOTAIR = 3;
		static const auto STAT_ACOW_GAME_COMPLETE = 1;
		static const auto STAT_ACOW_GAME_WINNER = 1;
		static const auto STAT_ACOW_FLAG_GRABDM = 1;
		static const auto STAT_ACOW_FLAG_HOLDER = 1;
		static const auto STAT_ACOW_FLAG_KILLER = 3;
		static const auto STAT_ACOW_FLAG_GRABFAST = 1;
		static const auto STAT_ACOW_DEFENSE_GEN = 1;
		static const auto STAT_ACOW_DEFENSE_FLAG = 1;
		static const auto STAT_ACOW_VD_BIKE = 2;
		static const auto STAT_ACOW_VD_TANK = 2;
		static const auto STAT_ACOW_VD_SHRIKE = 2;
		static const auto STAT_ACOW_FLAG_GRABE = 5;
		static const auto STAT_ACOW_FLAG_GRABLLAMA = 1;
		static const auto STAT_ACOW_ASSIST_VEHICLE = 1;
		static const auto STAT_ACOW_FLAG_GRABULTRA = 2;
		static const auto STAT_ACOW_BASEASSIST = 1;
		static const auto STAT_ACOW_TURRETASSIST = 1;
		static const auto STAT_AWD_CREDITS_EARNED = 204001;
		static const auto STAT_AWD_CREDITS_SPENT = 204002;
		static const auto STAT_AWD_DESTRUCTION_DEPLOYABLE = 204003;
		static const auto STAT_AWD_DESTRUCTION_VEHICLE = 204004;
		static const auto STAT_AWD_DISTANCE_HEADSHOT = 204005;
		static const auto STAT_AWD_DISTANCE_KILL = 204006;
		static const auto STAT_AWD_DISTANCE_SKIED = 204007;
		static const auto STAT_AWD_KILLS = 204008;
		static const auto STAT_AWD_KILLS_DEPLOYABLE = 204009;
		static const auto STAT_AWD_KILLS_MIDAIR = 204010;
		static const auto STAT_AWD_KILLS_VEHICLE = 204011;
		static const auto STAT_AWD_REPAIRS = 204012;
		static const auto STAT_AWD_SPEED_FLAGCAP = 204013;
		static const auto STAT_AWD_SPEED_FLAGGRAB = 204014;
		static const auto STAT_AWD_SPEED_SKIED = 204015;
		static const auto STAT_AWD_FLAG_RETURNS = 204016;
		static const auto STAT_AWD_DEATHS = 204017;
		static const auto STAT_AWDW_CREDITS_EARNED = 98;
		static const auto STAT_AWDW_CREDITS_SPENT = 89;
		static const auto STAT_AWDW_DESTRUCTION_DEPLOYABLE = 84;
		static const auto STAT_AWDW_DESTRUCTION_VEHICLE = 88;
		static const auto STAT_AWDW_DISTANCE_HEADSHOT = 87;
		static const auto STAT_AWDW_DISTANCE_KILL = 93;
		static const auto STAT_AWDW_DISTANCE_SKIED = 90;
		static const auto STAT_AWDW_KILLS = 86;
		static const auto STAT_AWDW_KILLS_DEPLOYABLE = 92;
		static const auto STAT_AWDW_KILLS_MIDAIR = 94;
		static const auto STAT_AWDW_KILLS_VEHICLE = 81;
		static const auto STAT_AWDW_REPAIRS = 96;
		static const auto STAT_AWDW_SPEED_FLAGCAP = -100;
		static const auto STAT_AWDW_SPEED_FLAGGRAB = 97;
		static const auto STAT_AWDW_SPEED_SKIED = 95;
		static const auto STAT_AWDW_FLAG_RETURNS = 85;
		static const auto STAT_AWDW_DEATHS = 1;
		static const auto MIN_CREDITS_FOR_XP = 100;
		static const auto FRIEND_REFERRAL_ACTIVITY = 115;
		static const auto HIDDEN_IF_UNEARNED_TYPE = 10378;
		ADD_STRUCT(ScriptArray<int>, CombatType, 360)
		ADD_STRUCT(ScriptArray<int>, ObjectiveType, 372)
		ADD_STRUCT(ScriptArray<int>, VehicleType, 384)
		ADD_STRUCT(ScriptArray<int>, TacticalType, 396)
		ADD_STRUCT(ScriptArray<int>, SingleType, 408)
		ADD_STRUCT(ScriptArray<int>, ReferralType, 420)
		ADD_STRUCT(int, ActiveType, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57495);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57497);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57501);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57503);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57507);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillProfile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57510);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		void FillCombatType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57515);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillObjectiveType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57520);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillVehicleType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57525);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillTacticalType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57530);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillSingleType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57535);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillReferralType(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57540);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillBadge(class GFxObject* Obj, int Count, int badgeIndex, bool bSkiBadge, bool bSingle, bool bReferralBadge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57546);
			byte params[24] = { NULL };
			*(class GFxObject**)params = Obj;
			*(int*)&params[4] = Count;
			*(int*)&params[8] = badgeIndex;
			*(bool*)&params[12] = bSkiBadge;
			*(bool*)&params[16] = bSingle;
			*(bool*)&params[20] = bReferralBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHighestBadgeIndex(int ActivityId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57557);
			byte params[8] = { NULL };
			*(int*)params = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetHighestSkiBadgeIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57564);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ProfileUp(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57569);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProfileDown(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57571);
			byte params[4] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
