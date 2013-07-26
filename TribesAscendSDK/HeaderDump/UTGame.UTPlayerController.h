#pragma once
#include "Core.Object.Rotator.h"
#include "UDKBase.UDKPlayerController.h"
#include "UTGame.UTAnnouncer.h"
#include "Core.Object.Vector.h"
#include "UTGame.UTUIDataStore_StringAliasBindingsMap.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTMusicManager.h"
#include "Engine.Actor.h"
#include "Engine.CameraAnim.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "UTGame.UTSeqAct_PlayCameraAnim.h"
#include "Engine.SpeechRecognition.h"
#include "Engine.OnlineSubsystem.SpeechRecognizedWord.h"
#include "Engine.Camera.ViewTargetTransitionParams.h"
#include "Engine.SoundCue.h"
#include "Engine.SavedMove.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "UTGame.UTVehicle.h"
#include "Engine.Projectile.h"
#include "Engine.HUD.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Core.Object.h"
#include "UTGame.UTSeqAct_StopCameraAnim.h"
#include "UTGame.UTTeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPlayerController : public UDKPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bLateComer, 0x1)
		ADD_OBJECT(UTUIDataStore_StringAliasBindingsMap, BoundEventsStringDataStore)
		ADD_VAR(::BoolProperty, bQuittingToMainMenu, 0x20000)
		ADD_VAR(::BoolProperty, bJustFoundVehicle, 0x80000)
		ADD_VAR(::BoolProperty, bLandingShake, 0x4000)
		ADD_VAR(::FloatProperty, LastWarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTauntAnimTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsTyping, 0x2)
		ADD_OBJECT(UTAnnouncer, Announcer)
		ADD_OBJECT(UTMusicManager, MusicManager)
		ADD_VAR(::BoolProperty, bBehindView, 0x80)
		ADD_VAR(::FloatProperty, LastKickWarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OnFootDefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponHandPreference, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoTaunt, 0x4)
		ADD_VAR(::BoolProperty, bCenteredWeaponFire, 0x8000)
		ADD_VAR(::ByteProperty, AutoObjectivePreference, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, VehicleControlType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PawnShadowMode, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastAutoObjective)
		ADD_VAR(::FloatProperty, LastShowPathTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseVehicleRotationOnPossess, 0x8)
		ADD_VAR(::ByteProperty, IdentifiedTeam, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponHand, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUseTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAlreadyReset, 0x400000)
		ADD_OBJECT(Actor, CalcViewActor)
		ADD_VAR(::BoolProperty, bFreeCamera, 0x200)
		ADD_VAR(::FloatProperty, LastCameraTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDebugFreeCam, 0x40000)
		ADD_STRUCT(::RotatorProperty, DebugFreeCamRot, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, MatineeCameraClass)
		ADD_STRUCT(::VectorProperty, CalcViewActorLocation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, CalcViewActorRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CalcEyeHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CalcWalkBob, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CalcViewLocation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, CalcViewRotation, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, DamageCameraAnim)
		ADD_VAR(::BoolProperty, bCurrentCamAnimIsDamageShake, 0x1000)
		ADD_VAR(::BoolProperty, bCurrentCamAnimAffectsFOV, 0x2000)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeShortWaveForm)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeLongWaveForm)
		ADD_VAR(::BoolProperty, bCameraOutOfWorld, 0x20)
		ADD_VAR(::StrProperty, MsgPlayerNotFound, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bServerMutedText, 0x800000)
		ADD_VAR(::BoolProperty, bNonlinearZoomInterpolation, 0x10000)
		ADD_VAR(::FloatProperty, FOVNonlinearZoomInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVLinearZoomRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastBullseyeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTeamChangeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoTextToSpeechVoiceMessages, 0x400)
		ADD_VAR(::BoolProperty, bTextToSpeechTeamMessagesOnly, 0x800)
		ADD_VAR(::FloatProperty, NextAdminCmdTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRotateMinimap, 0x10)
		ADD_VAR(::BoolProperty, bFirstPersonWeaponsSelfShadow, 0x40)
		ADD_VAR(::BoolProperty, bForceBehindView, 0x100)
		ADD_VAR(::BoolProperty, bNoCrosshair, 0x100000)
		ADD_VAR(::BoolProperty, bSimpleCrosshair, 0x200000)
		ADD_VAR(::BoolProperty, bHideObjectivePaths, 0x1000000)
		ADD_STRUCT(::VectorProperty, DesiredLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomRotationModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFriendlyFireTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastIncomingMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCombatUpdateTime, 0xFFFFFFFF)
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
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = CharClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bRegisterVoice;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void OnConnectionStatusChange(byte ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnConnectionStatusChange");
			byte* params = (byte*)malloc(1);
			*params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnLinkStatusChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReadProfileSettingsComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnReadProfileSettingsComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptArray<wchar_t> RequestingNick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnGameInviteReceived");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendInviteReceived(byte LocalUserNum, UniqueNetId RequestingPlayer, ScriptArray<wchar_t> RequestingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnFriendInviteReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = RequestingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = RequestingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendMessageReceived(byte LocalUserNum, UniqueNetId SendingPlayer, ScriptArray<wchar_t> SendingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnFriendMessageReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(UniqueNetId*)(params + 4) = SendingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = SendingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void SetFrontEndErrorMessage(ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetFrontEndErrorMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Title;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(bool*)params = bWasFromMenu;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnEndOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnEndOnlineGameComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDestroyOnlineGameComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnDestroyOnlineGameComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetSpeechRecognitionObject(class SpeechRecognition* NewRecognitionData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetSpeechRecognitionObject");
			byte* params = (byte*)malloc(4);
			*(class SpeechRecognition**)params = NewRecognitionData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpeechRecognitionComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SpeechRecognitionComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerProcessSpeechRecognition(SpeechRecognizedWord ReplicatedWords)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerProcessSpeechRecognition");
			byte* params = (byte*)malloc(20);
			*(SpeechRecognizedWord*)params = ReplicatedWords;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientHearSound");
			byte* params = (byte*)malloc(28);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(Vector*)(params + 8) = SourceLocation;
			*(bool*)(params + 20) = bStopWhenOwnerDestroyed;
			*(bool*)(params + 24) = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AimingHelp");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float AimHelpModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AimHelpModifier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = W;
			*(Vector*)(params + 4) = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FindVehicleToDrive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class UTVehicle* CheckPickedVehicle(class UTVehicle* V, bool bEnterVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckPickedVehicle");
			byte* params = (byte*)malloc(12);
			*(class UTVehicle**)params = V;
			*(bool*)(params + 4) = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTVehicle**)(params + 8);
			free(params);
			return returnVal;
		}
		void ClientSetRequestedEntryWithFlag(class UTVehicle* V, bool bNewValue, int MessageIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetRequestedEntryWithFlag");
			byte* params = (byte*)malloc(12);
			*(class UTVehicle**)params = V;
			*(bool*)(params + 4) = bNewValue;
			*(int*)(params + 8) = MessageIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTVehicle* CheckVehicleToDrive(bool bEnterVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckVehicleToDrive");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnterVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTVehicle**)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PlayBeepSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayBeepSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveWarning");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = shooter;
			*(float*)(params + 4) = projSpeed;
			*(Vector*)(params + 8) = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveProjectileWarning");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProjectileWarningTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ProjectileWarningTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWinMessage(bool bWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayWinMessage");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.TriggerInteracted");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bTyping;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnControllerChanged");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SoakPause");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DrawHUD");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FixFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.FixFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Restart");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientRestart");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewTarget(class Actor* NewViewTarget, ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetViewTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = NewViewTarget;
			*(ViewTargetTransitionParams*)(params + 4) = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckAutoObjective(bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckAutoObjective");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAutoObjective(class Actor* ObjectiveActor, bool bOnlyNotifyDifferent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetAutoObjective");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = ObjectiveActor;
			*(bool*)(params + 4) = bOnlyNotifyDifferent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetAutoObjective(class Actor* NewAutoObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetAutoObjective");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewAutoObjective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Possess(class Pawn* inPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Possess");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = inPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AcknowledgePossession");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ServerPlayerPreferences(byte NewWeaponHand, bool bNewAutoTaunt, bool bNewCenteredWeaponFire, byte NewAutoObjectivePreference, byte NewVehicleControls)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerPlayerPreferences");
			byte* params = (byte*)malloc(11);
			*params = NewWeaponHand;
			*(bool*)(params + 4) = bNewAutoTaunt;
			*(bool*)(params + 8) = bNewCenteredWeaponFire;
			*(params + 12) = NewAutoObjectivePreference;
			*(params + 13) = NewVehicleControls;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetHand(byte NewWeaponHand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetHand");
			byte* params = (byte*)malloc(1);
			*params = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHand(byte NewWeaponHand)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetHand");
			byte* params = (byte*)malloc(1);
			*params = NewWeaponHand;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ResetCameraMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.UsingFirstPersonCamera");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerSetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetAutoTaunt");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAutoTaunt(bool Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetAutoTaunt");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleScreenShotMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ToggleScreenShotMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayStartupMessage");
			byte* params = (byte*)malloc(1);
			*params = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayTakeHit(Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayTakeHit");
			byte* params = (byte*)malloc(17);
			*(Vector*)params = HitLoc;
			*(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ServerUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerUse");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Use()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Use");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PerformedUseAction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientSetBehindView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetCameraMode");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SpawnCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = POVLocation;
			*(Rotator*)(params + 12) = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)(params + 12);
			free(params);
		}
		void CalcCameraOnViewTarget(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CalcCameraOnViewTarget");
			byte* params = (byte*)malloc(32);
			*(float*)params = fDeltaTime;
			*(Vector*)(params + 4) = out_CamLoc;
			*(Rotator*)(params + 16) = out_CamRot;
			*(float*)(params + 28) = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_CamLoc = *(Vector*)(params + 4);
			out_CamRot = *(Rotator*)(params + 16);
			out_FOV = *(float*)(params + 28);
			free(params);
		}
		void ClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientMusicEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AlreadyInActionMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AlreadyInActionMusic");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClientPlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayAnnouncement");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = InMessageClass;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAnnouncement(ScriptClass* InMessageClass, int MessageIndex, class PlayerReplicationInfo* PRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayAnnouncement");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = InMessageClass;
			*(int*)(params + 4) = MessageIndex;
			*(class PlayerReplicationInfo**)(params + 8) = PRI;
			*(class Object**)(params + 12) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DamageShake(int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.DamageShake");
			byte* params = (byte*)malloc(8);
			*(int*)params = Damage;
			*(ScriptClass**)(params + 4) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopViewShaking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StopViewShaking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bIsDamageShake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PlayCameraAnim");
			byte* params = (byte*)malloc(28);
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)(params + 4) = Scale;
			*(float*)(params + 8) = Rate;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLoop;
			*(bool*)(params + 24) = bIsDamageShake;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopCameraAnim(bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StopCameraAnim");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCameraAnimStrength(float NewStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SetCameraAnimStrength");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewStrength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, byte Space, Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientPlayCameraAnim");
			byte* params = (byte*)malloc(41);
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)(params + 4) = Scale;
			*(float*)(params + 8) = Rate;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLoop;
			*(bool*)(params + 24) = bRandomStartTime;
			*(params + 28) = Space;
			*(Rotator*)(params + 32) = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientStopCameraAnim");
			byte* params = (byte*)malloc(4);
			*(class CameraAnim**)params = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayCameraAnim(class UTSeqAct_PlayCameraAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnPlayCameraAnim");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_PlayCameraAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnStopCameraAnim(class UTSeqAct_StopCameraAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnStopCameraAnim");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_StopCameraAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewShake");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void CallServerMove(class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CallServerMove");
			byte* params = (byte*)malloc(25);
			*(class SavedMove**)params = NewMove;
			*(Vector*)(params + 4) = ClientLoc;
			*(params + 16) = ClientRoll;
			*(int*)(params + 20) = View;
			*(class SavedMove**)(params + 24) = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShortServerMove(float TimeStamp, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ShortServerMove");
			byte* params = (byte*)malloc(22);
			*(float*)params = TimeStamp;
			*(Vector*)(params + 4) = ClientLoc;
			*(params + 16) = NewFlags;
			*(params + 17) = ClientRoll;
			*(int*)(params + 20) = View;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LongClientAdjustPosition(float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.LongClientAdjustPosition");
			byte* params = (byte*)malloc(53);
			*(float*)params = TimeStamp;
			*(ScriptName*)(params + 4) = NewState;
			*(params + 12) = newPhysics;
			*(float*)(params + 16) = NewLocX;
			*(float*)(params + 20) = NewLocY;
			*(float*)(params + 24) = NewLocZ;
			*(float*)(params + 28) = NewVelX;
			*(float*)(params + 32) = NewVelY;
			*(float*)(params + 36) = NewVelZ;
			*(class Actor**)(params + 40) = NewBase;
			*(float*)(params + 44) = NewFloorX;
			*(float*)(params + 48) = NewFloorY;
			*(float*)(params + 52) = NewFloorZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewNextBot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewNextBot");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchWeapon(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SwitchWeapon");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewSelf(ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerViewSelf");
			byte* params = (byte*)malloc(16);
			*(ViewTargetTransitionParams*)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewPlayerByName(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ViewPlayerByName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewPlayerByName(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerViewPlayerByName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CanCommunicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ShowMidGameMenu");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = TabTag;
			*(bool*)(params + 8) = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientGameEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RoundHasEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.RoundHasEnded");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientRoundEnded(class Actor* EndRoundFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientRoundEnded");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = EndRoundFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CheckBulletWhip");
			byte* params = (byte*)malloc(40);
			*(class SoundCue**)params = BulletWhip;
			*(Vector*)(params + 4) = FireLocation;
			*(Vector*)(params + 16) = FireDir;
			*(Vector*)(params + 28) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.PawnDied");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartZoom(float NewDesiredFOV, float NewZoomRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StartZoom");
			byte* params = (byte*)malloc(8);
			*(float*)params = NewDesiredFOV;
			*(float*)(params + 4) = NewZoomRate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartZoomNonlinear(float NewDesiredFOV, float NewZoomInterpSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.StartZoomNonlinear");
			byte* params = (byte*)malloc(8);
			*(float*)params = NewDesiredFOV;
			*(float*)(params + 4) = NewZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = ZoomInterpSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientEndZoom()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ClientEndZoom");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.UpdateRotation");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CharacterProcessingComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CharacterProcessingComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.CanRestartPlayer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.SendMessage");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)(params + 4) = MessageType;
			*(float*)(params + 12) = Wait;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveBotVoiceMessage(class UTPlayerReplicationInfo* SenderPRI, int MessageIndex, class Object* LocationObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ReceiveBotVoiceMessage");
			byte* params = (byte*)malloc(12);
			*(class UTPlayerReplicationInfo**)params = SenderPRI;
			*(int*)(params + 4) = MessageIndex;
			*(class Object**)(params + 8) = LocationObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSetNetSpeed");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BullseyeMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.BullseyeMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerChangeTeam");
			byte* params = (byte*)malloc(4);
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ServerKickBan(ScriptArray<wchar_t> PlayerToKick, bool bBan)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerKickBan");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerToKick;
			*(bool*)(params + 12) = bBan;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AllowTTSMessageFrom");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ServerSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerTeamSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerTeamSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTextMessage(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AllowTextMessage");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool AdminCmdOk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminCmdOk");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AdminLogin(ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminLogin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAdminLogin(ScriptArray<wchar_t> Password)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerAdminLogin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Password;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void Admin(ScriptArray<wchar_t> CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Admin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAdmin(ScriptArray<wchar_t> CommandLine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerAdmin");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = CommandLine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminKickBan(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminKickBan");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminKick(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminKick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void AdminChangeMap(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminChangeMap");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeMap(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerChangeMap");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminForceVoiceMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceVoiceMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerForceVoiceMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceVoiceMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminForceVoiceUnMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceVoiceUnMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerForceVoiceUnMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceVoiceUnMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminForceTextMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceTextMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerForceTextMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceTextMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdminForceTextUnMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.AdminForceTextUnMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerForceTextUnMute(ScriptArray<wchar_t> TargetPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.ServerForceTextUnMute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TargetPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Disconnect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.Disconnect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTPlayerController.OnScoreChanged");
			byte* params = (byte*)malloc(4);
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
