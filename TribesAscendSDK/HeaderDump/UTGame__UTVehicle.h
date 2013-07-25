#pragma once
#include "UTGame__UTHUD.h"
#include "Engine__Texture2D.h"
#include "UDKBase__UDKVehicle.h"
#include "Engine__Vehicle.h"
#include "Engine__StaticMesh.h"
#include "UTGame__UTWeapon.h"
#include "Engine__ParticleSystem.h"
#include "UTGame__UTGib.h"
#include "Engine__MaterialInterface.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "UTGame__UTVehicleDeathPiece.h"
#include "Engine__Weapon.h"
#include "Engine__CameraAnim.h"
#include "Engine__Emitter.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTVehicleFactory.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#include "Engine__Canvas.h"
#include "UTGame__UTCarriedObject.h"
#include "UTGame__UTMapInfo.h"
#include "UTGame__UTPlayerController.h"
#include "Engine__Controller.h"
#include "Engine__Projectile.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__PlayerController.h"
#include "UDKBase__UDKProjectile.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UDKBase__UDKCarriedObject.h"
#include "UTGame__UTSquadAI.h"
#include "UTGame__UTProjectile.h"
#include "UTGame__UTVehicleWeapon.h"
#include "UTGame__UTPawn.h"
#include "UTGame__UTSeqAct_ExitVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVehicle : public UDKVehicle
	{
	public:
		ADD_VAR(::BoolProperty, bCanCarryFlag, 0x2)
		ADD_VAR(::BoolProperty, bRequestedEntryWithFlag, 0x200000)
		ADD_VAR(::BoolProperty, bHasCustomEntryRadius, 0x10)
		ADD_OBJECT(UTVehicle, NextVehicle)
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDropDetailWhenDriving, 0x10000)
		ADD_VAR(::BoolProperty, bSpectatedView, 0x200)
		ADD_VAR(::FloatProperty, LastEnemyWarningTime, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, ReferenceMovementMesh)
		ADD_OBJECT(ParticleSystem, DisabledTemplate)
		ADD_VAR(::FloatProperty, TimeLastDisabled, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DisabledTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OldCameraPosition, 0xFFFFFFFF
		ADD_OBJECT(UTGib, DeathCameraGib)
		ADD_VAR(::FloatProperty, MinCameraDistSq, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookForwardDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CameraOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CameraLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraSmoothingFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldCamPosZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SeatCameraScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCollisionDamageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionDamageMult, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, BurnOutMaterial)
		ADD_VAR(::FloatProperty, SpawnInTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SpawnMaterialParameterCurve'!
		ADD_VAR(::NameProperty, SpawnMaterialParameterName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'HudCoords'!
		ADD_OBJECT(Texture2D, HudIcons)
		ADD_STRUCT(::VectorProperty, PassengerTeamBeaconOffset, 0xFFFFFFFF
		ADD_OBJECT(PlayerReplicationInfo, PassengerPRI)
		ADD_STRUCT(::VectorProperty, TeamBeaconOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, HealthPulseTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastHealth, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'DropOrbIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'DropFlagIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'EnterToolTipIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'FlipToolTipIconCoords'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, FlagBone, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, FlagRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FlagOffset, 0xFFFFFFFF
		ADD_OBJECT(SoundCue, BoostPadSound)
		ADD_OBJECT(SoundCue, SpawnOutSound)
		ADD_OBJECT(SoundCue, SpawnInSound)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BurnTimeParameterName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_VAR(::FloatProperty, TurretExplosiveForce, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, DestroyedTurretTemplate)
		ADD_OBJECT(UTVehicleDeathPiece, DestroyedTurret)
		ADD_STRUCT(::VectorProperty, TurretOffset, 0xFFFFFFFF
		ADD_VAR(::NameProperty, TurretSocketName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TurretScaleControlName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterExplosionShakeRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerExplosionShakeRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, DeathExplosionShake)
		ADD_VAR(::FloatProperty, ExplosionInAirAngVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionMomentum, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExplosionDamage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DelayedBurnoutCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeadVehicleLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BurnOutTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BigExplosionSocket, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, SecondaryExplosion)
		ADD_OBJECT(ParticleSystem, ExplosionTemplate)
		ADD_VAR(::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionDamageType)
		ADD_VAR(::FloatProperty, DamageSmokeThreshold, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, VehiclePieceClass)
		ADD_VAR(::IntProperty, ClientHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeTilSecondaryVehicleExplosion, 0xFFFFFFFF)
		ADD_OBJECT(Emitter, DeathExplosion)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionLightClass)
		ADD_OBJECT(ScriptClass, VehicleDrowningDamType)
		ADD_VAR(::FloatProperty, HUDExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo' for the property named 'NeedToPickUpAnnouncement'!
		ADD_VAR(::StrProperty, VehicleNameString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VehiclePositionString, 0xFFFFFFFF)
		ADD_OBJECT(UTBot, Reservation)
		ADD_OBJECT(UTVehicleFactory, ParentFactory)
		ADD_OBJECT(SoundCue, StolenSound)
		ADD_VAR(::IntProperty, StolenAnnouncementIndex, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, RanOverSound)
		ADD_OBJECT(ScriptClass, RanOverDamageType)
		ADD_OBJECT(SoundCue, LockedOnSound)
		ADD_VAR(::FloatProperty, ConsoleSteerScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDeadZone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LookSteerSensitivity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LeftStickDirDeadZone, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HornIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHornTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HornAIRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, LinkedEndSound)
		ADD_OBJECT(SoundCue, LinkedToCue)
		ADD_VAR(::FloatProperty, LinkHealMult, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialSpawnDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PlayerStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VehicleLostTime, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, DrivingPhysicalMaterial)
		ADD_VAR(::FloatProperty, DeflectionReverseThresh, 0xFFFFFFFF)
		ADD_OBJECT(Actor, NoPassengerObjective)
		ADD_VAR(::ByteProperty, LinkedToCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AIPurpose, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDriverHoldsFlag, 0x1)
		ADD_OBJECT(SoundCue, VehicleLockedSound)
		ADD_VAR(::BoolProperty, bIsNecrisVehicle, 0x100)
		ADD_VAR(::BoolProperty, bHasEnemyVehicleSound, 0x80)
		ADD_VAR(::BoolProperty, bStealthVehicle, 0x40)
		ADD_VAR(::BoolProperty, bShowDamageDebug, 0x20)
		ADD_VAR(::BoolProperty, bAcceptTurretJump, 0x10)
		ADD_VAR(::BoolProperty, bIsConsoleTurning, 0x8)
		ADD_VAR(::BoolProperty, bStopDeathCamera, 0x4)
		ADD_VAR(::BoolProperty, bCameraNeverHidesVehicle, 0x2)
		ADD_VAR(::BoolProperty, bFixedCamZ, 0x1)
		ADD_VAR(::BoolProperty, bNoFollowJumpZ, 0x80000000)
		ADD_VAR(::BoolProperty, bLimitCameraZLookingUp, 0x40000000)
		ADD_VAR(::BoolProperty, bNoZSmoothing, 0x20000000)
		ADD_VAR(::BoolProperty, bRotateCameraUnderVehicle, 0x10000000)
		ADD_VAR(::BoolProperty, bReducedFallingCollisionDamage, 0x8000000)
		ADD_VAR(::BoolProperty, bPlayingSpawnEffect, 0x4000000)
		ADD_VAR(::BoolProperty, bPostRenderTraceSucceeded, 0x2000000)
		ADD_VAR(::BoolProperty, bHasTurretExplosion, 0x1000000)
		ADD_VAR(::BoolProperty, bRagdollDriverOnDarkwalkerHorn, 0x800000)
		ADD_VAR(::BoolProperty, bInitializedVehicleEffects, 0x400000)
		ADD_VAR(::BoolProperty, bFindGroundExit, 0x100000)
		ADD_VAR(::BoolProperty, bUsingLookSteer, 0x80000)
		ADD_VAR(::BoolProperty, bLookSteerOnSimpleControls, 0x40000)
		ADD_VAR(::BoolProperty, bLookSteerOnNormalControls, 0x20000)
		ADD_VAR(::BoolProperty, bHasBeenDriven, 0x8000)
		ADD_VAR(::BoolProperty, bDriverCastsShadow, 0x4000)
		ADD_VAR(::BoolProperty, bDrawHealthOnHUD, 0x2000)
		ADD_VAR(::BoolProperty, bShouldLeaveForCombat, 0x1000)
		ADD_VAR(::BoolProperty, bNeverReset, 0x800)
		ADD_VAR(::BoolProperty, bHasWeaponBar, 0x400)
		ADD_VAR(::BoolProperty, bShouldAutoCenterViewPitch, 0x200)
		ADD_VAR(::BoolProperty, bStickDeflectionThrottle, 0x100)
		ADD_VAR(::BoolProperty, bOverrideAVRiLLocks, 0x80)
		ADD_VAR(::BoolProperty, bMustBeUpright, 0x40)
		ADD_VAR(::BoolProperty, bKeyVehicle, 0x20)
		ADD_VAR(::BoolProperty, bEnteringUnlocks, 0x8)
		ADD_VAR(::BoolProperty, bValidLinkTarget, 0x4)
		// Here lies the not-yet-implemented method 'TryToDrive'
		// Here lies the not-yet-implemented method 'InCustomEntryRadius'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'UpdateShadowSettings'
		// Here lies the not-yet-implemented method 'ReattachMesh'
		// Here lies the not-yet-implemented method 'CreateDamageMaterialInstance'
		// Here lies the not-yet-implemented method 'UpdateLookSteerStatus'
		// Here lies the not-yet-implemented method 'SetInputs'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'GetChargePower'
		// Here lies the not-yet-implemented method 'PlaySpawnEffect'
		// Here lies the not-yet-implemented method 'StopSpawnEffect'
		// Here lies the not-yet-implemented method 'EjectSeat'
		// Here lies the not-yet-implemented method 'GetRanOverDamageType'
		// Here lies the not-yet-implemented method 'DisplayWeaponBar'
		// Here lies the not-yet-implemented method 'DrawKillIcon'
		// Here lies the not-yet-implemented method 'RenderMapIcon'
		// Here lies the not-yet-implemented method 'AdjustedStrength'
		// Here lies the not-yet-implemented method 'ContinueOnFoot'
		// Here lies the not-yet-implemented method 'IsDriverSeat'
		// Here lies the not-yet-implemented method 'RecommendCharge'
		// Here lies the not-yet-implemented method 'CriticalChargeAttack'
		// Here lies the not-yet-implemented method 'CreateVehicleEffect'
		// Here lies the not-yet-implemented method 'InitializeEffects'
		// Here lies the not-yet-implemented method 'SetVehicleEffectParms'
		// Here lies the not-yet-implemented method 'TriggerVehicleEffect'
		// Here lies the not-yet-implemented method 'PlayVehicleSound'
		// Here lies the not-yet-implemented method 'PlayVehicleAnimation'
		// Here lies the not-yet-implemented method 'VehicleEvent'
		// Here lies the not-yet-implemented method 'EntryAnnouncement'
		// Here lies the not-yet-implemented method 'ExitRotation'
		// Here lies the not-yet-implemented method 'FindAutoExit'
		// Here lies the not-yet-implemented method 'RanInto'
		// Here lies the not-yet-implemented method 'PancakeOther'
		// Here lies the not-yet-implemented method 'TakeWaterDamage'
		// Here lies the not-yet-implemented method 'DriverRadiusDamage'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'SetTexturesToBeResident'
		// Here lies the not-yet-implemented method 'DisableVehicle'
		// Here lies the not-yet-implemented method 'EnableVehicle'
		// Here lies the not-yet-implemented method 'TakeFireDamage'
		// Here lies the not-yet-implemented method 'GetSeatIndexFromPrefix'
		// Here lies the not-yet-implemented method 'ServerSetConsoleTurning'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'GetClampedViewRotation'
		// Here lies the not-yet-implemented method 'ShouldClamp'
		// Here lies the not-yet-implemented method 'GetViewRotation'
		// Here lies the not-yet-implemented method 'WeaponRotationChanged'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetKeyVehicle'
		// Here lies the not-yet-implemented method 'DrivingStatusChanged'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'SeatAvailable'
		// Here lies the not-yet-implemented method 'AnySeatAvailable'
		// Here lies the not-yet-implemented method 'GetSeatIndexForController'
		// Here lies the not-yet-implemented method 'GetControllerForSeatIndex'
		// Here lies the not-yet-implemented method 'ServerAdjacentSeat'
		// Here lies the not-yet-implemented method 'ServerChangeSeat'
		// Here lies the not-yet-implemented method 'HasPriority'
		// Here lies the not-yet-implemented method 'ChangeSeat'
		// Here lies the not-yet-implemented method 'TornOff'
		// Here lies the not-yet-implemented method 'GetCollisionDamageInstigator'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'BlowupVehicle'
		// Here lies the not-yet-implemented method 'GetSeatPRI'
		// Here lies the not-yet-implemented method 'CanEnterVehicle'
		// Here lies the not-yet-implemented method 'KickOutBot'
		// Here lies the not-yet-implemented method 'VehicleLocked'
		// Here lies the not-yet-implemented method 'ShouldShowUseable'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'GetDisplayedHealth'
		// Here lies the not-yet-implemented method 'RenderPassengerBeacons'
		// Here lies the not-yet-implemented method 'PostRenderPassengerBeacon'
		// Here lies the not-yet-implemented method 'SetTeamNum'
		// Here lies the not-yet-implemented method 'TeamChanged'
		// Here lies the not-yet-implemented method 'TeamChanged_VehicleEffects'
		// Here lies the not-yet-implemented method 'Dodge'
		// Here lies the not-yet-implemented method 'IncomingMissile'
		// Here lies the not-yet-implemented method 'ShootMissile'
		// Here lies the not-yet-implemented method 'SendLockOnMessage'
		// Here lies the not-yet-implemented method 'LockOnWarning'
		// Here lies the not-yet-implemented method 'TooCloseToAttack'
		// Here lies the not-yet-implemented method 'CheckTurretPitchLimit'
		// Here lies the not-yet-implemented method 'PlayHorn'
		// Here lies the not-yet-implemented method 'DriverLeave'
		// Here lies the not-yet-implemented method 'UpdateControllerOnPossess'
		// Here lies the not-yet-implemented method 'NumPassengers'
		// Here lies the not-yet-implemented method 'GetMoveTargetFor'
		// Here lies the not-yet-implemented method 'HandleEnteringFlag'
		// Here lies the not-yet-implemented method 'DriverEnter'
		// Here lies the not-yet-implemented method 'HoldGameObject'
		// Here lies the not-yet-implemented method 'AttachFlag'
		// Here lies the not-yet-implemented method 'DriverLeft'
		// Here lies the not-yet-implemented method 'GetFirstAvailableSeat'
		// Here lies the not-yet-implemented method 'PassengerEnter'
		// Here lies the not-yet-implemented method 'PassengerLeave'
		// Here lies the not-yet-implemented method 'CheckReset'
		// Here lies the not-yet-implemented method 'Occupied'
		// Here lies the not-yet-implemented method 'OpenPositionFor'
		// Here lies the not-yet-implemented method 'BotDesireability'
		// Here lies the not-yet-implemented method 'ReservationCostMultiplier'
		// Here lies the not-yet-implemented method 'SpokenFor'
		// Here lies the not-yet-implemented method 'StopsProjectile'
		// Here lies the not-yet-implemented method 'SetReservation'
		// Here lies the not-yet-implemented method 'TeamLink'
		// Here lies the not-yet-implemented method 'AllowLinkThroughOwnedActor'
		// Here lies the not-yet-implemented method 'HealDamage'
		// Here lies the not-yet-implemented method 'IncrementLinkedToCount'
		// Here lies the not-yet-implemented method 'DecrementLinkedToCount'
		// Here lies the not-yet-implemented method 'StartLinkedEffect'
		// Here lies the not-yet-implemented method 'StopLinkedEffect'
		// Here lies the not-yet-implemented method 'PlayHit'
		// Here lies the not-yet-implemented method 'PlayTakeHitEffects'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'GetHomingTarget'
		// Here lies the not-yet-implemented method 'ImportantVehicle'
		// Here lies the not-yet-implemented method 'InitializeSeats'
		// Here lies the not-yet-implemented method 'PreCacheSeatNames'
		// Here lies the not-yet-implemented method 'InitializeTurrets'
		// Here lies the not-yet-implemented method 'PossessedBy'
		// Here lies the not-yet-implemented method 'SetFiringMode'
		// Here lies the not-yet-implemented method 'ClearFlashCount'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
		// Here lies the not-yet-implemented method 'SetFlashLocation'
		// Here lies the not-yet-implemented method 'ClearFlashLocation'
		// Here lies the not-yet-implemented method 'GetBarrelLocationAndRotation'
		// Here lies the not-yet-implemented method 'GetEffectLocation'
		// Here lies the not-yet-implemented method 'GetPhysicalFireStartLoc'
		// Here lies the not-yet-implemented method 'GetWeaponAim'
		// Here lies the not-yet-implemented method 'OverrideBeginFire'
		// Here lies the not-yet-implemented method 'OverrideEndFire'
		// Here lies the not-yet-implemented method 'GetWeaponViewAxes'
		// Here lies the not-yet-implemented method 'CauseMuzzleFlashLight'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'VehicleWeaponFired'
		// Here lies the not-yet-implemented method 'WeaponStoppedFiring'
		// Here lies the not-yet-implemented method 'VehicleWeaponStoppedFiring'
		// Here lies the not-yet-implemented method 'VehicleWeaponFireEffects'
		// Here lies the not-yet-implemented method 'FindWeaponHitNormal'
		// Here lies the not-yet-implemented method 'VehicleWeaponImpactEffects'
		// Here lies the not-yet-implemented method 'SpawnImpactEmitter'
		// Here lies the not-yet-implemented method 'VehicleAdjustFlashCount'
		// Here lies the not-yet-implemented method 'VehicleAdjustFlashLocation'
		// Here lies the not-yet-implemented method 'FindGoodEndView'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'GetCameraFocus'
		// Here lies the not-yet-implemented method 'GetCameraStart'
		// Here lies the not-yet-implemented method 'LimitCameraZ'
		// Here lies the not-yet-implemented method 'VehicleCalcCamera'
		// Here lies the not-yet-implemented method 'AdjustCameraScale'
		// Here lies the not-yet-implemented method 'StartBurnOut'
		// Here lies the not-yet-implemented method 'TurnOffShadows'
		// Here lies the not-yet-implemented method 'DisableDamageSmoke'
		// Here lies the not-yet-implemented method 'DisableCollision'
		// Here lies the not-yet-implemented method 'SetBurnOut'
		// Here lies the not-yet-implemented method 'ShouldSpawnExplosionLight'
		// Here lies the not-yet-implemented method 'RBPenetrationDestroy'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'TurretExplosion'
		// Here lies the not-yet-implemented method 'StopVehicleSounds'
		// Here lies the not-yet-implemented method 'CheckDamageSmoke'
		// Here lies the not-yet-implemented method 'AttachDriver'
		// Here lies the not-yet-implemented method 'SitDriver'
		// Here lies the not-yet-implemented method 'OnDriverPhysicsAssetChanged'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'OnPropertyChange'
		// Here lies the not-yet-implemented method 'GetHealth'
		// Here lies the not-yet-implemented method 'GetCollisionDamageModifier'
		// Here lies the not-yet-implemented method 'InitializeMorphs'
		// Here lies the not-yet-implemented method 'ReceivedHealthChange'
		// Here lies the not-yet-implemented method 'ApplyMorphHeal'
		// Here lies the not-yet-implemented method 'ApplyRandomMorphDamage'
		// Here lies the not-yet-implemented method 'SpawnGibVehicle'
		// Here lies the not-yet-implemented method 'GetSVehicleDebug'
		// Here lies the not-yet-implemented method 'OnExitVehicle'
		// Here lies the not-yet-implemented method 'SetShieldActive'
		// Here lies the not-yet-implemented method 'SetSeatStoragePawn'
		// Here lies the not-yet-implemented method 'SetMovementEffect'
		// Here lies the not-yet-implemented method 'DetachDriver'
		// Here lies the not-yet-implemented method 'CanAttack'
		// Here lies the not-yet-implemented method 'GetVehicleKillStatName'
		// Here lies the not-yet-implemented method 'DisplayHud'
		// Here lies the not-yet-implemented method 'DrawBarGraph'
		// Here lies the not-yet-implemented method 'DisplayExtraHud'
		// Here lies the not-yet-implemented method 'DisplaySeats'
		// Here lies the not-yet-implemented method 'GetSeatColor'
		// Here lies the not-yet-implemented method 'ApplyWeaponEffects'
		// Here lies the not-yet-implemented method 'ShouldLeaveForCombat'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
