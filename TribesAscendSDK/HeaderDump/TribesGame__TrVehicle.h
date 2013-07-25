#pragma once
#include "UTGame__UTVehicle.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__Projectile.h"
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrHUD.h"
#include "TribesGame__TrVehicleStation.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "Engine__Actor.h"
#include "UTGame__UTPawn.h"
#include "UDKBase__UDKCarriedObject.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTVehicleWeapon.h"
#include "Engine__ParticleSystem.h"
#include "TribesGame__TrProj_Tracer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehicle : public UTVehicle
	{
	public:
		ADD_VAR(::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nIconIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bClientPhysDirty, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.RigidBodyState' for the property named 'm_ClientRBState'!
		ADD_VAR(::BoolProperty, m_bServerCorrectionForce, 0x200)
		ADD_VAR(::BoolProperty, m_bImprovedLagSupport, 0x4)
		ADD_VAR(::ByteProperty, m_VehicleType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bUsesArmoredMultiplier, 0x80)
		ADD_VAR(::StrProperty, m_sWeapon1Name, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWeapon2Name, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxPawnLeaveSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nServerTickCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fClientPhysDeltaTime, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_STRUCT(::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleHealthBarPlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger4HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger3HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger2HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_Passenger1HealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_DriverHealthBarMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC)
		ADD_VAR(::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fContrailSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPawn.MaterialImpactEffect' for the property named 'm_DefaultDustEffect'!
		ADD_VAR(::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostFadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDivingMaxSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nBaseMaxSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastWallDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMinDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWallMaxDamageSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, WallCollisionDamageType)
		ADD_VAR(::FloatProperty, m_fVehicleDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastVehicleDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMinDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleMaxDamageSpeed, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, VehicleCollisionDamageType)
		ADD_VAR(::FloatProperty, m_fPawnDamageTickTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMaxDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMinDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnMaxDamageSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPawnPushSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFlagPushSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_CrashDamageSeverity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolTickRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolRechargeRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostReactivatePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostEnergyPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBoostMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToReset, 0xFFFFFFFF)
		ADD_OBJECT(TrVehicleStation, m_OwnerStation)
		ADD_VAR(::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_MissileLock, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bDetectedByEnemyScanner, 0x400)
		ADD_VAR(::BoolProperty, r_LevelFlightEnabled, 0x40)
		ADD_VAR(::BoolProperty, m_bLowPowerPool, 0x20)
		ADD_VAR(::BoolProperty, r_BoostersEnabled, 0x10)
		ADD_VAR(::BoolProperty, r_bIsInvulnerable, 0x8)
		ADD_VAR(::BoolProperty, m_bBoostRequiresThrust, 0x2)
		ADD_VAR(::BoolProperty, m_bPostSpawnLocked, 0x1)
		ADD_OBJECT(TrPawn, m_PawnToTeleport)
		ADD_OBJECT(Pawn, Passenger)
		// Here lies the not-yet-implemented method 'IsEmpty'
		// Here lies the not-yet-implemented method 'RidingPawnLeave'
		// Here lies the not-yet-implemented method 'GetSeatIndexForController'
		// Here lies the not-yet-implemented method 'CalcOtherWatchingCam'
		// Here lies the not-yet-implemented method 'SetScannerDetect'
		// Here lies the not-yet-implemented method 'StopsProjectile'
		// Here lies the not-yet-implemented method 'NativePostRenderFor'
		// Here lies the not-yet-implemented method 'ConsumePowerPool'
		// Here lies the not-yet-implemented method 'GetPowerPoolPercent'
		// Here lies the not-yet-implemented method 'RegainPowerPool'
		// Here lies the not-yet-implemented method 'SyncClientCurrentPowerPool'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'SetDetectedByEnemyScanner'
		// Here lies the not-yet-implemented method 'GetDetectedByEnemyScanner'
		// Here lies the not-yet-implemented method 'PancakeOther'
		// Here lies the not-yet-implemented method 'GetCollisionDamageInstigator'
		// Here lies the not-yet-implemented method 'GetDamageAmountForCollision'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'RanInto'
		// Here lies the not-yet-implemented method 'SitDriver'
		// Here lies the not-yet-implemented method 'DetachDriver'
		// Here lies the not-yet-implemented method 'SetPawnToTeleport'
		// Here lies the not-yet-implemented method 'SetPostSpawnLocked'
		// Here lies the not-yet-implemented method 'SendLockOnMessage'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'KillControllerForTeamChange'
		// Here lies the not-yet-implemented method 'TeleportDriverToSeat'
		// Here lies the not-yet-implemented method 'CanArmorDriveVehicle'
		// Here lies the not-yet-implemented method 'CanArmorEnterVehicle'
		// Here lies the not-yet-implemented method 'GetFirstAvailableSeat'
		// Here lies the not-yet-implemented method 'TryToDrive'
		// Here lies the not-yet-implemented method 'DriverLeft'
		// Here lies the not-yet-implemented method 'PassengerLeave'
		// Here lies the not-yet-implemented method 'CheckReset'
		// Here lies the not-yet-implemented method 'ResetResetTime'
		// Here lies the not-yet-implemented method 'HandleMomentum'
		// Here lies the not-yet-implemented method 'ToggleBoosters'
		// Here lies the not-yet-implemented method 'ConsumeBoostPowerPool'
		// Here lies the not-yet-implemented method 'CanActivateBoosters'
		// Here lies the not-yet-implemented method 'ShouldRechargePowerPool'
		// Here lies the not-yet-implemented method 'ServerToggleLevelFlight'
		// Here lies the not-yet-implemented method 'BoostSoundFinished'
		// Here lies the not-yet-implemented method 'PlayBoosterEffects'
		// Here lies the not-yet-implemented method 'PlayMissileLockSounds'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'Occupied'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'RenderDriverPassengerMarker'
		// Here lies the not-yet-implemented method 'SetSeatStoragePawn'
		// Here lies the not-yet-implemented method 'GetSVehicleDebug'
		// Here lies the not-yet-implemented method 'InitializeSeats'
		// Here lies the not-yet-implemented method 'PassengerEnter'
		// Here lies the not-yet-implemented method 'AttachDriver'
		// Here lies the not-yet-implemented method 'AttachRidingPawn'
		// Here lies the not-yet-implemented method 'DetachRidingPawn'
		// Here lies the not-yet-implemented method 'UpdateSeatAnimations'
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'HandleEnteringFlag'
		// Here lies the not-yet-implemented method 'DriverEnter'
		// Here lies the not-yet-implemented method 'GetSeatPRI'
		// Here lies the not-yet-implemented method 'ServerChangeSeat'
		// Here lies the not-yet-implemented method 'SwitchSeat'
		// Here lies the not-yet-implemented method 'ChangeSeat'
		// Here lies the not-yet-implemented method 'SwitchWeapon'
		// Here lies the not-yet-implemented method 'GetSeatIndexForStoragePawn'
		// Here lies the not-yet-implemented method 'PlaceExitingDriver'
		// Here lies the not-yet-implemented method 'TryExitPos'
		// Here lies the not-yet-implemented method 'SeatAvailable'
		// Here lies the not-yet-implemented method 'AnySeatAvailable'
		// Here lies the not-yet-implemented method 'GetWeaponAim'
		// Here lies the not-yet-implemented method 'WeaponRotationChanged'
		// Here lies the not-yet-implemented method 'HealDamage'
		// Here lies the not-yet-implemented method 'DoRepairs'
		// Here lies the not-yet-implemented method 'DriverRadiusDamage'
		// Here lies the not-yet-implemented method 'Suicide'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'CheckDamageSmoke'
		// Here lies the not-yet-implemented method 'BlowupVehicle'
		// Here lies the not-yet-implemented method 'VehicleWeaponFireEffects'
		// Here lies the not-yet-implemented method 'VehicleWeaponStoppedFiring'
		// Here lies the not-yet-implemented method 'ThirdPersonFireEffects'
		// Here lies the not-yet-implemented method 'SpawnTracerBeam'
		// Here lies the not-yet-implemented method 'SpawnTracerEffect'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'ProcessViewRotationBasedOnSeat'
		// Here lies the not-yet-implemented method 'ShouldShowUseable'
		// Here lies the not-yet-implemented method 'SetDriving'
		// Here lies the not-yet-implemented method 'PlayVehicleEvent'
		// Here lies the not-yet-implemented method 'VehicleEvent'
		// Here lies the not-yet-implemented method 'PlayClientVehicleSound'
		// Here lies the not-yet-implemented method 'MigrateVehicleSounds'
		// Here lies the not-yet-implemented method 'StopVehicleSounds'
		// Here lies the not-yet-implemented method 'GetCameraFocus'
		// Here lies the not-yet-implemented method 'GetSpectatorName'
		// Here lies the not-yet-implemented method 'PlayHorn'
		// Here lies the not-yet-implemented method 'GoInvulnerable'
		// Here lies the not-yet-implemented method 'ClearInvulnerability'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
