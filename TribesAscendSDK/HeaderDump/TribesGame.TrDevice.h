#pragma once
#include "TribesGame.TrObject.h"
#include "UTGame.UTWeapon.h"
#include "TribesGame.TrAnimNodeBlendByDeviceAnim.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrDeviceContentData.h"
#include "Core.Object.h"
#include "Engine.AnimSet.h"
#include "Engine.Material.h"
#include "Engine.CameraShake.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrDeployable.h"
#include "TribesGame.TrProj_Tracer.h"
#include "Engine.Weapon.h"
#include "Engine.Projectile.h"
#include "UDKBase.UDKPawn.h"
#include "TribesGame.TrPawn.h"
#include "UTGame.UTPlayerController.h"
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
	class TrDevice : public UTWeapon
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
		static const auto VALIDATE_HIT_DEFER = -1;
		static const auto VALIDATE_HIT_REJECT = 0;
		static const auto VALIDATE_HIT_APPROVE = 1;
		class EffectInfo
		{
		public:
			ADD_STRUCT(float, interval, 20)
			ADD_STRUCT(float, Value, 16)
			ADD_STRUCT(float, Lifetime, 12)
			ADD_STRUCT(TrObject::EffectType, Type, 8)
			ADD_OBJECT(ScriptClass, effectClass, 4)
			ADD_STRUCT(byte, FireModeNum, 0)
		};
		class ReplicatedAmmoCount
		{
		public:
			ADD_STRUCT(int, ClipAmmoCount, 4)
			ADD_STRUCT(int, CarriedAmmoCount, 0)
		};
		class DeviceModification
		{
		public:
			ADD_STRUCT(float, Value, 4)
			ADD_STRUCT(int, ModType, 0)
		};
		class DeviceUpgrade
		{
		public:
			ADD_STRUCT(int, DatabaseItemId, 4)
			ADD_STRUCT(int, IconId, 0)
			ADD_STRUCT(ScriptArray<TrDevice::DeviceModification>, Modifications, 8)
		};
		ADD_STRUCT(int, m_nCarriedAmmo, 1596)
		ADD_STRUCT(int, m_nIconIndex, 1688)
		ADD_STRUCT(ScriptArray<TrDevice::DeviceUpgrade>, Upgrades, 2088)
		ADD_STRUCT(ScriptString*, UpgradeDescription, 2028)
		ADD_STRUCT(int, DBXPActivityId, 1484)
		ADD_STRUCT(ScriptString*, InfoPanelDescription, 2000)
		ADD_STRUCT(int, InfoPanelDamage, 2012)
		ADD_STRUCT(int, InfoPanelRadius, 2016)
		ADD_STRUCT(int, InfoPanelFireRate, 2020)
		ADD_STRUCT(int, InfoPanelClipSize, 2024)
		ADD_STRUCT(int, DBWeaponId, 1472)
		ADD_STRUCT(int, m_nReticuleIndex, 1584)
		ADD_BOOL(m_bAllowFireWhileZoomed, 1548, 0x100000)
		ADD_STRUCT(ScriptArray<TrDevice::EffectInfo>, m_EffectInfo, 1492)
		ADD_STRUCT(ScriptArray<TrObject::DeviceTargeterType>, m_eTargetType, 1504)
		ADD_STRUCT(ScriptArray<TrObject::DeviceAttackType>, m_eAttackType, 1516)
		ADD_STRUCT(ScriptArray<int>, m_PowerPoolCost, 1528)
		ADD_STRUCT(ScriptArray<ScriptClass*>, m_WeaponDeployables, 1656)
		ADD_STRUCT(ScriptArray<TrObject::EffectFormOverwrite>, m_EffectFormOverwrite, 1768)
		ADD_STRUCT(ScriptArray<class AnimNodeSequence*>, m_MeshAnimSequenceNodes, 1840)
		ADD_STRUCT(Object::Vector, m_vClientSideFireOffset, 2136)
		ADD_OBJECT(TrDeviceContentData, m_ContentData, 2132)
		ADD_STRUCT(ScriptString*, m_sContentDataClassName, 2120)
		ADD_STRUCT(TrDevice::DeviceUpgrade, BaseMod, 2100)
		ADD_STRUCT(TrObject::PaperDollInfo, m_InGamePaperDollInfo, 1944)
		ADD_STRUCT(TrObject::PaperDollInfo, m_MainMenuPaperDollInfo, 1888)
		ADD_STRUCT(Object::Vector, m_TinyWeaponsOffset, 1876)
		ADD_STRUCT(float, m_fTimeBeforeInactiveReload, 1872)
		ADD_STRUCT(float, m_fLastActiveTime, 1868)
		ADD_STRUCT(int, m_nTetherCounter, 1864)
		ADD_OBJECT(AnimSet, m_NoAmmoAnimSet, 1860)
		ADD_STRUCT(float, m_fFireIntervalForLastShotInClip, 1856)
		ADD_STRUCT(float, m_fClientSideHitLeeway, 1852)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial, 1836)
		ADD_STRUCT(ScriptName, m_nmZoomMaterialEffectName, 1828)
		ADD_STRUCT(Object::Vector, m_vZoomMeshOffset, 1816)
		ADD_STRUCT(float, m_fZoomRate, 1812)
		ADD_STRUCT(float, m_fDesiredZoomFOV, 1808)
		ADD_STRUCT(int, m_ShotsFired, 1804)
		ADD_STRUCT(Object::Vector, m_vPositionPivotOffset, 1792)
		ADD_OBJECT(CameraShake, m_FireCameraShake, 1788)
		ADD_OBJECT(Material, r_ReplicatedMaterial, 1764)
		ADD_STRUCT(Object::Vector2D, m_v2WeaponLagSmoothingFactor, 1756)
		ADD_STRUCT(Object::Vector2D, m_v2WeaponLagInterpSpeed, 1748)
		ADD_STRUCT(int, m_nMaxWeaponLagPitch, 1744)
		ADD_STRUCT(int, m_nMaxWeaponLagYaw, 1740)
		ADD_STRUCT(Object::Vector2D, m_v2WeaponLagAimOffset, 1732)
		ADD_STRUCT(float, m_fMaxKickbackDistanceY, 1728)
		ADD_STRUCT(float, m_fMaxKickbackDistanceX, 1724)
		ADD_STRUCT(float, m_fKickbackBlendOutTime, 1720)
		ADD_STRUCT(float, m_fLastKickbackTime, 1716)
		ADD_STRUCT(Object::Vector2D, m_v2KickbackAmount, 1708)
		ADD_STRUCT(Object::Vector2D, m_v2MinMaxKickbackY, 1700)
		ADD_STRUCT(Object::Vector2D, m_v2MinMaxKickbackX, 1692)
		ADD_STRUCT(int, m_nCreditCost, 1684)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate, 1680)
		ADD_STRUCT(float, m_fShowTracerDistance, 1676)
		ADD_STRUCT(int, m_nTracerInterval, 1672)
		ADD_OBJECT(TrAnimNodeBlendByDeviceAnim, m_DeviceAnimNode, 1668)
		ADD_STRUCT(float, m_fLockTargetTime, 1652)
		ADD_OBJECT(Actor, c_LockedActor, 1648)
		ADD_STRUCT(float, c_fLockTime, 1644)
		ADD_STRUCT(TrDevice::ReplicatedAmmoCount, r_AmmoCount, 1636)
		ADD_STRUCT(int, s_iCheatCountAmmo, 1632)
		ADD_OBJECT(SoundCue, m_ZoomOutSoundCue, 1628)
		ADD_OBJECT(SoundCue, m_ZoomInSoundCue, 1624)
		ADD_OBJECT(SoundCue, m_DryFireSoundCue, 1620)
		ADD_OBJECT(SoundCue, m_ReloadAmmoSoundCue, 1616)
		ADD_STRUCT(float, m_fPctTimeBeforeReload, 1612)
		ADD_STRUCT(float, m_fReloadTime, 1608)
		ADD_STRUCT(int, m_RemainingAmmoInClip, 1604)
		ADD_STRUCT(int, m_nMaxCarriedAmmo, 1600)
		ADD_STRUCT(int, m_nLowAmmoWarning, 1592)
		ADD_STRUCT(int, m_nAltReticuleIndex, 1588)
		ADD_STRUCT(float, m_fQuickRetrieveEquipTime, 1580)
		ADD_STRUCT(float, m_fAccuracyCorrectionRate, 1576)
		ADD_STRUCT(float, m_fAimingModeAccuracyBonus, 1572)
		ADD_STRUCT(float, m_fAccuracyLossMax, 1568)
		ADD_STRUCT(float, m_fAccuracyLossOnShot, 1564)
		ADD_STRUCT(float, m_fAccuracyLossOnWeaponSwitch, 1560)
		ADD_STRUCT(float, m_fAccuracyLossOnJump, 1556)
		ADD_STRUCT(float, m_fDefaultAccuracy, 1552)
		ADD_BOOL(m_bTinyWeaponsEnabled, 1548, 0x4000000)
		ADD_BOOL(r_bIsReloading, 1548, 0x2000000)
		ADD_BOOL(m_bResumeZoomOnReloadEnd, 1548, 0x1000000)
		ADD_BOOL(m_bEndZoomOnReload, 1548, 0x800000)
		ADD_BOOL(m_bUseMeshZoomOffset, 1548, 0x400000)
		ADD_BOOL(m_bCanZoom, 1548, 0x200000)
		ADD_BOOL(m_bAllowHoldDownFire, 1548, 0x80000)
		ADD_BOOL(m_bWantsToFire, 1548, 0x40000)
		ADD_BOOL(m_bIsPassive, 1548, 0x20000)
		ADD_BOOL(m_bIsKickbackAdditive, 1548, 0x10000)
		ADD_BOOL(m_bSpawnTracerBeams, 1548, 0x8000)
		ADD_BOOL(m_bSpawnTracers, 1548, 0x4000)
		ADD_BOOL(m_bUsesDeployMode, 1548, 0x2000)
		ADD_BOOL(c_bLocking, 1548, 0x1000)
		ADD_BOOL(m_bForceReplicateAmmoOnFire, 1548, 0x800)
		ADD_BOOL(r_bReadyToFire, 1548, 0x400)
		ADD_BOOL(m_bCanEarlyAbortReload, 1548, 0x200)
		ADD_BOOL(m_bReloadBulletInChamber, 1548, 0x100)
		ADD_BOOL(m_bPendingReload, 1548, 0x80)
		ADD_BOOL(m_bReloadSingles, 1548, 0x40)
		ADD_BOOL(m_bAllowReloads, 1548, 0x20)
		ADD_BOOL(m_bLowAmmoOn, 1548, 0x10)
		ADD_BOOL(m_bRequireAimMode, 1548, 0x8)
		ADD_BOOL(m_bHighlightEnemies, 1548, 0x4)
		ADD_BOOL(m_bEquipEffectsApplied, 1548, 0x2)
		ADD_BOOL(m_bAllowMultipleTargets, 1548, 0x1)
		ADD_STRUCT(float, m_fConeAttackAngle, 1544)
		ADD_STRUCT(float, m_fDamageRadius, 1540)
		ADD_STRUCT(TrObject::EWeaponTracerType, m_TracerType, 1489)
		ADD_STRUCT(TrObject::TR_EQUIP_POINT, r_eEquipAt, 1488)
		ADD_STRUCT(int, DBWeaponTypeId, 1480)
		ADD_STRUCT(int, DBWeaponBaseId, 1476)
		float CalcHUDAimChargePercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcHUDAimChargePercent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAccuracy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		byte GetFireModeNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetFireModeNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		bool IsValidTarget(class Actor* Target, int nFireMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsValidTarget");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(int*)&params[4] = nFireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsEnemy(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsEnemy");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsInsideCone(Object::Vector SourceLookDir, class Actor* TargetActor, Object::Vector StartCone, float MinCosine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsInsideCone");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = SourceLookDir;
			*(class Actor**)&params[12] = TargetActor;
			*(Object::Vector*)&params[16] = StartCone;
			*(float*)&params[28] = MinCosine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool ShouldAddToImpactList(class Actor* HitActor, ScriptArray<Actor::ImpactInfo> ImpactList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldAddToImpactList");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(ScriptArray<Actor::ImpactInfo>*)&params[4] = ImpactList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.TickInHandWeapon");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetLock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResetLock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetLockedTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetLockedTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		class TrDeployable* SpawnPet(bool bPet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnPet");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bPet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeployable**)&params[4];
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTargetAccuracy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RestoreAccuracy");
			byte params[4] = { NULL };
			*(float*)&params[0] = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestoreKickback(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RestoreKickback");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInLOS(class Actor* TouchedActor, Object::Vector ExpectedLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsInLOS");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = TouchedActor;
			*(Object::Vector*)&params[4] = ExpectedLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AttachHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachHandsMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrDeviceContentData* LoadMeshData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.LoadMeshData");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeviceContentData**)&params[0];
		}
		int ValidateClientReportedHit(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ValidateClientReportedHit");
			byte params[93] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			*(bool*)&params[88] = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[92];
		}
		int ValidateClientReportedHitInternal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ValidateClientReportedHitInternal");
			byte params[93] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			*(bool*)&params[88] = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[92];
		}
		ScriptString* GetObjectReferencerName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetObjectReferencerName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetObjectReferencerPackageName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetObjectReferencerPackageName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddAmmo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool ReplicateAmmoOnWeaponFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ReplicateAmmoOnWeaponFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ConsumeAmmo_Internal");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ConsumeAmmo");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTraceOwner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachWeaponTo");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateFirstPersonHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CreateFirstPersonHandsMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ChangeVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CentralUpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CentralUpdateHandsMesh");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateHandsMesh");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CreateOverlayMesh");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayRetrieveAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnPlayRetrieveAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.WeaponEmpty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnSwitchToWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientWeaponSet");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOptionalSet;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayFireEffects");
			byte params[13] = { NULL };
			params[0] = FireModeNum;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayFireAnimation");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShakeView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShakeView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldFireTracer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldFireTracerBeam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SpawnTracerBeam(Object::Vector Start, Object::Vector End)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnTracerBeam");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(Object::Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SpawnTracerEffect");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(float*)&params[12] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[16];
		}
		class TrProj_Tracer* GetTracer(Object::Vector SpawnLocation, Object::Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetTracer");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(Object::Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[24];
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetNumRoundsCurrentlyInClip");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HasAmmo");
			byte params[9] = { NULL };
			params[0] = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HasAnyAmmo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool AllowSwitchTo(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AllowSwitchTo");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float CalculateRangeDamageFalloff(float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalculateRangeDamageFalloff");
			byte params[8] = { NULL };
			*(float*)&params[0] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, Actor::ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessInstantHit");
			byte params[85] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(int*)&params[84] = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerNotifyHit(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerNotifyHit");
			byte params[85] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessInstantHit_Internal");
			byte params[85] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ModifyInstantHitDamage");
			byte params[89] = { NULL };
			params[0] = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
		void ProcessEffect(class Actor* Target, byte FiringMode, TrObject::EffectType efType, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProcessEffect");
			byte params[10] = { NULL };
			*(class Actor**)&params[0] = Target;
			params[4] = FiringMode;
			*(TrObject::EffectType*)&params[5] = efType;
			*(bool*)&params[8] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UsesPower()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UsesPower");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsDeviceCoolingDown(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsDeviceCoolingDown");
			byte params[5] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EnterDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EnterDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ExitDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ToggleActivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForWeaponSwitch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForWeaponSwitch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PayAccuracyForShot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Rotator AddSpreadWithAccuracy(Object::Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddSpreadWithAccuracy");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = BaseAim;
			*(float*)&params[12] = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		Object::Rotator ApplyKickbackToAim(Object::Rotator Aim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ApplyKickbackToAim");
			byte params[24] = { NULL };
			*(Object::Rotator*)&params[0] = Aim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		Object::Vector2D GetCurrentKickbackAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetCurrentKickbackAmount");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)&params[0];
		}
		bool AddKickback()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddKickback");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetAdjustedAim(Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAdjustedAim");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		bool ShowWeaponRedLowAmmoIndicator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShowWeaponRedLowAmmoIndicator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.NeedToVisitInventoryStation");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAmmoCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void UpdateLowAmmoWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateLowAmmoWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetProjectileClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		Object::Vector GetClientSideProjectileFireStartLoc(Object::Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetClientSideProjectileFireStartLoc");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ProjectileFire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)&params[0];
		}
		void DestroyOldestProjectileOverLimit(class Projectile* newProjectile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.DestroyOldestProjectileOverLimit");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = newProjectile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float MaxRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.MaxRange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetWeaponRange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetWeaponRange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Rotator GetAimForCamera(Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetAimForCamera");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[12];
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanClientRequestReloadNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.HolderEnteredVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetReloadTime(class PlayerReplicationInfo* PRI, TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetReloadTime");
			byte params[9] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(TrObject::TR_EQUIP_POINT*)&params[4] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void ClearMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClearMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheMeshAnimSeqNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CacheMeshAnimSeqNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressAnimNotifies(bool bSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SuppressAnimNotifies");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsReloading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.IsReloading");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RequestReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RequestReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnClientReloaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PerformInactiveReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalcAmountToLoad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcAmountToLoad");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientFinishedReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeZoomOnReloadEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResumeZoomOnReloadEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayReloadAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayReloadAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableWeaponReadyToFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EnableWeaponReadyToFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.OnReloadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BeginAReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AddCarriedAmmo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateReplicatedCarriedAmmo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInactiveDueToOffhand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GoInactiveDueToOffhand");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BeginFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetEquipTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.TimeWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetPutDownTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetPutDownTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool CanFireOffhandNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanFireOffhandNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerOnClientDeniedFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerOnClientDeniedFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyEquipEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ApplyEquipEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveEquipEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.RemoveEquipEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SetPosition");
			byte params[8] = { NULL };
			*(class UDKPawn**)&params[0] = Holder;
			*(float*)&params[4] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int LagRot(int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.LagRot");
			byte params[24] = { NULL };
			*(int*)&params[0] = NewValue;
			*(int*)&params[4] = LastValue;
			*(float*)&params[8] = MaxDiff;
			*(int*)&params[12] = Index;
			*(float*)&params[16] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		bool ShouldRefire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ShouldRefire");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceInvalidPickup(class TrPawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AnnounceInvalidPickup");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.DenyPickupQuery");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PutDownFast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PutDownFast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ForceEndFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanAutoDeviceFireNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CustomFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CustomFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.AttachMuzzleFlash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.WeaponPlaySoundLocal");
			byte params[8] = { NULL };
			*(class SoundCue**)&params[0] = Sound;
			*(float*)&params[4] = NoiseLoudness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ClientWeaponThrown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateShotsFired");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Reset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.StartZoom");
			byte params[4] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.EndZoom");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CanViewZoom");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.SetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetAltReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ResetAltReticule");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Actor::ImpactInfo CalcWeaponFire(Object::Vector StartTrace, Object::Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.CalcWeaponFire");
			byte params[128] = { NULL };
			*(Object::Vector*)&params[0] = StartTrace;
			*(Object::Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Object::Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
		void PlayDryFireZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.PlayDryFireZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuffMaxCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.BuffMaxCarriedAmmo");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetMaxAmmoCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetMaxAmmoCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		int GetBasePickupAmmoAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.GetBasePickupAmmoAmount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.ServerStartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateWeaponMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice.UpdateWeaponMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
