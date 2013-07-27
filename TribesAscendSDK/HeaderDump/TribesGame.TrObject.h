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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrObject : public Object
	{
	public:
		static const auto FEET_TO_UNREAL_UNITS = 16;
		static const auto INDEX_DISPLAY_TARGET_INGAME = 0;
		static const auto INDEX_DISPLAY_TARGET_FOREGROUND = 1;
		static const auto INDEX_SEE_NORMAL_ENEMY = 0;
		static const auto INDEX_SEE_STEALTHED_ENEMY = 1;
		static const auto INDEX_SEE_LOW_HEALTH_ENEMY = 2;
		static const auto TR_TASKFORCE_NONE = 0;
		static const auto TR_TASKFORCE_BLOODEAGLE = 1;
		static const auto TR_TASKFORCE_DIAMONDSWORD = 2;
		static const float FADE_TIME;
		static const auto MAX_HEARING_DISTANCE = 1300;
		static const auto TR_MAX_SLOTS_TO_EQUIP = 5;
		static const float UnrealUnitsToKM;
		enum EffectFormMatTypes : byte
		{
			MAT_None = 0,
			MAT_Stealth = 1,
			MAT_Shield = 2,
			MAT_MAX = 3,
		};
		enum TeamAssignTypes : byte
		{
			TAT_BALANCED = 0,
			TAT_UNBALANCED = 1,
			TAT_AUTOASSIGN = 2,
			TAT_MAX = 3,
		};
		enum TrMiscMessages : byte
		{
			TrMISC_BloodEagleBoughtHerc = 0,
			TrMISC_DiamondSwordBoughtHerc = 1,
			TrMISC_BloodEagleCloseToWin = 2,
			TrMISC_DiamondSwordCloseToWin = 3,
			TrMISC_MAX = 4,
		};
		enum EArmorType : byte
		{
			ARMOR_Light = 0,
			ARMOR_Medium = 1,
			ARMOR_Heavy = 2,
			ARMOR_MAX = 3,
		};
		enum ETrPlayerCallIns : byte
		{
			TRCALLIN_None = 0,
			TrCallIn_SupportInventory = 1,
			TrCallIn_OrbitalStrike = 2,
			TrCallIn_TacticalStrike = 3,
			ETrPlayerCallIns_MAX = 4,
		};
		enum ESettingsList : byte
		{
			ESL_KEYBIND_START = 0,
			ESL_MOVE_FORWARD = 1,
			ESL_MOVE_BACKWARD = 2,
			ESL_STRAFE_LEFT = 3,
			ESL_STRAFE_RIGHT = 4,
			ESL_DO_SKI = 5,
			ESL_DO_JUMP = 6,
			ESL_DO_JETPACK = 7,
			ESL_DO_JUMPJETPACK = 8,
			ESL_DO_JUMPSKI = 9,
			ESL_TOGGLE_SKI = 10,
			ESL_DO_ZOOM = 11,
			ESL_FIRE_WEAPON = 12,
			ESL_RELOAD = 13,
			ESL_NEXT_WEAPON = 14,
			ESL_WEAPON_SWITCH_FILTER = 15,
			ESL_WEAPON_SWITCH_FILTER2 = 16,
			ESL_USE = 17,
			ESL_ACTIVATE_MELEE = 18,
			ESL_ACTIVATE_PACK = 19,
			ESL_ACTIVATE_BELT = 20,
			ESL_TOGGLE_MENU_CLASS = 21,
			ESL_SHOW_SCORES = 22,
			ESL_SHOW_OBJECTIVES = 23,
			ESL_DROP_FLAG = 24,
			ESL_TALK = 25,
			ESL_TALK_TEAM = 26,
			ESL_TALK_REPLY = 27,
			ESL_HORN = 28,
			ESL_BEGIN_VGS = 29,
			ESL_CALLIN_ONE = 30,
			ESL_CALLIN_TWO = 31,
			ESL_CALLIN_THREE = 32,
			ESL_TYPE_KEY = 33,
			ESL_WEAPON_PRIMARY = 34,
			ESL_WEAPON_SECONDARY = 35,
			ESL_SWITCH_SEAT_ONE = 36,
			ESL_SWITCH_SEAT_TWO = 37,
			ESL_SWITCH_SEAT_THREE = 38,
			ESL_SWITCH_SEAT_FOUR = 39,
			ESL_SWITCH_SEAT_FIVE = 40,
			ESL_SWITCH_SEAT_SIX = 41,
			ESL_SUICIDE = 42,
			ESL_SPOT_TARGET = 43,
			ESL_THIRD_PERSON = 44,
			ESL_FREE_LOOK = 45,
			ESL_TEAM_SELECT = 46,
			ESL_SUPPRESS_HELP = 47,
			ESL_QUICKCLASSES = 48,
			ESL_FRIENDS = 49,
			ESL_SETTINGS = 50,
			ESL_MAINMENU = 51,
			ESL_HOTKEY1 = 52,
			ESL_HOTKEY2 = 53,
			ESL_HOTKEY3 = 54,
			ESL_HOTKEY4 = 55,
			ESL_HOTKEY5 = 56,
			ESL_HOTKEY6 = 57,
			ESL_HOTKEY7 = 58,
			ESL_HOTKEY8 = 59,
			ESL_HOTKEY9 = 60,
			ESL_CHAT = 61,
			ESL_SPECTATE_MOVEUP = 62,
			ESL_SPECTATE_MOVEDOWN = 63,
			ESL_SPECTATE_MOVEFORWARD = 64,
			ESL_SPECTATE_MOVEBACKWARD = 65,
			ESL_SPECTATE_TURNLEFT = 66,
			ESL_SPECTATE_TURNRIGHT = 67,
			ESL_SPECTATE_STRAFELEFT = 68,
			ESL_SPECTATE_STRAFERIGHT = 69,
			ESL_SPECTATE_CAMERAX = 70,
			ESL_SPECTATE_CAMERAY = 71,
			ESL_SPECTATE_SPEEDINCREASE = 72,
			ESL_SPECTATE_SPEEDDECREASE = 73,
			ESL_SPECTATE_VIEWNEXTPLAYER = 74,
			ESL_SPECTATE_VIEWPREVPLAYER = 75,
			ESL_SPECTATE_VIEWSELF = 76,
			ESL_SPECTATE_VIEWBOOKMARKS = 77,
			ESL_SPECTATE_VIEWGENERATORS = 78,
			ESL_SPECTATE_VIEWSTANDS = 79,
			ESL_SPECTATE_VIEWFLAGS = 80,
			ESL_SPECTATE_SHOWCONTROLS = 81,
			ESL_SPECTATE_SHOWHUD = 82,
			ESL_SPECTATE_SHOWSCORES = 83,
			ESL_SPECTATE_TYPE_KEY = 84,
			ESL_SPECTATE_CHANGETEAM = 85,
			ESL_SPECTATE_VEHICLES = 86,
			ESL_SPECTATE_FASTESTPLAYER = 87,
			ESL_SPECTATE_OBJECTIVES = 88,
			ESL_SPECTATE_LOCKVIEW = 89,
			ESL_KEYBIND_END = 90,
			ESL_CONTROL_START = 91,
			ESL_MOUSESENSITIVITY = 92,
			ESL_FLYINGPITCHSENSITIVITY = 93,
			ESL_FLYINGYAWSENSITIVITY = 94,
			ESL_MOUSEINVERT = 95,
			ESL_VEHICLEINVERT = 96,
			ESL_MOUSESMOOTHING = 97,
			ESL_FOV = 98,
			ESL_TOGGLEZOOM = 99,
			ESL_DISABLEHELP = 100,
			ESL_HUDOBJECTIVES = 101,
			ESL_TINYWEAPONS = 102,
			ESL_DAMAGECOUNTER = 103,
			ESL_ALIENFX = 104,
			ESL_CHATFILTER = 105,
			ESL_SIMULATEDPROJECTILES = 106,
			ESL_HUDFRIENDSNOTIFY = 107,
			ESL_WHISPERNOTIFY = 108,
			ESL_CONTROL_END = 109,
			ESL_AUDIO_START = 110,
			ESL_MASTER = 111,
			ESL_EFFECTS = 112,
			ESL_MUSIC = 113,
			ESL_VGS = 114,
			ESL_VOICE = 115,
			ESL_BASSBOOST = 116,
			ESL_AUDIO_END = 117,
			EAKC_MAX = 118,
			ESettingsList_MAX = 119,
		};
		enum CaHCapturePointLabel : byte
		{
			CaHCapturePoint_A = 0,
			CaHCapturePoint_B = 1,
			CaHCapturePoint_C = 2,
			CaHCapturePoint_D = 3,
			CaHCapturePoint_E = 4,
			CaHCapturePoint_MAX = 5,
		};
		enum ServerPropType : byte
		{
			SPT_GAME = 0,
			SPT_QUEUE = 1,
			SPT_MAX = 2,
		};
		enum TrClassType : byte
		{
			TCT_PTH = 0,
			TCT_SEN = 1,
			TCT_INF = 2,
			TCT_SLD = 3,
			TCT_TCN = 4,
			TCT_RDR = 5,
			TCT_JUG = 6,
			TCT_DMB = 7,
			TCT_BRT = 8,
			TCT_MAX = 9,
		};
		enum LoadoutSlotTypes : byte
		{
			LST_DEFAULT = 0,
			LST_ONE = 1,
			LST_TWO = 2,
			LST_THREE = 3,
			LST_FOUR = 4,
			LST_FIVE = 5,
			LST_MAX = 6,
		};
		enum SpawnTypes : byte
		{
			EST_NORMAL = 0,
			EST_PTHSLDJUG = 1,
			EST_NAKEDPTH = 2,
			EST_MAX = 3,
		};
		enum EContentDataType : byte
		{
			CDT_None = 0,
			CDT_CTF = 1,
			CDT_RemoveFriend = 2,
			CDT_AddFriend = 3,
			CDT_Login = 4,
			CDT_BuyGold = 5,
			CDT_BuyBoost = 6,
			CDT_InviteToParty = 7,
			CDT_JoinGame = 8,
			CDT_MapRoaming = 9,
			CDT_PlayNow = 10,
			CDT_Rabbit = 11,
			CDT_MainMenu = 12,
			CDT_Settings = 13,
			CDT_SkiingTutorial = 14,
			CDT_TeamDeathMatch = 15,
			CDT_TargetPractice = 16,
			CDT_SkiChallenge = 17,
			CDT_QuickMatch = 18,
			CDT_RankedMatch = 19,
			CDT_Arena = 20,
			CDT_Bundle_Inf_Prem = 21,
			CDT_Bundle_Inf_Merc = 22,
			CDT_Bundle_Inf_Asn = 23,
			CDT_Bundle_Inf_Wep = 24,
			CDT_PrivateServer = 25,
			CDT_CaptureAndHold = 26,
			CDT_ChangeName = 27,
			CDT_Bundle_Rdr_Prem = 28,
			CDT_Bundle_Rdr_Gvr = 29,
			CDT_Bundle_Rdr_Merc = 30,
			CDT_Bundle_Rdr_Wep = 31,
			CDT_Bundle_Brt_Wep = 32,
			CDT_Bundle_LoG = 33,
			CDT_StarterPack = 34,
			CDT_Bundle_Twinfusor = 35,
			CDT_Bundle_SkinPack = 36,
			CDT_Bundle_Specialist = 37,
			CDT_Bundle_Sentinel = 38,
			CDT_MAX = 39,
		};
		enum ReticuleDataType : byte
		{
			RDT_TYPE = 0,
			RDT_COLOR = 1,
			RDT_OPACITY = 2,
			RDT_MAX = 3,
		};
		enum EVehicleTypes : byte
		{
			VEHICLE_GravCycle = 0,
			VEHICLE_Shrike = 1,
			VEHICLE_Beowulf = 2,
			VEHICLE_HERC = 3,
			VEHICLE_Havoc = 4,
			VEHICLE_MAX = 5,
		};
		enum EWeaponTracerType : byte
		{
			WTT_PistolBullet = 0,
			WTT_ChainGunBullet = 1,
			WTT_MAX = 2,
		};
		enum DeployModeStatus : byte
		{
			DMS_None = 0,
			DMS_CannotFire = 1,
			DMS_CannotPlace = 2,
			DMS_OK = 3,
			DMS_MAX = 4,
		};
		enum EffectCalcMethod : byte
		{
			TRCM_NA = 0,
			TRCM_ADD = 1,
			TRCM_SUBTRACT = 2,
			TRCM_PERC_INCREASE = 3,
			TRCM_PERC_DECREASE = 4,
			TRCM_STATIC = 5,
			TRCM_MAX = 6,
		};
		enum EffectFormPriority : byte
		{
			TR_EF_NORMAL = 0,
			TR_EF_SHIELD = 1,
			TR_EF_STEALTH = 2,
			TR_EF_MAX = 3,
		};
		enum DeviceAttackType : byte
		{
			TRTT_ATTCK_NA = 0,
			TRTT_ATTACK_INSTANT = 1,
			TRTT_ATTACK_PROJECTILE = 2,
			TRTT_ATTACK_DEPLOYABLE = 3,
			TRTT_ATTACK_SPAWN_PET = 4,
			TRTT_ATTACK_TELEPORT = 5,
			TRTT_MAX = 6,
		};
		enum DeviceTargeterType : byte
		{
			TRDTT_None = 0,
			TRDTT_Self = 1,
			TRDTT_Friend = 2,
			TRDTT_Enemy = 3,
			TRDTT_Enemy_And_Self = 4,
			TRDTT_Friend_Only = 5,
			TRDTT_All = 6,
			TRDTT_MAX = 7,
		};
		enum TR_WIDGET_SUBTYPES : byte
		{
			IST_NONE = 0,
			IST_DEVICE_MELEE = 1,
			IST_DEVICE_RANGED = 2,
			IST_DEVICE_SPECIALTY = 3,
			IST_DEVICE_JETPACK = 4,
			IST_DEVICE_TOGGLE = 5,
			IST_DEVICE_GRENADE = 6,
			IST_DEVICE_BELT = 7,
			IST_DEVICE_DEPLOYABLE = 8,
			IST_DEVICE_REST = 9,
			IST_MAX = 10,
		};
		enum EMissileLock : byte
		{
			EMissileLockNone = 0,
			EMissileLocking = 1,
			EMissileLocked = 2,
			EMissileFired = 3,
			EMissilePotentialTarget = 4,
			EMissileLock_MAX = 5,
		};
		enum TR_EQUIP_POINT : byte
		{
			EQP_NONE = 0,
			EQP_Melee = 1,
			EQP_Primary = 2,
			EQP_Secondary = 3,
			EQP_Pack = 4,
			EQP_Belt = 5,
			EQP_Deployable = 6,
			EQP_LaserTarget = 7,
			EQP_Armor = 8,
			EQP_PerkA = 9,
			EQP_PerkB = 10,
			EQP_Skin = 11,
			EQP_Voice = 12,
			EQP_MAX = 13,
		};
		enum TgSupportedAspectRatios : byte
		{
			TgAR_4x3 = 0,
			TgAR_5x4 = 1,
			TgAR_16x9 = 2,
			TgAR_16x10 = 3,
			TgAR_Other = 4,
			TgAR_MAX = 5,
		};
		enum TrCreditEventType : byte
		{
			PlayerKillEvent = 0,
			PlayerDeathEvent = 1,
			FlagCaptureEvent = 2,
			FlagPickupEvent = 3,
			FlagReturnEvent = 4,
			FiveKillStreakEvent = 5,
			TenKillStreakEvent = 6,
			FifteenKillStreakEvent = 7,
			TwentyKillStreakEvent = 8,
			TwentyFiveKillStreakEvent = 9,
			PlayerKillAssistEvent = 10,
			FiveSnipingStreakEvent = 11,
			TenSnipingStreakEvent = 12,
			FifteenSnipingStreakEvent = 13,
			FiveExplosiveStreakEvent = 14,
			TenExplosiveStreakEvent = 15,
			FifteenExplosiveStreakEvent = 16,
			FiveSpinfusorStreakEvent = 17,
			TenSpinfusorStreakEvent = 18,
			FifteenSpinfusorStreakEvent = 19,
			DoubleKillEvent = 20,
			TripleKillEvent = 21,
			QuatraKillEvent = 22,
			UltraKillEvent = 23,
			TeamKillEvent = 24,
			SpreeEndedEvent = 25,
			RevengeEvent = 26,
			AftermathEvent = 27,
			FirstBloodEvent = 28,
			BluePlateSpecialEvent = 29,
			StickyKillEvent = 30,
			HeadShotEvent = 31,
			ArtilleryShotEvent = 32,
			MeleeKillEvent = 33,
			SquishEvent = 34,
			GeneratorKillEvent = 35,
			GeneratorRepairEvent = 36,
			BaseTurretKillEvent = 37,
			BaseTurretRepairEvent = 38,
			RabbitKillEvent = 39,
			KillAsRabbitEvent = 40,
			FinalBlowEvent = 41,
			SuicideEvent = 42,
			OffhandKillCredit = 43,
			TeamKillCredit = 44,
			TrCreditEventType_MAX = 45,
		};
		enum OverlayType : byte
		{
			OT_UNKNOWN = 0,
			OT_PLAYER = 1,
			OT_OBJECTIVE = 2,
			OT_DEPLOYABLE = 3,
			OT_VEHICLE = 4,
			OT_MAX = 5,
		};
		enum EffectType : byte
		{
			ET_None = 0,
			ET_Hit = 1,
			ET_Fire = 2,
			ET_Equip = 3,
			ET_Active = 4,
			ET_MAX = 5,
		};
		enum DAMAGE_INFO_TYPE : byte
		{
			DIT_Death = 0,
			DIT_Damage = 1,
			DIT_Status = 2,
			DIT_Healing = 3,
			DIT_Objective = 4,
			DIT_Experience = 5,
			DIT_MAX = 6,
		};
		enum TR_HIDEABLE_HUD_ELEMENT : byte
		{
			DeviceBar = 0,
			BuffBar = 1,
			ChatBox = 2,
			AlertBox = 3,
			Minimap = 4,
			MissionInfo = 5,
			PlayerInfo = 6,
			TeamInfo = 7,
			Reticle = 8,
			OmegaAlert = 9,
			AgentInfo = 10,
			QuestTracking = 11,
			AllElements = 12,
			TR_HIDEABLE_HUD_ELEMENT_MAX = 13,
		};
		enum GAME_TYPE : byte
		{
			TGT_CTF = 0,
			TGT_RAB = 1,
			TGT_TDM = 2,
			TGT_ARN = 3,
			TGT_CAH = 4,
			TGT_MAX = 5,
		};
		enum GAME_WIN_STATE : byte
		{
			GWS_NONE = 0,
			GWS_DEFENDER_WON = 1,
			GWS_ATTACKER_WON = 2,
			GWS_TIE = 3,
			GWS_MAX = 4,
		};
		struct PaperDollInfo
		{
		public:
			ADD_BOOL(bIsLoading, 52, 0x2)
			ADD_BOOL(bIsStreaming, 52, 0x1)
			ADD_STRUCT(float, CharacterLightingContrastFactor, 48)
			ADD_BOOL(bOnlySelfShadow, 44, 0x1)
			ADD_OBJECT(AnimSet, AnimSet, 40)
			ADD_OBJECT(AnimTree, AnimTreeTemplate, 36)
			ADD_OBJECT(PhysicsAsset, PhysAsset, 32)
			ADD_OBJECT(SkeletalMesh, SkelMesh, 28)
			ADD_STRUCT(float, Scale, 24)
			ADD_STRUCT(Rotator, Rotation, 12)
			ADD_STRUCT(Vector, Translation, 0)
		};
		struct TrTakeEffectInfo
		{
		public:
			ADD_STRUCT(Vector, HitLocation, 0)
			ADD_OBJECT(ScriptClass, EffectForm, 12)
		};
		struct TrTakeHitInfo
		{
		public:
			ADD_STRUCT(int, Damage, 0)
			ADD_STRUCT(Vector, HitLocation, 4)
			ADD_STRUCT(Vector, Momentum, 16)
			ADD_OBJECT(ScriptClass, DamageType, 28)
			ADD_STRUCT(ScriptName, HitBone, 32)
		};
		struct OffhandAnimation
		{
		public:
			ADD_STRUCT(ScriptName, m_OffhandUseType, 0)
			ADD_STRUCT(ScriptName, m_AnimName, 8)
			ADD_BOOL(m_bFullBody, 16, 0x1)
		};
		struct ObjectiveMICInfo
		{
		public:
			ADD_STRUCT(int, MyTeam, 0)
			ADD_STRUCT(float, AmountFilled, 4)
			ADD_STRUCT(int, ObjStatus, 8)
			ADD_STRUCT(int, IsContested, 12)
			ADD_STRUCT(int, Flip, 16)
		};
		struct EffectFormOverwrite
		{
		public:
			ADD_OBJECT(Material, Mat, 4)
			ADD_STRUCT(TrObject::EffectFormMatTypes, eType, 0)
		};
		struct TrEventCredits
		{
		public:
			ADD_STRUCT(TrObject::TrCreditEventType, EventType, 0)
			ADD_STRUCT(int, eventCredits, 4)
			ADD_STRUCT(int, proxyEventCredits, 8)
			ADD_STRUCT(int, MsgIdx, 12)
			ADD_BOOL(bIsBroadcast, 16, 0x1)
		};
		struct TR_HUD_INFO
		{
		public:
			ADD_STRUCT(Vector, vScreenLoc, 0)
			ADD_STRUCT(float, fScale, 12)
			ADD_STRUCT(float, fAlphaLevel, 16)
			ADD_STRUCT(float, fLastSeenTime, 20)
			ADD_STRUCT(float, fLastUnseenTime, 24)
			ADD_BOOL(bIsTarget, 28, 0x1)
			ADD_STRUCT(ScriptString*, sName, 32)
			ADD_STRUCT(int, nHealth, 44)
			ADD_STRUCT(int, nMaxHealth, 48)
			ADD_BOOL(bEnemy, 52, 0x1)
			ADD_BOOL(bDrawStat, 52, 0x2)
			ADD_BOOL(bDrawHealth, 52, 0x4)
			ADD_STRUCT(float, fDistance, 56)
			ADD_STRUCT(TrObject::OverlayType, eOverlayType, 60)
			ADD_STRUCT(int, nActorId, 64)
		};
	};
	const float TrObject::FADE_TIME = 1.0f;
	const float TrObject::UnrealUnitsToKM = 0.072f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
