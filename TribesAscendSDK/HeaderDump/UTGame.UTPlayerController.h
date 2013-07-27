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
		static const auto CONTEXT_VSBOTS_4_TO = 6;
		static const auto CONTEXT_VSBOTS_3_TO = 5;
		static const auto CONTEXT_VSBOTS_2_TO = 4;
		static const auto CONTEXT_VSBOTS_3_TO = 3;
		static const auto CONTEXT_VSBOTS_1_TO = 2;
		static const auto CONTEXT_VSBOTS_1_TO = 1;
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
		static const auto CONTEXT_TIMELIMIT = 4;
		static const auto CONTEXT_TIMELIMIT = 3;
		static const auto CONTEXT_TIMELIMIT = 2;
		static const auto CONTEXT_TIMELIMIT = 1;
		static const auto CONTEXT_TIMELIMIT = 0;
		static const auto CONTEXT_NUMBOTS = 8;
		static const auto CONTEXT_NUMBOTS = 7;
		static const auto CONTEXT_NUMBOTS = 6;
		static const auto CONTEXT_NUMBOTS = 5;
		static const auto CONTEXT_NUMBOTS = 4;
		static const auto CONTEXT_NUMBOTS = 3;
		static const auto CONTEXT_NUMBOTS = 2;
		static const auto CONTEXT_NUMBOTS = 1;
		static const auto CONTEXT_NUMBOTS = 0;
		static const auto CONTEXT_GOALSCORE = 4;
		static const auto CONTEXT_GOALSCORE = 3;
		static const auto CONTEXT_GOALSCORE = 2;
		static const auto CONTEXT_GOALSCORE = 1;
		static const auto CONTEXT_GOALSCORE = 0;
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
		class PostProcessInfo
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
		ADD_STRUCT(Object::Rotator, DebugFreeCamRot, 2116)
		ADD_OBJECT(ScriptClass, MatineeCameraClass, 2028)
		ADD_STRUCT(Object::Vector, CalcViewActorLocation, 2036)
		ADD_STRUCT(Object::Rotator, CalcViewActorRotation, 2048)
		ADD_STRUCT(float, CalcEyeHeight, 2084)
		ADD_STRUCT(Object::Vector, CalcWalkBob, 2088)
		ADD_STRUCT(Object::Vector, CalcViewLocation, 2060)
		ADD_STRUCT(Object::Rotator, CalcViewRotation, 2072)
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
		ADD_STRUCT(Object::Vector, DesiredLocation, 1972)
		ADD_STRUCT(float, ZoomRotationModifier, 2112)
		ADD_STRUCT(float, OldMessageTime, 2144)
		ADD_STRUCT(float, LastFriendlyFireTime, 2148)
		ADD_STRUCT(float, LastIncomingMessageTime, 2164)
		ADD_STRUCT(float, LastCombatUpdateTime, 2168)
		void ServerThrowWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerThrowWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseTeamColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PulseTeamColor");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetCharacterClass(ScriptClass* CharClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetCharacterClass");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = CharClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearStringAliasBindingMapCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClearStringAliasBindingMapCache");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCustomPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.RegisterCustomPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.UnregisterPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddOnlineDelegates(bool bRegisterVoice)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AddOnlineDelegates");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bRegisterVoice;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearOnlineDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClearOnlineDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetOnlineStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetOnlineStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnConnectionStatusChange");
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)&params[0] = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnLinkStatusChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnReadProfileSettingsComplete");
			byte params[5] = { NULL };
			params[0] = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* RequestingNick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnGameInviteReceived");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnFriendInviteReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnFriendMessageReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyInviteFailed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NotifyInviteFailed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotAllPlayersCanJoinInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NotifyNotAllPlayersCanJoinInvite");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotEnoughSpaceInInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NotifyNotEnoughSpaceInInvite");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWasKicked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientWasKicked");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFrontEndErrorMessage(ScriptString* Title, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetFrontEndErrorMessage");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Title;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.QuitToMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishQuitToMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FinishQuitToMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CleanupOnlineSubsystemSession(bool bWasFromMenu)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CleanupOnlineSubsystemSession");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bWasFromMenu;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnEndOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnDestroyOnlineGameComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetSpeechRecognitionObject(class SpeechRecognition* NewRecognitionData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetSpeechRecognitionObject");
			byte params[4] = { NULL };
			*(class SpeechRecognition**)&params[0] = NewRecognitionData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpeechRecognitionComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SpeechRecognitionComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerProcessSpeechRecognition(OnlineSubsystem::SpeechRecognizedWord ReplicatedWords)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerProcessSpeechRecognition");
			byte params[20] = { NULL };
			*(OnlineSubsystem::SpeechRecognizedWord*)&params[0] = ReplicatedWords;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Object::Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientHearSound");
			byte params[28] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Object::Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AimingHelp");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AimHelpModifier");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* W, Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = W;
			*(Object::Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FindVehicleToDrive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class UTVehicle* CheckPickedVehicle(class UTVehicle* V, bool bEnterVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckPickedVehicle");
			byte params[12] = { NULL };
			*(class UTVehicle**)&params[0] = V;
			*(bool*)&params[4] = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[8];
		}
		void ClientSetRequestedEntryWithFlag(class UTVehicle* V, bool bNewValue, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetRequestedEntryWithFlag");
			byte params[12] = { NULL };
			*(class UTVehicle**)&params[0] = V;
			*(bool*)&params[4] = bNewValue;
			*(int*)&params[8] = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTVehicle* CheckVehicleToDrive(bool bEnterVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckVehicleToDrive");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		void DropFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DropFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerDropFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerDropFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool LandingShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.LandingShake");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PlayBeepSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayBeepSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Object::Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveWarning");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = shooter;
			*(float*)&params[4] = projSpeed;
			*(Object::Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveProjectileWarning");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProjectileWarningTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ProjectileWarningTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWinMessage(bool bWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayWinMessage");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.TriggerInteracted");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PlayVehicleHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayVehicleHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPlayVehicleHorn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerPlayVehicleHorn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Typing(bool bTyping)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Typing");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bTyping;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnControllerChanged");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SoakPause");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DrawHUD");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.KickWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckJumpOrDuck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FixFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Restart");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientRestart");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetViewTarget");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckAutoObjective(bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckAutoObjective");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAutoObjective(class Actor* ObjectiveActor, bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetAutoObjective");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = ObjectiveActor;
			*(bool*)&params[4] = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetAutoObjective(class Actor* NewAutoObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetAutoObjective");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewAutoObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Possess");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = inPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AcknowledgePossession");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IdentifyTeamMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.IdentifyTeamMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceivedPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPlayerPreferences(UTPlayerController::EWeaponHand NewWeaponHand, bool bNewAutoTaunt, bool bNewCenteredWeaponFire, UTPlayerController::EAutoObjectivePreference NewAutoObjectivePreference, UTPlayerController::EUTVehicleControls NewVehicleControls)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerPlayerPreferences");
			byte params[11] = { NULL };
			*(UTPlayerController::EWeaponHand*)&params[0] = NewWeaponHand;
			*(bool*)&params[4] = bNewAutoTaunt;
			*(bool*)&params[8] = bNewCenteredWeaponFire;
			*(UTPlayerController::EAutoObjectivePreference*)&params[12] = NewAutoObjectivePreference;
			*(UTPlayerController::EUTVehicleControls*)&params[13] = NewVehicleControls;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetHand(UTPlayerController::EWeaponHand NewWeaponHand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetHand");
			byte params[1] = { NULL };
			*(UTPlayerController::EWeaponHand*)&params[0] = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHand(UTPlayerController::EWeaponHand NewWeaponHand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetHand");
			byte params[1] = { NULL };
			*(UTPlayerController::EWeaponHand*)&params[0] = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ResetCameraMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.UsingFirstPersonCamera");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerSetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetAutoTaunt");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetAutoTaunt");
			byte params[4] = { NULL };
			*(bool*)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleScreenShotMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ToggleScreenShotMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayStartupMessage");
			byte params[1] = { NULL };
			params[0] = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayTakeHit(Object::Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayTakeHit");
			byte params[17] = { NULL };
			*(Object::Vector*)&params[0] = HitLoc;
			params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ServerUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerUse");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Use()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Use");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PerformedUseAction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClearDoubleClick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClearDoubleClick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ShowScoreboard");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BehindView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.BehindView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetBehindView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetBehindView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetCameraMode");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpawnCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SpawnCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Object::Vector& POVLocation, Object::Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = POVLocation;
			*(Object::Rotator*)&params[12] = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			POVLocation = *(Object::Vector*)&params[0];
			POVRotation = *(Object::Rotator*)&params[12];
		}
		void CalcCameraOnViewTarget(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CalcCameraOnViewTarget");
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
		void ClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientMusicEvent");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AlreadyInActionMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AlreadyInActionMusic");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClientPlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayAnnouncement");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayAnnouncement");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = InMessageClass;
			*(int*)&params[4] = MessageIndex;
			*(class PlayerReplicationInfo**)&params[8] = PRI;
			*(class Object**)&params[12] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DamageShake(int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DamageShake");
			byte params[8] = { NULL };
			*(int*)&params[0] = Damage;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopViewShaking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StopViewShaking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bIsDamageShake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayCameraAnim");
			byte params[28] = { NULL };
			*(class CameraAnim**)&params[0] = AnimToPlay;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StopCameraAnim");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraAnimStrength(float NewStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetCameraAnimStrength");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, Camera::ECameraAnimPlaySpace Space, Object::Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayCameraAnim");
			byte params[41] = { NULL };
			*(class CameraAnim**)&params[0] = AnimToPlay;
			*(float*)&params[4] = Scale;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bRandomStartTime;
			*(Camera::ECameraAnimPlaySpace*)&params[28] = Space;
			*(Object::Rotator*)&params[32] = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientStopCameraAnim");
			byte params[4] = { NULL };
			*(class CameraAnim**)&params[0] = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayCameraAnim(class UTSeqAct_PlayCameraAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnPlayCameraAnim");
			byte params[4] = { NULL };
			*(class UTSeqAct_PlayCameraAnim**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStopCameraAnim(class UTSeqAct_StopCameraAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnStopCameraAnim");
			byte params[4] = { NULL };
			*(class UTSeqAct_StopCameraAnim**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewShake");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleMelee()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ToggleMelee");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleTranslocator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ToggleTranslocator");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CallServerMove(class SavedMove* NewMove, Object::Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CallServerMove");
			byte params[25] = { NULL };
			*(class SavedMove**)&params[0] = NewMove;
			*(Object::Vector*)&params[4] = ClientLoc;
			params[16] = ClientRoll;
			*(int*)&params[20] = View;
			*(class SavedMove**)&params[24] = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShortServerMove(float TimeStamp, Object::Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ShortServerMove");
			byte params[22] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(Object::Vector*)&params[4] = ClientLoc;
			params[16] = NewFlags;
			params[17] = ClientRoll;
			*(int*)&params[20] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LongClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.LongClientAdjustPosition");
			byte params[53] = { NULL };
			*(float*)&params[0] = TimeStamp;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewNextBot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerViewSelf");
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)&params[0] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewPlayerByName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewPlayerByName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewPlayerByName(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerViewPlayerByName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewObjective");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerViewObjective");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustCameraScale(bool bIn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdjustCameraScale");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CanCommunicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ShowMidGameMenu");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = TabTag;
			*(bool*)&params[8] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientGameEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.RoundHasEnded");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientRoundEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientRoundEnded");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Object::Vector FireLocation, Object::Vector FireDir, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckBulletWhip");
			byte params[40] = { NULL };
			*(class SoundCue**)&params[0] = BulletWhip;
			*(Object::Vector*)&params[4] = FireLocation;
			*(Object::Vector*)&params[16] = FireDir;
			*(Object::Vector*)&params[28] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PawnDied");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPawnDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPawnDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyFOVAngle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnUpdatePropertyFOVAngle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustFOV(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdjustFOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoom(float NewDesiredFOV, float NewZoomRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StartZoom");
			byte params[8] = { NULL };
			*(float*)&params[0] = NewDesiredFOV;
			*(float*)&params[4] = NewZoomRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartZoomNonlinear(float NewDesiredFOV, float NewZoomInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StartZoomNonlinear");
			byte params[8] = { NULL };
			*(float*)&params[0] = NewDesiredFOV;
			*(float*)&params[4] = NewZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StopZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.EndZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndZoomNonlinear(float ZoomInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.EndZoomNonlinear");
			byte params[4] = { NULL };
			*(float*)&params[0] = ZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientEndZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientEndZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.UpdateRotation");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CharacterProcessingComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CharacterProcessingComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CanRestartPlayer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SendMessage");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveBotVoiceMessage(class UTPlayerReplicationInfo* SenderPRI, int MessageIndex, class Object* LocationObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveBotVoiceMessage");
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = SenderPRI;
			*(int*)&params[4] = MessageIndex;
			*(class Object**)&params[8] = LocationObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetNetSpeed");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BullseyeMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.BullseyeMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerChangeTeam");
			byte params[4] = { NULL };
			*(int*)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetSeamlessTravelActorList");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void ServerKickBan(ScriptString* PlayerToKick, bool bBan)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerKickBan");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = PlayerToKick;
			*(bool*)&params[12] = bBan;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AllowTTSMessageFrom");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ServerSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerTeamSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AllowTextMessage");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool AdminCmdOk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminCmdOk");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AdminLogin(ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminLogin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdminLogin(ScriptString* Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerAdminLogin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Password;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminLogout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminLogout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAdminLogOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerAdminLogOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Admin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Admin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAdmin(ScriptString* CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerAdmin");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminKickBan(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminKickBan");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminKick(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminKick");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminPlayerList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminPlayerList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdminRestartMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminRestartMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerRestartMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdminChangeMap(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminChangeMap");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeMap(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerChangeMap");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceVoiceMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceVoiceMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceVoiceMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceVoiceMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceVoiceUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceVoiceUnMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceVoiceUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceVoiceUnMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceTextMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceTextMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceTextMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceTextMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdminForceTextUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceTextUnMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerForceTextUnMute(ScriptString* TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceTextUnMute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Disconnect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Disconnect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnScoreChanged");
			byte params[4] = { NULL };
			*(class UTTeamInfo**)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
