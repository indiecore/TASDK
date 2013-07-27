#pragma once
#include "TribesGame.TrPaperDoll.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.CameraActor.h"
#include "TribesGame.AlienFXManager.h"
#include "TribesGame.TrSeqAct_PlayVGSCommand.h"
#include "TribesGame.TrDeployable_MotionSensor.h"
#include "TribesGame.TrEquipInterface.h"
#include "Engine.MaterialEffect.h"
#include "TribesGame.TrVGSCommandList.h"
#include "TribesGame.TrStrings.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "TribesGame.TrInventoryHelper.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Core.Object.h"
#include "TribesGame.TrStatsInterface.h"
#include "TribesGame.TrAccoladeManager.h"
#include "TribesGame.TrSeqAct_GiveCredits.h"
#include "Engine.Actor.h"
#include "TribesGame.TrProjectile.h"
#include "UTGame.UTWeapon.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrChatConsoleCommands.h"
#include "TribesGame.TrFlagBase.h"
#include "TribesGame.TrObject.h"
#include "TribesGame.TrWeatherVolume.h"
#include "TribesGame.TrPowerGenerator.h"
#include "TribesGame.TrCTFBase.h"
#include "TribesGame.TrCamera_SpectatorBookmark.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrStation.h"
#include "TribesGame.TrContentLoader.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrFlagCTF.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.CameraShake.h"
#include "UDKBase.UDKEmitCameraEffect.h"
#include "TribesGame.TrCameraModifier_CameraShake.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrAnnouncer.h"
#include "TribesGame.TrMusicManager.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrVehicleStation.h"
#include "TribesGame.TrDevice.h"
#include "PlatformCommon.TgSupportCommands.h"
#include "Engine.PlayerInput.h"
#include "TribesGame.TrPlayerInput_Spectator.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.TrSeqAct_GiveAccolade.h"
#include "TribesGame.TrSeqAct_RefreshInventory.h"
#include "UTGame.UTTeamInfo.h"
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
	class TrPlayerController : public UTPlayerController
	{
	public:
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
		static const auto ITEM_ARMOR_MOD_PATHFINDER_1 = 7836;
		static const auto ITEM_ARMOR_MOD_SENTINEL_1 = 7837;
		static const auto ITEM_ARMOR_MOD_INFILTRATOR_1 = 7838;
		static const auto ITEM_ARMOR_MOD_SOLDIER_1 = 7839;
		static const auto ITEM_ARMOR_MOD_TECHNICIAN_1 = 7840;
		static const auto ITEM_ARMOR_MOD_RAIDER_1 = 7841;
		static const auto ITEM_ARMOR_MOD_JUGGERNAUT_1 = 7842;
		static const auto ITEM_ARMOR_MOD_DOOMBRINGER_1 = 7843;
		static const auto ITEM_ARMOR_MOD_BRUTE_1 = 7844;
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
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_1 = 8700;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_2 = 8701;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_100X_3 = 8702;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_1 = 8703;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_2 = 8704;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_100X_3 = 8705;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_1 = 8706;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_2 = 8707;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIR_DEPLOYABLE_3 = 8708;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_1 = 8709;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_2 = 8710;
		static const auto ITEM_UPGRADE_TECHNICIAN_TC24_3 = 8711;
		static const auto ACTIVITY_PATHFINDER_PRIMARY_LIGHTSPINFUSOR_100X = 265;
		static const auto ACTIVITY_TECHNICIAN_BELT_REPAIR_DEPLOYABLE = 266;
		static const auto ACTIVITY_SOLDIER_PRIMARY_SPINFUSOR_100X = 264;
		static const auto ACTIVITY_TECHNICIAN_PRIMARY_TC24 = 267;
		static const auto ACTIVITY_SENTINEL_PRIMARY_SAP20 = 268;
		static const auto ACTIVITY_SENTINEL_SECONDARY_ACCURIZEDSHOTGUN = 269;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_1 = 8418;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_2 = 8419;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_MKD_3 = 8420;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_1 = 8421;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_2 = 8422;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_3 = 8423;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_MKD_4 = 8424;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_1 = 8425;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_2 = 8426;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_3 = 8427;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_MKD_4 = 8428;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_1 = 8429;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_2 = 8430;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_3 = 8431;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_MKD_4 = 8432;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_1 = 8433;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_2 = 8434;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_3 = 8435;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_MKD_4 = 8436;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_1 = 8437;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_2 = 8438;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_MKD_3 = 8439;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_1 = 8440;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_2 = 8441;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_MKD_3 = 8442;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_1 = 8443;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_2 = 8444;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_3 = 8445;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_MKD_4 = 8446;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_1 = 8447;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_2 = 8448;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_MKD_3 = 8449;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_1 = 8657;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_2 = 8658;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYTWINFUSOR_3 = 8659;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_1 = 8450;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_2 = 8451;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_MKD_3 = 8452;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_1 = 8453;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_2 = 8454;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_MKD_3 = 8455;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_1 = 8456;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_2 = 8457;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_MKD_3 = 8458;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_1 = 8459;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_2 = 8460;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_MKD_3 = 8461;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_1 = 8462;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_2 = 8463;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_MKD_3 = 8464;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_1 = 8465;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_2 = 8466;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_3 = 8467;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_MKD_4 = 8468;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_1 = 8469;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_2 = 8470;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_MKD_3 = 8471;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_1 = 8472;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_2 = 8473;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_MKD_3 = 8474;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_1 = 8475;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_2 = 8476;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_3 = 8477;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_MKD_4 = 8478;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_1 = 8479;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_2 = 8480;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_MKD_3 = 8481;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_1 = 8482;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_2 = 8483;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_MKD_3 = 8484;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_1 = 8486;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_2 = 8487;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_3 = 8488;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_MKD_4 = 8489;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_1 = 8490;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_2 = 8491;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_MKD_3 = 8492;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_1 = 8493;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_2 = 8494;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_MKD_3 = 8495;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_1 = 8496;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_2 = 8497;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_MKD_3 = 8498;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_1 = 8499;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_2 = 8500;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_MKD_3 = 8501;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_1 = 8502;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_2 = 8503;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_MKD_3 = 8504;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_1 = 8505;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_2 = 8506;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_MKD_3 = 8507;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_1 = 7850;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_2 = 7851;
		static const auto ITEM_UPGRADE_PATHFINDER_BOLTLAUNCHER_3 = 7852;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_1 = 7855;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_2 = 7860;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTSPINFUSOR_3 = 7857;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_1 = 8277;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_2 = 8278;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTTWINFUSOR_3 = 8279;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_1 = 7927;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_2 = 7929;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_3 = 7930;
		static const auto ITEM_UPGRADE_SENTINEL_BXT1SNIPERRIFLE_4 = 7931;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_1 = 7932;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_2 = 7933;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_3 = 7934;
		static const auto ITEM_UPGRADE_SENTINEL_PHASERIFLE_4 = 7935;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_1 = 8305;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_2 = 8306;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_3 = 8307;
		static const auto ITEM_UPGRADE_SENTINEL_SAP20_4 = 8308;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_1 = 7960;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_2 = 7961;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_3 = 7962;
		static const auto ITEM_UPGRADE_INFILTRATOR_RHINOSMG_4 = 7963;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_1 = 7964;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_2 = 7965;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHLIGHTSPINFUSOR_3 = 7966;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_1 = 8298;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_2 = 8299;
		static const auto ITEM_UPGRADE_INFILTRATOR_REMOTEARXBUSTER_3 = 8300;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_1 = 7985;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_2 = 7986;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_3 = 7987;
		static const auto ITEM_UPGRADE_SOLDIER_ASSAULTRIFLE_4 = 7988;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_1 = 7992;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_2 = 7993;
		static const auto ITEM_UPGRADE_SOLDIER_SPINFUSOR_3 = 7994;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_1 = 8316;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_2 = 8317;
		static const auto ITEM_UPGRADE_SOLDIER_TWINFUSOR_3 = 8318;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_1 = 8012;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_2 = 8013;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_3 = 8014;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCN4SMG_4 = 8015;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_1 = 8016;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_2 = 8017;
		static const auto ITEM_UPGRADE_TECHNICIAN_THUMPER_3 = 8018;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_1 = 8045;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_2 = 8046;
		static const auto ITEM_UPGRADE_RAIDER_GRENADELAUNCHER_3 = 8047;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_1 = 8042;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_2 = 8043;
		static const auto ITEM_UPGRADE_RAIDER_ARXBUSTER_3 = 8044;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_1 = 8070;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_2 = 8071;
		static const auto ITEM_UPGRADE_JUGGERNAUT_FUSIONMORTAR_3 = 8072;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_1 = 8073;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_2 = 8074;
		static const auto ITEM_UPGRADE_JUGGERNAUT_MIRVLAUNCHER_3 = 8075;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_1 = 8280;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_2 = 8281;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LR1MORTAR_3 = 8282;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_1 = 8100;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_2 = 8101;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_3 = 8102;
		static const auto ITEM_UPGRADE_DOOMBRINGER_CHAINGUN_4 = 8103;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_1 = 8104;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_2 = 8105;
		static const auto ITEM_UPGRADE_DOOMBRINGER_HEAVYBOLTLAUNCHER_3 = 8106;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_1 = 8124;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_2 = 8125;
		static const auto ITEM_UPGRADE_BRUTE_HEAVYSPINFUSOR_3 = 8126;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_1 = 8292;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_2 = 8293;
		static const auto ITEM_UPGRADE_BRUTE_PLASMACANNON_3 = 8294;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_1 = 8386;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_2 = 8387;
		static const auto ITEM_UPGRADE_BRUTE_SPIKELAUNCHER_3 = 8388;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_1 = 7861;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_2 = 7862;
		static const auto ITEM_UPGRADE_PATHFINDER_SHOTGUN_3 = 7863;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_1 = 7866;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_2 = 7867;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_3 = 7868;
		static const auto ITEM_UPGRADE_PATHFINDER_LIGHTASSAULTRIFLE_4 = 7869;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_1 = 8265;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_2 = 8266;
		static const auto ITEM_UPGRADE_PATHFINDER_BUCKLER_3 = 8267;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_1 = 7936;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_2 = 7937;
		static const auto ITEM_UPGRADE_SENTINEL_NOVABLASTER_3 = 7938;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_1 = 7939;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_2 = 7940;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_3 = 7941;
		static const auto ITEM_UPGRADE_SENTINEL_FALCONAUTOPISTOL_4 = 7942;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_1 = 8258;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_2 = 8259;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_3 = 8260;
		static const auto ITEM_UPGRADE_SENTINEL_ACCURIZEDSHOTGUN_4 = 8261;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_1 = 7967;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_2 = 7968;
		static const auto ITEM_UPGRADE_INFILTRATOR_SN7PISTOL_3 = 7969;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_1 = 8312;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_2 = 8313;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_3 = 8314;
		static const auto ITEM_UPGRADE_INFILTRATOR_THROWINGKNIVES_4 = 8315;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_1 = 7995;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_2 = 7996;
		static const auto ITEM_UPGRADE_SOLDIER_EAGLEPISTOL_3 = 7997;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_1 = 7989;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_2 = 7990;
		static const auto ITEM_UPGRADE_SOLDIER_THUMPERD_3 = 7991;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_1 = 8295;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_2 = 8296;
		static const auto ITEM_UPGRADE_SOLDIER_PLASMAGUN_3 = 8297;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_1 = 8019;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_2 = 8020;
		static const auto ITEM_UPGRADE_TECHNICIAN_REPAIRTOOLSD_3 = 8021;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_1 = 8022;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_2 = 8023;
		static const auto ITEM_UPGRADE_TECHNICIAN_SAWEDOFFSHOTGUN_3 = 8024;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_1 = 8025;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_2 = 8026;
		static const auto ITEM_UPGRADE_TECHNICIAN_SPARROWPISTOL_3 = 8027;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_1 = 8048;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_2 = 8049;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_3 = 8050;
		static const auto ITEM_UPGRADE_RAIDER_NJ4SMG_4 = 8051;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_1 = 8289;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_2 = 8290;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_3 = 8291;
		static const auto ITEM_UPGRADE_RAIDER_NJ5SMG_4 = 8304;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_1 = 8076;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_2 = 8077;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SPINFUSORD_3 = 8078;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_1 = 8079;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_2 = 8080;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_3 = 8081;
		static const auto ITEM_UPGRADE_JUGGERNAUT_LMG_4 = 8082;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_1 = 8107;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_2 = 8108;
		static const auto ITEM_UPGRADE_DOOMBRINGER_SABERLAUNCHER_3 = 8109;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_1 = 8301;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_2 = 8302;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ROCKETLAUNCHER_3 = 8303;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_1 = 8127;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_2 = 8128;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_3 = 8129;
		static const auto ITEM_UPGRADE_BRUTE_AUTOSHOTGUN_4 = 8130;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_1 = 8131;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_2 = 8132;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_3 = 8133;
		static const auto ITEM_UPGRADE_BRUTE_NOVACOLT_4 = 8134;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_1 = 7881;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_2 = 7882;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTNITRON_3 = 7883;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_1 = 7888;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_2 = 7889;
		static const auto ITEM_UPGRADE_PATHFINDER_GRENADE_ST_3 = 7890;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_1 = 8274;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_2 = 8275;
		static const auto ITEM_UPGRADE_PATHFINDER_IMPACTBOMBLETS_3 = 8276;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_1 = 7943;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_2 = 7944;
		static const auto ITEM_UPGRADE_SENTINEL_CLAYMORE_3 = 7945;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_1 = 7946;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_2 = 7947;
		static const auto ITEM_UPGRADE_SENTINEL_GRENADEXL_3 = 7948;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_1 = 8262;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_2 = 8263;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOREDCLAYMORE_3 = 8264;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_1 = 7970;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_2 = 7971;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_3 = 7972;
		static const auto ITEM_UPGRADE_INFILTRATOR_STICKYGRENADE_4 = 7973;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_1 = 7974;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_2 = 7975;
		static const auto ITEM_UPGRADE_INFILTRATOR_PRISMMINES_3 = 7976;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_1 = 8286;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_2 = 8287;
		static const auto ITEM_UPGRADE_INFILTRATOR_NINJASMOKE_3 = 8288;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_1 = 7998;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_2 = 7999;
		static const auto ITEM_UPGRADE_SOLDIER_FRAGGRENADEXL_3 = 8000;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_1 = 8001;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_2 = 8002;
		static const auto ITEM_UPGRADE_SOLDIER_APGRENADE_3 = 8003;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_1 = 8227;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_2 = 8228;
		static const auto ITEM_UPGRADE_SOLDIER_PROXIMITYGRENADE_3 = 8229;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_1 = 8028;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_2 = 8029;
		static const auto ITEM_UPGRADE_TECHNICIAN_TCNGGRENADE_3 = 8030;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_1 = 8031;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_2 = 8032;
		static const auto ITEM_UPGRADE_TECHNICIAN_MOTIONALARM_3 = 8033;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_1 = 8052;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_2 = 8053;
		static const auto ITEM_UPGRADE_RAIDER_EMPGRENADE_3 = 8054;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_1 = 8055;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_2 = 8056;
		static const auto ITEM_UPGRADE_RAIDER_WHITEOUTGRENADE_3 = 8057;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_1 = 8283;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_2 = 8284;
		static const auto ITEM_UPGRADE_RAIDER_MIRVGRENADE_3 = 8285;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_1 = 8083;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_2 = 8084;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEAVYAPGRENADE_3 = 8085;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_1 = 8086;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_2 = 8087;
		static const auto ITEM_UPGRADE_JUGGERNAUT_DISKTOSS_3 = 8088;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_1 = 8110;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_2 = 8111;
		static const auto ITEM_UPGRADE_DOOMBRINGER_GRENADE_3 = 8112;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_1 = 8113;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_2 = 8114;
		static const auto ITEM_UPGRADE_DOOMBRINGER_MINES_3 = 8115;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_1 = 8135;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_2 = 8136;
		static const auto ITEM_UPGRADE_BRUTE_FRACTALGRENADE_3 = 8137;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_1 = 8138;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_2 = 8139;
		static const auto ITEM_UPGRADE_BRUTE_STICKYGRENADE_3 = 8140;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_1 = 7871;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_2 = 7872;
		static const auto ITEM_UPGRADE_PATHFINDER_ENERGYRECHARGEPACK_3 = 7873;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_1 = 7876;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_2 = 7877;
		static const auto ITEM_UPGRADE_PATHFINDER_JUMPPACK_3 = 7878;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_1 = 7949;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_2 = 7950;
		static const auto ITEM_UPGRADE_SENTINEL_DROPJAMMER_3 = 7951;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_1 = 7952;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_2 = 7953;
		static const auto ITEM_UPGRADE_SENTINEL_ENERGYRECHARGEPACK_3 = 7954;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_1 = 7977;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_2 = 7978;
		static const auto ITEM_UPGRADE_INFILTRATOR_STEALTHPACK_3 = 7979;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_1 = 8271;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_2 = 8272;
		static const auto ITEM_UPGRADE_INFILTRATOR_HIGHSPEEDSTEALTH_3 = 8273;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_1 = 8004;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_2 = 8005;
		static const auto ITEM_UPGRADE_SOLDIER_ENERGYPACK_3 = 8006;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_1 = 8224;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_2 = 8225;
		static const auto ITEM_UPGRADE_SOLDIER_UTILITYPACK_3 = 8226;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_1 = 8034;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_2 = 8035;
		static const auto ITEM_UPGRADE_TECHNICIAN_LIGHTTURRET_3 = 8036;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_1 = 8268;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_2 = 8269;
		static const auto ITEM_UPGRADE_TECHNICIAN_EXRTURRET_3 = 8270;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_1 = 8058;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_2 = 8059;
		static const auto ITEM_UPGRADE_RAIDER_SHIELDPACK_3 = 8060;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_1 = 8061;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_2 = 8062;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_3 = 8063;
		static const auto ITEM_UPGRADE_RAIDER_JAMMERPACK_4 = 8064;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_1 = 8089;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_2 = 8090;
		static const auto ITEM_UPGRADE_JUGGERNAUT_HEALTHREGENPACK_3 = 8091;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_1 = 8092;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_2 = 8093;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ENERGYPACK_3 = 8094;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_1 = 8309;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_2 = 8310;
		static const auto ITEM_UPGRADE_JUGGERNAUT_SURVIVALPACK_3 = 8311;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_1 = 8116;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_2 = 8117;
		static const auto ITEM_UPGRADE_DOOMBRINGER_FORCEFIELD_3 = 8118;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_1 = 8141;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_2 = 8142;
		static const auto ITEM_UPGRADE_BRUTE_ENERGYPACK_3 = 8143;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_1 = 8144;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_2 = 8145;
		static const auto ITEM_UPGRADE_BRUTE_SHIELDPACK_3 = 8146;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_1 = 7893;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_2 = 7894;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_3 = 7895;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_4 = 7896;
		static const auto ITEM_UPGRADE_PATHFINDER_ARMOR_5 = 7897;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_1 = 7955;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_2 = 7956;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_3 = 7957;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_4 = 7958;
		static const auto ITEM_UPGRADE_SENTINEL_ARMOR_5 = 7959;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_1 = 7980;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_2 = 7981;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_3 = 7982;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_4 = 7983;
		static const auto ITEM_UPGRADE_INFILTRATOR_ARMOR_5 = 7984;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_1 = 8007;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_2 = 8008;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_3 = 8009;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_4 = 8010;
		static const auto ITEM_UPGRADE_SOLDIER_ARMOR_5 = 8011;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_1 = 8037;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_2 = 8038;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_3 = 8039;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_4 = 8040;
		static const auto ITEM_UPGRADE_TECHNICIAN_ARMOR_5 = 8041;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_1 = 8065;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_2 = 8066;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_3 = 8067;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_4 = 8068;
		static const auto ITEM_UPGRADE_RAIDER_ARMOR_5 = 8069;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_1 = 8095;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_2 = 8096;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_3 = 8097;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_4 = 8098;
		static const auto ITEM_UPGRADE_JUGGERNAUT_ARMOR_5 = 8099;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_1 = 8119;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_2 = 8120;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_3 = 8121;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_4 = 8122;
		static const auto ITEM_UPGRADE_DOOMBRINGER_ARMOR_5 = 8123;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_1 = 8147;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_2 = 8148;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_3 = 8149;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_4 = 8150;
		static const auto ITEM_UPGRADE_BRUTE_ARMOR_5 = 8151;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_1 = 8188;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_2 = 8189;
		static const auto ITEM_PERK_UPGRADE_BOUNTYHUNTER_3 = 8190;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_1 = 8194;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_2 = 8195;
		static const auto ITEM_PERK_UPGRADE_CLOSECOMBAT_3 = 8196;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_1 = 8173;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_2 = 8174;
		static const auto ITEM_PERK_UPGRADE_EGOCENTRIC_3 = 8175;
		static const auto ITEM_PERK_UPGRADE_LOOTER_1 = 8185;
		static const auto ITEM_PERK_UPGRADE_LOOTER_2 = 8186;
		static const auto ITEM_PERK_UPGRADE_LOOTER_3 = 8187;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_1 = 8215;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_2 = 8216;
		static const auto ITEM_PERK_UPGRADE_MECHANIC_3 = 8217;
		static const auto ITEM_PERK_UPGRADE_PILOT_1 = 8179;
		static const auto ITEM_PERK_UPGRADE_PILOT_2 = 8180;
		static const auto ITEM_PERK_UPGRADE_PILOT_3 = 8181;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_1 = 8200;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_2 = 8201;
		static const auto ITEM_PERK_UPGRADE_POTENTIALENERGY_3 = 8202;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_1 = 8209;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_2 = 8210;
		static const auto ITEM_PERK_UPGRADE_QUICKDRAW_3 = 8211;
		static const auto ITEM_PERK_UPGRADE_REACH_1 = 8152;
		static const auto ITEM_PERK_UPGRADE_REACH_2 = 8171;
		static const auto ITEM_PERK_UPGRADE_REACH_3 = 8172;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_1 = 8176;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_2 = 8177;
		static const auto ITEM_PERK_UPGRADE_SAFEFALL_3 = 8178;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_1 = 8212;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_2 = 8213;
		static const auto ITEM_PERK_UPGRADE_SAFETYTHIRD_3 = 8214;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_1 = 8206;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_2 = 8207;
		static const auto ITEM_PERK_UPGRADE_STEALTHY_3 = 8208;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_1 = 8197;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_2 = 8198;
		static const auto ITEM_PERK_UPGRADE_SUPERHEAVY_3 = 8199;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_1 = 8191;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_2 = 8192;
		static const auto ITEM_PERK_UPGRADE_SURVIVALIST_3 = 8193;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_1 = 8203;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_2 = 8204;
		static const auto ITEM_PERK_UPGRADE_ULTRACAPACITOR_3 = 8205;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_1 = 8182;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_2 = 8183;
		static const auto ITEM_PERK_UPGRADE_WHEELDEAL_3 = 8184;
		static const auto ITEM_PERK_UPGRADE_RAGE_1 = 8236;
		static const auto ITEM_PERK_UPGRADE_RAGE_2 = 8237;
		static const auto ITEM_PERK_UPGRADE_RAGE_3 = 8238;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_1 = 8233;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_2 = 8234;
		static const auto ITEM_PERK_UPGRADE_SONICPUNCH_3 = 8235;
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
		static const auto ACTIVITY_ARMOR_MOD_BRUTE_1 = 183;
		static const auto ACTIVITY_ARMOR_MOD_DOOMBRINGER_1 = 184;
		static const auto ACTIVITY_ARMOR_MOD_INFILTRATOR_1 = 185;
		static const auto ACTIVITY_ARMOR_MOD_JUGGERNAUT_1 = 186;
		static const auto ACTIVITY_ARMOR_MOD_PATHFINDER_1 = 187;
		static const auto ACTIVITY_ARMOR_MOD_RAIDER_1 = 188;
		static const auto ACTIVITY_ARMOR_MOD_SENTINEL_1 = 189;
		static const auto ACTIVITY_ARMOR_MOD_TECHNICIAN_1 = 190;
		static const auto ACTIVITY_ARMOR_MOD_SOLDIER_1 = 191;
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
		struct TrCameraShakeInfo
		{
		public:
			ADD_STRUCT(ScriptName, ShakeName, 4)
			ADD_OBJECT(CameraShake, Shake, 0)
		};
		struct VGSAudioCommand
		{
		public:
			ADD_OBJECT(SoundCue, QueuedSoundCue, 8)
			ADD_OBJECT(TrPlayerReplicationInfo, VGSInstigator, 0)
		};
		struct SpectatorKeybindViewTargetMap
		{
		public:
			ADD_OBJECT(Actor, ViewTarget, 24)
			ADD_STRUCT(Input::KeyBind, KeyBinding, 0)
		};
		struct PendingSkin
		{
		public:
			ADD_STRUCT(int, skinId, 4)
			ADD_OBJECT(TrPlayerReplicationInfo, TrPRI, 0)
		};
		ADD_BOOL(m_bShowHUDCracks, 2188, 0x100000)
		ADD_OBJECT(TrEquipInterface, m_TrEquipInterface, 3376)
		ADD_BOOL(m_bShowSpectatorHUD, 2184, 0x10000000)
		ADD_BOOL(m_bShowSpectatorControls, 2184, 0x8000000)
		ADD_BOOL(m_bShowHUDVisor, 2188, 0x100)
		ADD_BOOL(m_bShowHUDHealthBar, 2188, 0x80)
		ADD_BOOL(m_bShowHUDHeroText, 2188, 0x2000)
		ADD_BOOL(m_bShowHUDKillbox, 2188, 0x800)
		ADD_BOOL(m_bShowHUDCombatLog, 2188, 0x400)
		ADD_BOOL(m_bShowHUDSkiBars, 2188, 0x10000)
		ADD_BOOL(m_bShowHUDCredits, 2188, 0x8)
		ADD_BOOL(m_bShowHUDReticule, 2188, 0x4)
		ADD_BOOL(m_bShowHUDChat, 2188, 0x200)
		ADD_BOOL(m_bShowHUDPromptPanel, 2188, 0x4000)
		ADD_BOOL(m_bShowHUDDeathcam, 2188, 0x1000)
		ADD_BOOL(m_bShowHUDRespawnTimer, 2188, 0x8000)
		ADD_STRUCT(float, r_fRespawnTime, 2372)
		ADD_BOOL(m_bIsRovingSpectating, 2184, 0x20000000)
		ADD_BOOL(m_bViewThroughDeathCamera, 2184, 0x400000)
		ADD_OBJECT(AlienFXManager, AlienFX, 3344)
		ADD_BOOL(EnableAlienFX, 2188, 0x800000)
		ADD_BOOL(m_bShowHUDScores, 2188, 0x40)
		ADD_STRUCT(int, m_nLastDamagerUpgradeLevel, 2396)
		ADD_STRUCT(int, m_nLastDamagerHealthPercent, 2392)
		ADD_OBJECT(TrStrings, Strings, 3428)
		ADD_OBJECT(TrInventoryHelper, m_TrInventoryHelper, 3380)
		ADD_BOOL(m_bShowHUDBadges, 2188, 0x20)
		ADD_BOOL(m_bShowHUDAccolades, 2188, 0x10)
		ADD_BOOL(r_bNeedTeam, 2184, 0x8000)
		ADD_BOOL(r_bNeedLoadout, 2184, 0x10000)
		ADD_BOOL(r_bDailyCompleted, 2184, 0x2000000)
		ADD_STRUCT(int, m_RequestedTeam, 2240)
		ADD_BOOL(bAutoRevertSetting, 2188, 0x2000000)
		ADD_STRUCT(float, m_fLastHitEnemyTime, 2356)
		ADD_OBJECT(TrPlayerController, m_LastKilledBy, 2380)
		ADD_STRUCT(byte, r_nHitEnemyHeadshot, 2326)
		ADD_BOOL(m_bAllowSimulatedProjectiles, 2188, 0x400000)
		ADD_BOOL(c_bPressingZoomButton, 2184, 0x200)
		ADD_OBJECT(TrHelpTextManager, m_HelpTextManager, 2944)
		ADD_STRUCT(Rotator, m_rCurrentKickbackDirection, 2220)
		ADD_OBJECT(MaterialEffect, m_ZoomedEffect, 2340)
		ADD_OBJECT(TrStatsInterface, Stats, 3144)
		ADD_OBJECT(TrAccoladeManager, m_AccoladeManager, 2348)
		ADD_STRUCT(Vector, m_vDeathCamOffset, 3112)
		ADD_STRUCT(float, m_fDeathCameraCurrentScale, 3104)
		ADD_STRUCT(float, m_fDeathCameraInnerScale, 3100)
		ADD_STRUCT(float, m_fDeathCameraInterpSpeed, 3108)
		ADD_OBJECT(ScriptClass, m_OldPossessedFamilyInfo, 2936)
		ADD_STRUCT(int, m_BeginPlayedTime, 2416)
		ADD_BOOL(m_bPressingJetpack, 2184, 0x4)
		ADD_OBJECT(Actor, m_LastDamagedBy, 2388)
		ADD_STRUCT(int, FriendlyFireDamage, 3412)
		ADD_STRUCT(float, m_fLastFlagGrabTimestamp, 3080)
		ADD_BOOL(m_bShowHUDFriendColoring, 2188, 0x20000)
		ADD_BOOL(m_bEjectedFromVehicle, 2188, 0x10000000)
		ADD_BOOL(m_bLastDeathWasUserSuicide, 2184, 0x200000)
		ADD_STRUCT(int, FriendlyFireKills, 3408)
		ADD_STRUCT(UTWeapon::EZoomState, m_ZoomState, 2324)
		ADD_STRUCT(float, m_fFreeCamYawOffset, 3024)
		ADD_STRUCT(float, m_fFreeCamPitchOffset, 3028)
		ADD_STRUCT(float, m_fCallInCooldown, 3328)
		ADD_STRUCT(byte, r_nCallinCooldownFlash, 2328)
		ADD_OBJECT(TrChatConsoleCommands, m_PlayerCommands, 3324)
		ADD_STRUCT(ScriptArray<TrObject::TrEventCredits>, m_EventCreditMap, 2292)
		ADD_STRUCT(ScriptArray<TrPlayerController::TrCameraShakeInfo>, m_CameraShakes, 2432)
		ADD_STRUCT(ScriptArray<class TrWeatherVolume*>, m_CurrentWeatherVolumes, 2452)
		ADD_STRUCT(ScriptArray<float>, m_fLastBroadcastTimes, 3040)
		ADD_STRUCT(ScriptArray<class Actor*>, m_PotentialSeekingTargets, 3064)
		ADD_STRUCT(ScriptArray<class TrProjectile*>, m_ProjectilesNeedingTethering, 3084)
		ADD_STRUCT(ScriptArray<TrPlayerController::VGSAudioCommand>, m_VGSAudioCommands, 3160)
		ADD_STRUCT(ScriptArray<class CameraActor*>, m_SpectatorCameraBookmarks, 3176)
		ADD_STRUCT(ScriptArray<class TrPowerGenerator*>, m_SpectatorGenerators, 3188)
		ADD_STRUCT(ScriptArray<class TrCTFBase*>, m_SpectatorFlagStands, 3200)
		ADD_STRUCT(ScriptArray<class TrFlagBase*>, m_SpectatorFlags, 3212)
		ADD_STRUCT(ScriptArray<class TrVehicle*>, m_SpectatorVehicles, 3224)
		ADD_STRUCT(ScriptArray<TrPlayerController::SpectatorKeybindViewTargetMap>, m_SpectatorTransientKeybinds, 3312)
		ADD_STRUCT(ScriptArray<ScriptClass*>, m_CachedPendingClassDeviceContentData, 3352)
		ADD_STRUCT(ScriptArray<ScriptClass*>, m_PendingLoadoutDeviceClasses, 3364)
		ADD_STRUCT(ScriptArray<TrPlayerController::PendingSkin>, m_Pending3PSkins, 3384)
		ADD_STRUCT(ScriptArray<TrPlayerController::PendingSkin>, m_Pending1PSkins, 3396)
		ADD_STRUCT(float, fSniperRespawnDelay, 3424)
		ADD_STRUCT(float, m_fLastSuicideTimestamp, 3420)
		ADD_STRUCT(int, VGSClassId, 3416)
		ADD_OBJECT(TrContentLoader, c_ContentLoader, 3348)
		ADD_STRUCT(int, m_WhisperFilter, 3340)
		ADD_STRUCT(Rotator, r_rViewTargetViewRotation, 3300)
		ADD_STRUCT(Vector, r_vViewTargetViewLocation, 3288)
		ADD_OBJECT(PlayerReplicationInfo, r_ViewTargetVehiclePassengerPRI, 3284)
		ADD_OBJECT(PlayerReplicationInfo, r_ViewTargetVehicleDriverPRI, 3280)
		ADD_STRUCT(float, r_fViewTargetVehicleMaxPowerPool, 3276)
		ADD_STRUCT(float, r_fViewTargetVehicleCurrentPowerPool, 3272)
		ADD_STRUCT(int, r_nViewTargetPackAmmoCount, 3268)
		ADD_STRUCT(int, r_nViewTargetOffhandAmmoCount, 3264)
		ADD_STRUCT(int, r_nViewTargetSecondaryMaxAmmoCount, 3260)
		ADD_STRUCT(int, r_nViewTargetPrimaryMaxAmmoCount, 3256)
		ADD_STRUCT(int, r_nViewTargetSecondaryAmmoCount, 3252)
		ADD_STRUCT(int, r_nViewTargetPrimaryAmmoCount, 3248)
		ADD_STRUCT(float, r_fViewTargetMaxPowerPool, 3244)
		ADD_STRUCT(float, r_fViewTargetCurrentPowerpool, 3240)
		ADD_STRUCT(float, r_fViewTargetNextRegenTimestamp, 3236)
		ADD_STRUCT(int, m_nMaxVGSSoundChannels, 3172)
		ADD_STRUCT(int, m_TeamRabbitAssistCredit, 3156)
		ADD_STRUCT(int, m_TeamAssistCredit, 3152)
		ADD_STRUCT(int, m_DamageNeededForCredit, 3148)
		ADD_OBJECT(MaterialEffect, m_RoundEndedME, 3140)
		ADD_STRUCT(float, m_fDeterminationAccumulator, 3136)
		ADD_STRUCT(float, m_fDeterminationAmount, 3132)
		ADD_STRUCT(float, LoadingScreenTimeout, 3128)
		ADD_OBJECT(TrPaperDoll, m_PaperDoll, 3124)
		ADD_STRUCT(float, m_fDeathCameraOuterScale, 3096)
		ADD_STRUCT(float, m_fUserSuicideTimePenalty, 3076)
		ADD_STRUCT(float, m_fSpamLockoutTimeStamp, 3060)
		ADD_STRUCT(float, m_fLockoutFromSpamTime, 3056)
		ADD_STRUCT(float, m_fMessageSpamTime, 3052)
		ADD_STRUCT(int, m_fMaxBroadcastSpamCount, 3036)
		ADD_STRUCT(float, m_fLastSpotTargetTime, 3032)
		ADD_STRUCT(int, s_nNewPlayerAssistPoints, 3020)
		ADD_STRUCT(int, s_nMaxNewPlayerAssistPoints, 3016)
		ADD_STRUCT(float, s_fNewPlayerAssistMitigateCauseDamageMultiplier, 3012)
		ADD_STRUCT(float, s_fNewPlayerAssistMitigateTakeDamageMultiplier, 3008)
		ADD_STRUCT(float, m_fFlagGrabSpeedRecord, 3004)
		ADD_STRUCT(float, m_fFlagCapSpeedRecord, 3000)
		ADD_STRUCT(float, m_fSkiSpeedRecord, 2996)
		ADD_STRUCT(float, m_fSpeedCheckTotal, 2992)
		ADD_STRUCT(float, m_fLastSpeedCheckCount, 2988)
		ADD_STRUCT(float, m_fLastSpeedCheckTime, 2984)
		ADD_STRUCT(float, m_fSpeedCheckInterval, 2980)
		ADD_STRUCT(float, m_fHideJetpackHelpTextDistanceThresholdSq, 2976)
		ADD_STRUCT(float, m_fTotalDistanceJetpackedSq, 2972)
		ADD_STRUCT(float, m_fHideSkiHelpTextDistanceThresholdSq, 2968)
		ADD_STRUCT(float, m_fLastDistanceSkiedSq, 2964)
		ADD_STRUCT(float, m_fLastDistanceCheckTime, 2960)
		ADD_STRUCT(float, m_fDistanceCheckInterval, 2956)
		ADD_STRUCT(float, m_fTotalDistanceSkiedSq, 2952)
		ADD_OBJECT(ScriptClass, m_HelpTextManagerClass, 2948)
		ADD_OBJECT(TrVehicle, m_LastAcknowledgedVehicle, 2940)
		ADD_STRUCT(int, m_ActiveClassId, 2932)
		ADD_STRUCT(int, m_LastVGSUse, 2928)
		ADD_STRUCT(float, m_fIdleCheckTimer, 2924)
		ADD_STRUCT(float, m_RoundEndedVZeroSpeed, 2920)
		ADD_STRUCT(float, m_RoundEndedPPTarget, 2916)
		ADD_STRUCT(float, m_RoundEndedPPAlpha, 2912)
		ADD_STRUCT(float, m_RoundEndedPPInterpSpeed, 2908)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, m_RoundEndedPPSettings, 2688)
		ADD_STRUCT(PostProcessVolume::PostProcessSettings, m_DefaultPPSettings, 2468)
		ADD_STRUCT(float, m_fSpeedCameraSpeedSqared, 2464)
		ADD_OBJECT(UDKEmitCameraEffect, m_WeatherCameraEffect, 2448)
		ADD_OBJECT(UDKEmitCameraEffect, m_SpeedCameraEffect, 2444)
		ADD_STRUCT(int, m_nLatestAccoladeIcon, 2428)
		ADD_OBJECT(TrCameraModifier_CameraShake, m_CameraShake, 2424)
		ADD_OBJECT(Weapon, m_LastWeaponEquipped, 2420)
		ADD_STRUCT(int, m_VehicleSeatIndex, 2412)
		ADD_STRUCT(float, m_LastPressedSkiTimeStamp, 2408)
		ADD_STRUCT(float, m_fMinActiveSkiTimeToEnableFollowthough, 2404)
		ADD_STRUCT(float, m_fSkiFollowthroughTime, 2400)
		ADD_OBJECT(Actor, r_KilledBy, 2384)
		ADD_STRUCT(float, m_LastLoadoutRequestTime, 2376)
		ADD_STRUCT(int, m_nClientSpawnTimeRemaining, 2368)
		ADD_STRUCT(int, m_nRespawnTimeRemaining, 2364)
		ADD_STRUCT(float, m_fPlayBeginTime, 2360)
		ADD_OBJECT(TrAnnouncer, m_Announcer, 2352)
		ADD_OBJECT(TrMusicManager, m_MusicManager, 2344)
		ADD_STRUCT(float, c_fHUDZoomDuration, 2336)
		ADD_STRUCT(TrPawn::WalkingDeceleration, m_CurrentDecelerationFactor, 2334)
		ADD_STRUCT(byte, m_nCallinCooldownFlashStored, 2331)
		ADD_STRUCT(byte, m_nLastHitEnemyHeadshot, 2327)
		ADD_STRUCT(byte, r_nHitEnemy, 2325)
		ADD_STRUCT(float, c_fZoomButtonPressedTimeStamp, 2320)
		ADD_STRUCT(float, m_fZoomRate, 2316)
		ADD_STRUCT(float, m_fDesiredMagnifiedZoomFOV, 2312)
		ADD_STRUCT(float, m_fDesiredZoomFOV, 2308)
		ADD_OBJECT(TrStation, m_CurrentStation, 2304)
		ADD_STRUCT(int, r_nCurrentCredits, 2288)
		ADD_OBJECT(SoundCue, m_RicochetSound3P, 2284)
		ADD_OBJECT(SoundCue, m_MissileSeekingSelfCue, 2280)
		ADD_OBJECT(SoundCue, m_MissileFiredCue, 2276)
		ADD_OBJECT(SoundCue, m_MissileLockedCue, 2272)
		ADD_OBJECT(SoundCue, m_MissileLockingCue, 2268)
		ADD_STRUCT(int, m_OverwatchTeam, 2236)
		ADD_OBJECT(CameraActor, m_OverwatchCam, 2232)
		ADD_STRUCT(Rotator, m_rKickbackAim, 2208)
		ADD_STRUCT(float, m_fLastKickbackViewTime, 2204)
		ADD_STRUCT(float, m_fKickbackViewBlendInTime, 2200)
		ADD_STRUCT(float, m_fKickbackViewBlendOutTime, 2196)
		ADD_STRUCT(float, m_fRemainingInitiatingJettingTime, 2192)
		ADD_BOOL(bWarmingUp, 2188, 0x20000000)
		ADD_BOOL(m_bAirSpeedBoundToGroundSpeed, 2188, 0x8000000)
		ADD_BOOL(m_bEnableChatFilter, 2188, 0x4000000)
		ADD_BOOL(bBlockForAcquisition, 2188, 0x1000000)
		ADD_BOOL(m_bAnimMenu, 2188, 0x200000)
		ADD_BOOL(m_bShowHUDFriendStateNotifications, 2188, 0x80000)
		ADD_BOOL(m_bShowHUDNotifications, 2188, 0x40000)
		ADD_BOOL(m_bShowHUDObjectives, 2188, 0x2)
		ADD_BOOL(m_bEnableOverheadDamageIndicators, 2188, 0x1)
		ADD_BOOL(r_bViewTargetVehicleSecondaryWeaponReady, 2184, 0x80000000)
		ADD_BOOL(r_bViewTargetVehiclePrimaryWeaponReady, 2184, 0x40000000)
		ADD_BOOL(r_bWeeklyCompleted, 2184, 0x4000000)
		ADD_BOOL(m_bIsJumpJetting, 2184, 0x1000000)
		ADD_BOOL(m_bJustJoined, 2184, 0x800000)
		ADD_BOOL(m_bMonkeyMode, 2184, 0x100000)
		ADD_BOOL(m_bJetpackHelpTextThresholdReached, 2184, 0x80000)
		ADD_BOOL(m_bSkiHelpTextThresholdReached, 2184, 0x40000)
		ADD_BOOL(m_bEnableCameraSpeedEffect, 2184, 0x20000)
		ADD_BOOL(m_bLoadoutChangeAlerted, 2184, 0x4000)
		ADD_BOOL(m_bRequestingSki, 2184, 0x2000)
		ADD_BOOL(m_bPlayerSwappedTeams, 2184, 0x1000)
		ADD_BOOL(m_bReturnTo3PAfterZoom, 2184, 0x800)
		ADD_BOOL(m_bZoomMagnified, 2184, 0x400)
		ADD_BOOL(m_bPlayCreditsSound, 2184, 0x100)
		ADD_BOOL(bWasAutoBalanced, 2184, 0x80)
		ADD_BOOL(m_bAftermathKill, 2184, 0x40)
		ADD_BOOL(m_bKickbackBlendingIn, 2184, 0x20)
		ADD_BOOL(m_bBlink, 2184, 0x10)
		ADD_BOOL(m_bJumpJet, 2184, 0x8)
		ADD_BOOL(m_bPressingJetpackButton, 2184, 0x2)
		ADD_BOOL(m_bEditorMode, 2184, 0x1)
		ADD_STRUCT(float, m_fLastWeaponSwitchTimestamp, 2180)
		ADD_OBJECT(Actor, m_aHoverActor, 2176)
		int GetLanguageFontIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53555);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool InTraining()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53578);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptClass* GetFamilyInfoFromId(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53589);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		class TrDevice* GetDeviceByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53730);
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDevice**)&params[4];
		}
		UTWeapon::EZoomState GetZoomedState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53735);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTWeapon::EZoomState*)params;
		}
		bool InRovingSpectate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53743);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsTrPlayerMuted(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54526);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetActiveClassId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(54706);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetTeamClassCount(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56812);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool RegisterPendingClass(int ClassId, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58333);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetAllowedClassCount(TrObject::TrClassType ClassType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58399);
			byte params[5] = { NULL };
			*(TrObject::TrClassType*)params = ClassType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool SendPrivateChatMessage(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58832);
			byte params[28] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool BroadcastChatMessage(TgSupportCommands::GC_CHAT_CHANNEL Channel, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59829);
			byte params[17] = { NULL };
			*(TgSupportCommands::GC_CHAT_CHANNEL*)params = Channel;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ServerRequestPickTeam(byte RequestedTeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65204);
			byte params[5] = { NULL };
			*params = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ChooseBloodEagle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65206);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ChooseDiamondSword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65209);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetVehicleCost(ScriptClass* VehicleClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65227);
			byte params[8] = { NULL };
			*(ScriptClass**)params = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetCurrentCredits()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(65231);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool IsBassBoostToggled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68991);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool AllowHelpTextToDisplay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(69957);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(71606);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float GetCurrentDetermination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72626);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetNewPlayerAssistToApply()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72751);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PlayReliableSound(class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Vector SoundLocation, bool bNoRepToRelevant)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74088);
			byte params[32] = { NULL };
			*(class SoundCue**)params = InSoundCue;
			*(bool*)&params[4] = bNotReplicated;
			*(bool*)&params[8] = bNoRepToOwner;
			*(bool*)&params[12] = bStopWhenOwnerDestroyed;
			*(Vector*)&params[16] = SoundLocation;
			*(bool*)&params[28] = bNoRepToRelevant;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendCtrlRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76203);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendGameRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76205);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestSteamPurchase()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76207);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowAdminPage(ScriptString* ServerURL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76208);
			byte params[12] = { NULL };
			*(ScriptString**)params = ServerURL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHitValidationMode(int loggingMode, int validationMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76210);
			byte params[8] = { NULL };
			*(int*)params = loggingMode;
			*(int*)&params[4] = validationMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickPlayerFromMatch(int Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76213);
			byte params[4] = { NULL };
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MainMenuIsOpen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76215);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetMenuInGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76217);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMenuToLobby()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76218);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenSummaryScreen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76219);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMenuSummaryScreen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76220);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMenuEndOfMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76221);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginExperienceTweens()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76222);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickVoteReply(bool bVote)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76223);
			byte params[4] = { NULL };
			*(bool*)params = bVote;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMenuMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76225);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetUserSelectedClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76227);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void RevertSetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76229);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMenuBack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76230);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAcquisition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76231);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceFocus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76232);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTVTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76233);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76234);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateQueueTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76235);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleWorkingGraphic(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76236);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndHotkeyBlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76238);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MutePlayer(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76239);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnmutePlayer(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76241);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HaveMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76244);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsChatFiltered(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76246);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void RequestKickVote(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76249);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76251);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76252);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenClasses()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76253);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleFriends()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76254);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76255);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76256);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClaimPromotion(ScriptString* PromoCode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76257);
			byte params[12] = { NULL };
			*(ScriptString**)params = PromoCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireUILoadSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76259);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireRefreshPage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76260);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleBassBoost(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76261);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForwardChatFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76263);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowNotification(ScriptString* Message, ScriptString* Message2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76264);
			byte params[24] = { NULL };
			*(ScriptString**)params = Message;
			*(ScriptString**)&params[12] = Message2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideNotification()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76268);
			byte params[28] = { NULL };
			*(int*)params = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76272);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76273);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleChat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76274);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushChat(ScriptString* chatStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76275);
			byte params[12] = { NULL };
			*(ScriptString**)params = chatStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bug()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76277);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void _Crash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76278);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsGameUsingSeekFreeLoading()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76279);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ResetRunaway()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76281);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearVehicleMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76282);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowVehicleMenu(int Credits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76283);
			byte params[4] = { NULL };
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleMenuOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76285);
			byte params[40] = { NULL };
			*(ScriptString**)params = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = Icon;
			*(int*)&params[32] = CountSpawned;
			*(int*)&params[36] = CountAllowed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetOnlineFriends(ScriptArray<ScriptString*>& vFriends)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76292);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)params = vFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			vFriends = *(ScriptArray<ScriptString*>*)params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76301);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitHelpTextManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76310);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncerSound(class SoundCue* AnnouncementCue, bool bPlayRightNow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76312);
			byte params[8] = { NULL };
			*(class SoundCue**)params = AnnouncementCue;
			*(bool*)&params[4] = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestAnnouncement(bool bPlayRightNow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76315);
			byte params[4] = { NULL };
			*(bool*)params = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientHearReliableSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76318);
			byte params[28] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMySaberLauncherTargetingUpdated(TrObject::EMissileLock MissileLockValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76325);
			byte params[1] = { NULL };
			*(TrObject::EMissileLock*)params = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSeekingMissileTargetingSelfEvent(int EventSwitch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76327);
			byte params[4] = { NULL };
			*(int*)params = EventSwitch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMissileIntercepted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76333);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUDNotification(ScriptString* Message, ScriptString* Message2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76334);
			byte params[24] = { NULL };
			*(ScriptString**)params = Message;
			*(ScriptString**)&params[12] = Message2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideHUDNotification()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76339);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76341);
			byte params[40] = { NULL };
			*(class SoundCue**)params = BulletWhip;
			*(Vector*)&params[4] = FireLocation;
			*(Vector*)&params[16] = FireDir;
			*(Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76349);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessCreditEvent(TrObject::TrCreditEventType EventType, bool bProxyEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76352);
			byte params[5] = { NULL };
			*(TrObject::TrCreditEventType*)params = EventType;
			*(bool*)&params[4] = bProxyEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyCredits(int Count, bool bFreeCredits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76362);
			byte params[8] = { NULL };
			*(int*)params = Count;
			*(bool*)&params[4] = bFreeCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCurrentCredits(int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76370);
			byte params[4] = { NULL };
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreditsSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76374);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateCredits(int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76376);
			byte params[4] = { NULL };
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetLatestAccoladeIconIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76378);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ClientShowAccoladeIcon(int IconIndex, ScriptString* Description, ScriptString* Points)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76381);
			byte params[28] = { NULL };
			*(int*)params = IconIndex;
			*(ScriptString**)&params[4] = Description;
			*(ScriptString**)&params[16] = Points;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientShowAccoladeText(ScriptString* Message, int ShowTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76385);
			byte params[16] = { NULL };
			*(ScriptString**)params = Message;
			*(int*)&params[12] = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetStreaks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76388);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveCredits(int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76389);
			byte params[4] = { NULL };
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerGiveCreditsCheat(int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76391);
			byte params[4] = { NULL };
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76395);
			byte params[8] = { NULL };
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76398);
			byte params[8] = { NULL };
			*(class Weapon**)params = PreviousWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReloadWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76402);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerReloadWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76409);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetCharFamily(ScriptString* FamilyClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76410);
			byte params[12] = { NULL };
			*(ScriptString**)params = FamilyClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Suicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76414);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSuicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		TrObject::EArmorType GetArmorType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76417);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::EArmorType*)params;
		}
		float GetRespawnDelayTotalTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76420);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Rotator LimitViewRotation(Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76427);
			byte params[32] = { NULL };
			*(Rotator*)params = ViewRotation;
			*(float*)&params[12] = ViewPitchMin;
			*(float*)&params[16] = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[20];
		}
		void PressedMelee()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76432);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedLaser()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedBelt()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76435);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedPack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76438);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedDeployable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76447);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShowEquip(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76448);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PressedConsoleUse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76450);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedWeaponSwitch(bool bFilterTimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76451);
			byte params[4] = { NULL };
			*(bool*)params = bFilterTimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EquipPrimary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipSecondary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76459);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76462);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateDevice(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76464);
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76470);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateLockedTarget(class Actor* LockedActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76473);
			byte params[4] = { NULL };
			*(class Actor**)params = LockedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IdentifyTeamMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76476);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76480);
			byte params[1] = { NULL };
			*params = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindValidGRI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76482);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitHUDObjects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76483);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientStartSpawnTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76484);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompletePickTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76489);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestAutoAssignTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76492);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientEndTeamSelect(int RequestedTeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76498);
			byte params[4] = { NULL };
			*(int*)params = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeTeam(ScriptString* TeamName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76501);
			byte params[12] = { NULL };
			*(ScriptString**)params = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewAPlayer(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76522);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76529);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76531);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76538);
			byte params[28] = { NULL };
			*(class Weapon**)params = W;
			*(Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		void StartWeather()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76543);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopWeather()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76545);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredWeatherVolume(bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76546);
			byte params[8] = { NULL };
			*(bool*)params = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)&params[4] = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftWeatherVolume(bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76549);
			byte params[8] = { NULL };
			*(bool*)params = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)&params[4] = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLowHealthFX()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76552);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLowHealthFX()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76555);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRechargeHealthFX()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76556);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopRechargeHealthFX()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76559);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleJetpack(bool bEnabled, bool bJump)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76560);
			byte params[8] = { NULL };
			*(bool*)params = bEnabled;
			*(bool*)&params[4] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableJetpack(bool bEnabled, bool bJump, bool bForcedOff)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76563);
			byte params[12] = { NULL };
			*(bool*)params = bEnabled;
			*(bool*)&params[4] = bJump;
			*(bool*)&params[8] = bForcedOff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76573);
			byte params[4] = { NULL };
			*(bool*)params = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76575);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformBlink()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76576);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetBlinkPackAccel(Vector& newAccel, float& BlinkPackPctEffectiveness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76577);
			byte params[16] = { NULL };
			*(Vector*)params = newAccel;
			*(float*)&params[12] = BlinkPackPctEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			newAccel = *(Vector*)params;
			BlinkPackPctEffectiveness = *(float*)&params[12];
		}
		void InitRespawnTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRespawnTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76624);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76627);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestRespawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76630);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Respawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76631);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRespawnSoonSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76632);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupGameplayEffectsOnDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76635);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCrossedOffArenaList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76638);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76670);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76675);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAirVehicleInversion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76676);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerSetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76678);
			byte params[4] = { NULL };
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76680);
			byte params[4] = { NULL };
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76682);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClientVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76684);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76686);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerVerifyVehiclePhys(float TimeStamp, float InForward, float InStrafe, float InUp, int View, Actor::RigidBodyState InRBState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76688);
			byte params[84] = { NULL };
			*(float*)params = TimeStamp;
			*(float*)&params[4] = InForward;
			*(float*)&params[8] = InStrafe;
			*(float*)&params[12] = InUp;
			*(int*)&params[16] = View;
			*(Actor::RigidBodyState*)&params[32] = InRBState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerCorrectClientPhys(float TimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76699);
			byte params[4] = { NULL };
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76703);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76705);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessRiding(Rotator ViewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76741);
			byte params[12] = { NULL };
			*(Rotator*)params = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRiding(float TimeStamp, int View)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76743);
			byte params[8] = { NULL };
			*(float*)params = TimeStamp;
			*(int*)&params[4] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToCallIn(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76795);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRequestCallInChange(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76803);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToSeat(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76806);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSwitchToSeat(byte T, class TrVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76811);
			byte params[5] = { NULL };
			*params = T;
			*(class TrVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76816);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerRequestLoadoutChange(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76827);
			byte params[8] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfo, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76844);
			byte params[16] = { NULL };
			*(ScriptClass**)params = FamilyInfo;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76852);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnVehicle(ScriptString* vehicleClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76856);
			byte params[12] = { NULL };
			*(ScriptString**)params = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RequestBuyVehicle(ScriptString* vehicleClassStr)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76858);
			byte params[12] = { NULL };
			*(ScriptString**)params = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PressedSki(bool bJump)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76862);
			byte params[4] = { NULL };
			*(bool*)params = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleasedSki()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76866);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleSki()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76869);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayReleasedSki()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76871);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBindSkiJet(int method)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76872);
			byte params[4] = { NULL };
			*(int*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleShowObjectMarkers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76874);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerStartSki(bool bJump)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76876);
			byte params[4] = { NULL };
			*(bool*)params = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStopSki()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76879);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76881);
			byte params[4] = { NULL };
			*(ScriptClass**)params = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchHud()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76884);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnKickback(Rotator KickbackAim, float KickbackBlendOutTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76886);
			byte params[16] = { NULL };
			*(Rotator*)params = KickbackAim;
			*(float*)&params[12] = KickbackBlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateKickbackDirection(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76889);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestoreMoveInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76891);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestoreMoveInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76892);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestSpawnVehicle(ScriptClass* VehicleClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76893);
			byte params[4] = { NULL };
			*(ScriptClass**)params = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76899);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PressedZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76901);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleasedZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76902);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MagnifyZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76903);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DemagnifyZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76906);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76909);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckZoomButton()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76910);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrStartZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76911);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrStopZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76918);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrEndZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76919);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetZoomDuration(bool bPlayRechargeSoundOnWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76924);
			byte params[4] = { NULL };
			*(bool*)params = bPlayRechargeSoundOnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetZoom(UTWeapon::EZoomState NewZoomState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76927);
			byte params[1] = { NULL };
			*(UTWeapon::EZoomState*)params = NewZoomState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76929);
			byte params[20] = { NULL };
			*(ScriptClass**)params = Message;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveLocalizedNagMessage(ScriptClass* Message, int Switch, float Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76935);
			byte params[12] = { NULL };
			*(ScriptClass**)params = Message;
			*(int*)&params[4] = Switch;
			*(float*)&params[8] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76939);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76942);
			byte params[4] = { NULL };
			*(int*)params = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76944);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateClientSpawnTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76947);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76948);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76969);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76970);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerDropFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76973);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76974);
			byte params[24] = { NULL };
			*(Vector*)params = POVLocation;
			*(Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)&params[12];
		}
		void ActivateFreeCam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76982);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeactivateFreeCam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76983);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetViewTargetAsOverwatch(bool bForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76984);
			byte params[4] = { NULL };
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayCameraShake(ScriptName ShakeName, float Scale, class CameraShake* SourceShake)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76987);
			byte params[16] = { NULL };
			*(ScriptName*)params = ShakeName;
			*(float*)&params[8] = Scale;
			*(class CameraShake**)&params[12] = SourceShake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76992);
			byte params[8] = { NULL };
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			*(class Actor**)&params[4] = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpeedCameraEffect(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76995);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpeedCamEffect(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76997);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPulseHUD(byte Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76999);
			byte params[1] = { NULL };
			*params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PulseShield()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77003);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTimePlayed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77004);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77011);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MatchEndSoundMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77021);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetSoundMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressHelpText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77024);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TalkVGS(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77026);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77030);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPlayerCommand(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77032);
			byte params[16] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ShowFeedbackMessage(ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77036);
			byte params[12] = { NULL };
			*(ScriptString**)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Color GetChatColor(TgSupportCommands::GC_CHAT_CHANNEL Channel, bool bSameTeam, int& ChatColorIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77047);
			byte params[13] = { NULL };
			*(TgSupportCommands::GC_CHAT_CHANNEL*)params = Channel;
			*(bool*)&params[4] = bSameTeam;
			*(int*)&params[8] = ChatColorIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ChatColorIdx = *(int*)&params[8];
			return *(Object::Color*)&params[12];
		}
		void AddChatToConsole(ScriptString* Sender, ScriptString* ChatMessage, TgSupportCommands::GC_CHAT_CHANNEL Channel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77059);
			byte params[25] = { NULL };
			*(ScriptString**)params = Sender;
			*(ScriptString**)&params[12] = ChatMessage;
			*(TgSupportCommands::GC_CHAT_CHANNEL*)&params[24] = Channel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLastTellSender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77067);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ReplyTalk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77069);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77073);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Talk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77074);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatConsole(bool bTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77078);
			byte params[4] = { NULL };
			*(bool*)params = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TalkConsole(bool bTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77082);
			byte params[4] = { NULL };
			*(bool*)params = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamTalk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77087);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77090);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77092);
			byte params[16] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void WarnPlayerAboutSpam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77095);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginVGS()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77096);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpotTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77098);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestVGSContextCommand(TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation, class Actor* SpottedActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77102);
			byte params[10] = { NULL };
			*(TrVGSCommandList::EVGSContextActor*)params = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[1] = ContextLocation;
			*(bool*)&params[4] = bEnemyLocation;
			*(class Actor**)&params[8] = SpottedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRequestVGSCommand(TrVGSCommandList::VGSCommandType VGSCommandIndex, bool bGlobal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77108);
			byte params[5] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)params = VGSCommandIndex;
			*(bool*)&params[4] = bGlobal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveVGSCommand(class PlayerReplicationInfo* PRI, TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77112);
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(TrVGSCommandList::VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveVGSContextCommand(class PlayerReplicationInfo* PRI, TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77121);
			byte params[10] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(TrVGSCommandList::EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMoveErrors(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77128);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSkiHelpTextDistanceThresholdReached()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77130);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnJetpackHelpTextDistanceThresholdReached()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77131);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadPlayerProfile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77132);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetNewPlayerAssistAmount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77136);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void UpdateNewPlayerAssistPoints(int AmoutToSubtract)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77138);
			byte params[4] = { NULL };
			*(int*)params = AmoutToSubtract;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BehindView()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77142);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77143);
			byte params[4] = { NULL };
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77145);
			byte params[4] = { NULL };
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PlayerInput* GetEngineSettings(bool bUse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77147);
			byte params[8] = { NULL };
			*(bool*)params = bUse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)&params[4];
		}
		class TrPlayerInput_Spectator* GetSpectatorSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77151);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerInput_Spectator**)params;
		}
		void ClientOnMotionSensorAlarmSounded(class TrDeployable_MotionSensor* MotionSensor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77154);
			byte params[4] = { NULL };
			*(class TrDeployable_MotionSensor**)params = MotionSensor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientOnMotionSensorMineSounded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77158);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadPendingLoadoutContentData(int ClassId, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77159);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadPendingDeviceContentData(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77164);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideHUDElements()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77180);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientShowFlagIcon(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77182);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetPlayerClassObjects(ScriptString* ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77184);
			byte params[20] = { NULL };
			*(ScriptString**)params = ClassName;
			*(int*)&params[12] = PerkIcon1;
			*(int*)&params[16] = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePotentialSeekingTargets(ScriptArray<class Actor*> NewPotentialTargets)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77188);
			byte params[12] = { NULL };
			*(ScriptArray<class Actor*>*)params = NewPotentialTargets;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77193);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77198);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Spectate(bool bNeutral)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77202);
			byte params[4] = { NULL };
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndSpectate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77204);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSpectate(bool bNeutral)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77205);
			byte params[4] = { NULL };
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSpectate(bool bNeutral)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77208);
			byte params[4] = { NULL };
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFlags(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77212);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFlagStands(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77214);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewGenerators(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77216);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewBookmark(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77218);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewVehicles(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77220);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFastestPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77222);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewActor(class Actor* ActorToView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77223);
			byte params[4] = { NULL };
			*(class Actor**)params = ActorToView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientOnViewTargetChange(class Actor* NewViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77225);
			byte params[4] = { NULL };
			*(class Actor**)params = NewViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerIncreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77227);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerDecreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77229);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetMoveSpeed(float NewSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77231);
			byte params[4] = { NULL };
			*(float*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetCapturedFlag(class TrFlagCTF* NewFlagToWatch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77233);
			byte params[4] = { NULL };
			*(class TrFlagCTF**)params = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetFlagReturned()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77235);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewTargetDroppedFlag(class TrFlagBase* NewFlagToWatch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77236);
			byte params[4] = { NULL };
			*(class TrFlagBase**)params = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetLeftVehicle(class PlayerReplicationInfo* NewPRIToWatch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77238);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = NewPRIToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetViewTargetList(class TrPawn*& PawnViewTarget, class TrVehicle*& VehicleViewTarget, class TrCamera_SpectatorBookmark*& BookmarkViewTarget, class Actor*& ObjectiveViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77240);
			byte params[16] = { NULL };
			*(class TrPawn**)params = PawnViewTarget;
			*(class TrVehicle**)&params[4] = VehicleViewTarget;
			*(class TrCamera_SpectatorBookmark**)&params[8] = BookmarkViewTarget;
			*(class Actor**)&params[12] = ObjectiveViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PawnViewTarget = *(class TrPawn**)params;
			VehicleViewTarget = *(class TrVehicle**)&params[4];
			BookmarkViewTarget = *(class TrCamera_SpectatorBookmark**)&params[8];
			ObjectiveViewTarget = *(class Actor**)&params[12];
		}
		void ServerUnPossess()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77472);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayTakeHit(Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77474);
			byte params[17] = { NULL };
			*(Vector*)params = HitLoc;
			params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayReticuleHitSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77480);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayBluePlateImpact()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77485);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayAirMailImpact()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77488);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummarizeAwards()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77489);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientMatchOver(int Winner, ScriptString* WinnerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77490);
			byte params[16] = { NULL };
			*(int*)params = Winner;
			*(ScriptString**)&params[4] = WinnerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetEndOfMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFadeToSummary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77495);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77497);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRoundCountdown(int Seconds, int Round)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77499);
			byte params[8] = { NULL };
			*(int*)params = Seconds;
			*(int*)&params[4] = Round;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameCountdown(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77502);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKickPlayer(int Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77504);
			byte params[4] = { NULL };
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientKickPlayer(int Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77506);
			byte params[4] = { NULL };
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77508);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FumbledFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77509);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientOnFumbledFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77510);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallInAvailability()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77511);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallInCooldown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77516);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CalcCameraOnViewTarget(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77518);
			byte params[32] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
		}
		bool IsGameTypeArena()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77528);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsGameTypeDaD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77530);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsGameTypeCaH()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77533);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SwitchToDeathCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddProjectileToTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77538);
			byte params[4] = { NULL };
			*(class TrProjectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77540);
			byte params[4] = { NULL };
			*(class TrProjectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProjectile* TetherProjectile(class TrProjectile* ProjectileFromServer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77542);
			byte params[8] = { NULL };
			*(class TrProjectile**)params = ProjectileFromServer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProjectile**)&params[4];
		}
		void ConfigureSkiSpeedSteps(float SoftCap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77547);
			byte params[4] = { NULL };
			*(float*)params = SoftCap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77551);
			byte params[4] = { NULL };
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlushAccumulatedDetermination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77553);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearDetermination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77554);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDetermination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77560);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMenuMovieOpened()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77561);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMenuMovieClosed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77563);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayVGSAudio(class SoundCue* ASound, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77565);
			byte params[8] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class PlayerReplicationInfo**)&params[4] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VGSAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77570);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetLastDamagerInfo(int Health, int UpgradeLevel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77573);
			byte params[8] = { NULL };
			*(int*)params = Health;
			*(int*)&params[4] = UpgradeLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableTinyWeapons(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77576);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77580);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void EnableChatFilter(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77583);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77585);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void EnableDamageCounter(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77587);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77589);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void EnableHUDObjectives(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77591);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDReticule(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77593);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCredits(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77595);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDAccolades(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77597);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDBadges(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77599);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDScores(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77601);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDHealthBar(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77603);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDVisor(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77605);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDChat(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77607);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCombatLog(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77609);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDKillbox(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77611);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDDeathcam(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77613);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDHeroText(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77615);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDPromptPanel(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77617);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDRespawnTimer(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77619);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDSkiBars(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77621);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDFriendColoring(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77623);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDNotifications(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77625);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDFriendStateNotifications(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77627);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCracks(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77629);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowAlienFX(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77631);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77633);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool GetHUDNotifications()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77635);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77637);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetWhisperFilterValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77639);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SetWhisperFilter(int FilterValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77641);
			byte params[4] = { NULL };
			*(int*)params = FilterValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SummaryTweenTimer(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77643);
			byte params[4] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VoteNo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77645);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VoteYes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77650);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlashShooterHitReticule(int DamageAmount, bool isInstantHit, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77652);
			byte params[12] = { NULL };
			*(int*)params = DamageAmount;
			*(bool*)&params[4] = isInstantHit;
			*(int*)&params[8] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerShowOverheadNumber(int NumberToShow, Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77656);
			byte params[20] = { NULL };
			*(int*)params = NumberToShow;
			*(Vector*)&params[4] = WorldLocation;
			*(float*)&params[16] = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientShowOverheadNumber(int NumberToShow, Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77660);
			byte params[20] = { NULL };
			*(int*)params = NumberToShow;
			*(Vector*)&params[4] = WorldLocation;
			*(float*)&params[16] = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCreditsForDamageAmount(int DamageAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77666);
			byte params[8] = { NULL };
			*(int*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CashForDamage(int DamageAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77669);
			byte params[4] = { NULL };
			*(int*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AwardTeamAssistCredits()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77671);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardTeamRabbitAssistCredits(int Multiplier)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77672);
			byte params[4] = { NULL };
			*(int*)params = Multiplier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TypeKeyPressed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77677);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77679);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77680);
			byte params[4] = { NULL };
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetClassAffordable(int BitMask)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77682);
			byte params[4] = { NULL };
			*(int*)params = BitMask;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetClassBit(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77686);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void TestTrainingSlot(TrObject::TR_EQUIP_POINT equipType, int EquipId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77691);
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = equipType;
			*(int*)&params[4] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestSlot(TrObject::TR_EQUIP_POINT equipType, int EquipId, bool bTraining)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77695);
			byte params[9] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = equipType;
			*(int*)&params[4] = EquipId;
			*(bool*)&params[8] = bTraining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTestSlot(TrObject::TR_EQUIP_POINT EquipId, int EquipItem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77703);
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipId;
			*(int*)&params[4] = EquipItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77707);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77712);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void On1PSkinContentLoaded(ScriptClass* Skin1PDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77716);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Skin1PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddPending3PSkin(class TrPlayerReplicationInfo* TrPRI, int skinId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77718);
			byte params[8] = { NULL };
			*(class TrPlayerReplicationInfo**)params = TrPRI;
			*(int*)&params[4] = skinId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77722);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGiveCredits(class TrSeqAct_GiveCredits* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77723);
			byte params[4] = { NULL };
			*(class TrSeqAct_GiveCredits**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGiveAccolade(class TrSeqAct_GiveAccolade* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77727);
			byte params[4] = { NULL };
			*(class TrSeqAct_GiveAccolade**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayVGSCommand(class TrSeqAct_PlayVGSCommand* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77731);
			byte params[4] = { NULL };
			*(class TrSeqAct_PlayVGSCommand**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRefreshInventory(class TrSeqAct_RefreshInventory* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77737);
			byte params[4] = { NULL };
			*(class TrSeqAct_RefreshInventory**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartForceFocusTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77741);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartAcquisitionFireTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77742);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSettingBlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77743);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoRevertSetting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77744);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSendMenuBackTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77745);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QueueTimer(bool bStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77746);
			byte params[4] = { NULL };
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TVTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77748);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77749);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartHotkeyBlock()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77750);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientArenaRoundEnded(int WinningTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77759);
			byte params[4] = { NULL };
			*(int*)params = WinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayerResettingAndRespawning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77770);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyAllOwnedDeployables(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77771);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyAllOwnedMines(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77775);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyAllOwnedProjectiles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77778);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QueueBadge(int Icon, ScriptString* Title, ScriptString* XPReward)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77780);
			byte params[28] = { NULL };
			*(int*)params = Icon;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = XPReward;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientQueueAccolade(int Icon, ScriptString* Title, ScriptString* Subtitle, bool bIsBadge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77784);
			byte params[32] = { NULL };
			*(int*)params = Icon;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Subtitle;
			*(bool*)&params[28] = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClassHotkeyPTH()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77789);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeySEN()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77790);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyINF()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77791);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeySLD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77792);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyRDR()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77793);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyTCN()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyJUG()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77795);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyDMB()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77796);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyBRT()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77797);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuickClasses()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77798);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuickLoadouts(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77800);
			byte params[4] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndVGSInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77803);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartUILoadSummaryTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77805);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenVehicleMenu(class TrVehicleStation* VehicleStation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77806);
			byte params[4] = { NULL };
			*(class TrVehicleStation**)params = VehicleStation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77825);
			byte params[4] = { NULL };
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckFriendlyFireKills()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77832);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckFriendlyFireDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77835);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartRefreshPageTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77838);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMainMenuPaperDoll_Mesh(TrObject::EContentDataType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77839);
			byte params[1] = { NULL };
			*(TrObject::EContentDataType*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMainMenuPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77841);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77842);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77845);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SampleVoice(ScriptClass* VoiceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77850);
			byte params[4] = { NULL };
			*(ScriptClass**)params = VoiceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripTag(ScriptString* sValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77852);
			byte params[24] = { NULL };
			*(ScriptString**)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77856);
			byte params[4] = { NULL };
			*(bool*)params = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(77858);
			byte params[4] = { NULL };
			*(bool*)params = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
