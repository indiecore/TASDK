#pragma once
#include "Engine__SavedMove.h"
#include "Engine__UIInteraction.h"
#include "Engine__OnlineSubsystem.h"
#include "Engine__CoverReplicator.h"
#include "Engine__Controller.h"
#include "Engine__Player.h"
#include "Engine__HUD.h"
#include "Engine__Camera.h"
#include "Engine__Actor.h"
#include "Engine__Canvas.h"
#include "Engine__OnlineGameSearch.h"
#include "Engine__LevelStreaming.h"
#include "Engine__PlayerInput.h"
#include "Engine__ForceFeedbackManager.h"
#include "Engine__AnimNotify_Rumble.h"
#include "Engine__UIDataStore_OnlinePlayerData.h"
#include "Engine__Pawn.h"
#include "Engine__SoundCue.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__NetConnection.h"
#include "Engine__OnlineGameSettings.h"
#include "Engine__CheatManager.h"
#include "Engine__InterpTrackInstDirector.h"
#include "Engine__CameraAnim.h"
#include "Engine__Weapon.h"
#include "Engine__Inventory.h"
#include "Core__Object.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__SeqAct_ToggleInput.h"
#include "Engine__SeqAct_CameraLookAt.h"
#include "Engine__SeqAct_DrawText.h"
#include "Engine__SeqAct_SetCameraTarget.h"
#include "Engine__SeqAct_FlyThroughHasEnded.h"
#include "Engine__SeqAct_ToggleHUD.h"
#include "Engine__SeqAct_ForceFeedback.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__SeqAct_ToggleCinematicMode.h"
#include "Engine__SeqAct_ConsoleCommand.h"
#include "Engine__SeqAct_Destroy.h"
#include "Engine__Font.h"
#include "Engine__TextureMovie.h"
#include "Engine__MaterialInterface.h"
#include "Engine__CameraShake.h"
#include "Engine__SeqAct_CameraShake.h"
#include "Engine__SeqAct_SetSoundMode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerController : public Controller
	{
	public:
		ADD_VAR(::FloatProperty, LODDistanceFactor, 0xFFFFFFFF)
		ADD_OBJECT(Player, Player)
		ADD_OBJECT(Actor, ViewTarget)
		ADD_OBJECT(Camera, PlayerCamera)
		ADD_VAR(::BoolProperty, bIsExternalUIOpen, 0x400000)
		ADD_VAR(::BoolProperty, bPendingDestroy, 0x200)
		ADD_VAR(::BoolProperty, bIsControllerConnected, 0x800000)
		ADD_OBJECT(CoverReplicator, MyCoverReplicator)
		ADD_VAR(::FloatProperty, MaxTimeMargin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxResponseTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastActiveTime, 0xFFFFFFFF)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_OBJECT(OnlineGameSearch, MigratedSearchToJoin)
		ADD_VAR(::FloatProperty, TimeMargin, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShortConnectTimeOut, 0x100)
		ADD_OBJECT(HUD, myHUD)
		ADD_VAR(::FloatProperty, WaitDelay, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, SavedMoves)
		ADD_OBJECT(SavedMove, PendingMove)
		ADD_OBJECT(PlayerInput, PlayerInput)
		ADD_OBJECT(ScriptClass, InputClass)
		ADD_VAR(::StrProperty, ForceFeedbackManagerClassName, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackManager, ForceFeedbackManager)
		ADD_OBJECT(UIDataStore_OnlinePlayerData, OnlinePlayerData)
		ADD_VAR(::BoolProperty, bFrozen, 0x1)
		ADD_OBJECT(Pawn, AcknowledgedPawn)
		ADD_VAR(::FloatProperty, FOVAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastBroadcastTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LastBroadcastString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasSpeedHack, 0x400)
		ADD_VAR(::FloatProperty, LastSpeedHackLog, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PlayerController.ClientAdjustment' for the property named 'PendingAdjustment'!
		ADD_VAR(::FloatProperty, ServerTimeStamp, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SavedMoveClass)
		ADD_VAR(::BoolProperty, bDoubleJump, 0x4)
		ADD_VAR(::IntProperty, ClientCap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPingUpdate, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, FreeMoves)
		ADD_STRUCT(::VectorProperty, LastAckedAccel, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bUpdatePosition, 0x8)
		ADD_VAR(::ByteProperty, bRun, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bDuck, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPressedJump, 0x2)
		ADD_VAR(::BoolProperty, bUpdating, 0x10)
		ADD_VAR(::FloatProperty, ClientUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCinematicMode, 0x10000)
		ADD_VAR(::FloatProperty, InteractDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAimingHelp, 0x1000)
		ADD_VAR(::BoolProperty, bClientSimulatingViewTarget, 0x2000)
		ADD_OBJECT(ScriptClass, CameraClass)
		ADD_VAR(::ByteProperty, DoubleClickDir, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GroundPitch, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCheatFlying, 0x40)
		ADD_VAR(::FloatProperty, LastSpectatorStateSynchTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpectatorCameraSpeed, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, RealViewTarget)
		ADD_VAR(::FloatProperty, MinRespawnDelay, 0xFFFFFFFF)
		ADD_OBJECT(NetConnection, PendingSwapConnection)
		ADD_VAR(::ByteProperty, bIgnoreMoveInput, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bIgnoreLookInput, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCinemaDisableInputMove, 0x20000)
		ADD_VAR(::BoolProperty, bCinemaDisableInputLook, 0x40000)
		ADD_VAR(::BoolProperty, bHasVoiceHandshakeCompleted, 0x8000)
		ADD_VAR(::ByteProperty, NetPlayerIndex, 0xFFFFFFFF)
		ADD_OBJECT(CheatManager, CheatManager)
		ADD_VAR(::BoolProperty, bNeverSwitchOnPickup, 0x20)
		ADD_VAR(::BoolProperty, bCameraPositionLocked, 0x80)
		ADD_VAR(::BoolProperty, bWasSaturated, 0x800)
		ADD_VAR(::BoolProperty, bPreventRespawn, 0x4000)
		ADD_VAR(::BoolProperty, bIgnoreNetworkMessages, 0x80000)
		ADD_VAR(::BoolProperty, bReplicateAllPawns, 0x100000)
		ADD_VAR(::BoolProperty, bIsUsingStreamingVolumes, 0x200000)
		ADD_VAR(::BoolProperty, bCheckSoundOcclusion, 0x1000000)
		ADD_VAR(::BoolProperty, bDebugCameraAnims, 0x2000000)
		ADD_VAR(::BoolProperty, bBlockCameraAnimsFromOverridingPostProcess, 0x4000000)
		ADD_VAR(::BoolProperty, bLogHearSoundOverflow, 0x8000000)
		ADD_VAR(::BoolProperty, bCheckRelevancyThroughPortals, 0x10000000)
		ADD_VAR(::BoolProperty, bDebugClientAdjustPosition, 0x20000000)
		ADD_OBJECT(InterpTrackInstDirector, ControllingDirTrackInst)
		ADD_STRUCT(::RotatorProperty, TargetViewRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, TargetEyeHeight, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, BlendedTargetViewRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, DynamicPingThreshold, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, CheatClass)
		ADD_STRUCT(::VectorProperty, FailedPathStart, 0xFFFFFFFF
		ADD_VAR(::NameProperty, DelayedJoinSessionName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxConcurrentHearSounds, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetFOVAngle'
		// Here lies the not-yet-implemented method 'GetPlayerNetworkAddress'
		// Here lies the not-yet-implemented method 'GetViewTarget'
		// Here lies the not-yet-implemented method 'IsPrimaryPlayer'
		// Here lies the not-yet-implemented method 'SetNetSpeed'
		// Here lies the not-yet-implemented method 'GetServerNetworkAddress'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'ClientTravel'
		// Here lies the not-yet-implemented method 'UpdateURL'
		// Here lies the not-yet-implemented method 'GetDefaultURL'
		// Here lies the not-yet-implemented method 'CopyToClipboard'
		// Here lies the not-yet-implemented method 'PasteFromClipboard'
		// Here lies the not-yet-implemented method 'SetAllowMatureLanguage'
		// Here lies the not-yet-implemented method 'SetAudioGroupVolume'
		// Here lies the not-yet-implemented method 'ClientConvolve'
		// Here lies the not-yet-implemented method 'ServerProcessConvolve'
		// Here lies the not-yet-implemented method 'CheckSpeedHack'
		// Here lies the not-yet-implemented method 'FindStairRotation'
		// Here lies the not-yet-implemented method 'CleanUpAudioComponents'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'ForceClearUnpauseDelegates'
		// Here lies the not-yet-implemented method 'OnExternalUIChanged'
		// Here lies the not-yet-implemented method 'CanUnpauseExternalUI'
		// Here lies the not-yet-implemented method 'OnControllerChanged'
		// Here lies the not-yet-implemented method 'CanUnpauseControllerConnected'
		// Here lies the not-yet-implemented method 'SpawnCoverReplicator'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ReceivedPlayer'
		// Here lies the not-yet-implemented method 'RegisterPlayerDataStores'
		// Here lies the not-yet-implemented method 'FindConnectedPeerIndex'
		// Here lies the not-yet-implemented method 'AddPeer'
		// Here lies the not-yet-implemented method 'RemovePeer'
		// Here lies the not-yet-implemented method 'ServerAddPeer'
		// Here lies the not-yet-implemented method 'ServerRemovePeer'
		// Here lies the not-yet-implemented method 'ClientUpdateBestNextHosts'
		// Here lies the not-yet-implemented method 'NotifyPeerDisconnectHost'
		// Here lies the not-yet-implemented method 'IsBestHostPeer'
		// Here lies the not-yet-implemented method 'MigrateNewHost'
		// Here lies the not-yet-implemented method 'OnEndGameForHostMigrate'
		// Here lies the not-yet-implemented method 'GetRegisteredPlayersInSession'
		// Here lies the not-yet-implemented method 'RemoveMissingPeersFromSession'
		// Here lies the not-yet-implemented method 'OnUnregisterPlayerCompleteForMigrate'
		// Here lies the not-yet-implemented method 'OnHostMigratedOnlineGame'
		// Here lies the not-yet-implemented method 'GetCurrentSearchClass'
		// Here lies the not-yet-implemented method 'PeerDesignatedAsHost'
		// Here lies the not-yet-implemented method 'PeerTravelAsHost'
		// Here lies the not-yet-implemented method 'TellPeerToTravel'
		// Here lies the not-yet-implemented method 'TellPeerToTravelToSession'
		// Here lies the not-yet-implemented method 'PeerReceivedMigratedSession'
		// Here lies the not-yet-implemented method 'OnEndGameForJoinMigrate'
		// Here lies the not-yet-implemented method 'OnJoinMigratedGame'
		// Here lies the not-yet-implemented method 'PreRender'
		// Here lies the not-yet-implemented method 'ResetTimeMargin'
		// Here lies the not-yet-implemented method 'ServerShortTimeout'
		// Here lies the not-yet-implemented method 'ServerGivePawn'
		// Here lies the not-yet-implemented method 'KickWarning'
		// Here lies the not-yet-implemented method 'AddCheats'
		// Here lies the not-yet-implemented method 'EnableCheats'
		// Here lies the not-yet-implemented method 'SpawnDefaultHUD'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ClientReset'
		// Here lies the not-yet-implemented method 'CleanOutSavedMoves'
		// Here lies the not-yet-implemented method 'PreControllerIdChange'
		// Here lies the not-yet-implemented method 'PostControllerIdChange'
		// Here lies the not-yet-implemented method 'GetOnlineSubsystem'
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'ClientInitializeDataStores'
		// Here lies the not-yet-implemented method 'RegisterCustomPlayerDataStores'
		// Here lies the not-yet-implemented method 'RegisterStandardPlayerDataStores'
		// Here lies the not-yet-implemented method 'UnregisterPlayerDataStores'
		// Here lies the not-yet-implemented method 'UnregisterStandardPlayerDataStores'
		// Here lies the not-yet-implemented method 'ReloadProfileSettings'
		// Here lies the not-yet-implemented method 'SetRumbleScale'
		// Here lies the not-yet-implemented method 'IsControllerTiltActive'
		// Here lies the not-yet-implemented method 'SetControllerTiltDesiredIfAvailable'
		// Here lies the not-yet-implemented method 'SetControllerTiltActive'
		// Here lies the not-yet-implemented method 'SetOnlyUseControllerTiltInput'
		// Here lies the not-yet-implemented method 'SetUseTiltForwardAndBack'
		// Here lies the not-yet-implemented method 'IsKeyboardAvailable'
		// Here lies the not-yet-implemented method 'IsMouseAvailable'
		// Here lies the not-yet-implemented method 'ClientGotoState'
		// Here lies the not-yet-implemented method 'AskForPawn'
		// Here lies the not-yet-implemented method 'GivePawn'
		// Here lies the not-yet-implemented method 'Possess'
		// Here lies the not-yet-implemented method 'AcknowledgePossession'
		// Here lies the not-yet-implemented method 'ServerAcknowledgePossession'
		// Here lies the not-yet-implemented method 'UnPossess'
		// Here lies the not-yet-implemented method 'PawnDied'
		// Here lies the not-yet-implemented method 'ClientSetHUD'
		// Here lies the not-yet-implemented method 'HandlePickup'
		// Here lies the not-yet-implemented method 'CleanupPRI'
		// Here lies the not-yet-implemented method 'ReceiveLocalizedMessage'
		// Here lies the not-yet-implemented method 'ClientPlaySound'
		// Here lies the not-yet-implemented method 'HearSoundFinished'
		// Here lies the not-yet-implemented method 'GetPooledAudioComponent'
		// Here lies the not-yet-implemented method 'ClientHearSound'
		// Here lies the not-yet-implemented method 'IsClosestLocalPlayerToActor'
		// Here lies the not-yet-implemented method 'Kismet_ClientPlaySound'
		// Here lies the not-yet-implemented method 'Kismet_ClientStopSound'
		// Here lies the not-yet-implemented method 'ClientPlayActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'ClientMessage'
		// Here lies the not-yet-implemented method 'CanCommunicate'
		// Here lies the not-yet-implemented method 'AllowTTSMessageFrom'
		// Here lies the not-yet-implemented method 'CreateTTSSoundCue'
		// Here lies the not-yet-implemented method 'Talk'
		// Here lies the not-yet-implemented method 'TeamTalk'
		// Here lies the not-yet-implemented method 'SpeakTTS'
		// Here lies the not-yet-implemented method 'TeamMessage'
		// Here lies the not-yet-implemented method 'PlayBeepSound'
		// Here lies the not-yet-implemented method 'RegisterOnlineDelegates'
		// Here lies the not-yet-implemented method 'OnPartyMemberListChanged'
		// Here lies the not-yet-implemented method 'OnPartyMembersInfoChanged'
		// Here lies the not-yet-implemented method 'ClearOnlineDelegates'
		// Here lies the not-yet-implemented method 'CleanupPawn'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'FixFOV'
		// Here lies the not-yet-implemented method 'SetFOV'
		// Here lies the not-yet-implemented method 'ResetFOV'
		// Here lies the not-yet-implemented method 'FOV'
		// Here lies the not-yet-implemented method 'AllowTextMessage'
		// Here lies the not-yet-implemented method 'Say'
		// Here lies the not-yet-implemented method 'ServerSay'
		// Here lies the not-yet-implemented method 'ClientAdminMessage'
		// Here lies the not-yet-implemented method 'TeamSay'
		// Here lies the not-yet-implemented method 'ServerTeamSay'
		// Here lies the not-yet-implemented method 'PreClientTravel'
		// Here lies the not-yet-implemented method 'GetUIController'
		// Here lies the not-yet-implemented method 'Camera'
		// Here lies the not-yet-implemented method 'ServerCamera'
		// Here lies the not-yet-implemented method 'ClientSetCameraMode'
		// Here lies the not-yet-implemented method 'SetCameraMode'
		// Here lies the not-yet-implemented method 'ResetCameraMode'
		// Here lies the not-yet-implemented method 'ClientSetCameraFade'
		// Here lies the not-yet-implemented method 'UsingFirstPersonCamera'
		// Here lies the not-yet-implemented method 'ForceDeathUpdate'
		// Here lies the not-yet-implemented method 'DualServerMove'
		// Here lies the not-yet-implemented method 'OldServerMove'
		// Here lies the not-yet-implemented method 'GetServerMoveDeltaTime'
		// Here lies the not-yet-implemented method 'ServerMoveHandleClientError'
		// Here lies the not-yet-implemented method 'ServerMove'
		// Here lies the not-yet-implemented method 'SendClientAdjustment'
		// Here lies the not-yet-implemented method 'ServerDrive'
		// Here lies the not-yet-implemented method 'ProcessDrive'
		// Here lies the not-yet-implemented method 'ProcessMove'
		// Here lies the not-yet-implemented method 'MoveAutonomous'
		// Here lies the not-yet-implemented method 'VeryShortClientAdjustPosition'
		// Here lies the not-yet-implemented method 'ShortClientAdjustPosition'
		// Here lies the not-yet-implemented method 'ClientCapBandwidth'
		// Here lies the not-yet-implemented method 'ClientAckGoodMove'
		// Here lies the not-yet-implemented method 'UpdatePing'
		// Here lies the not-yet-implemented method 'ClientAdjustPosition'
		// Here lies the not-yet-implemented method 'LongClientAdjustPosition'
		// Here lies the not-yet-implemented method 'UpdateStateFromAdjustment'
		// Here lies the not-yet-implemented method 'ServerUpdatePing'
		// Here lies the not-yet-implemented method 'ClearAckedMoves'
		// Here lies the not-yet-implemented method 'ClientUpdatePosition'
		// Here lies the not-yet-implemented method 'GetFreeMove'
		// Here lies the not-yet-implemented method 'CompressAccel'
		// Here lies the not-yet-implemented method 'ReplicateMove'
		// Here lies the not-yet-implemented method 'CallServerMove'
		// Here lies the not-yet-implemented method 'HandleWalking'
		// Here lies the not-yet-implemented method 'ServerRestartGame'
		// Here lies the not-yet-implemented method 'RestartLevel'
		// Here lies the not-yet-implemented method 'PauseRumbleForAllPlayers'
		// Here lies the not-yet-implemented method 'CanUnpause'
		// Here lies the not-yet-implemented method 'SetPause'
		// Here lies the not-yet-implemented method 'IsPaused'
		// Here lies the not-yet-implemented method 'Pause'
		// Here lies the not-yet-implemented method 'ServerPause'
		// Here lies the not-yet-implemented method 'ConditionalPause'
		// Here lies the not-yet-implemented method 'ThrowWeapon'
		// Here lies the not-yet-implemented method 'ServerThrowWeapon'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'StopFire'
		// Here lies the not-yet-implemented method 'StartAltFire'
		// Here lies the not-yet-implemented method 'StopAltFire'
		// Here lies the not-yet-implemented method 'GetTriggerUseList'
		// Here lies the not-yet-implemented method 'Use'
		// Here lies the not-yet-implemented method 'ServerUse'
		// Here lies the not-yet-implemented method 'PerformedUseAction'
		// Here lies the not-yet-implemented method 'FindVehicleToDrive'
		// Here lies the not-yet-implemented method 'TriggerInteracted'
		// Here lies the not-yet-implemented method 'Suicide'
		// Here lies the not-yet-implemented method 'ServerSuicide'
		// Here lies the not-yet-implemented method 'SetName'
		// Here lies the not-yet-implemented method 'ServerChangeName'
		// Here lies the not-yet-implemented method 'SwitchTeam'
		// Here lies the not-yet-implemented method 'ChangeTeam'
		// Here lies the not-yet-implemented method 'ServerChangeTeam'
		// Here lies the not-yet-implemented method 'ClientSetProgressMessage'
		// Here lies the not-yet-implemented method 'Restart'
		// Here lies the not-yet-implemented method 'ServerNotifyLoadedWorld'
		// Here lies the not-yet-implemented method 'NotifyLoadedWorld'
		// Here lies the not-yet-implemented method 'HasClientLoadedCurrentWorld'
		// Here lies the not-yet-implemented method 'ForceSingleNetUpdateFor'
		// Here lies the not-yet-implemented method 'EnterStartState'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'GameHasEnded'
		// Here lies the not-yet-implemented method 'ClientGameEnded'
		// Here lies the not-yet-implemented method 'NotifyChangedWeapon'
		// Here lies the not-yet-implemented method 'PlayerTick'
		// Here lies the not-yet-implemented method 'PlayerMove'
		// Here lies the not-yet-implemented method 'AimingHelp'
		// Here lies the not-yet-implemented method 'CameraLookAtFinished'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'AimHelpDot'
		// Here lies the not-yet-implemented method 'NotifyLanded'
		// Here lies the not-yet-implemented method 'AdjustFOV'
		// Here lies the not-yet-implemented method 'IsLocalPlayerController'
		// Here lies the not-yet-implemented method 'SetViewTarget'
		// Here lies the not-yet-implemented method 'SetViewTargetWithBlend'
		// Here lies the not-yet-implemented method 'ClientSetViewTarget'
		// Here lies the not-yet-implemented method 'ServerVerifyViewTarget'
		// Here lies the not-yet-implemented method 'SpawnPlayerCamera'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'ViewShake'
		// Here lies the not-yet-implemented method 'UpdateRotation'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'LimitViewRotation'
		// Here lies the not-yet-implemented method 'CheckJumpOrDuck'
		// Here lies the not-yet-implemented method 'IsSpectating'
		// Here lies the not-yet-implemented method 'ServerSetSpectatorLocation'
		// Here lies the not-yet-implemented method 'ServerViewNextPlayer'
		// Here lies the not-yet-implemented method 'ServerViewPrevPlayer'
		// Here lies the not-yet-implemented method 'ViewAPlayer'
		// Here lies the not-yet-implemented method 'ServerViewSelf'
		// Here lies the not-yet-implemented method 'IsWaiting'
		// Here lies the not-yet-implemented method 'CanRestartPlayer'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'OnToggleInput'
		// Here lies the not-yet-implemented method 'ClientIgnoreMoveInput'
		// Here lies the not-yet-implemented method 'ClientIgnoreLookInput'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'OnDrawText'
		// Here lies the not-yet-implemented method 'ClientDrawKismetText'
		// Here lies the not-yet-implemented method 'ClientClearKismetText'
		// Here lies the not-yet-implemented method 'OnSetCameraTarget'
		// Here lies the not-yet-implemented method 'OnToggleHUD'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'OnForceFeedback'
		// Here lies the not-yet-implemented method 'ClientStopForceFeedbackWaveform'
		// Here lies the not-yet-implemented method 'PlayRumble'
		// Here lies the not-yet-implemented method 'ClientPlayForceFeedbackWaveform'
		// Here lies the not-yet-implemented method 'IsForceFeedbackAllowed'
		// Here lies the not-yet-implemented method 'OnToggleCinematicMode'
		// Here lies the not-yet-implemented method 'SetCinematicMode'
		// Here lies the not-yet-implemented method 'ClientSetCinematicMode'
		// Here lies the not-yet-implemented method 'IgnoreMoveInput'
		// Here lies the not-yet-implemented method 'IsMoveInputIgnored'
		// Here lies the not-yet-implemented method 'IgnoreLookInput'
		// Here lies the not-yet-implemented method 'IsLookInputIgnored'
		// Here lies the not-yet-implemented method 'ResetPlayerMovementInput'
		// Here lies the not-yet-implemented method 'OnConsoleCommand'
		// Here lies the not-yet-implemented method 'ClientForceGarbageCollection'
		// Here lies the not-yet-implemented method 'LevelStreamingStatusChanged'
		// Here lies the not-yet-implemented method 'ClientUpdateLevelStreamingStatus'
		// Here lies the not-yet-implemented method 'ServerUpdateLevelVisibility'
		// Here lies the not-yet-implemented method 'ClientPrepareMapChange'
		// Here lies the not-yet-implemented method 'DelayedPrepareMapChange'
		// Here lies the not-yet-implemented method 'ClientCommitMapChange'
		// Here lies the not-yet-implemented method 'ClientCancelPendingMapChange'
		// Here lies the not-yet-implemented method 'ClientFlushLevelStreaming'
		// Here lies the not-yet-implemented method 'ClientSetBlockOnAsyncLoading'
		// Here lies the not-yet-implemented method 'IsPlayerMuted'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'SeamlessTravelTo'
		// Here lies the not-yet-implemented method 'SeamlessTravelFrom'
		// Here lies the not-yet-implemented method 'ClientSetOnlineStatus'
		// Here lies the not-yet-implemented method 'GetPlayerControllerFromNetId'
		// Here lies the not-yet-implemented method 'ClientVoiceHandshakeComplete'
		// Here lies the not-yet-implemented method 'ClientMutePlayer'
		// Here lies the not-yet-implemented method 'ClientUnmutePlayer'
		// Here lies the not-yet-implemented method 'GameplayMutePlayer'
		// Here lies the not-yet-implemented method 'GameplayUnmutePlayer'
		// Here lies the not-yet-implemented method 'ServerMutePlayer'
		// Here lies the not-yet-implemented method 'ServerUnmutePlayer'
		// Here lies the not-yet-implemented method 'NotifyDirectorControl'
		// Here lies the not-yet-implemented method 'SetShowSubtitles'
		// Here lies the not-yet-implemented method 'IsShowingSubtitles'
		// Here lies the not-yet-implemented method 'ClientWasKicked'
		// Here lies the not-yet-implemented method 'ClientRegisterForArbitration'
		// Here lies the not-yet-implemented method 'OnArbitrationRegisterComplete'
		// Here lies the not-yet-implemented method 'ServerRegisteredForArbitration'
		// Here lies the not-yet-implemented method 'OnGameInviteAccepted'
		// Here lies the not-yet-implemented method 'InviteHasEnoughSpace'
		// Here lies the not-yet-implemented method 'CanAllPlayersPlayOnline'
		// Here lies the not-yet-implemented method 'ClearInviteDelegates'
		// Here lies the not-yet-implemented method 'OnEndForInviteComplete'
		// Here lies the not-yet-implemented method 'OnDestroyForInviteComplete'
		// Here lies the not-yet-implemented method 'ModifyClientURL'
		// Here lies the not-yet-implemented method 'OnInviteJoinComplete'
		// Here lies the not-yet-implemented method 'NotifyInviteFailed'
		// Here lies the not-yet-implemented method 'NotifyNotAllPlayersCanJoinInvite'
		// Here lies the not-yet-implemented method 'NotifyNotEnoughSpaceInInvite'
		// Here lies the not-yet-implemented method 'ClientArbitratedMatchEnded'
		// Here lies the not-yet-implemented method 'ClientWriteOnlinePlayerScores'
		// Here lies the not-yet-implemented method 'ClientWriteLeaderboardStats'
		// Here lies the not-yet-implemented method 'ClientSetHostUniqueId'
		// Here lies the not-yet-implemented method 'ClientStopNetworkedVoice'
		// Here lies the not-yet-implemented method 'ClientStartNetworkedVoice'
		// Here lies the not-yet-implemented method 'OnDestroy'
		// Here lies the not-yet-implemented method 'DrawDebugTextList'
		// Here lies the not-yet-implemented method 'AddDebugText'
		// Here lies the not-yet-implemented method 'RemoveDebugText'
		// Here lies the not-yet-implemented method 'RemoveAllDebugStrings'
		// Here lies the not-yet-implemented method 'ClientRegisterHostStatGuid'
		// Here lies the not-yet-implemented method 'OnRegisterHostStatGuidComplete'
		// Here lies the not-yet-implemented method 'ServerRegisterClientStatGuid'
		// Here lies the not-yet-implemented method 'ClientStartOnlineGame'
		// Here lies the not-yet-implemented method 'ClientEndOnlineGame'
		// Here lies the not-yet-implemented method 'CanViewUserCreatedContent'
		// Here lies the not-yet-implemented method 'IncrementNumberOfMatchesPlayed'
		// Here lies the not-yet-implemented method 'SoakPause'
		// Here lies the not-yet-implemented method 'ClientTravelToSession'
		// Here lies the not-yet-implemented method 'OnJoinTravelToSessionComplete'
		// Here lies the not-yet-implemented method 'ClientReturnToParty'
		// Here lies the not-yet-implemented method 'IsSplitscreenPlayer'
		// Here lies the not-yet-implemented method 'GetSplitscreenPlayerByIndex'
		// Here lies the not-yet-implemented method 'GetSplitscreenPlayerCount'
		// Here lies the not-yet-implemented method 'ClientControlMovieTexture'
		// Here lies the not-yet-implemented method 'ClientSetForceMipLevelsToBeResident'
		// Here lies the not-yet-implemented method 'ClientPrestreamTextures'
		// Here lies the not-yet-implemented method 'IsPartyLeader'
		// Here lies the not-yet-implemented method 'GetPartyMapName'
		// Here lies the not-yet-implemented method 'GetPartyGameTypeName'
		// Here lies the not-yet-implemented method 'GetAchievementProgression'
		// Here lies the not-yet-implemented method 'OnFlyThroughHasEnded'
		// Here lies the not-yet-implemented method 'Sentinel_SetupForGamebasedTravelTheWorld'
		// Here lies the not-yet-implemented method 'Sentinel_PreAcquireTravelTheWorldPoints'
		// Here lies the not-yet-implemented method 'Sentinel_PostAcquireTravelTheWorldPoints'
		// Here lies the not-yet-implemented method 'InputMatchDelegate'
		// Here lies the not-yet-implemented method 'DoForceFeedbackForScreenShake'
		// Here lies the not-yet-implemented method 'ClientPlayCameraShake'
		// Here lies the not-yet-implemented method 'ClientStopCameraShake'
		// Here lies the not-yet-implemented method 'OnCameraShake'
		// Here lies the not-yet-implemented method 'ClientPlayCameraAnim'
		// Here lies the not-yet-implemented method 'ClientStopCameraAnim'
		// Here lies the not-yet-implemented method 'ClientSpawnCameraLensEffect'
		// Here lies the not-yet-implemented method 'OnSetSoundMode'
		// Here lies the not-yet-implemented method 'HasPeerConnection'
		// Here lies the not-yet-implemented method 'BugItGo'
		// Here lies the not-yet-implemented method 'BugItGoString'
		// Here lies the not-yet-implemented method 'BugItWorker'
		// Here lies the not-yet-implemented method 'BugIt'
		// Here lies the not-yet-implemented method 'LogOutBugItGoToLogFile'
		// Here lies the not-yet-implemented method 'LogLoc'
		// Here lies the not-yet-implemented method 'BugItAI'
		// Here lies the not-yet-implemented method 'LogOutBugItAIGoToLogFile'
		// Here lies the not-yet-implemented method 'BugItStringCreator'
		// Here lies the not-yet-implemented method 'OnEngineInitialTick'
		// Here lies the not-yet-implemented method 'DisableDebugAI'
		// Here lies the not-yet-implemented method 'ReceivedGameClass'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
