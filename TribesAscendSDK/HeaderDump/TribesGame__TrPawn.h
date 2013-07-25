#pragma once
#include "UTGame__UTWeaponAttachment.h"
#include "UDKBase__UDKCarriedObject.h"
#include "UTGame__UTPawn.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrStatsInterface.h"
#include "TribesGame__TrAnimNodeBlendByRidingPassenger.h"
#include "TribesGame__TrAnimNodeAimOffset.h"
#include "TribesGame__TrProjectile.h"
#include "Engine__Weapon.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Material.h"
#include "TribesGame__TrPlayerReplicationInfo.h"
#include "TribesGame__TrPawnCollisionProxy.h"
#include "Engine__PlayerController.h"
#include "Engine__MorphNodeWeight.h"
#include "TribesGame__TrAnimNodeBlendByVehicle.h"
#include "Engine__Actor.h"
#include "TribesGame__TrHUD.h"
#include "TribesGame__TrValueModifier.h"
#include "Engine__MaterialInterface.h"
#include "Engine__Canvas.h"
#include "Engine__Controller.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__HUD.h"
#include "Engine__Vehicle.h"
#include "Engine__SVehicle.h"
#include "Engine__Pawn.h"
#include "TribesGame__TrDeployable_DropJammer.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPawn : public UTPawn
	{
	public:
		ADD_OBJECT(TrVehicle, m_RidingVehicle)
		ADD_VAR(::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHeadShotDamageMultiple, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnViewForwardAmount, 0xFFFFFFFF)
		ADD_OBJECT(TrAnimNodeBlendByRidingPassenger, m_RidingPassengerBlendNode)
		ADD_OBJECT(TrAnimNodeAimOffset, m_AimOffsetNode)
		ADD_OBJECT(TrAnimNodeAimOffset, m_1pBodyAimOffsetNode)
		ADD_STRUCT(::VectorProperty, r_FlashNormal, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fShowObjectThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsStealthed, 0x4)
		ADD_VAR(::BoolProperty, r_bIsInvulnerable, 0x100000)
		ADD_VAR(::BoolProperty, r_bIsSkiing, 0x800)
		ADD_VAR(::BoolProperty, r_bIsJetting, 0x8000)
		ADD_VAR(::FloatProperty, m_TerrainWalkableFloorZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSwapSkinDistSq, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, c_Pending1PSkin)
		ADD_OBJECT(ScriptClass, c_Pending3PSkin)
		ADD_VAR(::IntProperty, m_nNetViewPitchCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_PitchInterpRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTargetRemoteViewPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPreviousReceivedRemoteViewPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nSmoothedRemoteViewPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNetRotationCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_RotationInterpRate, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_TargetNetReceiveRotation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, m_PreviousNetReceiveRotation, 0xFFFFFFFF
		ADD_OBJECT(SkeletalMesh, m_GibMesh)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::FloatProperty, m_fInventoryStationLockoutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastInventoryStationVisitTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF)
		ADD_OBJECT(UDKCarriedObject, m_GameObjCheckTimer)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC)
		ADD_OBJECT(UTWeaponAttachment, m_InHandWeaponAttachmentFromAutoFire)
		ADD_VAR(::FloatProperty, m_fLastTakeClotheslineDamageTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClotheslineSpeedDifferenceMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClotheslineSpeedDifferenceMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClotheslineDamageMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClotheslineDamageMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatSpeedMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatSpeedMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatDamageFromWallMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatDamageFromWallMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatDamageFromLandMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatDamageFromLandMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_bJustLandedSpeedSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fGroundSkiEffectDist, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_InvulnerableOverlayMIC)
		ADD_OBJECT(Material, m_InvulnerableOverlayMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_RageOverlayMIC)
		ADD_OBJECT(Material, m_RageOverlayMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_JammerPackOverlayMIC)
		ADD_OBJECT(Material, m_JammerPackOverlayMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_RegenPackPackOverlayMIC)
		ADD_OBJECT(Material, m_RegenPackOverlayMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_RegenOverlayMIC)
		ADD_OBJECT(Material, m_RegenOverlayMaterial)
		ADD_VAR(::FloatProperty, m_fShieldPackMaterialHitRampDownSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverlayMaterialDeactivateSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverlayMaterialActivateSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldPackOverlayMIC)
		ADD_OBJECT(Material, m_ShieldPackOverlayMaterial)
		ADD_VAR(::FloatProperty, m_fForwardJettingPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxJetpackBoostGroundspeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nEnemyDropJammerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nFriendlyDropJammerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nEnemyJamCount, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerReplicationInfo, r_FriendJammingPRI)
		ADD_VAR(::IntProperty, m_JammingFriendTeam, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJamEffectRadius, 0xFFFFFFFF)
		ADD_OBJECT(TrPawnCollisionProxy, m_JammingCollisionProxy)
		ADD_OBJECT(Material, r_ReplicatedWeaponAttachmentMat)
		ADD_VAR(::FloatProperty, m_OldSpeed, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_avMultiShotLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fEnemyShowDistanceThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFriendlyShowDistanceThreshold, 0xFFFFFFFF)
		ADD_OBJECT(MorphNodeWeight, m_OverlayMorphNode)
		ADD_OBJECT(TrAnimNodeBlendByVehicle, m_VehicleBlendNode)
		ADD_VAR(::FloatProperty, m_fFallVelocityTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastDamagerTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastVehicleDamagerTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_AssistDamagePercentQualifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiAccelPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiAccelCapSpeedThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAirAccelSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAirAccelCapSpeedThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTerminalSkiSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSkiSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiSlopeGravityBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSkiControlPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiControlSigmaSquare, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPeakSkiControlSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.TrTakeEffectInfo' for the property named 'r_LastTakeEffectInfo'!
		ADD_VAR(::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.TR_HUD_INFO' for the property named 'm_HudInfo'!
		ADD_VAR(::IntProperty, r_nSensorAlertLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDecelerationRateWithFlag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSpeedWithFlag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPreserveVelocityZNormalThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPreserveVelocityThresholdMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPreserveVelocityThresholdMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSpeedDecelerationRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTerminalJettingSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxJettingSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAccelRateAtMaxThrustSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxJetpackThrustSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxStoppingDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStoppingDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHeadShotFudge, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTickedRegenDecimal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSecondsBeforeAutoHeal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fPowerPoolRechargeRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeLastUntargetByLocalPlayer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeLastTargetByLocalPlayer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeLastUnseenByLocalPlayer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeLastSeenByLocalPlayer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, s_fVE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldMultiple, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fFasterWeaponSwitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseStealthIgnoreTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseStealthIgnoreTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fPulseStealthSpeedThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseStealthFadeInInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseStealthVisibleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPulseStealthVisibleTimestamp, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_StealthMIC)
		ADD_OBJECT(Material, m_StealthMaterial)
		ADD_VAR(::FloatProperty, m_fMinStealthVisibilityParamValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDisableStealthVisibilityInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fEnableStealthVisibilityInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LastFXOverlay, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nWhiteOut, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_RemoteViewYaw, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PhysType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nFactionId, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nBlinked, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nPulseStealth, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_MissileLock, 0xFFFFFFFF)
		ADD_OBJECT(Actor, r_LockedTarget)
		ADD_VAR(::BoolProperty, m_bUseSmoothNetReceiveRotation, 0x1000000)
		ADD_VAR(::BoolProperty, r_bDetectedByEnemyScanner, 0x800000)
		ADD_VAR(::BoolProperty, m_bSplattedAgainstWall, 0x400000)
		ADD_VAR(::BoolProperty, m_bIsInConduit, 0x200000)
		ADD_VAR(::BoolProperty, m_bUpdateStickyGrenades, 0x80000)
		ADD_VAR(::BoolProperty, m_bLoadoutReset, 0x40000)
		ADD_VAR(::BoolProperty, r_bIsJamming, 0x20000)
		ADD_VAR(::BoolProperty, m_bIsJetEffectsPlaying, 0x10000)
		ADD_VAR(::BoolProperty, r_bAimingMode, 0x4000)
		ADD_VAR(::BoolProperty, m_bIsPlayingSkiEffectsSounds, 0x2000)
		ADD_VAR(::BoolProperty, m_bIsPlayingSkiEffects, 0x1000)
		ADD_VAR(::BoolProperty, bInDeployModeClient, 0x400)
		ADD_VAR(::BoolProperty, r_bInDeployMode, 0x200)
		ADD_VAR(::BoolProperty, bInFireLockClient, 0x100)
		ADD_VAR(::BoolProperty, r_bInFireLock, 0x80)
		ADD_VAR(::BoolProperty, r_bIsHealthRecharging, 0x40)
		ADD_VAR(::BoolProperty, r_bIsShielded, 0x20)
		ADD_VAR(::BoolProperty, r_bIsRaged, 0x10)
		ADD_VAR(::BoolProperty, m_bStealthVisible, 0x8)
		ADD_VAR(::BoolProperty, m_bRefreshInventoryWasRespawn, 0x2)
		ADD_VAR(::BoolProperty, m_bInitialized, 0x1)
		ADD_VAR(::NameProperty, m_nmMakeVisible, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetCurrentPowerPool'
		// Here lies the not-yet-implemented method 'GetMaxPowerPool'
		// Here lies the not-yet-implemented method 'CalculatePawnSpeed'
		// Here lies the not-yet-implemented method 'GetCurrCharClassInfo'
		// Here lies the not-yet-implemented method 'IsFirstPerson'
		// Here lies the not-yet-implemented method 'GetHandsMesh'
		// Here lies the not-yet-implemented method 'GetTribesReplicationInfo'
		// Here lies the not-yet-implemented method 'CheckHeadShot'
		// Here lies the not-yet-implemented method 'GetPawnViewLocation'
		// Here lies the not-yet-implemented method 'GetTrHud'
		// Here lies the not-yet-implemented method 'IsPulseStealthed'
		// Here lies the not-yet-implemented method 'IsJammedByFriendOrSelf'
		// Here lies the not-yet-implemented method 'CheckGrabSpeed'
		// Here lies the not-yet-implemented method 'NativeGetCollisionHeight'
		// Here lies the not-yet-implemented method 'NativeGetCollisionRadius'
		// Here lies the not-yet-implemented method 'SyncClientCurrentPowerPool'
		// Here lies the not-yet-implemented method 'ConsumePowerPool'
		// Here lies the not-yet-implemented method 'RegainPowerPool'
		// Here lies the not-yet-implemented method 'GetPowerPoolPercent'
		// Here lies the not-yet-implemented method 'GetCurrentDeviceAccuracyInfo'
		// Here lies the not-yet-implemented method 'SetOverlayMaterial'
		// Here lies the not-yet-implemented method 'ServerUpdateLockedTarget'
		// Here lies the not-yet-implemented method 'NativePostRenderFor'
		// Here lies the not-yet-implemented method 'GetTargetLocation'
		// Here lies the not-yet-implemented method 'SetFlashNormal'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'GetCurrentCredits'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'CurrentDeployedCount'
		// Here lies the not-yet-implemented method 'ExitDeployMode'
		// Here lies the not-yet-implemented method 'GetArmorType'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ReplicateMultiFlashLocation'
		// Here lies the not-yet-implemented method 'EquipBestPossibleDevice'
		// Here lies the not-yet-implemented method 'InitDefaultAnims'
		// Here lies the not-yet-implemented method 'SetCharacterClassFromInfo'
		// Here lies the not-yet-implemented method 'ActivatePendingClass'
		// Here lies the not-yet-implemented method 'RefreshInventoryTimer'
		// Here lies the not-yet-implemented method 'SetValuesFromCurrentFamilyInfo'
		// Here lies the not-yet-implemented method 'RefreshInventory'
		// Here lies the not-yet-implemented method 'ActivateSelectedDeployable'
		// Here lies the not-yet-implemented method 'RemoveEffectByClass'
		// Here lies the not-yet-implemented method 'ProcessEffectForm'
		// Here lies the not-yet-implemented method 'GetShieldStrength'
		// Here lies the not-yet-implemented method 'AdjustAmmoPool'
		// Here lies the not-yet-implemented method 'AdjustMaxPowerPool'
		// Here lies the not-yet-implemented method 'SetMaxPowerPool'
		// Here lies the not-yet-implemented method 'SetMaxHealthPool'
		// Here lies the not-yet-implemented method 'ClientUpdateHUDHealth'
		// Here lies the not-yet-implemented method 'ShouldRechargePowerPool'
		// Here lies the not-yet-implemented method 'ForceHealthRegen'
		// Here lies the not-yet-implemented method 'RechargeHealthPool'
		// Here lies the not-yet-implemented method 'GetJetpackAirControl'
		// Here lies the not-yet-implemented method 'UpdateSkiEffects'
		// Here lies the not-yet-implemented method 'PlayJetpackEffects'
		// Here lies the not-yet-implemented method 'UpdateJetpackEffects'
		// Here lies the not-yet-implemented method 'StopJetpackEffects'
		// Here lies the not-yet-implemented method 'PlayLandingSound'
		// Here lies the not-yet-implemented method 'PlayJumpingSound'
		// Here lies the not-yet-implemented method 'RememberLastDamager'
		// Here lies the not-yet-implemented method 'GetHealthPct'
		// Here lies the not-yet-implemented method 'CreateAssistRecord'
		// Here lies the not-yet-implemented method 'GetLastDamager'
		// Here lies the not-yet-implemented method 'ProcessKillAssists'
		// Here lies the not-yet-implemented method 'GetUnshieldedDamage'
		// Here lies the not-yet-implemented method 'GetPawnCausingDamage'
		// Here lies the not-yet-implemented method 'GetDamageScale'
		// Here lies the not-yet-implemented method 'DoRepairs'
		// Here lies the not-yet-implemented method 'CheckTribesTurretInstigator'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'PlayWhiteoutEffect'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'RecentlyGrabbedFlag'
		// Here lies the not-yet-implemented method 'GetShowDistanceThreshold'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'TakeFallingDamage'
		// Here lies the not-yet-implemented method 'PlayHardLandingEffect'
		// Here lies the not-yet-implemented method 'PlaySonicPunchEffect'
		// Here lies the not-yet-implemented method 'TakeFallDamage'
		// Here lies the not-yet-implemented method 'ProcessCreditEvent'
		// Here lies the not-yet-implemented method 'FlashLocationUpdated'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'Dodge'
		// Here lies the not-yet-implemented method 'PerformDodge'
		// Here lies the not-yet-implemented method 'gibbedBy'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'ShouldGib'
		// Here lies the not-yet-implemented method 'SetHandIKEnabled'
		// Here lies the not-yet-implemented method 'PlayDamageCameraShake'
		// Here lies the not-yet-implemented method 'IsLastHitFromNinjaSmoke'
		// Here lies the not-yet-implemented method 'PlayTakeHitEffects'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'StopLocalEffectsAndSounds'
		// Here lies the not-yet-implemented method 'SetOverlayMeshHidden'
		// Here lies the not-yet-implemented method 'PlayDying'
		// Here lies the not-yet-implemented method 'NotifyTeamChanged'
		// Here lies the not-yet-implemented method 'UpdateTeamBlockerMaterials'
		// Here lies the not-yet-implemented method 'PossessedBy'
		// Here lies the not-yet-implemented method 'ResetSkin'
		// Here lies the not-yet-implemented method 'SetSkin'
		// Here lies the not-yet-implemented method 'InitializeOverlayMaterials'
		// Here lies the not-yet-implemented method 'ClientPlayHealthRegenEffect'
		// Here lies the not-yet-implemented method 'SetShieldPackActive'
		// Here lies the not-yet-implemented method 'PlayShieldPackEffect'
		// Here lies the not-yet-implemented method 'SetStealthPackActive'
		// Here lies the not-yet-implemented method 'PlayStealthPackEffect'
		// Here lies the not-yet-implemented method 'PulseStealth'
		// Here lies the not-yet-implemented method 'SetRagePerkActive'
		// Here lies the not-yet-implemented method 'ClearRagePerk'
		// Here lies the not-yet-implemented method 'PlayRageEffect'
		// Here lies the not-yet-implemented method 'PlayInvulnerabilityEffect'
		// Here lies the not-yet-implemented method 'StartRidingInVehicle'
		// Here lies the not-yet-implemented method 'StopRidingInVehicle'
		// Here lies the not-yet-implemented method 'StartDriving'
		// Here lies the not-yet-implemented method 'StopDriving'
		// Here lies the not-yet-implemented method 'OnRanOver'
		// Here lies the not-yet-implemented method 'EnableJamming'
		// Here lies the not-yet-implemented method 'DisableJamming'
		// Here lies the not-yet-implemented method 'DisableJammingOtherPawns'
		// Here lies the not-yet-implemented method 'EnteredFriendJammingRadius'
		// Here lies the not-yet-implemented method 'ExitFriendJammingRadius'
		// Here lies the not-yet-implemented method 'EnteredEnemyJammingRadius'
		// Here lies the not-yet-implemented method 'ExitEnemyJammingRadius'
		// Here lies the not-yet-implemented method 'IsJammedByEnemy'
		// Here lies the not-yet-implemented method 'PlayJammerPackEffect'
		// Here lies the not-yet-implemented method 'PlayJammingByFriendEffect'
		// Here lies the not-yet-implemented method 'PlayEnemyJammerPackEffect'
		// Here lies the not-yet-implemented method 'OnPawnDetectedByCollisionProxy'
		// Here lies the not-yet-implemented method 'OnPawnExitedCollisionProxy'
		// Here lies the not-yet-implemented method 'OnEnteredDropJammer'
		// Here lies the not-yet-implemented method 'OnExitedDropJammer'
		// Here lies the not-yet-implemented method 'UpdateEnemyDropJammer'
		// Here lies the not-yet-implemented method 'UpdateFriendlyDropJammer'
		// Here lies the not-yet-implemented method 'PlayJammingByEnemyDropJammerEffect'
		// Here lies the not-yet-implemented method 'PlayJammingByFriendlyDropJammerEffect'
		// Here lies the not-yet-implemented method 'OnChangeJammingTeam'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'SetMeshVisibility'
		// Here lies the not-yet-implemented method 'SetFirstPersonBodyVisibility'
		// Here lies the not-yet-implemented method 'WeaponAttachmentChanged'
		// Here lies the not-yet-implemented method 'ForceCrouch'
		// Here lies the not-yet-implemented method 'FindClosestStickyGrenadeSocketIndex'
		// Here lies the not-yet-implemented method 'StickGrenadeToPawn'
		// Here lies the not-yet-implemented method 'UpdateStickyGrenades'
		// Here lies the not-yet-implemented method 'SetSkiing'
		// Here lies the not-yet-implemented method 'PlaySkiEffects'
		// Here lies the not-yet-implemented method 'StopSkiEffects'
		// Here lies the not-yet-implemented method 'PlaySkiEffectsSound'
		// Here lies the not-yet-implemented method 'StopSkiEffectsSound'
		// Here lies the not-yet-implemented method 'FaceRotation'
		// Here lies the not-yet-implemented method 'PlayDyingSound'
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'AdjustDamage'
		// Here lies the not-yet-implemented method 'GoInvulnerable'
		// Here lies the not-yet-implemented method 'ClearInvulnerability'
		// Here lies the not-yet-implemented method 'SetMovementPhysics'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'PlayTeleportEffect'
		// Here lies the not-yet-implemented method 'TurnOff'
		// Here lies the not-yet-implemented method 'SetDetectedByEnemyScanner'
		// Here lies the not-yet-implemented method 'GetDetectedByEnemyScanner'
		// Here lies the not-yet-implemented method 'SetScannerDetect'
		// Here lies the not-yet-implemented method 'GetFamilyInfo'
		// Here lies the not-yet-implemented method 'LockedOutFromFlagPickupTimer'
		// Here lies the not-yet-implemented method 'LockFromFlagPickup'
		// Here lies the not-yet-implemented method 'Blink'
		// Here lies the not-yet-implemented method 'PlayBlinkPackEffect'
		// Here lies the not-yet-implemented method 'DoJump'
		// Here lies the not-yet-implemented method 'CheckClotheslineDamage'
		// Here lies the not-yet-implemented method 'GetSpectatorName'
		// Here lies the not-yet-implemented method 'CrushedBy'
		// Here lies the not-yet-implemented method 'StuckOnPawn'
		// Here lies the not-yet-implemented method 'SetPending3PSkin'
		// Here lies the not-yet-implemented method 'CheckApplyPending3PSkin'
		// Here lies the not-yet-implemented method 'ThrowActiveWeapon'
		// Here lies the not-yet-implemented method 'ThrowWeaponOnDeath'
		// Here lies the not-yet-implemented method 'ClearSkiParticleEffects'
		// Here lies the not-yet-implemented method 'ClearJetpackParticleEffects'
		// Here lies the not-yet-implemented method 'AlienFXOverlay'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
