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
		class TrCameraShakeInfo
		{
		public:
			ADD_STRUCT(ScriptName, ShakeName, 4)
			ADD_OBJECT(CameraShake, Shake, 0)
		};
		class VGSAudioCommand
		{
		public:
			ADD_OBJECT(SoundCue, QueuedSoundCue, 8)
			ADD_OBJECT(TrPlayerReplicationInfo, VGSInstigator, 0)
		};
		class SpectatorKeybindViewTargetMap
		{
		public:
			ADD_OBJECT(Actor, ViewTarget, 24)
			ADD_STRUCT(Input::KeyBind, KeyBinding, 0)
		};
		class PendingSkin
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
		ADD_STRUCT(Object::Rotator, m_rCurrentKickbackDirection, 2220)
		ADD_OBJECT(MaterialEffect, m_ZoomedEffect, 2340)
		ADD_OBJECT(TrStatsInterface, Stats, 3144)
		ADD_OBJECT(TrAccoladeManager, m_AccoladeManager, 2348)
		ADD_STRUCT(Object::Vector, m_vDeathCamOffset, 3112)
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
		ADD_STRUCT(Object::Rotator, r_rViewTargetViewRotation, 3300)
		ADD_STRUCT(Object::Vector, r_vViewTargetViewLocation, 3288)
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
		ADD_STRUCT(Object::Rotator, m_rKickbackAim, 2208)
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLanguageFontIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool InTraining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InTraining");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptClass* GetFamilyInfoFromId(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetFamilyInfoFromId");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		class TrDevice* GetDeviceByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetDeviceByEquipPoint");
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDevice**)&params[4];
		}
		UTWeapon::EZoomState GetZoomedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetZoomedState");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UTWeapon::EZoomState*)&params[0];
		}
		bool InRovingSpectate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InRovingSpectate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsTrPlayerMuted(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsTrPlayerMuted");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetActiveClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetActiveClassId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetTeamClassCount(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetTeamClassCount");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool RegisterPendingClass(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RegisterPendingClass");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetAllowedClassCount(TrObject::TrClassType ClassType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAllowedClassCount");
			byte params[5] = { NULL };
			*(TrObject::TrClassType*)&params[0] = ClassType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool SendPrivateChatMessage(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendPrivateChatMessage");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool BroadcastChatMessage(TgSupportCommands::GC_CHAT_CHANNEL Channel, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BroadcastChatMessage");
			byte params[17] = { NULL };
			*(TgSupportCommands::GC_CHAT_CHANNEL*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool ServerRequestPickTeam(byte RequestedTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestPickTeam");
			byte params[5] = { NULL };
			params[0] = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ChooseBloodEagle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChooseBloodEagle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ChooseDiamondSword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChooseDiamondSword");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetVehicleCost(ScriptClass* VehicleClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetVehicleCost");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetCurrentCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCurrentCredits");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool IsBassBoostToggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsBassBoostToggled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool AllowHelpTextToDisplay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AllowHelpTextToDisplay");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NeedToVisitInventoryStation");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetCurrentDetermination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCurrentDetermination");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetNewPlayerAssistToApply()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetNewPlayerAssistToApply");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void PlayReliableSound(class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Object::Vector SoundLocation, bool bNoRepToRelevant)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayReliableSound");
			byte params[32] = { NULL };
			*(class SoundCue**)&params[0] = InSoundCue;
			*(bool*)&params[4] = bNotReplicated;
			*(bool*)&params[8] = bNoRepToOwner;
			*(bool*)&params[12] = bStopWhenOwnerDestroyed;
			*(Object::Vector*)&params[16] = SoundLocation;
			*(bool*)&params[28] = bNoRepToRelevant;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendCtrlRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendCtrlRequest");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendGameRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendGameRequest");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestSteamPurchase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestSteamPurchase");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowAdminPage(ScriptString* ServerURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowAdminPage");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ServerURL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHitValidationMode(int loggingMode, int validationMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetHitValidationMode");
			byte params[8] = { NULL };
			*(int*)&params[0] = loggingMode;
			*(int*)&params[4] = validationMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickPlayerFromMatch(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.KickPlayerFromMatch");
			byte params[4] = { NULL };
			*(int*)&params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool MainMenuIsOpen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MainMenuIsOpen");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetMenuInGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetMenuInGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMenuToLobby()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendMenuToLobby");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenSummaryScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TweenSummaryScreen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMenuSummaryScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetMenuSummaryScreen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMenuEndOfMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetMenuEndOfMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginExperienceTweens()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BeginExperienceTweens");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickVoteReply(bool bVote)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.KickVoteReply");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVote;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMenuMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetMenuMatchCountdown");
			byte params[4] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetUserSelectedClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetUserSelectedClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void RevertSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RevertSetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMenuBack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendMenuBack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAcquisition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FireAcquisition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceFocus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ForceFocus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTVTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateTVTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDealTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateDealTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateQueueTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateQueueTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleWorkingGraphic(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleWorkingGraphic");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndHotkeyBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EndHotkeyBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MutePlayer(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MutePlayer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnmutePlayer(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UnmutePlayer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HaveMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HaveMenu");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsChatFiltered(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsChatFiltered");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void RequestKickVote(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RequestKickVote");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OpenMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenClasses()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OpenClasses");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleFriends()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleFriends");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClaimPromotion(ScriptString* PromoCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClaimPromotion");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PromoCode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireUILoadSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FireUILoadSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireRefreshPage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FireRefreshPage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleBassBoost(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleBassBoost");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForwardChatFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ForwardChatFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowNotification(ScriptString* Message, ScriptString* Message2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowNotification");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(ScriptString**)&params[12] = Message2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptString* Sender, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChatMessageReceived");
			byte params[28] = { NULL };
			*(int*)&params[0] = Channel;
			*(ScriptString**)&params[4] = Sender;
			*(ScriptString**)&params[16] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushChat(ScriptString* chatStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PushChat");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = chatStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bug()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Bug");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void _Crash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController._Crash");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsGameUsingSeekFreeLoading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameUsingSeekFreeLoading");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ResetRunaway()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ResetRunaway");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearVehicleMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClearVehicleMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowVehicleMenu(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowVehicleMenu");
			byte params[4] = { NULL };
			*(int*)&params[0] = Credits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleMenuOption(ScriptString* ClassName, ScriptString* DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddVehicleMenuOption");
			byte params[40] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			*(ScriptString**)&params[12] = DisplayName;
			*(int*)&params[24] = Cost;
			*(int*)&params[28] = Icon;
			*(int*)&params[32] = CountSpawned;
			*(int*)&params[36] = CountAllowed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetOnlineFriends(ScriptArray<ScriptString*>& vFriends)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetOnlineFriends");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptString*>*)&params[0] = vFriends;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			vFriends = *(ScriptArray<ScriptString*>*)&params[0];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitHelpTextManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InitHelpTextManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncerSound(class SoundCue* AnnouncementCue, bool bPlayRightNow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayAnnouncerSound");
			byte params[8] = { NULL };
			*(class SoundCue**)&params[0] = AnnouncementCue;
			*(bool*)&params[4] = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestAnnouncement(bool bPlayRightNow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestAnnouncement");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientHearReliableSound(class SoundCue* ASound, class Actor* SourceActor, Object::Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientHearReliableSound");
			byte params[28] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Object::Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMySaberLauncherTargetingUpdated(TrObject::EMissileLock MissileLockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientMySaberLauncherTargetingUpdated");
			byte params[1] = { NULL };
			*(TrObject::EMissileLock*)&params[0] = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSeekingMissileTargetingSelfEvent(int EventSwitch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSeekingMissileTargetingSelfEvent");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventSwitch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMissileIntercepted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnMissileIntercepted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUDNotification(ScriptString* Message, ScriptString* Message2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowHUDNotification");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(ScriptString**)&params[12] = Message2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideHUDNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideHUDNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Object::Vector FireLocation, Object::Vector FireDir, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckBulletWhip");
			byte params[40] = { NULL };
			*(class SoundCue**)&params[0] = BulletWhip;
			*(Object::Vector*)&params[4] = FireLocation;
			*(Object::Vector*)&params[16] = FireDir;
			*(Object::Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessCreditEvent(TrObject::TrCreditEventType EventType, bool bProxyEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ProcessCreditEvent");
			byte params[5] = { NULL };
			*(TrObject::TrCreditEventType*)&params[0] = EventType;
			*(bool*)&params[4] = bProxyEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyCredits(int Count, bool bFreeCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ModifyCredits");
			byte params[8] = { NULL };
			*(int*)&params[0] = Count;
			*(bool*)&params[4] = bFreeCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCurrentCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateCurrentCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreditsSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CreditsSoundFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientUpdateCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetLatestAccoladeIconIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLatestAccoladeIconIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ClientShowAccoladeIcon(int IconIndex, ScriptString* Description, ScriptString* Points)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowAccoladeIcon");
			byte params[28] = { NULL };
			*(int*)&params[0] = IconIndex;
			*(ScriptString**)&params[4] = Description;
			*(ScriptString**)&params[16] = Points;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientShowAccoladeText(ScriptString* Message, int ShowTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowAccoladeText");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Message;
			*(int*)&params[12] = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetStreaks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ResetStreaks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GiveCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerGiveCreditsCheat(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerGiveCreditsCheat");
			byte params[4] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AimingHelp");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyChangedWeapon");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = PreviousWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReloadWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReloadWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerReloadWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerReloadWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetCharFamily(ScriptString* FamilyClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetCharFamily");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = FamilyClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSuicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSuicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		TrObject::EArmorType GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetArmorType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::EArmorType*)&params[0];
		}
		float GetRespawnDelayTotalTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetRespawnDelayTotalTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Rotator LimitViewRotation(Object::Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LimitViewRotation");
			byte params[32] = { NULL };
			*(Object::Rotator*)&params[0] = ViewRotation;
			*(float*)&params[12] = ViewPitchMin;
			*(float*)&params[16] = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[20];
		}
		void PressedMelee()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedMelee");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedLaser()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedLaser");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedBelt()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedBelt");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedPack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedPack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedDeployable");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShowEquip(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetShowEquip");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PressedConsoleUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedConsoleUse");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedWeaponSwitch(bool bFilterTimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedWeaponSwitch");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bFilterTimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EquipPrimary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EquipPrimary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipSecondary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EquipSecondary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateDevice(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ActivateDevice");
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateLockedTarget(class Actor* LockedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateLockedTarget");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = LockedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IdentifyTeamMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IdentifyTeamMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayStartupMessage");
			byte params[1] = { NULL };
			params[0] = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindValidGRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FindValidGRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitHUDObjects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InitHUDObjects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientStartSpawnTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientStartSpawnTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompletePickTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CompletePickTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestAutoAssignTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestAutoAssignTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientEndTeamSelect(int RequestedTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientEndTeamSelect");
			byte params[4] = { NULL };
			*(int*)&params[0] = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeTeam(ScriptString* TeamName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChangeTeam");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewAPlayer(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ViewAPlayer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerPlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerPlayerTick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayerTick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* W, Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = W;
			*(Object::Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		void StartWeather()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartWeather");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopWeather()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StopWeather");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredWeatherVolume(bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PawnEnteredWeatherVolume");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)&params[4] = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftWeatherVolume(bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PawnLeftWeatherVolume");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)&params[4] = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLowHealthFX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayLowHealthFX");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLowHealthFX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StopLowHealthFX");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRechargeHealthFX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayRechargeHealthFX");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopRechargeHealthFX()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StopRechargeHealthFX");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleJetpack(bool bEnabled, bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleJetpack");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnabled;
			*(bool*)&params[4] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableJetpack(bool bEnabled, bool bJump, bool bForcedOff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableJetpack");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bEnabled;
			*(bool*)&params[4] = bJump;
			*(bool*)&params[8] = bForcedOff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IgnoreMoveInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DoJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformBlink()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PerformBlink");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetBlinkPackAccel(Object::Vector& newAccel, float& BlinkPackPctEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetBlinkPackAccel");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = newAccel;
			*(float*)&params[12] = BlinkPackPctEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			newAccel = *(Object::Vector*)&params[0];
			BlinkPackPctEffectiveness = *(float*)&params[12];
		}
		void InitRespawnTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InitRespawnTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRespawnTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateRespawnTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestRespawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RequestRespawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Respawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Respawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRespawnSoonSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayRespawnSoonSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupGameplayEffectsOnDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CleanupGameplayEffectsOnDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCrossedOffArenaList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnCrossedOffArenaList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Possess");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RefreshHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAirVehicleInversion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAirVehicleInversion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerSetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetAirVehicleControls");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetAirVehicleControls");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsInVehicle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClientVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientVehiclePhysUpdated");
			byte params[4] = { NULL };
			*(class TrVehicle**)&params[0] = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerVehiclePhysUpdated");
			byte params[4] = { NULL };
			*(class TrVehicle**)&params[0] = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerVerifyVehiclePhys(float TimeStamp, float InForward, float InStrafe, float InUp, int View, Actor::RigidBodyState InRBState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerVerifyVehiclePhys");
			byte params[84] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(float*)&params[4] = InForward;
			*(float*)&params[8] = InStrafe;
			*(float*)&params[12] = InUp;
			*(int*)&params[16] = View;
			*(Actor::RigidBodyState*)&params[32] = InRBState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerCorrectClientPhys(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerCorrectClientPhys");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerToggleVehicleJets");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleVehicleJets");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessRiding(Object::Rotator ViewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ProcessRiding");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRiding(float TimeStamp, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRiding");
			byte params[8] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(int*)&params[4] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToCallIn(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToCallIn");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRequestCallInChange(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestCallInChange");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToSeat(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToSeat");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSwitchToSeat(byte T, class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSwitchToSeat");
			byte params[5] = { NULL };
			params[0] = T;
			*(class TrVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TriggerInteracted");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerRequestLoadoutChange(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestLoadoutChange");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfo, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePaperDoll");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePaperDoll_Device");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnVehicle(ScriptString* vehicleClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpawnVehicle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RequestBuyVehicle(ScriptString* vehicleClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RequestBuyVehicle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PressedSki(bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedSki");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReleasedSki()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReleasedSki");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleSki()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleSki");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayReleasedSki()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DelayReleasedSki");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBindSkiJet(int method)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetBindSkiJet");
			byte params[4] = { NULL };
			*(int*)&params[0] = method;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleShowObjectMarkers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleShowObjectMarkers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerStartSki(bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerStartSki");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerStopSki()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerStopSki");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetHUD");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnKickback(Object::Rotator KickbackAim, float KickbackBlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnKickback");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = KickbackAim;
			*(float*)&params[12] = KickbackBlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateKickbackDirection(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateKickbackDirection");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RestoreMoveInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RestoreMoveInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestoreMoveInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientRestoreMoveInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestSpawnVehicle(ScriptClass* VehicleClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestSpawnVehicle");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PerformedUseAction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PressedZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleasedZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReleasedZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MagnifyZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MagnifyZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DemagnifyZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DemagnifyZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReleaseZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckZoomButton()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckZoomButton");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrStartZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TrStartZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrStopZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TrStopZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrEndZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TrEndZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetZoomDuration(bool bPlayRechargeSoundOnWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ResetZoomDuration");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayRechargeSoundOnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetZoom(UTWeapon::EZoomState NewZoomState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetZoom");
			byte params[1] = { NULL };
			*(UTWeapon::EZoomState*)&params[0] = NewZoomState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReceiveLocalizedMessage");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = Message;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveLocalizedNagMessage(ScriptClass* Message, int Switch, float Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReceiveLocalizedNagMessage");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = Message;
			*(int*)&params[4] = Switch;
			*(float*)&params[8] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TrClientMusicEvent");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientRestart");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateClientSpawnTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateClientSpawnTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GameHasEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckJumpOrDuck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientGameEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerDropFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerDropFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Object::Vector& POVLocation, Object::Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = POVLocation;
			*(Object::Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Object::Vector*)&params[0];
			POVRotation = *(Object::Rotator*)&params[12];
		}
		void ActivateFreeCam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ActivateFreeCam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeactivateFreeCam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DeactivateFreeCam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetViewTargetAsOverwatch(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetViewTargetAsOverwatch");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayCameraShake(ScriptName ShakeName, float Scale, class CameraShake* SourceShake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayCameraShake");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = ShakeName;
			*(float*)&params[8] = Scale;
			*(class CameraShake**)&params[12] = SourceShake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayForceFeedbackWaveform");
			byte params[8] = { NULL };
			*(class ForceFeedbackWaveform**)&params[0] = FFWaveform;
			*(class Actor**)&params[4] = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpeedCameraEffect(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateSpeedCameraEffect");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpeedCamEffect(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpeedCamEffect");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPulseHUD(byte Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPulseHUD");
			byte params[1] = { NULL };
			params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PulseShield()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PulseShield");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddTimePlayed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddTimePlayed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AcknowledgePossession");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MatchEndSoundMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MatchEndSoundMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetSoundMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ResetSoundMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SuppressHelpText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SuppressHelpText");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TalkVGS(ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TalkVGS");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Say");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPlayerCommand(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsPlayerCommand");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ShowFeedbackMessage(ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowFeedbackMessage");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Color GetChatColor(TgSupportCommands::GC_CHAT_CHANNEL Channel, bool bSameTeam, int& ChatColorIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetChatColor");
			byte params[13] = { NULL };
			*(TgSupportCommands::GC_CHAT_CHANNEL*)&params[0] = Channel;
			*(bool*)&params[4] = bSameTeam;
			*(int*)&params[8] = ChatColorIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ChatColorIdx = *(int*)&params[8];
			return *(Object::Color*)&params[12];
		}
		void AddChatToConsole(ScriptString* Sender, ScriptString* ChatMessage, TgSupportCommands::GC_CHAT_CHANNEL Channel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddChatToConsole");
			byte params[25] = { NULL };
			*(ScriptString**)&params[0] = Sender;
			*(ScriptString**)&params[12] = ChatMessage;
			*(TgSupportCommands::GC_CHAT_CHANNEL*)&params[24] = Channel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetLastTellSender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLastTellSender");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ReplyTalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReplyTalk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CanCommunicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Talk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Talk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatConsole(bool bTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChatConsole");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TalkConsole(bool bTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TalkConsole");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamTalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TeamTalk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TeamSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AllowTextMessage");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void WarnPlayerAboutSpam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.WarnPlayerAboutSpam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginVGS()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BeginVGS");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpotTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpotTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRequestVGSContextCommand(TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation, class Actor* SpottedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestVGSContextCommand");
			byte params[10] = { NULL };
			*(TrVGSCommandList::EVGSContextActor*)&params[0] = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[1] = ContextLocation;
			*(bool*)&params[4] = bEnemyLocation;
			*(class Actor**)&params[8] = SpottedActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRequestVGSCommand(TrVGSCommandList::VGSCommandType VGSCommandIndex, bool bGlobal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestVGSCommand");
			byte params[5] = { NULL };
			*(TrVGSCommandList::VGSCommandType*)&params[0] = VGSCommandIndex;
			*(bool*)&params[4] = bGlobal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveVGSCommand(class PlayerReplicationInfo* PRI, TrVGSCommandList::VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientReceiveVGSCommand");
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(TrVGSCommandList::VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReceiveVGSContextCommand(class PlayerReplicationInfo* PRI, TrVGSCommandList::EVGSContextActor ContextActor, TrVGSCommandList::EVGSContextLocation ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientReceiveVGSContextCommand");
			byte params[10] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(TrVGSCommandList::EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList::EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMoveErrors(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowMoveErrors");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSkiHelpTextDistanceThresholdReached()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnSkiHelpTextDistanceThresholdReached");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnJetpackHelpTextDistanceThresholdReached()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnJetpackHelpTextDistanceThresholdReached");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadPlayerProfile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadPlayerProfile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetNewPlayerAssistAmount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetNewPlayerAssistAmount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void UpdateNewPlayerAssistPoints(int AmoutToSubtract)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateNewPlayerAssistPoints");
			byte params[4] = { NULL };
			*(int*)&params[0] = AmoutToSubtract;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BehindView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BehindView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetBehindView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetBehindView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PlayerInput* GetEngineSettings(bool bUse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetEngineSettings");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)&params[4];
		}
		class TrPlayerInput_Spectator* GetSpectatorSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetSpectatorSettings");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerInput_Spectator**)&params[0];
		}
		void ClientOnMotionSensorAlarmSounded(class TrDeployable_MotionSensor* MotionSensor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnMotionSensorAlarmSounded");
			byte params[4] = { NULL };
			*(class TrDeployable_MotionSensor**)&params[0] = MotionSensor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientOnMotionSensorMineSounded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnMotionSensorMineSounded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadPendingLoadoutContentData(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadPendingLoadoutContentData");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadPendingDeviceContentData(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadPendingDeviceContentData");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideHUDElements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideHUDElements");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientShowFlagIcon(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowFlagIcon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetPlayerClassObjects(ScriptString* ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetPlayerClassObjects");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = ClassName;
			*(int*)&params[12] = PerkIcon1;
			*(int*)&params[16] = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePotentialSeekingTargets(ScriptArray<class Actor*> NewPotentialTargets)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePotentialSeekingTargets");
			byte params[12] = { NULL };
			*(ScriptArray<class Actor*>*)&params[0] = NewPotentialTargets;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NotifyHitWall(Object::Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyHitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyFallingHitWall(Object::Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyFallingHitWall");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Spectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Spectate");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndSpectate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EndSpectate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSpectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSpectate");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSpectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSpectate");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFlags(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFlags");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFlagStands(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFlagStands");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewGenerators(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewGenerators");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewBookmark(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewBookmark");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewVehicles(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewVehicles");
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewFastestPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFastestPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewActor(class Actor* ActorToView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = ActorToView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientOnViewTargetChange(class Actor* NewViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnViewTargetChange");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerIncreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerIncreaseCamDistance");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerDecreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerDecreaseCamDistance");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetMoveSpeed(float NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetMoveSpeed");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetCapturedFlag(class TrFlagCTF* NewFlagToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetCapturedFlag");
			byte params[4] = { NULL };
			*(class TrFlagCTF**)&params[0] = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetFlagReturned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetFlagReturned");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewTargetDroppedFlag(class TrFlagBase* NewFlagToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetDroppedFlag");
			byte params[4] = { NULL };
			*(class TrFlagBase**)&params[0] = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewTargetLeftVehicle(class PlayerReplicationInfo* NewPRIToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetLeftVehicle");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = NewPRIToWatch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetViewTargetList(class TrPawn*& PawnViewTarget, class TrVehicle*& VehicleViewTarget, class TrCamera_SpectatorBookmark*& BookmarkViewTarget, class Actor*& ObjectiveViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetViewTargetList");
			byte params[16] = { NULL };
			*(class TrPawn**)&params[0] = PawnViewTarget;
			*(class TrVehicle**)&params[4] = VehicleViewTarget;
			*(class TrCamera_SpectatorBookmark**)&params[8] = BookmarkViewTarget;
			*(class Actor**)&params[12] = ObjectiveViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PawnViewTarget = *(class TrPawn**)&params[0];
			VehicleViewTarget = *(class TrVehicle**)&params[4];
			BookmarkViewTarget = *(class TrCamera_SpectatorBookmark**)&params[8];
			ObjectiveViewTarget = *(class Actor**)&params[12];
		}
		void ServerUnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerUnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayTakeHit(Object::Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayTakeHit");
			byte params[17] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayReticuleHitSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayReticuleHitSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayBluePlateImpact()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayBluePlateImpact");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayAirMailImpact()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayAirMailImpact");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummarizeAwards()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SummarizeAwards");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientMatchOver(int Winner, ScriptString* WinnerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientMatchOver");
			byte params[16] = { NULL };
			*(int*)&params[0] = Winner;
			*(ScriptString**)&params[4] = WinnerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetEndOfMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetEndOfMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFadeToSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientFadeToSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateMatchCountdown");
			byte params[4] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRoundCountdown(int Seconds, int Round)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateRoundCountdown");
			byte params[8] = { NULL };
			*(int*)&params[0] = Seconds;
			*(int*)&params[4] = Round;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateGameCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateGameCountdown");
			byte params[4] = { NULL };
			*(int*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerKickPlayer(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerKickPlayer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientKickPlayer(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientKickPlayer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.KickWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FumbledFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FumbledFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientOnFumbledFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnFumbledFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallInAvailability()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateCallInAvailability");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallInCooldown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateCallInCooldown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CalcCameraOnViewTarget(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CalcCameraOnViewTarget");
			byte params[32] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
		}
		bool IsGameTypeArena()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeArena");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsGameTypeDaD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeDaD");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsGameTypeCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeCaH");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SwitchToDeathCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToDeathCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddProjectileToTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddProjectileToTetherList");
			byte params[4] = { NULL };
			*(class TrProjectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckTetherList");
			byte params[4] = { NULL };
			*(class TrProjectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrProjectile* TetherProjectile(class TrProjectile* ProjectileFromServer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TetherProjectile");
			byte params[8] = { NULL };
			*(class TrProjectile**)&params[0] = ProjectileFromServer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProjectile**)&params[4];
		}
		void ConfigureSkiSpeedSteps(float SoftCap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ConfigureSkiSpeedSteps");
			byte params[4] = { NULL };
			*(float*)&params[0] = SoftCap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadingTimer");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlushAccumulatedDetermination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FlushAccumulatedDetermination");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearDetermination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClearDetermination");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddDetermination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddDetermination");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMenuMovieOpened()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnMenuMovieOpened");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMenuMovieClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnMenuMovieClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayVGSAudio(class SoundCue* ASound, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayVGSAudio");
			byte params[8] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class PlayerReplicationInfo**)&params[4] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VGSAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.VGSAudioFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetLastDamagerInfo(int Health, int UpgradeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetLastDamagerInfo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Health;
			*(int*)&params[4] = UpgradeLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableTinyWeapons(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableTinyWeapons");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetTinyWeaponValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void EnableChatFilter(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableChatFilter");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetChatFilterValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void EnableDamageCounter(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableDamageCounter");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetDamageCounterValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void EnableHUDObjectives(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDObjectives");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDReticule(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDReticule");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCredits(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCredits");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDAccolades(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDAccolades");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDBadges(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDBadges");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDScores(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDScores");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDHealthBar(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDHealthBar");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDVisor(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDVisor");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDChat(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDChat");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCombatLog(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCombatLog");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDKillbox(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDKillbox");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDDeathcam(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDDeathcam");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDHeroText(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDHeroText");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDPromptPanel(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDPromptPanel");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDRespawnTimer(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDRespawnTimer");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDSkiBars(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDSkiBars");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDFriendColoring(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDFriendColoring");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDNotifications(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDNotifications");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDFriendStateNotifications(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDFriendStateNotifications");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableHUDCracks(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCracks");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowAlienFX(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowAlienFX");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDObjectivesValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool GetHUDNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDNotifications");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDFriendStateNotifications");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetWhisperFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetWhisperFilterValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void SetWhisperFilter(int FilterValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetWhisperFilter");
			byte params[4] = { NULL };
			*(int*)&params[0] = FilterValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SummaryTweenTimer(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SummaryTweenTimer");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VoteNo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.VoteNo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VoteYes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.VoteYes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlashShooterHitReticule(int DamageAmount, bool isInstantHit, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FlashShooterHitReticule");
			byte params[12] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(bool*)&params[4] = isInstantHit;
			*(int*)&params[8] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerShowOverheadNumber(int NumberToShow, Object::Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerShowOverheadNumber");
			byte params[20] = { NULL };
			*(int*)&params[0] = NumberToShow;
			*(Object::Vector*)&params[4] = WorldLocation;
			*(float*)&params[16] = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientShowOverheadNumber(int NumberToShow, Object::Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowOverheadNumber");
			byte params[20] = { NULL };
			*(int*)&params[0] = NumberToShow;
			*(Object::Vector*)&params[4] = WorldLocation;
			*(float*)&params[16] = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCreditsForDamageAmount(int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCreditsForDamageAmount");
			byte params[8] = { NULL };
			*(int*)&params[0] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CashForDamage(int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CashForDamage");
			byte params[4] = { NULL };
			*(int*)&params[0] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AwardTeamAssistCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AwardTeamAssistCredits");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardTeamRabbitAssistCredits(int Multiplier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AwardTeamRabbitAssistCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Multiplier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TypeKeyPressed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TypeKeyPressed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FixFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetFOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetClassAffordable(int BitMask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetClassAffordable");
			byte params[4] = { NULL };
			*(int*)&params[0] = BitMask;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetClassBit(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetClassBit");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void TestTrainingSlot(TrObject::TR_EQUIP_POINT equipType, int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestTrainingSlot");
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = equipType;
			*(int*)&params[4] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TestSlot(TrObject::TR_EQUIP_POINT equipType, int EquipId, bool bTraining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestSlot");
			byte params[9] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = equipType;
			*(int*)&params[4] = EquipId;
			*(bool*)&params[8] = bTraining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTestSlot(TrObject::TR_EQUIP_POINT EquipId, int EquipItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerTestSlot");
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipId;
			*(int*)&params[4] = EquipItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnDeviceContentDataClassLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.On3PSkinContentLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void On1PSkinContentLoaded(ScriptClass* Skin1PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.On1PSkinContentLoaded");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Skin1PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddPending3PSkin(class TrPlayerReplicationInfo* TrPRI, int skinId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddPending3PSkin");
			byte params[8] = { NULL };
			*(class TrPlayerReplicationInfo**)&params[0] = TrPRI;
			*(int*)&params[4] = skinId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnClassSelectedMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGiveCredits(class TrSeqAct_GiveCredits* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnGiveCredits");
			byte params[4] = { NULL };
			*(class TrSeqAct_GiveCredits**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGiveAccolade(class TrSeqAct_GiveAccolade* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnGiveAccolade");
			byte params[4] = { NULL };
			*(class TrSeqAct_GiveAccolade**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayVGSCommand(class TrSeqAct_PlayVGSCommand* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnPlayVGSCommand");
			byte params[4] = { NULL };
			*(class TrSeqAct_PlayVGSCommand**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRefreshInventory(class TrSeqAct_RefreshInventory* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnRefreshInventory");
			byte params[4] = { NULL };
			*(class TrSeqAct_RefreshInventory**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartForceFocusTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartForceFocusTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartAcquisitionFireTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartAcquisitionFireTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSettingBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartSettingBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoRevertSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AutoRevertSetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSendMenuBackTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartSendMenuBackTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QueueTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.QueueTimer");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TVTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TVTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DealTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DealTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartHotkeyBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartHotkeyBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientArenaRoundEnded(int WinningTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientArenaRoundEnded");
			byte params[4] = { NULL };
			*(int*)&params[0] = WinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayerResettingAndRespawning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayerResettingAndRespawning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyAllOwnedDeployables(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedDeployables");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyAllOwnedMines(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedMines");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyAllOwnedProjectiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedProjectiles");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QueueBadge(int Icon, ScriptString* Title, ScriptString* XPReward)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.QueueBadge");
			byte params[28] = { NULL };
			*(int*)&params[0] = Icon;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = XPReward;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientQueueAccolade(int Icon, ScriptString* Title, ScriptString* Subtitle, bool bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientQueueAccolade");
			byte params[32] = { NULL };
			*(int*)&params[0] = Icon;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Subtitle;
			*(bool*)&params[28] = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClassHotkeyPTH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyPTH");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeySEN()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeySEN");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyINF()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyINF");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeySLD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeySLD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyRDR()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyRDR");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyTCN()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyTCN");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyJUG()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyJUG");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyDMB()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyDMB");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassHotkeyBRT()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClassHotkeyBRT");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuickClasses()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.QuickClasses");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuickLoadouts(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.QuickLoadouts");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndVGSInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EndVGSInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartUILoadSummaryTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartUILoadSummaryTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenVehicleMenu(class TrVehicleStation* VehicleStation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OpenVehicleMenu");
			byte params[4] = { NULL };
			*(class TrVehicleStation**)&params[0] = VehicleStation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnScoreChanged");
			byte params[4] = { NULL };
			*(class UTTeamInfo**)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckFriendlyFireKills()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckFriendlyFireKills");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckFriendlyFireDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckFriendlyFireDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartRefreshPageTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartRefreshPageTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMainMenuPaperDoll_Mesh(TrObject::EContentDataType Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateMainMenuPaperDoll_Mesh");
			byte params[1] = { NULL };
			*(TrObject::EContentDataType*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMainMenuPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClearMainMenuPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClearPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpecList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SampleVoice(ScriptClass* VoiceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SampleVoice");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = VoiceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* StripTag(ScriptString* sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StripTag");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetAllowSimProjectiles");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetAllowSimProjectiles");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
