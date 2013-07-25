#pragma once
#include "UTGame__UTPlayerController.h"
#include "Engine__CameraShake.h"
#include "TribesGame__TrEquipInterface.h"
#include "TribesGame__AlienFXManager.h"
#include "TribesGame__TrProjectile.h"
#include "Engine__Weapon.h"
#include "TribesGame__TrHelpTextManager.h"
#include "TribesGame__TrStrings.h"
#include "TribesGame__TrInventoryHelper.h"
#include "Engine__MaterialEffect.h"
#include "TribesGame__TrAccoladeManager.h"
#include "TribesGame__TrCameraModifier_CameraShake.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__Actor.h"
#include "TribesGame__TrChatConsoleCommands.h"
#include "TribesGame__TrContentLoader.h"
#include "TribesGame__TrWeatherVolume.h"
#include "Engine__SoundCue.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrPaperDoll.h"
#include "TribesGame__TrVehicle.h"
#include "UDKBase__UDKEmitCameraEffect.h"
#include "TribesGame__TrAnnouncer.h"
#include "TribesGame__TrMusicManager.h"
#include "TribesGame__TrStation.h"
#include "Engine__CameraActor.h"
#include "TribesGame__TrDevice.h"
#include "Engine__Pawn.h"
#include "Core__Object.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__PlayerInput.h"
#include "TribesGame__TrFlagBase.h"
#include "TribesGame__TrPlayerInput_Spectator.h"
#include "TribesGame__TrDeployable_MotionSensor.h"
#include "TribesGame__TrFlagCTF.h"
#include "TribesGame__TrSeqAct_PlayVGSCommand.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrSeqAct_GiveAccolade.h"
#include "TribesGame__TrCamera_SpectatorBookmark.h"
#include "TribesGame__TrPlayerReplicationInfo.h"
#include "TribesGame__TrSeqAct_GiveCredits.h"
#include "TribesGame__TrSeqAct_RefreshInventory.h"
#include "TribesGame__TrVehicleStation.h"
#include "UTGame__UTTeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerController : public UTPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, m_bShowHUDCracks, 0x100000)
		ADD_OBJECT(TrEquipInterface, m_TrEquipInterface)
		ADD_VAR(::BoolProperty, m_bShowSpectatorHUD, 0x10000000)
		ADD_VAR(::BoolProperty, m_bShowSpectatorControls, 0x8000000)
		ADD_VAR(::BoolProperty, m_bShowHUDVisor, 0x100)
		ADD_VAR(::BoolProperty, m_bShowHUDHealthBar, 0x80)
		ADD_VAR(::BoolProperty, m_bShowHUDHeroText, 0x2000)
		ADD_VAR(::BoolProperty, m_bShowHUDKillbox, 0x800)
		ADD_VAR(::BoolProperty, m_bShowHUDCombatLog, 0x400)
		ADD_VAR(::BoolProperty, m_bShowHUDSkiBars, 0x10000)
		ADD_VAR(::BoolProperty, m_bShowHUDCredits, 0x8)
		ADD_VAR(::BoolProperty, m_bShowHUDReticule, 0x4)
		ADD_VAR(::BoolProperty, m_bShowHUDChat, 0x200)
		ADD_VAR(::BoolProperty, m_bShowHUDPromptPanel, 0x4000)
		ADD_VAR(::BoolProperty, m_bShowHUDDeathcam, 0x1000)
		ADD_VAR(::BoolProperty, m_bShowHUDRespawnTimer, 0x8000)
		ADD_VAR(::FloatProperty, r_fRespawnTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsRovingSpectating, 0x20000000)
		ADD_VAR(::BoolProperty, m_bViewThroughDeathCamera, 0x400000)
		ADD_OBJECT(AlienFXManager, AlienFX)
		ADD_VAR(::BoolProperty, EnableAlienFX, 0x800000)
		ADD_VAR(::BoolProperty, m_bShowHUDScores, 0x40)
		ADD_VAR(::IntProperty, m_nLastDamagerUpgradeLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastDamagerHealthPercent, 0xFFFFFFFF)
		ADD_OBJECT(TrStrings, Strings)
		ADD_OBJECT(TrInventoryHelper, m_TrInventoryHelper)
		ADD_VAR(::BoolProperty, m_bShowHUDBadges, 0x20)
		ADD_VAR(::BoolProperty, m_bShowHUDAccolades, 0x10)
		ADD_VAR(::BoolProperty, r_bNeedTeam, 0x8000)
		ADD_VAR(::BoolProperty, r_bNeedLoadout, 0x10000)
		ADD_VAR(::BoolProperty, r_bDailyCompleted, 0x2000000)
		ADD_VAR(::IntProperty, m_RequestedTeam, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoRevertSetting, 0x2000000)
		ADD_VAR(::FloatProperty, m_fLastHitEnemyTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_LastKilledBy)
		ADD_VAR(::ByteProperty, r_nHitEnemyHeadshot, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAllowSimulatedProjectiles, 0x400000)
		ADD_VAR(::BoolProperty, c_bPressingZoomButton, 0x200)
		ADD_OBJECT(TrHelpTextManager, m_HelpTextManager)
		ADD_STRUCT(::RotatorProperty, m_rCurrentKickbackDirection, 0xFFFFFFFF
		ADD_OBJECT(MaterialEffect, m_ZoomedEffect)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_OBJECT(TrAccoladeManager, m_AccoladeManager)
		ADD_STRUCT(::VectorProperty, m_vDeathCamOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fDeathCameraCurrentScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeathCameraInnerScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeathCameraInterpSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_OldPossessedFamilyInfo)
		ADD_VAR(::IntProperty, m_BeginPlayedTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bPressingJetpack, 0x4)
		ADD_OBJECT(Actor, m_LastDamagedBy)
		ADD_VAR(::IntProperty, FriendlyFireDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastFlagGrabTimestamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bShowHUDFriendColoring, 0x20000)
		ADD_VAR(::BoolProperty, m_bEjectedFromVehicle, 0x10000000)
		ADD_VAR(::BoolProperty, m_bLastDeathWasUserSuicide, 0x200000)
		ADD_VAR(::IntProperty, FriendlyFireKills, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_ZoomState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFreeCamYawOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFreeCamPitchOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCallInCooldown, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nCallinCooldownFlash, 0xFFFFFFFF)
		ADD_OBJECT(TrChatConsoleCommands, m_PlayerCommands)
		ADD_VAR(::FloatProperty, fSniperRespawnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSuicideTimestamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VGSClassId, 0xFFFFFFFF)
		ADD_OBJECT(TrContentLoader, c_ContentLoader)
		ADD_VAR(::IntProperty, m_WhisperFilter, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, r_rViewTargetViewRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, r_vViewTargetViewLocation, 0xFFFFFFFF
		ADD_OBJECT(PlayerReplicationInfo, r_ViewTargetVehiclePassengerPRI)
		ADD_OBJECT(PlayerReplicationInfo, r_ViewTargetVehicleDriverPRI)
		ADD_VAR(::FloatProperty, r_fViewTargetVehicleMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fViewTargetVehicleCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetPackAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetOffhandAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetSecondaryMaxAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetPrimaryMaxAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetSecondaryAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nViewTargetPrimaryAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fViewTargetMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fViewTargetCurrentPowerpool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fViewTargetNextRegenTimestamp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nMaxVGSSoundChannels, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_TeamRabbitAssistCredit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_TeamAssistCredit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_DamageNeededForCredit, 0xFFFFFFFF)
		ADD_OBJECT(MaterialEffect, m_RoundEndedME)
		ADD_VAR(::FloatProperty, m_fDeterminationAccumulator, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeterminationAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LoadingScreenTimeout, 0xFFFFFFFF)
		ADD_OBJECT(TrPaperDoll, m_PaperDoll)
		ADD_VAR(::FloatProperty, m_fDeathCameraOuterScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fUserSuicideTimePenalty, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpamLockoutTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLockoutFromSpamTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMessageSpamTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_fMaxBroadcastSpamCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSpotTargetTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, s_nNewPlayerAssistPoints, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, s_nMaxNewPlayerAssistPoints, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, s_fNewPlayerAssistMitigateCauseDamageMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, s_fNewPlayerAssistMitigateTakeDamageMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFlagGrabSpeedRecord, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFlagCapSpeedRecord, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiSpeedRecord, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedCheckTotal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSpeedCheckCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSpeedCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedCheckInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHideJetpackHelpTextDistanceThresholdSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTotalDistanceJetpackedSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHideSkiHelpTextDistanceThresholdSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastDistanceSkiedSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastDistanceCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDistanceCheckInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTotalDistanceSkiedSq, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_HelpTextManagerClass)
		ADD_OBJECT(TrVehicle, m_LastAcknowledgedVehicle)
		ADD_VAR(::IntProperty, m_ActiveClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_LastVGSUse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIdleCheckTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RoundEndedVZeroSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RoundEndedPPTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RoundEndedPPAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RoundEndedPPInterpSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'm_RoundEndedPPSettings'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'm_DefaultPPSettings'!
		ADD_VAR(::FloatProperty, m_fSpeedCameraSpeedSqared, 0xFFFFFFFF)
		ADD_OBJECT(UDKEmitCameraEffect, m_WeatherCameraEffect)
		ADD_OBJECT(UDKEmitCameraEffect, m_SpeedCameraEffect)
		ADD_VAR(::IntProperty, m_nLatestAccoladeIcon, 0xFFFFFFFF)
		ADD_OBJECT(TrCameraModifier_CameraShake, m_CameraShake)
		ADD_OBJECT(Weapon, m_LastWeaponEquipped)
		ADD_VAR(::IntProperty, m_VehicleSeatIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_LastPressedSkiTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinActiveSkiTimeToEnableFollowthough, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiFollowthroughTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, r_KilledBy)
		ADD_VAR(::FloatProperty, m_LastLoadoutRequestTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nClientSpawnTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRespawnTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPlayBeginTime, 0xFFFFFFFF)
		ADD_OBJECT(TrAnnouncer, m_Announcer)
		ADD_OBJECT(TrMusicManager, m_MusicManager)
		ADD_VAR(::FloatProperty, c_fHUDZoomDuration, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_nCallinCooldownFlashStored, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_nLastHitEnemyHeadshot, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nHitEnemy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, c_fZoomButtonPressedTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fZoomRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDesiredMagnifiedZoomFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDesiredZoomFOV, 0xFFFFFFFF)
		ADD_OBJECT(TrStation, m_CurrentStation)
		ADD_VAR(::IntProperty, r_nCurrentCredits, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_RicochetSound3P)
		ADD_OBJECT(SoundCue, m_MissileSeekingSelfCue)
		ADD_OBJECT(SoundCue, m_MissileFiredCue)
		ADD_OBJECT(SoundCue, m_MissileLockedCue)
		ADD_OBJECT(SoundCue, m_MissileLockingCue)
		ADD_VAR(::IntProperty, m_OverwatchTeam, 0xFFFFFFFF)
		ADD_OBJECT(CameraActor, m_OverwatchCam)
		ADD_STRUCT(::RotatorProperty, m_rKickbackAim, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fLastKickbackViewTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fKickbackViewBlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fKickbackViewBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingInitiatingJettingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWarmingUp, 0x20000000)
		ADD_VAR(::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x8000000)
		ADD_VAR(::BoolProperty, m_bEnableChatFilter, 0x4000000)
		ADD_VAR(::BoolProperty, bBlockForAcquisition, 0x1000000)
		ADD_VAR(::BoolProperty, m_bAnimMenu, 0x200000)
		ADD_VAR(::BoolProperty, m_bShowHUDFriendStateNotifications, 0x80000)
		ADD_VAR(::BoolProperty, m_bShowHUDNotifications, 0x40000)
		ADD_VAR(::BoolProperty, m_bShowHUDObjectives, 0x2)
		ADD_VAR(::BoolProperty, m_bEnableOverheadDamageIndicators, 0x1)
		ADD_VAR(::BoolProperty, r_bViewTargetVehicleSecondaryWeaponReady, 0x80000000)
		ADD_VAR(::BoolProperty, r_bViewTargetVehiclePrimaryWeaponReady, 0x40000000)
		ADD_VAR(::BoolProperty, r_bWeeklyCompleted, 0x4000000)
		ADD_VAR(::BoolProperty, m_bIsJumpJetting, 0x1000000)
		ADD_VAR(::BoolProperty, m_bJustJoined, 0x800000)
		ADD_VAR(::BoolProperty, m_bMonkeyMode, 0x100000)
		ADD_VAR(::BoolProperty, m_bJetpackHelpTextThresholdReached, 0x80000)
		ADD_VAR(::BoolProperty, m_bSkiHelpTextThresholdReached, 0x40000)
		ADD_VAR(::BoolProperty, m_bEnableCameraSpeedEffect, 0x20000)
		ADD_VAR(::BoolProperty, m_bLoadoutChangeAlerted, 0x4000)
		ADD_VAR(::BoolProperty, m_bRequestingSki, 0x2000)
		ADD_VAR(::BoolProperty, m_bPlayerSwappedTeams, 0x1000)
		ADD_VAR(::BoolProperty, m_bReturnTo3PAfterZoom, 0x800)
		ADD_VAR(::BoolProperty, m_bZoomMagnified, 0x400)
		ADD_VAR(::BoolProperty, m_bPlayCreditsSound, 0x100)
		ADD_VAR(::BoolProperty, bWasAutoBalanced, 0x80)
		ADD_VAR(::BoolProperty, m_bAftermathKill, 0x40)
		ADD_VAR(::BoolProperty, m_bKickbackBlendingIn, 0x20)
		ADD_VAR(::BoolProperty, m_bBlink, 0x10)
		ADD_VAR(::BoolProperty, m_bJumpJet, 0x8)
		ADD_VAR(::BoolProperty, m_bPressingJetpackButton, 0x2)
		ADD_VAR(::BoolProperty, m_bEditorMode, 0x1)
		ADD_VAR(::FloatProperty, m_fLastWeaponSwitchTimestamp, 0xFFFFFFFF)
		ADD_OBJECT(Actor, m_aHoverActor)
		// Here lies the not-yet-implemented method 'GetLanguageFontIndex'
		// Here lies the not-yet-implemented method 'InTraining'
		// Here lies the not-yet-implemented method 'GetFamilyInfoFromId'
		// Here lies the not-yet-implemented method 'GetDeviceByEquipPoint'
		// Here lies the not-yet-implemented method 'GetZoomedState'
		// Here lies the not-yet-implemented method 'InRovingSpectate'
		// Here lies the not-yet-implemented method 'IsTrPlayerMuted'
		// Here lies the not-yet-implemented method 'GetActiveClassId'
		// Here lies the not-yet-implemented method 'GetTeamClassCount'
		// Here lies the not-yet-implemented method 'RegisterPendingClass'
		// Here lies the not-yet-implemented method 'GetAllowedClassCount'
		// Here lies the not-yet-implemented method 'SendPrivateChatMessage'
		// Here lies the not-yet-implemented method 'BroadcastChatMessage'
		// Here lies the not-yet-implemented method 'ServerRequestPickTeam'
		// Here lies the not-yet-implemented method 'ChooseBloodEagle'
		// Here lies the not-yet-implemented method 'ChooseDiamondSword'
		// Here lies the not-yet-implemented method 'GetVehicleCost'
		// Here lies the not-yet-implemented method 'GetCurrentCredits'
		// Here lies the not-yet-implemented method 'IsBassBoostToggled'
		// Here lies the not-yet-implemented method 'AllowHelpTextToDisplay'
		// Here lies the not-yet-implemented method 'NeedToVisitInventoryStation'
		// Here lies the not-yet-implemented method 'GetCurrentDetermination'
		// Here lies the not-yet-implemented method 'GetNewPlayerAssistToApply'
		// Here lies the not-yet-implemented method 'PlayReliableSound'
		// Here lies the not-yet-implemented method 'SendCtrlRequest'
		// Here lies the not-yet-implemented method 'SendGameRequest'
		// Here lies the not-yet-implemented method 'TestSteamPurchase'
		// Here lies the not-yet-implemented method 'ShowAdminPage'
		// Here lies the not-yet-implemented method 'SetHitValidationMode'
		// Here lies the not-yet-implemented method 'KickPlayerFromMatch'
		// Here lies the not-yet-implemented method 'MainMenuIsOpen'
		// Here lies the not-yet-implemented method 'SetMenuInGame'
		// Here lies the not-yet-implemented method 'SendMenuToLobby'
		// Here lies the not-yet-implemented method 'TweenSummaryScreen'
		// Here lies the not-yet-implemented method 'SetMenuSummaryScreen'
		// Here lies the not-yet-implemented method 'SetMenuEndOfMatch'
		// Here lies the not-yet-implemented method 'BeginExperienceTweens'
		// Here lies the not-yet-implemented method 'KickVoteReply'
		// Here lies the not-yet-implemented method 'SetMenuMatchCountdown'
		// Here lies the not-yet-implemented method 'GetUserSelectedClass'
		// Here lies the not-yet-implemented method 'RevertSetting'
		// Here lies the not-yet-implemented method 'SendMenuBack'
		// Here lies the not-yet-implemented method 'FireAcquisition'
		// Here lies the not-yet-implemented method 'ForceFocus'
		// Here lies the not-yet-implemented method 'UpdateTVTimer'
		// Here lies the not-yet-implemented method 'UpdateDealTimer'
		// Here lies the not-yet-implemented method 'UpdateQueueTimer'
		// Here lies the not-yet-implemented method 'ToggleWorkingGraphic'
		// Here lies the not-yet-implemented method 'EndHotkeyBlock'
		// Here lies the not-yet-implemented method 'MutePlayer'
		// Here lies the not-yet-implemented method 'UnmutePlayer'
		// Here lies the not-yet-implemented method 'HaveMenu'
		// Here lies the not-yet-implemented method 'IsChatFiltered'
		// Here lies the not-yet-implemented method 'RequestKickVote'
		// Here lies the not-yet-implemented method 'HideMenu'
		// Here lies the not-yet-implemented method 'OpenMenu'
		// Here lies the not-yet-implemented method 'OpenClasses'
		// Here lies the not-yet-implemented method 'ToggleFriends'
		// Here lies the not-yet-implemented method 'ToggleSettings'
		// Here lies the not-yet-implemented method 'ToggleMainMenu'
		// Here lies the not-yet-implemented method 'ClaimPromotion'
		// Here lies the not-yet-implemented method 'FireUILoadSummary'
		// Here lies the not-yet-implemented method 'FireRefreshPage'
		// Here lies the not-yet-implemented method 'ToggleBassBoost'
		// Here lies the not-yet-implemented method 'ForwardChatFlag'
		// Here lies the not-yet-implemented method 'ShowNotification'
		// Here lies the not-yet-implemented method 'HideNotification'
		// Here lies the not-yet-implemented method 'ChatMessageReceived'
		// Here lies the not-yet-implemented method 'ShowChat'
		// Here lies the not-yet-implemented method 'HideChat'
		// Here lies the not-yet-implemented method 'ToggleChat'
		// Here lies the not-yet-implemented method 'PushChat'
		// Here lies the not-yet-implemented method 'Bug'
		// Here lies the not-yet-implemented method '_Crash'
		// Here lies the not-yet-implemented method 'IsGameUsingSeekFreeLoading'
		// Here lies the not-yet-implemented method 'ResetRunaway'
		// Here lies the not-yet-implemented method 'ClearVehicleMenu'
		// Here lies the not-yet-implemented method 'ShowVehicleMenu'
		// Here lies the not-yet-implemented method 'AddVehicleMenuOption'
		// Here lies the not-yet-implemented method 'GetOnlineFriends'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitHelpTextManager'
		// Here lies the not-yet-implemented method 'InitInputSystem'
		// Here lies the not-yet-implemented method 'PlayAnnouncerSound'
		// Here lies the not-yet-implemented method 'TestAnnouncement'
		// Here lies the not-yet-implemented method 'ClientHearReliableSound'
		// Here lies the not-yet-implemented method 'ClientMySaberLauncherTargetingUpdated'
		// Here lies the not-yet-implemented method 'ClientSeekingMissileTargetingSelfEvent'
		// Here lies the not-yet-implemented method 'OnMissileIntercepted'
		// Here lies the not-yet-implemented method 'ShowHUDNotification'
		// Here lies the not-yet-implemented method 'HideHUDNotification'
		// Here lies the not-yet-implemented method 'CheckBulletWhip'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ProcessCreditEvent'
		// Here lies the not-yet-implemented method 'ModifyCredits'
		// Here lies the not-yet-implemented method 'UpdateCurrentCredits'
		// Here lies the not-yet-implemented method 'CreditsSoundFinished'
		// Here lies the not-yet-implemented method 'ClientUpdateCredits'
		// Here lies the not-yet-implemented method 'GetLatestAccoladeIconIndex'
		// Here lies the not-yet-implemented method 'ClientShowAccoladeIcon'
		// Here lies the not-yet-implemented method 'ClientShowAccoladeText'
		// Here lies the not-yet-implemented method 'ResetStreaks'
		// Here lies the not-yet-implemented method 'GiveCredits'
		// Here lies the not-yet-implemented method 'ServerGiveCreditsCheat'
		// Here lies the not-yet-implemented method 'AimingHelp'
		// Here lies the not-yet-implemented method 'NotifyChangedWeapon'
		// Here lies the not-yet-implemented method 'ReloadWeapon'
		// Here lies the not-yet-implemented method 'ServerReloadWeapon'
		// Here lies the not-yet-implemented method 'ServerSetCharFamily'
		// Here lies the not-yet-implemented method 'Suicide'
		// Here lies the not-yet-implemented method 'ServerSuicide'
		// Here lies the not-yet-implemented method 'GetArmorType'
		// Here lies the not-yet-implemented method 'GetRespawnDelayTotalTime'
		// Here lies the not-yet-implemented method 'LimitViewRotation'
		// Here lies the not-yet-implemented method 'PressedMelee'
		// Here lies the not-yet-implemented method 'PressedLaser'
		// Here lies the not-yet-implemented method 'PressedBelt'
		// Here lies the not-yet-implemented method 'PressedPack'
		// Here lies the not-yet-implemented method 'PressedDeployable'
		// Here lies the not-yet-implemented method 'SetShowEquip'
		// Here lies the not-yet-implemented method 'PressedConsoleUse'
		// Here lies the not-yet-implemented method 'PressedWeaponSwitch'
		// Here lies the not-yet-implemented method 'EquipPrimary'
		// Here lies the not-yet-implemented method 'EquipSecondary'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'PrevWeapon'
		// Here lies the not-yet-implemented method 'NextWeapon'
		// Here lies the not-yet-implemented method 'ActivateDevice'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'UpdateLockedTarget'
		// Here lies the not-yet-implemented method 'IdentifyTeamMessage'
		// Here lies the not-yet-implemented method 'PlayStartupMessage'
		// Here lies the not-yet-implemented method 'FindValidGRI'
		// Here lies the not-yet-implemented method 'InitHUDObjects'
		// Here lies the not-yet-implemented method 'ClientStartSpawnTimer'
		// Here lies the not-yet-implemented method 'CompletePickTeam'
		// Here lies the not-yet-implemented method 'ServerRequestAutoAssignTeam'
		// Here lies the not-yet-implemented method 'ClientEndTeamSelect'
		// Here lies the not-yet-implemented method 'ChangeTeam'
		// Here lies the not-yet-implemented method 'ViewAPlayer'
		// Here lies the not-yet-implemented method 'ServerPlayerTick'
		// Here lies the not-yet-implemented method 'PlayerTick'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'StartWeather'
		// Here lies the not-yet-implemented method 'StopWeather'
		// Here lies the not-yet-implemented method 'PawnEnteredWeatherVolume'
		// Here lies the not-yet-implemented method 'PawnLeftWeatherVolume'
		// Here lies the not-yet-implemented method 'PlayLowHealthFX'
		// Here lies the not-yet-implemented method 'StopLowHealthFX'
		// Here lies the not-yet-implemented method 'PlayRechargeHealthFX'
		// Here lies the not-yet-implemented method 'StopRechargeHealthFX'
		// Here lies the not-yet-implemented method 'ToggleJetpack'
		// Here lies the not-yet-implemented method 'EnableJetpack'
		// Here lies the not-yet-implemented method 'IgnoreMoveInput'
		// Here lies the not-yet-implemented method 'DoJump'
		// Here lies the not-yet-implemented method 'PerformBlink'
		// Here lies the not-yet-implemented method 'GetBlinkPackAccel'
		// Here lies the not-yet-implemented method 'InitRespawnTimer'
		// Here lies the not-yet-implemented method 'UpdateRespawnTimer'
		// Here lies the not-yet-implemented method 'ServerRequestRespawn'
		// Here lies the not-yet-implemented method 'RequestRespawn'
		// Here lies the not-yet-implemented method 'Respawn'
		// Here lies the not-yet-implemented method 'PlayRespawnSoonSound'
		// Here lies the not-yet-implemented method 'CleanupGameplayEffectsOnDeath'
		// Here lies the not-yet-implemented method 'OnCrossedOffArenaList'
		// Here lies the not-yet-implemented method 'Possess'
		// Here lies the not-yet-implemented method 'RefreshHUD'
		// Here lies the not-yet-implemented method 'GetAirVehicleInversion'
		// Here lies the not-yet-implemented method 'ServerSetAirVehicleControls'
		// Here lies the not-yet-implemented method 'SetAirVehicleControls'
		// Here lies the not-yet-implemented method 'IsInVehicle'
		// Here lies the not-yet-implemented method 'ClientVehiclePhysUpdated'
		// Here lies the not-yet-implemented method 'ServerVehiclePhysUpdated'
		// Here lies the not-yet-implemented method 'ServerVerifyVehiclePhys'
		// Here lies the not-yet-implemented method 'ServerCorrectClientPhys'
		// Here lies the not-yet-implemented method 'ServerToggleVehicleJets'
		// Here lies the not-yet-implemented method 'ToggleVehicleJets'
		// Here lies the not-yet-implemented method 'ProcessRiding'
		// Here lies the not-yet-implemented method 'ServerRiding'
		// Here lies the not-yet-implemented method 'SwitchToCallIn'
		// Here lies the not-yet-implemented method 'ServerRequestCallInChange'
		// Here lies the not-yet-implemented method 'SwitchToSeat'
		// Here lies the not-yet-implemented method 'ServerSwitchToSeat'
		// Here lies the not-yet-implemented method 'TriggerInteracted'
		// Here lies the not-yet-implemented method 'ServerRequestLoadoutChange'
		// Here lies the not-yet-implemented method 'UpdatePaperDoll'
		// Here lies the not-yet-implemented method 'UpdatePaperDoll_Device'
		// Here lies the not-yet-implemented method 'SpawnVehicle'
		// Here lies the not-yet-implemented method 'RequestBuyVehicle'
		// Here lies the not-yet-implemented method 'PressedSki'
		// Here lies the not-yet-implemented method 'ReleasedSki'
		// Here lies the not-yet-implemented method 'ToggleSki'
		// Here lies the not-yet-implemented method 'DelayReleasedSki'
		// Here lies the not-yet-implemented method 'SetBindSkiJet'
		// Here lies the not-yet-implemented method 'ToggleShowObjectMarkers'
		// Here lies the not-yet-implemented method 'ServerStartSki'
		// Here lies the not-yet-implemented method 'ServerStopSki'
		// Here lies the not-yet-implemented method 'ClientSetHUD'
		// Here lies the not-yet-implemented method 'SwitchHud'
		// Here lies the not-yet-implemented method 'OnKickback'
		// Here lies the not-yet-implemented method 'UpdateKickbackDirection'
		// Here lies the not-yet-implemented method 'RestoreMoveInput'
		// Here lies the not-yet-implemented method 'ClientRestoreMoveInput'
		// Here lies the not-yet-implemented method 'ServerRequestSpawnVehicle'
		// Here lies the not-yet-implemented method 'PerformedUseAction'
		// Here lies the not-yet-implemented method 'PressedZoom'
		// Here lies the not-yet-implemented method 'ReleasedZoom'
		// Here lies the not-yet-implemented method 'MagnifyZoom'
		// Here lies the not-yet-implemented method 'DemagnifyZoom'
		// Here lies the not-yet-implemented method 'ReleaseZoom'
		// Here lies the not-yet-implemented method 'CheckZoomButton'
		// Here lies the not-yet-implemented method 'TrStartZoom'
		// Here lies the not-yet-implemented method 'TrStopZoom'
		// Here lies the not-yet-implemented method 'TrEndZoom'
		// Here lies the not-yet-implemented method 'ResetZoomDuration'
		// Here lies the not-yet-implemented method 'ServerSetZoom'
		// Here lies the not-yet-implemented method 'ReceiveLocalizedMessage'
		// Here lies the not-yet-implemented method 'ReceiveLocalizedNagMessage'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'TrClientMusicEvent'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'UpdateClientSpawnTimer'
		// Here lies the not-yet-implemented method 'GameHasEnded'
		// Here lies the not-yet-implemented method 'CheckJumpOrDuck'
		// Here lies the not-yet-implemented method 'ClientGameEnded'
		// Here lies the not-yet-implemented method 'ServerDropFlag'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'ActivateFreeCam'
		// Here lies the not-yet-implemented method 'DeactivateFreeCam'
		// Here lies the not-yet-implemented method 'SetViewTargetAsOverwatch'
		// Here lies the not-yet-implemented method 'PlayCameraShake'
		// Here lies the not-yet-implemented method 'ClientPlayForceFeedbackWaveform'
		// Here lies the not-yet-implemented method 'UpdateSpeedCameraEffect'
		// Here lies the not-yet-implemented method 'SpeedCamEffect'
		// Here lies the not-yet-implemented method 'ClientPulseHUD'
		// Here lies the not-yet-implemented method 'PulseShield'
		// Here lies the not-yet-implemented method 'AddTimePlayed'
		// Here lies the not-yet-implemented method 'AcknowledgePossession'
		// Here lies the not-yet-implemented method 'MatchEndSoundMode'
		// Here lies the not-yet-implemented method 'ResetSoundMode'
		// Here lies the not-yet-implemented method 'SuppressHelpText'
		// Here lies the not-yet-implemented method 'TalkVGS'
		// Here lies the not-yet-implemented method 'Say'
		// Here lies the not-yet-implemented method 'IsPlayerCommand'
		// Here lies the not-yet-implemented method 'ShowFeedbackMessage'
		// Here lies the not-yet-implemented method 'GetChatColor'
		// Here lies the not-yet-implemented method 'AddChatToConsole'
		// Here lies the not-yet-implemented method 'GetLastTellSender'
		// Here lies the not-yet-implemented method 'ReplyTalk'
		// Here lies the not-yet-implemented method 'CanCommunicate'
		// Here lies the not-yet-implemented method 'Talk'
		// Here lies the not-yet-implemented method 'ChatConsole'
		// Here lies the not-yet-implemented method 'TalkConsole'
		// Here lies the not-yet-implemented method 'TeamTalk'
		// Here lies the not-yet-implemented method 'TeamSay'
		// Here lies the not-yet-implemented method 'AllowTextMessage'
		// Here lies the not-yet-implemented method 'WarnPlayerAboutSpam'
		// Here lies the not-yet-implemented method 'BeginVGS'
		// Here lies the not-yet-implemented method 'SpotTarget'
		// Here lies the not-yet-implemented method 'ServerRequestVGSContextCommand'
		// Here lies the not-yet-implemented method 'ServerRequestVGSCommand'
		// Here lies the not-yet-implemented method 'ClientReceiveVGSCommand'
		// Here lies the not-yet-implemented method 'ClientReceiveVGSContextCommand'
		// Here lies the not-yet-implemented method 'ShowMoveErrors'
		// Here lies the not-yet-implemented method 'OnSkiHelpTextDistanceThresholdReached'
		// Here lies the not-yet-implemented method 'OnJetpackHelpTextDistanceThresholdReached'
		// Here lies the not-yet-implemented method 'LoadPlayerProfile'
		// Here lies the not-yet-implemented method 'GetNewPlayerAssistAmount'
		// Here lies the not-yet-implemented method 'UpdateNewPlayerAssistPoints'
		// Here lies the not-yet-implemented method 'BehindView'
		// Here lies the not-yet-implemented method 'ServerSetBehindView'
		// Here lies the not-yet-implemented method 'ClientSetBehindView'
		// Here lies the not-yet-implemented method 'GetEngineSettings'
		// Here lies the not-yet-implemented method 'GetSpectatorSettings'
		// Here lies the not-yet-implemented method 'ClientOnMotionSensorAlarmSounded'
		// Here lies the not-yet-implemented method 'ClientOnMotionSensorMineSounded'
		// Here lies the not-yet-implemented method 'LoadPendingLoadoutContentData'
		// Here lies the not-yet-implemented method 'LoadPendingDeviceContentData'
		// Here lies the not-yet-implemented method 'HideHUDElements'
		// Here lies the not-yet-implemented method 'ClientShowFlagIcon'
		// Here lies the not-yet-implemented method 'ClientSetPlayerClassObjects'
		// Here lies the not-yet-implemented method 'UpdatePotentialSeekingTargets'
		// Here lies the not-yet-implemented method 'NotifyHitWall'
		// Here lies the not-yet-implemented method 'NotifyFallingHitWall'
		// Here lies the not-yet-implemented method 'Spectate'
		// Here lies the not-yet-implemented method 'EndSpectate'
		// Here lies the not-yet-implemented method 'ClientSpectate'
		// Here lies the not-yet-implemented method 'ServerSpectate'
		// Here lies the not-yet-implemented method 'ServerViewFlags'
		// Here lies the not-yet-implemented method 'ServerViewFlagStands'
		// Here lies the not-yet-implemented method 'ServerViewGenerators'
		// Here lies the not-yet-implemented method 'ServerViewBookmark'
		// Here lies the not-yet-implemented method 'ServerViewVehicles'
		// Here lies the not-yet-implemented method 'ServerViewFastestPlayer'
		// Here lies the not-yet-implemented method 'ServerViewActor'
		// Here lies the not-yet-implemented method 'ClientOnViewTargetChange'
		// Here lies the not-yet-implemented method 'ServerIncreaseCamDistance'
		// Here lies the not-yet-implemented method 'ServerDecreaseCamDistance'
		// Here lies the not-yet-implemented method 'ServerSetMoveSpeed'
		// Here lies the not-yet-implemented method 'OnViewTargetCapturedFlag'
		// Here lies the not-yet-implemented method 'OnViewTargetFlagReturned'
		// Here lies the not-yet-implemented method 'OnViewTargetDroppedFlag'
		// Here lies the not-yet-implemented method 'OnViewTargetLeftVehicle'
		// Here lies the not-yet-implemented method 'GetViewTargetList'
		// Here lies the not-yet-implemented method 'ServerUnPossess'
		// Here lies the not-yet-implemented method 'ClientPlayTakeHit'
		// Here lies the not-yet-implemented method 'ClientPlayReticuleHitSound'
		// Here lies the not-yet-implemented method 'ClientPlayBluePlateImpact'
		// Here lies the not-yet-implemented method 'ClientPlayAirMailImpact'
		// Here lies the not-yet-implemented method 'SummarizeAwards'
		// Here lies the not-yet-implemented method 'ClientMatchOver'
		// Here lies the not-yet-implemented method 'ClientSetEndOfMatch'
		// Here lies the not-yet-implemented method 'ClientFadeToSummary'
		// Here lies the not-yet-implemented method 'UpdateMatchCountdown'
		// Here lies the not-yet-implemented method 'UpdateRoundCountdown'
		// Here lies the not-yet-implemented method 'UpdateGameCountdown'
		// Here lies the not-yet-implemented method 'ServerKickPlayer'
		// Here lies the not-yet-implemented method 'ClientKickPlayer'
		// Here lies the not-yet-implemented method 'KickWarning'
		// Here lies the not-yet-implemented method 'FumbledFlag'
		// Here lies the not-yet-implemented method 'ClientOnFumbledFlag'
		// Here lies the not-yet-implemented method 'UpdateCallInAvailability'
		// Here lies the not-yet-implemented method 'UpdateCallInCooldown'
		// Here lies the not-yet-implemented method 'CalcCameraOnViewTarget'
		// Here lies the not-yet-implemented method 'IsGameTypeArena'
		// Here lies the not-yet-implemented method 'IsGameTypeDaD'
		// Here lies the not-yet-implemented method 'IsGameTypeCaH'
		// Here lies the not-yet-implemented method 'SwitchToDeathCamera'
		// Here lies the not-yet-implemented method 'AddProjectileToTetherList'
		// Here lies the not-yet-implemented method 'CheckTetherList'
		// Here lies the not-yet-implemented method 'TetherProjectile'
		// Here lies the not-yet-implemented method 'ConfigureSkiSpeedSteps'
		// Here lies the not-yet-implemented method 'LoadingTimer'
		// Here lies the not-yet-implemented method 'FlushAccumulatedDetermination'
		// Here lies the not-yet-implemented method 'ClearDetermination'
		// Here lies the not-yet-implemented method 'AddDetermination'
		// Here lies the not-yet-implemented method 'OnMenuMovieOpened'
		// Here lies the not-yet-implemented method 'OnMenuMovieClosed'
		// Here lies the not-yet-implemented method 'ClientPlayVGSAudio'
		// Here lies the not-yet-implemented method 'VGSAudioFinished'
		// Here lies the not-yet-implemented method 'ClientSetLastDamagerInfo'
		// Here lies the not-yet-implemented method 'EnableTinyWeapons'
		// Here lies the not-yet-implemented method 'GetTinyWeaponValue'
		// Here lies the not-yet-implemented method 'EnableChatFilter'
		// Here lies the not-yet-implemented method 'GetChatFilterValue'
		// Here lies the not-yet-implemented method 'EnableDamageCounter'
		// Here lies the not-yet-implemented method 'GetDamageCounterValue'
		// Here lies the not-yet-implemented method 'EnableHUDObjectives'
		// Here lies the not-yet-implemented method 'EnableHUDReticule'
		// Here lies the not-yet-implemented method 'EnableHUDCredits'
		// Here lies the not-yet-implemented method 'EnableHUDAccolades'
		// Here lies the not-yet-implemented method 'EnableHUDBadges'
		// Here lies the not-yet-implemented method 'EnableHUDScores'
		// Here lies the not-yet-implemented method 'EnableHUDHealthBar'
		// Here lies the not-yet-implemented method 'EnableHUDVisor'
		// Here lies the not-yet-implemented method 'EnableHUDChat'
		// Here lies the not-yet-implemented method 'EnableHUDCombatLog'
		// Here lies the not-yet-implemented method 'EnableHUDKillbox'
		// Here lies the not-yet-implemented method 'EnableHUDDeathcam'
		// Here lies the not-yet-implemented method 'EnableHUDHeroText'
		// Here lies the not-yet-implemented method 'EnableHUDPromptPanel'
		// Here lies the not-yet-implemented method 'EnableHUDRespawnTimer'
		// Here lies the not-yet-implemented method 'EnableHUDSkiBars'
		// Here lies the not-yet-implemented method 'EnableHUDFriendColoring'
		// Here lies the not-yet-implemented method 'EnableHUDNotifications'
		// Here lies the not-yet-implemented method 'EnableHUDFriendStateNotifications'
		// Here lies the not-yet-implemented method 'EnableHUDCracks'
		// Here lies the not-yet-implemented method 'ShowAlienFX'
		// Here lies the not-yet-implemented method 'GetHUDObjectivesValue'
		// Here lies the not-yet-implemented method 'GetHUDNotifications'
		// Here lies the not-yet-implemented method 'GetHUDFriendStateNotifications'
		// Here lies the not-yet-implemented method 'GetWhisperFilterValue'
		// Here lies the not-yet-implemented method 'SetWhisperFilter'
		// Here lies the not-yet-implemented method 'SummaryTweenTimer'
		// Here lies the not-yet-implemented method 'VoteNo'
		// Here lies the not-yet-implemented method 'VoteYes'
		// Here lies the not-yet-implemented method 'FlashShooterHitReticule'
		// Here lies the not-yet-implemented method 'ServerShowOverheadNumber'
		// Here lies the not-yet-implemented method 'ClientShowOverheadNumber'
		// Here lies the not-yet-implemented method 'GetCreditsForDamageAmount'
		// Here lies the not-yet-implemented method 'CashForDamage'
		// Here lies the not-yet-implemented method 'AwardTeamAssistCredits'
		// Here lies the not-yet-implemented method 'AwardTeamRabbitAssistCredits'
		// Here lies the not-yet-implemented method 'TypeKeyPressed'
		// Here lies the not-yet-implemented method 'FOV'
		// Here lies the not-yet-implemented method 'FixFOV'
		// Here lies the not-yet-implemented method 'SetFOV'
		// Here lies the not-yet-implemented method 'ServerSetClassAffordable'
		// Here lies the not-yet-implemented method 'GetClassBit'
		// Here lies the not-yet-implemented method 'TestTrainingSlot'
		// Here lies the not-yet-implemented method 'TestSlot'
		// Here lies the not-yet-implemented method 'ServerTestSlot'
		// Here lies the not-yet-implemented method 'OnDeviceContentDataClassLoaded'
		// Here lies the not-yet-implemented method 'On3PSkinContentLoaded'
		// Here lies the not-yet-implemented method 'On1PSkinContentLoaded'
		// Here lies the not-yet-implemented method 'AddPending3PSkin'
		// Here lies the not-yet-implemented method 'OnClassSelectedMainMenu'
		// Here lies the not-yet-implemented method 'OnGiveCredits'
		// Here lies the not-yet-implemented method 'OnGiveAccolade'
		// Here lies the not-yet-implemented method 'OnPlayVGSCommand'
		// Here lies the not-yet-implemented method 'OnRefreshInventory'
		// Here lies the not-yet-implemented method 'StartForceFocusTimer'
		// Here lies the not-yet-implemented method 'StartAcquisitionFireTimer'
		// Here lies the not-yet-implemented method 'StartSettingBlock'
		// Here lies the not-yet-implemented method 'AutoRevertSetting'
		// Here lies the not-yet-implemented method 'StartSendMenuBackTimer'
		// Here lies the not-yet-implemented method 'QueueTimer'
		// Here lies the not-yet-implemented method 'TVTimer'
		// Here lies the not-yet-implemented method 'DealTimer'
		// Here lies the not-yet-implemented method 'StartHotkeyBlock'
		// Here lies the not-yet-implemented method 'ClientArenaRoundEnded'
		// Here lies the not-yet-implemented method 'ClientPlayerResettingAndRespawning'
		// Here lies the not-yet-implemented method 'DestroyAllOwnedDeployables'
		// Here lies the not-yet-implemented method 'DestroyAllOwnedMines'
		// Here lies the not-yet-implemented method 'DestroyAllOwnedProjectiles'
		// Here lies the not-yet-implemented method 'QueueBadge'
		// Here lies the not-yet-implemented method 'ClientQueueAccolade'
		// Here lies the not-yet-implemented method 'ClassHotkeyPTH'
		// Here lies the not-yet-implemented method 'ClassHotkeySEN'
		// Here lies the not-yet-implemented method 'ClassHotkeyINF'
		// Here lies the not-yet-implemented method 'ClassHotkeySLD'
		// Here lies the not-yet-implemented method 'ClassHotkeyRDR'
		// Here lies the not-yet-implemented method 'ClassHotkeyTCN'
		// Here lies the not-yet-implemented method 'ClassHotkeyJUG'
		// Here lies the not-yet-implemented method 'ClassHotkeyDMB'
		// Here lies the not-yet-implemented method 'ClassHotkeyBRT'
		// Here lies the not-yet-implemented method 'QuickClasses'
		// Here lies the not-yet-implemented method 'QuickLoadouts'
		// Here lies the not-yet-implemented method 'EndVGSInput'
		// Here lies the not-yet-implemented method 'StartUILoadSummaryTimer'
		// Here lies the not-yet-implemented method 'OpenVehicleMenu'
		// Here lies the not-yet-implemented method 'OnScoreChanged'
		// Here lies the not-yet-implemented method 'CheckFriendlyFireKills'
		// Here lies the not-yet-implemented method 'CheckFriendlyFireDamage'
		// Here lies the not-yet-implemented method 'StartRefreshPageTimer'
		// Here lies the not-yet-implemented method 'UpdateMainMenuPaperDoll_Mesh'
		// Here lies the not-yet-implemented method 'ClearMainMenuPaperDoll'
		// Here lies the not-yet-implemented method 'ClearPaperDoll'
		// Here lies the not-yet-implemented method 'SpecList'
		// Here lies the not-yet-implemented method 'SampleVoice'
		// Here lies the not-yet-implemented method 'StripTag'
		// Here lies the not-yet-implemented method 'SetAllowSimProjectiles'
		// Here lies the not-yet-implemented method 'ServerSetAllowSimProjectiles'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
