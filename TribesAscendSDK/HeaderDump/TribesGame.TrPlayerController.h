#pragma once
#include "TribesGame.TrPaperDoll.h"
#include "UTGame.UTPlayerController.h"
#include "Core.Object.Rotator.h"
#include "Engine.CameraActor.h"
#include "TribesGame.AlienFXManager.h"
#include "TribesGame.TrSeqAct_PlayVGSCommand.h"
#include "TribesGame.TrDeployable_MotionSensor.h"
#include "TribesGame.TrEquipInterface.h"
#include "Engine.MaterialEffect.h"
#include "TribesGame.TrStrings.h"
#include "Core.Object.Color.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "TribesGame.TrInventoryHelper.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Core.Object.h"
#include "TribesGame.TrStatsInterface.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "TribesGame.TrAccoladeManager.h"
#include "Core.Object.Vector.h"
#include "TribesGame.TrSeqAct_GiveCredits.h"
#include "Engine.Actor.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrChatConsoleCommands.h"
#include "TribesGame.TrStation.h"
#include "TribesGame.TrContentLoader.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrCamera_SpectatorBookmark.h"
#include "TribesGame.TrVehicle.h"
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
#include "TribesGame.TrWeatherVolume.h"
#include "Engine.Actor.RigidBodyState.h"
#include "Engine.PlayerInput.h"
#include "TribesGame.TrPlayerInput_Spectator.h"
#include "TribesGame.TrFlagCTF.h"
#include "TribesGame.TrFlagBase.h"
#include "TribesGame.TrProjectile.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.TrSeqAct_GiveAccolade.h"
#include "TribesGame.TrSeqAct_RefreshInventory.h"
#include "UTGame.UTTeamInfo.h"
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
		ADD_STRUCT(::RotatorProperty, m_rCurrentKickbackDirection, 0xFFFFFFFF)
		ADD_OBJECT(MaterialEffect, m_ZoomedEffect)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_OBJECT(TrAccoladeManager, m_AccoladeManager)
		ADD_STRUCT(::VectorProperty, m_vDeathCamOffset, 0xFFFFFFFF)
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
		ADD_STRUCT(::RotatorProperty, r_rViewTargetViewRotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vViewTargetViewLocation, 0xFFFFFFFF)
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
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, m_RoundEndedPPSettings, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PostProcessSettings>, m_DefaultPPSettings, 0xFFFFFFFF)
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
		ADD_STRUCT(::RotatorProperty, m_rKickbackAim, 0xFFFFFFFF)
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
		int GetLanguageFontIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLanguageFontIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool InTraining()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InTraining");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetFamilyInfoFromId(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetFamilyInfoFromId");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		class TrDevice* GetDeviceByEquipPoint(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetDeviceByEquipPoint");
			byte* params = (byte*)malloc(5);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDevice**)(params + 4);
			free(params);
			return returnVal;
		}
		byte GetZoomedState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetZoomedState");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool InRovingSpectate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.InRovingSpectate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsTrPlayerMuted(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsTrPlayerMuted");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetActiveClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetActiveClassId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetTeamClassCount(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetTeamClassCount");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RegisterPendingClass(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RegisterPendingClass");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetAllowedClassCount(byte ClassType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAllowedClassCount");
			byte* params = (byte*)malloc(5);
			*params = ClassType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SendPrivateChatMessage(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendPrivateChatMessage");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool BroadcastChatMessage(byte Channel, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BroadcastChatMessage");
			byte* params = (byte*)malloc(17);
			*params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool ServerRequestPickTeam(byte RequestedTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestPickTeam");
			byte* params = (byte*)malloc(5);
			*params = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ChooseBloodEagle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChooseBloodEagle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ChooseDiamondSword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChooseDiamondSword");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetVehicleCost(ScriptClass* VehicleClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetVehicleCost");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetCurrentCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCurrentCredits");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool IsBassBoostToggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsBassBoostToggled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool AllowHelpTextToDisplay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AllowHelpTextToDisplay");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool NeedToVisitInventoryStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NeedToVisitInventoryStation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float GetCurrentDetermination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCurrentDetermination");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetNewPlayerAssistToApply()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetNewPlayerAssistToApply");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void PlayReliableSound(class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Vector SoundLocation, bool bNoRepToRelevant)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayReliableSound");
			byte* params = (byte*)malloc(32);
			*(class SoundCue**)params = InSoundCue;
			*(bool*)(params + 4) = bNotReplicated;
			*(bool*)(params + 8) = bNoRepToOwner;
			*(bool*)(params + 12) = bStopWhenOwnerDestroyed;
			*(Vector*)(params + 16) = SoundLocation;
			*(bool*)(params + 28) = bNoRepToRelevant;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendCtrlRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendCtrlRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendGameRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SendGameRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TestSteamPurchase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestSteamPurchase");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowAdminPage(ScriptArray<wchar_t> ServerURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowAdminPage");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ServerURL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHitValidationMode(int loggingMode, int validationMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetHitValidationMode");
			byte* params = (byte*)malloc(8);
			*(int*)params = loggingMode;
			*(int*)(params + 4) = validationMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KickPlayerFromMatch(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.KickPlayerFromMatch");
			byte* params = (byte*)malloc(4);
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool MainMenuIsOpen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MainMenuIsOpen");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVote;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMenuMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetMenuMatchCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetUserSelectedClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetUserSelectedClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndHotkeyBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EndHotkeyBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MutePlayer(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.MutePlayer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnmutePlayer(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UnmutePlayer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HaveMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HaveMenu");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsChatFiltered(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsChatFiltered");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void RequestKickVote(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RequestKickVote");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ClaimPromotion(ScriptArray<wchar_t> PromoCode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClaimPromotion");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PromoCode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForwardChatFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ForwardChatFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowNotification(ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Message2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowNotification");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Message;
			*(ScriptArray<wchar_t>*)(params + 12) = Message2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChatMessageReceived");
			byte* params = (byte*)malloc(28);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Sender;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void PushChat(ScriptArray<wchar_t> chatStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PushChat");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = chatStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVehicleMenuOption(ScriptArray<wchar_t> ClassName, ScriptArray<wchar_t> DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddVehicleMenuOption");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(ScriptArray<wchar_t>*)(params + 12) = DisplayName;
			*(int*)(params + 24) = Cost;
			*(int*)(params + 28) = Icon;
			*(int*)(params + 32) = CountSpawned;
			*(int*)(params + 36) = CountAllowed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetOnlineFriends(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& vFriends)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetOnlineFriends");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = vFriends;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			vFriends = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = AnnouncementCue;
			*(bool*)(params + 4) = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TestAnnouncement(bool bPlayRightNow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestAnnouncement");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientHearReliableSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientHearReliableSound");
			byte* params = (byte*)malloc(28);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(Vector*)(params + 8) = SourceLocation;
			*(bool*)(params + 20) = bStopWhenOwnerDestroyed;
			*(bool*)(params + 24) = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientMySaberLauncherTargetingUpdated(byte MissileLockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientMySaberLauncherTargetingUpdated");
			byte* params = (byte*)malloc(1);
			*params = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSeekingMissileTargetingSelfEvent(int EventSwitch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSeekingMissileTargetingSelfEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = EventSwitch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnMissileIntercepted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnMissileIntercepted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUDNotification(ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Message2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowHUDNotification");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Message;
			*(ScriptArray<wchar_t>*)(params + 12) = Message2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideHUDNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideHUDNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckBulletWhip(class SoundCue* BulletWhip, Vector FireLocation, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckBulletWhip");
			byte* params = (byte*)malloc(40);
			*(class SoundCue**)params = BulletWhip;
			*(Vector*)(params + 4) = FireLocation;
			*(Vector*)(params + 16) = FireDir;
			*(Vector*)(params + 28) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessCreditEvent(byte EventType, bool bProxyEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ProcessCreditEvent");
			byte* params = (byte*)malloc(5);
			*params = EventType;
			*(bool*)(params + 4) = bProxyEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyCredits(int Count, bool bFreeCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ModifyCredits");
			byte* params = (byte*)malloc(8);
			*(int*)params = Count;
			*(bool*)(params + 4) = bFreeCredits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCurrentCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateCurrentCredits");
			byte* params = (byte*)malloc(4);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreditsSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CreditsSoundFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientUpdateCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientUpdateCredits");
			byte* params = (byte*)malloc(4);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetLatestAccoladeIconIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLatestAccoladeIconIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ClientShowAccoladeIcon(int IconIndex, ScriptArray<wchar_t> Description, ScriptArray<wchar_t> Points)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowAccoladeIcon");
			byte* params = (byte*)malloc(28);
			*(int*)params = IconIndex;
			*(ScriptArray<wchar_t>*)(params + 4) = Description;
			*(ScriptArray<wchar_t>*)(params + 16) = Points;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientShowAccoladeText(ScriptArray<wchar_t> Message, int ShowTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowAccoladeText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Message;
			*(int*)(params + 12) = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetStreaks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ResetStreaks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GiveCredits");
			byte* params = (byte*)malloc(4);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerGiveCreditsCheat(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerGiveCreditsCheat");
			byte* params = (byte*)malloc(4);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AimingHelp");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyChangedWeapon");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = PreviousWeapon;
			*(class Weapon**)(params + 4) = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ServerSetCharFamily(ScriptArray<wchar_t> FamilyClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetCharFamily");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = FamilyClassStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		byte GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetArmorType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		float GetRespawnDelayTotalTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetRespawnDelayTotalTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Rotator LimitViewRotation(Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LimitViewRotation");
			byte* params = (byte*)malloc(32);
			*(Rotator*)params = ViewRotation;
			*(float*)(params + 12) = ViewPitchMin;
			*(float*)(params + 16) = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 20);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PressedConsoleUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedConsoleUse");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PressedWeaponSwitch(bool bFilterTimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedWeaponSwitch");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFilterTimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ActivateDevice(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ActivateDevice");
			byte* params = (byte*)malloc(1);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateLockedTarget(class Actor* LockedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateLockedTarget");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = LockedActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IdentifyTeamMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IdentifyTeamMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStartupMessage(byte StartupStage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayStartupMessage");
			byte* params = (byte*)malloc(1);
			*params = StartupStage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = RequestedTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeTeam(ScriptArray<wchar_t> TeamName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChangeTeam");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ViewAPlayer(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ViewAPlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerPlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerPlayerTick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayerTick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = W;
			*(Vector*)(params + 4) = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)(params + 4) = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeftWeatherVolume(bool bDeactivatePawnCentricWeather, class TrWeatherVolume* WeatherVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PawnLeftWeatherVolume");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDeactivatePawnCentricWeather;
			*(class TrWeatherVolume**)(params + 4) = WeatherVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnabled;
			*(bool*)(params + 4) = bJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableJetpack(bool bEnabled, bool bJump, bool bForcedOff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableJetpack");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bEnabled;
			*(bool*)(params + 4) = bJump;
			*(bool*)(params + 8) = bForcedOff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IgnoreMoveInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void GetBlinkPackAccel(Vector& newAccel, float& BlinkPackPctEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetBlinkPackAccel");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = newAccel;
			*(float*)(params + 12) = BlinkPackPctEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			newAccel = *(Vector*)params;
			BlinkPackPctEffectiveness = *(float*)(params + 12);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RefreshHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetAirVehicleInversion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetAirVehicleInversion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerSetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetAirVehicleControls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAirVehicleControls(bool bInvert)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetAirVehicleControls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInvert;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsInVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsInVehicle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClientVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientVehiclePhysUpdated");
			byte* params = (byte*)malloc(4);
			*(class TrVehicle**)params = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerVehiclePhysUpdated(class TrVehicle* InVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerVehiclePhysUpdated");
			byte* params = (byte*)malloc(4);
			*(class TrVehicle**)params = InVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerVerifyVehiclePhys(float TimeStamp, float InForward, float InStrafe, float InUp, int View, RigidBodyState InRBState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerVerifyVehiclePhys");
			byte* params = (byte*)malloc(84);
			*(float*)params = TimeStamp;
			*(float*)(params + 4) = InForward;
			*(float*)(params + 8) = InStrafe;
			*(float*)(params + 12) = InUp;
			*(int*)(params + 16) = View;
			*(RigidBodyState*)(params + 32) = InRBState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerCorrectClientPhys(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerCorrectClientPhys");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerToggleVehicleJets");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleVehicleJets(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleVehicleJets");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessRiding(Rotator ViewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ProcessRiding");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRiding(float TimeStamp, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRiding");
			byte* params = (byte*)malloc(8);
			*(float*)params = TimeStamp;
			*(int*)(params + 4) = View;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToCallIn(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToCallIn");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRequestCallInChange(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestCallInChange");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToSeat(byte T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToSeat");
			byte* params = (byte*)malloc(1);
			*params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSwitchToSeat(byte T, class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSwitchToSeat");
			byte* params = (byte*)malloc(5);
			*params = T;
			*(class TrVehicle**)(params + 4) = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TriggerInteracted");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerRequestLoadoutChange(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestLoadoutChange");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePaperDoll(ScriptClass* FamilyInfo, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePaperDoll");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = FamilyInfo;
			*(ScriptClass**)(params + 4) = DeviceClass;
			*(ScriptClass**)(params + 8) = skinClass;
			*(int*)(params + 12) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePaperDoll_Device(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePaperDoll_Device");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpawnVehicle(ScriptArray<wchar_t> vehicleClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpawnVehicle");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RequestBuyVehicle(ScriptArray<wchar_t> vehicleClassStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.RequestBuyVehicle");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = vehicleClassStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PressedSki(bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PressedSki");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = method;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleShowObjectMarkers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ToggleShowObjectMarkers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerStartSki(bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerStartSki");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerStopSki()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerStopSki");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetHUD");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnKickback(Rotator KickbackAim, float KickbackBlendOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnKickback");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = KickbackAim;
			*(float*)(params + 12) = KickbackBlendOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateKickbackDirection(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateKickbackDirection");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = VehicleClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PerformedUseAction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayRechargeSoundOnWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetZoom(byte NewZoomState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetZoom");
			byte* params = (byte*)malloc(1);
			*params = NewZoomState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReceiveLocalizedMessage");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = Message;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveLocalizedNagMessage(ScriptClass* Message, int Switch, float Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReceiveLocalizedNagMessage");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = Message;
			*(int*)(params + 4) = Switch;
			*(float*)(params + 8) = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TrClientMusicEvent(int EventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TrClientMusicEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = EventIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientRestart");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateClientSpawnTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateClientSpawnTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GameHasEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckJumpOrDuck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientGameEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerDropFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerDropFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& POVLocation, Rotator& POVRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = POVLocation;
			*(Rotator*)(params + 12) = POVRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			POVLocation = *(Vector*)params;
			POVRotation = *(Rotator*)(params + 12);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayCameraShake(ScriptName ShakeName, float Scale, class CameraShake* SourceShake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.PlayCameraShake");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ShakeName;
			*(float*)(params + 8) = Scale;
			*(class CameraShake**)(params + 12) = SourceShake;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayForceFeedbackWaveform");
			byte* params = (byte*)malloc(8);
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			*(class Actor**)(params + 4) = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSpeedCameraEffect(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateSpeedCameraEffect");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpeedCamEffect(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SpeedCamEffect");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPulseHUD(byte Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPulseHUD");
			byte* params = (byte*)malloc(1);
			*params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void TalkVGS(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TalkVGS");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Say(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Say");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsPlayerCommand(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsPlayerCommand");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void ShowFeedbackMessage(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowFeedbackMessage");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Color GetChatColor(byte Channel, bool bSameTeam, int& ChatColorIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetChatColor");
			byte* params = (byte*)malloc(13);
			*params = Channel;
			*(bool*)(params + 4) = bSameTeam;
			*(int*)(params + 8) = ChatColorIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ChatColorIdx = *(int*)(params + 8);
			auto returnVal = *(Color*)(params + 12);
			free(params);
			return returnVal;
		}
		void AddChatToConsole(ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> ChatMessage, byte Channel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddChatToConsole");
			byte* params = (byte*)malloc(25);
			*(ScriptArray<wchar_t>*)params = Sender;
			*(ScriptArray<wchar_t>*)(params + 12) = ChatMessage;
			*(params + 24) = Channel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetLastTellSender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetLastTellSender");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ReplyTalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ReplyTalk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CanCommunicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Talk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Talk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatConsole(bool bTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ChatConsole");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TalkConsole(bool bTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TalkConsole");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamTalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TeamTalk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TeamSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTextMessage(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AllowTextMessage");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
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
		void ServerRequestVGSContextCommand(byte ContextActor, byte ContextLocation, bool bEnemyLocation, class Actor* SpottedActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestVGSContextCommand");
			byte* params = (byte*)malloc(10);
			*params = ContextActor;
			*(params + 1) = ContextLocation;
			*(bool*)(params + 4) = bEnemyLocation;
			*(class Actor**)(params + 8) = SpottedActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRequestVGSCommand(byte VGSCommandIndex, bool bGlobal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerRequestVGSCommand");
			byte* params = (byte*)malloc(5);
			*params = VGSCommandIndex;
			*(bool*)(params + 4) = bGlobal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveVGSCommand(class PlayerReplicationInfo* PRI, byte VGSCommandIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientReceiveVGSCommand");
			byte* params = (byte*)malloc(5);
			*(class PlayerReplicationInfo**)params = PRI;
			*(params + 4) = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReceiveVGSContextCommand(class PlayerReplicationInfo* PRI, byte ContextActor, byte ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientReceiveVGSContextCommand");
			byte* params = (byte*)malloc(10);
			*(class PlayerReplicationInfo**)params = PRI;
			*(params + 4) = ContextActor;
			*(params + 5) = ContextLocation;
			*(bool*)(params + 8) = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowMoveErrors(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowMoveErrors");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void UpdateNewPlayerAssistPoints(int AmoutToSubtract)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateNewPlayerAssistPoints");
			byte* params = (byte*)malloc(4);
			*(int*)params = AmoutToSubtract;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BehindView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.BehindView");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetBehindView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetBehindView(bool bNewBehindView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetBehindView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewBehindView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PlayerInput* GetEngineSettings(bool bUse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetEngineSettings");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerInput**)(params + 4);
			free(params);
			return returnVal;
		}
		class TrPlayerInput_Spectator* GetSpectatorSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetSpectatorSettings");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrPlayerInput_Spectator**)params;
			free(params);
			return returnVal;
		}
		void ClientOnMotionSensorAlarmSounded(class TrDeployable_MotionSensor* MotionSensor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnMotionSensorAlarmSounded");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable_MotionSensor**)params = MotionSensor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientOnMotionSensorMineSounded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnMotionSensorMineSounded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadPendingLoadoutContentData(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadPendingLoadoutContentData");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadPendingDeviceContentData(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadPendingDeviceContentData");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideHUDElements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.HideHUDElements");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientShowFlagIcon(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowFlagIcon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetPlayerClassObjects(ScriptArray<wchar_t> ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetPlayerClassObjects");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(int*)(params + 12) = PerkIcon1;
			*(int*)(params + 16) = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePotentialSeekingTargets(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* NewPotentialTargets)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdatePotentialSeekingTargets");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = NewPotentialTargets;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyHitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.NotifyFallingHitWall");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Spectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.Spectate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndSpectate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EndSpectate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSpectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSpectate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSpectate(bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSpectate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewFlags(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFlags");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewFlagStands(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFlagStands");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewGenerators(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewGenerators");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewBookmark(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewBookmark");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewVehicles(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewVehicles");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewFastestPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewFastestPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewActor(class Actor* ActorToView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerViewActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = ActorToView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientOnViewTargetChange(class Actor* NewViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientOnViewTargetChange");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerIncreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerIncreaseCamDistance");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerDecreaseCamDistance(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerDecreaseCamDistance");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetMoveSpeed(float NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetMoveSpeed");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewTargetCapturedFlag(class TrFlagCTF* NewFlagToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetCapturedFlag");
			byte* params = (byte*)malloc(4);
			*(class TrFlagCTF**)params = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewTargetFlagReturned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetFlagReturned");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewTargetDroppedFlag(class TrFlagBase* NewFlagToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetDroppedFlag");
			byte* params = (byte*)malloc(4);
			*(class TrFlagBase**)params = NewFlagToWatch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewTargetLeftVehicle(class PlayerReplicationInfo* NewPRIToWatch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnViewTargetLeftVehicle");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = NewPRIToWatch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetViewTargetList(class TrPawn*& PawnViewTarget, class TrVehicle*& VehicleViewTarget, class TrCamera_SpectatorBookmark*& BookmarkViewTarget, class Actor*& ObjectiveViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetViewTargetList");
			byte* params = (byte*)malloc(16);
			*(class TrPawn**)params = PawnViewTarget;
			*(class TrVehicle**)(params + 4) = VehicleViewTarget;
			*(class TrCamera_SpectatorBookmark**)(params + 8) = BookmarkViewTarget;
			*(class Actor**)(params + 12) = ObjectiveViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PawnViewTarget = *(class TrPawn**)params;
			VehicleViewTarget = *(class TrVehicle**)(params + 4);
			BookmarkViewTarget = *(class TrCamera_SpectatorBookmark**)(params + 8);
			ObjectiveViewTarget = *(class Actor**)(params + 12);
			free(params);
		}
		void ServerUnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerUnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayTakeHit(Vector HitLoc, byte Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayTakeHit");
			byte* params = (byte*)malloc(17);
			*(Vector*)params = HitLoc;
			*(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ClientMatchOver(int Winner, ScriptArray<wchar_t> WinnerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientMatchOver");
			byte* params = (byte*)malloc(16);
			*(int*)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = WinnerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRoundCountdown(int Seconds, int Round)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateRoundCountdown");
			byte* params = (byte*)malloc(8);
			*(int*)params = Seconds;
			*(int*)(params + 4) = Round;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateGameCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerKickPlayer(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerKickPlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientKickPlayer(int Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientKickPlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void CalcCameraOnViewTarget(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CalcCameraOnViewTarget");
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
		bool IsGameTypeArena()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeArena");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsGameTypeDaD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeDaD");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsGameTypeCaH()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.IsGameTypeCaH");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SwitchToDeathCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SwitchToDeathCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddProjectileToTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddProjectileToTetherList");
			byte* params = (byte*)malloc(4);
			*(class TrProjectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckTetherList(class TrProjectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CheckTetherList");
			byte* params = (byte*)malloc(4);
			*(class TrProjectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrProjectile* TetherProjectile(class TrProjectile* ProjectileFromServer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TetherProjectile");
			byte* params = (byte*)malloc(8);
			*(class TrProjectile**)params = ProjectileFromServer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrProjectile**)(params + 4);
			free(params);
			return returnVal;
		}
		void ConfigureSkiSpeedSteps(float SoftCap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ConfigureSkiSpeedSteps");
			byte* params = (byte*)malloc(4);
			*(float*)params = SoftCap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.LoadingTimer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = ASound;
			*(class PlayerReplicationInfo**)(params + 4) = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VGSAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.VGSAudioFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetLastDamagerInfo(int Health, int UpgradeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientSetLastDamagerInfo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Health;
			*(int*)(params + 4) = UpgradeLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableTinyWeapons(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableTinyWeapons");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetTinyWeaponValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void EnableChatFilter(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableChatFilter");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetChatFilterValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void EnableDamageCounter(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableDamageCounter");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetDamageCounterValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void EnableHUDObjectives(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDObjectives");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDReticule(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDReticule");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDCredits(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCredits");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDAccolades(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDAccolades");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDBadges(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDBadges");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDScores(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDScores");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDHealthBar(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDHealthBar");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDVisor(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDVisor");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDChat(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDChat");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDCombatLog(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCombatLog");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDKillbox(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDKillbox");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDDeathcam(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDDeathcam");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDHeroText(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDHeroText");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDPromptPanel(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDPromptPanel");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDRespawnTimer(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDRespawnTimer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDSkiBars(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDSkiBars");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDFriendColoring(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDFriendColoring");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDNotifications(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDNotifications");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDFriendStateNotifications(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDFriendStateNotifications");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableHUDCracks(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.EnableHUDCracks");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowAlienFX(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ShowAlienFX");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDObjectivesValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool GetHUDNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDNotifications");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetHUDFriendStateNotifications");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetWhisperFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetWhisperFilterValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetWhisperFilter(int FilterValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetWhisperFilter");
			byte* params = (byte*)malloc(4);
			*(int*)params = FilterValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SummaryTweenTimer(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SummaryTweenTimer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(12);
			*(int*)params = DamageAmount;
			*(bool*)(params + 4) = isInstantHit;
			*(int*)(params + 8) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerShowOverheadNumber(int NumberToShow, Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerShowOverheadNumber");
			byte* params = (byte*)malloc(20);
			*(int*)params = NumberToShow;
			*(Vector*)(params + 4) = WorldLocation;
			*(float*)(params + 16) = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientShowOverheadNumber(int NumberToShow, Vector WorldLocation, float fScreenDepth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientShowOverheadNumber");
			byte* params = (byte*)malloc(20);
			*(int*)params = NumberToShow;
			*(Vector*)(params + 4) = WorldLocation;
			*(float*)(params + 16) = fScreenDepth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetCreditsForDamageAmount(int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetCreditsForDamageAmount");
			byte* params = (byte*)malloc(8);
			*(int*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void CashForDamage(int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.CashForDamage");
			byte* params = (byte*)malloc(4);
			*(int*)params = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AwardTeamAssistCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AwardTeamAssistCredits");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AwardTeamRabbitAssistCredits(int Multiplier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AwardTeamRabbitAssistCredits");
			byte* params = (byte*)malloc(4);
			*(int*)params = Multiplier;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TypeKeyPressed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TypeKeyPressed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FixFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.FixFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetClassAffordable(int BitMask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetClassAffordable");
			byte* params = (byte*)malloc(4);
			*(int*)params = BitMask;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetClassBit(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.GetClassBit");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void TestTrainingSlot(byte equipType, int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestTrainingSlot");
			byte* params = (byte*)malloc(5);
			*params = equipType;
			*(int*)(params + 4) = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TestSlot(byte equipType, int EquipId, bool bTraining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.TestSlot");
			byte* params = (byte*)malloc(9);
			*params = equipType;
			*(int*)(params + 4) = EquipId;
			*(bool*)(params + 8) = bTraining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerTestSlot(byte EquipId, int EquipItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerTestSlot");
			byte* params = (byte*)malloc(5);
			*params = EquipId;
			*(int*)(params + 4) = EquipItem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnDeviceContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.On3PSkinContentLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void On1PSkinContentLoaded(ScriptClass* Skin1PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.On1PSkinContentLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin1PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddPending3PSkin(class TrPlayerReplicationInfo* TrPRI, int skinId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.AddPending3PSkin");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerReplicationInfo**)params = TrPRI;
			*(int*)(params + 4) = skinId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnClassSelectedMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnClassSelectedMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnGiveCredits(class TrSeqAct_GiveCredits* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnGiveCredits");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_GiveCredits**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGiveAccolade(class TrSeqAct_GiveAccolade* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnGiveAccolade");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_GiveAccolade**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayVGSCommand(class TrSeqAct_PlayVGSCommand* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnPlayVGSCommand");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_PlayVGSCommand**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRefreshInventory(class TrSeqAct_RefreshInventory* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnRefreshInventory");
			byte* params = (byte*)malloc(4);
			*(class TrSeqAct_RefreshInventory**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = WinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayerResettingAndRespawning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientPlayerResettingAndRespawning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyAllOwnedDeployables(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedDeployables");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyAllOwnedMines(ScriptClass* DestroyIfNotOfType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedMines");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DestroyIfNotOfType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyAllOwnedProjectiles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.DestroyAllOwnedProjectiles");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QueueBadge(int Icon, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> XPReward)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.QueueBadge");
			byte* params = (byte*)malloc(28);
			*(int*)params = Icon;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = XPReward;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientQueueAccolade(int Icon, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Subtitle, bool bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ClientQueueAccolade");
			byte* params = (byte*)malloc(32);
			*(int*)params = Icon;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Subtitle;
			*(bool*)(params + 28) = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class TrVehicleStation**)params = VehicleStation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnScoreChanged(class UTTeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.OnScoreChanged");
			byte* params = (byte*)malloc(4);
			*(class UTTeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void UpdateMainMenuPaperDoll_Mesh(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.UpdateMainMenuPaperDoll_Mesh");
			byte* params = (byte*)malloc(1);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = VoiceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> StripTag(ScriptArray<wchar_t> sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.StripTag");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.SetAllowSimProjectiles");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetAllowSimProjectiles(bool bAllow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerController.ServerSetAllowSimProjectiles");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAllow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
