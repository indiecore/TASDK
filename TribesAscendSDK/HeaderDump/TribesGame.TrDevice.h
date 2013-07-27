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
		static const auto HAE_KILL_STREAK_LEVEL_1 = 1;
		static const auto HAE_KILL_STREAK_LEVEL_2 = 2;
		static const auto HAE_KILL_STREAK_LEVEL_3 = 3;
		static const auto HAE_KILL_STREAK_LEVEL_4 = 4;
		static const auto HAE_KILL_STREAK_LEVEL_5 = 5;
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
		static const auto TRICON_RANK_1 = 80;
		static const auto TRICON_RANK_2 = 81;
		static const auto TRICON_RANK_3 = 82;
		static const auto TRICON_RANK_4 = 83;
		static const auto TRICON_RANK_5 = 84;
		static const auto TRICON_RANK_6 = 85;
		static const auto TRICON_RANK_7 = 86;
		static const auto TRICON_RANK_8 = 87;
		static const auto TRICON_RANK_9 = 88;
		static const auto TRICON_RANK_10 = 89;
		static const auto TRICON_RANK_11 = 90;
		static const auto TRICON_RANK_12 = 91;
		static const auto TRICON_RANK_13 = 92;
		static const auto TRICON_RANK_14 = 93;
		static const auto TRICON_RANK_15 = 94;
		static const auto TRICON_RANK_16 = 95;
		static const auto TRICON_RANK_17 = 96;
		static const auto TRICON_RANK_18 = 97;
		static const auto TRICON_RANK_19 = 98;
		static const auto TRICON_RANK_20 = 99;
		static const auto TRICON_RANK_21 = 100;
		static const auto TRICON_RANK_22 = 101;
		static const auto TRICON_RANK_23 = 102;
		static const auto TRICON_RANK_24 = 103;
		static const auto TRICON_RANK_25 = 104;
		static const auto TRICON_RANK_26 = 105;
		static const auto TRICON_RANK_27 = 106;
		static const auto TRICON_RANK_28 = 107;
		static const auto TRICON_RANK_29 = 108;
		static const auto TRICON_RANK_30 = 109;
		static const auto TRICON_RANK_31 = 110;
		static const auto TRICON_RANK_32 = 111;
		static const auto TRICON_RANK_33 = 112;
		static const auto TRICON_RANK_34 = 113;
		static const auto TRICON_RANK_35 = 114;
		static const auto TRICON_RANK_36 = 115;
		static const auto TRICON_RANK_37 = 116;
		static const auto TRICON_RANK_38 = 117;
		static const auto TRICON_RANK_39 = 118;
		static const auto TRICON_RANK_40 = 119;
		static const auto TRICON_RANK_41 = 120;
		static const auto TRICON_RANK_42 = 121;
		static const auto TRICON_RANK_43 = 122;
		static const auto TRICON_RANK_44 = 123;
		static const auto TRICON_RANK_45 = 124;
		static const auto TRICON_RANK_46 = 125;
		static const auto TRICON_RANK_47 = 126;
		static const auto TRICON_RANK_48 = 127;
		static const auto TRICON_RANK_49 = 128;
		static const auto TRICON_RANK_50 = 129;
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
		static const auto TRICON_BADGE_FLAGDEFENSE_4 = 170;
		static const auto TRICON_BADGE_FLAGDEFENSE_3 = 171;
		static const auto TRICON_BADGE_FLAGDEFENSE_2 = 172;
		static const auto TRICON_BADGE_FLAGDEFENSE_1 = 173;
		static const auto TRICON_BADGE_OPERATOR_4 = 174;
		static const auto TRICON_BADGE_OPERATOR_3 = 175;
		static const auto TRICON_BADGE_OPERATOR_2 = 176;
		static const auto TRICON_BADGE_OPERATOR_1 = 177;
		static const auto TRICON_BADGE_CALLINKILLS_4 = 178;
		static const auto TRICON_BADGE_CALLINKILLS_3 = 179;
		static const auto TRICON_BADGE_CALLINKILLS_2 = 180;
		static const auto TRICON_BADGE_CALLINKILLS_1 = 181;
		static const auto TRICON_BADGE_MELEEKILLS_4 = 182;
		static const auto TRICON_BADGE_MELEEKILLS_3 = 183;
		static const auto TRICON_BADGE_MELEEKILLS_2 = 184;
		static const auto TRICON_BADGE_MELEEKILLS_1 = 185;
		static const auto TRICON_BADGE_ONEMANARMY_4 = 186;
		static const auto TRICON_BADGE_ONEMANARMY_3 = 187;
		static const auto TRICON_BADGE_ONEMANARMY_2 = 188;
		static const auto TRICON_BADGE_ONEMANARMY_1 = 189;
		static const auto TRICON_BADGE_FLAGCAPPER_4 = 190;
		static const auto TRICON_BADGE_FLAGCAPPER_3 = 191;
		static const auto TRICON_BADGE_FLAGCAPPER_2 = 192;
		static const auto TRICON_BADGE_FLAGCAPPER_1 = 193;
		static const auto TRICON_BADGE_TOUROFDUTY_4 = 194;
		static const auto TRICON_BADGE_TOUROFDUTY_3 = 195;
		static const auto TRICON_BADGE_TOUROFDUTY_2 = 196;
		static const auto TRICON_BADGE_TOUROFDUTY_1 = 197;
		static const auto TRICON_BADGE_MULTIKILL_4 = 198;
		static const auto TRICON_BADGE_MULTIKILL_3 = 199;
		static const auto TRICON_BADGE_MULTIKILL_2 = 200;
		static const auto TRICON_BADGE_MULTIKILL_1 = 201;
		static const auto TRICON_BADGE_COMBATSTAR_4 = 202;
		static const auto TRICON_BADGE_COMBATSTAR_3 = 203;
		static const auto TRICON_BADGE_COMBATSTAR_2 = 204;
		static const auto TRICON_BADGE_COMBATSTAR_1 = 205;
		static const auto TRICON_BADGE_CROSSCOUNTRY_4 = 206;
		static const auto TRICON_BADGE_CROSSCOUNTRY_3 = 207;
		static const auto TRICON_BADGE_CROSSCOUNTRY_2 = 208;
		static const auto TRICON_BADGE_CROSSCOUNTRY_1 = 209;
		static const auto TRICON_BADGE_POWERPLAYER_4 = 210;
		static const auto TRICON_BADGE_POWERPLAYER_3 = 211;
		static const auto TRICON_BADGE_POWERPLAYER_2 = 212;
		static const auto TRICON_BADGE_POWERPLAYER_1 = 213;
		static const auto TRICON_BADGE_DEMOMAN_4 = 214;
		static const auto TRICON_BADGE_DEMOMAN_3 = 215;
		static const auto TRICON_BADGE_DEMOMAN_2 = 216;
		static const auto TRICON_BADGE_DEMOMAN_1 = 217;
		static const auto TRICON_BADGE_SPEEDRUNNER_4 = 218;
		static const auto TRICON_BADGE_SPEEDRUNNER_3 = 219;
		static const auto TRICON_BADGE_SPEEDRUNNER_2 = 220;
		static const auto TRICON_BADGE_SPEEDRUNNER_1 = 221;
		static const auto TRICON_BADGE_GOODDRIVER_4 = 222;
		static const auto TRICON_BADGE_GOODDRIVER_3 = 223;
		static const auto TRICON_BADGE_GOODDRIVER_2 = 224;
		static const auto TRICON_BADGE_GOODDRIVER_1 = 225;
		static const auto TRICON_BADGE_PURPLEHEART_4 = 226;
		static const auto TRICON_BADGE_PURPLEHEART_3 = 227;
		static const auto TRICON_BADGE_PURPLEHEART_2 = 228;
		static const auto TRICON_BADGE_PURPLEHEART_1 = 229;
		static const auto TRICON_BADGE_HAPPENSTOUSALL = 230;
		static const auto TRICON_BADGE_INVSTATION = 231;
		static const auto TRICON_BADGE_ANTIVEHICLE_4 = 232;
		static const auto TRICON_BADGE_ANTIVEHICLE_3 = 233;
		static const auto TRICON_BADGE_ANTIVEHICLE_2 = 234;
		static const auto TRICON_BADGE_ANTIVEHICLE_1 = 235;
		static const auto TRICON_BADGE_UTILITYBELT_4 = 236;
		static const auto TRICON_BADGE_UTILITYBELT_3 = 237;
		static const auto TRICON_BADGE_UTILITYBELT_2 = 238;
		static const auto TRICON_BADGE_UTILITYBELT_1 = 239;
		static const auto TRICON_BADGE_ONCALL_4 = 240;
		static const auto TRICON_BADGE_ONCALL_3 = 241;
		static const auto TRICON_BADGE_ONCALL_2 = 242;
		static const auto TRICON_BADGE_ONCALL_1 = 243;
		static const auto TRICON_BADGE_SUPPORT_4 = 244;
		static const auto TRICON_BADGE_SUPPORT_3 = 245;
		static const auto TRICON_BADGE_SUPPORT_2 = 246;
		static const auto TRICON_BADGE_SUPPORT_1 = 247;
		static const auto TRICON_BADGE_MARKSMAN_4 = 248;
		static const auto TRICON_BADGE_MARKSMAN_3 = 249;
		static const auto TRICON_BADGE_MARKSMAN_2 = 250;
		static const auto TRICON_BADGE_MARKSMAN_1 = 251;
		static const auto TRICON_BADGE_ASSISTOR_4 = 252;
		static const auto TRICON_BADGE_ASSISTOR_3 = 253;
		static const auto TRICON_BADGE_ASSISTOR_2 = 254;
		static const auto TRICON_BADGE_ASSISTOR_1 = 255;
		static const auto TRICON_BADGE_BUILDER_4 = 256;
		static const auto TRICON_BADGE_BUILDER_3 = 257;
		static const auto TRICON_BADGE_BUILDER_2 = 258;
		static const auto TRICON_BADGE_BUILDER_1 = 259;
		static const auto TRICON_BADGE_GOINGFAST_4 = 260;
		static const auto TRICON_BADGE_GOINGFAST_3 = 261;
		static const auto TRICON_BADGE_GOINGFAST_2 = 262;
		static const auto TRICON_BADGE_GOINGFAST_1 = 263;
		static const auto RANK_XP_1 = 0;
		static const auto RANK_XP_2 = 1350;
		static const auto RANK_XP_3 = 2781;
		static const auto RANK_XP_4 = 4298;
		static const auto RANK_XP_5 = 5906;
		static const auto RANK_XP_6 = 11212;
		static const auto RANK_XP_7 = 16836;
		static const auto RANK_XP_8 = 22798;
		static const auto RANK_XP_9 = 31741;
		static const auto RANK_XP_10 = 41130;
		static const auto RANK_XP_11 = 50990;
		static const auto RANK_XP_12 = 61342;
		static const auto RANK_XP_13 = 76870;
		static const auto RANK_XP_14 = 93020;
		static const auto RANK_XP_15 = 109815;
		static const auto RANK_XP_16 = 127283;
		static const auto RANK_XP_17 = 145449;
		static const auto RANK_XP_18 = 172698;
		static const auto RANK_XP_19 = 200765;
		static const auto RANK_XP_20 = 229673;
		static const auto RANK_XP_21 = 259449;
		static const auto RANK_XP_22 = 290118;
		static const auto RANK_XP_23 = 321707;
		static const auto RANK_XP_24 = 369091;
		static const auto RANK_XP_25 = 417896;
		static const auto RANK_XP_26 = 468166;
		static const auto RANK_XP_27 = 519943;
		static const auto RANK_XP_28 = 573274;
		static const auto RANK_XP_29 = 628205;
		static const auto RANK_XP_30 = 684783;
		static const auto RANK_XP_31 = 743059;
		static const auto RANK_XP_32 = 803084;
		static const auto RANK_XP_33 = 864909;
		static const auto RANK_XP_34 = 928589;
		static const auto RANK_XP_35 = 994179;
		static const auto RANK_XP_36 = 1061737;
		static const auto RANK_XP_37 = 1131321;
		static const auto RANK_XP_38 = 1202994;
		static const auto RANK_XP_39 = 1276816;
		static const auto RANK_XP_40 = 1352853;
		static const auto RANK_XP_41 = 1431171;
		static const auto RANK_XP_42 = 1511839;
		static const auto RANK_XP_43 = 1594926;
		static const auto RANK_XP_44 = 1680507;
		static const auto RANK_XP_45 = 1768654;
		static const auto RANK_XP_46 = 1859447;
		static const auto RANK_XP_47 = 1952963;
		static const auto RANK_XP_48 = 2049284;
		static const auto RANK_XP_49 = 2148495;
		static const auto RANK_XP_50 = 2250682;
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
		struct EffectInfo
		{
		public:
			ADD_STRUCT(float, interval, 20)
			ADD_STRUCT(float, Value, 16)
			ADD_STRUCT(float, Lifetime, 12)
			ADD_STRUCT(TrObject::EffectType, Type, 8)
			ADD_OBJECT(ScriptClass, effectClass, 4)
			ADD_STRUCT(byte, FireModeNum, 0)
		};
		struct ReplicatedAmmoCount
		{
		public:
			ADD_STRUCT(int, ClipAmmoCount, 4)
			ADD_STRUCT(int, CarriedAmmoCount, 0)
		};
		struct DeviceModification
		{
		public:
			ADD_STRUCT(float, Value, 4)
			ADD_STRUCT(int, ModType, 0)
		};
		struct DeviceUpgrade
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
		ADD_STRUCT(Vector, m_vClientSideFireOffset, 2136)
		ADD_OBJECT(TrDeviceContentData, m_ContentData, 2132)
		ADD_STRUCT(ScriptString*, m_sContentDataClassName, 2120)
		ADD_STRUCT(TrDevice::DeviceUpgrade, BaseMod, 2100)
		ADD_STRUCT(TrObject::PaperDollInfo, m_InGamePaperDollInfo, 1944)
		ADD_STRUCT(TrObject::PaperDollInfo, m_MainMenuPaperDollInfo, 1888)
		ADD_STRUCT(Vector, m_TinyWeaponsOffset, 1876)
		ADD_STRUCT(float, m_fTimeBeforeInactiveReload, 1872)
		ADD_STRUCT(float, m_fLastActiveTime, 1868)
		ADD_STRUCT(int, m_nTetherCounter, 1864)
		ADD_OBJECT(AnimSet, m_NoAmmoAnimSet, 1860)
		ADD_STRUCT(float, m_fFireIntervalForLastShotInClip, 1856)
		ADD_STRUCT(float, m_fClientSideHitLeeway, 1852)
		ADD_OBJECT(MaterialInstanceConstant, m_ZoomOverlayMaterial, 1836)
		ADD_STRUCT(ScriptName, m_nmZoomMaterialEffectName, 1828)
		ADD_STRUCT(Vector, m_vZoomMeshOffset, 1816)
		ADD_STRUCT(float, m_fZoomRate, 1812)
		ADD_STRUCT(float, m_fDesiredZoomFOV, 1808)
		ADD_STRUCT(int, m_ShotsFired, 1804)
		ADD_STRUCT(Vector, m_vPositionPivotOffset, 1792)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53737);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetAccuracy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61617);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		byte GetFireModeNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67278);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool IsValidTarget(class Actor* Target, int nFireMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67280);
			byte params[12] = { NULL };
			*(class Actor**)params = Target;
			*(int*)&params[4] = nFireMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsEnemy(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67284);
			byte params[8] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsInsideCone(Vector SourceLookDir, class Actor* TargetActor, Vector StartCone, float MinCosine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67287);
			byte params[36] = { NULL };
			*(Vector*)params = SourceLookDir;
			*(class Actor**)&params[12] = TargetActor;
			*(Vector*)&params[16] = StartCone;
			*(float*)&params[28] = MinCosine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool ShouldAddToImpactList(class Actor* HitActor, ScriptArray<Actor::ImpactInfo> ImpactList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67293);
			byte params[20] = { NULL };
			*(class Actor**)params = HitActor;
			*(ScriptArray<Actor::ImpactInfo>*)&params[4] = ImpactList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void TickInHandWeapon(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67298);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetLock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67300);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetLockedTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67301);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		class TrDeployable* SpawnPet(bool bPet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67303);
			byte params[8] = { NULL };
			*(bool*)params = bPet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeployable**)&params[4];
		}
		float GetTargetAccuracy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67306);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void RestoreAccuracy(float fTimeStep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67308);
			byte params[4] = { NULL };
			*(float*)params = fTimeStep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestoreKickback(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67310);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInLOS(class Actor* TouchedActor, Vector ExpectedLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67312);
			byte params[20] = { NULL };
			*(class Actor**)params = TouchedActor;
			*(Vector*)&params[4] = ExpectedLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AttachHandsMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67316);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class TrDeviceContentData* LoadMeshData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67317);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDeviceContentData**)params;
		}
		int ValidateClientReportedHit(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67319);
			byte params[93] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			*(bool*)&params[88] = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[92];
		}
		int ValidateClientReportedHitInternal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot, bool bDeviceIsFiring)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67325);
			byte params[93] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			*(bool*)&params[88] = bDeviceIsFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[92];
		}
		ScriptString* GetObjectReferencerName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67331);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetObjectReferencerPackageName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67333);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67338);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67340);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67341);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool ReplicateAmmoOnWeaponFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67344);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ConsumeAmmo_Internal(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67346);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsumeAmmo(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67348);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetTraceOwner()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67350);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		void AttachWeaponTo(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshCpnt, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67353);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshCpnt;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateFirstPersonHandsMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67362);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeVisibility(bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67365);
			byte params[4] = { NULL };
			*(bool*)params = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CentralUpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67367);
			byte params[4] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67370);
			byte params[4] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateOverlayMesh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67377);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67383);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67385);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayRetrieveAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67398);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67399);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponEmpty()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67404);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchToWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67405);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67406);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWeaponSet(bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67407);
			byte params[8] = { NULL };
			*(bool*)params = bOptionalSet;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67411);
			byte params[13] = { NULL };
			*params = FireModeNum;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireAnimation(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67414);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShakeView()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireTracer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67418);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldFireTracerBeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67420);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpawnTracerBeam(Vector Start, Vector End)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67422);
			byte params[24] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProj_Tracer* SpawnTracerEffect(Vector HitLocation, float HitDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67426);
			byte params[20] = { NULL };
			*(Vector*)params = HitLocation;
			*(float*)&params[12] = HitDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[16];
		}
		class TrProj_Tracer* GetTracer(Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67434);
			byte params[28] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(Rotator*)&params[12] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[24];
		}
		int GetNumRoundsCurrentlyInClip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67442);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool HasAmmo(byte FireModeNum, int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67444);
			byte params[9] = { NULL };
			*params = FireModeNum;
			*(int*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool HasAnyAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67450);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool AllowSwitchTo(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67452);
			byte params[8] = { NULL };
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float CalculateRangeDamageFalloff(float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67455);
			byte params[8] = { NULL };
			*(float*)params = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void InstantFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessInstantHit(byte FiringMode, Actor::ImpactInfo Impact, int NumHits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67472);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(int*)&params[84] = NumHits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerNotifyHit(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67480);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessInstantHit_Internal(byte FiringMode, Actor::ImpactInfo Impact, bool bHeadShot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67489);
			byte params[85] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(bool*)&params[84] = bHeadShot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float ModifyInstantHitDamage(byte FiringMode, Actor::ImpactInfo Impact, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67497);
			byte params[89] = { NULL };
			*params = FiringMode;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			*(float*)&params[84] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[88];
		}
		void ProcessEffect(class Actor* Target, byte FiringMode, TrObject::EffectType efType, bool bRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67502);
			byte params[10] = { NULL };
			*(class Actor**)params = Target;
			params[4] = FiringMode;
			*(TrObject::EffectType*)&params[5] = efType;
			*(bool*)&params[8] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UsesPower()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67511);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsDeviceCoolingDown(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67513);
			byte params[5] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EnterDeployMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67516);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67517);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleActivate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67518);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67519);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForWeaponSwitch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67522);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PayAccuracyForShot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67524);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Rotator AddSpreadWithAccuracy(Rotator BaseAim, float fAccuracy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67526);
			byte params[28] = { NULL };
			*(Rotator*)params = BaseAim;
			*(float*)&params[12] = fAccuracy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		Rotator ApplyKickbackToAim(Rotator Aim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67537);
			byte params[24] = { NULL };
			*(Rotator*)params = Aim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		Object::Vector2D GetCurrentKickbackAmount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67544);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector2D*)params;
		}
		bool AddKickback()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67547);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetAdjustedAim(Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67550);
			byte params[24] = { NULL };
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		bool ShowWeaponRedLowAmmoIndicator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67556);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67558);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetAmmoCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67560);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void UpdateLowAmmoWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67562);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* GetProjectileClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67565);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		Vector GetClientSideProjectileFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67567);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67581);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void DestroyOldestProjectileOverLimit(class Projectile* newProjectile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67598);
			byte params[4] = { NULL };
			*(class Projectile**)params = newProjectile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67604);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float MaxRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67613);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetWeaponRange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67616);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Rotator GetAimForCamera(Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67618);
			byte params[24] = { NULL };
			*(Vector*)params = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[12];
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67621);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void HolderEnteredVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetReloadTime(class PlayerReplicationInfo* PRI, TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67654);
			byte params[9] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(TrObject::TR_EQUIP_POINT*)&params[4] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void ClearMeshAnimSeqNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67690);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CacheMeshAnimSeqNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67691);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressAnimNotifies(bool bSuppress)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67694);
			byte params[4] = { NULL };
			*(bool*)params = bSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsReloading()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67697);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RequestReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67699);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClientReloaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67700);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67701);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CalcAmountToLoad()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67703);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ClientFinishedReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67732);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResumeZoomOnReloadEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67733);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayReloadAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67735);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableWeaponReadyToFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67738);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReloadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67739);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginAReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67740);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int AddCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67741);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67745);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GoInactiveDueToOffhand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67746);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67747);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67749);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetEquipTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67751);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void TimeWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67758);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetPutDownTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67760);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool CanFireOffhandNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67766);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerOnClientDeniedFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67768);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyEquipEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67786);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveEquipEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67787);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPosition(class UDKPawn* Holder, float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67788);
			byte params[8] = { NULL };
			*(class UDKPawn**)params = Holder;
			*(float*)&params[4] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int LagRot(int NewValue, int LastValue, float MaxDiff, int Index, float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67812);
			byte params[24] = { NULL };
			*(int*)params = NewValue;
			*(int*)&params[4] = LastValue;
			*(float*)&params[8] = MaxDiff;
			*(int*)&params[12] = Index;
			*(float*)&params[16] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		bool ShouldRefire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67821);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67823);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Activate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67825);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceInvalidPickup(class TrPawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67826);
			byte params[4] = { NULL };
			*(class TrPawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67828);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PutDownFast()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67832);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceEndFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67833);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanAutoDeviceFireNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67847);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CustomFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67849);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AttachMuzzleFlash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67853);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WeaponPlaySoundLocal(class SoundCue* Sound, float NoiseLoudness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67854);
			byte params[8] = { NULL };
			*(class SoundCue**)params = Sound;
			*(float*)&params[4] = NoiseLoudness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponThrown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67857);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShotsFired(bool Reset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67859);
			byte params[4] = { NULL };
			*(bool*)params = Reset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67861);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndZoom(class UTPlayerController* PC, bool bReturningTo3P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67866);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			*(bool*)&params[4] = bReturningTo3P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanViewZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67870);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetAltReticule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67872);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetAltReticule()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67879);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Actor::ImpactInfo CalcWeaponFire(Vector StartTrace, Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67884);
			byte params[128] = { NULL };
			*(Vector*)params = StartTrace;
			*(Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
		void PlayDryFireZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67908);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuffMaxCarriedAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67909);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetMaxAmmoCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67911);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		int GetBasePickupAmmoAmount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67922);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ServerStartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67924);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateWeaponMICs()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67927);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
