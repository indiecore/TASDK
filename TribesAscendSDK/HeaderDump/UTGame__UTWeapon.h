#pragma once
#include "Engine__Controller.h"
#include "UDKBase__UDKWeapon.h"
#include "Engine__Canvas.h"
#include "Engine__ForceFeedbackWaveform.h"
#include "Engine__Texture2D.h"
#include "Engine__SoundCue.h"
#include "UDKBase__UDKPawn.h"
#include "Engine__AnimSet.h"
#include "Engine__ParticleSystem.h"
#include "Engine__Material.h"
#include "Engine__HUD.h"
#include "Engine__Pawn.h"
#include "Engine__Actor.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__Projectile.h"
#include "UTGame__UTPlayerController.h"
#include "Engine__Weapon.h"
#include "UTGame__UTPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTWeapon : public UDKWeapon
	{
	public:
		ADD_VAR(::ByteProperty, AmmoDisplayType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InventoryGroup, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UseHintString, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bExportMenuData, 0x1)
		ADD_VAR(::BoolProperty, bAllowFiringWithoutController, 0x40000)
		ADD_VAR(::BoolProperty, bSmallWeapons, 0x8)
		ADD_VAR(::BoolProperty, bUseCustomCoordinates, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'SimpleCrossHairCoordinates'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'CustomCrosshairCoordinates'!
		ADD_VAR(::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InventoryWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroupWeight, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'CrossHairCoordinates'!
		ADD_VAR(::FloatProperty, CrosshairScaling, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, CrosshairImage)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'CrosshairColor'!
		ADD_VAR(::BoolProperty, bWasLocked, 0x2)
		ADD_VAR(::FloatProperty, LockedStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentLockedScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartLockedScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LockedScaleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FinalLockedScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'LockedCrossHairCoordinates'!
		ADD_VAR(::FloatProperty, ZoomedRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomedTargetFOV, 0xFFFFFFFF)
		ADD_OBJECT(AnimSet, ArmsAnimSet)
		ADD_OBJECT(ForceFeedbackWaveform, WeaponFireWaveForm)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x40)
		ADD_VAR(::BoolProperty, bMuzzleFlashPSCLoops, 0x400)
		ADD_OBJECT(ScriptClass, MuzzleFlashLightClass)
		ADD_VAR(::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowAltMuzzlePSCWhenWeaponHidden, 0x200)
		ADD_OBJECT(ParticleSystem, MuzzleFlashAltPSCTemplate)
		ADD_VAR(::BoolProperty, bMuzzleFlashAttached, 0x800)
		ADD_OBJECT(ParticleSystem, MuzzleFlashPSCTemplate)
		ADD_VAR(::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WeaponPutDownAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ArmsPutDownAnim, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, WeaponPutDownSnd)
		ADD_VAR(::NameProperty, WeaponEquipAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ArmsEquipAnim, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, WeaponEquipSnd)
		ADD_VAR(::BoolProperty, bPendingShow, 0x100)
		ADD_OBJECT(ScriptClass, AttachmentClass)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'MuzzleFlashColor'!
		ADD_VAR(::BoolProperty, bForceHidden, 0x200000)
		ADD_STRUCT(::VectorProperty, HiddenWeaponsOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PlayerViewOffset, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, SmallWeaponsOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WideScreenOffsetScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BobDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, JumpDamping, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, LastRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MaxYawLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPitchLag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRotUpdate, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, WidescreenRotationOffset, 0xFFFFFFFF
		ADD_VAR(::IntProperty, OldRotDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldLeadMag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMaxDiff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotChgSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReturnChgSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentRating, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, AmmoPickupClass)
		ADD_VAR(::IntProperty, MaxAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSplashJump, 0x1000)
		ADD_VAR(::BoolProperty, bUsingAimingHelp, 0x20000)
		ADD_VAR(::FloatProperty, AimingHelpRadius, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ZoomedFireModeNum, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, ZoomInSound)
		ADD_OBJECT(SoundCue, ZoomOutSound)
		ADD_VAR(::FloatProperty, SwitchAbortTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProjectileSpawnOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponCanvasXPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeaponCanvasYPct, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoordinates'!
		ADD_VAR(::BoolProperty, bSuperWeapon, 0x10)
		ADD_VAR(::BoolProperty, bNeverForwardPendingFire, 0x20)
		ADD_VAR(::BoolProperty, bUsesOffhand, 0x80)
		ADD_VAR(::BoolProperty, bRecommendSplashDamage, 0x2000)
		ADD_VAR(::BoolProperty, bSniping, 0x4000)
		ADD_VAR(::BoolProperty, bFastRepeater, 0x8000)
		ADD_VAR(::BoolProperty, bLockedAimWhileFiring, 0x10000)
		ADD_VAR(::BoolProperty, bTargetFrictionEnabled, 0x80000)
		ADD_VAR(::BoolProperty, bTargetAdhesionEnabled, 0x100000)
		ADD_VAR(::BoolProperty, bHasLocationSpeech, 0x400000)
		ADD_VAR(::IntProperty, LockerAmmoCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DroppedPickupOffsetZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoomFadeTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PivotTranslation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WeaponColor'!
		ADD_STRUCT(::RotatorProperty, LockerRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LockerOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, aimerror, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKPlayerController.ObjectiveAnnouncementInfo' for the property named 'NeedToPickUpAnnouncement'!
		ADD_VAR(::FloatProperty, ZoomedTurnSpeedScalePct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistanceMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistancePeak, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionDistanceMax, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'TargetFrictionDistanceCurve'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'TargetFrictionMultiplierRange'!
		ADD_VAR(::FloatProperty, TargetFrictionPeakRadiusScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetFrictionPeakHeightScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TargetFrictionOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, TargetFrictionZoomedBoostValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionTimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionDistanceMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionAimDistY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionAimDistZ, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'TargetAdhesionScaleRange'!
		ADD_VAR(::FloatProperty, TargetAdhesionScaleAmountMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionTargetVelocityMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionPlayerVelocityMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetAdhesionZoomedBoostValue, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetAmmoCount'
		// Here lies the not-yet-implemented method 'CoversScreenSpace'
		// Here lies the not-yet-implemented method 'GetPowerPerc'
		// Here lies the not-yet-implemented method 'DesireAmmo'
		// Here lies the not-yet-implemented method 'ServerStartFire'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'AdjustWeaponTimingForConsole'
		// Here lies the not-yet-implemented method 'CreateOverlayMesh'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'CalcInventoryWeight'
		// Here lies the not-yet-implemented method 'ShouldSwitchTo'
		// Here lies the not-yet-implemented method 'SetSkin'
		// Here lies the not-yet-implemented method 'ActiveRenderOverlays'
		// Here lies the not-yet-implemented method 'DrawWeaponCrosshair'
		// Here lies the not-yet-implemented method 'DrawLockedOn'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'GetFireInterval'
		// Here lies the not-yet-implemented method 'PlayArmAnimation'
		// Here lies the not-yet-implemented method 'PlayWeaponAnimation'
		// Here lies the not-yet-implemented method 'PlayFireEffects'
		// Here lies the not-yet-implemented method 'StopFireEffects'
		// Here lies the not-yet-implemented method 'ShakeView'
		// Here lies the not-yet-implemented method 'WeaponCalcCamera'
		// Here lies the not-yet-implemented method 'WeaponPlaySound'
		// Here lies the not-yet-implemented method 'PlayFiringSound'
		// Here lies the not-yet-implemented method 'MuzzleFlashTimer'
		// Here lies the not-yet-implemented method 'CauseMuzzleFlashLight'
		// Here lies the not-yet-implemented method 'CauseMuzzleFlash'
		// Here lies the not-yet-implemented method 'StopMuzzleFlash'
		// Here lies the not-yet-implemented method 'TimeWeaponPutDown'
		// Here lies the not-yet-implemented method 'PlayWeaponPutDown'
		// Here lies the not-yet-implemented method 'TimeWeaponEquipping'
		// Here lies the not-yet-implemented method 'GetEquipTime'
		// Here lies the not-yet-implemented method 'PlayWeaponEquip'
		// Here lies the not-yet-implemented method 'AttachWeaponTo'
		// Here lies the not-yet-implemented method 'SetMuzzleFlashParams'
		// Here lies the not-yet-implemented method 'AttachMuzzleFlash'
		// Here lies the not-yet-implemented method 'DetachWeapon'
		// Here lies the not-yet-implemented method 'DetachMuzzleFlash'
		// Here lies the not-yet-implemented method 'ChangeVisibility'
		// Here lies the not-yet-implemented method 'PerformWeaponChange'
		// Here lies the not-yet-implemented method 'GetViewAxes'
		// Here lies the not-yet-implemented method 'ServerReselectWeapon'
		// Here lies the not-yet-implemented method 'CanThrow'
		// Here lies the not-yet-implemented method 'GetHand'
		// Here lies the not-yet-implemented method 'SetPosition'
		// Here lies the not-yet-implemented method 'ShouldLagRot'
		// Here lies the not-yet-implemented method 'LagRot'
		// Here lies the not-yet-implemented method 'AdjustPlayerDamage'
		// Here lies the not-yet-implemented method 'RelativeStrengthVersus'
		// Here lies the not-yet-implemented method 'GetWeaponRating'
		// Here lies the not-yet-implemented method 'CanAttack'
		// Here lies the not-yet-implemented method 'BotDesireability'
		// Here lies the not-yet-implemented method 'AmmoMaxed'
		// Here lies the not-yet-implemented method 'GetDamageRadius'
		// Here lies the not-yet-implemented method 'CanHeal'
		// Here lies the not-yet-implemented method 'GetOptimalRangeFor'
		// Here lies the not-yet-implemented method 'FireOnRelease'
		// Here lies the not-yet-implemented method 'FocusOnLeader'
		// Here lies the not-yet-implemented method 'RecommendRangedAttack'
		// Here lies the not-yet-implemented method 'SuggestAttackStyle'
		// Here lies the not-yet-implemented method 'SuggestDefenseStyle'
		// Here lies the not-yet-implemented method 'RangedAttackTime'
		// Here lies the not-yet-implemented method 'SplashJump'
		// Here lies the not-yet-implemented method 'ShouldFireWithoutTarget'
		// Here lies the not-yet-implemented method 'BestMode'
		// Here lies the not-yet-implemented method 'IsFullyCharged'
		// Here lies the not-yet-implemented method 'ReadyToFire'
		// Here lies the not-yet-implemented method 'StillFiring'
		// Here lies the not-yet-implemented method 'ConsumeAmmo'
		// Here lies the not-yet-implemented method 'AddAmmo'
		// Here lies the not-yet-implemented method 'HasAmmo'
		// Here lies the not-yet-implemented method 'HasAnyAmmo'
		// Here lies the not-yet-implemented method 'NeedAmmo'
		// Here lies the not-yet-implemented method 'Loaded'
		// Here lies the not-yet-implemented method 'DenyPickupQuery'
		// Here lies the not-yet-implemented method 'WeaponEmpty'
		// Here lies the not-yet-implemented method 'bReadyToFire'
		// Here lies the not-yet-implemented method 'InstantFireStartTrace'
		// Here lies the not-yet-implemented method 'InstantFireEndTrace'
		// Here lies the not-yet-implemented method 'InstantFire'
		// Here lies the not-yet-implemented method 'InstantAimHelp'
		// Here lies the not-yet-implemented method 'ProjectileFire'
		// Here lies the not-yet-implemented method 'ProcessInstantHit'
		// Here lies the not-yet-implemented method 'GetZoomedState'
		// Here lies the not-yet-implemented method 'CheckZoom'
		// Here lies the not-yet-implemented method 'StartZoom'
		// Here lies the not-yet-implemented method 'EndZoom'
		// Here lies the not-yet-implemented method 'ClientEndFire'
		// Here lies the not-yet-implemented method 'EndFire'
		// Here lies the not-yet-implemented method 'SendToFiringState'
		// Here lies the not-yet-implemented method 'ClientWeaponSet'
		// Here lies the not-yet-implemented method 'FireAmmunition'
		// Here lies the not-yet-implemented method 'PreloadTextures'
		// Here lies the not-yet-implemented method 'AllowSwitchTo'
		// Here lies the not-yet-implemented method 'TryPutDown'
		// Here lies the not-yet-implemented method 'FiringPutDownWeapon'
		// Here lies the not-yet-implemented method 'GetPhysicalFireStartLoc'
		// Here lies the not-yet-implemented method 'GetEffectLocation'
		// Here lies the not-yet-implemented method 'RefireCheckTimer'
		// Here lies the not-yet-implemented method 'SetupArmsAnim'
		// Here lies the not-yet-implemented method 'GetArmAnimNodeSeq'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'SetWeaponOverlayFlags'
		// Here lies the not-yet-implemented method 'DetourWeight'
		// Here lies the not-yet-implemented method 'RecommendLongRangedAttack'
		// Here lies the not-yet-implemented method 'ThrottleLook'
		// Here lies the not-yet-implemented method 'Activate'
		// Here lies the not-yet-implemented method 'DropFrom'
		// Here lies the not-yet-implemented method 'ClientWeaponThrown'
		// Here lies the not-yet-implemented method 'CanViewAccelerationWhenFiring'
		// Here lies the not-yet-implemented method 'HolderEnteredVehicle'
		// Here lies the not-yet-implemented method 'HolderExitedVehicle'
		// Here lies the not-yet-implemented method 'DrawKillIcon'
		// Here lies the not-yet-implemented method 'EnableFriendlyWarningCrosshair'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
