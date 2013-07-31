#pragma once
#include "UDKBase.UDKPlayerController.h"
#include "UTGame.UTAnnouncer.h"
#include "UTGame.UTUIDataStore_StringAliasBindingsMap.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTMusicManager.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.CameraAnim.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.OnlineSubsystem.h"
#include "UTGame.UTSeqAct_PlayCameraAnim.h"
#include "Engine.SpeechRecognition.h"
#include "Engine.SoundCue.h"
#include "Engine.SavedMove.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "UTGame.UTVehicle.h"
#include "Engine.Projectile.h"
#include "Engine.HUD.h"
#include "Engine.Camera.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTSeqAct_StopCameraAnim.h"
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
	class UTPlayerController : public UDKPlayerController
	{
	public:
		static const auto STATS_VIEW_DM_WEAPONS_RANKED_ALLTIME = 8;
		static const auto STATS_VIEW_DM_VEHICLEWEAPONS_RANKED_ALLTIME = 7;
		static const auto STATS_VIEW_DM_VEHICLES_RANKED_ALLTIME = 6;
		static const auto STATS_VIEW_DM_VEHICLEWEAPONS_ALLTIME = 5;
		static const auto STATS_VIEW_DM_VEHICLES_ALLTIME = 4;
		static const auto STATS_VIEW_DM_WEAPONS_ALLTIME = 3;
		static const auto STATS_VIEW_DM_RANKED_ALLTIME = 2;
		static const auto STATS_VIEW_DM_PLAYER_ALLTIME = 1;
		static const auto QUERY_CAMPAIGN = 6;
		static const auto QUERY_DUEL = 5;
		static const auto QUERY_WAR = 4;
		static const auto QUERY_VCTF = 3;
		static const auto QUERY_CTF = 2;
		static const auto QUERY_TDM = 1;
		static const auto QUERY_DM = 0;
		static const auto PROPERTY_CUSTOMMUTATORS = 0x40000004;
		static const auto PROPERTY_SERVERDESCRIPTION = 0x40000003;
		static const auto PROPERTY_CUSTOMGAMEMODE = 0x40000002;
		static const auto PROPERTY_CUSTOMMAPNAME = 0x40000001;
		static const auto PROPERTY_EPICMUTATORS = 0x10000105;
		static const auto PROPERTY_LEADERBOARDRATING = 0x20000004;
		static const auto PROPERTY_GOALSCORE = 0x1000000B;
		static const auto PROPERTY_TIMELIMIT = 0x1000000A;
		static const auto PROPERTY_NUMBOTS = 0x100000F7;
		static const auto CONTEXT_VSBOTS_4_TO_1 = 6;
		static const auto CONTEXT_VSBOTS_3_TO_1 = 5;
		static const auto CONTEXT_VSBOTS_2_TO_1 = 4;
		static const auto CONTEXT_VSBOTS_3_TO_2 = 3;
		static const auto CONTEXT_VSBOTS_1_TO_1 = 2;
		static const auto CONTEXT_VSBOTS_1_TO_2 = 1;
		static const auto CONTEXT_VSBOTS_NONE = 0;
		static const auto CONTEXT_DEDICATEDSERVER_YES = 1;
		static const auto CONTEXT_DEDICATEDSERVER_NO = 0;
		static const auto CONTEXT_EMPTYSERVER_YES = 1;
		static const auto CONTEXT_EMPTYSERVER_NO = 0;
		static const auto CONTEXT_FULLSERVER_YES = 1;
		static const auto CONTEXT_FULLSERVER_NO = 0;
		static const auto CONTEXT_ALLOWKEYBOARD_ANY = 2;
		static const auto CONTEXT_ALLOWKEYBOARD_YES = 1;
		static const auto CONTEXT_ALLOWKEYBOARD_NO = 0;
		static const auto CONTEXT_FORCERESPAWN_YES = 1;
		static const auto CONTEXT_FORCERESPAWN_NO = 0;
		static const auto CONTEXT_CAMPAIGN_YES = 1;
		static const auto CONTEXT_CAMPAIGN_NO = 0;
		static const auto CONTEXT_LOCKEDSERVER_YES = 1;
		static const auto CONTEXT_LOCKEDSERVER_NO = 0;
		static const auto CONTEXT_PURESERVER_ANY = 2;
		static const auto CONTEXT_PURESERVER_YES = 1;
		static const auto CONTEXT_PURESERVER_NO = 0;
		static const auto CONTEXT_TIMELIMIT_30 = 4;
		static const auto CONTEXT_TIMELIMIT_20 = 3;
		static const auto CONTEXT_TIMELIMIT_15 = 2;
		static const auto CONTEXT_TIMELIMIT_10 = 1;
		static const auto CONTEXT_TIMELIMIT_5 = 0;
		static const auto CONTEXT_NUMBOTS_8 = 8;
		static const auto CONTEXT_NUMBOTS_7 = 7;
		static const auto CONTEXT_NUMBOTS_6 = 6;
		static const auto CONTEXT_NUMBOTS_5 = 5;
		static const auto CONTEXT_NUMBOTS_4 = 4;
		static const auto CONTEXT_NUMBOTS_3 = 3;
		static const auto CONTEXT_NUMBOTS_2 = 2;
		static const auto CONTEXT_NUMBOTS_1 = 1;
		static const auto CONTEXT_NUMBOTS_0 = 0;
		static const auto CONTEXT_GOALSCORE_30 = 4;
		static const auto CONTEXT_GOALSCORE_20 = 3;
		static const auto CONTEXT_GOALSCORE_15 = 2;
		static const auto CONTEXT_GOALSCORE_10 = 1;
		static const auto CONTEXT_GOALSCORE_5 = 0;
		static const auto CONTEXT_BOTSKILL_GODLIKE = 7;
		static const auto CONTEXT_BOTSKILL_INHUMAN = 6;
		static const auto CONTEXT_BOTSKILL_MASTERFUL = 5;
		static const auto CONTEXT_BOTSKILL_ADEPT = 4;
		static const auto CONTEXT_BOTSKILL_SKILLED = 3;
		static const auto CONTEXT_BOTSKILL_EXPERIENCED = 2;
		static const auto CONTEXT_BOTSKILL_AVERAGE = 1;
		static const auto CONTEXT_BOTSKILL_NOVICE = 0;
		static const auto CONTEXT_MAPNAME_CUSTOM = 0;
		static const auto CONTEXT_DEDICATEDSERVER = 17;
		static const auto CONTEXT_EMPTYSERVER = 16;
		static const auto CONTEXT_FULLSERVER = 15;
		static const auto CONTEXT_FORCERESPAWN = 14;
		static const auto CONTEXT_CAMPAIGN = 13;
		static const auto CONTEXT_VSBOTS = 12;
		static const auto CONTEXT_PURESERVER = 11;
		static const auto CONTEXT_BOTSKILL = 10;
		static const auto CONTEXT_ALLOWKEYBOARD = 2;
		static const auto CONTEXT_LOCKEDSERVER = 1;
		static const auto CONTEXT_MAPNAME = 0;
		static const auto CONTEXT_GAME_MODE_CAMPAIGN = 7;
		static const auto CONTEXT_GAME_MODE_CUSTOM = 6;
		static const auto CONTEXT_GAME_MODE_DUEL = 5;
		static const auto CONTEXT_GAME_MODE_TDM = 4;
		static const auto CONTEXT_GAME_MODE_VCTF = 3;
		static const auto CONTEXT_GAME_MODE_WAR = 2;
		static const auto CONTEXT_GAME_MODE_CTF = 1;
		static const auto CONTEXT_GAME_MODE_DM = 0;
		static const auto CONTEXT_GAME_MODE = 0x0000800B;
		static const auto CONTEXT_PRESENCE_MENUPRESENCE = 0;
		static const auto GS_CDKEY_PART_MAXLENGTH = 4;
		static const auto GS_EMAIL_MAXLENGTH = 50;
		static const auto GS_MESSAGE_MAXLENGTH = 255;
		static const auto GS_PASSWORD_MAXLENGTH = 30;
		static const auto GS_USERNAME_MAXLENGTH = 15;
		enum EWeaponHand : byte
		{
			HAND_Right = 0,
			HAND_Left = 1,
			HAND_Centered = 2,
			HAND_Hidden = 3,
			HAND_MAX = 4,
		};
		enum EPawnShadowMode : byte
		{
			SHADOW_None = 0,
			SHADOW_Self = 1,
			SHADOW_All = 2,
			SHADOW_MAX = 3,
		};
		enum EAutoObjectivePreference : byte
		{
			AOP_Disabled = 0,
			AOP_NoPreference = 1,
			AOP_Attack = 2,
			AOP_Defend = 3,
			AOP_OrbRunner = 4,
			AOP_SpecialOps = 5,
			AOP_MAX = 6,
		};
		enum EUTVehicleControls : byte
		{
			UTVC_Simple = 0,
			UTVC_Normal = 1,
			UTVC_Advanced = 2,
			UTVC_MAX = 3,
		};
		struct PostProcessInfo
		{
		public:
			ADD_STRUCT(float, Desaturation, 12)
			ADD_STRUCT(float, HighLights, 8)
			ADD_STRUCT(float, MidTones, 4)
			ADD_STRUCT(float, Shadows, 0)
		};
		ADD_BOOL(bLateComer, 1960, 0x1)
		ADD_OBJECT(UTUIDataStore_StringAliasBindingsMap, BoundEventsStringDataStore, 2152)
		ADD_BOOL(bQuittingToMainMenu, 1960, 0x20000)
		ADD_BOOL(bJustFoundVehicle, 1960, 0x80000)
		ADD_BOOL(bLandingShake, 1960, 0x4000)
		ADD_STRUCT(float, LastWarningTime, 2100)
		ADD_STRUCT(float, LastTauntAnimTime, 1992)
		ADD_BOOL(bIsTyping, 1960, 0x2)
		ADD_OBJECT(UTAnnouncer, Announcer, 1984)
		ADD_OBJECT(UTMusicManager, MusicManager, 1988)
		ADD_BOOL(bBehindView, 1960, 0x80)
		ADD_STRUCT(float, LastKickWarningTime, 1996)
		ADD_STRUCT(float, OnFootDefaultFOV, 2160)
		ADD_STRUCT(UTPlayerController::EWeaponHand, WeaponHandPreference, 1966)
		ADD_BOOL(bAutoTaunt, 1960, 0x4)
		ADD_BOOL(bCenteredWeaponFire, 1960, 0x8000)
		ADD_STRUCT(UTPlayerController::EAutoObjectivePreference, AutoObjectivePreference, 1968)
		ADD_STRUCT(UTPlayerController::EUTVehicleControls, VehicleControlType, 1969)
		ADD_STRUCT(UTPlayerController::EPawnShadowMode, PawnShadowMode, 1965)
		ADD_OBJECT(Actor, LastAutoObjective, 2132)
		ADD_STRUCT(float, LastShowPathTime, 2128)
		ADD_BOOL(bUseVehicleRotationOnPossess, 1960, 0x8)
		ADD_STRUCT(byte, IdentifiedTeam, 1964)
		ADD_STRUCT(UTPlayerController::EWeaponHand, WeaponHand, 1967)
		ADD_STRUCT(float, LastUseTime, 2140)
		ADD_BOOL(bAlreadyReset, 1960, 0x400000)
		ADD_OBJECT(Actor, CalcViewActor, 2032)
		ADD_BOOL(bFreeCamera, 1960, 0x200)
		ADD_STRUCT(float, LastCameraTimeStamp, 2024)
		ADD_BOOL(bDebugFreeCam, 1960, 0x40000)
		ADD_STRUCT(Rotator, DebugFreeCamRot, 2116)
		ADD_OBJECT(ScriptClass, MatineeCameraClass, 2028)
		ADD_STRUCT(Vector, CalcViewActorLocation, 2036)
		ADD_STRUCT(Rotator, CalcViewActorRotation, 2048)
		ADD_STRUCT(float, CalcEyeHeight, 2084)
		ADD_STRUCT(Vector, CalcWalkBob, 2088)
		ADD_STRUCT(Vector, CalcViewLocation, 2060)
		ADD_STRUCT(Rotator, CalcViewRotation, 2072)
		ADD_OBJECT(CameraAnim, DamageCameraAnim, 2020)
		ADD_BOOL(bCurrentCamAnimIsDamageShake, 1960, 0x1000)
		ADD_BOOL(bCurrentCamAnimAffectsFOV, 1960, 0x2000)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeShortWaveForm, 2012)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeLongWaveForm, 2016)
		ADD_BOOL(bCameraOutOfWorld, 1960, 0x20)
		ADD_STRUCT(ScriptString*, MsgPlayerNotFound, 2000)
		ADD_BOOL(bServerMutedText, 1960, 0x800000)
		ADD_BOOL(bNonlinearZoomInterpolation, 1960, 0x10000)
		ADD_STRUCT(float, FOVNonlinearZoomInterpSpeed, 2108)
		ADD_STRUCT(float, FOVLinearZoomRate, 2104)
		ADD_STRUCT(float, LastBullseyeTime, 2136)
		ADD_STRUCT(float, LastTeamChangeTime, 2172)
		ADD_BOOL(bNoTextToSpeechVoiceMessages, 1960, 0x400)
		ADD_BOOL(bTextToSpeechTeamMessagesOnly, 1960, 0x800)
		ADD_STRUCT(float, NextAdminCmdTime, 2156)
		ADD_BOOL(bRotateMinimap, 1960, 0x10)
		ADD_BOOL(bFirstPersonWeaponsSelfShadow, 1960, 0x40)
		ADD_BOOL(bForceBehindView, 1960, 0x100)
		ADD_BOOL(bNoCrosshair, 1960, 0x100000)
		ADD_BOOL(bSimpleCrosshair, 1960, 0x200000)
		ADD_BOOL(bHideObjectivePaths, 1960, 0x1000000)
		ADD_STRUCT(Vector, DesiredLocation, 1972)
		ADD_STRUCT(float, ZoomRotationModifier, 2112)
		ADD_STRUCT(float, OldMessageTime, 2144)
		ADD_STRUCT(float, LastFriendlyFireTime, 2148)
		ADD_STRUCT(float, LastIncomingMessageTime, 2164)
		ADD_STRUCT(float, LastCombatUpdateTime, 2168)
		void ServerThrowWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36302);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36303);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseTeamColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36305);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetCharacterClass(ScriptClass* CharClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36306);
			byte params[4] = { NULL };
			*(ScriptClass**)params = CharClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStringAliasBindingMapCache()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36314);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCustomPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36316);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36321);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddOnlineDelegates(bool bRegisterVoice)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36324);
			byte params[4] = { NULL };
			*(bool*)params = bRegisterVoice;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearOnlineDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36326);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetOnlineStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36328);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36337);
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36341);
			byte params[4] = { NULL };
			*(bool*)params = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36344);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* RequestingNick)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36347);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36350);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36355);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyInviteFailed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36360);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotAllPlayersCanJoinInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36361);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotEnoughSpaceInInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36362);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWasKicked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36363);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFrontEndErrorMessage(ScriptString* Title, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36364);
			byte params[24] = { NULL };
			*(ScriptString**)params = Title;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36367);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishQuitToMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36369);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CleanupOnlineSubsystemSession(bool bWasFromMenu)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36370);
			byte params[8] = { NULL };
			*(bool*)params = bWasFromMenu;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36373);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36376);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetSpeechRecognitionObject(class SpeechRecognition* NewRecognitionData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36379);
			byte params[4] = { NULL };
			*(class SpeechRecognition**)params = NewRecognitionData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpeechRecognitionComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36381);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerProcessSpeechRecognition(OnlineSubsystem::SpeechRecognizedWord ReplicatedWords)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36386);
			byte params[20] = { NULL };
			*(OnlineSubsystem::SpeechRecognizedWord*)params = ReplicatedWords;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36392);
			byte params[28] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36399);
			byte params[8] = { NULL };
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36403);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36406);
			byte params[28] = { NULL };
			*(class Weapon**)params = W;
			*(Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36419);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class UTVehicle* CheckPickedVehicle(class UTVehicle* V, bool bEnterVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36421);
			byte params[12] = { NULL };
			*(class UTVehicle**)params = V;
			*(bool*)&params[4] = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[8];
		}
		void ClientSetRequestedEntryWithFlag(class UTVehicle* V, bool bNewValue, int MessageIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36432);
			byte params[12] = { NULL };
			*(class UTVehicle**)params = V;
			*(bool*)&params[4] = bNewValue;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTVehicle* CheckVehicleToDrive(bool bEnterVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36438);
			byte params[8] = { NULL };
			*(bool*)params = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		void DropFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36455);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerDropFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool LandingShake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36457);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PlayBeepSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36460);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36461);
			byte params[20] = { NULL };
			*(class Pawn**)params = shooter;
			*(float*)&params[4] = projSpeed;
			*(Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36466);
			byte params[4] = { NULL };
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProjectileWarningTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36468);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWinMessage(bool bWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36469);
			byte params[4] = { NULL };
			*(bool*)params = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36471);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PlayVehicleHorn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36483);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPlayVehicleHorn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36486);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Typing(bool bTyping)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36488);
			byte params[4] = { NULL };
			*(bool*)params = bTyping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36491);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36494);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36498);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36501);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36503);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36506);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36509);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36512);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36513);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36515);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36524);
			byte params[20] = { NULL };
			*(class Actor**)params = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckAutoObjective(bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36532);
			byte params[4] = { NULL };
			*(bool*)params = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAutoObjective(class Actor* ObjectiveActor, bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36538);
			byte params[8] = { NULL };
			*(class Actor**)params = ObjectiveActor;
			*(bool*)&params[4] = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetAutoObjective(class Actor* NewAutoObjective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36549);
			byte params[4] = { NULL };
			*(class Actor**)params = NewAutoObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36553);
			byte params[8] = { NULL };
			*(class Pawn**)params = inPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36556);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IdentifyTeamMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36561);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36563);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPlayerPreferences(UTPlayerController::EWeaponHand NewWeaponHand, bool bNewAutoTaunt, bool bNewCenteredWeaponFire, UTPlayerController::EAutoObjectivePreference NewAutoObjectivePreference, UTPlayerController::EUTVehicleControls NewVehicleControls)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36564);
			byte params[11] = { NULL };
			*(UTPlayerController::EWeaponHand*)params = NewWeaponHand;
			*(bool*)&params[4] = bNewAutoTaunt;
			*(bool*)&params[8] = bNewCenteredWeaponFire;
			*(UTPlayerController::EAutoObjectivePreference*)&params[12] = NewAutoObjectivePreference;
			*(UTPlayerController::EUTVehicleControls*)&params[13] = NewVehicleControls;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetHand(UTPlayerController::EWeaponHand NewWeaponHand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36570);
			byte params[1] = { NULL };
			*(UTPlayerController::EWeaponHand*)params = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHand(UTPlayerController::EWeaponHand NewWeaponHand)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36573);
			byte params[1] = { NULL };
			*(UTPlayerController::EWeaponHand*)params = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36575);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36576);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerSetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36578);
			byte params[4] = { NULL };
			*(bool*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36580);
			byte params[4] = { NULL };
			*(bool*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleScreenShotMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36582);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36585);
			byte params[1] = { NULL };
			*params = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36589);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayTakeHit(Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36596);
			byte params[17] = { NULL };
			*(Vector*)params = HitLoc;
			params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ServerUse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36600);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool Use()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36603);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36606);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearDoubleClick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36611);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36720);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36767);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36772);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36773);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BehindView()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36775);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36776);
			byte params[4] = { NULL };
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36780);
			byte params[4] = { NULL };
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36782);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36786);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36789);
			byte params[24] = { NULL };
			*(Vector*)params = POVLocation;
			*(Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)&params[12];
		}
		void CalcCameraOnViewTarget(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36802);
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
		void ClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36807);
			byte params[4] = { NULL };
			*(int*)params = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AlreadyInActionMusic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36809);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClientPlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36814);
			byte params[16] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36819);
			byte params[16] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DamageShake(int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36825);
			byte params[8] = { NULL };
			*(int*)params = Damage;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopViewShaking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36834);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bIsDamageShake)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36835);
			byte params[28] = { NULL };
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)&params[4] = Scale;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bIsDamageShake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopCameraAnim(bool bImmediate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36847);
			byte params[4] = { NULL };
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraAnimStrength(float NewStrength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36849);
			byte params[4] = { NULL };
			*(float*)params = NewStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, Camera::ECameraAnimPlaySpace Space, Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36851);
			byte params[41] = { NULL };
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)&params[4] = Scale;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bRandomStartTime;
			*(Camera::ECameraAnimPlaySpace*)&params[28] = Space;
			*(Rotator*)&params[32] = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36861);
			byte params[4] = { NULL };
			*(class CameraAnim**)params = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayCameraAnim(class UTSeqAct_PlayCameraAnim* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36863);
			byte params[4] = { NULL };
			*(class UTSeqAct_PlayCameraAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStopCameraAnim(class UTSeqAct_StopCameraAnim* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36871);
			byte params[4] = { NULL };
			*(class UTSeqAct_StopCameraAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36874);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleMelee()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleTranslocator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36878);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CallServerMove(class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36879);
			byte params[25] = { NULL };
			*(class SavedMove**)params = NewMove;
			*(Vector*)&params[4] = ClientLoc;
			params[16] = ClientRoll;
			*(int*)&params[20] = View;
			*(class SavedMove**)&params[24] = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShortServerMove(float TimeStamp, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36889);
			byte params[22] = { NULL };
			*(float*)params = TimeStamp;
			*(Vector*)&params[4] = ClientLoc;
			params[16] = NewFlags;
			params[17] = ClientRoll;
			*(int*)&params[20] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LongClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36895);
			byte params[53] = { NULL };
			*(float*)params = TimeStamp;
			*(ScriptName*)&params[4] = NewState;
			*(Actor::EPhysics*)&params[12] = newPhysics;
			*(float*)&params[16] = NewLocX;
			*(float*)&params[20] = NewLocY;
			*(float*)&params[24] = NewLocZ;
			*(float*)&params[28] = NewVelX;
			*(float*)&params[32] = NewVelY;
			*(float*)&params[36] = NewVelZ;
			*(class Actor**)&params[40] = NewBase;
			*(float*)&params[44] = NewFloorX;
			*(float*)&params[48] = NewFloorY;
			*(float*)&params[52] = NewFloorZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewNextBot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36929);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36930);
			byte params[1] = { NULL };
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36932);
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewPlayerByName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36936);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewPlayerByName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36938);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36942);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36943);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36944);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36945);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustCameraScale(bool bIn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36946);
			byte params[4] = { NULL };
			*(bool*)params = bIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36967);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36970);
			byte params[12] = { NULL };
			*(ScriptName*)params = TabTag;
			*(bool*)&params[8] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36974);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36977);
			byte params[4] = { NULL };
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRoundEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36979);
			byte params[4] = { NULL };
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36981);
			byte params[40] = { NULL };
			*(class SoundCue**)params = BulletWhip;
			*(Vector*)&params[4] = FireLocation;
			*(Vector*)&params[16] = FireDir;
			*(Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36989);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPawnDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36991);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyFOVAngle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36992);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustFOV(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36993);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(float NewDesiredFOV, float NewZoomRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(36999);
			byte params[8] = { NULL };
			*(float*)params = NewDesiredFOV;
			*(float*)&params[4] = NewZoomRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoomNonlinear(float NewDesiredFOV, float NewZoomInterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37002);
			byte params[8] = { NULL };
			*(float*)params = NewDesiredFOV;
			*(float*)&params[4] = NewZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37005);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37006);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndZoomNonlinear(float ZoomInterpSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37007);
			byte params[4] = { NULL };
			*(float*)params = ZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientEndZoom()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37009);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37010);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CharacterProcessingComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37013);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37016);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37018);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveBotVoiceMessage(class UTPlayerReplicationInfo* SenderPRI, int MessageIndex, class Object* LocationObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37024);
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)params = SenderPRI;
			*(int*)&params[4] = MessageIndex;
			*(class Object**)&params[8] = LocationObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37028);
			byte params[4] = { NULL };
			*(int*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BullseyeMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37030);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37035);
			byte params[4] = { NULL };
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37038);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void ServerKickBan(ScriptString* PlayerToKick, bool bBan)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37042);
			byte params[16] = { NULL };
			*(ScriptString**)params = PlayerToKick;
			*(bool*)&params[12] = bBan;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37045);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ServerSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37053);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37055);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37057);
			byte params[16] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AdminCmdOk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37060);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void AdminLogin(ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37063);
			byte params[12] = { NULL };
			*(ScriptString**)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdminLogin(ScriptString* Password)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37065);
			byte params[12] = { NULL };
			*(ScriptString**)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminLogout()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37067);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAdminLogOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37068);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Admin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37069);
			byte params[12] = { NULL };
			*(ScriptString**)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdmin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37071);
			byte params[12] = { NULL };
			*(ScriptString**)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminKickBan(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37074);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminKick(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37076);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminPlayerList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37078);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdminRestartMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37080);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37081);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdminChangeMap(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37082);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeMap(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37084);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceVoiceMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37086);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceVoiceMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37088);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceVoiceUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37092);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceVoiceUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37094);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceTextMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37098);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceTextMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37100);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceTextUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37103);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceTextUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37105);
			byte params[12] = { NULL };
			*(ScriptString**)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Disconnect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37108);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(37109);
			byte params[4] = { NULL };
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
