#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "UDKBase__UDKPlayerController.h"
#include "Engine__SpeechRecognition.h"
#include "Engine__Weapon.h"
#include "Engine__CameraAnim.h"
#include "UTGame__UTUIDataStore_StringAliasBindingsMap.h"
#include "UTGame__UTMusicManager.h"
#include "UTGame__UTAnnouncer.h"
#include "Engine__Actor.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "UTGame__UTVehicle.h"
#include "Engine__Pawn.h"
#include "Engine__Projectile.h"
#include "Engine__HUD.h"
#include "Engine__Controller.h"
#include "Core__Object.h"
#include "UTGame__UTSeqAct_PlayCameraAnim.h"
#include "UTGame__UTSeqAct_StopCameraAnim.h"
#include "Engine__SavedMove.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UTGame__UTTeamInfo.h"
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
		ADD_STRUCT(::RotatorProperty, DebugFreeCamRot, 0xFFFFFFFF
		ADD_OBJECT(ScriptClass, MatineeCameraClass)
		ADD_STRUCT(::VectorProperty, CalcViewActorLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, CalcViewActorRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CalcEyeHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CalcWalkBob, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, CalcViewLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, CalcViewRotation, 0xFFFFFFFF
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
		ADD_STRUCT(::VectorProperty, DesiredLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ZoomRotationModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFriendlyFireTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastIncomingMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCombatUpdateTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ServerThrowWeapon'
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'PulseTeamColor'
		// Here lies the not-yet-implemented method 'ServerSetCharacterClass'
		// Here lies the not-yet-implemented method 'ClearStringAliasBindingMapCache'
		// Here lies the not-yet-implemented method 'RegisterCustomPlayerDataStores'
		// Here lies the not-yet-implemented method 'UnregisterPlayerDataStores'
		// Here lies the not-yet-implemented method 'AddOnlineDelegates'
		// Here lies the not-yet-implemented method 'ClearOnlineDelegates'
		// Here lies the not-yet-implemented method 'ClientSetOnlineStatus'
		// Here lies the not-yet-implemented method 'OnConnectionStatusChange'
		// Here lies the not-yet-implemented method 'OnLinkStatusChanged'
		// Here lies the not-yet-implemented method 'OnReadProfileSettingsComplete'
		// Here lies the not-yet-implemented method 'OnGameInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendInviteReceived'
		// Here lies the not-yet-implemented method 'OnFriendMessageReceived'
		// Here lies the not-yet-implemented method 'NotifyInviteFailed'
		// Here lies the not-yet-implemented method 'NotifyNotAllPlayersCanJoinInvite'
		// Here lies the not-yet-implemented method 'NotifyNotEnoughSpaceInInvite'
		// Here lies the not-yet-implemented method 'ClientWasKicked'
		// Here lies the not-yet-implemented method 'SetFrontEndErrorMessage'
		// Here lies the not-yet-implemented method 'QuitToMainMenu'
		// Here lies the not-yet-implemented method 'FinishQuitToMainMenu'
		// Here lies the not-yet-implemented method 'CleanupOnlineSubsystemSession'
		// Here lies the not-yet-implemented method 'OnEndOnlineGameComplete'
		// Here lies the not-yet-implemented method 'OnDestroyOnlineGameComplete'
		// Here lies the not-yet-implemented method 'ClientSetSpeechRecognitionObject'
		// Here lies the not-yet-implemented method 'SpeechRecognitionComplete'
		// Here lies the not-yet-implemented method 'ServerProcessSpeechRecognition'
		// Here lies the not-yet-implemented method 'ClientHearSound'
		// Here lies the not-yet-implemented method 'AimingHelp'
		// Here lies the not-yet-implemented method 'AimHelpModifier'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'FindVehicleToDrive'
		// Here lies the not-yet-implemented method 'CheckPickedVehicle'
		// Here lies the not-yet-implemented method 'ClientSetRequestedEntryWithFlag'
		// Here lies the not-yet-implemented method 'CheckVehicleToDrive'
		// Here lies the not-yet-implemented method 'DropFlag'
		// Here lies the not-yet-implemented method 'ServerDropFlag'
		// Here lies the not-yet-implemented method 'LandingShake'
		// Here lies the not-yet-implemented method 'PlayBeepSound'
		// Here lies the not-yet-implemented method 'ReceiveWarning'
		// Here lies the not-yet-implemented method 'ReceiveProjectileWarning'
		// Here lies the not-yet-implemented method 'ProjectileWarningTimer'
		// Here lies the not-yet-implemented method 'PlayWinMessage'
		// Here lies the not-yet-implemented method 'TriggerInteracted'
		// Here lies the not-yet-implemented method 'PlayVehicleHorn'
		// Here lies the not-yet-implemented method 'ServerPlayVehicleHorn'
		// Here lies the not-yet-implemented method 'Typing'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'OnControllerChanged'
		// Here lies the not-yet-implemented method 'SoakPause'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'KickWarning'
		// Here lies the not-yet-implemented method 'CheckJumpOrDuck'
		// Here lies the not-yet-implemented method 'FOV'
		// Here lies the not-yet-implemented method 'FixFOV'
		// Here lies the not-yet-implemented method 'Restart'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'SetViewTarget'
		// Here lies the not-yet-implemented method 'CheckAutoObjective'
		// Here lies the not-yet-implemented method 'SetAutoObjective'
		// Here lies the not-yet-implemented method 'ClientSetAutoObjective'
		// Here lies the not-yet-implemented method 'Possess'
		// Here lies the not-yet-implemented method 'AcknowledgePossession'
		// Here lies the not-yet-implemented method 'IdentifyTeamMessage'
		// Here lies the not-yet-implemented method 'ReceivedPlayer'
		// Here lies the not-yet-implemented method 'ServerPlayerPreferences'
		// Here lies the not-yet-implemented method 'ServerSetHand'
		// Here lies the not-yet-implemented method 'SetHand'
		// Here lies the not-yet-implemented method 'ResetCameraMode'
		// Here lies the not-yet-implemented method 'UsingFirstPersonCamera'
		// Here lies the not-yet-implemented method 'ServerSetAutoTaunt'
		// Here lies the not-yet-implemented method 'SetAutoTaunt'
		// Here lies the not-yet-implemented method 'ToggleScreenShotMode'
		// Here lies the not-yet-implemented method 'PlayStartupMessage'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'ClientPlayTakeHit'
		// Here lies the not-yet-implemented method 'ServerUse'
		// Here lies the not-yet-implemented method 'Use'
		// Here lies the not-yet-implemented method 'PerformedUseAction'
		// Here lies the not-yet-implemented method 'ClearDoubleClick'
		// Here lies the not-yet-implemented method 'ShowScoreboard'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ClientReset'
		// Here lies the not-yet-implemented method 'BehindView'
		// Here lies the not-yet-implemented method 'SetBehindView'
		// Here lies the not-yet-implemented method 'ClientSetBehindView'
		// Here lies the not-yet-implemented method 'SetCameraMode'
		// Here lies the not-yet-implemented method 'SpawnCamera'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'CalcCameraOnViewTarget'
		// Here lies the not-yet-implemented method 'ClientMusicEvent'
		// Here lies the not-yet-implemented method 'AlreadyInActionMusic'
		// Here lies the not-yet-implemented method 'ClientPlayAnnouncement'
		// Here lies the not-yet-implemented method 'PlayAnnouncement'
		// Here lies the not-yet-implemented method 'DamageShake'
		// Here lies the not-yet-implemented method 'StopViewShaking'
		// Here lies the not-yet-implemented method 'PlayCameraAnim'
		// Here lies the not-yet-implemented method 'StopCameraAnim'
		// Here lies the not-yet-implemented method 'SetCameraAnimStrength'
		// Here lies the not-yet-implemented method 'ClientPlayCameraAnim'
		// Here lies the not-yet-implemented method 'ClientStopCameraAnim'
		// Here lies the not-yet-implemented method 'OnPlayCameraAnim'
		// Here lies the not-yet-implemented method 'OnStopCameraAnim'
		// Here lies the not-yet-implemented method 'ViewShake'
		// Here lies the not-yet-implemented method 'ToggleMelee'
		// Here lies the not-yet-implemented method 'ToggleTranslocator'
		// Here lies the not-yet-implemented method 'CallServerMove'
		// Here lies the not-yet-implemented method 'ShortServerMove'
		// Here lies the not-yet-implemented method 'LongClientAdjustPosition'
		// Here lies the not-yet-implemented method 'ViewNextBot'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'ServerViewSelf'
		// Here lies the not-yet-implemented method 'ViewPlayerByName'
		// Here lies the not-yet-implemented method 'ServerViewPlayerByName'
		// Here lies the not-yet-implemented method 'ViewObjective'
		// Here lies the not-yet-implemented method 'ServerViewObjective'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'AdjustCameraScale'
		// Here lies the not-yet-implemented method 'CanCommunicate'
		// Here lies the not-yet-implemented method 'ShowMidGameMenu'
		// Here lies the not-yet-implemented method 'ClientGameEnded'
		// Here lies the not-yet-implemented method 'RoundHasEnded'
		// Here lies the not-yet-implemented method 'ClientRoundEnded'
		// Here lies the not-yet-implemented method 'CheckBulletWhip'
		// Here lies the not-yet-implemented method 'PawnDied'
		// Here lies the not-yet-implemented method 'ClientPawnDied'
		// Here lies the not-yet-implemented method 'OnUpdatePropertyFOVAngle'
		// Here lies the not-yet-implemented method 'AdjustFOV'
		// Here lies the not-yet-implemented method 'StartZoom'
		// Here lies the not-yet-implemented method 'StartZoomNonlinear'
		// Here lies the not-yet-implemented method 'StopZoom'
		// Here lies the not-yet-implemented method 'EndZoom'
		// Here lies the not-yet-implemented method 'EndZoomNonlinear'
		// Here lies the not-yet-implemented method 'ClientEndZoom'
		// Here lies the not-yet-implemented method 'UpdateRotation'
		// Here lies the not-yet-implemented method 'CharacterProcessingComplete'
		// Here lies the not-yet-implemented method 'CanRestartPlayer'
		// Here lies the not-yet-implemented method 'SendMessage'
		// Here lies the not-yet-implemented method 'ReceiveBotVoiceMessage'
		// Here lies the not-yet-implemented method 'ServerSetNetSpeed'
		// Here lies the not-yet-implemented method 'BullseyeMessage'
		// Here lies the not-yet-implemented method 'ServerChangeTeam'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'ServerKickBan'
		// Here lies the not-yet-implemented method 'AllowTTSMessageFrom'
		// Here lies the not-yet-implemented method 'ServerSay'
		// Here lies the not-yet-implemented method 'ServerTeamSay'
		// Here lies the not-yet-implemented method 'AllowTextMessage'
		// Here lies the not-yet-implemented method 'AdminCmdOk'
		// Here lies the not-yet-implemented method 'AdminLogin'
		// Here lies the not-yet-implemented method 'ServerAdminLogin'
		// Here lies the not-yet-implemented method 'AdminLogout'
		// Here lies the not-yet-implemented method 'ServerAdminLogOut'
		// Here lies the not-yet-implemented method 'Admin'
		// Here lies the not-yet-implemented method 'ServerAdmin'
		// Here lies the not-yet-implemented method 'AdminKickBan'
		// Here lies the not-yet-implemented method 'AdminKick'
		// Here lies the not-yet-implemented method 'AdminPlayerList'
		// Here lies the not-yet-implemented method 'AdminRestartMap'
		// Here lies the not-yet-implemented method 'ServerRestartMap'
		// Here lies the not-yet-implemented method 'AdminChangeMap'
		// Here lies the not-yet-implemented method 'ServerChangeMap'
		// Here lies the not-yet-implemented method 'AdminForceVoiceMute'
		// Here lies the not-yet-implemented method 'ServerForceVoiceMute'
		// Here lies the not-yet-implemented method 'AdminForceVoiceUnMute'
		// Here lies the not-yet-implemented method 'ServerForceVoiceUnMute'
		// Here lies the not-yet-implemented method 'AdminForceTextMute'
		// Here lies the not-yet-implemented method 'ServerForceTextMute'
		// Here lies the not-yet-implemented method 'AdminForceTextUnMute'
		// Here lies the not-yet-implemented method 'ServerForceTextUnMute'
		// Here lies the not-yet-implemented method 'Disconnect'
		// Here lies the not-yet-implemented method 'OnScoreChanged'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
