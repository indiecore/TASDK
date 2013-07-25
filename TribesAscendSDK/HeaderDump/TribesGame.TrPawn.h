#pragma once
#include "UTGame.UTWeaponAttachment.h"
#include "Engine.SkeletalMesh.h"
#include "UTGame.UTPawn.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.Canvas.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrAnimNodeBlendByRidingPassenger.h"
#include "TribesGame.TrStatsInterface.h"
#include "TribesGame.TrAnimNodeAimOffset.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrValueModifier.h"
#include "Engine.Material.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.TrPawnCollisionProxy.h"
#include "Engine.MorphNodeWeight.h"
#include "TribesGame.TrAnimNodeBlendByVehicle.h"
#include "Engine.Actor.h"
#include "TribesGame.TrHUD.h"
#include "Engine.MaterialInterface.h"
#include "Engine.PlayerController.h"
#include "Engine.Controller.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.HUD.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "Engine.Vehicle.h"
#include "Engine.SVehicle.h"
#include "TribesGame.TrDeployable_DropJammer.h"
#include "TribesGame.TrProjectile.h"
#include "Engine.AnimNodeSequence.h"
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
		ADD_STRUCT(::VectorProperty, r_FlashNormal, 0xFFFFFFFF)
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
		ADD_STRUCT(::RotatorProperty, m_TargetNetReceiveRotation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_PreviousNetReceiveRotation, 0xFFFFFFFF)
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
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF)
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
		ADD_STRUCT(::VectorProperty, r_avMultiShotLocation, 0xFFFFFFFF)
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
		float GetCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentPowerPool");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetMaxPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetMaxPowerPool");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		int CalculatePawnSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CalculatePawnSpeed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetCurrCharClassInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrCharClassInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsFirstPerson");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class SkeletalMesh* GetHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetHandsMesh");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)(params + 4);
			free(params);
			return returnVal;
		}
		class TrPlayerReplicationInfo* GetTribesReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTribesReplicationInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrPlayerReplicationInfo**)params;
			free(params);
			return returnVal;
		}
		bool CheckHeadShot(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void*& Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckHeadShot");
			byte* params = (byte*)malloc(84);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)params = Impact;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Impact = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)params;
			auto returnVal = *(bool*)(params + 80);
			free(params);
			return returnVal;
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPawnViewLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		class TrHUD* GetTrHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTrHud");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrHUD**)params;
			free(params);
			return returnVal;
		}
		bool IsPulseStealthed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsPulseStealthed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsJammedByFriendOrSelf()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsJammedByFriendOrSelf");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CheckGrabSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckGrabSpeed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float NativeGetCollisionHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativeGetCollisionHeight");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float NativeGetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativeGetCollisionRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SyncClientCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SyncClientCurrentPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConsumePowerPool(float fAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ConsumePowerPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = fAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RegainPowerPool(float fDeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RegainPowerPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = fDeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetPowerPoolPercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPowerPoolPercent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void GetCurrentDeviceAccuracyInfo(float& fAccuracy, float& fAmountCurrentlyOffOfTargetAccuray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentDeviceAccuracyInfo");
			byte* params = (byte*)malloc(8);
			*(float*)params = fAccuracy;
			*(float*)(params + 4) = fAmountCurrentlyOffOfTargetAccuray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			fAccuracy = *(float*)params;
			fAmountCurrentlyOffOfTargetAccuray = *(float*)(params + 4);
			free(params);
		}
		void SetOverlayMaterial(class MaterialInterface* NewOverlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetOverlayMaterial");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewOverlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ServerUpdateLockedTarget(class Actor* Locked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ServerUpdateLockedTarget");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Locked;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativePostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTargetLocation");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = RequestedBy;
			*(bool*)(params + 4) = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetFlashNormal(Vector FlashNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetFlashNormal");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = FlashNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetCurrentCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentCredits");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ClientRestart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClientRestart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CurrentDeployedCount(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CurrentDeployedCount");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ExitDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetArmorType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicateMultiFlashLocation(int shotNumber, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ReplicateMultiFlashLocation");
			byte* params = (byte*)malloc(16);
			*(int*)params = shotNumber;
			*(Vector*)(params + 4) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EquipBestPossibleDevice(byte eqpPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EquipBestPossibleDevice");
			byte* params = (byte*)malloc(1);
			*params = eqpPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitDefaultAnims(ScriptClass* Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.InitDefaultAnims");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Info;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetCharacterClassFromInfo");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Info;
			*(bool*)(params + 4) = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivatePendingClass(bool bIsRespawn, bool bCallin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ActivatePendingClass");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bIsRespawn;
			*(bool*)(params + 4) = bCallin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshInventoryTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RefreshInventoryTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetValuesFromCurrentFamilyInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetValuesFromCurrentFamilyInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshInventory(bool bIsRespawn, bool bCallin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RefreshInventory");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bIsRespawn;
			*(bool*)(params + 4) = bCallin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivateSelectedDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ActivateSelectedDeployable");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveEffectByClass(ScriptClass* efClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RemoveEffectByClass");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = efClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessEffectForm(ScriptClass* efClass, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessEffectForm");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = efClass;
			*(bool*)(params + 4) = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetShieldStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetShieldStrength");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void AdjustAmmoPool(float Change)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustAmmoPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = Change;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustMaxPowerPool(float Change)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustMaxPowerPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = Change;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMaxPowerPool(int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMaxPowerPool");
			byte* params = (byte*)malloc(4);
			*(int*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMaxHealthPool(int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMaxHealthPool");
			byte* params = (byte*)malloc(4);
			*(int*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientUpdateHUDHealth(int NewHealth, int NewHealthMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClientUpdateHUDHealth");
			byte* params = (byte*)malloc(8);
			*(int*)params = NewHealth;
			*(int*)(params + 4) = NewHealthMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldRechargePowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ShouldRechargePowerPool");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ForceHealthRegen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ForceHealthRegen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RechargeHealthPool(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RechargeHealthPool");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetJetpackAirControl(Vector InAcceleration, Vector ZAxis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetJetpackAirControl");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = InAcceleration;
			*(Vector*)(params + 12) = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 24);
			free(params);
			return returnVal;
		}
		void UpdateSkiEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateSkiEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopJetpackEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopJetpackEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayLandingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayLandingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJumpingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJumpingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RememberLastDamager(class Controller* Damager, int DamageAmount, class Actor* DamagingActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RememberLastDamager");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Damager;
			*(int*)(params + 4) = DamageAmount;
			*(class Actor**)(params + 8) = DamagingActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetHealthPct()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetHealthPct");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrPawn.AssistInfo'!
void* CreateAssistRecord(class Controller* Damager, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CreateAssistRecord");
			byte* params = (byte*)malloc(20);
			*(class Controller**)params = Damager;
			*(int*)(params + 4) = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrPawn.AssistInfo'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		class TrPlayerController* GetLastDamager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetLastDamager");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrPlayerController**)params;
			free(params);
			return returnVal;
		}
		void ProcessKillAssists(class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessKillAssists");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Killer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetUnshieldedDamage(float inputDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetUnshieldedDamage");
			byte* params = (byte*)malloc(8);
			*(float*)params = inputDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		class TrPawn* GetPawnCausingDamage(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPawnCausingDamage");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = EventInstigator;
			*(class Actor**)(params + 4) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrPawn**)(params + 8);
			free(params);
			return returnVal;
		}
		float GetDamageScale(class Actor* DamageCauser, float Dist, ScriptClass* dmgType, class Controller* EventInstigator, class TrValueModifier* VM, float& DamageScaleWithoutNewPlayerAssist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetDamageScale");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = DamageCauser;
			*(float*)(params + 4) = Dist;
			*(ScriptClass**)(params + 8) = dmgType;
			*(class Controller**)(params + 12) = EventInstigator;
			*(class TrValueModifier**)(params + 16) = VM;
			*(float*)(params + 20) = DamageScaleWithoutNewPlayerAssist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DamageScaleWithoutNewPlayerAssist = *(float*)(params + 20);
			auto returnVal = *(float*)(params + 24);
			free(params);
			return returnVal;
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DoRepairs");
			byte* params = (byte*)malloc(16);
			*(int*)params = HealAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(class Actor**)(params + 8) = DamageCauser;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Controller* CheckTribesTurretInstigator(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckTribesTurretInstigator");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = EventInstigator;
			*(class Actor**)(params + 4) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 8);
			free(params);
			return returnVal;
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWhiteoutEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayWhiteoutEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* EventInstigator, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeRadiusDamage");
			byte* params = (byte*)malloc(44);
			*(class Controller**)params = EventInstigator;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(float*)(params + 40) = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RecentlyGrabbedFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RecentlyGrabbedFlag");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float GetShowDistanceThreshold(bool bIsEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetShowDistanceThreshold");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bIsEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeFallingDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHardLandingEffect(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayHardLandingEffect");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlaySonicPunchEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlaySonicPunchEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeFallDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeFallDamage");
			byte* params = (byte*)malloc(32);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessCreditEvent(byte EventType, bool bProxyEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessCreditEvent");
			byte* params = (byte*)malloc(5);
			*params = EventType;
			*(bool*)(params + 4) = bProxyEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlashLocationUpdated(class Weapon* InWeapon, Vector InFlashLocation, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FlashLocationUpdated");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(Vector*)(params + 4) = InFlashLocation;
			*(bool*)(params + 16) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.WeaponFired");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Dodge(byte DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Dodge");
			byte* params = (byte*)malloc(5);
			*params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PerformDodge(byte DoubleClickMove, Vector Dir, Vector Cross)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PerformDodge");
			byte* params = (byte*)malloc(29);
			*params = DoubleClickMove;
			*(Vector*)(params + 4) = Dir;
			*(Vector*)(params + 16) = Cross;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.gibbedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldGib(ScriptClass* UTDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ShouldGib");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = UTDamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetHandIKEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDamageCameraShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDamageCameraShake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsLastHitFromNinjaSmoke()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsLastHitFromNinjaSmoke");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PlayTakeHitEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayTakeHitEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void StopLocalEffectsAndSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopLocalEffectsAndSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOverlayMeshHidden(bool bNewHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetOverlayMeshHidden");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewHidden;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDying");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = DamageType;
			*(Vector*)(params + 4) = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTeamBlockerMaterials()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateTeamBlockerMaterials");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PossessedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ResetSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetSkin");
			byte* params = (byte*)malloc(4);
			*(class Material**)params = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitializeOverlayMaterials()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.InitializeOverlayMaterials");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientPlayHealthRegenEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClientPlayHealthRegenEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShieldPackActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetShieldPackActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayShieldPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayShieldPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStealthPackActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetStealthPackActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStealthPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayStealthPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseStealth(bool bOverrideIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PulseStealth");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bOverrideIgnore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRagePerkActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetRagePerkActive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearRagePerk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClearRagePerk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayRageEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayRageEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayInvulnerabilityEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayInvulnerabilityEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartRidingInVehicle(class TrVehicle* V, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StartRidingInVehicle");
			byte* params = (byte*)malloc(8);
			*(class TrVehicle**)params = V;
			*(int*)(params + 4) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopRidingInVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopRidingInVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StartDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRanOver(class SVehicle* Vehicle, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* RunOverComponent, int WheelIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnRanOver");
			byte* params = (byte*)malloc(12);
			*(class SVehicle**)params = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = RunOverComponent;
			*(int*)(params + 8) = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableJamming()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EnableJamming");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableJamming()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DisableJamming");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableJammingOtherPawns()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DisableJammingOtherPawns");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnteredFriendJammingRadius(class TrPawn* JammingFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EnteredFriendJammingRadius");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = JammingFriend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ExitFriendJammingRadius(class TrPawn* JammingFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ExitFriendJammingRadius");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = JammingFriend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnteredEnemyJammingRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EnteredEnemyJammingRadius");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitEnemyJammingRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ExitEnemyJammingRadius");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsJammedByEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsJammedByEnemy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PlayJammerPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJammerPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJammingByFriendEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJammingByFriendEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayEnemyJammerPackEffect(bool enteredJammingRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayEnemyJammerPackEffect");
			byte* params = (byte*)malloc(4);
			*(bool*)params = enteredJammingRadius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnPawnDetectedByCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnPawnExitedCollisionProxy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnEnteredDropJammer(class TrDeployable_DropJammer* DropJammer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnEnteredDropJammer");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable_DropJammer**)params = DropJammer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnExitedDropJammer(class TrDeployable_DropJammer* DropJammer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnExitedDropJammer");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable_DropJammer**)params = DropJammer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateEnemyDropJammer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateEnemyDropJammer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateFriendlyDropJammer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateFriendlyDropJammer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJammingByEnemyDropJammerEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJammingByEnemyDropJammerEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayJammingByFriendlyDropJammerEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayJammingByFriendlyDropJammerEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnChangeJammingTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnChangeJammingTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMeshVisibility(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMeshVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFirstPersonBodyVisibility(bool bHide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetFirstPersonBodyVisibility");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bHide;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponAttachmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.WeaponAttachmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceCrouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ForceCrouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindClosestStickyGrenadeSocketIndex(Vector ProjectileLocation, bool bOnlyFindAvailableSlots)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FindClosestStickyGrenadeSocketIndex");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = ProjectileLocation;
			*(bool*)(params + 12) = bOnlyFindAvailableSlots;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		void StickGrenadeToPawn(class TrProjectile* Projectile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StickGrenadeToPawn");
			byte* params = (byte*)malloc(4);
			*(class TrProjectile**)params = Projectile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateStickyGrenades(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateStickyGrenades");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkiing(bool bEnabled, bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetSkiing");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnabled;
			*(bool*)(params + 4) = bJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlaySkiEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlaySkiEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopSkiEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopSkiEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlaySkiEffectsSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlaySkiEffectsSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopSkiEffectsSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopSkiEffectsSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FaceRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDyingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.HoldGameObject");
			byte* params = (byte*)malloc(4);
			*(class UDKCarriedObject**)params = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustDamage(int& InDamage, Vector& Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = InDamage;
			*(Vector*)(params + 4) = Momentum;
			*(class Controller**)(params + 16) = InstigatedBy;
			*(Vector*)(params + 20) = HitLocation;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InDamage = *(int*)params;
			Momentum = *(Vector*)(params + 4);
			free(params);
		}
		void GoInvulnerable(float InvulnerableTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GoInvulnerable");
			byte* params = (byte*)malloc(4);
			*(float*)params = InvulnerableTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearInvulnerability()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClearInvulnerability");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMovementPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMovementPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayTeleportEffect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOut;
			*(bool*)(params + 4) = bSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TurnOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TurnOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDetectedByEnemyScanner(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetDetectedByEnemyScanner");
			byte* params = (byte*)malloc(4);
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetDetectedByEnemyScanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetDetectedByEnemyScanner");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SetScannerDetect(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetScannerDetect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = detected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetFamilyInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetFamilyInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void LockedOutFromFlagPickupTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.LockedOutFromFlagPickupTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LockFromFlagPickup(float TimeToLock)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.LockFromFlagPickup");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeToLock;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Blink(Vector Impulse, float MinZ, float PctEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Blink");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = Impulse;
			*(float*)(params + 12) = MinZ;
			*(float*)(params + 16) = PctEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBlinkPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayBlinkPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DoJump");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckClotheslineDamage(class Pawn* PawnHittingMe)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckClotheslineDamage");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = PawnHittingMe;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CrushedBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StuckOnPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPending3PSkin(ScriptClass* NewPendingSkin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetPending3PSkin");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = NewPendingSkin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckApplyPending3PSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckApplyPending3PSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ThrowActiveWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThrowWeaponOnDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ThrowWeaponOnDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSkiParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClearSkiParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearJetpackParticleEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClearJetpackParticleEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AlienFXOverlay(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AlienFXOverlay");
			byte* params = (byte*)malloc(1);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
