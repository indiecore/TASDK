#pragma once
#include "TribesGame.AlienFXManager.h"
#include "UTGame.UTWeaponAttachment.h"
#include "TribesGame.TrEffectForm.h"
#include "UTGame.UTPawn.h"
#include "UDKBase.UDKCarriedObject.h"
#include "TribesGame.TrObject.h"
#include "Engine.Canvas.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrAnimNodeBlendByRidingPassenger.h"
#include "TribesGame.TrStatsInterface.h"
#include "Core.Object.h"
#include "TribesGame.TrAnimNodeAimOffset.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.TrEffect.h"
#include "TribesGame.TrDeployable_DropJammer.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrValueModifier.h"
#include "Engine.Material.h"
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
#include "TribesGame.TrProjectile.h"
#include "Engine.AnimNodeSequence.h"
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
	class TrPawn : public UTPawn
	{
	public:
		static const auto MAX_SCANNER_SEE_FLAG = 2;
		static const auto MAX_SCANNER_DISPLAY_FLAG = 3;
		static const auto MAX_MULTISHOT_LOCATIONS = 8;
		static const auto VELOCITY_HISTORY_SIZE = 3;
		enum PhysicsType : byte
		{
			PhysType_SpeedCap = 0,
			PhysType_AccelCap = 1,
			PhysType_NoCap = 2,
			PhysType_MAX = 3,
		};
		enum WalkingDeceleration : byte
		{
			WalkingDeceleration_None = 0,
			WalkingDeceleration_A = 1,
			WalkingDeceleration_B = 2,
			WalkingDeceleration_C = 3,
			WalkingDeceleration_D = 4,
			WalkingDeceleration_E = 5,
			WalkingDeceleration_MAX = 6,
		};
		class AssistInfo
		{
		public:
			ADD_STRUCT(float, m_fDamagerTime, 8)
			ADD_STRUCT(int, m_AccumulatedDamage, 4)
			ADD_OBJECT(TrPlayerController, m_Damager, 0)
		};
		class FootstepParticleInfo
		{
		public:
			ADD_OBJECT(ParticleSystem, FootParticle, 8)
			ADD_STRUCT(ScriptName, MaterialType, 0)
		};
		class StickyGrenadeSocketInfo
		{
		public:
			ADD_STRUCT(Object::Vector, ViewOffset, 16)
			ADD_OBJECT(TrProjectile, Projectile, 8)
			ADD_STRUCT(ScriptName, SocketName, 0)
		};
		ADD_OBJECT(TrVehicle, m_RidingVehicle, 3096)
		ADD_STRUCT(float, m_fCurrentPowerPool, 2320)
		ADD_STRUCT(float, m_fHeadShotDamageMultiple, 2348)
		ADD_STRUCT(float, m_fCurrentAccuracy, 2540)
		ADD_STRUCT(float, m_fPawnViewForwardAmount, 2964)
		ADD_OBJECT(TrAnimNodeBlendByRidingPassenger, m_RidingPassengerBlendNode, 2600)
		ADD_OBJECT(TrAnimNodeAimOffset, m_AimOffsetNode, 2588)
		ADD_OBJECT(TrAnimNodeAimOffset, m_1pBodyAimOffsetNode, 2592)
		ADD_STRUCT(Object::Vector, r_FlashNormal, 2228)
		ADD_STRUCT(float, m_fShowObjectThreshold, 2616)
		ADD_BOOL(r_bIsStealthed, 2220, 0x4)
		ADD_BOOL(r_bIsInvulnerable, 2220, 0x100000)
		ADD_BOOL(r_bIsSkiing, 2220, 0x800)
		ADD_BOOL(r_bIsJetting, 2220, 0x8000)
		ADD_STRUCT(ScriptArray<class TrEffect*>, m_AppliedEffects, 2476)
		ADD_STRUCT(ScriptArray<class TrEffectForm*>, m_AppliedEffectForms, 2488)
		ADD_STRUCT(ScriptArray<TrPawn::AssistInfo>, m_KillAssisters, 2572)
		ADD_STRUCT(ScriptArray<TrObject::EffectFormOverwrite>, m_EffectFormOverwrite, 2752)
		ADD_STRUCT(ScriptArray<class TrPawn*>, m_JammedFriends, 2776)
		ADD_STRUCT(ScriptArray<class TrPawn*>, m_JammedEnemies, 2788)
		ADD_STRUCT(ScriptArray<class TrPlayerReplicationInfo*>, m_FriendJammingList, 2808)
		ADD_STRUCT(ScriptArray<class TrDeployable_DropJammer*>, m_FriendlyDropJammerList, 2832)
		ADD_STRUCT(ScriptArray<class TrDeployable_DropJammer*>, m_EnemyDropJammerList, 2844)
		ADD_STRUCT(ScriptArray<TrPawn::FootstepParticleInfo>, m_SkiParticles, 2944)
		ADD_STRUCT(ScriptArray<TrPawn::StickyGrenadeSocketInfo>, m_StickyGrenadeSocketList, 2968)
		ADD_STRUCT(ScriptArray<Object::Vector>, m_aPreviousVelocities, 3048)
		ADD_STRUCT(ScriptArray<Object::Vector>, m_aPreviousLocations, 3060)
		ADD_STRUCT(ScriptArray<float>, m_aPreviousTickTimes, 3072)
		ADD_STRUCT(float, m_TerrainWalkableFloorZ, 3188)
		ADD_STRUCT(float, m_fSwapSkinDistSq, 3184)
		ADD_OBJECT(ScriptClass, c_Pending1PSkin, 3180)
		ADD_OBJECT(ScriptClass, c_Pending3PSkin, 3176)
		ADD_STRUCT(int, m_nNetViewPitchCount, 3172)
		ADD_STRUCT(float, m_PitchInterpRate, 3168)
		ADD_STRUCT(int, m_nTargetRemoteViewPitch, 3164)
		ADD_STRUCT(int, m_nPreviousReceivedRemoteViewPitch, 3160)
		ADD_STRUCT(int, m_nSmoothedRemoteViewPitch, 3156)
		ADD_STRUCT(int, m_nNetRotationCount, 3152)
		ADD_STRUCT(float, m_RotationInterpRate, 3148)
		ADD_STRUCT(Object::Rotator, m_TargetNetReceiveRotation, 3136)
		ADD_STRUCT(Object::Rotator, m_PreviousNetReceiveRotation, 3124)
		ADD_OBJECT(SkeletalMesh, m_GibMesh, 3120)
		ADD_OBJECT(TrStatsInterface, Stats, 3116)
		ADD_STRUCT(float, m_fInventoryStationLockoutTime, 3112)
		ADD_STRUCT(float, m_fLastInventoryStationVisitTime, 3108)
		ADD_STRUCT(int, m_nDetectedByEnemyScannerCount, 3104)
		ADD_OBJECT(UDKCarriedObject, m_GameObjCheckTimer, 3100)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC, 3092)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC, 3088)
		ADD_OBJECT(UTWeaponAttachment, m_InHandWeaponAttachmentFromAutoFire, 3084)
		ADD_STRUCT(float, m_fLastTakeClotheslineDamageTimestamp, 3044)
		ADD_STRUCT(float, m_fClotheslineSpeedDifferenceMax, 3040)
		ADD_STRUCT(float, m_fClotheslineSpeedDifferenceMin, 3036)
		ADD_STRUCT(float, m_fClotheslineDamageMax, 3032)
		ADD_STRUCT(float, m_fClotheslineDamageMin, 3028)
		ADD_STRUCT(float, m_fSplatSpeedMax, 3024)
		ADD_STRUCT(float, m_fSplatSpeedMin, 3020)
		ADD_STRUCT(float, m_fSplatDamageFromWallMax, 3016)
		ADD_STRUCT(float, m_fSplatDamageFromWallMin, 3012)
		ADD_STRUCT(float, m_fSplatDamageFromLandMax, 3008)
		ADD_STRUCT(float, m_fSplatDamageFromLandMin, 3004)
		ADD_STRUCT(float, m_bJustLandedSpeedSq, 3000)
		ADD_STRUCT(float, m_fRemainingSeekingTargetHUDZoomTime, 2996)
		ADD_STRUCT(Object::Rotator, m_rPotentialSeekingTargetHUDRotation, 2984)
		ADD_STRUCT(float, m_fRemainingPotentialSeekingTargetHUDZoomTime, 2980)
		ADD_STRUCT(float, m_fGroundSkiEffectDist, 2956)
		ADD_OBJECT(MaterialInstanceConstant, m_InvulnerableOverlayMIC, 2920)
		ADD_OBJECT(Material, m_InvulnerableOverlayMaterial, 2916)
		ADD_OBJECT(MaterialInstanceConstant, m_RageOverlayMIC, 2912)
		ADD_OBJECT(Material, m_RageOverlayMaterial, 2908)
		ADD_OBJECT(MaterialInstanceConstant, m_JammerPackOverlayMIC, 2904)
		ADD_OBJECT(Material, m_JammerPackOverlayMaterial, 2900)
		ADD_OBJECT(MaterialInstanceConstant, m_RegenPackPackOverlayMIC, 2896)
		ADD_OBJECT(Material, m_RegenPackOverlayMaterial, 2892)
		ADD_OBJECT(MaterialInstanceConstant, m_RegenOverlayMIC, 2888)
		ADD_OBJECT(Material, m_RegenOverlayMaterial, 2884)
		ADD_STRUCT(float, m_fShieldPackMaterialHitRampDownSpeed, 2880)
		ADD_STRUCT(float, m_fOverlayMaterialDeactivateSpeed, 2876)
		ADD_STRUCT(float, m_fOverlayMaterialActivateSpeed, 2872)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldPackOverlayMIC, 2868)
		ADD_OBJECT(Material, m_ShieldPackOverlayMaterial, 2864)
		ADD_STRUCT(float, m_fForwardJettingPct, 2860)
		ADD_STRUCT(float, m_fMaxJetpackBoostGroundspeed, 2856)
		ADD_STRUCT(int, r_nEnemyDropJammerCount, 2828)
		ADD_STRUCT(int, r_nFriendlyDropJammerCount, 2824)
		ADD_STRUCT(int, r_nEnemyJamCount, 2820)
		ADD_OBJECT(TrPlayerReplicationInfo, r_FriendJammingPRI, 2804)
		ADD_STRUCT(int, m_JammingFriendTeam, 2800)
		ADD_STRUCT(float, m_fJamEffectRadius, 2772)
		ADD_OBJECT(TrPawnCollisionProxy, m_JammingCollisionProxy, 2768)
		ADD_OBJECT(Material, r_ReplicatedWeaponAttachmentMat, 2764)
		ADD_STRUCT(float, m_OldSpeed, 2748)
		ADD_STRUCT(Object::Vector, r_avMultiShotLocation, 2620)
		ADD_STRUCT(float, m_fEnemyShowDistanceThreshold, 2612)
		ADD_STRUCT(float, m_fFriendlyShowDistanceThreshold, 2608)
		ADD_OBJECT(MorphNodeWeight, m_OverlayMorphNode, 2604)
		ADD_OBJECT(TrAnimNodeBlendByVehicle, m_VehicleBlendNode, 2596)
		ADD_STRUCT(float, m_fFallVelocityTransfer, 2584)
		ADD_STRUCT(float, m_fLastDamagerTimeStamp, 2568)
		ADD_STRUCT(float, m_fLastVehicleDamagerTimeStamp, 2564)
		ADD_STRUCT(float, m_AssistDamagePercentQualifier, 2560)
		ADD_STRUCT(float, m_fSkiAccelPct, 2556)
		ADD_STRUCT(float, m_fSkiAccelCapSpeedThreshold, 2552)
		ADD_STRUCT(float, m_fAirAccelSpeed, 2548)
		ADD_STRUCT(float, m_fAirAccelCapSpeedThreshold, 2544)
		ADD_STRUCT(float, m_fTerminalSkiSpeed, 2536)
		ADD_STRUCT(float, m_fMaxSkiSpeed, 2532)
		ADD_STRUCT(float, m_fSkiSlopeGravityBoost, 2528)
		ADD_STRUCT(float, m_fMaxSkiControlPct, 2524)
		ADD_STRUCT(float, m_fSkiControlSigmaSquare, 2520)
		ADD_STRUCT(float, m_fPeakSkiControlSpeed, 2516)
		ADD_STRUCT(TrObject::TrTakeEffectInfo, r_LastTakeEffectInfo, 2500)
		ADD_STRUCT(float, ShowHeaderUntil, 2472)
		ADD_STRUCT(TrObject::TR_HUD_INFO, m_HudInfo, 2404)
		ADD_STRUCT(int, r_nSensorAlertLevel, 2400)
		ADD_STRUCT(float, m_fDecelerationRateWithFlag, 2396)
		ADD_STRUCT(float, m_fMaxSpeedWithFlag, 2392)
		ADD_STRUCT(float, m_fPreserveVelocityZNormalThreshold, 2388)
		ADD_STRUCT(float, m_fPreserveVelocityThresholdMin, 2384)
		ADD_STRUCT(float, m_fPreserveVelocityThresholdMax, 2380)
		ADD_STRUCT(float, m_fMaxSpeedDecelerationRate, 2376)
		ADD_STRUCT(float, m_fTerminalJettingSpeed, 2372)
		ADD_STRUCT(float, m_fMaxJettingSpeed, 2368)
		ADD_STRUCT(float, m_fAccelRateAtMaxThrustSpeed, 2364)
		ADD_STRUCT(float, m_fMaxJetpackThrustSpeed, 2360)
		ADD_STRUCT(float, m_fMaxStoppingDistance, 2356)
		ADD_STRUCT(float, m_fStoppingDistance, 2352)
		ADD_STRUCT(float, m_fHeadShotFudge, 2344)
		ADD_STRUCT(float, m_fTickedRegenDecimal, 2340)
		ADD_STRUCT(float, m_fSecondsBeforeAutoHeal, 2336)
		ADD_STRUCT(float, r_fPowerPoolRechargeRate, 2332)
		ADD_STRUCT(float, r_fMaxPowerPool, 2328)
		ADD_STRUCT(float, r_fCurrentPowerPool, 2324)
		ADD_STRUCT(float, m_fTimeLastUntargetByLocalPlayer, 2316)
		ADD_STRUCT(float, m_fTimeLastTargetByLocalPlayer, 2312)
		ADD_STRUCT(float, m_fTimeLastUnseenByLocalPlayer, 2308)
		ADD_STRUCT(float, m_fTimeLastSeenByLocalPlayer, 2304)
		ADD_STRUCT(float, s_fVE, 2300)
		ADD_STRUCT(float, m_fShieldMultiple, 2296)
		ADD_STRUCT(float, r_fFasterWeaponSwitchMultiplier, 2292)
		ADD_STRUCT(float, m_fPulseStealthIgnoreTime, 2288)
		ADD_STRUCT(float, m_fPulseStealthIgnoreTimeStamp, 2284)
		ADD_STRUCT(float, r_fPulseStealthSpeedThreshold, 2280)
		ADD_STRUCT(float, m_fPulseStealthFadeInInterpSpeed, 2276)
		ADD_STRUCT(float, m_fPulseStealthVisibleTime, 2272)
		ADD_STRUCT(float, m_fPulseStealthVisibleTimestamp, 2268)
		ADD_OBJECT(MaterialInstanceConstant, m_StealthMIC, 2264)
		ADD_OBJECT(Material, m_StealthMaterial, 2260)
		ADD_STRUCT(float, m_fMinStealthVisibilityParamValue, 2256)
		ADD_STRUCT(float, m_fDisableStealthVisibilityInterpSpeed, 2252)
		ADD_STRUCT(float, m_fEnableStealthVisibilityInterpSpeed, 2248)
		ADD_STRUCT(AlienFXManager::FXOverlay, LastFXOverlay, 2247)
		ADD_STRUCT(byte, r_nWhiteOut, 2246)
		ADD_STRUCT(TrObject::EMissileLock, m_MissileLockStatus, 2245)
		ADD_STRUCT(byte, r_RemoteViewYaw, 2244)
		ADD_STRUCT(TrPawn::PhysicsType, PhysType, 2243)
		ADD_STRUCT(int, r_nFactionId, 2208)
		ADD_STRUCT(byte, r_nBlinked, 2242)
		ADD_STRUCT(byte, r_nPulseStealth, 2241)
		ADD_STRUCT(TrObject::EMissileLock, r_MissileLock, 2240)
		ADD_OBJECT(Actor, r_LockedTarget, 2224)
		ADD_BOOL(m_bUseSmoothNetReceiveRotation, 2220, 0x1000000)
		ADD_BOOL(r_bDetectedByEnemyScanner, 2220, 0x800000)
		ADD_BOOL(m_bSplattedAgainstWall, 2220, 0x400000)
		ADD_BOOL(m_bIsInConduit, 2220, 0x200000)
		ADD_BOOL(m_bUpdateStickyGrenades, 2220, 0x80000)
		ADD_BOOL(m_bLoadoutReset, 2220, 0x40000)
		ADD_BOOL(r_bIsJamming, 2220, 0x20000)
		ADD_BOOL(m_bIsJetEffectsPlaying, 2220, 0x10000)
		ADD_BOOL(r_bAimingMode, 2220, 0x4000)
		ADD_BOOL(m_bIsPlayingSkiEffectsSounds, 2220, 0x2000)
		ADD_BOOL(m_bIsPlayingSkiEffects, 2220, 0x1000)
		ADD_BOOL(bInDeployModeClient, 2220, 0x400)
		ADD_BOOL(r_bInDeployMode, 2220, 0x200)
		ADD_BOOL(bInFireLockClient, 2220, 0x100)
		ADD_BOOL(r_bInFireLock, 2220, 0x80)
		ADD_BOOL(r_bIsHealthRecharging, 2220, 0x40)
		ADD_BOOL(r_bIsShielded, 2220, 0x20)
		ADD_BOOL(r_bIsRaged, 2220, 0x10)
		ADD_BOOL(m_bStealthVisible, 2220, 0x8)
		ADD_BOOL(m_bRefreshInventoryWasRespawn, 2220, 0x2)
		ADD_BOOL(m_bInitialized, 2220, 0x1)
		ADD_STRUCT(ScriptName, m_nmMakeVisible, 2212)
		float GetCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentPowerPool");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetMaxPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetMaxPowerPool");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		int CalculatePawnSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CalculatePawnSpeed");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		ScriptClass* GetCurrCharClassInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrCharClassInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsFirstPerson");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class SkeletalMesh* GetHandsMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetHandsMesh");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[4];
		}
		class TrPlayerReplicationInfo* GetTribesReplicationInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTribesReplicationInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerReplicationInfo**)&params[0];
		}
		bool CheckHeadShot(Actor::ImpactInfo& Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckHeadShot");
			byte params[84] = { NULL };
			*(Actor::ImpactInfo*)&params[0] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Impact = *(Actor::ImpactInfo*)&params[0];
			return *(bool*)&params[80];
		}
		Object::Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPawnViewLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		class TrHUD* GetTrHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTrHud");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrHUD**)&params[0];
		}
		bool IsPulseStealthed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsPulseStealthed");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsJammedByFriendOrSelf()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsJammedByFriendOrSelf");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CheckGrabSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckGrabSpeed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float NativeGetCollisionHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativeGetCollisionHeight");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float NativeGetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativeGetCollisionRadius");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SyncClientCurrentPowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SyncClientCurrentPowerPool");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConsumePowerPool(float fAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ConsumePowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = fAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RegainPowerPool(float fDeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RegainPowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetPowerPoolPercent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPowerPoolPercent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void GetCurrentDeviceAccuracyInfo(float& fAccuracy, float& fAmountCurrentlyOffOfTargetAccuray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentDeviceAccuracyInfo");
			byte params[8] = { NULL };
			*(float*)&params[0] = fAccuracy;
			*(float*)&params[4] = fAmountCurrentlyOffOfTargetAccuray;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			fAccuracy = *(float*)&params[0];
			fAmountCurrentlyOffOfTargetAccuray = *(float*)&params[4];
		}
		void SetOverlayMaterial(class MaterialInterface* NewOverlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetOverlayMaterial");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = NewOverlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ServerUpdateLockedTarget(class Actor* Locked)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ServerUpdateLockedTarget");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Locked;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.NativePostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetTargetLocation");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		void SetFlashNormal(Object::Vector FlashNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetFlashNormal");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = FlashNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCurrentCredits()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetCurrentCredits");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ClientRestart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClientRestart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int CurrentDeployedCount(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CurrentDeployedCount");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ExitDeployMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ExitDeployMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		TrObject::EArmorType GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetArmorType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::EArmorType*)&params[0];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicateMultiFlashLocation(int shotNumber, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ReplicateMultiFlashLocation");
			byte params[16] = { NULL };
			*(int*)&params[0] = shotNumber;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EquipBestPossibleDevice(TrObject::TR_EQUIP_POINT eqpPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EquipBestPossibleDevice");
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = eqpPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitDefaultAnims(ScriptClass* Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.InitDefaultAnims");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCharacterClassFromInfo(ScriptClass* Info, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetCharacterClassFromInfo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Info;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivatePendingClass(bool bIsRespawn, bool bCallin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ActivatePendingClass");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bIsRespawn;
			*(bool*)&params[4] = bCallin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(bool*)&params[0] = bIsRespawn;
			*(bool*)&params[4] = bCallin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivateSelectedDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ActivateSelectedDeployable");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveEffectByClass(ScriptClass* efClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RemoveEffectByClass");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = efClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessEffectForm(ScriptClass* efClass, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessEffectForm");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = efClass;
			*(bool*)&params[4] = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetShieldStrength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetShieldStrength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void AdjustAmmoPool(float Change)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustAmmoPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = Change;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustMaxPowerPool(float Change)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustMaxPowerPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = Change;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMaxPowerPool(int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMaxPowerPool");
			byte params[4] = { NULL };
			*(int*)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMaxHealthPool(int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetMaxHealthPool");
			byte params[4] = { NULL };
			*(int*)&params[0] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateHUDHealth(int NewHealth, int NewHealthMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ClientUpdateHUDHealth");
			byte params[8] = { NULL };
			*(int*)&params[0] = NewHealth;
			*(int*)&params[4] = NewHealthMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldRechargePowerPool()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ShouldRechargePowerPool");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ForceHealthRegen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ForceHealthRegen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RechargeHealthPool(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RechargeHealthPool");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector GetJetpackAirControl(Object::Vector InAcceleration, Object::Vector ZAxis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetJetpackAirControl");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = InAcceleration;
			*(Object::Vector*)&params[12] = ZAxis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
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
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = Damager;
			*(int*)&params[4] = DamageAmount;
			*(class Actor**)&params[8] = DamagingActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetHealthPct()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetHealthPct");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		TrPawn::AssistInfo CreateAssistRecord(class Controller* Damager, int DamageAmount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CreateAssistRecord");
			byte params[20] = { NULL };
			*(class Controller**)&params[0] = Damager;
			*(int*)&params[4] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrPawn::AssistInfo*)&params[8];
		}
		class TrPlayerController* GetLastDamager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetLastDamager");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerController**)&params[0];
		}
		void ProcessKillAssists(class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessKillAssists");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Killer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetUnshieldedDamage(float inputDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetUnshieldedDamage");
			byte params[8] = { NULL };
			*(float*)&params[0] = inputDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		class TrPawn* GetPawnCausingDamage(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetPawnCausingDamage");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			*(class Actor**)&params[4] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPawn**)&params[8];
		}
		float GetDamageScale(class Actor* DamageCauser, float Dist, ScriptClass* dmgType, class Controller* EventInstigator, class TrValueModifier* VM, float& DamageScaleWithoutNewPlayerAssist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetDamageScale");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = DamageCauser;
			*(float*)&params[4] = Dist;
			*(ScriptClass**)&params[8] = dmgType;
			*(class Controller**)&params[12] = EventInstigator;
			*(class TrValueModifier**)&params[16] = VM;
			*(float*)&params[20] = DamageScaleWithoutNewPlayerAssist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DamageScaleWithoutNewPlayerAssist = *(float*)&params[20];
			return *(float*)&params[24];
		}
		void DoRepairs(int HealAmount, class Controller* EventInstigator, class Actor* DamageCauser, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DoRepairs");
			byte params[16] = { NULL };
			*(int*)&params[0] = HealAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(class Actor**)&params[8] = DamageCauser;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* CheckTribesTurretInstigator(class Controller* EventInstigator, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckTribesTurretInstigator");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			*(class Actor**)&params[4] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[8];
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWhiteoutEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayWhiteoutEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* EventInstigator, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = EventInstigator;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RecentlyGrabbedFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.RecentlyGrabbedFlag");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float GetShowDistanceThreshold(bool bIsEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetShowDistanceThreshold");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bIsEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeFallingDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHardLandingEffect(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayHardLandingEffect");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlaySonicPunchEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlaySonicPunchEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeFallDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TakeFallDamage");
			byte params[32] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessCreditEvent(TrObject::TrCreditEventType EventType, bool bProxyEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ProcessCreditEvent");
			byte params[5] = { NULL };
			*(TrObject::TrCreditEventType*)&params[0] = EventType;
			*(bool*)&params[4] = bProxyEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashLocationUpdated(class Weapon* InWeapon, Object::Vector InFlashLocation, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FlashLocationUpdated");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = InFlashLocation;
			*(bool*)&params[16] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Dodge");
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PerformDodge(Actor::EDoubleClickDir DoubleClickMove, Object::Vector Dir, Object::Vector Cross)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PerformDodge");
			byte params[29] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			*(Object::Vector*)&params[4] = Dir;
			*(Object::Vector*)&params[16] = Cross;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.gibbedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldGib(ScriptClass* UTDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ShouldGib");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = UTDamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetHandIKEnabled(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetHandIKEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDamageCameraShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDamageCameraShake");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsLastHitFromNinjaSmoke()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.IsLastHitFromNinjaSmoke");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PlayTakeHitEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayTakeHitEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void StopLocalEffectsAndSounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopLocalEffectsAndSounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOverlayMeshHidden(bool bNewHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetOverlayMeshHidden");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Object::Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDying");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = DamageType;
			*(Object::Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ResetSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkin(class Material* NewMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetSkin");
			byte params[4] = { NULL };
			*(class Material**)&params[0] = NewMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayShieldPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayShieldPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStealthPackActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetStealthPackActive");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStealthPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayStealthPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseStealth(bool bOverrideIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PulseStealth");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bOverrideIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class TrVehicle**)&params[0] = V;
			*(int*)&params[4] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopRidingInVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopRidingInVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StartDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StopDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRanOver(class SVehicle* Vehicle, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* RunOverComponent, int WheelIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnRanOver");
			byte params[12] = { NULL };
			*(class SVehicle**)&params[0] = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = RunOverComponent;
			*(int*)&params[8] = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = JammingFriend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExitFriendJammingRadius(class TrPawn* JammingFriend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ExitFriendJammingRadius");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = JammingFriend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = enteredJammingRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnDetectedByCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnPawnDetectedByCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPawnExitedCollisionProxy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnPawnExitedCollisionProxy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEnteredDropJammer(class TrDeployable_DropJammer* DropJammer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnEnteredDropJammer");
			byte params[4] = { NULL };
			*(class TrDeployable_DropJammer**)&params[0] = DropJammer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnExitedDropJammer(class TrDeployable_DropJammer* DropJammer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.OnExitedDropJammer");
			byte params[4] = { NULL };
			*(class TrDeployable_DropJammer**)&params[0] = DropJammer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFirstPersonBodyVisibility(bool bHide)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetFirstPersonBodyVisibility");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bHide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		int FindClosestStickyGrenadeSocketIndex(Object::Vector ProjectileLocation, bool bOnlyFindAvailableSlots)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FindClosestStickyGrenadeSocketIndex");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = ProjectileLocation;
			*(bool*)&params[12] = bOnlyFindAvailableSlots;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		void StickGrenadeToPawn(class TrProjectile* Projectile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StickGrenadeToPawn");
			byte params[4] = { NULL };
			*(class TrProjectile**)&params[0] = Projectile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateStickyGrenades(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.UpdateStickyGrenades");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkiing(bool bEnabled, bool bJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetSkiing");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnabled;
			*(bool*)&params[4] = bJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void FaceRotation(Object::Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.FaceRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayDyingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HoldGameObject(class UDKCarriedObject* GameObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.HoldGameObject");
			byte params[4] = { NULL };
			*(class UDKCarriedObject**)&params[0] = GameObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustDamage(int& InDamage, Object::Vector& Momentum, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AdjustDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = InDamage;
			*(Object::Vector*)&params[4] = Momentum;
			*(class Controller**)&params[16] = InstigatedBy;
			*(Object::Vector*)&params[20] = HitLocation;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InDamage = *(int*)&params[0];
			Momentum = *(Object::Vector*)&params[4];
		}
		void GoInvulnerable(float InvulnerableTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GoInvulnerable");
			byte params[4] = { NULL };
			*(float*)&params[0] = InvulnerableTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayTeleportEffect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.TurnOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDetectedByEnemyScanner(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetDetectedByEnemyScanner");
			byte params[4] = { NULL };
			*(bool*)&params[0] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDetectedByEnemyScanner()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetDetectedByEnemyScanner");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SetScannerDetect(bool detected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetScannerDetect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = detected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptClass* GetFamilyInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetFamilyInfo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void LockedOutFromFlagPickupTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.LockedOutFromFlagPickupTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LockFromFlagPickup(float TimeToLock)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.LockFromFlagPickup");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeToLock;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Blink(Object::Vector Impulse, float MinZ, float PctEffectiveness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.Blink");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = Impulse;
			*(float*)&params[12] = MinZ;
			*(float*)&params[16] = PctEffectiveness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBlinkPackEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.PlayBlinkPackEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.DoJump");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckClotheslineDamage(class Pawn* PawnHittingMe)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckClotheslineDamage");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = PawnHittingMe;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CrushedBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.StuckOnPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPending3PSkin(ScriptClass* NewPendingSkin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.SetPending3PSkin");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = NewPendingSkin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckApplyPending3PSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.CheckApplyPending3PSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.ThrowActiveWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void AlienFXOverlay(AlienFXManager::FXOverlay Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawn.AlienFXOverlay");
			byte params[1] = { NULL };
			*(AlienFXManager::FXOverlay*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
