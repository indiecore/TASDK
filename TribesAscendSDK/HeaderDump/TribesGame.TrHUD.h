#pragma once
#include "UTGame.UTGFxHudWrapper.h"
#include "Core.Object.h"
#include "TribesGame.TrSpectatorHUDCache.h"
#include "TribesGame.TrCamera_SpectatorBookmark.h"
#include "TribesGame.TrVehicle.h"
#include "Engine.Canvas.h"
#include "TribesGame.GFxTrUI_TeamSelectionMenu.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrDeployable.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Texture2D.h"
#include "TribesGame.GfxTrHud.h"
#include "TribesGame.TrCaHStats.h"
#include "TribesGame.TrProj_Mine.h"
#include "Engine.UberPostProcessEffect.h"
#include "Engine.MaterialEffect.h"
#include "TribesGame.TrDaDStats.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrArenaStats.h"
#include "PlatformCommon.TgSupportCommands.h"
#include "TribesGame.TrTeamRabbitStats.h"
#include "TribesGame.TrHUDTeamCTFStats.h"
#include "TribesGame.TrRabbitLeaderboard.h"
#include "TribesGame.TrScoreboard.h"
#include "TribesGame.GFxTrUI_VehicleMenu.h"
#include "Engine.Material.h"
#include "TribesGame.TrPawn.h"
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
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
	class TrHUD : public UTGFxHudWrapper
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
		struct QueuedAccolade
		{
		public:
			ADD_STRUCT(ScriptString*, Subtitle, 20)
			ADD_STRUCT(ScriptString*, Title, 8)
			ADD_BOOL(bIsBadge, 4, 0x1)
			ADD_STRUCT(int, Icon, 0)
		};
		struct OverheadNumber
		{
		public:
			ADD_STRUCT(float, CurrentScale, 36)
			ADD_STRUCT(Object::Color, CurrentColor, 32)
			ADD_STRUCT(Object::Vector4, WorldSpaceLocation, 16)
			ADD_STRUCT(float, RemainingTime, 4)
			ADD_STRUCT(int, NumberValue, 0)
		};
		ADD_BOOL(m_bIsControllerSkiing, 1548, 0x8)
		ADD_OBJECT(TrSpectatorHUDCache, m_SpectatorHUDCache, 2424)
		ADD_OBJECT(GFxTrUI_TeamSelectionMenu, TeamSelectionMenuMovie, 2044)
		ADD_OBJECT(TrPlayerController, TrPlayerOwner, 2096)
		ADD_BOOL(bIsMainMenuOpen, 1548, 0x1000)
		ADD_OBJECT(MaterialInstanceConstant, MarkerBaseMIC, 1632)
		ADD_BOOL(bShowObjectives, 1548, 0x4)
		ADD_STRUCT(Object::LinearColor, MarkerColorFriendly, 1668)
		ADD_STRUCT(Object::LinearColor, MarkerColorEnemy, 1636)
		ADD_OBJECT(Texture2D, BaseDeployableLevel1, 1820)
		ADD_OBJECT(Texture2D, BaseDeployableLevel2, 1824)
		ADD_OBJECT(Texture2D, BaseDeployableLevel3, 1828)
		ADD_OBJECT(Texture2D, BaseDeployableLevel4, 1832)
		ADD_OBJECT(Texture2D, BaseDeployableLevel5, 1836)
		ADD_OBJECT(Texture2D, BaseNoPower, 1816)
		ADD_OBJECT(Texture2D, DeployableTurret, 1980)
		ADD_OBJECT(Texture2D, BaseTurretLevel1, 1920)
		ADD_OBJECT(Texture2D, BaseTurretLevel2, 1924)
		ADD_OBJECT(Texture2D, BaseTurretLevel3, 1928)
		ADD_OBJECT(Texture2D, BaseTurretLevel4, 1932)
		ADD_OBJECT(Texture2D, BaseTurretLevel5, 1936)
		ADD_OBJECT(Texture2D, BaseTurretLevel1_Down, 1940)
		ADD_OBJECT(Texture2D, BaseTurretLevel2_Down, 1944)
		ADD_OBJECT(Texture2D, BaseTurretLevel3_Down, 1948)
		ADD_OBJECT(Texture2D, BaseTurretLevel4_Down, 1952)
		ADD_OBJECT(Texture2D, BaseTurretLevel5_Down, 1956)
		ADD_STRUCT(int, m_nPotentialSeekingTargetHUDRotationRate, 2276)
		ADD_STRUCT(float, m_fPotentialSeekingTargetHUDZoomTime, 2280)
		ADD_STRUCT(float, m_fSeekingTargetHUDZoomTime, 2300)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocked, 1784)
		ADD_STRUCT(float, m_fSeekingTargetHUDZoomEnd, 2308)
		ADD_STRUCT(float, m_fSeekingTargetHUDZoomOpacityStart, 2312)
		ADD_STRUCT(float, m_fSeekingTargetHUDZoomOpacityEnd, 2316)
		ADD_STRUCT(float, m_fSeekingTargetHUDZoomStart, 2304)
		ADD_STRUCT(float, m_fInitialSeekingTargetYaw, 2320)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocking, 1780)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTargetLocked, 1792)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTarget, 1788)
		ADD_STRUCT(float, m_fPotentialSeekingTargetHUDZoomOpacityStart, 2292)
		ADD_STRUCT(float, m_fPotentialSeekingTargetHUDZoomOpacityEnd, 2296)
		ADD_STRUCT(float, m_fPotentialSeekingTargetHUDZoomStart, 2284)
		ADD_STRUCT(float, m_fPotentialSeekingTargetHUDZoomEnd, 2288)
		ADD_STRUCT(float, m_fCaratPlacementX, 2348)
		ADD_STRUCT(float, m_fCaratPlacementY, 2352)
		ADD_STRUCT(float, m_fMarker2DDistance, 2488)
		ADD_STRUCT(float, m_fCurrentWhiteoutValue, 2232)
		ADD_STRUCT(float, TeamPlayerInfoMaxDist, 1576)
		ADD_OBJECT(Texture2D, DeployableSensor, 1972)
		ADD_OBJECT(Texture2D, MarkerLight, 1716)
		ADD_OBJECT(Texture2D, MarkerMedium, 1720)
		ADD_OBJECT(Texture2D, MarkerHeavy, 1724)
		ADD_OBJECT(Texture2D, FlagHeldLight, 1756)
		ADD_OBJECT(Texture2D, FlagHeldMedium, 1760)
		ADD_OBJECT(Texture2D, FlagHeldHeavy, 1764)
		ADD_STRUCT(Object::LinearColor, MarkerColorEnemy_IsFriend, 1652)
		ADD_STRUCT(float, m_fNamePlacementX, 2340)
		ADD_STRUCT(float, m_fNamePlacementY, 2344)
		ADD_STRUCT(float, m_fHealthBarPlacementX, 2324)
		ADD_STRUCT(float, m_fHealthBarPlacementY, 2328)
		ADD_STRUCT(float, m_fHealthBarWidth, 2332)
		ADD_STRUCT(float, m_fHealthBarHeight, 2336)
		ADD_STRUCT(Object::LinearColor, MarkerColorFriendly_IsFriend, 1684)
		ADD_OBJECT(GfxTrHud, m_GFxHud, 2076)
		ADD_STRUCT(int, FriendlyChatColorIdx, 2004)
		ADD_STRUCT(Object::Color, FriendlyChatColor, 2016)
		ADD_STRUCT(int, EnemyChatColorIdx, 2000)
		ADD_STRUCT(Object::Color, EnemyChatColor, 2020)
		ADD_STRUCT(int, WhisperChatColorIdx, 2012)
		ADD_STRUCT(Object::Color, WhisperChatColor, 2028)
		ADD_STRUCT(int, InfoChatColorIdx, 1996)
		ADD_BOOL(bVotePending, 1548, 0x800)
		ADD_OBJECT(Texture2D, FlagEmptyBase, 1772)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1, 1840)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1_Down, 1860)
		ADD_OBJECT(Texture2D, DeployableJammer, 1964)
		ADD_OBJECT(Texture2D, DeployableShield, 1976)
		ADD_OBJECT(Texture2D, BaseSensorLevel1, 1880)
		ADD_OBJECT(Texture2D, BaseSensorLevel2, 1884)
		ADD_OBJECT(Texture2D, BaseSensorLevel3, 1888)
		ADD_OBJECT(Texture2D, BaseSensorLevel4, 1892)
		ADD_OBJECT(Texture2D, BaseSensorLevel5, 1896)
		ADD_OBJECT(Texture2D, BaseSensorLevel1_Down, 1900)
		ADD_OBJECT(Texture2D, BaseSensorLevel2_Down, 1904)
		ADD_OBJECT(Texture2D, BaseSensorLevel3_Down, 1908)
		ADD_OBJECT(Texture2D, BaseSensorLevel4_Down, 1912)
		ADD_OBJECT(Texture2D, BaseSensorLevel5_Down, 1916)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTargetAimPoint, 1800)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTarget, 1796)
		ADD_STRUCT(Object::Color, LaserTargetTracePossible, 1592)
		ADD_STRUCT(Object::Color, LaserTargetTraceImprobable, 1596)
		ADD_OBJECT(Texture2D, AmmoDropPickup, 1984)
		ADD_OBJECT(Texture2D, FlagAtBase, 1748)
		ADD_OBJECT(Texture2D, FlagDropped, 1752)
		ADD_STRUCT(ScriptArray<class TrDeployable*>, m_OwnedDeployables, 1600)
		ADD_STRUCT(ScriptArray<class TrProj_Mine*>, m_OwnedMines, 1612)
		ADD_STRUCT(ScriptArray<TrHUD::QueuedAccolade>, QueuedAccolades, 2428)
		ADD_STRUCT(ScriptArray<TrHUD::OverheadNumber>, m_OverheadNumbers, 2440)
		ADD_STRUCT(float, m_fOverheadNumberColorizeTimeMax, 2484)
		ADD_STRUCT(float, m_fOverheadNumberColorizeTimeMin, 2480)
		ADD_STRUCT(float, m_fOverheadNumberMaxScaleAmount, 2476)
		ADD_STRUCT(float, m_fOverheadNumberScaleTime, 2472)
		ADD_STRUCT(float, m_fOverheadNumberFadeTime, 2468)
		ADD_STRUCT(float, m_fOverheadNumberTotalTime, 2464)
		ADD_STRUCT(Object::Color, m_OverheadNumberColorMax, 2460)
		ADD_STRUCT(Object::Color, m_OverheadNumberColorMin, 2456)
		ADD_STRUCT(float, m_fOverheadNumberZSpeed, 2452)
		ADD_OBJECT(UberPostProcessEffect, m_UperPPEffect, 2420)
		ADD_STRUCT(Canvas::FontRenderInfo, m_nNameFontRenderInfo, 2380)
		ADD_STRUCT(float, m_fMineDeployerNamePlacementY, 2376)
		ADD_STRUCT(float, m_fMineDeployerNamePlacementX, 2372)
		ADD_STRUCT(float, m_fMineNamePlacementY, 2368)
		ADD_STRUCT(float, m_fMineNamePlacementX, 2364)
		ADD_STRUCT(float, m_fVehicleNamePlacementY, 2360)
		ADD_STRUCT(float, m_fVehicleNamePlacementX, 2356)
		ADD_OBJECT(MaterialInstanceConstant, AwardMIC, 2272)
		ADD_STRUCT(float, AwardTimelineLoc, 2268)
		ADD_STRUCT(float, AwardFadeInScale, 2264)
		ADD_STRUCT(float, AwardTimelineLength, 2260)
		ADD_STRUCT(float, AwardBaseHeight, 2256)
		ADD_STRUCT(float, AwardBaseSize, 2252)
		ADD_STRUCT(float, m_fCurrentFumbledFlagValue, 2248)
		ADD_STRUCT(float, m_FumbledFlagFadeOutSpeed, 2244)
		ADD_OBJECT(MaterialInstanceConstant, m_FumbledFlagMaterialInstance, 2240)
		ADD_OBJECT(MaterialEffect, m_FumbledFlagMaterialEffect, 2236)
		ADD_STRUCT(float, m_WhiteoutFadeOutSpeed, 2228)
		ADD_OBJECT(MaterialInstanceConstant, m_WhiteoutMaterialInstance, 2224)
		ADD_OBJECT(MaterialEffect, m_WhiteoutMaterialEffect, 2220)
		ADD_STRUCT(float, m_VignetteValueMultiplier, 2216)
		ADD_STRUCT(float, m_VignetteFadeTarget, 2212)
		ADD_STRUCT(float, m_VignetteFadeSpeed, 2208)
		ADD_OBJECT(MaterialInstanceConstant, m_VignetteMaterialInstance, 2204)
		ADD_OBJECT(MaterialEffect, m_VignetteMaterialEffect, 2200)
		ADD_STRUCT(int, LastChangeResCheckTime, 2196)
		ADD_STRUCT(int, LastChangeResTime, 2192)
		ADD_STRUCT(int, LastCreditTotal, 2188)
		ADD_STRUCT(float, m_JammerPackFadeOutSpeed, 2184)
		ADD_OBJECT(MaterialInstanceConstant, m_JammerPackMaterialInstance, 2180)
		ADD_OBJECT(MaterialEffect, m_JammerPackMaterialEffect, 2176)
		ADD_STRUCT(float, m_ShieldHitFadeOutSpeed, 2172)
		ADD_STRUCT(float, m_ShieldHitFadeInSpeed, 2168)
		ADD_STRUCT(float, m_ShieldFadeOutSpeed, 2164)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldMaterialInstance, 2160)
		ADD_OBJECT(MaterialEffect, m_ShieldMaterialEffect, 2156)
		ADD_STRUCT(float, m_InvulnerableFadeOutSpeed, 2152)
		ADD_OBJECT(MaterialInstanceConstant, m_InvulnerableMaterialInstance, 2148)
		ADD_OBJECT(MaterialEffect, m_InvulnerableMaterialEffect, 2144)
		ADD_STRUCT(float, m_PickupFlashFadeOutSpeed, 2140)
		ADD_OBJECT(MaterialInstanceConstant, m_PickupFlashMaterialInstance, 2136)
		ADD_OBJECT(MaterialEffect, m_PickupFlashMaterialEffect, 2132)
		ADD_STRUCT(float, m_fSkiEffectStrobeTime, 2128)
		ADD_STRUCT(float, m_fSkiEffectFadeOutTime, 2124)
		ADD_STRUCT(float, m_fSkiEffectFadeInTime, 2120)
		ADD_STRUCT(float, m_fSkiEffectMinIntensity, 2116)
		ADD_STRUCT(float, m_fSkiEffectMaxIntensity, 2112)
		ADD_STRUCT(float, m_fControllerSkiSpeed, 2108)
		ADD_OBJECT(MaterialInstanceConstant, m_SkiEffectMaterialInstance, 2104)
		ADD_OBJECT(MaterialEffect, m_SkiEffect, 2100)
		ADD_OBJECT(ScriptClass, m_GameClass, 2092)
		ADD_OBJECT(ScriptClass, m_MusicManagerClass, 2088)
		ADD_STRUCT(float, m_fEnemyGeneratorRestoreTime, 2084)
		ADD_STRUCT(float, m_fFriendlyGeneratorRestoreTime, 2080)
		ADD_OBJECT(TrCaHStats, CaHStats, 2072)
		ADD_OBJECT(TrDaDStats, DaDStats, 2068)
		ADD_OBJECT(TrArenaStats, ArenaStats, 2064)
		ADD_OBJECT(TrTeamRabbitStats, TeamRabbitStats, 2060)
		ADD_OBJECT(TrHUDTeamCTFStats, HUDTeamCTFStats, 2056)
		ADD_OBJECT(TrRabbitLeaderboard, RabbitLeaderboard, 2052)
		ADD_OBJECT(TrScoreboard, Scoreboard, 2048)
		ADD_OBJECT(GFxTrUI_VehicleMenu, VehicleMenuMovie, 2040)
		ADD_OBJECT(Material, MapMaterialReference, 2036)
		ADD_OBJECT(MaterialInstanceConstant, LowAmmoMic, 2032)
		ADD_STRUCT(Object::Color, TeamChatColor, 2024)
		ADD_STRUCT(int, SelfChatColorIdx, 2008)
		ADD_OBJECT(Texture2D, SpottedTarget_MotionMine, 1992)
		ADD_OBJECT(Texture2D, SpottedTarget, 1988)
		ADD_OBJECT(Texture2D, DeployableMine, 1968)
		ADD_OBJECT(Texture2D, DeployableClaymore, 1960)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5_Down, 1876)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4_Down, 1872)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3_Down, 1868)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2_Down, 1864)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5, 1856)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4, 1852)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3, 1848)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2, 1844)
		ADD_OBJECT(Texture2D, BaseVehicleStation, 1812)
		ADD_OBJECT(Texture2D, BaseRepairStation, 1808)
		ADD_OBJECT(Texture2D, BaseInventoryStation, 1804)
		ADD_OBJECT(Texture2D, HUDMarkerMissileIncoming, 1776)
		ADD_OBJECT(Texture2D, FlagHeldVehicle, 1768)
		ADD_OBJECT(Texture2D, VehicleMarkerNoDriver, 1744)
		ADD_OBJECT(Texture2D, VehicleMarkerHeavy, 1740)
		ADD_OBJECT(Texture2D, VehicleMarkerMedium, 1736)
		ADD_OBJECT(Texture2D, VehicleMarkerLight, 1732)
		ADD_OBJECT(Texture2D, VehicleMarker, 1728)
		ADD_STRUCT(Object::LinearColor, MarkerColorNone, 1700)
		ADD_STRUCT(int, m_LastDeployableCount, 1628)
		ADD_STRUCT(int, m_LastMineCount, 1624)
		ADD_STRUCT(Object::Color, ColorEnemy, 1588)
		ADD_STRUCT(Object::Color, ColorFriend, 1584)
		ADD_STRUCT(float, ObjectiveInfoMaxDist, 1580)
		ADD_STRUCT(ScriptString*, m_sLastClassName, 1564)
		ADD_STRUCT(ScriptString*, m_sWinningPlayer, 1552)
		ADD_BOOL(bAccoladePlaying, 1548, 0x40000)
		ADD_BOOL(m_bIsSpectatorFloatCameraPanelVisible, 1548, 0x20000)
		ADD_BOOL(m_bIsSpectatorObjectivePanelVisible, 1548, 0x10000)
		ADD_BOOL(m_bIsSpectatorBookmarkPanelVisible, 1548, 0x8000)
		ADD_BOOL(m_bIsSpectatorVehiclePanelVisible, 1548, 0x4000)
		ADD_BOOL(m_bIsSpectatorPlayerPanelVisible, 1548, 0x2000)
		ADD_BOOL(bPlayAward, 1548, 0x400)
		ADD_BOOL(m_bUpdateFumbledFlagEffect, 1548, 0x200)
		ADD_BOOL(m_bUpdateWhiteoutEffect, 1548, 0x100)
		ADD_BOOL(bLoadSequenceComplete, 1548, 0x80)
		ADD_BOOL(bRestoreHUDState, 1548, 0x40)
		ADD_BOOL(m_bEffectFadingIn, 1548, 0x20)
		ADD_BOOL(m_bStrobeIn, 1548, 0x10)
		ADD_BOOL(HasGlobalChatAsAlert, 1548, 0x2)
		ADD_BOOL(m_bGameOver, 1548, 0x1)
		ADD_STRUCT(int, m_nLastPerk2Icon, 1544)
		ADD_STRUCT(int, m_nLastPerk1Icon, 1540)
		ADD_STRUCT(int, m_nWinningTeam, 1536)
		Vector DrawMarkerText(ScriptString* ShowText, bool bFriend, Vector Placement, class Canvas* DrawCanvas, bool bBuddy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71610);
			byte params[48] = { NULL };
			*(ScriptString**)params = ShowText;
			*(bool*)&params[12] = bFriend;
			*(Vector*)&params[16] = Placement;
			*(class Canvas**)&params[28] = DrawCanvas;
			*(bool*)&params[32] = bBuddy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[36];
		}
		Vector DrawMICMarker(class MaterialInstanceConstant* MarkerMIC, Vector Placement, class Canvas* DrawCanvas, Object::Vector2D MarkerSize, ScriptString* markText, bool bFriend, float distScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71612);
			byte params[60] = { NULL };
			*(class MaterialInstanceConstant**)params = MarkerMIC;
			*(Vector*)&params[4] = Placement;
			*(class Canvas**)&params[16] = DrawCanvas;
			*(Object::Vector2D*)&params[20] = MarkerSize;
			*(ScriptString**)&params[28] = markText;
			*(bool*)&params[40] = bFriend;
			*(float*)&params[44] = distScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[48];
		}
		bool GetEdgeScreenCoordinates(class Canvas* inCanvas, Vector CameraPosition, Vector CameraDir, Vector ObjectLocation, Vector& ScreenLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72894);
			byte params[56] = { NULL };
			*(class Canvas**)params = inCanvas;
			*(Vector*)&params[4] = CameraPosition;
			*(Vector*)&params[16] = CameraDir;
			*(Vector*)&params[28] = ObjectLocation;
			*(Vector*)&params[40] = ScreenLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ScreenLocation = *(Vector*)&params[40];
			return *(bool*)&params[52];
		}
		Vector DrawMarker(class Texture2D* Marker, Vector Placement, class Canvas* DrawCanvas, ScriptString* markText, bool bFriend, float Alpha, float distScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72902);
			byte params[56] = { NULL };
			*(class Texture2D**)params = Marker;
			*(Vector*)&params[4] = Placement;
			*(class Canvas**)&params[16] = DrawCanvas;
			*(ScriptString**)&params[20] = markText;
			*(bool*)&params[32] = bFriend;
			*(float*)&params[36] = Alpha;
			*(float*)&params[40] = distScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[44];
		}
		Vector DrawRotatedMarker(class Texture2D* Marker, Vector Placement, Rotator Rot, class Canvas* DrawCanvas, ScriptString* markText, bool bFriend, float Alpha, float distScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72910);
			byte params[68] = { NULL };
			*(class Texture2D**)params = Marker;
			*(Vector*)&params[4] = Placement;
			*(Rotator*)&params[16] = Rot;
			*(class Canvas**)&params[28] = DrawCanvas;
			*(ScriptString**)&params[32] = markText;
			*(bool*)&params[44] = bFriend;
			*(float*)&params[48] = Alpha;
			*(float*)&params[52] = distScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[56];
		}
		void ShowDebugInfo(float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96115);
			byte params[8] = { NULL };
			*(float*)params = out_YL;
			*(float*)&params[4] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)params;
			out_YPos = *(float*)&params[4];
		}
		void CreateHUDMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96120);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorControls(bool bForceEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96130);
			byte params[4] = { NULL };
			*(bool*)params = bForceEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShowScores(bool bEnableShowScores)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96132);
			byte params[4] = { NULL };
			*(bool*)params = bEnableShowScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96136);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeGameHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96137);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96145);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Fade(float FadeTarget, float FadeSpeed, float bForceFadeInStartAlpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96146);
			byte params[12] = { NULL };
			*(float*)params = FadeTarget;
			*(float*)&params[4] = FadeSpeed;
			*(float*)&params[8] = bForceFadeInStartAlpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRoundOver(int WinningTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96150);
			byte params[4] = { NULL };
			*(int*)params = WinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowRoundEnding()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96152);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMatchOver(int Winner, ScriptString* WinnerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96153);
			byte params[16] = { NULL };
			*(int*)params = Winner;
			*(ScriptString**)&params[4] = WinnerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowEnding()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96156);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96159);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleformJoystickInputEvent(float leftAngle, float rightAngle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96160);
			byte params[8] = { NULL };
			*(float*)params = leftAngle;
			*(float*)&params[4] = rightAngle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleSkiEffect(bool bEnabled, float fSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96163);
			byte params[8] = { NULL };
			*(bool*)params = bEnabled;
			*(float*)&params[4] = fSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TogglePauseMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96166);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMovieHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96168);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleVehicleMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96169);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleTeamSelectionMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96172);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPowerOscillation(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96174);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddUpdateToCombatLog(int CombatType, ScriptString* Aggressor, int WeaponIcon, ScriptString* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96176);
			byte params[32] = { NULL };
			*(int*)params = CombatType;
			*(ScriptString**)&params[4] = Aggressor;
			*(int*)&params[16] = WeaponIcon;
			*(ScriptString**)&params[20] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddToPromptPanel(ScriptString* Message, TgSupportCommands::GC_ALERT_PRIORITY Priority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96181);
			byte params[13] = { NULL };
			*(ScriptString**)params = Message;
			*(TgSupportCommands::GC_ALERT_PRIORITY*)&params[12] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddToPromptPanelTime(ScriptString* Message, float EndTime, TgSupportCommands::GC_ALERT_PRIORITY Priority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96184);
			byte params[17] = { NULL };
			*(ScriptString**)params = Message;
			*(float*)&params[12] = EndTime;
			*(TgSupportCommands::GC_ALERT_PRIORITY*)&params[16] = Priority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPromptPanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96188);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToHeroStatus(ScriptString* Message, float ShowTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96189);
			byte params[16] = { NULL };
			*(ScriptString**)params = Message;
			*(float*)&params[12] = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHeroStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearPromptPanelMessage(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96193);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateVGSMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96195);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideVGSMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96196);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToHelpText(ScriptString* Title, ScriptString* Body, float PictureIndex, ScriptString* footer, ScriptString* SuppressString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96197);
			byte params[52] = { NULL };
			*(ScriptString**)params = Title;
			*(ScriptString**)&params[12] = Body;
			*(float*)&params[24] = PictureIndex;
			*(ScriptString**)&params[28] = footer;
			*(ScriptString**)&params[40] = SuppressString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHelpText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96203);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddUpdateToKillMessage(int RankIcon, int PlayerIcon, ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96204);
			byte params[32] = { NULL };
			*(int*)params = RankIcon;
			*(int*)&params[4] = PlayerIcon;
			*(ScriptString**)&params[8] = PlayerName;
			*(ScriptString**)&params[20] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlyingIcon(int iconNumber, ScriptString* Description, ScriptString* Points, int bIsBadge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96209);
			byte params[32] = { NULL };
			*(int*)params = iconNumber;
			*(ScriptString**)&params[4] = Description;
			*(ScriptString**)&params[16] = Points;
			*(int*)&params[28] = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSpectate(bool bUpdateTeamState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96214);
			byte params[4] = { NULL };
			*(bool*)params = bUpdateTeamState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateSpectatorHUDCache()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96216);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSpectatorHUDCache()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96217);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideHUDElements(bool bShowStats, bool bForceCredits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96218);
			byte params[8] = { NULL };
			*(bool*)params = bShowStats;
			*(bool*)&params[4] = bForceCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowHUDPlayerSpawning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96221);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUDPlayerAlive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96222);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowCenterHUDElements(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96223);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRespawnText(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96225);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRespawnTimer(int TimeRemaining)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96227);
			byte params[4] = { NULL };
			*(int*)params = TimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHUDCredits(int changeAmount, int newTotal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96229);
			byte params[8] = { NULL };
			*(int*)params = changeAmount;
			*(int*)&params[4] = newTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96232);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96234);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardUpdateSlot(int Index, ScriptString* PlayerName, ScriptString* Score, ScriptString* Kills, ScriptString* Assists, ScriptString* Ping, ScriptString* ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96236);
			byte params[84] = { NULL };
			*(int*)params = Index;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96246);
			byte params[84] = { NULL };
			*(int*)params = Index;
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
		void TeamScoreboardUpdateTeamScore(int Index, int Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96256);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96259);
			byte params[12] = { NULL };
			*(ScriptString**)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardUpdateTime(ScriptString* Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96261);
			byte params[12] = { NULL };
			*(ScriptString**)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamScoreboardActivePlayer(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96263);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RabbitScoreboardActivePlayer(int Index, bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96265);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(bool*)&params[4] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96268);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestoreHUDState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96271);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideMenus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96275);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96276);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteVehicleMenuClose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96277);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteTeamSelectionMenuClose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96278);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearCrosshairOnFriendly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96279);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckCrosshairOnFriendly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96280);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector DrawColoredMarkerText(ScriptString* ShowText, Object::Color TextColor, Vector Placement, class Canvas* DrawCanvas, float ScaleX, float ScaleY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96323);
			byte params[52] = { NULL };
			*(ScriptString**)params = ShowText;
			*(Object::Color*)&params[12] = TextColor;
			*(Vector*)&params[16] = Placement;
			*(class Canvas**)&params[28] = DrawCanvas;
			*(float*)&params[32] = ScaleX;
			*(float*)&params[36] = ScaleY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[40];
		}
		void DrawSmallText(ScriptString* ShowText, bool bFriend, Vector Placement, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96333);
			byte params[32] = { NULL };
			*(ScriptString**)params = ShowText;
			*(bool*)&params[12] = bFriend;
			*(Vector*)&params[16] = Placement;
			*(class Canvas**)&params[28] = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawHealthBar(class MaterialInstanceConstant* HealthBarMIC, bool bFriend, Vector Placement, class Canvas* DrawCanvas, float PlacementX, float PlacementY, float Width, float Height)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96340);
			byte params[40] = { NULL };
			*(class MaterialInstanceConstant**)params = HealthBarMIC;
			*(bool*)&params[4] = bFriend;
			*(Vector*)&params[8] = Placement;
			*(class Canvas**)&params[20] = DrawCanvas;
			*(float*)&params[24] = PlacementX;
			*(float*)&params[28] = PlacementY;
			*(float*)&params[32] = Width;
			*(float*)&params[36] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96369);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRemainingFriendlyGeneratorRestoreTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96370);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetRemainingEnemyGeneratorRestoreTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96372);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void UpdateSkiEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96374);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdatePickupFlashEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96376);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulsePickupFlashEffect(float PulseAmount, float PulseSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96378);
			byte params[8] = { NULL };
			*(float*)params = PulseAmount;
			*(float*)&params[4] = PulseSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateInvulnerableEfect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96381);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShieldEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96385);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseShieldEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96389);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateJammerEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96390);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateFadeEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96393);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FumbleFlag(float Speed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96395);
			byte params[4] = { NULL };
			*(float*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateFumbledFlagEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96397);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Whiteout(float Speed, float Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96398);
			byte params[8] = { NULL };
			*(float*)params = Speed;
			*(float*)&params[4] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearWhiteout()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96401);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateWhiteoutEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96402);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, ScriptString* CriticalString, int Switch, float Position, float Lifetime, int FontSize, Object::Color DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96403);
			byte params[48] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			*(ScriptString**)&params[12] = CriticalString;
			*(int*)&params[24] = Switch;
			*(float*)&params[28] = Position;
			*(float*)&params[32] = Lifetime;
			*(int*)&params[36] = FontSize;
			*(Object::Color*)&params[40] = DrawColor;
			*(class Object**)&params[44] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96421);
			byte params[28] = { NULL };
			*(int*)params = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripTag(ScriptString* sValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96436);
			byte params[24] = { NULL };
			*(ScriptString**)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SendLocalMessageToGlobalAlert(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96440);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendLocalMessageToChat(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96442);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerClassObjects(ScriptString* ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96446);
			byte params[20] = { NULL };
			*(ScriptString**)params = ClassName;
			*(int*)&params[12] = PerkIcon1;
			*(int*)&params[16] = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideGlobalAlert()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96450);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickVoteMessage(bool bComplete, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96451);
			byte params[16] = { NULL };
			*(bool*)params = bComplete;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableGameTypeHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96455);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96457);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorPlayerPanel(class TrPawn* ViewTargetTrPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96458);
			byte params[4] = { NULL };
			*(class TrPawn**)params = ViewTargetTrPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96466);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96467);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorVehiclePanel(class TrVehicle* ViewTargetVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96468);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = ViewTargetVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorBookmark()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96474);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorBookmark()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96475);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorBookmarkPanel(class TrCamera_SpectatorBookmark* BookMark)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96476);
			byte params[4] = { NULL };
			*(class TrCamera_SpectatorBookmark**)params = BookMark;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorObjectivePanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96478);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorObjectivePanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96479);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorObjectivePanel(class Actor* ObjectiveActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96480);
			byte params[4] = { NULL };
			*(class Actor**)params = ObjectiveActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96484);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96485);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96486);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideAllSpectatorPanels()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96487);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewTargetChange(class Actor* NewViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96488);
			byte params[4] = { NULL };
			*(class Actor**)params = NewViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestNumber(int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96490);
			byte params[4] = { NULL };
			*(int*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddOverheadNumber(int Value, Object::Vector4 WorldLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96492);
			byte params[20] = { NULL };
			*(int*)params = Value;
			*(Object::Vector4*)&params[16] = WorldLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateOverheadNumbers(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96496);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96505);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* DrawCanvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96507);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = DrawCanvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAward(class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96512);
			byte params[4] = { NULL };
			*(class Canvas**)params = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QueueAccolade(int Icon, ScriptString* Title, ScriptString* Subtitle, bool bIsBadge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96519);
			byte params[32] = { NULL };
			*(int*)params = Icon;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Subtitle;
			*(bool*)&params[28] = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckQueuedAccolades()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96525);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RunQueuedAccoladesTimer(bool bIsBadge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96526);
			byte params[4] = { NULL };
			*(bool*)params = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueuedAccoladesTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96529);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeployableReplicated(class TrDeployable* NewDep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96530);
			byte params[4] = { NULL };
			*(class TrDeployable**)params = NewDep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MineReplicated(class TrProj_Mine* NewMine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96532);
			byte params[4] = { NULL };
			*(class TrProj_Mine**)params = NewMine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateOwnedItems()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(96535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
