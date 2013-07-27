#pragma once
#include "TribesGame.GFxTrReticules.h"
#include "UTGame.GFxMinimapHud.h"
#include "TribesGame.GFxDeviceAmmoCount.h"
#include "GFxUI.GFxObject.h"
#include "PlatformCommon.TgSupportCommands.h"
#include "Engine.TeamInfo.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.MaterialEffect.h"
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrHUD.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrVehicle.h"
#include "Core.Object.h"
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
	class GfxTrHud : public GFxMinimapHud
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
		static const auto MAX_CLASS_SLOTS = 10;
		static const auto TR_QUERY_CTF = 0;
		static const auto TR_QUERY_TDM = 1;
		static const auto TR_QUERY_RABBIT = 2;
		static const auto TR_QUERY_TEAMRABBIT = 3;
		static const auto TR_QUERY_ARENA = 4;
		static const auto TR_QUERY_DEFENDANDDESTROY = 5;
		static const auto TR_QUERY_CTFBLITZ = 6;
		static const auto CONTEXT_GAME_MODE_TRCTF = 0;
		static const auto CONTEXT_GAME_MODE_TRTDM = 1;
		static const auto CONTEXT_GAME_MODE_TRRABBIT = 2;
		static const auto CONTEXT_GAME_MODE_TRSIEGE = 3;
		static const auto CONTEXT_GAME_MODE_TRTRAINING = 4;
		static const auto CONTEXT_GAME_MODE_TRSTORM = 5;
		static const auto CONTEXT_GAME_MODE_TRTEAMRABBIT = 6;
		static const auto CONTEXT_GAME_MODE_TRARENA = 7;
		static const auto CONTEXT_GAME_MODE_TRDEFENDANDDESTROY = 8;
		static const auto CONTEXT_GAME_MODE_TRCAPTUREANDHOLD = 9;
		static const auto CONTEXT_GAME_MODE_TRCTFBLITZ = 10;
		static const auto STAT_VIEW_BASE_PLAYER = 1;
		static const auto STAT_VIEW_BASE_GAME = 101;
		static const auto STAT_VIEW_BASE_WEAPON_TYPE = 1000;
		static const auto GAME_SESSION_NAME = 'Game';
		static const auto PROPERTY_CUSTOM_MAPNAME = 0x40000001;
		static const auto PROPERTY_CUSTOM_GAMEMODE = 0x40000002;
		static const auto PROPERTY_SERVER_DESCRIPTION = 0x40000003;
		static const auto PROPERTY_CUSTOM_MUTATORS = 0x40000004;
		static const auto CLASS_TYPE_UNKNOWN = 1668;
		static const auto CLASS_TYPE_LIGHT_INFILTRATOR = 1682;
		static const auto CLASS_TYPE_LIGHT_JUMPER = 1696;
		static const auto CLASS_TYPE_LIGHT_ARCHITECT = 1697;
		static const auto CLASS_TYPE_LIGHT_PATHFINDER = 1683;
		static const auto CLASS_TYPE_LIGHT_NAKEDPATHFINDER = 1701;
		static const auto CLASS_TYPE_LIGHT_WRAITH = 1685;
		static const auto CLASS_TYPE_LIGHT_SENTINEL = 1686;
		static const auto CLASS_TYPE_MEDIUM_ENGINEER = 1698;
		static const auto CLASS_TYPE_MEDIUM_RANGER = 1687;
		static const auto CLASS_TYPE_MEDIUM_SCRAMBLER = 1688;
		static const auto CLASS_TYPE_MEDIUM_SOLDIER = 1693;
		static const auto CLASS_TYPE_MEDIUM_RAIDER = 1699;
		static const auto CLASS_TYPE_MEDIUM_TECHNICIAN = 1694;
		static const auto CLASS_TYPE_MEDIUM_WARDER = 1700;
		static const auto CLASS_TYPE_HEAVY_BRUTE = 1689;
		static const auto CLASS_TYPE_HEAVY_ROOK = 1690;
		static const auto CLASS_TYPE_HEAVY_DOOMBRINGER = 1691;
		static const auto CLASS_TYPE_HEAVY_JUGGERNAUGHT = 1692;
		static const auto CLASS_TYPE_HEAVY_MARAUDER = 1695;
		static const auto CLASS_PURCHASE_LIGHT_INFILTRATOR = 7476;
		static const auto CLASS_PURCHASE_LIGHT_PATHFINDER = 7466;
		static const auto CLASS_PURCHASE_LIGHT_SENTINEL = 7478;
		static const auto CLASS_PURCHASE_MEDIUM_SOLDIER = 7470;
		static const auto CLASS_PURCHASE_MEDIUM_RAIDER = 7494;
		static const auto CLASS_PURCHASE_MEDIUM_TECHNICIAN = 7472;
		static const auto CLASS_PURCHASE_HEAVY_BRUTE = 7486;
		static const auto CLASS_PURCHASE_HEAVY_DOOMBRINGER = 7488;
		static const auto CLASS_PURCHASE_HEAVY_JUGGERNAUGHT = 7474;
		static const auto CLASS_INFO_BIT_NONE = 0x00000000;
		static const auto CLASS_INFO_BIT_INFILTRATOR = 0x00000001;
		static const auto CLASS_INFO_BIT_JUMPER = 0x00000002;
		static const auto CLASS_INFO_BIT_ARCHITECT = 0x00000004;
		static const auto CLASS_INFO_BIT_PATHFINDER = 0x00000008;
		static const auto CLASS_INFO_BIT_WRAITH = 0x00000010;
		static const auto CLASS_INFO_BIT_SENTINEL = 0x00000020;
		static const auto CLASS_INFO_BIT_ENGINEER = 0x00000040;
		static const auto CLASS_INFO_BIT_RANGER = 0x00000080;
		static const auto CLASS_INFO_BIT_SCRAMBLER = 0x00000100;
		static const auto CLASS_INFO_BIT_SOLDIER = 0x00000200;
		static const auto CLASS_INFO_BIT_RAIDER = 0x00000400;
		static const auto CLASS_INFO_BIT_TECHNICIAN = 0x00000800;
		static const auto CLASS_INFO_BIT_WARDER = 0x00001000;
		static const auto CLASS_INFO_BIT_BRUTE = 0x00002000;
		static const auto CLASS_INFO_BIT_ROOK = 0x00004000;
		static const auto CLASS_INFO_BIT_DOOMBRINGER = 0x00008000;
		static const auto CLASS_INFO_BIT_JUGGERNAUT = 0x00010000;
		static const auto CLASS_INFO_BIT_MARAUDER = 0x00020000;
		static const auto CLASS_INFO_BIT_NAKEDPATHFINDER = 0x00040000;
		static const auto WEAPON_ID_UNKNOWN = 102000;
		static const auto WEAPON_ID_AVMINE = 102003;
		static const auto WEAPON_ID_DUALRHINO = 102024;
		static const auto WEAPON_ID_LACERATOR = 102016;
		static const auto WEAPON_ID_ARX_BUSTER = 7384;
		static const auto WEAPON_ID_CHAINGUN = 7386;
		static const auto WEAPON_ID_DROPJAMMER = 7456;
		static const auto WEAPON_ID_FORCEFIELD = 7411;
		static const auto WEAPON_ID_FORCEFIELD_PERSONAL = 7460;
		static const auto WEAPON_ID_GRENADE = 7390;
		static const auto WEAPON_ID_GRENADE_AP = 7434;
		static const auto WEAPON_ID_GRENADE_AP_HEAVY = 7447;
		static const auto WEAPON_ID_GRENADE_EMP = 7444;
		static const auto WEAPON_ID_GRENADE_FLARE = 7389;
		static const auto WEAPON_ID_GRENADE_NITRON = 7387;
		static const auto WEAPON_ID_GRENADE_NITRON_HEAVY = 7450;
		static const auto WEAPON_ID_GRENADE_SPIKE = 7428;
		static const auto WEAPON_ID_GRENADE_ST = 7437;
		static const auto WEAPON_ID_GRENADE_STICKY = 7402;
		static const auto WEAPON_ID_GRENADE_STICKY_LIGHT = 7455;
		static const auto WEAPON_ID_GRENADE_WHITEOUT = 7432;
		static const auto WEAPON_ID_GRENADE_XL = 7430;
		static const auto WEAPON_ID_GUNNER_BEOWULF = 7405;
		static const auto WEAPON_ID_GUNNER_HERC = 7404;
		static const auto WEAPON_ID_LAUNCHER_BOLT = 7425;
		static const auto WEAPON_ID_LAUNCHER_BOLT_HEAVY = 7452;
		static const auto WEAPON_ID_LAUNCHER_GRENADE = 7416;
		static const auto WEAPON_ID_LAUNCHER_MIRV = 7457;
		static const auto WEAPON_ID_LAUNCHER_MORTAR = 7393;
		static const auto WEAPON_ID_LAUNCHER_SABER = 7398;
		static const auto WEAPON_ID_MELEE = 7391;
		static const auto WEAPON_ID_MINE = 7392;
		static const auto WEAPON_ID_MINE_CLAYMORE = 7421;
		static const auto WEAPON_ID_MINE_PRISM = 7440;
		static const auto WEAPON_ID_MOTIONALARM = 7426;
		static const auto WEAPON_ID_PILOT_BEOWULF = 7406;
		static const auto WEAPON_ID_PILOT_GRAVCYCLE = 7410;
		static const auto WEAPON_ID_PILOT_HAVOC = 7409;
		static const auto WEAPON_ID_PILOT_HERC = 7403;
		static const auto WEAPON_ID_PILOT_SHRIKE = 7407;
		static const auto WEAPON_ID_PISTOL_EAGLE = 7388;
		static const auto WEAPON_ID_PISTOL_EAGLE_CUSTOM = 7439;
		static const auto WEAPON_ID_PISTOL_NOVA_COLT = 7394;
		static const auto WEAPON_ID_PISTOL_NOVA_SLUG = 7431;
		static const auto WEAPON_ID_PISTOL_FALCON = 7419;
		static const auto WEAPON_ID_PISTOL_H1 = 7435;
		static const auto WEAPON_ID_PISTOL_SN7 = 7418;
		static const auto WEAPON_ID_PISTOL_SPARROW = 7433;
		static const auto WEAPON_ID_TURRET_EXR = 7417;
		static const auto WEAPON_ID_TURRET_BASE = 7412;
		static const auto WEAPON_ID_TURRET_LIGHT = 7413;
		static const auto WEAPON_ID_TURRET_WALL = 7445;
		static const auto WEAPON_ID_REPAIR_TOOL = 7396;
		static const auto WEAPON_ID_REPAIR_TOOL_SD = 7436;
		static const auto WEAPON_ID_RIFLE_ASSAULT = 7385;
		static const auto WEAPON_ID_RIFLE_ASSAULT_LIGHT = 7438;
		static const auto WEAPON_ID_RIFLE_ASSAULT_S22 = 7424;
		static const auto WEAPON_ID_RIFLE_ASSAULT_X1 = 7458;
		static const auto WEAPON_ID_RIFLE_PHASE = 7395;
		static const auto WEAPON_ID_RIFLE_SNIPER = 7400;
		static const auto WEAPON_ID_SMG_NJ4 = 7441;
		static const auto WEAPON_ID_SMG_RHINO = 7397;
		static const auto WEAPON_ID_SMG_TCN4 = 7443;
		static const auto WEAPON_ID_SHOTGUN = 7399;
		static const auto WEAPON_ID_SHOTGUN_ARX = 7454;
		static const auto WEAPON_ID_SHOTGUN_AUTO = 7449;
		static const auto WEAPON_ID_SHOTGUN_SAWED_OFF = 7427;
		static const auto WEAPON_ID_SPINFUSOR = 7401;
		static const auto WEAPON_ID_SPINFUSOR_D = 7446;
		static const auto WEAPON_ID_SPINFUSOR_HEAVY = 7448;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT = 7422;
		static const auto WEAPON_ID_SPINFUSOR_TOSS = 7459;
		static const auto WEAPON_ID_CALLIN_TACTICALSTRIKE = 7609;
		static const auto WEAPON_ID_CALLIN_INVENTORYDROP = 7610;
		static const auto WEAPON_ID_CALLIN_ORBITALSTRIKE = 7611;
		static const auto WEAPON_ID_TCNG = 7736;
		static const auto WEAPON_ID_FALLING = 7815;
		static const auto WEAPON_ID_HITWALL = 7816;
		static const auto WEAPON_ID_RANOVER = 7817;
		static const auto WEAPON_ID_THUMPER = 7461;
		static const auto WEAPON_ID_THUMPER_D = 7462;
		static const auto WEAPON_ID_STEALTHLIGHTSPINFUSOR = 7902;
		static const auto WEAPON_ID_GRENADE_T5 = 7914;
		static const auto WEAPON_ID_PROXIMITY_GRENADE = 8222;
		static const auto WEAPON_ID_INFILTRATORBLANK = 8230;
		static const auto WEAPON_ID_ACCURIZEDSHOTGUN = 8239;
		static const auto WEAPON_ID_MINE_ARMOREDCLAYMORE = 8240;
		static const auto WEAPON_ID_BUCKLER = 8242;
		static const auto WEAPON_ID_IMPACTBOMBLETS = 8244;
		static const auto WEAPON_ID_LIGHTTWINFUSOR = 8245;
		static const auto WEAPON_ID_LR1MORTAR = 8246;
		static const auto WEAPON_ID_MIRV_GRENADE = 8247;
		static const auto WEAPON_ID_GRENADE_NINJASMOKE = 8248;
		static const auto WEAPON_ID_NJ5SMG = 8249;
		static const auto WEAPON_ID_PLASMA_CANNON = 8250;
		static const auto WEAPON_ID_PLASMA_GUN = 8251;
		static const auto WEAPON_ID_REMOTE_ARX_BUSTER = 8252;
		static const auto WEAPON_ID_ROCKETLAUNCHER = 8253;
		static const auto WEAPON_ID_SAP20 = 8254;
		static const auto WEAPON_ID_THROWINGKNIVES = 8256;
		static const auto WEAPON_ID_TWINFUSOR = 8257;
		static const auto WEAPON_ID_HEAVYTWINFUSOR = 8656;
		static const auto WEAPON_ID_SPIKELAUNCHER = 8357;
		static const auto WEAPON_ID_TARGETINGBEACON = 8358;
		static const auto ITEM_PACK_AMMO = 7821;
		static const auto ITEM_PACK_BLINK = 7822;
		static const auto ITEM_PACK_DAMAGE = 7823;
		static const auto ITEM_PACK_ENERGY_SOLDIER = 7824;
		static const auto ITEM_PACK_ENERGY_JUGGERNAUT = 7901;
		static const auto ITEM_PACK_ENERGY_BRUTE = 7830;
		static const auto ITEM_PACK_RECHARGE_PATHFINDER = 7825;
		static const auto ITEM_PACK_RECHARGE_SENTINEL = 7900;
		static const auto ITEM_PACK_HEAVYSHIELD = 7826;
		static const auto ITEM_PACK_JAMMER = 7827;
		static const auto ITEM_PACK_LIGHTREGEN = 7828;
		static const auto ITEM_PACK_POWERPOOL = 7829;
		static const auto ITEM_PACK_MINORENERGY = 7830;
		static const auto ITEM_PACK_REGEN = 7831;
		static const auto ITEM_PACK_SHIELD = 7832;
		static const auto ITEM_PACK_STEALTH = 7833;
		static const auto ITEM_PACK_UTILITY_SOLDIER = 8223;
		static const auto ITEM_PACK_HIGHSPEEDSTEALTH = 8243;
		static const auto ITEM_PACK_SURVIVAL = 8255;
		static const auto WEAPON_BASE_UNKNOWN = 0;
		static const auto WEAPON_BASE_SPINFUSOR = 1;
		static const auto WEAPON_BASE_PISTOL = 2;
		static const auto WEAPON_BASE_SNIPERRIFLE = 3;
		static const auto WEAPON_BASE_ASSAULTRIFLE = 4;
		static const auto WEAPON_BASE_GRENADE = 5;
		static const auto WEAPON_BASE_REPAIRTOOL = 6;
		static const auto WEAPON_BASE_CALLIN = 7;
		static const auto WEAPON_BASE_SMG = 8;
		static const auto WEAPON_BASE_SHOTGUN = 9;
		static const auto WEAPON_BASE_VEHICLE = 10;
		static const auto WEAPON_TYPE_UNKNOWN = 0;
		static const auto WEAPON_TYPE_PROJECTILE = 1;
		static const auto WEAPON_TYPE_INSTANTFIRE = 2;
		static const auto ITEM_PERK_BOUNTYHUNTER = 8153;
		static const auto ITEM_PERK_CLOSECOMBAT = 8156;
		static const auto ITEM_PERK_DETERMINATION = 8157;
		static const auto ITEM_PERK_EGOCENTRIC = 7917;
		static const auto ITEM_PERK_LOOTER = 8158;
		static const auto ITEM_PERK_MECHANIC = 8170;
		static const auto ITEM_PERK_PILOT = 8159;
		static const auto ITEM_PERK_POTENTIALENERGY = 8160;
		static const auto ITEM_PERK_QUICKDRAW = 8161;
		static const auto ITEM_PERK_REACH = 7916;
		static const auto ITEM_PERK_SAFEFALL = 8162;
		static const auto ITEM_PERK_SAFETYTHIRD = 8163;
		static const auto ITEM_PERK_STEALTHY = 8164;
		static const auto ITEM_PERK_SUPERCAPACITOR = 8165;
		static const auto ITEM_PERK_SUPERHEAVY = 8166;
		static const auto ITEM_PERK_SURVIVALIST = 8167;
		static const auto ITEM_PERK_ULTRACAPACITOR = 8168;
		static const auto ITEM_PERK_WHEELDEAL = 8169;
		static const auto ITEM_PERK_RAGE = 8232;
		static const auto ITEM_PERK_SONICPUNCH = 8231;
		static const auto ITEM_PERK_LIGHTWEIGHT = 8646;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_AMMO_I = 7508;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_AMMO_II = 7637;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_ANTIARMOR = 7509;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_AMMO_I = 7638;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_AMMO_II = 7640;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_CLIP = 7639;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_FALLOFF = 7641;
		static const auto ITEM_SKILL_PATHFINDER_GRENADE_AMMO = 7504;
		static const auto ITEM_SKILL_PATHFINDER_GRENADE_RADIUS = 7505;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_POOL = 7636;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_REGEN_RATE = 7507;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_REGEN_DELAY = 7506;
		static const auto ITEM_SKILL_PATHFINDER_ENERGY_REGEN_I = 7501;
		static const auto ITEM_SKILL_PATHFINDER_ENERGY_REGEN_II = 7635;
		static const auto ITEM_SKILL_PATHFINDER_SPEED_I = 7502;
		static const auto ITEM_SKILL_PATHFINDER_SPEED_II = 7503;
		static const auto ITEM_SKILL_PATHFINDER_GROUND_SPEED = 7754;
		static const auto ITEM_SKILL_PATHFINDER_STOP_DISTANCE = 7755;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_AMMO_I = 7564;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_AMMO_II = 7646;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_ANTIARMOR = 7645;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_AMMO = 7647;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_RELOAD = 7565;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_FALLOFF = 7648;
		static const auto ITEM_SKILL_JUMPER_GRENADE_AMMO = 7563;
		static const auto ITEM_SKILL_JUMPER_PACK_COST_I = 7558;
		static const auto ITEM_SKILL_JUMPER_PACK_COST_II = 7643;
		static const auto ITEM_SKILL_JUMPER_PACK_POTENCY = 7560;
		static const auto ITEM_SKILL_JUMPER_HEALTH_POOL = 7562;
		static const auto ITEM_SKILL_JUMPER_HEALTH_REGEN_RATE = 7644;
		static const auto ITEM_SKILL_JUMPER_HEALTH_REGEN_DELAY = 7561;
		static const auto ITEM_SKILL_JUMPER_ENERGY_POOL = 7642;
		static const auto ITEM_SKILL_JUMPER_CONTROL = 7557;
		static const auto ITEM_SKILL_JUMPER_SPEED = 7559;
		static const auto ITEM_SKILL_JUMPER_GROUND_SPEED = 7756;
		static const auto ITEM_SKILL_JUMPER_STOP_DISTANCE = 7757;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_AMMO_I = 7551;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_AMMO_II = 7667;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_ANTIARMOR = 7552;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_AMMO = 7670;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_CLIP = 7671;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_RELOAD = 7556;
		static const auto ITEM_SKILL_SOLDIER_GRENADE_AMMO = 7540;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_POOL_I = 7555;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_POOL_II = 7668;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_REGEN_RATE = 7669;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_REGEN_DELAY = 7554;
		static const auto ITEM_SKILL_SOLDIER_ENERGY_POOL_I = 7541;
		static const auto ITEM_SKILL_SOLDIER_ENERGY_POOL_II = 7665;
		static const auto ITEM_SKILL_SOLDIER_CONTROL = 7664;
		static const auto ITEM_SKILL_SOLDIER_SPEED_I = 7548;
		static const auto ITEM_SKILL_SOLDIER_SPEED_II = 7666;
		static const auto ITEM_SKILL_SOLDIER_GROUND_SPEED = 7759;
		static const auto ITEM_SKILL_SOLDIER_STOP_DISTANCE = 7760;
		static const auto ITEM_SKILL_SOLDIER_WEAPON_SWITCH = 7761;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_AMMO_I = 7568;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_AMMO_II = 7658;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_ANTIARMOR = 7569;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_AMMO_I = 7573;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_AMMO_II = 7660;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_ANTIARMOR = 7574;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_AMMO_I = 7566;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_AMMO_II = 7663;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_RADIUS = 7662;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_POOL_I = 7576;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_POOL_II = 7661;
		static const auto ITEM_SKILL_JUGGERNAUGHT_ENERGY_POOL_I = 7572;
		static const auto ITEM_SKILL_JUGGERNAUGHT_ENERGY_POOL_II = 7659;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_REGEN_DELAY = 7575;
		static const auto ITEM_SKILL_JUGGERNAUGHT_CONTROL = 7657;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SPEED = 7570;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GROUND_SPEED = 7770;
		static const auto ITEM_SKILL_JUGGERNAUGHT_WEAPON_SWITCH = 7771;
		static const auto ITEM_SKILL_TECHNICIAN_PRIMARY_AMMO = 7685;
		static const auto ITEM_SKILL_TECHNICIAN_PRIMARY_RELOAD = 7686;
		static const auto ITEM_SKILL_TECHNICIAN_REPAIR_RATE_I = 7519;
		static const auto ITEM_SKILL_TECHNICIAN_REPAIR_RATE_II = 7681;
		static const auto ITEM_SKILL_TECHNICIAN_GRENADE_AMMO_I = 7518;
		static const auto ITEM_SKILL_TECHNICIAN_GRENADE_AMMO_II = 7687;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_ACQUIRE = 7512;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_LIMIT = 7513;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_ANTIARMOR = 7514;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_POOL_I = 7520;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_POOL_II = 7684;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_REGEN_DELAY = 7516;
		static const auto ITEM_SKILL_TECHNICIAN_ENERGY_POOL = 7515;
		static const auto ITEM_SKILL_TECHNICIAN_CONTROL = 7517;
		static const auto ITEM_SKILL_TECHNICIAN_SPEED_I = 7682;
		static const auto ITEM_SKILL_TECHNICIAN_SPEED_II = 7683;
		static const auto ITEM_SKILL_TECHNICIAN_GROUND_SPEED = 7765;
		static const auto ITEM_SKILL_TECHNICIAN_STOP_DISTANCE = 7766;
		static const auto ITEM_SKILL_TECHNICIAN_WEAPON_SWITCH = 7767;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_AMMO_I = 7528;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_AMMO_II = 7655;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_CLIP = 7654;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_FALLOFF = 7529;
		static const auto ITEM_SKILL_SENTINEL_SECONDARY_AMMO = 7651;
		static const auto ITEM_SKILL_SENTINEL_SECONDARY_CLIP = 7652;
		static const auto ITEM_SKILL_SENTINEL_GRENADE_AMMO = 7527;
		static const auto ITEM_SKILL_SENTINEL_GRENADE_RADIUS = 7656;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_HEALTH = 7649;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_RADIUS_I = 7521;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_RADIUS_II = 7650;
		static const auto ITEM_SKILL_SENTINEL_HEALTH_REGEN_RATE = 7526;
		static const auto ITEM_SKILL_SENTINEL_HEALTH_REGEN_DELAY = 7525;
		static const auto ITEM_SKILL_SENTINEL_ENERGY_POOL_I = 7523;
		static const auto ITEM_SKILL_SENTINEL_ENERGY_POOL_II = 7653;
		static const auto ITEM_SKILL_SENTINEL_SPEED = 7524;
		static const auto ITEM_SKILL_SENTINEL_WEAPON_SWITCH = 7758;
		static const auto ITEM_SKILL_RANGER_PRIMARY_AMMO = 7679;
		static const auto ITEM_SKILL_RANGER_PRIMARY_CLIP = 7680;
		static const auto ITEM_SKILL_RANGER_PRIMARY_RELOAD = 7582;
		static const auto ITEM_SKILL_RANGER_SECONDARY_AMMO_I = 7581;
		static const auto ITEM_SKILL_RANGER_SECONDARY_AMMO_II = 7675;
		static const auto ITEM_SKILL_RANGER_SECONDARY_ANTIARMOR = 7674;
		static const auto ITEM_SKILL_RANGER_GRENADE_AMMO_I = 7580;
		static const auto ITEM_SKILL_RANGER_GRENADE_AMMO_II = 7677;
		static const auto ITEM_SKILL_RANGER_PACK_COST = 7583;
		static const auto ITEM_SKILL_RANGER_HEALTH_POOL_I = 7585;
		static const auto ITEM_SKILL_RANGER_HEALTH_POOL_II = 7676;
		static const auto ITEM_SKILL_RANGER_HEALTH_REGEN_DELAY = 7584;
		static const auto ITEM_SKILL_RANGER_ENERGY_POOL_I = 7577;
		static const auto ITEM_SKILL_RANGER_ENERGY_POOL_II = 7678;
		static const auto ITEM_SKILL_RANGER_CONTROL = 7672;
		static const auto ITEM_SKILL_RANGER_SPEED_I = 7578;
		static const auto ITEM_SKILL_RANGER_SPEED_II = 7673;
		static const auto ITEM_SKILL_RANGER_GROUND_SPEED = 7762;
		static const auto ITEM_SKILL_RANGER_STOP_DISTANCE = 7763;
		static const auto ITEM_SKILL_RANGER_WEAPON_SWITCH = 7764;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_AMMO_I = 7598;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_AMMO_II = 7632;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_SPINUP = 7597;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_AMMO_I = 7590;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_AMMO_II = 7634;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_AMMO = 7591;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_ANTIARMOR = 7633;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_HEALTH_I = 7592;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_HEALTH_II = 7629;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_POOL_I = 7596;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_POOL_II = 7631;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_REGEN_DELAY = 7595;
		static const auto ITEM_SKILL_DOOMBRINGER_ENERGY_POOL = 7628;
		static const auto ITEM_SKILL_DOOMBRINGER_CONTROL = 7594;
		static const auto ITEM_SKILL_DOOMBRINGER_SPEED_I = 7593;
		static const auto ITEM_SKILL_DOOMBRINGER_SPEED_II = 7630;
		static const auto ITEM_SKILL_DOOMBRINGER_GROUND_SPEED = 7772;
		static const auto ITEM_SKILL_DOOMBRINGER_STOP_DISTANCE = 7773;
		static const auto ITEM_SKILL_DOOMBRINGER_WEAPON_SWITCH = 7774;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_AMMO_I = 7612;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_AMMO_II = 7818;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_RELOAD = 7614;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_FALLOFF = 7613;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_AMMO = 7623;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_CLIP = 7625;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_RELOAD = 7624;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_AMMO_I = 7615;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_AMMO_II = 7618;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_RADIUS = 7617;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_ANTIARMOR = 7616;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_COST_I = 7620;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_COST_II = 7622;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_POTENCY = 7621;
		static const auto ITEM_SKILL_INFILTRATOR_HEALTH_REGEN_RATE = 7627;
		static const auto ITEM_SKILL_INFILTRATOR_HEALTH_REGEN_DELAY = 7626;
		static const auto ITEM_SKILL_INFILTRATOR_ENERGY_POOL = 7619;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_AMMO = 7688;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_RELOAD = 7690;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_FALLOFF = 7689;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_AMMO = 7691;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_CLIP = 7693;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_ANTIARMOR = 7692;
		static const auto ITEM_SKILL_RAIDER_GRENADE_AMMO = 7694;
		static const auto ITEM_SKILL_RAIDER_GRENADE_EFFECT = 7695;
		static const auto ITEM_SKILL_RAIDER_GRENADE_RADIUS = 7696;
		static const auto ITEM_SKILL_RAIDER_PACK_COST_I = 7700;
		static const auto ITEM_SKILL_RAIDER_PACK_COST_II = 7703;
		static const auto ITEM_SKILL_RAIDER_PACK_POTENCY = 7701;
		static const auto ITEM_SKILL_RAIDER_HEALTH_POOL_I = 7698;
		static const auto ITEM_SKILL_RAIDER_HEALTH_POOL_II = 7699;
		static const auto ITEM_SKILL_RAIDER_HEALTH_REGEN_DELAY = 7697;
		static const auto ITEM_SKILL_RAIDER_ENERGY_POOL = 7702;
		static const auto ITEM_SKILL_BRUTE_ENERGY_POOL = 7723;
		static const auto ITEM_SKILL_BRUTE_GRENADE_AMMO = 7720;
		static const auto ITEM_SKILL_BRUTE_GRENADE_DURATION = 7721;
		static const auto ITEM_SKILL_BRUTE_GRENADE_RADIUS = 7722;
		static const auto ITEM_SKILL_BRUTE_HEALTH_POOL_I = 7729;
		static const auto ITEM_SKILL_BRUTE_HEALTH_POOL_II = 7732;
		static const auto ITEM_SKILL_BRUTE_HEALTH_REGEN_DELAY = 7730;
		static const auto ITEM_SKILL_BRUTE_HEALTH_REGEN_RATE = 7731;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_AMMO_I = 7726;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_AMMO_II = 7728;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_ANTIARMOR = 7727;
		static const auto ITEM_SKILL_BRUTE_SECONARY_AMMO = 7733;
		static const auto ITEM_SKILL_BRUTE_SECONDARY_CLIP = 7735;
		static const auto ITEM_SKILL_BRUTE_SECONDARY_RELOAD = 7734;
		static const auto ITEM_SKILL_BRUTE_CONTROL = 7725;
		static const auto ITEM_SKILL_BRUTE_SPEED = 7724;
		static const auto ITEM_SKILL_BRUTE_GROUND_SPEED = 7775;
		static const auto ITEM_SKILL_BRUTE_WEAPON_SWITCH = 7776;
		static const auto ITEM_SKILL_SCRAMBLER_ENERGY_POOL = 7707;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_AMMO = 7704;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_DURATION = 7706;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_RADIUS = 7705;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_POOL_I = 7714;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_POOL_II = 7715;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_REGEN_DELAY = 7713;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_COST_I = 7716;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_COST_II = 7718;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_EFFECTIVENESS_I = 7717;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_EFFECTIVENESS_II = 7719;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_AMMO_I = 7710;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_AMMO_II = 7712;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_ANTIARMOR = 7711;
		static const auto ITEM_SKILL_SCRAMBLER_CONTROL = 7709;
		static const auto ITEM_SKILL_SCRAMBLER_SPEED = 7708;
		static const auto ITEM_SKILL_SCRAMBLER_GROUND_SPEED = 7768;
		static const auto ITEM_SKILL_SCRAMBLER_WEAPON_SWITCH = 7769;
		static const auto ITEM_SKILL_WRAITH_ENERGY_POOL = 7790;
		static const auto ITEM_SKILL_WRAITH_ENERGY_REGEN_I = 7781;
		static const auto ITEM_SKILL_WRAITH_ENERGY_REGEN_II = 7783;
		static const auto ITEM_SKILL_WRAITH_GRENADE_AMMO = 7788;
		static const auto ITEM_SKILL_WRAITH_GRENADE_RADIUS = 7789;
		static const auto ITEM_SKILL_WRAITH_GROUND_SPEED = 7782;
		static const auto ITEM_SKILL_WRAITH_HEALTH_REGEN_DELAY = 7791;
		static const auto ITEM_SKILL_WRAITH_HEALTH_REGEN_RATE = 7792;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_AMMO_I = 7793;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_AMMO_II = 7796;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_CLIP = 7795;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_ENERGY_COST = 7794;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_AMMO = 7784;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_CLIP_I = 7785;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_CLIP_II = 7786;
		static const auto ITEM_SKILL_WRAITH_WEAPON_SWITCH = 7787;
		static const auto TR_MAX_CALLINS = 3;
		static const auto PROPERTY_CALLIN_ORBITALSTRIKE = 10241;
		static const auto PROPERTY_CALLIN_TACTICALSTRIKE = 10201;
		static const auto PROPERTY_CALLIN_SUPPORTINVENTORY = 10234;
		static const auto ITEM_SKIN_PATHFINDER = 7834;
		static const auto ITEM_SKIN_PATHFINDER_MERC = 8326;
		static const auto ITEM_SKIN_INFILTRATOR = 7835;
		static const auto ITEM_SKIN_INFILTRATOR_ASSASSIN = 8337;
		static const auto ITEM_SKIN_INFILTRATOR_MERC = 8336;
		static const auto ITEM_SKIN_SENTINEL = 8327;
		static const auto ITEM_SKIN_SENTINEL_MERC = 8665;
		static const auto ITEM_SKIN_SOLDIER = 8328;
		static const auto ITEM_SKIN_TECHNICIAN = 8329;
		static const auto ITEM_SKIN_TECHNICIAN_MERC = 8731;
		static const auto ITEM_SKIN_RAIDER = 8330;
		static const auto ITEM_SKIN_RAIDER_GRIEVER = 8351;
		static const auto ITEM_SKIN_RAIDER_MERC = 8352;
		static const auto ITEM_SKIN_JUGGERNAUT = 8331;
		static const auto ITEM_SKIN_DOOMBRINGER = 8332;
		static const auto ITEM_SKIN_BRUTE = 8333;
		static const auto ITEM_SKIN_BRUTE_MERC = 8663;
		static const auto ITEM_VOICE_LIGHT_STANDARD = 7903;
		static const auto ITEM_VOICE_MEDIUM_STANDARD = 7904;
		static const auto ITEM_VOICE_HEAVY_STANDARD = 7905;
		static const auto ITEM_ARMOR_MOD_PATHFINDER = 7836;
		static const auto ITEM_ARMOR_MOD_SENTINEL = 7837;
		static const auto ITEM_ARMOR_MOD_INFILTRATOR = 7838;
		static const auto ITEM_ARMOR_MOD_SOLDIER = 7839;
		static const auto ITEM_ARMOR_MOD_TECHNICIAN = 7840;
		static const auto ITEM_ARMOR_MOD_RAIDER = 7841;
		static const auto ITEM_ARMOR_MOD_JUGGERNAUT = 7842;
		static const auto ITEM_ARMOR_MOD_DOOMBRINGER = 7843;
		static const auto ITEM_ARMOR_MOD_BRUTE = 7844;
		static const auto WEAPON_ID_ARX_BUSTER_MKD = 8391;
		static const auto WEAPON_ID_CHAINGUN_MKD = 8392;
		static const auto WEAPON_ID_GRENADE_MKD = 8393;
		static const auto WEAPON_ID_GRENADE_AP_HEAVY_MKD = 8394;
		static const auto WEAPON_ID_GRENADE_EMP_MKD = 8395;
		static const auto WEAPON_ID_GRENADE_NITRON_MKD = 8396;
		static const auto WEAPON_ID_GRENADE_SPIKE_MKD = 8397;
		static const auto WEAPON_ID_GRENADE_STICKY_MKD = 8398;
		static const auto WEAPON_ID_GRENADE_XL_MKD = 8399;
		static const auto WEAPON_ID_LAUNCHER_MORTAR_MKD = 8400;
		static const auto WEAPON_ID_LAUNCHER_SABER_MKD = 8401;
		static const auto WEAPON_ID_MINE_CLAYMORE_MKD = 8402;
		static const auto WEAPON_ID_PISTOL_NOVA_COLT_MKD = 8403;
		static const auto WEAPON_ID_PISTOL_SN7_MKD = 8404;
		static const auto WEAPON_ID_REPAIR_TOOL_SD_MKD = 8405;
		static const auto WEAPON_ID_RIFLE_ASSAULT_MKD = 8406;
		static const auto WEAPON_ID_RIFLE_SNIPER_MKD = 8407;
		static const auto WEAPON_ID_SMG_NJ4_MKD = 8408;
		static const auto WEAPON_ID_SMG_RHINO_MKD = 8409;
		static const auto WEAPON_ID_SMG_TCN4_MKD = 8410;
		static const auto WEAPON_ID_SHOTGUN_MKD = 8411;
		static const auto WEAPON_ID_SHOTGUN_AUTO_MKD = 8412;
		static const auto WEAPON_ID_SPINFUSOR_D_MKD = 8413;
		static const auto WEAPON_ID_SPINFUSOR_HEAVY_MKD = 8414;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT_MKD = 8415;
		static const auto WEAPON_ID_TCNG_MKD = 8416;
		static const auto WEAPON_ID_THUMPERD_MKD = 8417;
		static const auto WEAPON_ID_REPAIR_DEPLOYABLE = 8698;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT_100X = 8696;
		static const auto WEAPON_ID_SPINFUSOR_100X = 8697;
		static const auto WEAPON_ID_TC24 = 8699;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X = 8700;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X = 8701;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X = 8702;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X = 8703;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X = 8704;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X = 8705;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE = 8706;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE = 8707;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE = 8708;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24 = 8709;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24 = 8710;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24 = 8711;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR_100X = 265;
		static const auto ACTIVITY_TECHNICIAN_BELT_REPAIR_DEPLOYABLE = 266;
		static const auto ACTIVITY_SOLDIER_PRIMARY_SPINFUSOR_100X = 264;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TC24 = 267;
		static const auto ACTIVITY_SENTINEL_PRIMARY_SAP20 = 268;
		static const auto ACTIVITY_SENTINEL_SECONDARY_ACCURIZEDSHOTGUN = 269;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD = 8418;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD = 8419;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD = 8420;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD = 8421;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD = 8422;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD = 8423;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD = 8424;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD = 8425;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD = 8426;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD = 8427;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD = 8428;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD = 8429;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD = 8430;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD = 8431;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD = 8432;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD = 8433;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD = 8434;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD = 8435;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD = 8436;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD = 8437;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD = 8438;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD = 8439;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD = 8440;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD = 8441;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD = 8442;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD = 8443;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD = 8444;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD = 8445;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD = 8446;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD = 8447;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD = 8448;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD = 8449;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR = 8657;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR = 8658;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR = 8659;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD = 8450;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD = 8451;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD = 8452;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD = 8453;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD = 8454;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD = 8455;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD = 8456;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD = 8457;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD = 8458;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD = 8459;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD = 8460;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD = 8461;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD = 8462;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD = 8463;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD = 8464;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD = 8465;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD = 8466;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD = 8467;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD = 8468;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD = 8469;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD = 8470;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD = 8471;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD = 8472;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD = 8473;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD = 8474;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD = 8475;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD = 8476;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD = 8477;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD = 8478;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD = 8479;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD = 8480;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD = 8481;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD = 8482;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD = 8483;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD = 8484;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD = 8486;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD = 8487;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD = 8488;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD = 8489;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD = 8490;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD = 8491;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD = 8492;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD = 8493;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD = 8494;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD = 8495;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD = 8496;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD = 8497;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD = 8498;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD = 8499;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD = 8500;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD = 8501;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD = 8502;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD = 8503;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD = 8504;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD = 8505;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD = 8506;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD = 8507;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER = 7850;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER = 7851;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER = 7852;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR = 7855;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR = 7860;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR = 7857;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR = 8277;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR = 8278;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR = 8279;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE = 7927;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE = 7929;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE = 7930;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE = 7931;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE = 7932;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE = 7933;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE = 7934;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE = 7935;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20 = 8305;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20 = 8306;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20 = 8307;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20 = 8308;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG = 7960;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG = 7961;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG = 7962;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG = 7963;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR = 7964;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR = 7965;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR = 7966;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER = 8298;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER = 8299;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER = 8300;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE = 7985;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE = 7986;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE = 7987;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE = 7988;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR = 7992;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR = 7993;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR = 7994;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR = 8316;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR = 8317;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR = 8318;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG = 8012;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG = 8013;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG = 8014;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG = 8015;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER = 8016;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER = 8017;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER = 8018;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER = 8045;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER = 8046;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER = 8047;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER = 8042;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER = 8043;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER = 8044;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR = 8070;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR = 8071;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR = 8072;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER = 8073;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER = 8074;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER = 8075;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR = 8280;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR = 8281;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR = 8282;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN = 8100;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN = 8101;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN = 8102;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN = 8103;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER = 8104;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER = 8105;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER = 8106;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR = 8124;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR = 8125;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR = 8126;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON = 8292;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON = 8293;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON = 8294;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER = 8386;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER = 8387;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER = 8388;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN = 7861;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN = 7862;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN = 7863;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE = 7866;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE = 7867;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE = 7868;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE = 7869;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER = 8265;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER = 8266;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER = 8267;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER = 7936;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER = 7937;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER = 7938;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL = 7939;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL = 7940;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL = 7941;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL = 7942;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN = 8258;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN = 8259;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN = 8260;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN = 8261;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL = 7967;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL = 7968;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL = 7969;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES = 8312;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES = 8313;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES = 8314;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES = 8315;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL = 7995;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL = 7996;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL = 7997;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD = 7989;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD = 7990;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD = 7991;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN = 8295;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN = 8296;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN = 8297;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD = 8019;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD = 8020;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD = 8021;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN = 8022;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN = 8023;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN = 8024;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL = 8025;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL = 8026;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL = 8027;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG = 8048;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG = 8049;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG = 8050;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG = 8051;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG = 8289;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG = 8290;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG = 8291;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG = 8304;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD = 8076;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD = 8077;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD = 8078;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG = 8079;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG = 8080;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG = 8081;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG = 8082;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER = 8107;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER = 8108;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER = 8109;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER = 8301;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER = 8302;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER = 8303;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN = 8127;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN = 8128;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN = 8129;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN = 8130;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT = 8131;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT = 8132;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT = 8133;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT = 8134;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON = 7881;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON = 7882;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON = 7883;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST = 7888;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST = 7889;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST = 7890;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS = 8274;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS = 8275;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS = 8276;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE = 7943;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE = 7944;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE = 7945;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL = 7946;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL = 7947;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL = 7948;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE = 8262;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE = 8263;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE = 8264;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE = 7970;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE = 7971;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE = 7972;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE = 7973;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES = 7974;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES = 7975;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES = 7976;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE = 8286;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE = 8287;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE = 8288;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL = 7998;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL = 7999;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL = 8000;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE = 8001;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE = 8002;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE = 8003;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE = 8227;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE = 8228;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE = 8229;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE = 8028;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE = 8029;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE = 8030;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM = 8031;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM = 8032;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM = 8033;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE = 8052;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE = 8053;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE = 8054;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE = 8055;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE = 8056;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE = 8057;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE = 8283;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE = 8284;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE = 8285;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE = 8083;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE = 8084;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE = 8085;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS = 8086;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS = 8087;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS = 8088;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE = 8110;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE = 8111;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE = 8112;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES = 8113;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES = 8114;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES = 8115;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE = 8135;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE = 8136;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE = 8137;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE = 8138;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE = 8139;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE = 8140;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK = 7871;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK = 7872;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK = 7873;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK = 7876;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK = 7877;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK = 7878;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER = 7949;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER = 7950;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER = 7951;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK = 7952;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK = 7953;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK = 7954;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK = 7977;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK = 7978;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK = 7979;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH = 8271;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH = 8272;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH = 8273;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK = 8004;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK = 8005;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK = 8006;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK = 8224;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK = 8225;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK = 8226;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET = 8034;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET = 8035;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET = 8036;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET = 8268;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET = 8269;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET = 8270;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK = 8058;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK = 8059;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK = 8060;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK = 8061;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK = 8062;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK = 8063;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK = 8064;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK = 8089;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK = 8090;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK = 8091;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK = 8092;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK = 8093;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK = 8094;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK = 8309;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK = 8310;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK = 8311;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD = 8116;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD = 8117;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD = 8118;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK = 8141;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK = 8142;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK = 8143;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK = 8144;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK = 8145;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK = 8146;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR = 7893;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR = 7894;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR = 7895;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR = 7896;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR = 7897;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR = 7955;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR = 7956;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR = 7957;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR = 7958;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR = 7959;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR = 7980;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR = 7981;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR = 7982;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR = 7983;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR = 7984;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR = 8007;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR = 8008;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR = 8009;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR = 8010;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR = 8011;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR = 8037;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR = 8038;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR = 8039;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR = 8040;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR = 8041;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR = 8065;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR = 8066;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR = 8067;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR = 8068;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR = 8069;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR = 8095;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR = 8096;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR = 8097;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR = 8098;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR = 8099;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR = 8119;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR = 8120;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR = 8121;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR = 8122;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR = 8123;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR = 8147;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR = 8148;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR = 8149;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR = 8150;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR = 8151;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER = 8188;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER = 8189;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER = 8190;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT = 8194;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT = 8195;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT = 8196;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC = 8173;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC = 8174;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC = 8175;
		static const auto ITEM_PERK_UPGRADE_LOOTER = 8185;
		static const auto ITEM_PERK_UPGRADE_LOOTER = 8186;
		static const auto ITEM_PERK_UPGRADE_LOOTER = 8187;
		static const auto ITEM_PERK_UPGRADE_MECHANIC = 8215;
		static const auto ITEM_PERK_UPGRADE_MECHANIC = 8216;
		static const auto ITEM_PERK_UPGRADE_MECHANIC = 8217;
		static const auto ITEM_PERK_UPGRADE_PILOT = 8179;
		static const auto ITEM_PERK_UPGRADE_PILOT = 8180;
		static const auto ITEM_PERK_UPGRADE_PILOT = 8181;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY = 8200;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY = 8201;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY = 8202;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW = 8209;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW = 8210;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW = 8211;
		static const auto ITEM_PERK_UPGRADE_REACH = 8152;
		static const auto ITEM_PERK_UPGRADE_REACH = 8171;
		static const auto ITEM_PERK_UPGRADE_REACH = 8172;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL = 8176;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL = 8177;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL = 8178;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD = 8212;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD = 8213;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD = 8214;
		static const auto ITEM_PERK_UPGRADE_STEALTHY = 8206;
		static const auto ITEM_PERK_UPGRADE_STEALTHY = 8207;
		static const auto ITEM_PERK_UPGRADE_STEALTHY = 8208;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY = 8197;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY = 8198;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY = 8199;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST = 8191;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST = 8192;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST = 8193;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR = 8203;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR = 8204;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR = 8205;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL = 8182;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL = 8183;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL = 8184;
		static const auto ITEM_PERK_UPGRADE_RAGE = 8236;
		static const auto ITEM_PERK_UPGRADE_RAGE = 8237;
		static const auto ITEM_PERK_UPGRADE_RAGE = 8238;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH = 8233;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH = 8234;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH = 8235;
		static const auto ITEM_UPGRADE_TEMP = 99999;
		static const auto SHOP_VENDOR_GOLD = 507;
		static const auto SHOP_VENDOR_BUNDLES = 518;
		static const auto SHOP_VENDOR_BOOSTERS = 508;
		static const auto SHOP_VENDOR_NAMECHANGE = 512;
		static const auto SHOP_VENDOR_CLANTAG = 545;
		static const auto SKIN_INFILTRATOR_BE = 6;
		static const auto SKIN_INFILTRATOR_DS = 7;
		static const auto SKIN_SENTINEL_BE = 8;
		static const auto SKIN_SENTINEL_DS = 9;
		static const auto SKIN_RAIDER_BE = 10;
		static const auto SKIN_RAIDER_DS = 11;
		static const auto SKIN_TECHNICIAN_BE = 12;
		static const auto SKIN_TECHNICIAN_DS = 13;
		static const auto SKIN_DOOMBRINGER_BE = 14;
		static const auto SKIN_DOOMBRINGER_DS = 15;
		static const auto SKIN_JUGGERNAUT_BE = 16;
		static const auto SKIN_JUGGERNAUT_DS = 17;
		static const auto SKIN_BRUTE_BE = 18;
		static const auto SKIN_BRUTE_DS = 19;
		static const auto SKIN_SOLDIER_BE = 20;
		static const auto SKIN_SOLDIER_DS = 21;
		static const auto SKIN_PATHFINDER_BE = 22;
		static const auto SKIN_PATHFINDER_DS = 23;
		static const auto SKIN_PATHFINDER_MC = 24;
		static const auto SKIN_INFILTRATOR_AS = 25;
		static const auto SKIN_INFILTRATOR_MC = 26;
		static const auto SKIN_RAIDER_GV = 25;
		static const auto SKIN_RAIDER_MC = 26;
		static const auto SKIN_SENTINEL_MC = 27;
		static const auto SKIN_BRUTE_MC = 28;
		static const auto SKIN_TECHNICIAN_MC = 29;
		static const auto QUEUE_CONFIG_SERVERNAME = 1243;
		static const auto QUEUE_CONFIG_ADMINPASSWORD = 1245;
		static const auto QUEUE_CONFIG_GENPASSWORD = 1246;
		static const auto QUEUE_CONFIG_SLOTS = 1247;
		static const auto QUEUE_CONFIG_MATCHQUEUEID = 1253;
		static const auto QUEUE_CONFIG_SERVERDESCRIPTION = 1255;
		static const auto QUEUE_CONFIG_MAPROTATIONTYPE = 1256;
		static const auto QUEUE_CONFIG_MAPSLOT1 = 1257;
		static const auto QUEUE_CONFIG_MAPSLOT2 = 1258;
		static const auto QUEUE_CONFIG_MAPSLOT3 = 1259;
		static const auto QUEUE_CONFIG_MAPSLOT4 = 1260;
		static const auto QUEUE_CONFIG_MAPSLOT5 = 1261;
		static const auto QUEUE_CONFIG_MAPSLOT6 = 1262;
		static const auto QUEUE_CONFIG_MAPSLOT7 = 1263;
		static const auto QUEUE_CONFIG_MAPSLOT8 = 1264;
		static const auto QUEUE_CONFIG_SITEID = 1272;
		static const auto QUEUE_CONFIG_MINLEVEL = 1296;
		static const auto QUEUE_CONFIG_MAXLEVEL = 1297;
		static const auto GAME_CONFIG_TIMELIMIT = 1059;
		static const auto GAME_CONFIG_MAXPLAYERS = 1060;
		static const auto GAME_CONFIG_AUTOBALANCE = 1062;
		static const auto GAME_CONFIG_OVERTIMELIMIT = 1063;
		static const auto GAME_CONFIG_RESPAWNTIME = 1064;
		static const auto GAME_CONFIG_FRIENDLYFIRE = 1065;
		static const auto GAME_CONFIG_GENAUTOREGEN = 1066;
		static const auto GAME_CONFIG_UPGRADES = 1067;
		static const auto GAME_CONFIG_SPAWNNAKED = 1068;
		static const auto GAME_CONFIG_BASEASSETS = 1070;
		static const auto GAME_CONFIG_POWERDEPLOYS = 1072;
		static const auto GAME_CONFIG_VEHICLELIMITS = 1075;
		static const auto GAME_CONFIG_VGRAVCYCLELIMIT = 1268;
		static const auto GAME_CONFIG_VBEOWULFLIMIT = 1269;
		static const auto GAME_CONFIG_VSHRIKELIMIT = 1270;
		static const auto GAME_CONFIG_VBEOWULFPRICE = 1076;
		static const auto GAME_CONFIG_VGRAVPRICE = 1077;
		static const auto GAME_CONFIG_VSHRIKEPRICE = 1080;
		static const auto GAME_CONFIG_TEAMJOINTYPE = 1081;
		static const auto GAME_CONFIG_FFMULTIPLIER = 1123;
		static const auto GAME_CONFIG_CALLINSDENIED = 1233;
		static const auto GAME_CONFIG_CALLINPRICETAC = 1234;
		static const auto GAME_CONFIG_CALLINPRICESUP = 1235;
		static const auto GAME_CONFIG_CALLINPRICEORB = 1236;
		static const auto GAME_CONFIG_CALLINCLDWNTAC = 1237;
		static const auto GAME_CONFIG_CALLINCLDWNSUP = 1238;
		static const auto GAME_CONFIG_CALLINCLDWNORB = 1239;
		static const auto GAME_CONFIG_CALLINBLDUPTAC = 1249;
		static const auto GAME_CONFIG_CALLINBLDUPSUP = 1250;
		static const auto GAME_CONFIG_CALLINBLDUPORB = 1251;
		static const auto GAME_CONFIG_BASEDESTLIMIT = 1241;
		static const auto GAME_CONFIG_WARMUPTIME = 1248;
		static const auto GAME_CONFIG_TEAMDISPARITY = 1252;
		static const auto GAME_CONFIG_CONFIGCASEID = 1254;
		static const auto GAME_CONFIG_ARENAROUNDS = 1265;
		static const auto GAME_CONFIG_SCORELIMIT_CTF = 1061;
		static const auto GAME_CONFIG_SCORELIMIT_RAB = 1278;
		static const auto GAME_CONFIG_SCORELIMIT_TDM = 1276;
		static const auto GAME_CONFIG_SCORELIMIT_ARN = 1277;
		static const auto GAME_CONFIG_SCORELIMIT_CAH = 1279;
		static const auto GAME_CONFIG_GAMETYPE = 1244;
		static const auto GAME_CONFIG_GENDESTROYABLE = 1280;
		static const auto GAME_CONFIG_INVDESTROYABLE = 1281;
		static const auto GAME_CONFIG_FFDEPLOYABLES = 1282;
		static const auto GAME_CONFIG_FFBASEASSETS = 1283;
		static const auto GAME_CONFIG_FFDMGLIMIT = 1284;
		static const auto GAME_CONFIG_FFKILLLIMIT = 1285;
		static const auto GAME_CONFIG_SUPPLYDROPAMMOONLY = 1286;
		static const auto GAME_CONFIG_CLASSCOUNT_PTH = 1287;
		static const auto GAME_CONFIG_CLASSCOUNT_SEN = 1289;
		static const auto GAME_CONFIG_CLASSCOUNT_INF = 1288;
		static const auto GAME_CONFIG_CLASSCOUNT_SLD = 1290;
		static const auto GAME_CONFIG_CLASSCOUNT_TCN = 1291;
		static const auto GAME_CONFIG_CLASSCOUNT_RDR = 1292;
		static const auto GAME_CONFIG_CLASSCOUNT_JUG = 1293;
		static const auto GAME_CONFIG_CLASSCOUNT_DMB = 1294;
		static const auto GAME_CONFIG_CLASSCOUNT_BRT = 1295;
		static const auto GAME_CONFIG_POWEREDCALLINS = 1298;
		static const auto GAME_CONFIG_TEAMCREDITS = 1299;
		static const auto GAME_CONFIG_VEHICLEHEALTHMULT = 1327;
		static const auto GAME_CONFIG_SKIENABLED = 1373;
		static const auto GAME_CONFIG_ENERGYMULTIPLIER = 1374;
		static const auto GAME_CONFIG_AOESIZEMULTIPLIER = 1375;
		static const auto GAME_CONFIG_AOEDAMAGEMULTIPLIER = 1376;
		static const auto GAME_CONFIG_CTFBLITZALLFLAGSMOVE = 1377;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGLIGHT = 1391;
		static const auto GAME_CONFIG_DECELERATIONRATEWITHFLAG = 1392;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGMEDIUM = 1395;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGHEAVY = 1396;
		static const auto SERVER_RT_METHOD_RANDOM = 10070;
		static const auto SERVER_RT_METHOD_LINEAR = 10071;
		static const auto SERVER_RT_METHOD_LINEAR2 = 10072;
		static const auto SERVER_RT_METHOD_LINEAR4 = 10073;
		static const auto TR_MAX_GAMETYPES = 5;
		static const auto SERVER_GAMECLASSID_CTF = 197;
		static const auto SERVER_GAMECLASSID_RAB = 8012;
		static const auto SERVER_GAMECLASSID_TDM = 8036;
		static const auto SERVER_GAMECLASSID_ARN = 8086;
		static const auto SERVER_GAMECLASSID_CAH = 8094;
		static const auto SERVER_GAMECLASSID_BTZ = 8118;
		static const auto SERVER_DEFAULT_MAP_CTF = 1462;
		static const auto SERVER_DEFAULT_MAP_RAB = 1465;
		static const auto SERVER_DEFAULT_MAP_TDM = 1488;
		static const auto SERVER_DEFAULT_MAP_ARN = 1495;
		static const auto SERVER_DEFAULT_MAP_CAH = 1519;
		static const auto SERVER_DEFAULT_MAP_BTZ = 1539;
		static const auto PTH_LOADOUT_ONE = 8359;
		static const auto PTH_LOADOUT_TWO = 8360;
		static const auto PTH_LOADOUT_THREE = 8361;
		static const auto PTH_LOADOUT_FOUR = 8674;
		static const auto PTH_LOADOUT_FIVE = 8675;
		static const auto INF_LOADOUT_ONE = 8362;
		static const auto INF_LOADOUT_TWO = 8363;
		static const auto INF_LOADOUT_THREE = 8364;
		static const auto INF_LOADOUT_FOUR = 8676;
		static const auto INF_LOADOUT_FIVE = 8677;
		static const auto SEN_LOADOUT_ONE = 8365;
		static const auto SEN_LOADOUT_TWO = 8366;
		static const auto SEN_LOADOUT_THREE = 8367;
		static const auto SEN_LOADOUT_FOUR = 8678;
		static const auto SEN_LOADOUT_FIVE = 8679;
		static const auto SLD_LOADOUT_ONE = 8368;
		static const auto SLD_LOADOUT_TWO = 8369;
		static const auto SLD_LOADOUT_THREE = 8370;
		static const auto SLD_LOADOUT_FOUR = 8680;
		static const auto SLD_LOADOUT_FIVE = 8681;
		static const auto TCN_LOADOUT_ONE = 8371;
		static const auto TCN_LOADOUT_TWO = 8372;
		static const auto TCN_LOADOUT_THREE = 8373;
		static const auto TCN_LOADOUT_FOUR = 8682;
		static const auto TCN_LOADOUT_FIVE = 8683;
		static const auto RDR_LOADOUT_ONE = 8374;
		static const auto RDR_LOADOUT_TWO = 8375;
		static const auto RDR_LOADOUT_THREE = 8376;
		static const auto RDR_LOADOUT_FOUR = 8684;
		static const auto RDR_LOADOUT_FIVE = 8685;
		static const auto JUG_LOADOUT_ONE = 8377;
		static const auto JUG_LOADOUT_TWO = 8378;
		static const auto JUG_LOADOUT_THREE = 8379;
		static const auto JUG_LOADOUT_FOUR = 8686;
		static const auto JUG_LOADOUT_FIVE = 8687;
		static const auto DMB_LOADOUT_ONE = 8380;
		static const auto DMB_LOADOUT_TWO = 8381;
		static const auto DMB_LOADOUT_THREE = 8382;
		static const auto DMB_LOADOUT_FOUR = 8688;
		static const auto DMB_LOADOUT_FIVE = 8689;
		static const auto BRT_LOADOUT_ONE = 8383;
		static const auto BRT_LOADOUT_TWO = 8384;
		static const auto BRT_LOADOUT_THREE = 8385;
		static const auto BRT_LOADOUT_FOUR = 8690;
		static const auto BRT_LOADOUT_FIVE = 8691;
		static const auto ACTIVITY_DEVICE_NONE = 0;
		static const auto ACTIVITY_SENTINEL_PRIMARY_BXT1 = 124;
		static const auto ACTIVITY_SENTINEL_BELT_MINE_CLAYMORE_MKD = 125;
		static const auto ACTIVITY_SENTINEL_PRIMARY_SNIPERRIFLE_MKD = 126;
		static const auto ACTIVITY_BRUTE_PRIMARY_HEAVYSPINFUSOR = 127;
		static const auto ACTIVITY_BRUTE_PRIMARY_HEAVYSPINFUSOR_MKD = 128;
		static const auto ACTIVITY_BRUTE_PRIMARY_SPIKELAUNCHER = 129;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_CHAINGUN = 131;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_CHAINGUN_MKD = 132;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_HEAVYBOLTLAUNCHER = 133;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_REMOTEARXBUSTER = 134;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_RHINOSMG = 135;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_RHINOSMG_MKD = 136;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_STEALTHLIGHTSPINFUSOR = 137;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_FUSIONMORTAR = 138;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_FUSIONMORTAR_MKD = 139;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_MIRVLAUNCHER = 140;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_BOLTLAUNCHER = 141;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR = 142;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR_MKD = 143;
		static const auto ACTIVITY_RAIDER_PRIMARY_ARXBUSTER = 144;
		static const auto ACTIVITY_RAIDER_PRIMARY_ARXBUSTER_MKD = 145;
		static const auto ACTIVITY_RAIDER_PRIMARY_GRENADELAUNCHER = 146;
		static const auto ACTIVITY_RAIDER_PRIMARY_PLASMAGUN = 147;
		static const auto ACTIVITY_SENTINEL_PRIMARY_PHASERIFLE = 148;
		static const auto ACTIVITY_SOLDIER_PRIMARY_ASSAULTRIFLE = 149;
		static const auto ACTIVITY_SOLDIER_PRIMARY_ASSAULTRIFLE_MKD = 150;
		static const auto ACTIVITY_SOLDIER_PRIMARY_SPINFUSOR = 151;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TCN4 = 152;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TCN4_MKD = 153;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_THUMPER = 154;
		static const auto ACTIVITY_BRUTE_SECONDARY_AUTOSHOTGUN = 155;
		static const auto ACTIVITY_BRUTE_SECONDARY_AUTOSHOTGUN_MKD = 156;
		static const auto ACTIVITY_BRUTE_SECONDARY_NOVACOLT = 157;
		static const auto ACTIVITY_BRUTE_SECONDARY_PLASMACANNON = 158;
		static const auto ACTIVITY_DOOMBRINGER_SECONDARY_SABERLAUNCHER = 159;
		static const auto ACTIVITY_DOOMBRINGER_SECONDARY_SABERLAUNCHER_MKD = 160;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_SN7 = 161;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_SN7_MKD = 162;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_THROWINGKNIVES = 163;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_SPINFUSORD = 164;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_SPINFUSORD_MKD = 165;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_X1LMG = 166;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_LIGHTASSAULTRIFLE = 167;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_SHOTGUN = 168;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_SHOTGUN_MKD = 169;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ4SMG = 170;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ4SMG_MKD = 171;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ5SMG = 172;
		static const auto ACTIVITY_SENTINEL_SECONDARY_FALCON = 173;
		static const auto ACTIVITY_SENTINEL_SECONDARY_NOVABLASTER = 174;
		static const auto ACTIVITY_SENTINEL_SECONDARY_NOVABLASTER_MKD = 175;
		static const auto ACTIVITY_SOLDIER_SECONDARY_EAGLE = 176;
		static const auto ACTIVITY_SOLDIER_SECONDARY_THUMPERD = 177;
		static const auto ACTIVITY_SOLDIER_SECONDARY_THUMPERD_MKD = 178;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_REPAIRTOOLSD = 179;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_REPAIRTOOLSD_MKD = 180;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_SAWEDOFF = 181;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_SPARROW = 182;
		static const auto ACTIVITY_ARMOR_MOD_BRUTE = 183;
		static const auto ACTIVITY_ARMOR_MOD_DOOMBRINGER = 184;
		static const auto ACTIVITY_ARMOR_MOD_INFILTRATOR = 185;
		static const auto ACTIVITY_ARMOR_MOD_JUGGERNAUT = 186;
		static const auto ACTIVITY_ARMOR_MOD_PATHFINDER = 187;
		static const auto ACTIVITY_ARMOR_MOD_RAIDER = 188;
		static const auto ACTIVITY_ARMOR_MOD_SENTINEL = 189;
		static const auto ACTIVITY_ARMOR_MOD_TECHNICIAN = 190;
		static const auto ACTIVITY_ARMOR_MOD_SOLDIER = 191;
		static const auto ACTIVITY_BRUTE_BELT_FRACTALGRENADE = 192;
		static const auto ACTIVITY_BRUTE_BELT_FRACTALGRENADE_MKD = 193;
		static const auto ACTIVITY_BRUTE_BELT_LIGHTSTICKYGRENADE = 194;
		static const auto ACTIVITY_DOOMBRINGER_BELT_MINE = 195;
		static const auto ACTIVITY_DOOMBRINGER_BELT_STANDARDGRENADE = 196;
		static const auto ACTIVITY_DOOMBRINGER_BELT_STANDARDGRENADE_MKD = 197;
		static const auto ACTIVITY_INFILTRATOR_BELT_NINJASMOKE = 198;
		static const auto ACTIVITY_INFILTRATOR_BELT_PRISMMINES = 199;
		static const auto ACTIVITY_INFILTRATOR_BELT_STICKYGRENADE = 200;
		static const auto ACTIVITY_INFILTRATOR_BELT_STICKYGRENADE_MKD = 201;
		static const auto ACTIVITY_JUGGERNAUT_BELT_DISKTOSS = 202;
		static const auto ACTIVITY_JUGGERNAUT_BELT_HEAVYAPGRENADE = 203;
		static const auto ACTIVITY_JUGGERNAUT_BELT_HEAVYAPGRENADE_MKD = 204;
		static const auto ACTIVITY_PATHFINDER_BELT_IMPACTNITRON = 205;
		static const auto ACTIVITY_PATHFINDER_BELT_IMPACTNITRON_MKD = 206;
		static const auto ACTIVITY_PATHFINDER_BELT_STGRENADE = 207;
		static const auto ACTIVITY_RAIDER_BELT_EMPGRENADE = 208;
		static const auto ACTIVITY_RAIDER_BELT_EMPGRENADE_MKD = 209;
		static const auto ACTIVITY_RAIDER_BELT_MIRVGRENADE = 210;
		static const auto ACTIVITY_RAIDER_BELT_WHITEOUT = 211;
		static const auto ACTIVITY_SENTINEL_BELT_ARMOREDCLAYMORE = 212;
		static const auto ACTIVITY_SENTINEL_BELT_CLAYMORE = 213;
		static const auto ACTIVITY_SENTINEL_BELT_CLAYMORE_MKD = 214;
		static const auto ACTIVITY_SENTINEL_BELT_GRENADET5 = 215;
		static const auto ACTIVITY_SOLDIER_BELT_APGRENADE = 216;
		static const auto ACTIVITY_SOLDIER_BELT_FRAGGRENADEXL = 217;
		static const auto ACTIVITY_SOLDIER_BELT_FRAGGRENADEXL_MKD = 218;
		static const auto ACTIVITY_SOLDIER_BELT_PROXIMITYGRENADE = 219;
		static const auto ACTIVITY_TECHNICIAN_BELT_MOTIONALARM = 220;
		static const auto ACTIVITY_TECHNICIAN_BELT_TCNG = 221;
		static const auto ACTIVITY_TECHNICIAN_BELT_TCNG_MKD = 222;
		static const auto ACTIVITY_BRUTE_PACK_HEAVYSHIELD = 223;
		static const auto ACTIVITY_BRUTE_PACK_MINORENERGY = 224;
		static const auto ACTIVITY_BRUTE_PACK_SURVIVALPACK = 225;
		static const auto ACTIVITY_DOOMBRINGER_PACK_FORCEFIELD = 226;
		static const auto ACTIVITY_INFILTRATOR_PACK_STEALTH = 227;
		static const auto ACTIVITY_JUGGERNAUT_PACK_HEALTHREGEN = 228;
		static const auto ACTIVITY_PATHFINDER_PACK_ENERGYRECHARGE = 229;
		static const auto ACTIVITY_PATHFINDER_PACK_JUMPPACK = 230;
		static const auto ACTIVITY_RAIDER_PACK_JAMMER = 231;
		static const auto ACTIVITY_RAIDER_PACK_SHIELD = 232;
		static const auto ACTIVITY_SENTINEL_PACK_DROPJAMMER = 233;
		static const auto ACTIVITY_SENTINEL_PACK_ENERGYRECHARGE = 234;
		static const auto ACTIVITY_SOLDIER_PACK_ENERGYPOOL = 235;
		static const auto ACTIVITY_SOLDIER_PACK_UTILITY = 236;
		static const auto ACTIVITY_TECHNICIAN_PACK_EXRTURRET = 237;
		static const auto ACTIVITY_TECHNICIAN_PACK_LIGHTTURRET = 238;
		static const auto ACTIVITY_PERK_BOUNTY_HUNTER = 239;
		static const auto ACTIVITY_PERK_CLOSE_COMBAT = 240;
		static const auto ACTIVITY_PERK_LOOTER = 241;
		static const auto ACTIVITY_PERK_RAGE = 242;
		static const auto ACTIVITY_PERK_REACH = 243;
		static const auto ACTIVITY_PERK_SAFE_FALL = 244;
		static const auto ACTIVITY_PERK_SAFETY_THIRD = 245;
		static const auto ACTIVITY_PERK_STEALTHY = 246;
		static const auto ACTIVITY_PERK_SUPER_CAPACITOR = 247;
		static const auto ACTIVITY_PERK_WHEEL_DEAL = 248;
		static const auto ACTIVITY_PERK_DETERMINATION = 249;
		static const auto ACTIVITY_PERK_EGOCENTRIC = 250;
		static const auto ACTIVITY_PERK_MECHANIC = 253;
		static const auto ACTIVITY_PERK_PILOT = 254;
		static const auto ACTIVITY_PERK_POTENTIAL_ENERGY = 255;
		static const auto ACTIVITY_PERK_QUICKDRAW = 256;
		static const auto ACTIVITY_PERK_SONIC_PUNCH = 257;
		static const auto ACTIVITY_PERK_SUPER_HEAVY = 258;
		static const auto ACTIVITY_PERK_SURVIVALIST = 259;
		static const auto ACTIVITY_PERK_ULTRA_CAPACITOR = 260;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTTWINFUSOR = 261;
		static const auto ACTIVITY_SOLDIER_PRIMARY_TWINFUSOR = 262;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_HEAVYTWINFUSOR = 263;
		static const auto BUNDLE_LOOT_ID_CAD_ASSASSIN = 8918;
		static const auto BUNDLE_LOOT_ID_CAD_MERCENARY = 8919;
		static const auto BUNDLE_LOOT_ID_CAD_PREMIUM = 8912;
		static const auto BUNDLE_LOOT_ID_CAD_WEAPONS = 8920;
		static const auto BUNDLE_LOOT_ID_RAP_GRIEVER = 8982;
		static const auto BUNDLE_LOOT_ID_RAP_MERCENARY = 8983;
		static const auto BUNDLE_LOOT_ID_RAP_PREMIUM = 8981;
		static const auto BUNDLE_LOOT_ID_RAP_WEAPONS = 8984;
		static const auto BUNDLE_LOOT_ID_NEWPLAYER = 9214;
		static const auto BUNDLE_LOOT_ID_SHAZBUNDLE = 9213;
		static const auto BUNDLE_LOOT_ID_STAYINALIVE = 9035;
		static const auto BUNDLE_LOOT_ID_TWINFUSOR = 9449;
		static const auto BUNDLE_LOOT_ID_SKINPACK = 9457;
		static const auto BUNDLE_LOOT_ID_SPECIALIST = 9496;
		static const auto BUNDLE_LOOT_ID_SENTINEL = 9510;
		static const auto ITEM_VOICE_LIGHT = 8666;
		static const auto ITEM_VOICE_MEDIUM = 8667;
		static const auto ITEM_VOICE_HEAVY = 8668;
		static const auto ITEM_VOICE_DARK = 8669;
		static const auto ITEM_VOICE_FEM1 = 8670;
		static const auto ITEM_VOICE_FEM2 = 8671;
		static const auto ITEM_VOICE_AUS = 8695;
		static const auto ITEM_VOICE_T2FEM01 = 8712;
		static const auto ITEM_VOICE_T2FEM02 = 8714;
		static const auto ITEM_VOICE_T2FEM03 = 8715;
		static const auto ITEM_VOICE_T2FEM04 = 8716;
		static const auto ITEM_VOICE_T2FEM05 = 8717;
		static const auto ITEM_VOICE_T2MALE01 = 8719;
		static const auto ITEM_VOICE_T2MALE02 = 8720;
		static const auto ITEM_VOICE_T2MALE03 = 8721;
		static const auto ITEM_VOICE_T2MALE04 = 8722;
		static const auto ITEM_VOICE_T2MALE05 = 8723;
		static const auto ITEM_VOICE_T2BDERM01 = 8724;
		static const auto ITEM_VOICE_T2BDERM02 = 8725;
		static const auto ITEM_VOICE_T2BDERM03 = 8726;
		static const auto MAX_VGS_ENTRIES = 16;
		class TrTempMessage
		{
		public:
			ADD_STRUCT(TgSupportCommands::GC_ALERT_PRIORITY, Priority, 20)
			ADD_STRUCT(ScriptString*, Message, 8)
			ADD_STRUCT(float, TakeDownTime, 4)
			ADD_BOOL(bInUse, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, m_aDamageEffectNames, 3004)
		ADD_STRUCT(GfxTrHud::TrTempMessage, m_HeroStatusTempMessage, 3068)
		ADD_STRUCT(GfxTrHud::TrTempMessage, m_PromptPanelTempMessage, 3044)
		ADD_STRUCT(ScriptString*, m_sRound, 3032)
		ADD_OBJECT(GFxObject, VGSMenuList, 3028)
		ADD_OBJECT(GFxObject, _global, 3024)
		ADD_OBJECT(MaterialInstanceConstant, m_DirDamageMaterialInstance, 3020)
		ADD_OBJECT(MaterialEffect, m_DirectionalDamageEffect, 3016)
		ADD_STRUCT(float, m_fDirectionalDamageFadeTime, 3000)
		ADD_STRUCT(int, m_nNearDeathHealthMax, 2996)
		ADD_OBJECT(GFxObject, KillCamInfoObject, 2992)
		ADD_OBJECT(GFxObject, VGSMenuEntry, 2928)
		ADD_OBJECT(GFxObject, SpecHelp_LockViewTF, 2924)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomOutTF, 2920)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomInTF, 2916)
		ADD_OBJECT(GFxObject, SpecHelp_FreeCameraTF, 2912)
		ADD_OBJECT(GFxObject, SpecHelp_FastestPlayerTF, 2908)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeVehiclesTF, 2904)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeBookmarksTF, 2900)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagstandsTF, 2896)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagsTF, 2892)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeGeneratorsTF, 2888)
		ADD_OBJECT(GFxObject, SpecHelp_ChangePlayersTF, 2884)
		ADD_OBJECT(GFxObject, SpecHelp_DecreaseSpeedTF, 2880)
		ADD_OBJECT(GFxObject, SpecHelp_IncreaseSpeedTF, 2876)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeRightTF, 2872)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeLeftTF, 2868)
		ADD_OBJECT(GFxObject, SpecHelp_MoveBackTF, 2864)
		ADD_OBJECT(GFxObject, SpecHelp_MoveForwardTF, 2860)
		ADD_OBJECT(GFxObject, SpecHelp_MoveDownTF, 2856)
		ADD_OBJECT(GFxObject, SpecHelp_MoveUpTF, 2852)
		ADD_OBJECT(GFxObject, SpecHelp_ObjKaratsTF, 2848)
		ADD_OBJECT(GFxObject, SpecHelp_SpecHudTF, 2844)
		ADD_OBJECT(GFxObject, SpecHelp_MainmenuTF, 2840)
		ADD_OBJECT(GFxObject, SpecHelp_ScoreboardTF, 2836)
		ADD_OBJECT(GFxObject, SpecHelp_TeamSelectTF, 2832)
		ADD_OBJECT(GFxObject, SpecHelp_HelpTF, 2828)
		ADD_OBJECT(GFxObject, SpecFloat_DescriptionTF, 2824)
		ADD_OBJECT(GFxObject, SpecFloat_FloatCameraNameTF, 2820)
		ADD_OBJECT(GFxObject, SpecObjective_HealthTF, 2816)
		ADD_OBJECT(GFxObject, SpecObjective_HealthFillBar, 2812)
		ADD_OBJECT(GFxObject, SpecObjective_DescriptionTF, 2808)
		ADD_OBJECT(GFxObject, SpecObjective_ObjectiveNameTF, 2804)
		ADD_OBJECT(GFxObject, SpecBookmark_DescriptionTF, 2800)
		ADD_OBJECT(GFxObject, SpecBookmark_BookmarkNameTF, 2796)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar_speedoTF, 2792)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar, 2788)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_secondaryReady, 2784)
		ADD_OBJECT(GFxObject, SpecVehicle_SecondaryNameTF, 2780)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_primaryReady, 2776)
		ADD_OBJECT(GFxObject, SpecVehicle_PrimaryNameTF, 2772)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyTF, 2768)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyFillBar, 2764)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthTF, 2760)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthFillBar, 2756)
		ADD_OBJECT(GFxObject, SpecVehicle_PassengerNameTF, 2752)
		ADD_OBJECT(GFxObject, SpecVehicle_DriverNameTF, 2748)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleNameTF, 2744)
		ADD_OBJECT(GFxObject, SpecVehicle_FlagCarried, 2740)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar_speedoTF, 2736)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar, 2732)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk2TF, 2728)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem2, 2724)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk1TF, 2720)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem1, 2716)
		ADD_OBJECT(GFxObject, SpecPlayer_PackNameTF, 2712)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_count, 2708)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_icon, 2704)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandNameTF, 2700)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_count, 2696)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_icon, 2692)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryAmmoTF, 2688)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryNameTF, 2684)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryAmmoTF, 2680)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryNameTF, 2676)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyTF, 2672)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyFillBar, 2668)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthTF, 2664)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthFillBar, 2660)
		ADD_OBJECT(GFxObject, SpecPlayer_RegenTF, 2656)
		ADD_OBJECT(GFxObject, SpecPlayer_ClassNameTF, 2652)
		ADD_OBJECT(GFxObject, SpecPlayer_PlayerNameTF, 2648)
		ADD_OBJECT(GFxObject, SpecPlayer_FlagCarried, 2644)
		ADD_OBJECT(GFxObject, SpecObjective, 2640)
		ADD_OBJECT(GFxObject, SpecBookmark, 2636)
		ADD_OBJECT(GFxObject, SpawnCounter, 2632)
		ADD_OBJECT(GFxObject, SpecVehicle, 2628)
		ADD_OBJECT(GFxObject, SpecPlayer, 2624)
		ADD_OBJECT(GFxObject, SpecFloat, 2620)
		ADD_OBJECT(GFxObject, SpecHelp, 2616)
		ADD_OBJECT(GFxObject, VGS, 2612)
		ADD_OBJECT(GFxObject, NotificationPopup, 2608)
		ADD_OBJECT(GFxObject, DeployStatus, 2584)
		ADD_OBJECT(GFxObject, GlobalAlertTF, 2580)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CallItem, 2568)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Count, 2564)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Icon, 2560)
		ADD_OBJECT(GFxObject, PlayerStats_PackCount, 2556)
		ADD_OBJECT(GFxObject, PlayerStats_PackMC, 2552)
		ADD_OBJECT(GFxObject, PlayerStats_Pack, 2548)
		ADD_OBJECT(GFxObject, playerStats_Offhand1, 2544)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleSlot, 2520)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleEnergyFill, 2516)
		ADD_OBJECT(GFxObject, VehicleStats_EnergyTF_TextField, 2512)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleHealthFill, 2508)
		ADD_OBJECT(GFxObject, VehicleStats_HealthTF_TextField, 2504)
		ADD_OBJECT(GFxObject, VehicleStats, 2500)
		ADD_OBJECT(GFxObject, TeamStats, 2496)
		ADD_OBJECT(GFxObject, Offhands_And_Flag_FlagInHand, 2492)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CreditsGroup_CreditsMC_CreditsN, 2488)
		ADD_OBJECT(GFxObject, RabbitScoreboard, 2484)
		ADD_OBJECT(GFxObject, TeamScoreBoard, 2480)
		ADD_OBJECT(GFxObject, ArenaStats, 2476)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyScoreTF, 2472)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyScoreTF, 2468)
		ADD_OBJECT(GFxObject, ArenaStats_roundCountTF, 2464)
		ADD_OBJECT(GFxObject, ArenaStats_arenaGameTimerTF, 2460)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic08, 2456)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic07, 2452)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic06, 2448)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic05, 2444)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic04, 2440)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic03, 2436)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic02, 2432)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic01, 2428)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic08, 2424)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic07, 2420)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic06, 2416)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic05, 2412)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic04, 2408)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic03, 2404)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic02, 2400)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic01, 2396)
		ADD_OBJECT(GFxObject, CaHControlPointE, 2392)
		ADD_OBJECT(GFxObject, CaHControlPointD, 2388)
		ADD_OBJECT(GFxObject, CaHControlPointC, 2384)
		ADD_OBJECT(GFxObject, CaHControlPointB, 2380)
		ADD_OBJECT(GFxObject, CaHControlPointA, 2376)
		ADD_OBJECT(GFxObject, CaHStats, 2372)
		ADD_OBJECT(GFxObject, DaDStats, 2368)
		ADD_OBJECT(GFxObject, TdmStats, 2364)
		ADD_OBJECT(GFxObject, TdmStats_gameTimer, 2360)
		ADD_OBJECT(GFxObject, TdmStats_rightFlagStatus, 2356)
		ADD_OBJECT(GFxObject, TdmStats_leftFlagStatus, 2352)
		ADD_OBJECT(GFxObject, CTFStats, 2348)
		ADD_OBJECT(GFxObject, CTFStats_Timer, 2344)
		ADD_OBJECT(GFxObject, CTFStats_RightScore, 2340)
		ADD_OBJECT(GFxObject, CTFStats_LeftScore, 2336)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagTimer, 2332)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagTimer, 2328)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagStatus, 2324)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagStatus, 2320)
		ADD_OBJECT(GFxObject, CTFStats_RightGenTimer, 2316)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenTimer, 2312)
		ADD_OBJECT(GFxObject, CTFStats_RightGenStatus, 2308)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenStatus, 2304)
		ADD_OBJECT(GFxObject, RabbitStats_Timer, 2300)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderScore, 2288)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderText, 2276)
		ADD_OBJECT(GFxObject, RabbitStats, 2272)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerHighlight, 2240)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankIcon, 2208)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankTF, 2176)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ClassTF, 2144)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PingTF, 2112)
		ADD_OBJECT(GFxObject, RabbitScoreboard_AssistsTF, 2080)
		ADD_OBJECT(GFxObject, RabbitScoreboard_KillsTF, 2048)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ScoreT, 2016)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerTF, 1984)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankTF, 1920)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankIcon, 1856)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ClassTF, 1792)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PingTF, 1728)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_AssistsTF, 1664)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_KillsTF, 1600)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ScoreTF, 1536)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PlayerNameTF, 1472)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankTF, 1408)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankIcon, 1344)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ClassTF, 1280)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PingTF, 1216)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_AssistsTF, 1152)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_KillsTF, 1088)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ScoreTF, 1024)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PlayerNameTF, 960)
		ADD_OBJECT(GFxObject, PlayerStats_EnergyFillBar, 956)
		ADD_OBJECT(GFxObject, PlayerStats_GhostHealthBar, 952)
		ADD_OBJECT(GFxObject, PlayerStats_HealthFillBar, 948)
		ADD_OBJECT(GFxObject, SpawnCounter_TimeLabel, 944)
		ADD_OBJECT(GFxObject, SpawnCounter_StatusMessage, 940)
		ADD_OBJECT(GFxObject, CreditsAndStreaks_Streak, 928)
		ADD_OBJECT(GFxObject, CreditsAndStreaks, 924)
		ADD_OBJECT(GFxObject, SkiIndicatorFillBar, 916)
		ADD_OBJECT(GFxObject, SkiIndicatorTF, 908)
		ADD_OBJECT(GFxObject, SkiIndicator, 900)
		ADD_OBJECT(GFxObject, CombatLog, 896)
		ADD_OBJECT(GFxObject, KillMessageArea, 892)
		ADD_OBJECT(GFxObject, KillCamInfo, 888)
		ADD_OBJECT(GFxObject, PromptPanel, 884)
		ADD_OBJECT(GFxObject, HeroStatus_outputTF, 880)
		ADD_OBJECT(GFxObject, PlayerStats, 876)
		ADD_OBJECT(GFxObject, Visor, 860)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoPoolMP, 856)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoCountMP, 852)
		ADD_OBJECT(GFxTrReticules, Reticules, 848)
		ADD_OBJECT(GFxObject, sniperPowerUp, 844)
		ADD_OBJECT(TrDevice, m_LastOffhand, 832)
		ADD_OBJECT(TeamInfo, m_LastTeam, 828)
		ADD_STRUCT(int, m_nLastVehicleAmmoPool, 824)
		ADD_STRUCT(float, m_fLastVehicleEnergy, 820)
		ADD_STRUCT(int, m_nLastVehicleHealth, 816)
		ADD_STRUCT(int, m_nLastSeatMask, 812)
		ADD_STRUCT(float, m_fSpeedometerUpdateInterval, 808)
		ADD_STRUCT(int, m_SkiSpeedSteps, 760)
		ADD_STRUCT(int, m_VGSMenuListCount, 756)
		ADD_STRUCT(float, m_fLastSpeedometerUpdateTime, 752)
		ADD_STRUCT(float, m_fCurrentGhostHealth, 748)
		ADD_STRUCT(float, m_fLastActualHealth, 744)
		ADD_STRUCT(float, m_fLastMaxHealth, 740)
		ADD_STRUCT(float, m_fLastRotation, 736)
		ADD_BOOL(bVGSLoadouts, 732, 0x200)
		ADD_BOOL(m_bNearDeathOn, 732, 0x100)
		ADD_BOOL(bShowingBadge, 732, 0x80)
		ADD_BOOL(m_bLastIn3P, 732, 0x40)
		ADD_BOOL(m_bShowingAmmoClip, 732, 0x20)
		ADD_BOOL(m_bLastInVehicle, 732, 0x10)
		ADD_BOOL(m_bGameOver, 732, 0x8)
		ADD_BOOL(m_bShowPlayerStats, 732, 0x4)
		ADD_BOOL(m_bLastHasFlag, 732, 0x2)
		ADD_BOOL(m_bLastSkiing, 732, 0x1)
		ADD_STRUCT(float, m_fCrosshairDepth, 728)
		ADD_STRUCT(int, m_nLastFriendlyGeneratorTime, 724)
		ADD_STRUCT(int, m_nLastEnemyGeneratorTime, 720)
		ADD_STRUCT(int, m_nLastOffhandCount, 708)
		ADD_STRUCT(int, m_nLastPercentReload, 704)
		ADD_STRUCT(int, m_nLastPercentLaser, 700)
		ADD_STRUCT(int, m_nLastSkiSpeedStep, 696)
		ADD_STRUCT(int, m_nStreakEvent, 676)
		ADD_STRUCT(int, m_nCrossHairMode, 672)
		ADD_STRUCT(int, m_nLastAmmoPool, 668)
		ADD_STRUCT(int, m_nLastCredits, 664)
		ADD_STRUCT(int, m_nLastPercent, 660)
		ADD_STRUCT(int, m_HUDStageHeight, 656)
		ADD_STRUCT(int, m_HUDStageWidth, 652)
		ADD_STRUCT(int, m_HUDStageOriginY, 648)
		ADD_STRUCT(int, m_HUDStageOriginX, 644)
		ADD_OBJECT(TrPlayerController, m_TrPC, 640)
		ADD_OBJECT(TrHUD, m_TrHUD, 636)
		void DelegateSoundAccolade()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DelegateSoundAccolade");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelegateLoadVGSMenu(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DelegateLoadVGSMenu");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void registerReticules(class GFxTrReticules* MC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.registerReticules");
			byte params[4] = { NULL };
			*(class GFxTrReticules**)&params[0] = MC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.Init");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadVGSMenuDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetLoadVGSMenuDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundAccoladeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSoundAccoladeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitLeaderboardUpdateSlot(int Index, ScriptString* PlayerName, ScriptString* Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardUpdateSlot");
			byte params[28] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = PlayerName;
			*(ScriptString**)&params[16] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitLeaderboardUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetFontIndex");
			byte params[4] = { NULL };
			*(int*)&params[0] = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPromptPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearPromptPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromPromptPanel(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RemoveFromPromptPanel");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPromptPanelMessage(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearPromptPanelMessage");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadVGSMenu(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.LoadVGSMenu");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVGSEntry(ScriptString* Command, bool bBold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddVGSEntry");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Command;
			*(bool*)&params[12] = bBold;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddToPromptPanelTime(ScriptString* Message, float EndTime, TgSupportCommands::GC_ALERT_PRIORITY messagePriority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddToPromptPanelTime");
			byte params[17] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(float*)&params[12] = EndTime;
			*(TgSupportCommands::GC_ALERT_PRIORITY*)&params[16] = messagePriority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddtoPromptPanelAS(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddtoPromptPanelAS");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHeroStatus(ScriptString* Message, float ShowTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHeroStatus");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(float*)&params[12] = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHeroStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearHeroStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSpeedometer(int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpeedometer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerRankIcon(int IconIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerRankIcon");
			byte params[4] = { NULL };
			*(int*)&params[0] = IconIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerTeamIcon(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerTeamIcon");
			byte params[4] = { NULL };
			*(int*)&params[0] = Team;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerClassObjects(ScriptString* ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerClassObjects");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			*(int*)&params[12] = PerkIcon1;
			*(int*)&params[16] = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldShowSpectatorReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShouldShowSpectatorReticule");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SystemEnableNotifies(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SystemEnableNotifies");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConfigureSpectatorHUD(bool bIsNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureSpectatorHUD");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConfigureHUDState(bool bAlive, bool bReady, bool bForceCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureHUDState");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bAlive;
			*(bool*)&params[4] = bReady;
			*(bool*)&params[8] = bForceCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowChatLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowChatLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChatLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideChatLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowCenterHUDElements(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowCenterHUDElements");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCreditsAndStreaks(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCreditsAndStreaks");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScoreboardTitle(ScriptString* sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetScoreboardTitle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRespawnText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateRespawnText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRespawnText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetRespawnText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRespawnTimer(int TimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateRespawnTimer");
			byte params[4] = { NULL };
			*(int*)&params[0] = TimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHUDCredits(int changeAmount, int newTotal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHUDCredits");
			byte params[8] = { NULL };
			*(int*)&params[0] = changeAmount;
			*(int*)&params[4] = newTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void registerHUDView(class GFxObject* MovieClip, bool secondPass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.registerHUDView");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = MovieClip;
			*(bool*)&params[4] = secondPass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHUDStageSize(int HUDOriginX, int HUDOriginY, int Width, int Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetHUDStageSize");
			byte params[16] = { NULL };
			*(int*)&params[0] = HUDOriginX;
			*(int*)&params[4] = HUDOriginY;
			*(int*)&params[8] = Width;
			*(int*)&params[12] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAmmoCountTF(class Weapon* Wep, ScriptString* Ammo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetAmmoCountTF");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = Wep;
			*(ScriptString**)&params[4] = Ammo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearStats");
			byte params[4] = { NULL };
			*(bool*)&params[0] = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceHealthUpdate(int NewHealth, int NewMaxHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ForceHealthUpdate");
			byte params[8] = { NULL };
			*(int*)&params[0] = NewHealth;
			*(int*)&params[4] = NewMaxHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetSkiSpeedStep(float Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetSkiSpeedStep");
			byte params[8] = { NULL };
			*(float*)&params[0] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ConfigureSkiSpeedSteps(float SoftCap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureSkiSpeedSteps");
			byte params[4] = { NULL };
			*(float*)&params[0] = SoftCap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetFrameNumberForVehicle(class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetFrameNumberForVehicle");
			byte params[8] = { NULL };
			*(class TrVehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void TickHud(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickHud");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASSetHeading(int Heading)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASSetHeading");
			byte params[4] = { NULL };
			*(int*)&params[0] = Heading;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TickDirectionalDamageEffect(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickDirectionalDamageEffect");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ChangeDamageEffectParameter(ScriptName ParamName, float changeValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ChangeDamageEffectParameter");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = ParamName;
			*(float*)&params[8] = changeValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void PlayDamageEffectWithNoDirectionalIndicator(float Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.PlayDamageEffectWithNoDirectionalIndicator");
			byte params[4] = { NULL };
			*(float*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyDirectionalDamageEffect(int EffectIndex, float addValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ApplyDirectionalDamageEffect");
			byte params[8] = { NULL };
			*(int*)&params[0] = EffectIndex;
			*(float*)&params[4] = addValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyNearDeathEffect(float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ApplyNearDeathEffect");
			byte params[4] = { NULL };
			*(float*)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayHit(Object::Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DisplayHit");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitDir;
			*(int*)&params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHealth(GFxMinimapHud::HeEnDisplay& Info, float NewHealth, float HealthMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHealth");
			byte params[44] = { NULL };
			*(GFxMinimapHud::HeEnDisplay*)&params[0] = Info;
			*(float*)&params[36] = NewHealth;
			*(float*)&params[40] = HealthMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Info = *(GFxMinimapHud::HeEnDisplay*)&params[0];
		}
		void TickGhostHealth(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickGhostHealth");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateEnergy(GFxMinimapHud::HeEnDisplay& Info, float NewEnergy, float EnergyMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateEnergy");
			byte params[44] = { NULL };
			*(GFxMinimapHud::HeEnDisplay*)&params[0] = Info;
			*(float*)&params[36] = NewEnergy;
			*(float*)&params[40] = EnergyMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Info = *(GFxMinimapHud::HeEnDisplay*)&params[0];
		}
		void SetOwnership()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetOwnership");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamScoreboardUpdateSlot(int Index, ScriptString* PlayerName, ScriptString* Score, ScriptString* Kills, ScriptString* Assists, ScriptString* Ping, ScriptString* ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateSlot");
			byte params[84] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = PlayerName;
			*(ScriptString**)&params[16] = Score;
			*(ScriptString**)&params[28] = Kills;
			*(ScriptString**)&params[40] = Assists;
			*(ScriptString**)&params[52] = Ping;
			*(ScriptString**)&params[64] = ClassAbb;
			*(int*)&params[76] = Rank;
			*(int*)&params[80] = RankIcon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardUpdateSlot(int Index, ScriptString* PlayerName, ScriptString* Score, ScriptString* Kills, ScriptString* Assists, ScriptString* Ping, ScriptString* ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardUpdateSlot");
			byte params[84] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = PlayerName;
			*(ScriptString**)&params[16] = Score;
			*(ScriptString**)&params[28] = Kills;
			*(ScriptString**)&params[40] = Assists;
			*(ScriptString**)&params[52] = Ping;
			*(ScriptString**)&params[64] = ClassAbb;
			*(int*)&params[76] = Rank;
			*(int*)&params[80] = RankIcon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardActivePlayer(int Index, bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardActivePlayer");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitLeaderboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateGeneratorStatus(int Team, bool bPowered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateGeneratorStatus");
			byte params[8] = { NULL };
			*(int*)&params[0] = Team;
			*(bool*)&params[4] = bPowered;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateGeneratorTimer(int Team, ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateGeneratorTimer");
			byte params[16] = { NULL };
			*(int*)&params[0] = Team;
			*(ScriptString**)&params[4] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateFlagReturnTime(int Team, ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateFlagReturnTime");
			byte params[16] = { NULL };
			*(int*)&params[0] = Team;
			*(ScriptString**)&params[4] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateFlagStatus(int Team, bool bAtBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateFlagStatus");
			byte params[8] = { NULL };
			*(int*)&params[0] = Team;
			*(bool*)&params[4] = bAtBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateTeamScore");
			byte params[8] = { NULL };
			*(int*)&params[0] = Team;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamCTFStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamRabbitStatsUpdateFlagStatus(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateFlagStatus");
			byte params[4] = { NULL };
			*(int*)&params[0] = Team;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamRabbitStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateTeamScore");
			byte params[8] = { NULL };
			*(int*)&params[0] = Team;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_FriendlyTDMScoreUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyTDMScoreUpdate");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_EnemyTDMScoreUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyTDMScoreUpdate");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamRabbitStatsPointBreak(int Team, ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsPointBreak");
			byte params[16] = { NULL };
			*(int*)&params[0] = Team;
			*(ScriptString**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_FriendlyTDMPointBreak(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyTDMPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_EnemyTDMPointBreak(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyTDMPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowNotification(ScriptString* val, ScriptString* Val2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowNotification");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = val;
			*(ScriptString**)&params[12] = Val2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamRabbitStatsUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamRabbitStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaUpdateManGraphic(class GFxObject* Obj, ScriptString* Path, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaUpdateManGraphic");
			byte params[20] = { NULL };
			*(class GFxObject**)&params[0] = Obj;
			*(ScriptString**)&params[4] = Path;
			*(int*)&params[16] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsUpdateRoundCount(int RoundNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateRoundCount");
			byte params[4] = { NULL };
			*(int*)&params[0] = RoundNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsUpdateFriendlyRoundScore(int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateFriendlyRoundScore");
			byte params[4] = { NULL };
			*(int*)&params[0] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsUpdateEnemyRoundScore(int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateEnemyRoundScore");
			byte params[4] = { NULL };
			*(int*)&params[0] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsPointBreak(int Team, ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsPointBreak");
			byte params[16] = { NULL };
			*(int*)&params[0] = Team;
			*(ScriptString**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_FriendlyArenaPointBreak(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyArenaPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_EnemyArenaPointBreak(ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyArenaPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArenaStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateTeamScore");
			byte params[8] = { NULL };
			*(int*)&params[0] = Team;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_FriendlyArenaLivesUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyArenaLivesUpdate");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_EnemyArenaLivesUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyArenaLivesUpdate");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DaDStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDStatsShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DaDUpdateFriendlyStats(int bGenOnline, ScriptString* RemainingGenTime, int CapAOnline, int CapBOnline, int CapCOnline, int CoreHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDUpdateFriendlyStats");
			byte params[32] = { NULL };
			*(int*)&params[0] = bGenOnline;
			*(ScriptString**)&params[4] = RemainingGenTime;
			*(int*)&params[16] = CapAOnline;
			*(int*)&params[20] = CapBOnline;
			*(int*)&params[24] = CapCOnline;
			*(int*)&params[28] = CoreHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DaDUpdateEnemyStats(int bGenOnline, ScriptString* RemainingGenTime, int CapAOnline, int CapBOnline, int CapCOnline, int CoreHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDUpdateEnemyStats");
			byte params[32] = { NULL };
			*(int*)&params[0] = bGenOnline;
			*(ScriptString**)&params[4] = RemainingGenTime;
			*(int*)&params[16] = CapAOnline;
			*(int*)&params[20] = CapBOnline;
			*(int*)&params[24] = CapCOnline;
			*(int*)&params[28] = CoreHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHStatsShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHControlPointAShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointAShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHControlPointBShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointBShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHControlPointCShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointCShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHControlPointDShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointDShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHControlPointEShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointEShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHUpdate(int FriendlyHeld, int FriendlyPoints, int FriendlyPct, int EnemyHeld, int EnemyPoints, int EnemyPct, ScriptString* GenTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHUpdate");
			byte params[36] = { NULL };
			*(int*)&params[0] = FriendlyHeld;
			*(int*)&params[4] = FriendlyPoints;
			*(int*)&params[8] = FriendlyPct;
			*(int*)&params[12] = EnemyHeld;
			*(int*)&params[16] = EnemyPoints;
			*(int*)&params[20] = EnemyPct;
			*(ScriptString**)&params[24] = GenTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHPointUpdate(ScriptString* PointName, int PointType, int PctHeld)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHPointUpdate");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = PointName;
			*(int*)&params[12] = PointType;
			*(int*)&params[16] = PctHeld;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHFriendlyPointBreak(ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHFriendlyPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CaHEnemyPointBreak(ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHEnemyPointBreak");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardShow");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCredits(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateFlagInHand(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateFlagInHand");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSkiing(bool bSkiing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateSkiing");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bSkiing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSkiLevel(int Level)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateSkiLevel");
			byte params[4] = { NULL };
			*(int*)&params[0] = Level;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTeamStats(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateTeamStats");
			byte params[4] = { NULL };
			*(int*)&params[0] = Team;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateVehicleStats(bool bVisible, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleStats");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bVisible;
			*(int*)&params[4] = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateVehicleHealth(int Health, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleHealth");
			byte params[8] = { NULL };
			*(int*)&params[0] = Health;
			*(int*)&params[4] = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateVehicleEnergy(float Energy, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleEnergy");
			byte params[8] = { NULL };
			*(float*)&params[0] = Energy;
			*(int*)&params[4] = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateVehicleSeat(int Index, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleSeat");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(int*)&params[4] = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateOffhand(int Index, bool bVisible, int FrameId, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateOffhand");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = bVisible;
			*(int*)&params[8] = FrameId;
			*(int*)&params[12] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateOwnedItem(int Index, bool bVisible, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateOwnedItem");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = bVisible;
			*(int*)&params[8] = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundAccolade()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SoundAccolade");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallIn(int Index, bool bEnable, bool bAvailable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCallIn");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(bool*)&params[4] = bEnable;
			*(bool*)&params[8] = bAvailable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* RetrieveGFxObject(class GFxObject*& Obj, ScriptString* ObjName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RetrieveGFxObject");
			byte params[20] = { NULL };
			*(class GFxObject**)&params[0] = Obj;
			*(ScriptString**)&params[4] = ObjName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Obj = *(class GFxObject**)&params[0];
			return *(class GFxObject**)&params[16];
		}
		void SetGlobalAlert(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetGlobalAlert");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideGlobalAlert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideGlobalAlert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateKillCamInfo(class TrPlayerReplicationInfo* KillerPRI, class TrPlayerReplicationInfo* VictimPRI, ScriptClass* KillDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CreateKillCamInfo");
			byte params[12] = { NULL };
			*(class TrPlayerReplicationInfo**)&params[0] = KillerPRI;
			*(class TrPlayerReplicationInfo**)&params[4] = VictimPRI;
			*(ScriptClass**)&params[8] = KillDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowKillCamInfo(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowKillCamInfo");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetWeaponNameFromDamageType(class TrPlayerReplicationInfo* PRI, ScriptClass* FamilyInfo, ScriptClass* KillDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetWeaponNameFromDamageType");
			byte params[24] = { NULL };
			*(class TrPlayerReplicationInfo**)&params[0] = PRI;
			*(ScriptClass**)&params[4] = FamilyInfo;
			*(ScriptClass**)&params[8] = KillDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SetSpectatorPlayerPanel_FlagCarried(bool bCarried)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_FlagCarried");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bCarried;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PlayerName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PlayerName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_ClassName(ScriptString* ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_ClassName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_NextRegen(ScriptString* NextRegen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_NextRegen");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = NextRegen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_HealthFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_HealthFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Health(ScriptString* Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Health");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Health;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_EnergyFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_EnergyFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Energy(ScriptString* Energy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Energy");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Energy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PrimaryWeaponName(ScriptString* PrimaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PrimaryWeaponName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PrimaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PrimaryAmmoCount(ScriptString* PrimaryAmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PrimaryAmmoCount");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PrimaryAmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_SecondaryWeaponName(ScriptString* SecondaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SecondaryWeaponName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SecondaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_SecondaryAmmoCount(ScriptString* SecondaryAmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SecondaryAmmoCount");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SecondaryAmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_OffhandIcon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandIcon");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_OffhandAmmo(ScriptString* OffhandAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandAmmo");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = OffhandAmmo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_OffhandName(ScriptString* OffhandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = OffhandName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PackIcon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackIcon");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PackAmmo(ScriptString* PackAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackAmmo");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PackAmmo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_PackName(ScriptString* PackName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PackName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Perk1Icon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk1Icon");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Perk1Name(ScriptString* PerkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk1Name");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PerkName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Perk2Icon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk2Icon");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Perk2Name(ScriptString* PerkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk2Name");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PerkName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_SkiIndicatorFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SkiIndicatorFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_SkiIndicatorSpeed(ScriptString* Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SkiIndicatorSpeed");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorPlayerPanel_Selected(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Selected");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_FlagCarried(bool bCarried)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_FlagCarried");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bCarried;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_VehicleName(ScriptString* VehicleName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_VehicleName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = VehicleName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_DriverName(ScriptString* DriverName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_DriverName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = DriverName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_PassengerName(ScriptString* PassengerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PassengerName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PassengerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_HealthFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_HealthFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_Health(ScriptString* Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Health");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Health;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_EnergyFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_EnergyFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_Energy(ScriptString* Energy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Energy");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Energy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponName(ScriptString* PrimaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PrimaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponReady(int Ready)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponReady");
			byte params[4] = { NULL };
			*(int*)&params[0] = Ready;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponVisible(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponVisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponName(ScriptString* SecondaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SecondaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponReady(int Ready)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponReady");
			byte params[4] = { NULL };
			*(int*)&params[0] = Ready;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponVisible(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponVisible");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_SkiIndicatorFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SkiIndicatorFillBar");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_SkiIndicatorSpeed(ScriptString* Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SkiIndicatorSpeed");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorVehiclePanel_Selected(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Selected");
			byte params[4] = { NULL };
			*(int*)&params[0] = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorBookmarkPanel_BookmarkName(ScriptString* BookmarkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorBookmarkPanel_BookmarkName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = BookmarkName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorObjectivePanel_ObjectiveName(ScriptString* ObjectiveName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_ObjectiveName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ObjectiveName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorObjectivePanel_ObjectiveDescription(ScriptString* ObjectiveDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_ObjectiveDescription");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ObjectiveDescription;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorObjectivePanel_HealthFillBar(int FrameIndex, int Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_HealthFillBar");
			byte params[8] = { NULL };
			*(int*)&params[0] = FrameIndex;
			*(int*)&params[4] = Health;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorFloatCameraPanel_Name(ScriptString* FloatCameraName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorFloatCameraPanel_Name");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = FloatCameraName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectatorFloatCameraPanel_Description(ScriptString* Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorFloatCameraPanel_Description");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorControls(bool bShowControls)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorControls");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShowControls;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideVGSMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideVGSMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideTutorial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideTutorial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowFlagCarried()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowFlagCarried");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideFlagCarried()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideFlagCarried");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideKillCamInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideKillCamInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateVGSMenuList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVGSMenuList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowEnding(int Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowEnding");
			byte params[4] = { NULL };
			*(int*)&params[0] = Winner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateChatLog(ScriptString* Message, int ChannelColor, bool bPublic)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateChatLog");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(int*)&params[12] = ChannelColor;
			*(bool*)&params[16] = bPublic;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPowerOscillation(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPowerOscillation");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateChatLogInput(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateChatLogInput");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardActivePlayer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardActivePlayer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardUpdateTime");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardUpdateTeamScore(int Index, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateTeamScore");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTutorial(ScriptString* Title, ScriptString* Body, float Icon, ScriptString* footer, ScriptString* Suppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateTutorial");
			byte params[52] = { NULL };
			*(ScriptString**)&params[0] = Title;
			*(ScriptString**)&params[12] = Body;
			*(float*)&params[24] = Icon;
			*(ScriptString**)&params[28] = footer;
			*(ScriptString**)&params[40] = Suppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddUpdateToCombatLog(int CombatType, ScriptString* Aggressor, int WeaponIcon, ScriptString* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddUpdateToCombatLog");
			byte params[32] = { NULL };
			*(int*)&params[0] = CombatType;
			*(ScriptString**)&params[4] = Aggressor;
			*(int*)&params[16] = WeaponIcon;
			*(ScriptString**)&params[20] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddUpdateToKillMessage(int RankIcon, int PlayerIcon, ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddUpdateToKillMessage");
			byte params[32] = { NULL };
			*(int*)&params[0] = RankIcon;
			*(int*)&params[4] = PlayerIcon;
			*(ScriptString**)&params[8] = PlayerName;
			*(ScriptString**)&params[20] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFlyingIcon(int iconNumber, ScriptString* Description, ScriptString* Points, int bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddFlyingIcon");
			byte params[32] = { NULL };
			*(int*)&params[0] = iconNumber;
			*(ScriptString**)&params[4] = Description;
			*(ScriptString**)&params[16] = Points;
			*(int*)&params[28] = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
