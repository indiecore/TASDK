#pragma once
#include "TribesGame.TrObject.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "TribesGame.TrStatsInterface.h"
#include "Engine.Actor.h"
#include "TribesGame.TrValueModifier.h"
#include "Engine.TeamInfo.h"
#include "TribesGame.TrInventoryHelper.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.ParticleSystem.h"
#include "UTGame.UTCarriedObject.h"
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
	class TrPlayerReplicationInfo : public UTPlayerReplicationInfo
	{
	public:
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
		class EquipLevel
		{
		public:
			ADD_STRUCT(byte, UpgradeLevel, 4)
			ADD_STRUCT(int, EquipId, 0)
		};
		ADD_STRUCT(int, m_nCreditsEarned, 948)
		ADD_STRUCT(int, m_nKills, 940)
		ADD_STRUCT(int, m_nAssists, 944)
		ADD_STRUCT(int, r_nArenaSpawnsLeft, 1128)
		ADD_BOOL(r_bIsCrossedOffArenaList, 972, 0x8)
		ADD_OBJECT(Actor, m_LockedTarget, 976)
		ADD_BOOL(c_bIsBuddyToLocalPlayer, 972, 0x2)
		ADD_BOOL(c_bIsMutualBuddiesWithLocalPlayer, 972, 0x4)
		ADD_BOOL(r_bIsLastManStanding, 972, 0x10)
		ADD_STRUCT(int, m_nFreeCredits, 964)
		ADD_STRUCT(int, m_nCurrentCredits, 968)
		ADD_OBJECT(ScriptClass, r_VoiceClass, 984)
		ADD_STRUCT(int, m_nRabbitRank, 924)
		ADD_STRUCT(int, m_nPlayerIconIndex, 936)
		ADD_STRUCT(int, r_bSkinId, 1132)
		ADD_OBJECT(ScriptClass, c_Cached1PSkin, 1124)
		ADD_OBJECT(ScriptClass, c_Cached3PSkin, 1120)
		ADD_OBJECT(TrValueModifier, m_ValueModifier, 1116)
		ADD_STRUCT(TrPlayerReplicationInfo::EquipLevel, r_EquipLevels, 1012)
		ADD_STRUCT(float, c_fRedFlagTimeStamp, 1008)
		ADD_STRUCT(float, c_fRedFlagPingTime, 1004)
		ADD_STRUCT(float, c_fRedFlagPingThreshold, 1000)
		ADD_STRUCT(float, c_fCurrentPingMS, 996)
		ADD_OBJECT(TrInventoryHelper, InvHelper, 992)
		ADD_OBJECT(TrStatsInterface, Stats, 988)
		ADD_STRUCT(TrObject::EArmorType, m_ArmorType, 980)
		ADD_BOOL(bDevUpgrades, 972, 0x1)
		ADD_STRUCT(int, m_nPlayerClassId, 960)
		ADD_STRUCT(int, m_nBaseXP, 956)
		ADD_STRUCT(int, m_nBaseGP, 952)
		ADD_STRUCT(int, m_nRankIconIndex, 932)
		ADD_STRUCT(int, m_nRankNum, 928)
		ADD_OBJECT(ScriptClass, m_PendingBaseClass, 920)
		ADD_OBJECT(ScriptClass, m_CurrentBaseClass, 916)
		ADD_OBJECT(ScriptClass, m_Rank, 912)
		ADD_STRUCT(int, m_PendingLoadout, 908)
		ADD_STRUCT(int, m_CurrentLoadout, 904)
		ScriptClass* GetPlayerRank()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerRank");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		ScriptClass* GetCurrentClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		ScriptClass* GetEquipDevice(ScriptClass* FamilyInfo, TrObject::TR_EQUIP_POINT equipSlot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetEquipDevice");
			byte params[9] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(TrObject::TR_EQUIP_POINT*)&params[4] = equipSlot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[8];
		}
		int GetRankIcon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetRankIcon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		class TrValueModifier* GetCurrentValueModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentValueModifier");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrValueModifier**)&params[0];
		}
		TrObject::TR_EQUIP_POINT GetEquipPointByWeaponId(int WeaponId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetEquipPointByWeaponId");
			byte params[5] = { NULL };
			*(int*)&params[0] = WeaponId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::TR_EQUIP_POINT*)&params[4];
		}
		TrObject::EArmorType GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetArmorType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::EArmorType*)&params[0];
		}
		ScriptClass* GetCurrentSkinClass(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentSkinClass");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		class SkeletalMesh* GetGibMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetGibMesh");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[4];
		}
		class SkeletalMesh* Get3PSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Get3PSkin");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[0];
		}
		class SkeletalMesh* GetBodyMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBodyMesh");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[0];
		}
		class SkeletalMesh* GetHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetHandsMesh");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[0];
		}
		class ParticleSystem* GetSkiThrust(ScriptClass* FamilyInfo, class ParticleSystem* DefaultSystem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetSkiThrust");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(class ParticleSystem**)&params[4] = DefaultSystem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[8];
		}
		int GetJetpackSocketCount(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocketCount");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class ParticleSystem* GetJetpackThrust(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackThrust");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[4];
		}
		ScriptName GetJetpackSocket(ScriptClass* FamilyInfo, int Socket)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocket");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(int*)&params[4] = Socket;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		class ParticleSystem* GetJetpackTrail(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackTrail");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ParticleSystem**)&params[4];
		}
		bool RequestLoadoutChange(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RequestLoadoutChange");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool VerifyCharacter(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.VerifyCharacter");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetCharacterEquip(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquip");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetCharacterEquipLocal(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquipLocal");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetUpgradeLevel(int ClassId, int Type, ScriptArray<int> UpgradeList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevel");
			byte params[24] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(ScriptArray<int>*)&params[8] = UpgradeList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		int GetUpgradeLevelLocal(int ClassId, int Type, ScriptArray<int> UpgradeList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevelLocal");
			byte params[24] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(ScriptArray<int>*)&params[8] = UpgradeList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdatePing");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RegisterBuddy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RegisterBuddy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* Load1PData(ScriptString* ContentPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Load1PData");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ContentPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[12];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterPlayerWithSession()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RegisterPlayerWithSession");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateValueModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdateValueModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerTeam(class TeamInfo* NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerTeam");
			byte params[4] = { NULL };
			*(class TeamInfo**)&params[0] = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwapToPendingCharClass(bool bIsRespawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SwapToPendingCharClass");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsRespawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool VerifyAndLoadCharacter(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.VerifyAndLoadCharacter");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetSelectedLoadout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetSelectedLoadout");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool ShouldVisitStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ShouldVisitStation");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ResolveDefaultEquip(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ResolveDefaultEquip");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveEquip(TrObject::TR_EQUIP_POINT EquipId, int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetActiveEquip");
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipId;
			*(int*)&params[4] = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementKills(bool bEnemyKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.IncrementKills");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnemyKill;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckMultiKill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.CheckMultiKill");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPlayerClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerClassId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptClass* GetPendingClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPendingClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		ScriptString* GetCurrentClassAbb()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentClassAbb");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		int GetPlayerRankNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerRankNum");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetBaseGP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBaseGP");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetBaseXP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBaseXP");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void SetPlayerGP(int GP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerGP");
			byte params[4] = { NULL };
			*(int*)&params[0] = GP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerXP");
			byte params[4] = { NULL };
			*(int*)&params[0] = XP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetRankFromXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetRankFromXP");
			byte params[8] = { NULL };
			*(int*)&params[0] = XP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		ScriptClass* GetPerkFromId(int PerkId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPerkFromId");
			byte params[8] = { NULL };
			*(int*)&params[0] = PerkId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		void SetFlag(class UTCarriedObject* NewFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetFlag");
			byte params[4] = { NULL };
			*(class UTCarriedObject**)&params[0] = NewFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PlayerReplicationInfo* Duplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Duplicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[0];
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.CopyProperties");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCached3PSkin(ScriptClass* NewCachedSkin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetCached3PSkin");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = NewCachedSkin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetCurrentVoiceClass(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentVoiceClass");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		void UpdateCachedSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdateCachedSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.On3PSkinContentLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void On1PSkinContentLoaded(ScriptClass* Skin1PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.On1PSkinContentLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Skin1PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Update1PMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Update1PMesh");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPingRedFlagged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.OnPingRedFlagged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPingRedFlag(float CurrentPingMS)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ServerPingRedFlag");
			byte params[4] = { NULL };
			*(float*)&params[0] = CurrentPingMS;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
