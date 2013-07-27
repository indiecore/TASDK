#pragma once
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TrAccolade : public Object
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
		static const auto THR_SPINFUSOR = 1;
		static const auto THR_SMG = 2;
		static const auto THR_RIFLE = 3;
		static const auto THR_LOCKED_ON = 4;
		static const auto THR_CROSSBOW = 5;
		static const auto THR_FLAME_THROWER = 6;
		static const auto THR_CHAIN_GUN = 7;
		static const auto THR_MISSILE = 8;
		static const auto THR_NANITE = 9;
		static const auto THR_SHOTGUN = 10;
		static const auto THR_UNKNOWN = 11;
		static const auto THR_LASER = 12;
		static const auto THR_CH_V13 = 13;
		static const auto THR_SCOPE = 14;
		static const auto THR_STANDARD = 15;
		static const auto THR_GRENADE_LAUNCHER = 16;
		static const auto THR_MELEE = 17;
		static const auto THR_SHRIKE = 18;
		static const auto THR_FREE_SPECTATOR = 19;
		static const auto THR_RED_DOT = 20;
		static const auto THR_BXT1 = 21;
		static const auto THR_PHASERIFLE = 22;
		static const auto THR_SAP20 = 23;
		static const auto THR_PLASMAGUN = 24;
		static const auto HAE_KILL_STREAK_LEVEL = 1;
		static const auto HAE_KILL_STREAK_LEVEL = 2;
		static const auto HAE_KILL_STREAK_LEVEL = 3;
		static const auto HAE_KILL_STREAK_LEVEL = 4;
		static const auto HAE_KILL_STREAK_LEVEL = 5;
		static const auto TRHUD_PACK_STEALTH = 1;
		static const auto TRHUD_PACK_DAMAGE = 2;
		static const auto TRHUD_PACK_OMNI = 3;
		static const auto TRHUD_PACK_ERECHARGE = 4;
		static const auto TRHUD_PACK_AIRTURRET = 5;
		static const auto TRHUD_PACK_BLINK = 6;
		static const auto TRHUD_PACK_ENERGY = 7;
		static const auto TRHUD_PACK_SHIELD = 8;
		static const auto TRHUD_PACK_JAMMER = 9;
		static const auto TRHUD_PACK_LIGHTTURRET = 10;
		static const auto TRHUD_PACK_FORCEFIELD = 11;
		static const auto TRHUD_PACK_WALLTURRET = 12;
		static const auto TRHUD_PACK_REGEN = 13;
		static const auto TRHUD_PACK_DROPJAMMER = 14;
		static const auto TRHUD_TBD1 = 15;
		static const auto TRHUD_TBD2 = 16;
		static const auto TRHUD_TBD3 = 17;
		static const auto TRHUD_BELT_STICKYGREN = 18;
		static const auto TRHUD_BELT_FRAG = 19;
		static const auto TRHUD_BELT_CLAYMORE = 20;
		static const auto TRHUD_BELT_NITRON = 21;
		static const auto TRHUD_BELT_MOTIONALARM = 22;
		static const auto TRHUD_BELT_SPIKEGREN = 23;
		static const auto TRHUD_BELT_WHITEOUT = 24;
		static const auto TRHUD_BELT_APGREN = 25;
		static const auto TRHUD_BELT_STGREN = 26;
		static const auto TRHUD_BELT_PRISMMINES = 27;
		static const auto TRHUD_BELT_FLARE = 28;
		static const auto TRHUD_BELT_EMPGREN = 29;
		static const auto TRHUD_BELT_MINES = 30;
		static const auto TRHUD_BELT_DISKTOSS = 31;
		static const auto TRHUD_TBD4 = 32;
		static const auto TRHUD_TBD5 = 33;
		static const auto TRHUD_MEDAL_ASSIST = 34;
		static const auto TRHUD_CLAYMOREMINE = 35;
		static const auto TRHUD_PRISMMINE = 36;
		static const auto TRHUD_LIGHTTURRET = 37;
		static const auto TRHUD_AATURRET = 38;
		static const auto TRHUD_MOTIONSENSOR = 39;
		static const auto TRHUD_MINES = 40;
		static const auto TRHUD_FORCESHIELD = 41;
		static const auto TRHUD_DROPJAMMER = 42;
		static const auto TRHUD_GENERATOR = 43;
		static const auto TRHUD_SKIING = 44;
		static const auto TRHUD_MEDAL_KILLINGSPREE = 45;
		static const auto TRHUD_MEDAL_KILLINGRAMPAGE = 46;
		static const auto TRHUD_MEDAL_UNSTOPPABLE = 47;
		static const auto TRHUD_MEDAL_RELENTLESS = 48;
		static const auto TRHUD_MEDAL_THESLAYER = 49;
		static const auto TRHUD_MEDAL_SNIPINGSPREE = 50;
		static const auto TRHUD_MEDAL_MARKSMAN = 51;
		static const auto TRHUD_MEDAL_SHARPSHOOTER = 52;
		static const auto TRHUD_MEDAL_AIRMAIL = 53;
		static const auto TRHUD_MEDAL_DEMOLITIONSEXPERT = 54;
		static const auto TRHUD_MEDAL_HURTLOCKER = 55;
		static const auto TRHUD_MEDAL_CLASSICSPREE = 56;
		static const auto TRHUD_MEDAL_DISKJOCKEY = 57;
		static const auto TRHUD_MEDAL_TRIBALFANATIC = 58;
		static const auto TRHUD_MEDAL_DOUBLEKILL = 59;
		static const auto TRHUD_MEDAL_TRIPLEKILL = 60;
		static const auto TRHUD_MEDAL_QUATRAKILL = 61;
		static const auto TRHUD_MEDAL_ULTRAKILL = 62;
		static const auto TRHUD_MEDAL_TEAMKILL = 63;
		static const auto TRHUD_MEDAL_NOJOY = 64;
		static const auto TRHUD_MEDAL_REVENGE = 65;
		static const auto TRHUD_MEDAL_AFTERMATH = 66;
		static const auto TRHUD_MEDAL_FIRSTBLOOD = 67;
		static const auto TRHUD_MEDAL_BLUEPLATE = 68;
		static const auto TRHUD_MEDAL_STICKYKILL = 69;
		static const auto TRHUD_MEDAL_HEADSHOT = 70;
		static const auto TRHUD_MEDAL_ARTILLERYSHOT = 71;
		static const auto TRHUD_MEDAL_MARTIALART = 72;
		static const auto TRHUD_MEDAL_SQUISH = 73;
		static const auto TRHUD_MEDAL_FLAGGOLD = 74;
		static const auto TRHUD_MEDAL_FLAGSILVER = 75;
		static const auto TRHUD_MEDAL_FLAGBRONZE = 75;
		static const auto TRHUD_MEDAL_FLAGLLAMA = 75;
		static const auto TRHUD_MEDAL_GENERHATER = 76;
		static const auto TRHUD_MEDAL_RABBITHUNTER = 77;
		static const auto TRHUD_MEDAL_CAERBANNOG = 78;
		static const auto TRHUD_MEDAL_FINALBLOW = 79;
		static const auto TRHUD_MEDAL_GENDEFENSE = 76;
		static const auto TRHUD_MEDAL_FLAGDEFENSE = 75;
		static const auto TRHUD_MEDAL_VDESTROY = 73;
		static const auto TRHUD_MEDAL_HOTAIR = 284;
		static const auto TRICON_RANK = 80;
		static const auto TRICON_RANK = 81;
		static const auto TRICON_RANK = 82;
		static const auto TRICON_RANK = 83;
		static const auto TRICON_RANK = 84;
		static const auto TRICON_RANK = 85;
		static const auto TRICON_RANK = 86;
		static const auto TRICON_RANK = 87;
		static const auto TRICON_RANK = 88;
		static const auto TRICON_RANK = 89;
		static const auto TRICON_RANK = 90;
		static const auto TRICON_RANK = 91;
		static const auto TRICON_RANK = 92;
		static const auto TRICON_RANK = 93;
		static const auto TRICON_RANK = 94;
		static const auto TRICON_RANK = 95;
		static const auto TRICON_RANK = 96;
		static const auto TRICON_RANK = 97;
		static const auto TRICON_RANK = 98;
		static const auto TRICON_RANK = 99;
		static const auto TRICON_RANK = 100;
		static const auto TRICON_RANK = 101;
		static const auto TRICON_RANK = 102;
		static const auto TRICON_RANK = 103;
		static const auto TRICON_RANK = 104;
		static const auto TRICON_RANK = 105;
		static const auto TRICON_RANK = 106;
		static const auto TRICON_RANK = 107;
		static const auto TRICON_RANK = 108;
		static const auto TRICON_RANK = 109;
		static const auto TRICON_RANK = 110;
		static const auto TRICON_RANK = 111;
		static const auto TRICON_RANK = 112;
		static const auto TRICON_RANK = 113;
		static const auto TRICON_RANK = 114;
		static const auto TRICON_RANK = 115;
		static const auto TRICON_RANK = 116;
		static const auto TRICON_RANK = 117;
		static const auto TRICON_RANK = 118;
		static const auto TRICON_RANK = 119;
		static const auto TRICON_RANK = 120;
		static const auto TRICON_RANK = 121;
		static const auto TRICON_RANK = 122;
		static const auto TRICON_RANK = 123;
		static const auto TRICON_RANK = 124;
		static const auto TRICON_RANK = 125;
		static const auto TRICON_RANK = 126;
		static const auto TRICON_RANK = 127;
		static const auto TRICON_RANK = 128;
		static const auto TRICON_RANK = 129;
		static const auto TRICON_KILLTYPE_EXPLOSIVE = 130;
		static const auto TRICON_KILLTYPE_STICKY = 131;
		static const auto TRICON_KILLTYPE_SQUISH = 132;
		static const auto TRICON_KILLTYPE_MELEE = 133;
		static const auto TRICON_KILLTYPE_FALLING = 134;
		static const auto TRICON_KILLTYPE_VEHICLE = 135;
		static const auto TRICON_KILLTYPE_BULLET = 136;
		static const auto TRICON_KILLTYPE_SNIPER = 137;
		static const auto TRICON_KILLTYPE_BASE_TURRET = 138;
		static const auto TRICON_KILLTYPE_HEADSHOT = 139;
		static const auto TRICON_KILLTYPE_GENERIC = 140;
		static const auto TRICON_KILLTYPE_SPINFUSOR = 141;
		static const auto TRICON_KILLTYPE_TURRET = 142;
		static const auto TRICON_ACCOLADE_BASE_DESTROY = 143;
		static const auto TRICON_ACCOLADE_BASE_REPAIR = 144;
		static const auto TRICON_ACCOLADE_MIRACLE = 145;
		static const auto TRICON_ACCOLADE_ULTRAKILLNORED = 146;
		static const auto TRICON_ACCOLADE_NOTAMONGEQUALS = 147;
		static const auto TRICON_ACCOLADE_EXPLOSIVESPREE = 148;
		static const auto TRICON_ACCOLADE_ULTRAFASTGRAB = 149;
		static const auto TRICON_ACCOLADE_ONEMANARMY = 150;
		static const auto TRICON_ACCOLADE_GAMEWINNER = 151;
		static const auto TRICON_ACCOLADE_UNITEDWESTAND = 152;
		static const auto TRICON_ACCOLADE_DOUBLEDOWN = 153;
		static const auto TRICON_ACCOLADE_FASTFLAGGRAB = 154;
		static const auto TRICON_ACCOLADE_SHRIKEDOWN = 155;
		static const auto TRICON_ACCOLADE_GRAVCYCLEDOWN = 156;
		static const auto TRICON_ACCOLADE_BEOWULFDOWN = 157;
		static const auto TRICON_ACCOLADE_FINALBLOW = 158;
		static const auto TRICON_ACCOLADE_BENCHEM = 159;
		static const auto TRICON_ACCOLADE_LASTMANSTANDING = 160;
		static const auto TRICON_ACCOLADE_TRIBALHONOR = 161;
		static const auto TRICON_ACCOLADE_FLAGKILLER = 162;
		static const auto TRICON_ACCOLADE_GAMECOMPLETE = 163;
		static const auto TRICON_ACCOLADE_FLAGDEFENSE = 164;
		static const auto TRICON_ACCOLADE_GENERATORDEFENSE = 165;
		static const auto TRICON_ACCOLADE_LLAMAGRAB = 166;
		static const auto TRICON_ACCOLADE_EGRAB = 167;
		static const auto TRICON_ACCOLADE_TURRETDESTROYED = 168;
		static const auto TRICON_ACCOLADE_ALTFLAGCARRY = 169;
		static const auto TRICON_ACCOLADE_HOLDTHELINE = 281;
		static const auto TRICON_ACCOLADE_CAPTUREANDHOLD = 282;
		static const auto TRICON_BADGE_FLAGDEFENSE = 170;
		static const auto TRICON_BADGE_FLAGDEFENSE = 171;
		static const auto TRICON_BADGE_FLAGDEFENSE = 172;
		static const auto TRICON_BADGE_FLAGDEFENSE = 173;
		static const auto TRICON_BADGE_OPERATOR = 174;
		static const auto TRICON_BADGE_OPERATOR = 175;
		static const auto TRICON_BADGE_OPERATOR = 176;
		static const auto TRICON_BADGE_OPERATOR = 177;
		static const auto TRICON_BADGE_CALLINKILLS = 178;
		static const auto TRICON_BADGE_CALLINKILLS = 179;
		static const auto TRICON_BADGE_CALLINKILLS = 180;
		static const auto TRICON_BADGE_CALLINKILLS = 181;
		static const auto TRICON_BADGE_MELEEKILLS = 182;
		static const auto TRICON_BADGE_MELEEKILLS = 183;
		static const auto TRICON_BADGE_MELEEKILLS = 184;
		static const auto TRICON_BADGE_MELEEKILLS = 185;
		static const auto TRICON_BADGE_ONEMANARMY = 186;
		static const auto TRICON_BADGE_ONEMANARMY = 187;
		static const auto TRICON_BADGE_ONEMANARMY = 188;
		static const auto TRICON_BADGE_ONEMANARMY = 189;
		static const auto TRICON_BADGE_FLAGCAPPER = 190;
		static const auto TRICON_BADGE_FLAGCAPPER = 191;
		static const auto TRICON_BADGE_FLAGCAPPER = 192;
		static const auto TRICON_BADGE_FLAGCAPPER = 193;
		static const auto TRICON_BADGE_TOUROFDUTY = 194;
		static const auto TRICON_BADGE_TOUROFDUTY = 195;
		static const auto TRICON_BADGE_TOUROFDUTY = 196;
		static const auto TRICON_BADGE_TOUROFDUTY = 197;
		static const auto TRICON_BADGE_MULTIKILL = 198;
		static const auto TRICON_BADGE_MULTIKILL = 199;
		static const auto TRICON_BADGE_MULTIKILL = 200;
		static const auto TRICON_BADGE_MULTIKILL = 201;
		static const auto TRICON_BADGE_COMBATSTAR = 202;
		static const auto TRICON_BADGE_COMBATSTAR = 203;
		static const auto TRICON_BADGE_COMBATSTAR = 204;
		static const auto TRICON_BADGE_COMBATSTAR = 205;
		static const auto TRICON_BADGE_CROSSCOUNTRY = 206;
		static const auto TRICON_BADGE_CROSSCOUNTRY = 207;
		static const auto TRICON_BADGE_CROSSCOUNTRY = 208;
		static const auto TRICON_BADGE_CROSSCOUNTRY = 209;
		static const auto TRICON_BADGE_POWERPLAYER = 210;
		static const auto TRICON_BADGE_POWERPLAYER = 211;
		static const auto TRICON_BADGE_POWERPLAYER = 212;
		static const auto TRICON_BADGE_POWERPLAYER = 213;
		static const auto TRICON_BADGE_DEMOMAN = 214;
		static const auto TRICON_BADGE_DEMOMAN = 215;
		static const auto TRICON_BADGE_DEMOMAN = 216;
		static const auto TRICON_BADGE_DEMOMAN = 217;
		static const auto TRICON_BADGE_SPEEDRUNNER = 218;
		static const auto TRICON_BADGE_SPEEDRUNNER = 219;
		static const auto TRICON_BADGE_SPEEDRUNNER = 220;
		static const auto TRICON_BADGE_SPEEDRUNNER = 221;
		static const auto TRICON_BADGE_GOODDRIVER = 222;
		static const auto TRICON_BADGE_GOODDRIVER = 223;
		static const auto TRICON_BADGE_GOODDRIVER = 224;
		static const auto TRICON_BADGE_GOODDRIVER = 225;
		static const auto TRICON_BADGE_PURPLEHEART = 226;
		static const auto TRICON_BADGE_PURPLEHEART = 227;
		static const auto TRICON_BADGE_PURPLEHEART = 228;
		static const auto TRICON_BADGE_PURPLEHEART = 229;
		static const auto TRICON_BADGE_HAPPENSTOUSALL = 230;
		static const auto TRICON_BADGE_INVSTATION = 231;
		static const auto TRICON_BADGE_ANTIVEHICLE = 232;
		static const auto TRICON_BADGE_ANTIVEHICLE = 233;
		static const auto TRICON_BADGE_ANTIVEHICLE = 234;
		static const auto TRICON_BADGE_ANTIVEHICLE = 235;
		static const auto TRICON_BADGE_UTILITYBELT = 236;
		static const auto TRICON_BADGE_UTILITYBELT = 237;
		static const auto TRICON_BADGE_UTILITYBELT = 238;
		static const auto TRICON_BADGE_UTILITYBELT = 239;
		static const auto TRICON_BADGE_ONCALL = 240;
		static const auto TRICON_BADGE_ONCALL = 241;
		static const auto TRICON_BADGE_ONCALL = 242;
		static const auto TRICON_BADGE_ONCALL = 243;
		static const auto TRICON_BADGE_SUPPORT = 244;
		static const auto TRICON_BADGE_SUPPORT = 245;
		static const auto TRICON_BADGE_SUPPORT = 246;
		static const auto TRICON_BADGE_SUPPORT = 247;
		static const auto TRICON_BADGE_MARKSMAN = 248;
		static const auto TRICON_BADGE_MARKSMAN = 249;
		static const auto TRICON_BADGE_MARKSMAN = 250;
		static const auto TRICON_BADGE_MARKSMAN = 251;
		static const auto TRICON_BADGE_ASSISTOR = 252;
		static const auto TRICON_BADGE_ASSISTOR = 253;
		static const auto TRICON_BADGE_ASSISTOR = 254;
		static const auto TRICON_BADGE_ASSISTOR = 255;
		static const auto TRICON_BADGE_BUILDER = 256;
		static const auto TRICON_BADGE_BUILDER = 257;
		static const auto TRICON_BADGE_BUILDER = 258;
		static const auto TRICON_BADGE_BUILDER = 259;
		static const auto TRICON_BADGE_GOINGFAST = 260;
		static const auto TRICON_BADGE_GOINGFAST = 261;
		static const auto TRICON_BADGE_GOINGFAST = 262;
		static const auto TRICON_BADGE_GOINGFAST = 263;
		static const auto RANK_XP = 0;
		static const auto RANK_XP = 1350;
		static const auto RANK_XP = 2781;
		static const auto RANK_XP = 4298;
		static const auto RANK_XP = 5906;
		static const auto RANK_XP = 11212;
		static const auto RANK_XP = 16836;
		static const auto RANK_XP = 22798;
		static const auto RANK_XP = 31741;
		static const auto RANK_XP = 41130;
		static const auto RANK_XP = 50990;
		static const auto RANK_XP = 61342;
		static const auto RANK_XP = 76870;
		static const auto RANK_XP = 93020;
		static const auto RANK_XP = 109815;
		static const auto RANK_XP = 127283;
		static const auto RANK_XP = 145449;
		static const auto RANK_XP = 172698;
		static const auto RANK_XP = 200765;
		static const auto RANK_XP = 229673;
		static const auto RANK_XP = 259449;
		static const auto RANK_XP = 290118;
		static const auto RANK_XP = 321707;
		static const auto RANK_XP = 369091;
		static const auto RANK_XP = 417896;
		static const auto RANK_XP = 468166;
		static const auto RANK_XP = 519943;
		static const auto RANK_XP = 573274;
		static const auto RANK_XP = 628205;
		static const auto RANK_XP = 684783;
		static const auto RANK_XP = 743059;
		static const auto RANK_XP = 803084;
		static const auto RANK_XP = 864909;
		static const auto RANK_XP = 928589;
		static const auto RANK_XP = 994179;
		static const auto RANK_XP = 1061737;
		static const auto RANK_XP = 1131321;
		static const auto RANK_XP = 1202994;
		static const auto RANK_XP = 1276816;
		static const auto RANK_XP = 1352853;
		static const auto RANK_XP = 1431171;
		static const auto RANK_XP = 1511839;
		static const auto RANK_XP = 1594926;
		static const auto RANK_XP = 1680507;
		static const auto RANK_XP = 1768654;
		static const auto RANK_XP = 1859447;
		static const auto RANK_XP = 1952963;
		static const auto RANK_XP = 2049284;
		static const auto RANK_XP = 2148495;
		static const auto RANK_XP = 2250682;
		static const auto ACCOLADE_TYPE_MISC = 0;
		static const auto ACCOLADE_TYPE_MULTIKILL = 1;
		static const auto ACCOLADE_TYPE_KILLSTREAK = 2;
		static const auto TRICON_PERK_ICON_WIP = 1;
		static const auto TRICON_PERK_BONUS_KILL_CREDITS = 1;
		static const auto TRICON_PERK_STICKY_HANDS = 2;
		static const auto TRICON_PERK_REDUCED_VEHICLE_COST = 3;
		static const auto TRICON_PERK_REDUCED_SELF_DAMAGE = 4;
		static const auto TRICON_PERK_REDUCED_RUN_OVER = 5;
		static const auto TRICON_PERK_REDUCED_BASE_UPGRADE_COST = 6;
		static const auto TRICON_PERK_REDUCED_FALL_DMG = 7;
		static const auto TRICON_PERK_REDUCED_AIR_VEHICLE_COST = 8;
		static const auto TRICON_PERK_TRAP_DETECTION = 9;
		static const auto TRICON_PERK_PICKUP_ENERGY_HEALTH = 10;
		static const auto TRICON_PERK_MELEE_FLAG_DROP = 11;
		static const auto TRICON_PERK_EXTRA_MINES = 12;
		static const auto TRICON_PERK_EXTRA_ENERGY = 13;
		static const auto TRICON_PERK_EXTRA_GRENADE_PICKUP = 14;
		static const auto TRICON_PERK_EXTRA_AMMO = 15;
		static const auto TRICON_PERK_EXTRA_GRENADE = 16;
		static const auto TRICON_PERK_BEOWULF_HEALTH_INCREASE = 17;
		static const auto TRICON_PERK_EJECTION_SEAT = 18;
		static const auto TRICON_PERK_ORBITAL_STRIKE = 19;
		static const auto TRICON_PERK_REDUCED_MELEE_DAMAGE = 20;
		static const auto TRICON_PERK_MELEE_BACKSTAB = 21;
		static const auto TRICON_PERK_DEMOLITIONS = 22;
		static const auto TRICON_PERK_SQUIRRELLY = 23;
		static const auto TRICON_PERK_STEALTHY = 24;
		static const auto TRICON_PERK_ULTRA_CAPACITOR = 25;
		static const auto TRICON_PERK_DETERMINATION = 26;
		static const auto TRICON_SKILL_SPEED = 1;
		static const auto TRICON_SKILL_ENERGY = 2;
		static const auto TRICON_SKILL_PING = 3;
		static const auto TRICON_SKILL_AMMO = 4;
		static const auto TRICON_SKILL_ANTI_ARMOR = 5;
		static const auto TRICON_SKILL_GRENADE = 6;
		static const auto TRICON_SKILL_RADIUS = 7;
		static const auto TRICON_SKILL_HEALTH = 8;
		static const auto TRICON_SKILL_BOOT = 9;
		static const auto TRICON_SKILL_TIMER = 10;
		static const auto TRICON_CLASS_SENTINEL = 1;
		static const auto TRICON_CLASS_PATHFINDER = 2;
		static const auto TRICON_CLASS_JUMPER = 3;
		static const auto TRICON_CLASS_INFILTRATOR = 4;
		static const auto TRICON_CLASS_WARDER = 30;
		static const auto TRICON_CLASS_TECHNICIAN = 31;
		static const auto TRICON_CLASS_SOLDIER = 32;
		static const auto TRICON_CLASS_SCRAMBLER = 33;
		static const auto TRICON_CLASS_RANGER = 34;
		static const auto TRICON_CLASS_RAIDER = 35;
		static const auto TRICON_CLASS_ENGINEER = 36;
		static const auto TRICON_CLASS_ROOK = 60;
		static const auto TRICON_CLASS_MARAUDER = 61;
		static const auto TRICON_CLASS_JUGGERNAUT = 62;
		static const auto TRICON_CLASS_DOOMBRINGER = 63;
		static const auto TRICON_CLASS_BRUTE = 64;
		static const auto TRICON_CLASS_WIP = 88;
		static const auto ICON_UPGRADE_NONE = 0;
		static const auto MOD_TYPE_NONE = 1;
		static const auto MOD_TYPE_HEALTH = 2;
		static const auto MOD_TYPE_MASSPCT = 3;
		static const auto MOD_TYPE_RADARLINK = 4;
		static const auto MOD_TYPE_FLAGREACH = 5;
		static const auto MOD_TYPE_BUILDUPPCT = 6;
		static const auto MOD_TYPE_CLOTHESLINE = 7;
		static const auto MOD_TYPE_STICKYHANDS = 8;
		static const auto MOD_TYPE_MAXSKISPEED = 9;
		static const auto MOD_TYPE_EXTRAENERGY = 10;
		static const auto MOD_TYPE_EJECTIONSEAT = 11;
		static const auto MOD_TYPE_SELFDAMAGEPCT = 12;
		static const auto MOD_TYPE_REPAIRRATEPCT = 13;
		static const auto MOD_TYPE_EXTRAMINESOUT = 14;
		static const auto MOD_TYPE_VEHICLEEXTRAHEALTH = 15;
		static const auto MOD_TYPE_GROUNDSPEEDPCT = 16;
		static const auto MOD_TYPE_ENERGYDRAINPCT = 17;
		static const auto MOD_TYPE_UPGRADECOSTPCT = 18;
		static const auto MOD_TYPE_CANDETECTTRAPS = 19;
		static const auto MOD_TYPE_SPLATDAMAGEPCT = 20;
		static const auto MOD_TYPE_WEAPONSWITCHPCT = 21;
		static const auto MOD_TYPE_POTENTIALENERGY = 22;
		static const auto MOD_TYPE_MAXJETTINGSPEED = 23;
		static const auto MOD_TYPE_CREDITSFROMKILLS = 24;
		static const auto MOD_TYPE_TERMINALSKISPEED = 25;
		static const auto MOD_TYPE_MAXSKICONTROLPCT = 26;
		static const auto MOD_TYPE_HASDETERMINATION = 27;
		static const auto MOD_TYPE_DEPLOYABLEHEALTH = 28;
		static const auto MOD_TYPE_EXTRAOFFHANDAMMO = 29;
		static const auto MOD_TYPE_EXTRAPRIMARYAMMO = 30;
		static const auto MOD_TYPE_PRIMARYRELOADPCT = 31;
		static const auto MOD_TYPE_SENSORDISTANCEPCT = 32;
		static const auto MOD_TYPE_PACKENERGYCOSTPCT = 33;
		static const auto MOD_TYPE_AMMOFROMPICKUPPCT = 34;
		static const auto MOD_TYPE_TIMETOREGENENERGY = 35;
		static const auto MOD_TYPE_SECONDARYRELOADPCT = 36;
		static const auto MOD_TYPE_EXTRASECONDARYAMMO = 37;
		static const auto MOD_TYPE_ENERGYREGENRATEPCT = 38;
		static const auto MOD_TYPE_HEALTHREGENRATEPCT = 39;
		static const auto MOD_TYPE_DEPLOYABLERANGEPCT = 40;
		static const auto MOD_TYPE_JAMMERPACKRADIUSPCT = 41;
		static const auto MOD_TYPE_BLINKPACKPOTENCYPCT = 42;
		static const auto MOD_TYPE_PEAKSKICONTROLSPEED = 43;
		static const auto MOD_TYPE_CANCALLINSUPPLYDROP = 44;
		static const auto MOD_TYPE_EXTRADEPLOYABLESOUT = 45;
		static const auto MOD_TYPE_HEALTHFROMPICKUPPCT = 46;
		static const auto MOD_TYPE_ENERGYFROMPICKUPPCT = 47;
		static const auto MOD_TYPE_TERMINALJETTINGSPEED = 48;
		static const auto MOD_TYPE_TIMETOREGENHEALTHPCT = 49;
		static const auto MOD_TYPE_VEHICLECOSTPCT = 50;
		static const auto MOD_TYPE_SKICONTROLSIGMASQUARE = 51;
		static const auto MOD_TYPE_RECEIVEMELEEDAMAGEPCT = 52;
		static const auto MOD_TYPE_VICTIMDROPFLAGONMELEE = 53;
		static const auto MOD_TYPE_PRIMARYWEAPONRANGEPCT = 54;
		static const auto MOD_TYPE_OFFHANDDAMAGERADIUSPCT = 55;
		static const auto MOD_TYPE_TURRETACQUIRETARGETPCT = 56;
		static const auto MOD_TYPE_WHITEOUTINTERPSPEEDPCT = 57;
		static const auto MOD_TYPE_BACKSTABMELEEDAMAGEPCT = 58;
		static const auto MOD_TYPE_MAXSTOPPINGDISTANCEPCT = 59;
		static const auto MOD_TYPE_SECONDARYWEAPONRANGEPCT = 60;
		static const auto MOD_TYPE_EXTRAGRENADESFROMPICKUP = 61;
		static const auto MOD_TYPE_SHIELDPACKEFFECTIVENESS = 62;
		static const auto MOD_TYPE_STEALTHPACKPULSETIMEPCT = 63;
		static const auto MOD_TYPE_PRIMARYINCREASEDCLIPSIZE = 64;
		static const auto MOD_TYPE_EXTRACREDITSFROMBELTKILLS = 65;
		static const auto MOD_TYPE_TURRETARMORPENETRATIONPCT = 66;
		static const auto MOD_TYPE_SECONDARYINCREASEDCLIPSIZE = 67;
		static const auto MOD_TYPE_OFFHANDARMORPENETRATIONPCT = 68;
		static const auto MOD_TYPE_PRIMARYARMORPENETRATIONPCT = 69;
		static const auto MOD_TYPE_RUNOVERDAMAGEPROTECTIONPCT = 70;
		static const auto MOD_TYPE_PRIMARYWEAPONENERGYCOSTPCT = 71;
		static const auto MOD_TYPE_ACQUIRETIMEBYENEMYTURRETPCT = 72;
		static const auto MOD_TYPE_SECONDARYARMORPENETRATIONPCT = 73;
		static const auto MOD_TYPE_VEHICLEEXTRAENERGY = 74;
		static const auto MOD_TYPE_AMMOPICKUPREACH = 75;
		static const auto MOD_TYPE_VEHICLEPASSENGERDMGPROTPCT = 76;
		static const auto MOD_TYPE_DAMAGEREPAIRENEMYOBJECTIVES = 77;
		static const auto MOD_TYPE_POTENTIALENERGYFALLDAMAGE = 78;
		static const auto MOD_TYPE_FASTERTHROWBELTBUFFPCT = 79;
		static const auto MOD_TYPE_IGNOREGRENADESECONDARYONSELF = 80;
		static const auto MOD_TYPE_POTENTIALENERGYDMGTRANSFERPCT = 81;
		static const auto MOD_TYPE_FLAGREACHTIER = 82;
		static const auto MOD_TYPE_SONICPUNCH = 83;
		static const auto MOD_TYPE_SONICPUNCHDIST = 84;
		static const auto MOD_TYPE_SONICPUNCHKNOCKBACK = 85;
		static const auto MOD_TYPE_RAGE = 86;
		static const auto MOD_TYPE_RAGEENERGYREGEN = 87;
		static const auto MOD_TYPE_RAGETIMELENGTH = 88;
		static const auto MOD_TYPE_RAGEHEALTHRESTOREPCT = 89;
		static const auto MOD_TYPE_IGNOREPULSESTEALTHTIME = 90;
		static const auto MOD_TYPE_RAGEMASSREDUCTION = 91;
		static const auto MOD_TYPE_REPAIRDEPLOYABLERATEPCT = 92;
		ADD_STRUCT(int, DatabaseId, 68)
		ADD_STRUCT(int, ActivityId, 72)
		ADD_STRUCT(int, Type, 88)
		ADD_STRUCT(int, IconIndex, 64)
		ADD_STRUCT(ScriptString*, FriendlyName, 104)
		ADD_STRUCT(ScriptString*, Description, 116)
		ADD_STRUCT(ScriptString*, HUDMessage, 92)
		ADD_STRUCT(float, Weight, 84)
		ADD_BOOL(Broadcast, 80, 0x1)
		ADD_STRUCT(int, MessageSwitch, 76)
		ADD_STRUCT(int, CreditsAwarded, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
