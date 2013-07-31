#pragma once
#include "TribesGame.TrStreamManager.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "TribesGame.TrBrowserManager.h"
#include "PlatformCommon.TgPlayerProfile.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrPageManager.h"
#include "Engine.OnlineSubsystem.h"
#include "TribesGame.TrStrings.h"
#include "TribesGame.TrUser.h"
#include "TribesGame.TrInventoryHelper.h"
#include "TribesGame.TrEquipInterface.h"
#include "TribesGame.TrLoginManager.h"
#include "TribesGame.TrQueueManager.h"
#include "TribesGame.TrPartyManager.h"
#include "TribesGame.TrLoadingData.h"
#include "TribesGame.TrSettingsManager.h"
#include "TribesGame.TrRibbonManager.h"
#include "TribesGame.TrFriendManager.h"
#include "TribesGame.GFxTrScene_EULA.h"
#include "TribesGame.GFxTrScene_MatchSummary.h"
#include "TribesGame.GFxTrScene_PlayerSummary.h"
#include "TribesGame.GFxTrMenuSounds.h"
#include "Core.Object.h"
#include "TribesGame.TrHUD.h"
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
	class GFxTrMenuMoviePlayer : public GFxMoviePlayer
	{
	public:
		static const auto ITEM_VOICE_T2BDERM03 = 8726;
		static const auto ITEM_VOICE_T2BDERM02 = 8725;
		static const auto ITEM_VOICE_T2BDERM01 = 8724;
		static const auto ITEM_VOICE_T2MALE05 = 8723;
		static const auto ITEM_VOICE_T2MALE04 = 8722;
		static const auto ITEM_VOICE_T2MALE03 = 8721;
		static const auto ITEM_VOICE_T2MALE02 = 8720;
		static const auto ITEM_VOICE_T2MALE01 = 8719;
		static const auto ITEM_VOICE_T2FEM05 = 8717;
		static const auto ITEM_VOICE_T2FEM04 = 8716;
		static const auto ITEM_VOICE_T2FEM03 = 8715;
		static const auto ITEM_VOICE_T2FEM02 = 8714;
		static const auto ITEM_VOICE_T2FEM01 = 8712;
		static const auto ITEM_VOICE_AUS = 8695;
		static const auto ITEM_VOICE_FEM2 = 8671;
		static const auto ITEM_VOICE_FEM1 = 8670;
		static const auto ITEM_VOICE_DARK = 8669;
		static const auto ITEM_VOICE_HEAVY = 8668;
		static const auto ITEM_VOICE_MEDIUM = 8667;
		static const auto ITEM_VOICE_LIGHT = 8666;
		static const auto BUNDLE_LOOT_ID_SENTINEL = 9510;
		static const auto BUNDLE_LOOT_ID_SPECIALIST = 9496;
		static const auto BUNDLE_LOOT_ID_SKINPACK = 9457;
		static const auto BUNDLE_LOOT_ID_TWINFUSOR = 9449;
		static const auto BUNDLE_LOOT_ID_STAYINALIVE = 9035;
		static const auto BUNDLE_LOOT_ID_SHAZBUNDLE = 9213;
		static const auto BUNDLE_LOOT_ID_NEWPLAYER = 9214;
		static const auto BUNDLE_LOOT_ID_RAP_WEAPONS = 8984;
		static const auto BUNDLE_LOOT_ID_RAP_PREMIUM = 8981;
		static const auto BUNDLE_LOOT_ID_RAP_MERCENARY = 8983;
		static const auto BUNDLE_LOOT_ID_RAP_GRIEVER = 8982;
		static const auto BUNDLE_LOOT_ID_CAD_WEAPONS = 8920;
		static const auto BUNDLE_LOOT_ID_CAD_PREMIUM = 8912;
		static const auto BUNDLE_LOOT_ID_CAD_MERCENARY = 8919;
		static const auto BUNDLE_LOOT_ID_CAD_ASSASSIN = 8918;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_HEAVYTWINFUSOR = 263;
		static const auto ACTIVITY_SOLDIER_PRIMARY_TWINFUSOR = 262;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTTWINFUSOR = 261;
		static const auto ACTIVITY_PERK_ULTRA_CAPACITOR = 260;
		static const auto ACTIVITY_PERK_SURVIVALIST = 259;
		static const auto ACTIVITY_PERK_SUPER_HEAVY = 258;
		static const auto ACTIVITY_PERK_SONIC_PUNCH = 257;
		static const auto ACTIVITY_PERK_QUICKDRAW = 256;
		static const auto ACTIVITY_PERK_POTENTIAL_ENERGY = 255;
		static const auto ACTIVITY_PERK_PILOT = 254;
		static const auto ACTIVITY_PERK_MECHANIC = 253;
		static const auto ACTIVITY_PERK_EGOCENTRIC = 250;
		static const auto ACTIVITY_PERK_DETERMINATION = 249;
		static const auto ACTIVITY_PERK_WHEEL_DEAL = 248;
		static const auto ACTIVITY_PERK_SUPER_CAPACITOR = 247;
		static const auto ACTIVITY_PERK_STEALTHY = 246;
		static const auto ACTIVITY_PERK_SAFETY_THIRD = 245;
		static const auto ACTIVITY_PERK_SAFE_FALL = 244;
		static const auto ACTIVITY_PERK_REACH = 243;
		static const auto ACTIVITY_PERK_RAGE = 242;
		static const auto ACTIVITY_PERK_LOOTER = 241;
		static const auto ACTIVITY_PERK_CLOSE_COMBAT = 240;
		static const auto ACTIVITY_PERK_BOUNTY_HUNTER = 239;
		static const auto ACTIVITY_TECHNICIAN_PACK_LIGHTTURRET = 238;
		static const auto ACTIVITY_TECHNICIAN_PACK_EXRTURRET = 237;
		static const auto ACTIVITY_SOLDIER_PACK_UTILITY = 236;
		static const auto ACTIVITY_SOLDIER_PACK_ENERGYPOOL = 235;
		static const auto ACTIVITY_SENTINEL_PACK_ENERGYRECHARGE = 234;
		static const auto ACTIVITY_SENTINEL_PACK_DROPJAMMER = 233;
		static const auto ACTIVITY_RAIDER_PACK_SHIELD = 232;
		static const auto ACTIVITY_RAIDER_PACK_JAMMER = 231;
		static const auto ACTIVITY_PATHFINDER_PACK_JUMPPACK = 230;
		static const auto ACTIVITY_PATHFINDER_PACK_ENERGYRECHARGE = 229;
		static const auto ACTIVITY_JUGGERNAUT_PACK_HEALTHREGEN = 228;
		static const auto ACTIVITY_INFILTRATOR_PACK_STEALTH = 227;
		static const auto ACTIVITY_DOOMBRINGER_PACK_FORCEFIELD = 226;
		static const auto ACTIVITY_BRUTE_PACK_SURVIVALPACK = 225;
		static const auto ACTIVITY_BRUTE_PACK_MINORENERGY = 224;
		static const auto ACTIVITY_BRUTE_PACK_HEAVYSHIELD = 223;
		static const auto ACTIVITY_TECHNICIAN_BELT_TCNG_MKD = 222;
		static const auto ACTIVITY_TECHNICIAN_BELT_TCNG = 221;
		static const auto ACTIVITY_TECHNICIAN_BELT_MOTIONALARM = 220;
		static const auto ACTIVITY_SOLDIER_BELT_PROXIMITYGRENADE = 219;
		static const auto ACTIVITY_SOLDIER_BELT_FRAGGRENADEXL_MKD = 218;
		static const auto ACTIVITY_SOLDIER_BELT_FRAGGRENADEXL = 217;
		static const auto ACTIVITY_SOLDIER_BELT_APGRENADE = 216;
		static const auto ACTIVITY_SENTINEL_BELT_GRENADET5 = 215;
		static const auto ACTIVITY_SENTINEL_BELT_CLAYMORE_MKD = 214;
		static const auto ACTIVITY_SENTINEL_BELT_CLAYMORE = 213;
		static const auto ACTIVITY_SENTINEL_BELT_ARMOREDCLAYMORE = 212;
		static const auto ACTIVITY_RAIDER_BELT_WHITEOUT = 211;
		static const auto ACTIVITY_RAIDER_BELT_MIRVGRENADE = 210;
		static const auto ACTIVITY_RAIDER_BELT_EMPGRENADE_MKD = 209;
		static const auto ACTIVITY_RAIDER_BELT_EMPGRENADE = 208;
		static const auto ACTIVITY_PATHFINDER_BELT_STGRENADE = 207;
		static const auto ACTIVITY_PATHFINDER_BELT_IMPACTNITRON_MKD = 206;
		static const auto ACTIVITY_PATHFINDER_BELT_IMPACTNITRON = 205;
		static const auto ACTIVITY_JUGGERNAUT_BELT_HEAVYAPGRENADE_MKD = 204;
		static const auto ACTIVITY_JUGGERNAUT_BELT_HEAVYAPGRENADE = 203;
		static const auto ACTIVITY_JUGGERNAUT_BELT_DISKTOSS = 202;
		static const auto ACTIVITY_INFILTRATOR_BELT_STICKYGRENADE_MKD = 201;
		static const auto ACTIVITY_INFILTRATOR_BELT_STICKYGRENADE = 200;
		static const auto ACTIVITY_INFILTRATOR_BELT_PRISMMINES = 199;
		static const auto ACTIVITY_INFILTRATOR_BELT_NINJASMOKE = 198;
		static const auto ACTIVITY_DOOMBRINGER_BELT_STANDARDGRENADE_MKD = 197;
		static const auto ACTIVITY_DOOMBRINGER_BELT_STANDARDGRENADE = 196;
		static const auto ACTIVITY_DOOMBRINGER_BELT_MINE = 195;
		static const auto ACTIVITY_BRUTE_BELT_LIGHTSTICKYGRENADE = 194;
		static const auto ACTIVITY_BRUTE_BELT_FRACTALGRENADE_MKD = 193;
		static const auto ACTIVITY_BRUTE_BELT_FRACTALGRENADE = 192;
		static const auto ACTIVITY_ARMOR_MOD_SOLDIER_1 = 191;
		static const auto ACTIVITY_ARMOR_MOD_TECHNICIAN_1 = 190;
		static const auto ACTIVITY_ARMOR_MOD_SENTINEL_1 = 189;
		static const auto ACTIVITY_ARMOR_MOD_RAIDER_1 = 188;
		static const auto ACTIVITY_ARMOR_MOD_PATHFINDER_1 = 187;
		static const auto ACTIVITY_ARMOR_MOD_JUGGERNAUT_1 = 186;
		static const auto ACTIVITY_ARMOR_MOD_INFILTRATOR_1 = 185;
		static const auto ACTIVITY_ARMOR_MOD_DOOMBRINGER_1 = 184;
		static const auto ACTIVITY_ARMOR_MOD_BRUTE_1 = 183;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_SPARROW = 182;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_SAWEDOFF = 181;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_REPAIRTOOLSD_MKD = 180;
		static const auto ACTIVITY_TECHNICIAN_SECONDARY_REPAIRTOOLSD = 179;
		static const auto ACTIVITY_SOLDIER_SECONDARY_THUMPERD_MKD = 178;
		static const auto ACTIVITY_SOLDIER_SECONDARY_THUMPERD = 177;
		static const auto ACTIVITY_SOLDIER_SECONDARY_EAGLE = 176;
		static const auto ACTIVITY_SENTINEL_SECONDARY_NOVABLASTER_MKD = 175;
		static const auto ACTIVITY_SENTINEL_SECONDARY_NOVABLASTER = 174;
		static const auto ACTIVITY_SENTINEL_SECONDARY_FALCON = 173;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ5SMG = 172;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ4SMG_MKD = 171;
		static const auto ACTIVITY_RAIDER_SECONDARY_NJ4SMG = 170;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_SHOTGUN_MKD = 169;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_SHOTGUN = 168;
		static const auto ACTIVITY_PATHFINDER_SECONDARY_LIGHTASSAULTRIFLE = 167;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_X1LMG = 166;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_SPINFUSORD_MKD = 165;
		static const auto ACTIVITY_JUGGERNAUT_SECONDARY_SPINFUSORD = 164;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_THROWINGKNIVES = 163;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_SN7_MKD = 162;
		static const auto ACTIVITY_INFILTRATOR_SECONDARY_SN7 = 161;
		static const auto ACTIVITY_DOOMBRINGER_SECONDARY_SABERLAUNCHER_MKD = 160;
		static const auto ACTIVITY_DOOMBRINGER_SECONDARY_SABERLAUNCHER = 159;
		static const auto ACTIVITY_BRUTE_SECONDARY_PLASMACANNON = 158;
		static const auto ACTIVITY_BRUTE_SECONDARY_NOVACOLT = 157;
		static const auto ACTIVITY_BRUTE_SECONDARY_AUTOSHOTGUN_MKD = 156;
		static const auto ACTIVITY_BRUTE_SECONDARY_AUTOSHOTGUN = 155;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_THUMPER = 154;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TCN4_MKD = 153;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TCN4 = 152;
		static const auto ACTIVITY_SOLDIER_PRIMARY_SPINFUSOR = 151;
		static const auto ACTIVITY_SOLDIER_PRIMARY_ASSAULTRIFLE_MKD = 150;
		static const auto ACTIVITY_SOLDIER_PRIMARY_ASSAULTRIFLE = 149;
		static const auto ACTIVITY_SENTINEL_PRIMARY_PHASERIFLE = 148;
		static const auto ACTIVITY_RAIDER_PRIMARY_PLASMAGUN = 147;
		static const auto ACTIVITY_RAIDER_PRIMARY_GRENADELAUNCHER = 146;
		static const auto ACTIVITY_RAIDER_PRIMARY_ARXBUSTER_MKD = 145;
		static const auto ACTIVITY_RAIDER_PRIMARY_ARXBUSTER = 144;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR_MKD = 143;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR = 142;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_BOLTLAUNCHER = 141;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_MIRVLAUNCHER = 140;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_FUSIONMORTAR_MKD = 139;
		static const auto ACTIVITY_JUGGERNAUT_PRIMARY_FUSIONMORTAR = 138;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_STEALTHLIGHTSPINFUSOR = 137;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_RHINOSMG_MKD = 136;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_RHINOSMG = 135;
		static const auto ACTIVITY_INFILTRATOR_PRIMARY_REMOTEARXBUSTER = 134;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_HEAVYBOLTLAUNCHER = 133;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_CHAINGUN_MKD = 132;
		static const auto ACTIVITY_DOOMBRINGER_PRIMARY_CHAINGUN = 131;
		static const auto ACTIVITY_BRUTE_PRIMARY_SPIKELAUNCHER = 129;
		static const auto ACTIVITY_BRUTE_PRIMARY_HEAVYSPINFUSOR_MKD = 128;
		static const auto ACTIVITY_BRUTE_PRIMARY_HEAVYSPINFUSOR = 127;
		static const auto ACTIVITY_SENTINEL_PRIMARY_SNIPERRIFLE_MKD = 126;
		static const auto ACTIVITY_SENTINEL_BELT_MINE_CLAYMORE_MKD = 125;
		static const auto ACTIVITY_SENTINEL_PRIMARY_BXT1 = 124;
		static const auto ACTIVITY_DEVICE_NONE = 0;
		static const auto BRT_LOADOUT_FIVE = 8691;
		static const auto BRT_LOADOUT_FOUR = 8690;
		static const auto BRT_LOADOUT_THREE = 8385;
		static const auto BRT_LOADOUT_TWO = 8384;
		static const auto BRT_LOADOUT_ONE = 8383;
		static const auto DMB_LOADOUT_FIVE = 8689;
		static const auto DMB_LOADOUT_FOUR = 8688;
		static const auto DMB_LOADOUT_THREE = 8382;
		static const auto DMB_LOADOUT_TWO = 8381;
		static const auto DMB_LOADOUT_ONE = 8380;
		static const auto JUG_LOADOUT_FIVE = 8687;
		static const auto JUG_LOADOUT_FOUR = 8686;
		static const auto JUG_LOADOUT_THREE = 8379;
		static const auto JUG_LOADOUT_TWO = 8378;
		static const auto JUG_LOADOUT_ONE = 8377;
		static const auto RDR_LOADOUT_FIVE = 8685;
		static const auto RDR_LOADOUT_FOUR = 8684;
		static const auto RDR_LOADOUT_THREE = 8376;
		static const auto RDR_LOADOUT_TWO = 8375;
		static const auto RDR_LOADOUT_ONE = 8374;
		static const auto TCN_LOADOUT_FIVE = 8683;
		static const auto TCN_LOADOUT_FOUR = 8682;
		static const auto TCN_LOADOUT_THREE = 8373;
		static const auto TCN_LOADOUT_TWO = 8372;
		static const auto TCN_LOADOUT_ONE = 8371;
		static const auto SLD_LOADOUT_FIVE = 8681;
		static const auto SLD_LOADOUT_FOUR = 8680;
		static const auto SLD_LOADOUT_THREE = 8370;
		static const auto SLD_LOADOUT_TWO = 8369;
		static const auto SLD_LOADOUT_ONE = 8368;
		static const auto SEN_LOADOUT_FIVE = 8679;
		static const auto SEN_LOADOUT_FOUR = 8678;
		static const auto SEN_LOADOUT_THREE = 8367;
		static const auto SEN_LOADOUT_TWO = 8366;
		static const auto SEN_LOADOUT_ONE = 8365;
		static const auto INF_LOADOUT_FIVE = 8677;
		static const auto INF_LOADOUT_FOUR = 8676;
		static const auto INF_LOADOUT_THREE = 8364;
		static const auto INF_LOADOUT_TWO = 8363;
		static const auto INF_LOADOUT_ONE = 8362;
		static const auto PTH_LOADOUT_FIVE = 8675;
		static const auto PTH_LOADOUT_FOUR = 8674;
		static const auto PTH_LOADOUT_THREE = 8361;
		static const auto PTH_LOADOUT_TWO = 8360;
		static const auto PTH_LOADOUT_ONE = 8359;
		static const auto SERVER_DEFAULT_MAP_BTZ = 1539;
		static const auto SERVER_DEFAULT_MAP_CAH = 1519;
		static const auto SERVER_DEFAULT_MAP_ARN = 1495;
		static const auto SERVER_DEFAULT_MAP_TDM = 1488;
		static const auto SERVER_DEFAULT_MAP_RAB = 1465;
		static const auto SERVER_DEFAULT_MAP_CTF = 1462;
		static const auto SERVER_GAMECLASSID_BTZ = 8118;
		static const auto SERVER_GAMECLASSID_CAH = 8094;
		static const auto SERVER_GAMECLASSID_ARN = 8086;
		static const auto SERVER_GAMECLASSID_TDM = 8036;
		static const auto SERVER_GAMECLASSID_RAB = 8012;
		static const auto SERVER_GAMECLASSID_CTF = 197;
		static const auto TR_MAX_GAMETYPES = 5;
		static const auto SERVER_RT_METHOD_LINEAR4 = 10073;
		static const auto SERVER_RT_METHOD_LINEAR2 = 10072;
		static const auto SERVER_RT_METHOD_LINEAR = 10071;
		static const auto SERVER_RT_METHOD_RANDOM = 10070;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGHEAVY = 1396;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGMEDIUM = 1395;
		static const auto GAME_CONFIG_DECELERATIONRATEWITHFLAG = 1392;
		static const auto GAME_CONFIG_MAXSPEEDWITHFLAGLIGHT = 1391;
		static const auto GAME_CONFIG_CTFBLITZALLFLAGSMOVE = 1377;
		static const auto GAME_CONFIG_AOEDAMAGEMULTIPLIER = 1376;
		static const auto GAME_CONFIG_AOESIZEMULTIPLIER = 1375;
		static const auto GAME_CONFIG_ENERGYMULTIPLIER = 1374;
		static const auto GAME_CONFIG_SKIENABLED = 1373;
		static const auto GAME_CONFIG_VEHICLEHEALTHMULT = 1327;
		static const auto GAME_CONFIG_TEAMCREDITS = 1299;
		static const auto GAME_CONFIG_POWEREDCALLINS = 1298;
		static const auto GAME_CONFIG_CLASSCOUNT_BRT = 1295;
		static const auto GAME_CONFIG_CLASSCOUNT_DMB = 1294;
		static const auto GAME_CONFIG_CLASSCOUNT_JUG = 1293;
		static const auto GAME_CONFIG_CLASSCOUNT_RDR = 1292;
		static const auto GAME_CONFIG_CLASSCOUNT_TCN = 1291;
		static const auto GAME_CONFIG_CLASSCOUNT_SLD = 1290;
		static const auto GAME_CONFIG_CLASSCOUNT_INF = 1288;
		static const auto GAME_CONFIG_CLASSCOUNT_SEN = 1289;
		static const auto GAME_CONFIG_CLASSCOUNT_PTH = 1287;
		static const auto GAME_CONFIG_SUPPLYDROPAMMOONLY = 1286;
		static const auto GAME_CONFIG_FFKILLLIMIT = 1285;
		static const auto GAME_CONFIG_FFDMGLIMIT = 1284;
		static const auto GAME_CONFIG_FFBASEASSETS = 1283;
		static const auto GAME_CONFIG_FFDEPLOYABLES = 1282;
		static const auto GAME_CONFIG_INVDESTROYABLE = 1281;
		static const auto GAME_CONFIG_GENDESTROYABLE = 1280;
		static const auto GAME_CONFIG_GAMETYPE = 1244;
		static const auto GAME_CONFIG_SCORELIMIT_CAH = 1279;
		static const auto GAME_CONFIG_SCORELIMIT_ARN = 1277;
		static const auto GAME_CONFIG_SCORELIMIT_TDM = 1276;
		static const auto GAME_CONFIG_SCORELIMIT_RAB = 1278;
		static const auto GAME_CONFIG_SCORELIMIT_CTF = 1061;
		static const auto GAME_CONFIG_ARENAROUNDS = 1265;
		static const auto GAME_CONFIG_CONFIGCASEID = 1254;
		static const auto GAME_CONFIG_TEAMDISPARITY = 1252;
		static const auto GAME_CONFIG_WARMUPTIME = 1248;
		static const auto GAME_CONFIG_BASEDESTLIMIT = 1241;
		static const auto GAME_CONFIG_CALLINBLDUPORB = 1251;
		static const auto GAME_CONFIG_CALLINBLDUPSUP = 1250;
		static const auto GAME_CONFIG_CALLINBLDUPTAC = 1249;
		static const auto GAME_CONFIG_CALLINCLDWNORB = 1239;
		static const auto GAME_CONFIG_CALLINCLDWNSUP = 1238;
		static const auto GAME_CONFIG_CALLINCLDWNTAC = 1237;
		static const auto GAME_CONFIG_CALLINPRICEORB = 1236;
		static const auto GAME_CONFIG_CALLINPRICESUP = 1235;
		static const auto GAME_CONFIG_CALLINPRICETAC = 1234;
		static const auto GAME_CONFIG_CALLINSDENIED = 1233;
		static const auto GAME_CONFIG_FFMULTIPLIER = 1123;
		static const auto GAME_CONFIG_TEAMJOINTYPE = 1081;
		static const auto GAME_CONFIG_VSHRIKEPRICE = 1080;
		static const auto GAME_CONFIG_VGRAVPRICE = 1077;
		static const auto GAME_CONFIG_VBEOWULFPRICE = 1076;
		static const auto GAME_CONFIG_VSHRIKELIMIT = 1270;
		static const auto GAME_CONFIG_VBEOWULFLIMIT = 1269;
		static const auto GAME_CONFIG_VGRAVCYCLELIMIT = 1268;
		static const auto GAME_CONFIG_VEHICLELIMITS = 1075;
		static const auto GAME_CONFIG_POWERDEPLOYS = 1072;
		static const auto GAME_CONFIG_BASEASSETS = 1070;
		static const auto GAME_CONFIG_SPAWNNAKED = 1068;
		static const auto GAME_CONFIG_UPGRADES = 1067;
		static const auto GAME_CONFIG_GENAUTOREGEN = 1066;
		static const auto GAME_CONFIG_FRIENDLYFIRE = 1065;
		static const auto GAME_CONFIG_RESPAWNTIME = 1064;
		static const auto GAME_CONFIG_OVERTIMELIMIT = 1063;
		static const auto GAME_CONFIG_AUTOBALANCE = 1062;
		static const auto GAME_CONFIG_MAXPLAYERS = 1060;
		static const auto GAME_CONFIG_TIMELIMIT = 1059;
		static const auto QUEUE_CONFIG_MAXLEVEL = 1297;
		static const auto QUEUE_CONFIG_MINLEVEL = 1296;
		static const auto QUEUE_CONFIG_SITEID = 1272;
		static const auto QUEUE_CONFIG_MAPSLOT8 = 1264;
		static const auto QUEUE_CONFIG_MAPSLOT7 = 1263;
		static const auto QUEUE_CONFIG_MAPSLOT6 = 1262;
		static const auto QUEUE_CONFIG_MAPSLOT5 = 1261;
		static const auto QUEUE_CONFIG_MAPSLOT4 = 1260;
		static const auto QUEUE_CONFIG_MAPSLOT3 = 1259;
		static const auto QUEUE_CONFIG_MAPSLOT2 = 1258;
		static const auto QUEUE_CONFIG_MAPSLOT1 = 1257;
		static const auto QUEUE_CONFIG_MAPROTATIONTYPE = 1256;
		static const auto QUEUE_CONFIG_SERVERDESCRIPTION = 1255;
		static const auto QUEUE_CONFIG_MATCHQUEUEID = 1253;
		static const auto QUEUE_CONFIG_SLOTS = 1247;
		static const auto QUEUE_CONFIG_GENPASSWORD = 1246;
		static const auto QUEUE_CONFIG_ADMINPASSWORD = 1245;
		static const auto QUEUE_CONFIG_SERVERNAME = 1243;
		static const auto SKIN_TECHNICIAN_MC = 29;
		static const auto SKIN_BRUTE_MC = 28;
		static const auto SKIN_SENTINEL_MC = 27;
		static const auto SKIN_RAIDER_MC = 26;
		static const auto SKIN_RAIDER_GV = 25;
		static const auto SKIN_INFILTRATOR_MC = 26;
		static const auto SKIN_INFILTRATOR_AS = 25;
		static const auto SKIN_PATHFINDER_MC = 24;
		static const auto SKIN_PATHFINDER_DS = 23;
		static const auto SKIN_PATHFINDER_BE = 22;
		static const auto SKIN_SOLDIER_DS = 21;
		static const auto SKIN_SOLDIER_BE = 20;
		static const auto SKIN_BRUTE_DS = 19;
		static const auto SKIN_BRUTE_BE = 18;
		static const auto SKIN_JUGGERNAUT_DS = 17;
		static const auto SKIN_JUGGERNAUT_BE = 16;
		static const auto SKIN_DOOMBRINGER_DS = 15;
		static const auto SKIN_DOOMBRINGER_BE = 14;
		static const auto SKIN_TECHNICIAN_DS = 13;
		static const auto SKIN_TECHNICIAN_BE = 12;
		static const auto SKIN_RAIDER_DS = 11;
		static const auto SKIN_RAIDER_BE = 10;
		static const auto SKIN_SENTINEL_DS = 9;
		static const auto SKIN_SENTINEL_BE = 8;
		static const auto SKIN_INFILTRATOR_DS = 7;
		static const auto SKIN_INFILTRATOR_BE = 6;
		static const auto SHOP_VENDOR_CLANTAG = 545;
		static const auto SHOP_VENDOR_NAMECHANGE = 512;
		static const auto SHOP_VENDOR_BOOSTERS = 508;
		static const auto SHOP_VENDOR_BUNDLES = 518;
		static const auto SHOP_VENDOR_GOLD = 507;
		static const auto ITEM_UPGRADE_TEMP = 99999;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_3 = 8235;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_2 = 8234;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_1 = 8233;
		static const auto ITEM_PERK_UPGRADE_RAGE_3 = 8238;
		static const auto ITEM_PERK_UPGRADE_RAGE_2 = 8237;
		static const auto ITEM_PERK_UPGRADE_RAGE_1 = 8236;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_3 = 8184;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_2 = 8183;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_1 = 8182;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_3 = 8205;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_2 = 8204;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_1 = 8203;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_3 = 8193;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_2 = 8192;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_1 = 8191;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_3 = 8199;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_2 = 8198;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_1 = 8197;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_3 = 8208;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_2 = 8207;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_1 = 8206;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_3 = 8214;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_2 = 8213;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_1 = 8212;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_3 = 8178;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_2 = 8177;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_1 = 8176;
		static const auto ITEM_PERK_UPGRADE_REACH_3 = 8172;
		static const auto ITEM_PERK_UPGRADE_REACH_2 = 8171;
		static const auto ITEM_PERK_UPGRADE_REACH_1 = 8152;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_3 = 8211;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_2 = 8210;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_1 = 8209;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_3 = 8202;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_2 = 8201;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_1 = 8200;
		static const auto ITEM_PERK_UPGRADE_PILOT_3 = 8181;
		static const auto ITEM_PERK_UPGRADE_PILOT_2 = 8180;
		static const auto ITEM_PERK_UPGRADE_PILOT_1 = 8179;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_3 = 8217;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_2 = 8216;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_1 = 8215;
		static const auto ITEM_PERK_UPGRADE_LOOTER_3 = 8187;
		static const auto ITEM_PERK_UPGRADE_LOOTER_2 = 8186;
		static const auto ITEM_PERK_UPGRADE_LOOTER_1 = 8185;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_3 = 8175;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_2 = 8174;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_1 = 8173;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_3 = 8196;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_2 = 8195;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_1 = 8194;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_3 = 8190;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_2 = 8189;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_1 = 8188;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_5 = 8151;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_4 = 8150;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_3 = 8149;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_2 = 8148;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_1 = 8147;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_5 = 8123;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_4 = 8122;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_3 = 8121;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_2 = 8120;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_1 = 8119;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_5 = 8099;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_4 = 8098;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_3 = 8097;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_2 = 8096;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_1 = 8095;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_5 = 8069;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_4 = 8068;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_3 = 8067;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_2 = 8066;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_1 = 8065;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_5 = 8041;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_4 = 8040;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_3 = 8039;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_2 = 8038;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_1 = 8037;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_5 = 8011;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_4 = 8010;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_3 = 8009;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_2 = 8008;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_1 = 8007;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_5 = 7984;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_4 = 7983;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_3 = 7982;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_2 = 7981;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_1 = 7980;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_5 = 7959;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_4 = 7958;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_3 = 7957;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_2 = 7956;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_1 = 7955;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_5 = 7897;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_4 = 7896;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_3 = 7895;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_2 = 7894;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_1 = 7893;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_3 = 8146;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_2 = 8145;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_1 = 8144;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_3 = 8143;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_2 = 8142;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_1 = 8141;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_3 = 8118;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_2 = 8117;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_1 = 8116;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_3 = 8311;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_2 = 8310;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_1 = 8309;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_3 = 8094;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_2 = 8093;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_1 = 8092;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_3 = 8091;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_2 = 8090;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_1 = 8089;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_4 = 8064;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_3 = 8063;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_2 = 8062;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_1 = 8061;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_3 = 8060;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_2 = 8059;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_1 = 8058;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_3 = 8270;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_2 = 8269;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_1 = 8268;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_3 = 8036;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_2 = 8035;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_1 = 8034;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_3 = 8226;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_2 = 8225;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_1 = 8224;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_3 = 8006;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_2 = 8005;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_1 = 8004;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_3 = 8273;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_2 = 8272;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_1 = 8271;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_3 = 7979;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_2 = 7978;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_1 = 7977;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_3 = 7954;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_2 = 7953;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_1 = 7952;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_3 = 7951;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_2 = 7950;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_1 = 7949;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_3 = 7878;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_2 = 7877;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_1 = 7876;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_3 = 7873;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_2 = 7872;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_1 = 7871;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_3 = 8140;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_2 = 8139;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_1 = 8138;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_3 = 8137;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_2 = 8136;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_1 = 8135;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_3 = 8115;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_2 = 8114;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_1 = 8113;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_3 = 8112;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_2 = 8111;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_1 = 8110;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_3 = 8088;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_2 = 8087;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_1 = 8086;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_3 = 8085;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_2 = 8084;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_1 = 8083;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_3 = 8285;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_2 = 8284;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_1 = 8283;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_3 = 8057;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_2 = 8056;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_1 = 8055;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_3 = 8054;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_2 = 8053;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_1 = 8052;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_3 = 8033;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_2 = 8032;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_1 = 8031;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_3 = 8030;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_2 = 8029;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_1 = 8028;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_3 = 8229;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_2 = 8228;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_1 = 8227;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_3 = 8003;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_2 = 8002;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_1 = 8001;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_3 = 8000;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_2 = 7999;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_1 = 7998;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_3 = 8288;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_2 = 8287;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_1 = 8286;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_3 = 7976;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_2 = 7975;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_1 = 7974;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_4 = 7973;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_3 = 7972;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_2 = 7971;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_1 = 7970;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_3 = 8264;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_2 = 8263;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_1 = 8262;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_3 = 7948;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_2 = 7947;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_1 = 7946;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_3 = 7945;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_2 = 7944;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_1 = 7943;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_3 = 8276;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_2 = 8275;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_1 = 8274;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_3 = 7890;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_2 = 7889;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_1 = 7888;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_3 = 7883;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_2 = 7882;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_1 = 7881;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_4 = 8134;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_3 = 8133;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_2 = 8132;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_1 = 8131;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_4 = 8130;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_3 = 8129;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_2 = 8128;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_1 = 8127;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_3 = 8303;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_2 = 8302;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_1 = 8301;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_3 = 8109;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_2 = 8108;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_1 = 8107;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_4 = 8082;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_3 = 8081;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_2 = 8080;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_1 = 8079;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_3 = 8078;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_2 = 8077;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_1 = 8076;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_4 = 8304;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_3 = 8291;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_2 = 8290;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_1 = 8289;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_4 = 8051;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_3 = 8050;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_2 = 8049;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_1 = 8048;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_3 = 8027;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_2 = 8026;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_1 = 8025;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_3 = 8024;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_2 = 8023;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_1 = 8022;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_3 = 8021;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_2 = 8020;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_1 = 8019;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_3 = 8297;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_2 = 8296;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_1 = 8295;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_3 = 7991;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_2 = 7990;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_1 = 7989;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_3 = 7997;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_2 = 7996;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_1 = 7995;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_4 = 8315;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_3 = 8314;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_2 = 8313;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_1 = 8312;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_3 = 7969;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_2 = 7968;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_1 = 7967;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_4 = 8261;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_3 = 8260;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_2 = 8259;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_1 = 8258;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_4 = 7942;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_3 = 7941;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_2 = 7940;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_1 = 7939;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_3 = 7938;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_2 = 7937;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_1 = 7936;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_3 = 8267;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_2 = 8266;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_1 = 8265;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_4 = 7869;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_3 = 7868;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_2 = 7867;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_1 = 7866;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_3 = 7863;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_2 = 7862;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_1 = 7861;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_3 = 8388;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_2 = 8387;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_1 = 8386;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_3 = 8294;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_2 = 8293;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_1 = 8292;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_3 = 8126;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_2 = 8125;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_1 = 8124;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_3 = 8106;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_2 = 8105;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_1 = 8104;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_4 = 8103;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_3 = 8102;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_2 = 8101;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_1 = 8100;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_3 = 8282;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_2 = 8281;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_1 = 8280;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_3 = 8075;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_2 = 8074;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_1 = 8073;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_3 = 8072;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_2 = 8071;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_1 = 8070;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_3 = 8044;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_2 = 8043;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_1 = 8042;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_3 = 8047;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_2 = 8046;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_1 = 8045;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_3 = 8018;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_2 = 8017;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_1 = 8016;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_4 = 8015;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_3 = 8014;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_2 = 8013;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_1 = 8012;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_3 = 8318;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_2 = 8317;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_1 = 8316;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_3 = 7994;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_2 = 7993;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_1 = 7992;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_4 = 7988;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_3 = 7987;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_2 = 7986;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_1 = 7985;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_3 = 8300;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_2 = 8299;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_1 = 8298;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_3 = 7966;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_2 = 7965;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_1 = 7964;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_4 = 7963;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_3 = 7962;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_2 = 7961;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_1 = 7960;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_4 = 8308;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_3 = 8307;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_2 = 8306;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_1 = 8305;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_4 = 7935;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_3 = 7934;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_2 = 7933;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_1 = 7932;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_4 = 7931;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_3 = 7930;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_2 = 7929;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_1 = 7927;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_3 = 8279;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_2 = 8278;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_1 = 8277;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_3 = 7857;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_2 = 7860;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_1 = 7855;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_3 = 7852;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_2 = 7851;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_1 = 7850;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_3 = 8507;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_2 = 8506;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_1 = 8505;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_3 = 8504;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_2 = 8503;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_1 = 8502;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_3 = 8501;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_2 = 8500;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_1 = 8499;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_3 = 8498;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_2 = 8497;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_1 = 8496;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_3 = 8495;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_2 = 8494;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_1 = 8493;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_3 = 8492;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_2 = 8491;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_1 = 8490;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_4 = 8489;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_3 = 8488;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_2 = 8487;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_1 = 8486;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_3 = 8484;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_2 = 8483;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_1 = 8482;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_3 = 8481;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_2 = 8480;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_1 = 8479;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_4 = 8478;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_3 = 8477;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_2 = 8476;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_1 = 8475;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_3 = 8474;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_2 = 8473;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_1 = 8472;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_3 = 8471;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_2 = 8470;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_1 = 8469;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_4 = 8468;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_3 = 8467;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_2 = 8466;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_1 = 8465;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_3 = 8464;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_2 = 8463;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_1 = 8462;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_3 = 8461;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_2 = 8460;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_1 = 8459;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_3 = 8458;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_2 = 8457;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_1 = 8456;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_3 = 8455;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_2 = 8454;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_1 = 8453;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_3 = 8452;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_2 = 8451;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_1 = 8450;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_3 = 8659;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_2 = 8658;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_1 = 8657;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_3 = 8449;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_2 = 8448;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_1 = 8447;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_4 = 8446;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_3 = 8445;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_2 = 8444;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_1 = 8443;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_3 = 8442;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_2 = 8441;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_1 = 8440;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_3 = 8439;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_2 = 8438;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_1 = 8437;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_4 = 8436;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_3 = 8435;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_2 = 8434;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_1 = 8433;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_4 = 8432;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_3 = 8431;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_2 = 8430;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_1 = 8429;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_4 = 8428;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_3 = 8427;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_2 = 8426;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_1 = 8425;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_4 = 8424;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_3 = 8423;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_2 = 8422;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_1 = 8421;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_3 = 8420;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_2 = 8419;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_1 = 8418;
		static const auto ACTIVITY_SENTINEL_SECONDARY_ACCURIZEDSHOTGUN = 269;
		static const auto ACTIVITY_SENTINEL_PRIMARY_SAP20 = 268;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TC24 = 267;
		static const auto ACTIVITY_SOLDIER_PRIMARY_SPINFUSOR_100X = 264;
		static const auto ACTIVITY_TECHNICIAN_BELT_REPAIR_DEPLOYABLE = 266;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR_100X = 265;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_3 = 8711;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_2 = 8710;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_1 = 8709;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_3 = 8708;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_2 = 8707;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_1 = 8706;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_3 = 8705;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_2 = 8704;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_1 = 8703;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_3 = 8702;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_2 = 8701;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_1 = 8700;
		static const auto WEAPON_ID_TC24 = 8699;
		static const auto WEAPON_ID_SPINFUSOR_100X = 8697;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT_100X = 8696;
		static const auto WEAPON_ID_REPAIR_DEPLOYABLE = 8698;
		static const auto WEAPON_ID_THUMPERD_MKD = 8417;
		static const auto WEAPON_ID_TCNG_MKD = 8416;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT_MKD = 8415;
		static const auto WEAPON_ID_SPINFUSOR_HEAVY_MKD = 8414;
		static const auto WEAPON_ID_SPINFUSOR_D_MKD = 8413;
		static const auto WEAPON_ID_SHOTGUN_AUTO_MKD = 8412;
		static const auto WEAPON_ID_SHOTGUN_MKD = 8411;
		static const auto WEAPON_ID_SMG_TCN4_MKD = 8410;
		static const auto WEAPON_ID_SMG_RHINO_MKD = 8409;
		static const auto WEAPON_ID_SMG_NJ4_MKD = 8408;
		static const auto WEAPON_ID_RIFLE_SNIPER_MKD = 8407;
		static const auto WEAPON_ID_RIFLE_ASSAULT_MKD = 8406;
		static const auto WEAPON_ID_REPAIR_TOOL_SD_MKD = 8405;
		static const auto WEAPON_ID_PISTOL_SN7_MKD = 8404;
		static const auto WEAPON_ID_PISTOL_NOVA_COLT_MKD = 8403;
		static const auto WEAPON_ID_MINE_CLAYMORE_MKD = 8402;
		static const auto WEAPON_ID_LAUNCHER_SABER_MKD = 8401;
		static const auto WEAPON_ID_LAUNCHER_MORTAR_MKD = 8400;
		static const auto WEAPON_ID_GRENADE_XL_MKD = 8399;
		static const auto WEAPON_ID_GRENADE_STICKY_MKD = 8398;
		static const auto WEAPON_ID_GRENADE_SPIKE_MKD = 8397;
		static const auto WEAPON_ID_GRENADE_NITRON_MKD = 8396;
		static const auto WEAPON_ID_GRENADE_EMP_MKD = 8395;
		static const auto WEAPON_ID_GRENADE_AP_HEAVY_MKD = 8394;
		static const auto WEAPON_ID_GRENADE_MKD = 8393;
		static const auto WEAPON_ID_CHAINGUN_MKD = 8392;
		static const auto WEAPON_ID_ARX_BUSTER_MKD = 8391;
		static const auto ITEM_ARMOR_MOD_BRUTE_1 = 7844;
		static const auto ITEM_ARMOR_MOD_DOOMBRINGER_1 = 7843;
		static const auto ITEM_ARMOR_MOD_JUGGERNAUT_1 = 7842;
		static const auto ITEM_ARMOR_MOD_RAIDER_1 = 7841;
		static const auto ITEM_ARMOR_MOD_TECHNICIAN_1 = 7840;
		static const auto ITEM_ARMOR_MOD_SOLDIER_1 = 7839;
		static const auto ITEM_ARMOR_MOD_INFILTRATOR_1 = 7838;
		static const auto ITEM_ARMOR_MOD_SENTINEL_1 = 7837;
		static const auto ITEM_ARMOR_MOD_PATHFINDER_1 = 7836;
		static const auto ITEM_VOICE_HEAVY_STANDARD = 7905;
		static const auto ITEM_VOICE_MEDIUM_STANDARD = 7904;
		static const auto ITEM_VOICE_LIGHT_STANDARD = 7903;
		static const auto ITEM_SKIN_BRUTE_MERC = 8663;
		static const auto ITEM_SKIN_BRUTE = 8333;
		static const auto ITEM_SKIN_DOOMBRINGER = 8332;
		static const auto ITEM_SKIN_JUGGERNAUT = 8331;
		static const auto ITEM_SKIN_RAIDER_MERC = 8352;
		static const auto ITEM_SKIN_RAIDER_GRIEVER = 8351;
		static const auto ITEM_SKIN_RAIDER = 8330;
		static const auto ITEM_SKIN_TECHNICIAN_MERC = 8731;
		static const auto ITEM_SKIN_TECHNICIAN = 8329;
		static const auto ITEM_SKIN_SOLDIER = 8328;
		static const auto ITEM_SKIN_SENTINEL_MERC = 8665;
		static const auto ITEM_SKIN_SENTINEL = 8327;
		static const auto ITEM_SKIN_INFILTRATOR_MERC = 8336;
		static const auto ITEM_SKIN_INFILTRATOR_ASSASSIN = 8337;
		static const auto ITEM_SKIN_INFILTRATOR = 7835;
		static const auto ITEM_SKIN_PATHFINDER_MERC = 8326;
		static const auto ITEM_SKIN_PATHFINDER = 7834;
		static const auto PROPERTY_CALLIN_SUPPORTINVENTORY = 10234;
		static const auto PROPERTY_CALLIN_TACTICALSTRIKE = 10201;
		static const auto PROPERTY_CALLIN_ORBITALSTRIKE = 10241;
		static const auto TR_MAX_CALLINS = 3;
		static const auto ITEM_SKILL_WRAITH_WEAPON_SWITCH = 7787;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_CLIP_II = 7786;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_CLIP_I = 7785;
		static const auto ITEM_SKILL_WRAITH_SECONDARY_AMMO = 7784;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_ENERGY_COST = 7794;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_CLIP = 7795;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_AMMO_II = 7796;
		static const auto ITEM_SKILL_WRAITH_PRIMARY_AMMO_I = 7793;
		static const auto ITEM_SKILL_WRAITH_HEALTH_REGEN_RATE = 7792;
		static const auto ITEM_SKILL_WRAITH_HEALTH_REGEN_DELAY = 7791;
		static const auto ITEM_SKILL_WRAITH_GROUND_SPEED = 7782;
		static const auto ITEM_SKILL_WRAITH_GRENADE_RADIUS = 7789;
		static const auto ITEM_SKILL_WRAITH_GRENADE_AMMO = 7788;
		static const auto ITEM_SKILL_WRAITH_ENERGY_REGEN_II = 7783;
		static const auto ITEM_SKILL_WRAITH_ENERGY_REGEN_I = 7781;
		static const auto ITEM_SKILL_WRAITH_ENERGY_POOL = 7790;
		static const auto ITEM_SKILL_SCRAMBLER_WEAPON_SWITCH = 7769;
		static const auto ITEM_SKILL_SCRAMBLER_GROUND_SPEED = 7768;
		static const auto ITEM_SKILL_SCRAMBLER_SPEED = 7708;
		static const auto ITEM_SKILL_SCRAMBLER_CONTROL = 7709;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_ANTIARMOR = 7711;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_AMMO_II = 7712;
		static const auto ITEM_SKILL_SCRAMBLER_PRIMARY_AMMO_I = 7710;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_EFFECTIVENESS_II = 7719;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_EFFECTIVENESS_I = 7717;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_COST_II = 7718;
		static const auto ITEM_SKILL_SCRAMBLER_PACK_COST_I = 7716;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_REGEN_DELAY = 7713;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_POOL_II = 7715;
		static const auto ITEM_SKILL_SCRAMBLER_HEALTH_POOL_I = 7714;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_RADIUS = 7705;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_DURATION = 7706;
		static const auto ITEM_SKILL_SCRAMBLER_GRENADE_AMMO = 7704;
		static const auto ITEM_SKILL_SCRAMBLER_ENERGY_POOL = 7707;
		static const auto ITEM_SKILL_BRUTE_WEAPON_SWITCH = 7776;
		static const auto ITEM_SKILL_BRUTE_GROUND_SPEED = 7775;
		static const auto ITEM_SKILL_BRUTE_SPEED = 7724;
		static const auto ITEM_SKILL_BRUTE_CONTROL = 7725;
		static const auto ITEM_SKILL_BRUTE_SECONDARY_RELOAD = 7734;
		static const auto ITEM_SKILL_BRUTE_SECONDARY_CLIP = 7735;
		static const auto ITEM_SKILL_BRUTE_SECONARY_AMMO = 7733;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_ANTIARMOR = 7727;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_AMMO_II = 7728;
		static const auto ITEM_SKILL_BRUTE_PRIMARY_AMMO_I = 7726;
		static const auto ITEM_SKILL_BRUTE_HEALTH_REGEN_RATE = 7731;
		static const auto ITEM_SKILL_BRUTE_HEALTH_REGEN_DELAY = 7730;
		static const auto ITEM_SKILL_BRUTE_HEALTH_POOL_II = 7732;
		static const auto ITEM_SKILL_BRUTE_HEALTH_POOL_I = 7729;
		static const auto ITEM_SKILL_BRUTE_GRENADE_RADIUS = 7722;
		static const auto ITEM_SKILL_BRUTE_GRENADE_DURATION = 7721;
		static const auto ITEM_SKILL_BRUTE_GRENADE_AMMO = 7720;
		static const auto ITEM_SKILL_BRUTE_ENERGY_POOL = 7723;
		static const auto ITEM_SKILL_RAIDER_ENERGY_POOL = 7702;
		static const auto ITEM_SKILL_RAIDER_HEALTH_REGEN_DELAY = 7697;
		static const auto ITEM_SKILL_RAIDER_HEALTH_POOL_II = 7699;
		static const auto ITEM_SKILL_RAIDER_HEALTH_POOL_I = 7698;
		static const auto ITEM_SKILL_RAIDER_PACK_POTENCY = 7701;
		static const auto ITEM_SKILL_RAIDER_PACK_COST_II = 7703;
		static const auto ITEM_SKILL_RAIDER_PACK_COST_I = 7700;
		static const auto ITEM_SKILL_RAIDER_GRENADE_RADIUS = 7696;
		static const auto ITEM_SKILL_RAIDER_GRENADE_EFFECT = 7695;
		static const auto ITEM_SKILL_RAIDER_GRENADE_AMMO = 7694;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_ANTIARMOR = 7692;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_CLIP = 7693;
		static const auto ITEM_SKILL_RAIDER_SECONDARY_AMMO = 7691;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_FALLOFF = 7689;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_RELOAD = 7690;
		static const auto ITEM_SKILL_RAIDER_PRIMARY_AMMO = 7688;
		static const auto ITEM_SKILL_INFILTRATOR_ENERGY_POOL = 7619;
		static const auto ITEM_SKILL_INFILTRATOR_HEALTH_REGEN_DELAY = 7626;
		static const auto ITEM_SKILL_INFILTRATOR_HEALTH_REGEN_RATE = 7627;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_POTENCY = 7621;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_COST_II = 7622;
		static const auto ITEM_SKILL_INFILTRATOR_PACK_COST_I = 7620;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_ANTIARMOR = 7616;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_RADIUS = 7617;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_AMMO_II = 7618;
		static const auto ITEM_SKILL_INFILTRATOR_GRENADE_AMMO_I = 7615;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_RELOAD = 7624;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_CLIP = 7625;
		static const auto ITEM_SKILL_INFILTRATOR_SECONDARY_AMMO = 7623;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_FALLOFF = 7613;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_RELOAD = 7614;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_AMMO_II = 7818;
		static const auto ITEM_SKILL_INFILTRATOR_PRIMARY_AMMO_I = 7612;
		static const auto ITEM_SKILL_DOOMBRINGER_WEAPON_SWITCH = 7774;
		static const auto ITEM_SKILL_DOOMBRINGER_STOP_DISTANCE = 7773;
		static const auto ITEM_SKILL_DOOMBRINGER_GROUND_SPEED = 7772;
		static const auto ITEM_SKILL_DOOMBRINGER_SPEED_II = 7630;
		static const auto ITEM_SKILL_DOOMBRINGER_SPEED_I = 7593;
		static const auto ITEM_SKILL_DOOMBRINGER_CONTROL = 7594;
		static const auto ITEM_SKILL_DOOMBRINGER_ENERGY_POOL = 7628;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_REGEN_DELAY = 7595;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_POOL_II = 7631;
		static const auto ITEM_SKILL_DOOMBRINGER_HEALTH_POOL_I = 7596;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_HEALTH_II = 7629;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_HEALTH_I = 7592;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_ANTIARMOR = 7633;
		static const auto ITEM_SKILL_DOOMBRINGER_DEPLOY_AMMO = 7591;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_AMMO_II = 7634;
		static const auto ITEM_SKILL_DOOMBRINGER_GRENADE_AMMO_I = 7590;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_SPINUP = 7597;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_AMMO_II = 7632;
		static const auto ITEM_SKILL_DOOMBRINGER_PRIMARY_AMMO_I = 7598;
		static const auto ITEM_SKILL_RANGER_WEAPON_SWITCH = 7764;
		static const auto ITEM_SKILL_RANGER_STOP_DISTANCE = 7763;
		static const auto ITEM_SKILL_RANGER_GROUND_SPEED = 7762;
		static const auto ITEM_SKILL_RANGER_SPEED_II = 7673;
		static const auto ITEM_SKILL_RANGER_SPEED_I = 7578;
		static const auto ITEM_SKILL_RANGER_CONTROL = 7672;
		static const auto ITEM_SKILL_RANGER_ENERGY_POOL_II = 7678;
		static const auto ITEM_SKILL_RANGER_ENERGY_POOL_I = 7577;
		static const auto ITEM_SKILL_RANGER_HEALTH_REGEN_DELAY = 7584;
		static const auto ITEM_SKILL_RANGER_HEALTH_POOL_II = 7676;
		static const auto ITEM_SKILL_RANGER_HEALTH_POOL_I = 7585;
		static const auto ITEM_SKILL_RANGER_PACK_COST = 7583;
		static const auto ITEM_SKILL_RANGER_GRENADE_AMMO_II = 7677;
		static const auto ITEM_SKILL_RANGER_GRENADE_AMMO_I = 7580;
		static const auto ITEM_SKILL_RANGER_SECONDARY_ANTIARMOR = 7674;
		static const auto ITEM_SKILL_RANGER_SECONDARY_AMMO_II = 7675;
		static const auto ITEM_SKILL_RANGER_SECONDARY_AMMO_I = 7581;
		static const auto ITEM_SKILL_RANGER_PRIMARY_RELOAD = 7582;
		static const auto ITEM_SKILL_RANGER_PRIMARY_CLIP = 7680;
		static const auto ITEM_SKILL_RANGER_PRIMARY_AMMO = 7679;
		static const auto ITEM_SKILL_SENTINEL_WEAPON_SWITCH = 7758;
		static const auto ITEM_SKILL_SENTINEL_SPEED = 7524;
		static const auto ITEM_SKILL_SENTINEL_ENERGY_POOL_II = 7653;
		static const auto ITEM_SKILL_SENTINEL_ENERGY_POOL_I = 7523;
		static const auto ITEM_SKILL_SENTINEL_HEALTH_REGEN_DELAY = 7525;
		static const auto ITEM_SKILL_SENTINEL_HEALTH_REGEN_RATE = 7526;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_RADIUS_II = 7650;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_RADIUS_I = 7521;
		static const auto ITEM_SKILL_SENTINEL_DEPLOY_HEALTH = 7649;
		static const auto ITEM_SKILL_SENTINEL_GRENADE_RADIUS = 7656;
		static const auto ITEM_SKILL_SENTINEL_GRENADE_AMMO = 7527;
		static const auto ITEM_SKILL_SENTINEL_SECONDARY_CLIP = 7652;
		static const auto ITEM_SKILL_SENTINEL_SECONDARY_AMMO = 7651;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_FALLOFF = 7529;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_CLIP = 7654;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_AMMO_II = 7655;
		static const auto ITEM_SKILL_SENTINEL_PRIMARY_AMMO_I = 7528;
		static const auto ITEM_SKILL_TECHNICIAN_WEAPON_SWITCH = 7767;
		static const auto ITEM_SKILL_TECHNICIAN_STOP_DISTANCE = 7766;
		static const auto ITEM_SKILL_TECHNICIAN_GROUND_SPEED = 7765;
		static const auto ITEM_SKILL_TECHNICIAN_SPEED_II = 7683;
		static const auto ITEM_SKILL_TECHNICIAN_SPEED_I = 7682;
		static const auto ITEM_SKILL_TECHNICIAN_CONTROL = 7517;
		static const auto ITEM_SKILL_TECHNICIAN_ENERGY_POOL = 7515;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_REGEN_DELAY = 7516;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_POOL_II = 7684;
		static const auto ITEM_SKILL_TECHNICIAN_HEALTH_POOL_I = 7520;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_ANTIARMOR = 7514;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_LIMIT = 7513;
		static const auto ITEM_SKILL_TECHNICIAN_DEPLOY_ACQUIRE = 7512;
		static const auto ITEM_SKILL_TECHNICIAN_GRENADE_AMMO_II = 7687;
		static const auto ITEM_SKILL_TECHNICIAN_GRENADE_AMMO_I = 7518;
		static const auto ITEM_SKILL_TECHNICIAN_REPAIR_RATE_II = 7681;
		static const auto ITEM_SKILL_TECHNICIAN_REPAIR_RATE_I = 7519;
		static const auto ITEM_SKILL_TECHNICIAN_PRIMARY_RELOAD = 7686;
		static const auto ITEM_SKILL_TECHNICIAN_PRIMARY_AMMO = 7685;
		static const auto ITEM_SKILL_JUGGERNAUGHT_WEAPON_SWITCH = 7771;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GROUND_SPEED = 7770;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SPEED = 7570;
		static const auto ITEM_SKILL_JUGGERNAUGHT_CONTROL = 7657;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_REGEN_DELAY = 7575;
		static const auto ITEM_SKILL_JUGGERNAUGHT_ENERGY_POOL_II = 7659;
		static const auto ITEM_SKILL_JUGGERNAUGHT_ENERGY_POOL_I = 7572;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_POOL_II = 7661;
		static const auto ITEM_SKILL_JUGGERNAUGHT_HEALTH_POOL_I = 7576;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_RADIUS = 7662;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_AMMO_II = 7663;
		static const auto ITEM_SKILL_JUGGERNAUGHT_GRENADE_AMMO_I = 7566;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_ANTIARMOR = 7574;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_AMMO_II = 7660;
		static const auto ITEM_SKILL_JUGGERNAUGHT_SECONDARY_AMMO_I = 7573;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_ANTIARMOR = 7569;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_AMMO_II = 7658;
		static const auto ITEM_SKILL_JUGGERNAUGHT_PRIMARY_AMMO_I = 7568;
		static const auto ITEM_SKILL_SOLDIER_WEAPON_SWITCH = 7761;
		static const auto ITEM_SKILL_SOLDIER_STOP_DISTANCE = 7760;
		static const auto ITEM_SKILL_SOLDIER_GROUND_SPEED = 7759;
		static const auto ITEM_SKILL_SOLDIER_SPEED_II = 7666;
		static const auto ITEM_SKILL_SOLDIER_SPEED_I = 7548;
		static const auto ITEM_SKILL_SOLDIER_CONTROL = 7664;
		static const auto ITEM_SKILL_SOLDIER_ENERGY_POOL_II = 7665;
		static const auto ITEM_SKILL_SOLDIER_ENERGY_POOL_I = 7541;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_REGEN_DELAY = 7554;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_REGEN_RATE = 7669;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_POOL_II = 7668;
		static const auto ITEM_SKILL_SOLDIER_HEALTH_POOL_I = 7555;
		static const auto ITEM_SKILL_SOLDIER_GRENADE_AMMO = 7540;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_RELOAD = 7556;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_CLIP = 7671;
		static const auto ITEM_SKILL_SOLDIER_SECONDARY_AMMO = 7670;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_ANTIARMOR = 7552;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_AMMO_II = 7667;
		static const auto ITEM_SKILL_SOLDIER_PRIMARY_AMMO_I = 7551;
		static const auto ITEM_SKILL_JUMPER_STOP_DISTANCE = 7757;
		static const auto ITEM_SKILL_JUMPER_GROUND_SPEED = 7756;
		static const auto ITEM_SKILL_JUMPER_SPEED = 7559;
		static const auto ITEM_SKILL_JUMPER_CONTROL = 7557;
		static const auto ITEM_SKILL_JUMPER_ENERGY_POOL = 7642;
		static const auto ITEM_SKILL_JUMPER_HEALTH_REGEN_DELAY = 7561;
		static const auto ITEM_SKILL_JUMPER_HEALTH_REGEN_RATE = 7644;
		static const auto ITEM_SKILL_JUMPER_HEALTH_POOL = 7562;
		static const auto ITEM_SKILL_JUMPER_PACK_POTENCY = 7560;
		static const auto ITEM_SKILL_JUMPER_PACK_COST_II = 7643;
		static const auto ITEM_SKILL_JUMPER_PACK_COST_I = 7558;
		static const auto ITEM_SKILL_JUMPER_GRENADE_AMMO = 7563;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_FALLOFF = 7648;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_RELOAD = 7565;
		static const auto ITEM_SKILL_JUMPER_SECONDARY_AMMO = 7647;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_ANTIARMOR = 7645;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_AMMO_II = 7646;
		static const auto ITEM_SKILL_JUMPER_PRIMARY_AMMO_I = 7564;
		static const auto ITEM_SKILL_PATHFINDER_STOP_DISTANCE = 7755;
		static const auto ITEM_SKILL_PATHFINDER_GROUND_SPEED = 7754;
		static const auto ITEM_SKILL_PATHFINDER_SPEED_II = 7503;
		static const auto ITEM_SKILL_PATHFINDER_SPEED_I = 7502;
		static const auto ITEM_SKILL_PATHFINDER_ENERGY_REGEN_II = 7635;
		static const auto ITEM_SKILL_PATHFINDER_ENERGY_REGEN_I = 7501;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_REGEN_DELAY = 7506;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_REGEN_RATE = 7507;
		static const auto ITEM_SKILL_PATHFINDER_HEALTH_POOL = 7636;
		static const auto ITEM_SKILL_PATHFINDER_GRENADE_RADIUS = 7505;
		static const auto ITEM_SKILL_PATHFINDER_GRENADE_AMMO = 7504;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_FALLOFF = 7641;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_CLIP = 7639;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_AMMO_II = 7640;
		static const auto ITEM_SKILL_PATHFINDER_SECONDARY_AMMO_I = 7638;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_ANTIARMOR = 7509;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_AMMO_II = 7637;
		static const auto ITEM_SKILL_PATHFINDER_PRIMARY_AMMO_I = 7508;
		static const auto ITEM_PERK_LIGHTWEIGHT = 8646;
		static const auto ITEM_PERK_SONICPUNCH = 8231;
		static const auto ITEM_PERK_RAGE = 8232;
		static const auto ITEM_PERK_WHEELDEAL = 8169;
		static const auto ITEM_PERK_ULTRACAPACITOR = 8168;
		static const auto ITEM_PERK_SURVIVALIST = 8167;
		static const auto ITEM_PERK_SUPERHEAVY = 8166;
		static const auto ITEM_PERK_SUPERCAPACITOR = 8165;
		static const auto ITEM_PERK_STEALTHY = 8164;
		static const auto ITEM_PERK_SAFETYTHIRD = 8163;
		static const auto ITEM_PERK_SAFEFALL = 8162;
		static const auto ITEM_PERK_REACH = 7916;
		static const auto ITEM_PERK_QUICKDRAW = 8161;
		static const auto ITEM_PERK_POTENTIALENERGY = 8160;
		static const auto ITEM_PERK_PILOT = 8159;
		static const auto ITEM_PERK_MECHANIC = 8170;
		static const auto ITEM_PERK_LOOTER = 8158;
		static const auto ITEM_PERK_EGOCENTRIC = 7917;
		static const auto ITEM_PERK_DETERMINATION = 8157;
		static const auto ITEM_PERK_CLOSECOMBAT = 8156;
		static const auto ITEM_PERK_BOUNTYHUNTER = 8153;
		static const auto WEAPON_TYPE_INSTANTFIRE = 2;
		static const auto WEAPON_TYPE_PROJECTILE = 1;
		static const auto WEAPON_TYPE_UNKNOWN = 0;
		static const auto WEAPON_BASE_VEHICLE = 10;
		static const auto WEAPON_BASE_SHOTGUN = 9;
		static const auto WEAPON_BASE_SMG = 8;
		static const auto WEAPON_BASE_CALLIN = 7;
		static const auto WEAPON_BASE_REPAIRTOOL = 6;
		static const auto WEAPON_BASE_GRENADE = 5;
		static const auto WEAPON_BASE_ASSAULTRIFLE = 4;
		static const auto WEAPON_BASE_SNIPERRIFLE = 3;
		static const auto WEAPON_BASE_PISTOL = 2;
		static const auto WEAPON_BASE_SPINFUSOR = 1;
		static const auto WEAPON_BASE_UNKNOWN = 0;
		static const auto ITEM_PACK_SURVIVAL = 8255;
		static const auto ITEM_PACK_HIGHSPEEDSTEALTH = 8243;
		static const auto ITEM_PACK_UTILITY_SOLDIER = 8223;
		static const auto ITEM_PACK_STEALTH = 7833;
		static const auto ITEM_PACK_SHIELD = 7832;
		static const auto ITEM_PACK_REGEN = 7831;
		static const auto ITEM_PACK_MINORENERGY = 7830;
		static const auto ITEM_PACK_POWERPOOL = 7829;
		static const auto ITEM_PACK_LIGHTREGEN = 7828;
		static const auto ITEM_PACK_JAMMER = 7827;
		static const auto ITEM_PACK_HEAVYSHIELD = 7826;
		static const auto ITEM_PACK_RECHARGE_SENTINEL = 7900;
		static const auto ITEM_PACK_RECHARGE_PATHFINDER = 7825;
		static const auto ITEM_PACK_ENERGY_BRUTE = 7830;
		static const auto ITEM_PACK_ENERGY_JUGGERNAUT = 7901;
		static const auto ITEM_PACK_ENERGY_SOLDIER = 7824;
		static const auto ITEM_PACK_DAMAGE = 7823;
		static const auto ITEM_PACK_BLINK = 7822;
		static const auto ITEM_PACK_AMMO = 7821;
		static const auto WEAPON_ID_TARGETINGBEACON = 8358;
		static const auto WEAPON_ID_SPIKELAUNCHER = 8357;
		static const auto WEAPON_ID_HEAVYTWINFUSOR = 8656;
		static const auto WEAPON_ID_TWINFUSOR = 8257;
		static const auto WEAPON_ID_THROWINGKNIVES = 8256;
		static const auto WEAPON_ID_SAP20 = 8254;
		static const auto WEAPON_ID_ROCKETLAUNCHER = 8253;
		static const auto WEAPON_ID_REMOTE_ARX_BUSTER = 8252;
		static const auto WEAPON_ID_PLASMA_GUN = 8251;
		static const auto WEAPON_ID_PLASMA_CANNON = 8250;
		static const auto WEAPON_ID_NJ5SMG = 8249;
		static const auto WEAPON_ID_GRENADE_NINJASMOKE = 8248;
		static const auto WEAPON_ID_MIRV_GRENADE = 8247;
		static const auto WEAPON_ID_LR1MORTAR = 8246;
		static const auto WEAPON_ID_LIGHTTWINFUSOR = 8245;
		static const auto WEAPON_ID_IMPACTBOMBLETS = 8244;
		static const auto WEAPON_ID_BUCKLER = 8242;
		static const auto WEAPON_ID_MINE_ARMOREDCLAYMORE = 8240;
		static const auto WEAPON_ID_ACCURIZEDSHOTGUN = 8239;
		static const auto WEAPON_ID_INFILTRATORBLANK = 8230;
		static const auto WEAPON_ID_PROXIMITY_GRENADE = 8222;
		static const auto WEAPON_ID_GRENADE_T5 = 7914;
		static const auto WEAPON_ID_STEALTHLIGHTSPINFUSOR = 7902;
		static const auto WEAPON_ID_THUMPER_D = 7462;
		static const auto WEAPON_ID_THUMPER = 7461;
		static const auto WEAPON_ID_RANOVER = 7817;
		static const auto WEAPON_ID_HITWALL = 7816;
		static const auto WEAPON_ID_FALLING = 7815;
		static const auto WEAPON_ID_TCNG = 7736;
		static const auto WEAPON_ID_CALLIN_ORBITALSTRIKE = 7611;
		static const auto WEAPON_ID_CALLIN_INVENTORYDROP = 7610;
		static const auto WEAPON_ID_CALLIN_TACTICALSTRIKE = 7609;
		static const auto WEAPON_ID_SPINFUSOR_TOSS = 7459;
		static const auto WEAPON_ID_SPINFUSOR_LIGHT = 7422;
		static const auto WEAPON_ID_SPINFUSOR_HEAVY = 7448;
		static const auto WEAPON_ID_SPINFUSOR_D = 7446;
		static const auto WEAPON_ID_SPINFUSOR = 7401;
		static const auto WEAPON_ID_SHOTGUN_SAWED_OFF = 7427;
		static const auto WEAPON_ID_SHOTGUN_AUTO = 7449;
		static const auto WEAPON_ID_SHOTGUN_ARX = 7454;
		static const auto WEAPON_ID_SHOTGUN = 7399;
		static const auto WEAPON_ID_SMG_TCN4 = 7443;
		static const auto WEAPON_ID_SMG_RHINO = 7397;
		static const auto WEAPON_ID_SMG_NJ4 = 7441;
		static const auto WEAPON_ID_RIFLE_SNIPER = 7400;
		static const auto WEAPON_ID_RIFLE_PHASE = 7395;
		static const auto WEAPON_ID_RIFLE_ASSAULT_X1 = 7458;
		static const auto WEAPON_ID_RIFLE_ASSAULT_S22 = 7424;
		static const auto WEAPON_ID_RIFLE_ASSAULT_LIGHT = 7438;
		static const auto WEAPON_ID_RIFLE_ASSAULT = 7385;
		static const auto WEAPON_ID_REPAIR_TOOL_SD = 7436;
		static const auto WEAPON_ID_REPAIR_TOOL = 7396;
		static const auto WEAPON_ID_TURRET_WALL = 7445;
		static const auto WEAPON_ID_TURRET_LIGHT = 7413;
		static const auto WEAPON_ID_TURRET_BASE = 7412;
		static const auto WEAPON_ID_TURRET_EXR = 7417;
		static const auto WEAPON_ID_PISTOL_SPARROW = 7433;
		static const auto WEAPON_ID_PISTOL_SN7 = 7418;
		static const auto WEAPON_ID_PISTOL_H1 = 7435;
		static const auto WEAPON_ID_PISTOL_FALCON = 7419;
		static const auto WEAPON_ID_PISTOL_NOVA_SLUG = 7431;
		static const auto WEAPON_ID_PISTOL_NOVA_COLT = 7394;
		static const auto WEAPON_ID_PISTOL_EAGLE_CUSTOM = 7439;
		static const auto WEAPON_ID_PISTOL_EAGLE = 7388;
		static const auto WEAPON_ID_PILOT_SHRIKE = 7407;
		static const auto WEAPON_ID_PILOT_HERC = 7403;
		static const auto WEAPON_ID_PILOT_HAVOC = 7409;
		static const auto WEAPON_ID_PILOT_GRAVCYCLE = 7410;
		static const auto WEAPON_ID_PILOT_BEOWULF = 7406;
		static const auto WEAPON_ID_MOTIONALARM = 7426;
		static const auto WEAPON_ID_MINE_PRISM = 7440;
		static const auto WEAPON_ID_MINE_CLAYMORE = 7421;
		static const auto WEAPON_ID_MINE = 7392;
		static const auto WEAPON_ID_MELEE = 7391;
		static const auto WEAPON_ID_LAUNCHER_SABER = 7398;
		static const auto WEAPON_ID_LAUNCHER_MORTAR = 7393;
		static const auto WEAPON_ID_LAUNCHER_MIRV = 7457;
		static const auto WEAPON_ID_LAUNCHER_GRENADE = 7416;
		static const auto WEAPON_ID_LAUNCHER_BOLT_HEAVY = 7452;
		static const auto WEAPON_ID_LAUNCHER_BOLT = 7425;
		static const auto WEAPON_ID_GUNNER_HERC = 7404;
		static const auto WEAPON_ID_GUNNER_BEOWULF = 7405;
		static const auto WEAPON_ID_GRENADE_XL = 7430;
		static const auto WEAPON_ID_GRENADE_WHITEOUT = 7432;
		static const auto WEAPON_ID_GRENADE_STICKY_LIGHT = 7455;
		static const auto WEAPON_ID_GRENADE_STICKY = 7402;
		static const auto WEAPON_ID_GRENADE_ST = 7437;
		static const auto WEAPON_ID_GRENADE_SPIKE = 7428;
		static const auto WEAPON_ID_GRENADE_NITRON_HEAVY = 7450;
		static const auto WEAPON_ID_GRENADE_NITRON = 7387;
		static const auto WEAPON_ID_GRENADE_FLARE = 7389;
		static const auto WEAPON_ID_GRENADE_EMP = 7444;
		static const auto WEAPON_ID_GRENADE_AP_HEAVY = 7447;
		static const auto WEAPON_ID_GRENADE_AP = 7434;
		static const auto WEAPON_ID_GRENADE = 7390;
		static const auto WEAPON_ID_FORCEFIELD_PERSONAL = 7460;
		static const auto WEAPON_ID_FORCEFIELD = 7411;
		static const auto WEAPON_ID_DROPJAMMER = 7456;
		static const auto WEAPON_ID_CHAINGUN = 7386;
		static const auto WEAPON_ID_ARX_BUSTER = 7384;
		static const auto WEAPON_ID_LACERATOR = 102016;
		static const auto WEAPON_ID_DUALRHINO = 102024;
		static const auto WEAPON_ID_AVMINE = 102003;
		static const auto WEAPON_ID_UNKNOWN = 102000;
		static const auto CLASS_INFO_BIT_NAKEDPATHFINDER = 0x00040000;
		static const auto CLASS_INFO_BIT_MARAUDER = 0x00020000;
		static const auto CLASS_INFO_BIT_JUGGERNAUT = 0x00010000;
		static const auto CLASS_INFO_BIT_DOOMBRINGER = 0x00008000;
		static const auto CLASS_INFO_BIT_ROOK = 0x00004000;
		static const auto CLASS_INFO_BIT_BRUTE = 0x00002000;
		static const auto CLASS_INFO_BIT_WARDER = 0x00001000;
		static const auto CLASS_INFO_BIT_TECHNICIAN = 0x00000800;
		static const auto CLASS_INFO_BIT_RAIDER = 0x00000400;
		static const auto CLASS_INFO_BIT_SOLDIER = 0x00000200;
		static const auto CLASS_INFO_BIT_SCRAMBLER = 0x00000100;
		static const auto CLASS_INFO_BIT_RANGER = 0x00000080;
		static const auto CLASS_INFO_BIT_ENGINEER = 0x00000040;
		static const auto CLASS_INFO_BIT_SENTINEL = 0x00000020;
		static const auto CLASS_INFO_BIT_WRAITH = 0x00000010;
		static const auto CLASS_INFO_BIT_PATHFINDER = 0x00000008;
		static const auto CLASS_INFO_BIT_ARCHITECT = 0x00000004;
		static const auto CLASS_INFO_BIT_JUMPER = 0x00000002;
		static const auto CLASS_INFO_BIT_INFILTRATOR = 0x00000001;
		static const auto CLASS_INFO_BIT_NONE = 0x00000000;
		static const auto CLASS_PURCHASE_HEAVY_JUGGERNAUGHT = 7474;
		static const auto CLASS_PURCHASE_HEAVY_DOOMBRINGER = 7488;
		static const auto CLASS_PURCHASE_HEAVY_BRUTE = 7486;
		static const auto CLASS_PURCHASE_MEDIUM_TECHNICIAN = 7472;
		static const auto CLASS_PURCHASE_MEDIUM_RAIDER = 7494;
		static const auto CLASS_PURCHASE_MEDIUM_SOLDIER = 7470;
		static const auto CLASS_PURCHASE_LIGHT_SENTINEL = 7478;
		static const auto CLASS_PURCHASE_LIGHT_PATHFINDER = 7466;
		static const auto CLASS_PURCHASE_LIGHT_INFILTRATOR = 7476;
		static const auto CLASS_TYPE_HEAVY_MARAUDER = 1695;
		static const auto CLASS_TYPE_HEAVY_JUGGERNAUGHT = 1692;
		static const auto CLASS_TYPE_HEAVY_DOOMBRINGER = 1691;
		static const auto CLASS_TYPE_HEAVY_ROOK = 1690;
		static const auto CLASS_TYPE_HEAVY_BRUTE = 1689;
		static const auto CLASS_TYPE_MEDIUM_WARDER = 1700;
		static const auto CLASS_TYPE_MEDIUM_TECHNICIAN = 1694;
		static const auto CLASS_TYPE_MEDIUM_RAIDER = 1699;
		static const auto CLASS_TYPE_MEDIUM_SOLDIER = 1693;
		static const auto CLASS_TYPE_MEDIUM_SCRAMBLER = 1688;
		static const auto CLASS_TYPE_MEDIUM_RANGER = 1687;
		static const auto CLASS_TYPE_MEDIUM_ENGINEER = 1698;
		static const auto CLASS_TYPE_LIGHT_SENTINEL = 1686;
		static const auto CLASS_TYPE_LIGHT_WRAITH = 1685;
		static const auto CLASS_TYPE_LIGHT_NAKEDPATHFINDER = 1701;
		static const auto CLASS_TYPE_LIGHT_PATHFINDER = 1683;
		static const auto CLASS_TYPE_LIGHT_ARCHITECT = 1697;
		static const auto CLASS_TYPE_LIGHT_JUMPER = 1696;
		static const auto CLASS_TYPE_LIGHT_INFILTRATOR = 1682;
		static const auto CLASS_TYPE_UNKNOWN = 1668;
		static const auto PROPERTY_CUSTOM_MUTATORS = 0x40000004;
		static const auto PROPERTY_SERVER_DESCRIPTION = 0x40000003;
		static const auto PROPERTY_CUSTOM_GAMEMODE = 0x40000002;
		static const auto PROPERTY_CUSTOM_MAPNAME = 0x40000001;
		static const auto GAME_SESSION_NAME = 'Game';
		static const auto STAT_VIEW_BASE_WEAPON_TYPE = 1000;
		static const auto STAT_VIEW_BASE_GAME = 101;
		static const auto STAT_VIEW_BASE_PLAYER = 1;
		static const auto CONTEXT_GAME_MODE_TRCTFBLITZ = 10;
		static const auto CONTEXT_GAME_MODE_TRCAPTUREANDHOLD = 9;
		static const auto CONTEXT_GAME_MODE_TRDEFENDANDDESTROY = 8;
		static const auto CONTEXT_GAME_MODE_TRARENA = 7;
		static const auto CONTEXT_GAME_MODE_TRTEAMRABBIT = 6;
		static const auto CONTEXT_GAME_MODE_TRSTORM = 5;
		static const auto CONTEXT_GAME_MODE_TRTRAINING = 4;
		static const auto CONTEXT_GAME_MODE_TRSIEGE = 3;
		static const auto CONTEXT_GAME_MODE_TRRABBIT = 2;
		static const auto CONTEXT_GAME_MODE_TRTDM = 1;
		static const auto CONTEXT_GAME_MODE_TRCTF = 0;
		static const auto TR_QUERY_CTFBLITZ = 6;
		static const auto TR_QUERY_DEFENDANDDESTROY = 5;
		static const auto TR_QUERY_ARENA = 4;
		static const auto TR_QUERY_TEAMRABBIT = 3;
		static const auto TR_QUERY_RABBIT = 2;
		static const auto TR_QUERY_TDM = 1;
		static const auto TR_QUERY_CTF = 0;
		static const auto MAX_CLASS_SLOTS = 10;
		enum AcquisitionType : byte
		{
			AT_STANDARD = 0,
			AT_USEDGOLD = 1,
			AT_USEDXP = 2,
			AT_VIP = 3,
			AT_BOOST = 4,
			AT_FWOTD = 5,
			AT_PROMO = 6,
			AT_CLASS = 7,
			AT_SKILL = 8,
			AT_MAX = 9,
		};
		enum POPUPTYPE : byte
		{
			PUT_NONE = 0,
			PUT_STEAM_INIT = 1,
			PUT_STEAM_FINALIZE = 2,
			PUT_STEAM_DECLINED = 3,
			PUT_STEAM_BADDATA = 4,
			PUT_VIDEO_WARNING = 5,
			PUT_PORTAL_CONFIRM = 6,
			PUT_MAX = 7,
		};
		struct VendorItemData
		{
		public:
			ADD_STRUCT(ScriptString*, Description, 20)
			ADD_STRUCT(ScriptString*, Title, 8)
			ADD_STRUCT(int, LootId, 4)
			ADD_STRUCT(int, Price, 0)
		};
		struct AcquisitionData
		{
		public:
			ADD_STRUCT(int, Icon, 36)
			ADD_STRUCT(ScriptString*, Type, 24)
			ADD_STRUCT(ScriptString*, Text, 12)
			ADD_STRUCT(ScriptString*, Title, 0)
		};
		struct QueueUIData
		{
		public:
			ADD_STRUCT(int, LevelMax, 60)
			ADD_STRUCT(int, LevelMin, 56)
			ADD_STRUCT(int, SortOrder, 52)
			ADD_STRUCT(int, contentIndex, 48)
			ADD_STRUCT(ScriptString*, RibbonText, 36)
			ADD_STRUCT(int, ribbonType, 32)
			ADD_BOOL(bShowRibbon, 28, 0x2)
			ADD_BOOL(bAvailable, 28, 0x1)
			ADD_STRUCT(ScriptString*, Subtitle, 16)
			ADD_STRUCT(ScriptString*, Title, 4)
			ADD_STRUCT(int, queueId, 0)
		};
		ADD_STRUCT(GFxTrMenuMoviePlayer::POPUPTYPE, m_PopupType, 380)
		ADD_BOOL(bInitialized, 384, 0x1000)
		ADD_OBJECT(GFxObject, _global, 748)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 784)
		ADD_OBJECT(TrUser, User, 752)
		ADD_OBJECT(TrStrings, Strings, 756)
		ADD_OBJECT(TrStreamManager, StreamManager, 780)
		ADD_OBJECT(TrInventoryHelper, EquipHelper, 804)
		ADD_OBJECT(TrEquipInterface, EquipInterface, 800)
		ADD_OBJECT(TgPlayerProfile, PlayerProfile, 796)
		ADD_OBJECT(TrBrowserManager, Browser, 792)
		ADD_OBJECT(TrLoginManager, LoginManager, 768)
		ADD_OBJECT(TrQueueManager, QueueManager, 772)
		ADD_OBJECT(TrPartyManager, PartyManager, 776)
		ADD_OBJECT(TrLoadingData, LoadingData, 764)
		ADD_OBJECT(TrPageManager, Pages, 760)
		ADD_OBJECT(TrSettingsManager, SettingsManager, 808)
		ADD_OBJECT(TrRibbonManager, RibbonManager, 820)
		ADD_OBJECT(TrFriendManager, Friends, 788)
		ADD_OBJECT(GFxTrScene_EULA, EULAScene, 732)
		ADD_OBJECT(GFxTrScene_MatchSummary, MatchSummaryScene, 736)
		ADD_OBJECT(GFxTrScene_PlayerSummary, PlayerSummaryScene, 740)
		ADD_OBJECT(GFxTrMenuSounds, MenuSounds, 744)
		ADD_BOOL(bStartupCompleted, 384, 0x2)
		ADD_BOOL(bCreatingNewPlayer, 384, 0x8000)
		ADD_BOOL(bOpeningMenu, 388, 0x1000)
		ADD_BOOL(bPeachy, 384, 0x1)
		ADD_BOOL(bWaitingForEntry, 388, 0x4000)
		ADD_BOOL(bFullyLoaded, 384, 0x800)
		ADD_BOOL(bLoggedIn, 384, 0x200)
		ADD_BOOL(bNeedsEULA, 384, 0x100)
		ADD_STRUCT(int, EstimatedWaitTime, 540)
		ADD_BOOL(bWaitingForServerDropPopup, 388, 0x1)
		ADD_BOOL(bInGame, 384, 0x8)
		ADD_BOOL(bLoading, 384, 0x10)
		ADD_BOOL(bEndOfMatch, 384, 0x80)
		ADD_BOOL(bViewingSummary, 384, 0x10000000)
		ADD_BOOL(bWelcomed, 384, 0x4)
		ADD_BOOL(bWaitingForQuitGameConfirm, 384, 0x20000000)
		ADD_BOOL(bWaitingForLeaveMatchConfirm, 384, 0x40000000)
		ADD_STRUCT(ScriptString*, LoginFailure, 416)
		ADD_BOOL(bWaitingForLoginFailedPopup, 388, 0x8)
		ADD_BOOL(LoginSuccess, 384, 0x20000)
		ADD_BOOL(bProfileLoaded, 384, 0x4000)
		ADD_BOOL(bEquipmentLoaded, 384, 0x40000)
		ADD_STRUCT(ScriptString*, LoginPlayer, 392)
		ADD_STRUCT(ScriptString*, LoginReason, 404)
		ADD_BOOL(bRefreshingMenu, 388, 0x2000)
		ADD_STRUCT(ScriptString*, GenericFailReason, 452)
		ADD_BOOL(bWaitingForJoinFailed, 388, 0x20)
		ADD_BOOL(bWaitingForJoinRequiresPassword, 388, 0x40)
		ADD_STRUCT(int, PlayerNameFailType, 504)
		ADD_BOOL(bWaitingForPlayerNamePopup, 384, 0x4000000)
		ADD_STRUCT(int, Progress, 516)
		ADD_STRUCT(int, RankIcon, 524)
		ADD_STRUCT(int, NextRank, 520)
		ADD_BOOL(bBlockRelease, 384, 0x2000)
		ADD_STRUCT(int, EndOfMatchTimer, 508)
		ADD_STRUCT(ScriptString*, CapturedKey, 428)
		ADD_BOOL(bWaitingForPopup, 388, 0x80)
		ADD_BOOL(bChatOpen, 388, 0x200)
		ADD_BOOL(bBlockHotkey, 384, 0x400)
		ADD_STRUCT(ScriptString*, UnlockItemName, 480)
		ADD_STRUCT(ScriptString*, UnlockTypeName, 492)
		ADD_STRUCT(GFxTrMenuMoviePlayer::AcquisitionType, UnlockIconType, 381)
		ADD_STRUCT(int, UnlockIconId, 476)
		ADD_STRUCT(ScriptArray<GFxTrMenuMoviePlayer::AcquisitionData>, AcquisitionList, 708)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, UnknownList, 696)
		ADD_BOOL(bWaitingForLoginQueuePopup, 384, 0x80000000)
		ADD_BOOL(bWaitingForAFKKickPopup, 388, 0x2)
		ADD_BOOL(bWaitingForPurchaseReturn, 388, 0x10)
		ADD_BOOL(bWaitingForAddFriendPopup, 388, 0x4)
		ADD_STRUCT(ScriptString*, PurchaseFailedMsg, 528)
		ADD_BOOL(bShowPurchaseFailed, 384, 0x100000)
		ADD_STRUCT(int, PurchasingCurrency, 512)
		ADD_BOOL(bShowPromoCodeFailed, 384, 0x1000000)
		ADD_STRUCT(ScriptString*, PromoFailReason, 440)
		ADD_BOOL(bShowGenericFailure, 384, 0x2000000)
		ADD_BOOL(bWaitingForPlayerNameInput, 384, 0x8000000)
		ADD_STRUCT(ScriptString*, NameRulesMessage, 544)
		ADD_STRUCT(GFxTrMenuMoviePlayer::VendorItemData, PortalPurchase, 652)
		ADD_BOOL(bInQueue, 384, 0x20)
		ADD_BOOL(bQueueListDirty, 384, 0x40)
		ADD_BOOL(bWebVendorLoaded, 384, 0x10000)
		ADD_BOOL(bShowDiamondSword, 384, 0x80000)
		ADD_BOOL(bWaitingForSelectionPopup, 384, 0x200000)
		ADD_BOOL(bWaitingForCurrencyPopup, 384, 0x400000)
		ADD_BOOL(bWaitingForConfirmationPopup, 384, 0x800000)
		ADD_BOOL(bPasswordPopup, 388, 0x100)
		ADD_BOOL(bInvitationPopup, 388, 0x400)
		ADD_BOOL(bBadgeModification, 388, 0x800)
		ADD_STRUCT(ScriptString*, NextMapName, 464)
		ADD_STRUCT(ScriptString*, FriendLabel, 556)
		ADD_STRUCT(ScriptString*, FollowerLabel, 568)
		ADD_STRUCT(ScriptString*, OfflineLabel, 580)
		ADD_STRUCT(ScriptString*, OnlineLabel, 592)
		ADD_STRUCT(ScriptString*, InGameLabel, 604)
		ADD_STRUCT(ScriptString*, InLobbyLabel, 616)
		ADD_STRUCT(ScriptString*, OKLabel, 628)
		ADD_STRUCT(ScriptString*, CancelLabel, 640)
		ADD_STRUCT(ScriptArray<GFxTrMenuMoviePlayer::VendorItemData>, GoldItemList, 684)
		ADD_STRUCT(ScriptArray<GFxTrMenuMoviePlayer::QueueUIData>, QueueUIList, 720)
		void DelegateNoParam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54312);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelegateInt(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54313);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateBool(bool bVal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54315);
			byte params[4] = { NULL };
			*(bool*)params = bVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateString(ScriptString* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54317);
			byte params[12] = { NULL };
			*(ScriptString**)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateGFxList(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54319);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateIntInt(int Val1, int Val2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54321);
			byte params[8] = { NULL };
			*(int*)params = Val1;
			*(int*)&params[4] = Val2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateIntString(int Val1, ScriptString* Val2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54324);
			byte params[16] = { NULL };
			*(int*)params = Val1;
			*(ScriptString**)&params[4] = Val2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateStringInt(ScriptString* Val1, int Val2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54327);
			byte params[16] = { NULL };
			*(ScriptString**)params = Val1;
			*(int*)&params[12] = Val2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateStringBool(ScriptString* val, bool bVal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54330);
			byte params[16] = { NULL };
			*(ScriptString**)params = val;
			*(bool*)&params[12] = bVal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateIntGFxList(int val, class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54333);
			byte params[8] = { NULL };
			*(int*)params = val;
			*(class GFxObject**)&params[4] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelegateOnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54336);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int DelegateGetInt()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54338);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int DelegateGetPrice(float XPValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54340);
			byte params[8] = { NULL };
			*(float*)params = XPValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool DelegateIntIntInt(int Val1, int Val2, int Val3)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54343);
			byte params[16] = { NULL };
			*(int*)params = Val1;
			*(int*)&params[4] = Val2;
			*(int*)&params[8] = Val3;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool DelegateGetBoolIntInt(int SlotId, int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54348);
			byte params[12] = { NULL };
			*(int*)params = SlotId;
			*(int*)&params[4] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool DelegateLogin(ScriptString* UserName, ScriptString* Password, bool bRemember)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54352);
			byte params[32] = { NULL };
			*(ScriptString**)params = UserName;
			*(ScriptString**)&params[12] = Password;
			*(bool*)&params[24] = bRemember;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool DelegateBoolGetBool(bool val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54357);
			byte params[8] = { NULL };
			*(bool*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* DelegateGetString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54360);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void DelegateOptions(class GFxObject* List, int ClassId, int SkillId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54362);
			byte params[12] = { NULL };
			*(class GFxObject**)params = List;
			*(int*)&params[4] = ClassId;
			*(int*)&params[8] = SkillId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int DelegateAction(int val, class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54366);
			byte params[12] = { NULL };
			*(int*)params = val;
			*(class GFxObject**)&params[4] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool UseSteam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54370);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RequestPurchaseSteamItem(int LootId, int Price)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54372);
			byte params[8] = { NULL };
			*(int*)params = LootId;
			*(int*)&params[4] = Price;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RequestSteamUserData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54375);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGoldItemInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54376);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool UsePortal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54378);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetPortalBalance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54380);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* GetPortalCurrencyName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54382);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool RequestPurchasePortalItem(int LootItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54384);
			byte params[8] = { NULL };
			*(int*)params = LootItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckAutoLoginStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54387);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PurchasedItem(int VendorId, int LootId, bool bSuccess, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54389);
			byte params[24] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = LootId;
			*(bool*)&params[8] = bSuccess;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54394);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReadPlayerProfileData(class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54396);
			byte params[8] = { NULL };
			*(class TgPlayerProfile**)params = Profile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UserLoginChanged(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54399);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterMarshalCallback(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54401);
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		ScriptString* GetVersionString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54404);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ForceFocus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54406);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddAcquisition(int VendorId, int LootId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54407);
			byte params[12] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = LootId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void GetQueueUIInfo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54411);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLanguageFontIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54412);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void RequestStreams()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54414);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetEquipmentXP(int ActivityId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54415);
			byte params[8] = { NULL };
			*(int*)params = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetEquipmentTierXP(int ActivityId, int Tier)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54418);
			byte params[12] = { NULL };
			*(int*)params = ActivityId;
			*(int*)&params[4] = Tier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool HaveClanTag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54422);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54424);
			byte params[8] = { NULL };
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetLoginDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54453);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSubmitPlayerNameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54454);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadTeamMiscDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54455);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadTeamScoreboardDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54456);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadTeamStatsDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54457);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadTeamAccoladeDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54458);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadPlayerMiscDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54459);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadPlayerStatsDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54460);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadPlayerAccoladeDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54461);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAcceptEULADelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54462);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundXPGain(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54463);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundClassType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54464);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundSkillType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54465);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEscapeClass(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54467);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExitGameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54468);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetGetPlatformDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54469);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetGetViewModeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54470);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShowSummaryDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54471);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAlertDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54472);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserGoldDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54473);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserStoreDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54474);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserSupportDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54475);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserProfileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54476);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserBoosterDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54477);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserClassVideoDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54478);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserActivateKeyDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54479);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserCreateAccountDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54480);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserRecoverPasswordDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54481);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBrowserRecoverUsernameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54482);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetExitQueueDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54483);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetJoinCustomServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54484);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFavoriteServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54485);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPasswordServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54486);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetServerPageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54487);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetServerSortDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54488);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetReticuleActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54489);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSaveReticuleDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54490);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRequestNewsDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54491);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetStartLoginDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54492);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSmoothAnimDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54493);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54494);
			byte params[4] = { NULL };
			*(int*)params = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_Resize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54495);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPopupDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54497);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPopupCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54498);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFocusedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54499);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSelectedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54500);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetModifiedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54501);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetModifyFocusDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54502);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActionUpDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54503);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActionDownDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54504);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHelpButtonDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54505);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProfilePageUpDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54506);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetProfilePageDownDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54507);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMutePlayerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54508);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSummaryActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54509);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFriendPlayerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54510);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLoadXPSummaryDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54511);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPromoActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54512);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSelectedFeatureDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54513);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CompleteStartup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54514);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryAction(int ActionId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54517);
			byte params[4] = { NULL };
			*(int*)params = ActionId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54521);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMutePlayer(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54523);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripTag(ScriptString* sValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54528);
			byte params[24] = { NULL };
			*(ScriptString**)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void StartPeach()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54532);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54534);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeach()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowPeach()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54536);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EntryPlayerReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54537);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HaveEntry()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54540);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetPlayerMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54544);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClosePopup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54548);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerInLogin(bool bServerDrop)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54549);
			byte params[4] = { NULL };
			*(bool*)params = bServerDrop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QueuePopup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54553);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerInLobby()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54554);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_StopLoading()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54560);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerLoading()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54562);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_GotoState(ScriptString* NewState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54563);
			byte params[12] = { NULL };
			*(ScriptString**)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerInGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54564);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEndOfMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54566);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54567);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Escape()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54569);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CloseClasses()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54570);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54571);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenClasses()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54572);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenFriends()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54573);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuitGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54575);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54577);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuitGamePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54579);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveMatchPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54585);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitGamePopupComplete(int Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54591);
			byte params[4] = { NULL };
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveMatchPopupComplete(int Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54593);
			byte params[4] = { NULL };
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Quit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54595);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendPlayerLogin(ScriptString* PlayerName, ScriptString* Reason, bool Success, bool bNeedEULA)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54597);
			byte params[32] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Reason;
			*(bool*)&params[24] = Success;
			*(bool*)&params[28] = bNeedEULA;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AlienMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54612);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnProfileLoaded(bool bShowEula)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54614);
			byte params[4] = { NULL };
			*(bool*)params = bShowEula;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsLoadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54621);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SendBack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54627);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipmentLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54635);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipmentChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54637);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshPage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54648);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54649);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinFailed(ScriptString* Error)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54650);
			byte params[12] = { NULL };
			*(ScriptString**)params = Error;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayJoinFailed(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54654);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinRequiresPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54658);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinRequiresPasswordComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54660);
			byte params[16] = { NULL };
			*(int*)params = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckRibbons(bool bForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54664);
			byte params[4] = { NULL };
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProfileUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54667);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ProfileUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54668);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitPopup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54669);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_PopupError(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54670);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayEULA()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54671);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_HideLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54672);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FillEULAText(ScriptString* EULAText, ScriptString* Title, ScriptString* Accept, ScriptString* Decline)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54673);
			byte params[48] = { NULL };
			*(ScriptString**)params = EULAText;
			*(ScriptString**)&params[12] = Title;
			*(ScriptString**)&params[24] = Accept;
			*(ScriptString**)&params[36] = Decline;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateNewPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54678);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayerNameNotAllowed(bool bTaken)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54679);
			byte params[4] = { NULL };
			*(bool*)params = bTaken;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetUserSelectedClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54683);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void FillProfileData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54686);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendProfileData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54696);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FillProfile(class GFxObject* ObjList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54710);
			byte params[4] = { NULL };
			*(class GFxObject**)params = ObjList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetBoostLabel(int Hours)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54711);
			byte params[16] = { NULL };
			*(int*)params = Hours;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptClass* GetRankFromXP(int XP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54720);
			byte params[8] = { NULL };
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54726);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void RestorePlayerHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54731);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPlatform()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54734);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* GetViewMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54736);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ShowMovie(bool bFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54738);
			byte params[4] = { NULL };
			*(bool*)params = bFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54742);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_HideMovie()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54744);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54745);
			byte params[28] = { NULL };
			*(int*)params = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateStatus(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54749);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCountdownTimer(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54750);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54753);
			byte params[4] = { NULL };
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequestPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54757);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void KeyBindCaptured(ScriptString* KeyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54759);
			byte params[12] = { NULL };
			*(ScriptString**)params = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool KeyPressCaptured(ScriptString* KeyName, bool bReleased)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54762);
			byte params[20] = { NULL };
			*(ScriptString**)params = KeyName;
			*(bool*)&params[12] = bReleased;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool TeamSelectActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54786);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool TeamSelectOpen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54790);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool PlayerNeedsTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54793);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool PlayerNeedsClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54797);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class TrHUD* GetPlayerHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54801);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrHUD**)params;
		}
		void StartHotkeyBlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54804);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndHotkeyBlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54806);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedItem(ScriptString* Description, int ItemId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54807);
			byte params[16] = { NULL };
			*(ScriptString**)params = Description;
			*(int*)&params[12] = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedGold(ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54822);
			byte params[12] = { NULL };
			*(ScriptString**)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedXP(ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54825);
			byte params[12] = { NULL };
			*(ScriptString**)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedBooster(ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54827);
			byte params[12] = { NULL };
			*(ScriptString**)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedBadge(ScriptString* Description, ScriptString* RankStr, int Id)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54829);
			byte params[28] = { NULL };
			*(ScriptString**)params = Description;
			*(ScriptString**)&params[12] = RankStr;
			*(int*)&params[24] = Id;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedNameChange(ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54833);
			byte params[12] = { NULL };
			*(ScriptString**)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedVIP()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54836);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedServerTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54838);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedClanTag(bool bRemoved)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54842);
			byte params[4] = { NULL };
			*(bool*)params = bRemoved;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnlockedSkill(int SkillId, int ParentId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54846);
			byte params[8] = { NULL };
			*(int*)params = SkillId;
			*(int*)&params[4] = ParentId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WinOfTheDay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54856);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClaimedPromotion(ScriptString* PromoName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54858);
			byte params[12] = { NULL };
			*(ScriptString**)params = PromoName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckVIPForLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54861);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadyAcquisition(ScriptString* TopName, ScriptString* BotName, GFxTrMenuMoviePlayer::AcquisitionType IconType, int IconId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54862);
			byte params[29] = { NULL };
			*(ScriptString**)params = TopName;
			*(ScriptString**)&params[12] = BotName;
			*(GFxTrMenuMoviePlayer::AcquisitionType*)&params[24] = IconType;
			*(int*)&params[28] = IconId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayAcquisitions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54871);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAcquisitions()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54873);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_UnlockedItem(ScriptString* TopName, ScriptString* BotName, ScriptString* IconType, int IconId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54876);
			byte params[40] = { NULL };
			*(ScriptString**)params = TopName;
			*(ScriptString**)&params[12] = BotName;
			*(ScriptString**)&params[24] = IconType;
			*(int*)&params[36] = IconId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickVoteFeedback(bool bComplete, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54877);
			byte params[16] = { NULL };
			*(bool*)params = bComplete;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerInLoginQueue(int Estimate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54882);
			byte params[4] = { NULL };
			*(int*)params = Estimate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoginQueuePopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54885);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoginQueuePopupComplete(int Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54900);
			byte params[4] = { NULL };
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerDropPopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54902);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AFKKickPopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54906);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoginFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54911);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WaitingForPurchaseReturn(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54915);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PasswordPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54920);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFriendScoreboardPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54925);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PurchaseFailed(ScriptString* FailMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54936);
			byte params[12] = { NULL };
			*(ScriptString**)params = FailMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PurchaseFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54940);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PromoCodeFailed(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54951);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PromoCodeFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54955);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GenericFailure(ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54958);
			byte params[12] = { NULL };
			*(ScriptString**)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GenericFailurePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54961);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NewPlayerNamePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54964);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RevertSetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54972);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54973);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestNews()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54977);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowNews(ScriptString* News, bool bFeatured)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54978);
			byte params[16] = { NULL };
			*(ScriptString**)params = News;
			*(bool*)&params[12] = bFeatured;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QueueTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54980);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginExperienceTweens(bool bDailyCompleted, bool bWeeklyCompleted)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54981);
			byte params[8] = { NULL };
			*(bool*)params = bDailyCompleted;
			*(bool*)&params[4] = bWeeklyCompleted;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TweenExperienceSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54986);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenPlayerSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54988);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleWorkingGraphic(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54989);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowWorkingGraphic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54991);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideWorkingGraphic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54992);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedUnknown(int VendorId, int LootId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54993);
			byte params[8] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = LootId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeedAccolades(class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54998);
			byte params[4] = { NULL };
			*(class TgPlayerProfile**)params = Profile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UILoadSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55010);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_LoadPlayerSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearVehicleMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55015);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowVehicleMenu(int Credits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55017);
			byte params[4] = { NULL };
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PullOpenMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_OpeningMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ForceFocus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55023);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVehicleMenuOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55024);
			byte params[40] = { NULL };
			*(ScriptString**)params = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = Icon;
			*(int*)&params[32] = CountSpawned;
			*(int*)&params[36] = CountAllowed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55031);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55032);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushChat(ScriptString* chatStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55033);
			byte params[12] = { NULL };
			*(ScriptString**)params = chatStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55035);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSteamTransaction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55036);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSteamResponse(bool bAuthorized)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55037);
			byte params[4] = { NULL };
			*(bool*)params = bAuthorized;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55039);
			byte params[8] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HandlePopupComplete(int Id, ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55053);
			byte params[20] = { NULL };
			*(int*)params = Id;
			*(ScriptString**)&params[4] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NavigateSteamGold(bool bSuccess)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55058);
			byte params[4] = { NULL };
			*(bool*)params = bSuccess;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAccount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55061);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowNotification(ScriptString* Message, ScriptString* Message2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55063);
			byte params[24] = { NULL };
			*(ScriptString**)params = Message;
			*(ScriptString**)&params[12] = Message2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideNotification()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55066);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateButton(class GFxObject* Obj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55067);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HidePopup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55069);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowQueue(ScriptString* Estimate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55070);
			byte params[12] = { NULL };
			*(ScriptString**)params = Estimate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_LeftGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55073);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_JoinGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55074);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FocusLogin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55075);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_LoadMatchSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55076);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_GlobalAlert(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55078);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_KeyPressCaptured(ScriptString* KeyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55084);
			byte params[12] = { NULL };
			*(ScriptString**)params = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_PromptNewPlayerName(ScriptString* ErrorString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55086);
			byte params[12] = { NULL };
			*(ScriptString**)params = ErrorString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_PurchaseComplete(bool bSuccess, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55088);
			byte params[16] = { NULL };
			*(bool*)params = bSuccess;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_ShowReticuleBuilder(class GFxObject* Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55097);
			byte params[4] = { NULL };
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASC_HideReticuleBuilder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55099);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_SetMapLoadText(ScriptString* A, ScriptString* B, ScriptString* C, ScriptString* D, ScriptString* E, ScriptString* F, ScriptString* G, ScriptString* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55102);
			byte params[96] = { NULL };
			*(ScriptString**)params = A;
			*(ScriptString**)&params[12] = B;
			*(ScriptString**)&params[24] = C;
			*(ScriptString**)&params[36] = D;
			*(ScriptString**)&params[48] = E;
			*(ScriptString**)&params[60] = F;
			*(ScriptString**)&params[72] = G;
			*(ScriptString**)&params[84] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundSkillBar(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55139);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSoundPerkType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55142);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShowingPopupDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(55166);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
